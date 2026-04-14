#include "service_dynamic.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

Service create_service(Repository* repo) {
    Service service;
    service.repo = repo;
    service.undoStack = create_stack();
    service.redoStack = create_stack();
    return service;
}

// cleans the undo/redo stacks
void destroy_service(Service* service) {
    if (service == NULL)
        return;

    // destroy both stacks to free the operations inside them
    destroy_stack(service->undoStack);
    destroy_stack(service->redoStack);
    
}

void to_lowercase(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = (char)tolower((unsigned char)s[i]);
    }
}

int is_valid_date(int day, int month, int year) {
    if (year < 2026)
        return 0;
    if (month < 1 || month > 12)
        return 0;
    if (day < 1 || day > 31)
        return 0;
    return 1;
}

int is_valid_category(char category[]) {
    char copy[20];
    strcpy(copy, category);
    to_lowercase(copy);

    return strcmp(copy, "dairy") == 0 ||
           strcmp(copy, "sweets") == 0 ||
           strcmp(copy, "meat") == 0 ||
           strcmp(copy, "fruit") == 0;
}

// every time the user performs a new action, the redo history must be deleted
void clear_redo(Service* service) {
    while (!is_empty(service->redoStack)) {
        Operation* op = pop(service->redoStack);
        destroy_operation(op);
    }
}

int add_product_service(Service* service, char name[], char category[], int quantity, int day, int month, int year) {
    //void* leak = malloc(10240);
    if (!is_valid_date(day, month, year))
        return -2;

    if (!is_valid_category(category))
        return -1;

    int pos = find_product(service->repo, name, category);

    if (pos == -1) {
        Product new_product = create_product(name, category, quantity, day, month, year);
        int res = add_product_repo(service->repo, new_product);
        if (res == 1) {
            // record the "add" operation
            Operation* op = create_operation(new_product, "add");
            push(service->undoStack, op);
            clear_redo(service);
        }
        return res;
    }
    else {
        // update existing quantity
        Product* products = get_all_products(service->repo);
        Product p_before = products[pos];
        products[pos].quantity += quantity;
        Product p_added = create_product(name,category,quantity,day,month,year);
        Operation* op = create_operation(p_added,"update_add");
        push(service->undoStack, op);
        clear_redo(service);
        return 1;
    }
}

int delete_product_service(Service* service, char name[], char category[]) {
    int pos = find_product(service->repo,name,category);
    if (pos==-1)
        return 0;
    // We must copy the product BEFORE deleting it to save it in the stack
    Product* all = get_all_products(service->repo);
    Product p_to_delete = all[pos];

    int res = delete_product_repo(service->repo, name, category);
    if (res == 1) {
        Operation* op = create_operation(p_to_delete, "delete");
        push(service->undoStack, op);
        clear_redo(service);
        // Clear redo stack because a new action was performed
        // (Optional but standard: destroy_stack(service->redoStack); service->redoStack = create_stack();)
    }
    return res;
}

int update_product_service(Service* service, char name[], char category[], int quantity, int day, int month, int year) {
    if (!is_valid_date(day, month, year))
        return -2;

    if (!is_valid_category(category))
        return -1;

    int pos = find_product(service->repo, name, category);
    if (pos == -1) return 0;

    Product old_p = get_all_products(service->repo)[pos];

    Product updated_p = create_product(name, category, quantity, day, month, year);
    int res = update_product_repo(service->repo, updated_p);
    
    if (res == 1) {
        Operation* op = create_operation(old_p, "update");
        push(service->undoStack, op);
        clear_redo(service);
    }
    return res;
}

void sort_products_by_quantity(Product v[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (v[j].quantity < v[i].quantity) {
                Product aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void filter_products_by_name(Service* service, char substring[], Product result[], int* result_length) {
    Product* all_products = get_all_products(service->repo);
    int total = get_repo_length(service->repo);

    *result_length = 0;

    if (strlen(substring) == 0) {
        for (int i = 0; i < total; i++) {
            result[*result_length] = all_products[i];
            (*result_length)++;
        }
    } 
    else {
        for (int i = 0; i < total; i++) {
            if (strstr(all_products[i].name, substring) != NULL) {
                result[*result_length] = all_products[i];
                (*result_length)++;
            }
        }
    }

    sort_products_by_quantity(result, *result_length);
}

int expires_in_x_days(Product p, int x) {
    int current_day=17;
    int current_month=3;
    int current_year=2026;
    int today = current_year * 365 + current_month * 30 + current_day;
    int expiration_date = p.expiration_year * 365 + p.expiration_month * 30 + p.expiration_day;
    int diff = expiration_date - today;
    if (diff >= 0 && diff <= x)
        return 1;
    return 0;
}


void display_expire(Service* service, char given_category[], int x, Product result[], int* result_length){
    int total = get_repo_length(service->repo);
    Product* all_products = get_all_products(service->repo);
    *result_length = 0;
    for (int i=0; i<total; i++) {
        Product p = all_products[i];
        if (strcmp(given_category, "") == 0 || strcmp(p.category, given_category) == 0){
            if (expires_in_x_days(p, x)) {
                result[*result_length] = p;
                (*result_length)++;
            }
        }
    }    
}

// service pops the last operation and does the opposite
int undo_service(Service* service) {
    if (is_empty(service->undoStack)) return 0;

    Operation* op = pop(service->undoStack);
    
    if (strcmp(op->operation_type, "add") == 0) {
        // Inverse of add is delete
        delete_product_repo(service->repo, op->product.name, op->product.category);
    } 
    else if (strcmp(op->operation_type, "delete") == 0) {
        // Inverse of delete is add
        add_product_repo(service->repo, op->product);
    }
    else if (strcmp(op->operation_type, "update") == 0) {
        int pos = find_product(service->repo, op->product.name, op->product.category);
        Product current_in_repo = get_all_products(service->repo)[pos];
        update_product_repo(service->repo, op->product);
        op->product = current_in_repo; // Swap so Redo has the "new" version
    }
    else if (strcmp(op->operation_type, "update_add") == 0) {
    int pos = find_product(service->repo, op->product.name, op->product.category);
    if (pos != -1) {
        Product* all = get_all_products(service->repo);
        // Subtract the quantity that was recorded in the operation
        all[pos].quantity -= op->product.quantity;
    }
}

    // After undoing, push the operation to Redo stack
    push(service->redoStack, op);
    return 1;
}

// looks at the operation type and performs the action again
int redo_service(Service* service) {
    if (is_empty(service->redoStack)) return 0;

    Operation* op = pop(service->redoStack);
    
    if (strcmp(op->operation_type, "add") == 0) {
        // Inverse of add is delete
        add_product_repo(service->repo, op->product);
    } 
    else if (strcmp(op->operation_type, "delete") == 0) {
        // Inverse of delete is add
        delete_product_repo(service->repo, op->product.name, op->product.category);
    }
    else if (strcmp(op->operation_type, "update") == 0) {
        // Inverse of update is putting the OLD version back
        int pos = find_product(service->repo, op->product.name, op->product.category);
        Product current_in_repo = get_all_products(service->repo)[pos];
        update_product_repo(service->repo, op->product);
        op->product = current_in_repo;
    }
    else if (strcmp(op->operation_type, "update_add") == 0) {
    int pos = find_product(service->repo, op->product.name, op->product.category);
    if (pos != -1) {
        Product* all = get_all_products(service->repo);
        // Add the quantity back
        all[pos].quantity += op->product.quantity;
    }
}
    // After redoing, push the operation to Undo stack
    push(service->undoStack, op);
    return 1;
}

void add_default_products(Service* service) {
    add_product_repo(service->repo, create_product("Milk", "Dairy", 10, 15, 10, 2029));
    add_product_repo(service->repo, create_product("Cheese", "Dairy", 15, 30, 10, 2028));
    add_product_repo(service->repo, create_product("Butter", "Dairy", 5, 5, 11, 2028));
    add_product_repo(service->repo, create_product("Yogurt", "Dairy", 8, 10, 11, 2028));
    add_product_repo(service->repo, create_product("banana", "fruit", 4, 11, 3, 2026));
    add_product_repo(service->repo, create_product("apple", "fruit", 7, 20, 3, 2026));
    add_product_repo(service->repo, create_product("chicken", "meat", 3, 9, 3, 2026));
    add_product_repo(service->repo, create_product("beef", "meat", 2, 18, 3, 2026));
    add_product_repo(service->repo, create_product("cake", "sweets", 1, 14, 3, 2026));
    add_product_repo(service->repo, create_product("chocolate", "sweets", 6, 30, 4, 2026));
    add_product_repo(service->repo, create_product("icecream", "sweets", 2, 25, 3, 2026));
    
}
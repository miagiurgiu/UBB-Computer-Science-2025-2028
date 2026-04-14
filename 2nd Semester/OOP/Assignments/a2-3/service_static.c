#include "service_static.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// creates service based on received repo
Service create_service(Repository* repo) {
    Service service; // local variable
    service.repo = repo; // save address of repo in service
    return service; // return created service
}

// dairy = DAIRY = DaIrY
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

// returns 1 if at lease one condition is true
int is_valid_category(char category[]) {
    char copy[20];
    strcpy(copy,category);
    to_lowercase(copy);
    return strcmp(copy, "dairy") == 0 ||
        strcmp(copy, "sweets") == 0 ||
        strcmp(copy, "meat") == 0 ||
        strcmp(copy, "fruit") == 0;
}

int add_product_service(Service* service, char name[], char category[], int quantity, int day, int month, int year) {
    //Product new_product = create_product(name, category, quantity, day, month, year);
    if (!is_valid_date(day, month, year))
        return -2;
    
    if (!is_valid_category(category)) {
        return -1; // Invalid category
    }
    int pos = find_product(service->repo, name, category); // product already exists in repo?
    if (pos == -1) { // does not exist already
        Product new_product = create_product(name, category, quantity, day, month, year); // new product
        return add_product_repo(service->repo, new_product); // add it to repo and return result
    }
    Product* products = get_all_products(service->repo); // get address of the vector of products from repo
    products[pos].quantity += quantity; // if already exists, just increase its quantity
    return 1; // successfully added
}

int delete_product_service(Service* service, char name[], char category[]) {
    if (!is_valid_category(category)) {
        return -1; // Invalid category
    }
    return delete_product_repo(service->repo, name, category); // call repo function
}

int update_product_service(Service* service, char name[], char category[], int quantity, int day, int month, int year) {
    if (!is_valid_category(category)) {
        return -1; // Invalid category
    }
    Product updated_product = create_product(name, category, quantity, day, month, year); // creates new product that will replace the old product
    return update_product_repo(service->repo, updated_product);
}

// generic ascending sort
void sort_products_by_quantity(Product v[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i+1; j < length; j++) {
            if (v[j].quantity < v[i].quantity) {
                Product aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

// result[] is the vector of found products, *result_length because ?
void filter_products_by_name(Service* service, char substring[], Product result[], int* result_length) {
    Product* all_products = get_all_products(service->repo); // take vector of products from repo
    int total = get_repo_length(service->repo); // actual nr of products in repo
    *result_length = 0;
    if (strlen(substring) == 0) {
        // If substring is empty, copy all products
        for (int i = 0; i < total; i++) {
            result[*result_length] = all_products[i];
            (*result_length)++;
        }
    } else {
        for (int i = 0; i < total; i++) {
            if (strstr(all_products[i].name, substring) != NULL) {
                result[*result_length] = all_products[i];
                (*result_length)++;
            }
        }
    }
    sort_products_by_quantity(result, *result_length); // sort all found elements
}

// default list of products (hardcoded)
void add_default_products(Service* service) {
    add_product_service(service, "Milk", "Dairy", 10, 15, 10, 2029);
    add_product_service(service, "apple", "fruit", 30, 25, 10, 2029);
    add_product_service(service, "Cheese", "Dairy", 15, 30, 10, 2028);
    add_product_service(service, "Butter", "Dairy", 5, 5, 11, 2028);
    add_product_service(service, "Yogurt", "Dairy", 8, 10, 11, 2028);
    add_product_service(service, "banana", "fruit", 4, 11, 3, 2026);
    add_product_service(service, "chicken", "meat", 3, 9, 3, 2026);
    add_product_service(service, "beef", "meat", 2, 18, 3, 2026);
    add_product_service(service, "cake", "sweets", 1, 14, 3, 2026);
    add_product_service(service, "chocolate", "sweets", 6, 30, 4, 2026);
    add_product_service(service, "icecream", "sweets", 2, 25, 3, 2026);

}
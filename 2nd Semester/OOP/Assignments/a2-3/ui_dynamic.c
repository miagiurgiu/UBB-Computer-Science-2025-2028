#include "ui_dynamic.h" // include the ui header
#include <stdio.h> // for printf, scanf
#include <stdlib.h> // for memory functions
#include <string.h> // for string functions

void menu()
{
    printf("Welcome Intelligent Refrigerator DYNAMIC!\n");
    printf("1. Add product\n");
    printf("2. Delete product\n");
    printf("3. Update product\n");
    printf("4. Filter products by name\n");
    printf("5. Display all products\n");
    printf("6. Display products about to expire\n");
    printf("7. Undo\n");
    printf("8. Redo\n");
    printf("0. Exit\n");
}

// Creates an UI and receives pointer to service
UI create_ui(Service* service) {
    UI ui; // create local variable ui of type UI
    ui.service = service; // save the service pointer in the ui structure
    return ui; // return the created ui
}

// Displays the list of products
void print_products(Product products[], int length) {
    if (length == 0) { // if there are no products
        printf("No products found.\n");
        return; // exit function
    }
    for (int i=0; i < length; i++) { // traverse all the products
        printf("Name: %s, Category: %s, Quantity: %d, Expiration Date: %d/%d/%d\n",
               products[i].name, products[i].category, products[i].quantity,
               products[i].expiration_day, products[i].expiration_month, products[i].expiration_year);
    }
}

void add_product_ui(UI* ui) {
    char name[50], category[20];
    int quantity, day, month, year;

    printf("Name:");
    scanf("%49s", name); // read max 49 characters (the 50th one is for '\0')

    printf("Category:");
    scanf("%19s", category); // string is already an address

    printf("Quantity:");
    scanf("%d", &quantity); // address of the variable because scanf needs address

    printf("Expiration day:");
    scanf("%d", &day);

    printf("Expiration month:");
    scanf("%d", &month);

    printf("Expiration year:");
    scanf("%d", &year);

    /*
    if (!is_valid_date(day,month,year)) {
        printf("Invalid date. Please enter a valid date.\n");
        return;
    }
    */
    
    int result = add_product_service(ui->service, name, category, quantity, day, month, year);
    // ui -> service is a pointer to service
    // name -> address of the first character from vector name
    // category -> address of the first character from vector category
    // quantity, day, month, year -> values
    if (result == -1)
        printf("Invalid category. Valid categories are: dairy, sweets, meat, fruit.\n");
    else if(result == -2)
        printf("Invalid date. Please enter a valid date.\n");
    else if (result==1)
        printf("Product added successfully.\n");
    else
        printf("Failed to add product.\n");

}

void delete_product_ui(UI* ui) {
    char name[50], category[20];

    printf("Name: ");
    scanf("%49s",name);

    printf("Category: ");
    scanf("%19s", category);

    int result = delete_product_service(ui->service, name, category);
    if (result == -1)
        printf("Invalid category. Valid categories are: dairy, sweets, meat, fruit.\n");
    else if (result==1)
        printf("Product deleted successfully.\n");
    else
        printf("Product not found.\n");
    
}

void update_product_ui(UI* ui) {
    char name[50], category[20];
    int quantity, day, month, year;

    printf("Name: ");
    scanf("%49s",name);

    printf("Category: ");
    scanf("%19s",category);

    printf("New quantity: ");
    scanf("%d", &quantity);

    printf("New expiration day: ");
    scanf("%d", &day);

    printf("New expiration month: ");
    scanf("%d", &month);

    printf("New expiration year: ");
    scanf("%d", &year);

    int result = update_product_service(ui->service, name, category, quantity, day, month, year);

    if (result == -1)
        printf("Invalid category. Valid categories are: dairy, sweets, meat, fruit.\n");
    else if (result == -2)
        printf("Invalid date. Please enter a valid date.\n");
    else if (result==1)
        printf("Product updated successfully.\n");
    else
        printf("Product not found.\n");
}

// receives pointer to UI so it can reach service
void filter_products_ui(UI* ui) {
    char substring[50];
    Product result[100];
    int result_length =0;
    printf("Substring: ");
    getchar(); // consume the newline character left by previous scanf
    //scanf("%49s", substring);
    fgets(substring, sizeof(substring), stdin); // read a line of text, including spaces
    substring[strcspn(substring, "\n")] = '\0'; // remove the newline character at the end of the string
    //Product* result = filter_products_by_name(ui->service, substring, &result_length);
    filter_products_by_name(ui->service, substring,result,&result_length);
    // &result_length -> address of the variable that the service will modify
    // & because i want the function to modify the original value
    print_products(result, result_length);
    //free(result);
}

void display_all_products_ui(UI* ui) {
    Product* products = get_all_products(ui->service->repo); // ui is a pointer to UI, ui-> service is a pointer to service, ui->service->repo is a pointer to repo
    int length = get_repo_length(ui->service->repo); // nr of products in the repo
    print_products(products, length);
}


void display_expire_ui(UI* ui){
    char given_category[50];
    int x;
    Product result[100];
    int result_length=0;
    printf("Give category: ");
    getchar(); // consume newline left from run()
    fgets(given_category, sizeof(given_category), stdin);
    given_category[strcspn(given_category,"\n")]='\0';
    printf("Give range X of days: ");
    scanf("%d", &x);
    // &result_length because service will modify the value
    display_expire(ui->service, given_category, x, result, &result_length);
    print_products(result, result_length);
}

void undo_ui(UI* ui) {
    int res = undo_service(ui->service);
    if(res==1)
        printf("Undo successful.\n");
    else
        printf("No more operations to undo.\n");
}

void redo_ui(UI* ui) {
    int res = redo_service(ui->service);
    if (res==1)
        printf("Redo successful.\n");
    else
        printf("No more operations to redo.\n");
}

void run(UI* ui) {
    int option; 
    while(1) { // infinite loop -> stops at break
        menu();
        printf("Choose an option: "); 
        if (scanf("%d", &option) != 1) { // if user writes text instead of number, returns sth else than 1
            printf("Invalid input. Please enter a number.\n");
            scanf("%*s"); // Clear the invalid input (* means read, but don't save)
            continue; // return to beginning of loop (next iteration)
        }
        if (option == 0) {
            printf("Exiting...\n");
            break;
        }
        switch (option) { // choose action depending on option
            case 1:
                add_product_ui(ui);
                break;
            case 2:
                delete_product_ui(ui);
                break;
            case 3:
                update_product_ui(ui);
                break;
            case 4:
                filter_products_ui(ui);
                break;
            case 5:
                display_all_products_ui(ui);
                break;
            case 6:
                display_expire_ui(ui);
                break;
            case 7:
                undo_ui(ui);
                break;
            case 8:
                redo_ui(ui);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}
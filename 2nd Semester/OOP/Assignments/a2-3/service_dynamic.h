#ifndef SERVICE_DYNAMIC_H
#define SERVICE_DYNAMIC_H

#include "../repository/repo_dynamic.h"
#include "OperationStack.h"

typedef struct {
    Repository* repo;
    OperationsStack* undoStack;
    OperationsStack* redoStack;
} Service;

Service create_service(Repository* repo);

void destroy_service(Service* service);
int is_valid_category(char category[]);
int is_valid_date(int day, int month, int year);
void to_lowercase(char s[]);

void clear_redo(Service* service);

int add_product_service(Service* service, char name[], char category[], int quantity, int day, int month, int year);
int delete_product_service(Service* service, char name[], char category[]);
int update_product_service(Service* service, char name[], char category[], int quantity, int day, int month, int year);

void filter_products_by_name(Service* service, char substring[], Product result[], int* result_length);
void sort_products_by_quantity(Product v[], int length);
int expires_in_x_days(Product p, int x);
void display_expire(Service* service, char given_category[], int x, Product result[], int *result_length);
void add_default_products(Service* service);

int undo_service(Service* service);
int redo_service(Service* service);
#endif
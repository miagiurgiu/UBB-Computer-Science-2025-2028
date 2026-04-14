#ifndef SERVICE_H
#define SERVICE_H

#include "../repository/repo_static.h"

// service contains pointer to repo
// service does not contain the products directly, but works through repo
// service does validations, repo just ??
typedef struct {
    Repository* repo;
} Service;

// creates service and gives access to repo
Service create_service(Repository* repo);

// checks if a category is valid
int is_valid_category(char category[]);
int is_valid_date(int day, int month, int year);

// logic operations of the app
int add_product_service(Service* service, char name[], char category[], int quantity, int day, int month, int year);
int delete_product_service(Service* service, char name[], char category[]);
int update_product_service(Service* service, char name[], char category[], int quantity, int day, int month, int year);

// filters products by name, results added to vector result[], number added in *result_length (* because nr can change)
void filter_products_by_name(Service* service, char substring[], Product result[], int* result_length);
void sort_products_by_quantity(Product v[], int length);

// add to default products
void add_default_products(Service* service);

#endif

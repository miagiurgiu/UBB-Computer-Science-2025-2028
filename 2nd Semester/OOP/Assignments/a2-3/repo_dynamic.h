#ifndef REPO_DYNAMIC_H
#define REPO_DYNAMIC_H

#include "../domain/product.h"
#include "dynamic_array.h"

typedef struct {
    DynamicArray* products; // pointer to dynamic array
} Repository;

Repository create_repository();
void destroy_repository(Repository* repo);

int get_repo_length(Repository* repo);
Product* get_all_products(Repository* repo);

int find_product(Repository* repo, char name[], char category[]);
int add_product_repo(Repository* repo, Product p);
int delete_product_repo(Repository* repo, char name[], char category[]);
int update_product_repo(Repository* repo, Product p);

#endif
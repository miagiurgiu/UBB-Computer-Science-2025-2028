#ifndef REPO_H
#define REPO_H

#include "../domain/product.h"

// define the type repository
typedef struct {
    Product products[100]; // static vector of max 100 products
    int length; // current number of products
} Repository;

Repository create_repository();

// returns nr of products in repo
int get_repo_length(Repository* repo);

// returns address of the vector of products
Product* get_all_products(Repository* repo);

// searches a product after name and category and returns its position
int find_product(Repository* repo, char name[], char category[]);

int add_product_repo(Repository* repo, Product p);
int delete_product_repo(Repository* repo, char name[], char category[]);
int update_product_repo(Repository* repo, Product p);

#endif 



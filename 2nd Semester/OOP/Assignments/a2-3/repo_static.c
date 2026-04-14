#include "repo_static.h"
#include <string.h>

Repository create_repository() {
    Repository repo; // local variable of type repo
    repo.length = 0; // initially, no products inside repo
    return repo; // return created repo
}

// receives pointer to repo and returns nr of used products
int get_repo_length(Repository* repo) {
    return repo->length;
}

// returns the address of the first element in the vector products
// who calls this function can access all products
Product* get_all_products(Repository* repo) {
    return repo->products;
}

// finds the product with given name and category
int find_product(Repository* repo, char name[], char category[]) {
    for (int i = 0; i < repo->length; i++) {
       if (strcmp(repo->products[i].name, name) == 0 &&
           strcmp(repo->products[i].category, category) == 0) {
           return i; // return index
       }
    }
    return -1; // if not found
}

// function that adds product p to repo
int add_product_repo(Repository* repo, Product p) {
    if (repo->length >= 100) {
        return 0; // Repository is full
    }
    repo->products[repo->length] = p; // put the new product on the first free position
    repo->length++; // increase length
    return 1; // successful addition
}

// deletes identified product through its name and category
int delete_product_repo(Repository* repo, char name[], char category[]) {
    int index = find_product(repo, name, category); // find the product's position
    if (index == -1) {
        return 0; // Product not found
    }
    for (int i = index; i < repo->length - 1; i++) { // move every product after it one position to the left
        repo->products[i] = repo->products[i + 1];
    }
    repo->length--; // decrease length
    return 1; // successful deletion
}

int update_product_repo(Repository* repo, Product p) {
    int index = find_product(repo, p.name, p.category); // search product with same name and category as new product p
    if (index == -1) {
        return 0; // Product not found
    }
    repo->products[index] = p; // replace the product at that index with new product
    return 1; // Success
}
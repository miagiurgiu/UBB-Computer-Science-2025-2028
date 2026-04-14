#include "repo_dynamic.h"
#include <string.h>

// initializes a repository struct and asks the dynamic array to allocate space for 2 products
Repository create_repository() {
    Repository repo;
    repo.products = create_dynamic_array(2);
    return repo;
}

// then the repo is no longer needed, it tells the dynamic array to free all its allocated memory
void destroy_repository(Repository* repo) {
    if (repo == NULL)
        return;

    destroy_dynamic_array(repo->products);
}

int get_repo_length(Repository* repo) {
    return repo->products->size;
}

Product* get_all_products(Repository* repo) {
    return repo->products->elems;
}

// locates a specific product based on its unique identity (name + category)
// linear search
// used by add, delete, update
int find_product(Repository* repo, char name[], char category[]) {
    for (int i = 0; i < repo->products->size; i++) {
        if (strcmp(repo->products->elems[i].name, name) == 0 &&
            strcmp(repo->products->elems[i].category, category) == 0) {
            return i;
        }
    }
    return -1;
}

// save a new product into the array
int add_product_repo(Repository* repo, Product p) {
    add(repo->products, p); // add from the dynamic_array.c
    return 1;
}

// remove a product
// uses shifting strategy 
// decrease size by 1
int delete_product_repo(Repository* repo, char name[], char category[]) {
    int index = find_product(repo, name, category);
    if (index == -1)
        return 0;

    for (int i = index; i < repo->products->size - 1; i++) {
        repo->products->elems[i] = repo->products->elems[i + 1];
    }

    repo->products->size--;
    return 1;
}

// replace old info with new data
// finds the index of the product using the name, category inside the product p
int update_product_repo(Repository* repo, Product p) {
    int index = find_product(repo, p.name, p.category);
    if (index == -1)
        return 0;

    repo->products->elems[index] = p; // direct assignment (overwrites in that memory slot)
    return 1;
}
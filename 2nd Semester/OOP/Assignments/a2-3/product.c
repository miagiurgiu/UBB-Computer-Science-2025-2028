#include "product.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// implementation of the function defined in header
Product create_product(char name[], char category[], int quantity, int day, int month, int year) {
    Product p; // local variable of type Product (it contains space for name[50], category[20], quantity, expiration_day, expiration_month, expiration_year)
    strcpy(p.name, name); // copy the string received as parameter in the name field of the product
    strcpy(p.category, category);
    p.quantity = quantity; // copy the values
    p.expiration_day = day;
    p.expiration_month = month;
    p.expiration_year = year;
    return p; // return the newly created product
}

// used for undo/redo
Product* copy_product(Product* p) {
    if (p == NULL)
        return NULL;

    Product* copy = (Product*)malloc(sizeof(Product));
    if (copy == NULL)
        return NULL;

    *copy = *p;   // shallow copy
    return copy;
}

// destructor (takes a generic pointer)
void destroy_product(void* p) {
    if (p == NULL)
        return;

    free((Product*)p); // free the memory previously allocated with malloc
}

// function receives pointer to Product
char* get_name(Product* p) {
    return p->name; // access the name field
}

char* get_category(Product* p) {
    return p->category;
}

int get_quantity(Product* p) {
    return p->quantity;
}

int get_expiration_day(Product* p) {
    return p->expiration_day;
}

int get_expiration_month(Product* p) {
    return p->expiration_month;
}

int get_expiration_year(Product* p) {
    return p->expiration_year;
}

// does not return anything
// receives a pointer to Product and changes the original product quantity
void set_quantity(Product* p, int new_quantity) {
    p->quantity = new_quantity;
}

// changes the expiration date of the original product
void set_expiration_date(Product* p, int day, int month, int year) {
    p->expiration_day = day;
    p->expiration_month = month;
    p->expiration_year = year;
}

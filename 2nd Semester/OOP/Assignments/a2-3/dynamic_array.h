#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include "../domain/product.h"

//typedef void* Product;
//typedef void (*destroyFct)(Product);

typedef struct {
    int capacity, size;
    Product* elems; // dynamically allocated vector of products
} DynamicArray;

DynamicArray* create_dynamic_array(int cap);
void destroy_dynamic_array(DynamicArray* arr);

int resize_dynamic_array(DynamicArray* arr);
void add(DynamicArray* arr, Product elem);

#endif
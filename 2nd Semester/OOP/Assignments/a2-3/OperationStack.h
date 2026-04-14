#pragma once
#include "../domain/product.h"
// #include "../repository/dynamic_array.h"
#include <string.h>

typedef struct {
    Product product;
    char operation_type[20]; // "add", "delete", "update"
} Operation; 

typedef struct {
    //DynamicArray* stack;
    Operation** elems;
    int length;
    int capacity;
} OperationsStack;

Operation* create_operation(Product p, char operation_type[]);

void destroy_operation(void* op);

OperationsStack* create_stack();

void destroy_stack(OperationsStack* stack);

void push(OperationsStack* stack, Operation* op);

Operation* pop(OperationsStack* stack);

int is_empty(OperationsStack* stack);

#include "OperationStack.h"
#include <stdlib.h>
#include <string.h>

// each time service performs an action, we save on the HEAP the product's state at that moment
Operation* create_operation(Product p, char operation_type[]) {
    // allocate memory
    Operation* op = malloc(sizeof(Operation));
    // check null
    if (op==NULL)
        return NULL;
    // copy product
    op->product=p;
    // copy string (strcpy)
    strcpy(op->operation_type,operation_type);
    // return
    return op;
}

// free the memory of a single action once is no longer needed
void destroy_operation(void* op) {
    // if null -> return
    if (op==NULL)
        return;
    // free memory
    free(op);
} 

// initializes a stack with capacity 10
// double allocation: one malloc for the stack, another for the elems (array of pointers)
OperationsStack* create_stack() {
    // malloc for stack
    OperationsStack* stack = malloc(sizeof(OperationsStack));
    // checks NULL
    if (stack==NULL)
        return NULL;
    stack->length = 0;
    stack->capacity = 10;
    // creates dynamic array
    stack->elems = malloc(sizeof(Operation*)*stack->capacity);
    if (stack->elems == NULL) {
        free(stack);
        return NULL;
    }
    // return
    return stack;
}

// deep cleanup
// does not just free the array, it loops through every pointer and destroy operation to free the actions
// before freeing the stack array, it loops through all saved operations and frees each one individually
void destroy_stack(OperationsStack* stack) {
    // if null return
    if (stack==NULL)
        return;
    // destroy dynamic array
    for(int i=0; i<stack->length; i++) {
        destroy_operation(stack->elems[i]);
    }
    // free stack
    free(stack-> elems);
    free(stack);
}

// add new operation to the top
void push(OperationsStack* stack, Operation* op) {
    // add in dynamic array
    // returns nothing
    //addDynamicArray(stack->elems);
    if (stack==NULL || op == NULL)
        return;
    if (stack->length == stack->capacity) {
        stack->capacity*=2;
        Operation** new_elems = realloc(stack->elems, sizeof(Operation*)*stack->capacity);
        if (new_elems == NULL)
            return;
        stack->elems = new_elems;
    }
    stack->elems[stack->length]=op;
    stack->length++;
}

// returns pointer to the last operation added (does not free because service needs to reverse action)
Operation* pop(OperationsStack* stack){
    // returns an operation 
    if (stack==NULL || stack->length == 0)
        return NULL;
    stack->length--;
    return stack->elems[stack->length];
}

int is_empty(OperationsStack* stack) {
    if (stack == NULL) 
        return 1;
    return stack->length==0;
}
#include "dynamic_array.h"
#include <stdlib.h>

// create dynamic array
DynamicArray* create_dynamic_array(int cap) {
    DynamicArray* arr = malloc(sizeof(DynamicArray));
	if (arr == NULL)
		return NULL;
	arr->capacity = cap; // max size
	arr->size = 0; // current size
	arr->elems = malloc(sizeof(Product) * cap);
	if (arr->elems == NULL)
	{
		free(arr);
		return NULL;
	}
	return arr;
}

// manually released memory
// check for memory leaks
// frees the elems array and the structure itself
void destroy_dynamic_array(DynamicArray* arr)
{
	if (arr == NULL)
		return;
	free(arr->elems);
	free(arr);
}

// resize -> double capacity
void resize(DynamicArray* arr) {
	if (arr == NULL)
		return;

	arr->capacity *= 2;
	/*TElem* aux = malloc(sizeof(TElem) * arr->capacity);
	for (int i = 0; i < arr->size; i++)
		aux[i] = arr->elems[i];

	free(arr->elems);
	arr->elems = aux;*/

	Product* aux = realloc(arr->elems, arr->capacity * sizeof(Product));
	if (aux == NULL)
		return;
	arr->elems = aux;
}

// automatically resize
void add(DynamicArray* arr, Product elem)
{
	if (arr == NULL)
		return;

	if (arr->size == arr->capacity)
		resize(arr);
	arr->elems[arr->size++] = elem;
}


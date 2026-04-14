#include "../repo/dynamic_vector.h"

// constructor
DynamicArray::DynamicArray(int cap): capacity{cap}, size{0}
{
	this->elems = new TElem[this->capacity]; // allocates new memory on the Heap
}

// DESTRUCTOR: frees that memory using delete[]
DynamicArray::~DynamicArray()
{
	delete[] this->elems; // new - delete
}

// COPY CONSTRUCTOR: deep copy
DynamicArray::DynamicArray(const DynamicArray& arr)
{
	this->capacity = arr.capacity;
	this->size = arr.size;
	this->elems = new TElem[this->capacity]; // allocate new memory
	for (int i = 0; i < this->size; i++)
	    this->elems[i] = arr.elems[i]; // copy data manually
}

// assignment operator
DynamicArray& DynamicArray::operator=(const DynamicArray& arr)
{
    if(this==&arr) // same object -> do nothing
        return *this;
    
    delete[] this->elems; // free old memory
    this->capacity=arr.capacity;
    this->size=arr.size;
    this->elems=new TElem[this->capacity]; // deep copy

    for(int i=0; i<this->size; i++) // copy elements
        this->elems[i]=arr.elems[i];
    
    return *this; // return current object (permits chaining a=b=c)
}

// resize operation
void DynamicArray::resize()
{
    this->capacity *=2;
    TElem* newElems = new TElem[this->capacity];
    for(int i=0; i<this->size; i++)
        newElems[i]=this->elems[i];
    delete[] this->elems;
    this->elems = newElems;
}

// add element
void DynamicArray::add(const TElem& elem)
{
    if (this->size == this->capacity)
        this->resize();
    this->elems[this->size++]=elem;
}

// remove element by position
void DynamicArray::remove(int pos)
{
    if (pos<0 || pos >= this->size)
        return;
    for (int i=pos; i<this->size-1; i++) // left
        this->elems[i] = this->elems[i+1];
    this->size--;
}

// get size ~ length
int DynamicArray::get_size() const
{
    return this->size;
}

// get element by position
TElem DynamicArray::get_elem(int pos) const
{
    return this->elems[pos];
}
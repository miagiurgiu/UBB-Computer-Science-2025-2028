#include "../repo/dynamic_array.h"

DynamicArray::DynamicArray(int cap): capacity{cap}, size{0} {
    this->elems = new TElem[this->capacity];
}

DynamicArray::~DynamicArray() {
    delete[] this->elems;
}

DynamicArray::DynamicArray(const DynamicArray& arr) {
    this->capacity = arr.capacity;
    this->size = arr.size;
    this->elems = new TElem[this->capacity];
    for(int i=0; i<this->size; i++)
        this->elems[i]=arr.elems[i];
}

DynamicArray& DynamicArray::operator=(const DynamicArray& arr) {
    if(this==&arr)
        return *this;
    delete[] this->elems;
    this->capacity = arr.capacity;
    this->size = arr.size;
    this->elems = new TElem[this->capacity];
    for(int i=0; i<this->size; i++)
        this->elems[i]=arr.elems[i];
    return *this;
}

void DynamicArray::resize() {
    this->capacity*=2;
    TElem* newElems = new TElem[this->capacity];
    for(int i=0; i<this->size; i++)
        newElems[i] = this->elems[i];
    delete[] this->elems;
    this->elems = newElems;
}
void DynamicArray::add(const TElem& elem) {
    if(this->size == this->capacity)
        this->resize();
    this->elems[this->size++]=elem;
}

void DynamicArray::remove(int pos) {
    if(pos < 0 || pos >=this->size)
        return;
    for(int i=pos; i<this->size-1; i++)
        this->elems[i]=this->elems[i+1];
    this->size--;
}

int DynamicArray::get_size() const {
    return this->size;
}

TElem DynamicArray::get_elem(int pos) const {
    return this->elems[pos];
}

void DynamicArray::set_elem(int pos, const TElem& elem) {
    this->elems[pos]=elem;
}
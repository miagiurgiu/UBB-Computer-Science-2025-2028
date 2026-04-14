#pragma once
#include "../domain/protein.h"

typedef Protein TElem;

class DynamicArray {
private:
    int size;
    int capacity;
    TElem *elems;

    void resize();
public:
    DynamicArray(int n=10);
    ~DynamicArray();
    DynamicArray(const DynamicArray& arr);
    DynamicArray& operator=(const DynamicArray& arr);

    void add(const TElem& elem);
    void remove(int pos);
    int get_size() const;
    TElem get_elem(int pos) const;
    void set_elem(int pos, const TElem& elem);
};

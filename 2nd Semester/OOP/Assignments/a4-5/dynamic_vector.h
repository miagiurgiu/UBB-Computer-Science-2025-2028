#pragma once
#include "../domain/coat.h"

typedef Coat TElem; // instead of hardcoding coat everywhere

class DynamicArray {
	private:
		int size;
		int capacity;
		TElem* elems;

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
};
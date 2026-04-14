#pragma once
template <typename T>
class DynamicVector {
    private:
		int size;
		int capacity;
		T* elems;

        void resize() 
        {
            this->capacity *=2;
            T* newElems = new T[this->capacity];
            for(int i=0; i<this->size; i++)
                newElems[i]=this->elems[i];
            delete[] this->elems;
            this->elems = newElems;
        }

	public:
        // constructor
		DynamicVector(int cap=10) : size{0}, capacity{cap} 
        {
            this->elems = new T[this->capacity]; // T instead of TElem
        }

        // destructor
		~DynamicVector() 
        {
            delete[] this->elems;
        }

        // copy constructor
		DynamicVector(const DynamicVector& arr) 
        {
            this->capacity = arr.capacity;
            this->size = arr.size;
            this->elems = new T[this->capacity]; // allocate new memory
            for (int i = 0; i < this->size; i++)
                this->elems[i] = arr.elems[i]; // copy data manually
        }

        // assignment operator
        DynamicVector& operator=(const DynamicVector& arr) 
        {
            if(this==&arr) // same object -> do nothing
                return *this;
    
            delete[] this->elems; // free old memory
            this->capacity=arr.capacity;
            this->size=arr.size;
            this->elems=new T[this->capacity]; // deep copy

            for(int i=0; i<this->size; i++) // copy elements
                this->elems[i]=arr.elems[i];
            
            return *this; // return current object (permits chaining a=b=c)
        }

        void add(const T& elem) 
        {
            if (this->size == this->capacity)
                this->resize();
            this->elems[this->size++]=elem;
        }

        void remove(int pos) 
        {
            if (pos<0 || pos >= this->size)
                return;
            for (int i=pos; i<this->size-1; i++) // left
                this->elems[i] = this->elems[i+1];
            this->size--;
        }

        int get_size() const 
        {
            return this->size;
        }

        T get_elem(int pos) const
        {
            return this->elems[pos];
        }
};
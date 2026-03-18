## Lecture 1 - 25 feb 2026

## Lecture 2 - 4 mar 2026

## Seminar 1 - 4 mar 2026

Theory:
1. Bag =
- container with no positions, like a shopping cart
- container in which the order of elements is not important and the elements do not have to be unique
- there are no positions (meaning no operations working/returning positions)
- the elements are added to the bag according to the order of memory (we cannot control)
- printing can be done in whichever order

Formal definition:
- DOMAIN: B = {b | b is a bag with elements of type TElem}
- INTERFACE: 
		add(b,e)
		remove(b,e)
		size(b)
		search(b,e)
		init(b)
		destroy(b)
		iterator(b,it) -> it is the output
		nrOfOccurences(b,e)
update operation does not make sense because we have no positions for bags
What is input and what is output?
	input => exists pre
	output => does not exist pre, but exist post-conditions

2. ADT Iterator = 
- uni-directional (only next), bi-directional (next + previous)
- we have an iterator because we don't have positions

Formal definition:
- DOMAIN: I = {it | it is an iterator over a bag b}
- INTERFACE: 
		init(i,b) = constructor
		iterator(b,it) = call the constructor (b exists already, it is being created)

Never pass constructor or iterator directly. Use the iterator function.
```
it = BagIterator(b) INCORRECT
iterator(b,it) CORRECT (means create iterator for b)
```
next() -> changes internally
first() -> go back to the beginning (iterator)

#### Bag representation:
1. Using a LIST for the elements
- the list is already a container ??!
- current element from the iterator = index/position of the current element (not the value of the current element, but the index)
```
[1,5,5,7]
current = index
current = 0 => 1
current = 1 => 5
current = 2 => 5
current = 3 => 7

self.__current = 0
getCurrent() -> bag[current]
```
2. Using a LIST OF UNIQUE ELEMENTS + FREQUENCIES
- current element from the iterator = current position + current frequency ??? concrete??
```
elems = [5,7,9]
fr = [3,1,2]
=> 5 appears 3 times
=> 7 appears 1 time
=> 9 appears 2 times

the real bag: {5,5,5,7,9,9}

the iterator holds current element and current frequency

```

#### Bag implementation:
b=input (exists from before => precondition)
e=input (exists from before => precondition)
it=output (exists only after execution => postcondition)

```
class Bag:  
    def __init__(self):  
        self.__bag = list()  
  
    def add(self,e):  
        self.__bag.append(e)  
  
    def remove(self,e):  
        if e in self.__bag:  
            self.__bag.remove(e)  
            return True  
        return False  
    def search(self,e):  
        return e in self.__bag  
  
    def size(self):  
        return len(self.__bag)  
  
    def nrOfOccurences(self,e):  
        count = 0  
        for elem in self.__bag:  
            if elem == e:  
                count += 1  
        return count  
  
    def iterator(self):  
        return BagIterator(self)  
  
class BagIterator:  
    def __init__(self, b):  
        self.__bag = b  
        self.__current = 0  
  
    def getCurrent(self):  
        if self.valid():  
            return self.__bag._Bag__bag[self.__current] # this instead of self.__bag.__bag[self.__current]  
        else:  
            raise ValueError()  
  
    def next(self):  
        self.__current += 1  
  
    def valid(self):  
        return self.__current < self.__bag.size()  
  
    def first(self):  
        self.__current = 0  
  
class BagFr:  
    def __init__(self):  
        self.__elems = []  
        self.__fr = []  
  
    def add(self,e):  
        self.__elems.append(e)  
  
    def remove(self,e):  
        if e in self.__elems:  
            self.__elems.remove(e)  
            return True  
        return False  
    def search(self,e):  
        return e in self.__elems  
  
    def size(self):  
        return len(self.__elems)  
  
    def nrOfOccurences(self,e):  
        count = 0  
        for el in self.__elems:  
            if el == e:  
                count += 1  
        return count  
  
    def iterator(self):  
        return BagFrIterator(self)  
  
class BagFrIterator:  
    def __init__(self, b):  
        self.__elems = b  
        self.__current = 0  
  
    def getCurrent(self):  
        return self.__elems._BagFr__elems[self.__current]  
  
    def next(self):  
        self.__current += 1  
  
    def valid(self):  
        return self.__current < self.__elems.size()  
  
    def first(self):  
        self.__current = 0  
  
def createIntBag():  
    b = Bag()  
    b.add(1)  
    b.add(2)  
    b.add(3)  
    b.add(4)  
    b.add(5)  
    b.add(6)  
    b.add(7)  
    return b  
  
def printBag(b):  
    it = b.iterator()  
    while it.valid():  
        e = it.getCurrent()  
        print(e)  
        it.next()  
  
b = createIntBag()  
printBag(b)
```

Wrap-up with this ADT concept: ADT describes abstract operations, and in implementation they become calls to constructors or methods

## Lecture 2 

Dynamic arrays (data structures)

addToEnd - Pseudocode:
```
subalgorithm addToEnd (da, e) is:
    if da.nrElem == da.cap then
        //the dynamic array is full. We need to resize it
        da.cap ← da.cap * 2
        newElems ← @ an array with da.cap empty slots

        //we need to copy existing elements into newElems
        for index ← 1, da.nrElem execute
            newElems[index] ← da.elems[index]
        end-for

        //we need to replace the old element array with the new one
        //depending on the prog. lang., we may need to free the old elems array
        da.elems ← newElems
    end-if

    //now we certainly have space for the element e
    da.nrElem ← da.nrElem + 1
    da.elems[da.nrElem] ← e
end-subalgorithm
```

addToEnd - Python:
```
class DynamicArray:
    def __init__(self, cap):
        self.cap = cap
        self.nrElem = 0
        self.elems = [None] * (cap + 1)  # 1-based indexing


def addToEnd(da, e):
    if da.nrElem == da.cap:
        # the dynamic array is full. We need to resize it
        da.cap = da.cap * 2
        newElems = [None] * (da.cap + 1)  # an array with da.cap empty slots

        # we need to copy existing elements into newElems
        for index in range(1, da.nrElem + 1):
            newElems[index] = da.elems[index]

        # we need to replace the old element array with the new one
        # depending on the prog. lang., we may need to free the old elems array
        da.elems = newElems

    # now we certainly have space for the element e
    da.nrElem = da.nrElem + 1
    da.elems[da.nrElem] = e

```

addToEnd - C++:
```
#include <iostream>
using namespace std;

struct DynamicArray {
    int cap;
    int nrElem;
    int* elems;
};

void addToEnd(DynamicArray& da, int e) {
    if (da.nrElem == da.cap) {
        // the dynamic array is full. We need to resize it
        da.cap = da.cap * 2;
        int* newElems = new int[da.cap + 1]; // an array with da.cap empty slots

        // we need to copy existing elements into newElems
        for (int index = 1; index <= da.nrElem; index++) {
            newElems[index] = da.elems[index];
        }

        // we need to replace the old element array with the new one
        // depending on the prog. lang., we may need to free the old elems array
        delete[] da.elems;
        da.elems = newElems;
    }

    // now we certainly have space for the element e
    da.nrElem = da.nrElem + 1;
    da.elems[da.nrElem] = e;
}
```


addToEnd - C:
```
#include <stdio.h>
#include <stdlib.h>

struct DynamicArray {
    int cap;
    int nrElem;
    int* elems;
};

void addToEnd(struct DynamicArray* da, int e) {
    if (da->nrElem == da->cap) {
        // the dynamic array is full. We need to resize it
        da->cap = da->cap * 2;
        int* newElems = (int*)malloc((da->cap + 1) * sizeof(int)); // an array with da.cap empty slots

        // we need to copy existing elements into newElems
        for (int index = 1; index <= da->nrElem; index++) {
            newElems[index] = da->elems[index];
        }

        // we need to replace the old element array with the new one
        // depending on the prog. lang., we may need to free the old elems array
        free(da->elems);
        da->elems = newElems;
    }

    // now we certainly have space for the element e
    da->nrElem = da->nrElem + 1;
    da->elems[da->nrElem] = e;
}
```

addToPosition - Pseudocode
```
subalgorithm addToPosition (da, i, e) is:
    if i > 0 and i ≤ da.nrElem+1 then
        if da.nrElem = da.cap then //the dynamic array is full. We need to resize it
            da.cap ← da.cap * 2
            newElems ← @ an array with da.cap empty slots

            for index ← 1, da.nrElem execute
                newElems[index] ← da.elems[index]
            end-for

            da.elems ← newElems
        end-if

        //now we certainly have space for the element e
        da.nrElem ← da.nrElem + 1

        for index ← da.nrElem, i+1, -1 execute //move the elements to the right
            da.elems[index] ← da.elems[index-1]
        end-for

        da.elems[i] ← e
    else
        @throw exception
    end-if
end-subalgorithm
```

addToPosition - Python
```
class DynamicArray:
    def __init__(self, cap):
        self.cap = cap
        self.nrElem = 0
        self.elems = [None] * (cap + 1)  # 1-based indexing


def addToPosition(da, i, e):
    if i > 0 and i <= da.nrElem + 1:
        if da.nrElem == da.cap:  # the dynamic array is full. We need to resize it
            da.cap = da.cap * 2
            newElems = [None] * (da.cap + 1)

            for index in range(1, da.nrElem + 1):
                newElems[index] = da.elems[index]

            da.elems = newElems

        # now we certainly have space for the element e
        da.nrElem = da.nrElem + 1

        # move the elements to the right
        for index in range(da.nrElem, i, -1):
            da.elems[index] = da.elems[index - 1]

        da.elems[i] = e
    else:
        raise Exception("invalid position")
```

addToPosition - C++
```
#include <iostream>
#include <stdexcept>
using namespace std;

struct DynamicArray {
    int cap;
    int nrElem;
    int* elems;
};

void addToPosition(DynamicArray& da, int i, int e) {
    if (i > 0 && i <= da.nrElem + 1) {
        if (da.nrElem == da.cap) { // the dynamic array is full. We need to resize it
            da.cap = da.cap * 2;
            int* newElems = new int[da.cap + 1];

            for (int index = 1; index <= da.nrElem; index++) {
                newElems[index] = da.elems[index];
            }

            delete[] da.elems;
            da.elems = newElems;
        }

        // now we certainly have space for the element e
        da.nrElem = da.nrElem + 1;

        // move the elements to the right
        for (int index = da.nrElem; index >= i + 1; index--) {
            da.elems[index] = da.elems[index - 1];
        }

        da.elems[i] = e;
    } else {
        throw runtime_error("invalid position");
    }
}
```

addToPosition - C
```
#include <stdio.h>
#include <stdlib.h>

struct DynamicArray {
    int cap;
    int nrElem;
    int* elems;
};

void addToPosition(struct DynamicArray* da, int i, int e) {
    if (i > 0 && i <= da->nrElem + 1) {
        if (da->nrElem == da->cap) { // the dynamic array is full. We need to resize it
            da->cap = da->cap * 2;
            int* newElems = (int*)malloc((da->cap + 1) * sizeof(int));

            for (int index = 1; index <= da->nrElem; index++) {
                newElems[index] = da->elems[index];
            }

            free(da->elems);
            da->elems = newElems;
        }

        // now we certainly have space for the element e
        da->nrElem = da->nrElem + 1;

        // move the elements to the right
        for (int index = da->nrElem; index >= i + 1; index--) {
            da->elems[index] = da->elems[index - 1];
        }

        da->elems[i] = e;
    } else {
        printf("Exception: invalid position\n");
        exit(1);
    }
}
```
## Lab 1
elements = the beginning of the memory address
```
private:
	TElem* elements; // elements = the beginning of the memory address
	int capacity; // how big is this array (max)
	int mapSize; // how many elements i currently have (current)
```
we cannot allow the map size to increase indefinitely.
without the capacity we would not know if we can still add new stuff or not.

to compile all files in vs code:    

FixedCapBiMapIterator.cpp
Maria@Mac FixedCapBiMap % clang++ *.cpp -o app
Maria@Mac FixedCapBiMap % ./app

or:

clang++ App.cpp FixedCapBiMap.cpp FixedCapBiMapIterator.cpp -o app
Maria@Mac FixedCapBiMap % ./app

## Lecture 3 - 18 mar 2026

Containers

1) Bag
- representation 1
- representation 2 - with frequencies
- see end of lecture 2
- always possible, no matter the data structure used for a bag
- representation 3 - array of positions -> "nightmare" for a sorted bag
- representatoin 4 - searching is faster theta(1) -> compute formula -> not good for sorted?
- it is recommended to have non-zero elements on the first and last positions
- iterator is a little different because of the zero values
	- should not have as current element sth that is 0
	- go the next non-zero operation
	- no longer theta(1) because it will have a while loop
	- we need the current frequency 
	- keep count of the current frequencies
	- when you go the next position, you might need to skip a few zeroes

2) Sorted bag
- elements are sorted (they have an order)
- no positions
- binary search instead of linear search (but not visible from the outside)
- sorting criteria
- only init is changed (in the interface; the only change is that init will take a relation as parameter; like giving a function asa parameter; and that function is a 2-parameter function which returns true or false)
- how relations are done for lab assignments:
- rel(e1,e2) = true if e1<=e2; false if e1>e2
- the test functions are defined in this way
- how to check if a bag is sorted (not at implementation level?) two posibilities:
	- 1. add to the bag: 3,1,4,2 -> two approaches
		- sort them internally when adding them to the bag: 1,2,3,4 -> standard iterator for dynamic array; add operation is more complicated based on relation; -> iterator is efficient (stored internally by the relation altough it might not be visually vi)
		- i don't have positions -> store them in 3,1,4,2 -> iterator needs sorted order -> search for the min -> position 2 -> when calling next() -> find the next smallest value => 4th position -> 1st position -> 3rd position -> change more things -> iteration is inefficient -> we want theta(1) complexity, whenever is possible -> innefficient, we don't use (would work in the sense that the behaviour will be ok)

regular bag ->
sorted bag -> only the first two

3) SET. electoral application
	- elements to be unique
	- order not important
	- no positions, like in a bag
	- container w no positions but elements are unique -> called a SET
	- nr of occurences does not make sense for a set because elements are unique
	- union, intersection
	- same for sorted bag but interface is changed by relation
	- iterator has to return elems in correct sorted order

4) minesweeper. what type of container needed to place the mines?
- matrix? list? dictionary? matrix. 
- matrix is container 2-dimensional array
- container with positions for the elements
- what operations? create matrix, specify nr lines, columns -> non zero, positive numbers
- get nr lines, get nr columns
- return value from given position based on line, column (valid values for lines, cols)
- no add, remove from matrix (does not make sense)
- we have "modify values on a specific position" operation instead.
	- split it in helper function for different cases, but still one modify operation
	- put a specific value on a given position
	- there is a value on every position
	- 4 cases: current(0/1) vs new(0/1)
	- ex: if sth is not there (3 3), then it means it's 0
```
0 (current) -> 0 (new) => do nothing
0 (current) -> !=0 (new) => insert/add
!=0 (current) -> 0 (new) => remove from the data structure
!=0 (current) -> !=0 (new) => change value

```

- most positions are empty in minesweeper. 480 positions?
- sparse matrix (not a lot of positions occupied)
	- 1. way of storing 1: only store the non-zero values -> triples (line, col, value)
	- 
"remove element 10" -> value-min+1

- "compressed sparse line representation" and "compressed sparse column representation"
- "waste of memory" (modify the value from position 3 3 to 19) -> making the lines array shorter (have as many elements as.... + 1)
```
1 2 3 4  5  6   7
1 4 8 11 15 15 19

we don't have 5 on the line -> put the one on the next
we don't have 7 (too big) -> last position + 1 = 19
elements from line 3 -> positions 8,9,10 in the other 2 arrays -> p

for i <- lines[line], lines[line+1],1 ex

(for loop that traverses the elements on line line)
```

- most frequent word of a text:
	- dictionaries (key = words; values = frequencies)
	- order of keys is not important
	- MAP (=DICTIONARY in Python)
	- i need iterator because map does not have position (key-value pair will be returned by iterator)
	- one single getCurrentFunction
	- sortedmap sorted by the keys
	- for maps -> no previous/next key
- morse
	- multi-map: key is allowed not to be unique?
	- add a new key-value pair simply because
	- for remove, specify the entire pair
	- for a simple map, the value is not required for removing, it removes by position ig
	- sorted multi-map -> sort only the keys

- stack
	- restricted access (only to some elements - the one on the top)
	- add, remove operations happen on the top
	- remove. stack knows what. 
	- LIFO
	- push (add)
	- pop (remove+return), exception from an empty stack
	- 


## Lecture 4 - 18 mar 2026

Types of containers
1) ADT Queues
- ex: emergency room
- rear = tail/back (end position) -> where we add
- front -> where we remove
- FIFO
- all elements inserted at the end (rear)
- Implementing a queue using an array (static/dynamic), where should we place the front and rear of the queue?
- theta(n) operation is not enough
- front: remove/pop
- rear: add/push

|     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- |
|     |     |     |     |     |     |
Front                                                                 Rear
Rear  ->                                                             Front

2) ADT Priority queue <-> priorities
- each element has an associated priority
- a relation on these priorities (tells which element has a higher priority)
- higher number does not mean higher priority
- function - takes two priorities, returns true/false if the relation is checked
- when we push sth to this type of queue -> actually a pair
- pop -> removes the element with the higher priority
- priority given by position? by a value?
- no iterators

2) ADT Deque <-> both ends
- container in which we can insert/delete from both ends
- could be used instead of a stack/queue

2) ADT List <-> positions
- only for lists: POSITIONS => they give an order
- TPosition - the type of a position (index or iterator)
- operations:
	- init function to create a list
	- getElement -> return element from given position
	- position -> return position from given element
	- setElement -> put a specific value for a specific position -> STORE DIRECTLY ORDERED INTERNALLY
	- addToEnd -> 
	- remove -> from given position
	- search -> boolean function
	- destroy ->
	- etc.
- "perpendicular" = invalid position (no next position)
- sorted list -> add, validate, set element does not make sense (5 cannot be added at the beginning because it is already sorted, and my list is 2,4,6,8...) -> sorted indexed list, sorted iterated list
- relation passed as a parameter to the init function (init will have 2 parameters)
- iterator returns element in sorted order

2) Linked list
- elements can be anywhere in the memory (no longer at consecutive position)
- i will know the address of the first node
- i have a pointer which tells me who is the first node. contains a pointer who tells me who is the next one etc.
- 4th node has the address of the 5th one...
- singly linked list (every node has one single link, the one pointing to the next node)
- doubly linked list
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
```
2. Using a LIST OF UNIQUE ELEMENTS + FREQUENCIES
- current element from the iterator = current position + current frequency ??? concrete??
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

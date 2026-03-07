## Lecture 1 - 25 feb 2026

## Lecture 2 - 4 mar 2026

## Seminar 1 - 4 mar 2026

Theory:
Bag =
- container with no positions, like a shopping cart
- container in which the order of elements is not important and the elements do not have to be unique
- there are no positions (meaning no operations working/returning positions)
- the elements are added to the bag according to the order of memory (we cannot control)
- printing can be done in whichever order

Formal definition:
- DOMAIN: 
#### Bag implementation:

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

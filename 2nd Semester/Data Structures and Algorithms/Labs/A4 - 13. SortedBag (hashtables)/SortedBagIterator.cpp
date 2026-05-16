#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>
#include <__chrono/convert_to_timespec.h>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	//TODO - Implementation
	//first();

	length=bag.length;
	elements=new TElem[length];
	currentPos=0;
	int index=0;
	for (int i=0;i<bag.capacity;i++) {
		SortedBag::Node* currentNode=bag.table[i];
		while (currentNode!=nullptr) {
			for (int f=0;f<currentNode->freq;f++) {
				elements[index++]=currentNode->elem;
			}
			currentNode=currentNode->next;
		}
	}
	sortElements();
}

void SortedBagIterator::sortElements() {
	for (int i=0; i<length-1; i++) {
		for (int j=i+1; j<length; j++) {
			if (!bag.relation(elements[i],elements[j])) {
				TElem aux=elements[i];
				elements[i]=elements[j];
				elements[j]=aux;
			}
		}
	}
}

TComp SortedBagIterator::getCurrent() {
	//TODO - Implementation
	if (!valid()) {
		throw exception();
	}
	return elements[currentPos];
}

bool SortedBagIterator::valid() {
	//TODO - Implementation
	return currentPos<length;
}

void SortedBagIterator::next() {
	//TODO - Implementation
	if (!valid()) {
		throw exception();
	}
	currentPos++;
}

void SortedBagIterator::first() {
	//TODO - Implementation
	currentPos=0;
}

SortedBagIterator::~SortedBagIterator() {
	delete[] elements;
}
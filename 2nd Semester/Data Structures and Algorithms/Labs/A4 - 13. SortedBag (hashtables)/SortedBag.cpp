#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) {
	//TODO - Implementation
	this->capacity=10;
	this->length=0; // total (including duplicates)
	this->distinctCount=0; // unique
	this->relation=r;
	this->maxLoadFactor=0.7;

	// hash table
	this->table=new Node*[this->capacity];

	// initialize with nullptr
	for (int i=0; i<this->capacity; i++) {
		this->table[i]=nullptr;
	}
}

void SortedBag::add(TComp e) {
	//TODO - Implementation
	int pos=hash(e);
	Node* current=table[pos];
	while (current!=nullptr) { // search through LL on that pos to see if e already exists
		if (current->elem==e) {
			current->freq++;
			length++;
			return;
		}
		current=current->next;
	}
	Node* newNode=new Node;
	newNode->elem=e;
	newNode->freq=1;
	newNode->next=table[pos]; // make new node point to the current head of the LL
	table[pos]=newNode; // insert at the front
	length++;
	distinctCount++;
	if ((double)distinctCount/capacity>maxLoadFactor) {
		resizeAndRehash();
	}
}


bool SortedBag::remove(TComp e) {
	//TODO - Implementation
	int pos=hash(e); // where element should be
	Node* current=table[pos]; // start traversing that LL
	Node* previous=nullptr; // will keep the node before current
	while (current!=nullptr) {
		if (current->elem==e) {
			current->freq--;
			length--;
			if (current->freq==0) { // actual removal
				if (previous==nullptr) { // if first in LL
					table[pos]=current->next; // head moves to next node
				}
				else { // if in middle/end
					previous->next=current->next;
				}
				delete current; // free memory
				distinctCount--; // unique elem deleted
			}
			return true; // removal succeeded
		}
		// advance through LL
		previous=current;
		current=current->next;
	}
	return false; // elem not found
}


bool SortedBag::search(TComp elem) const {
	//TODO - Implementation
	return nrOccurrences(elem)>0;
}

int SortedBag::nrOccurrences(TComp elem) const {
	//TODO - Implementation
	int pos=hash(elem);
	Node* current=table[pos];
	while (current!=nullptr) {
		if (current->elem==elem) {
			return current->freq;
		}
		current=current->next;
	}
	return 0;
}

int SortedBag::size() const {
	//TODO - Implementation
	return length; // total (including duplicates)
}


bool SortedBag::isEmpty() const {
	//TODO - Implementation
	return length==0;
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
	//TODO - Implementation
	// delete every linked list from the table array
	for (int i=0; i<capacity; i++) {
		Node* current=table[i];
		while (current!=nullptr) {
			Node* temp=current;
			current=current->next;
			delete temp;
		}
	}
	// delete the table array
	delete[] table;
}

int SortedBag::hash(TComp e) const {
	if (e<0) { // we don't want negative index
		e=-e;
	}
	return e%capacity;
}

void SortedBag::resizeAndRehash() {
	// resize
	int oldCapacity=capacity;
	Node** oldTable=table;
	capacity *=2;
	table=new Node*[capacity];
	for (int i=0; i<capacity; i++) {
		table[i]=nullptr;
	}

	// rehash
	for (int i=0;i<oldCapacity;i++) {
		Node* current=oldTable[i];
		while (current!=nullptr) {
			Node* nextNode=current->next; // save next node
			int newPos=hash(current->elem); // compute new position of current
			current->next=table[newPos];
			table[newPos]=current; // make current node the new head
			current=nextNode;
		}
	}
	delete[] oldTable;
}
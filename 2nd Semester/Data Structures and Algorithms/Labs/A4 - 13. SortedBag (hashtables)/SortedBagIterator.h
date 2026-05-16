#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);

	//TODO - Representation
	int currentPos; // current table index.
	//SortedBag::Node* currentNode; // current node in that chain.
	//int currentFreq; // which duplicate occurrence we are currently on.

	TElem* elements;
	int length;
	void sortElements();

public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
	~SortedBagIterator();
};


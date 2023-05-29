#ifndef ITERATORG_H_
#define ITERATORG_H_

#include "DNodeG.h"
#include "NodeMapG.h"

#include <iostream>
using namespace std;

template <typename K, typename V>

class IteratorG {
public:

	const V& operator*(); // reference to the element
	bool operator==(const IteratorG& p) const; // compare positions
	bool operator!=(const IteratorG& p) const;
	IteratorG& operator++(); // move to next position
	IteratorG& operator--(); // move to previous position

	friend class NodeMapG<K,V>; // give NodeMapG access
friend class EnglishDictionary;

	IteratorG(){};
private:
	DNodeG<K,V>* v; // pointer to the node
	IteratorG(DNodeG<K,V>* u); // create from node
};

#endif /* ITERATORG_H_ */
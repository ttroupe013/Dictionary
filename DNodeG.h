#ifndef DNODEG_H_
#define DNODEG_H_

#include <iostream>

using namespace std;

template <typename K, typename V>
class NodeMapG;

template<typename K, typename V >
class IteratorG;

template<typename K, typename V >
class Entry;

template <typename K, typename V>
class DNodeG{
private:
	Entry<K,V> elm;
	DNodeG<K,V> *next;
	DNodeG<K,V> *prev;

	friend class NodeMapG<K,V>;
	friend class IteratorG<K,V>;
friend class EnglishDictionary;
};



#endif /* DNODEG_H_ */
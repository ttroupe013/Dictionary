#include "NodeMapG.h"

#include "IteratorG.h"

template <typename K, typename V>
NodeMapG<K,V>::NodeMapG() {
	n = 0; // initially empty
	header = new DNodeG<K,V>; // create sentinels
	trailer = new DNodeG<K,V>;
	header->next = trailer; // have them point to each other
	trailer->prev = header;
   uniqueKeys = 0;
}


template <typename K, typename V>
NodeMapG<K,V>::~NodeMapG() {
}

template <typename K, typename V>
int NodeMapG<K,V>::size() const {
	return n;
}

template <typename K, typename V>
int NodeMapG<K,V>::sizeK() const {
	return uniqueKeys;
}

template <typename K, typename V>
bool NodeMapG<K,V>::empty() const {
	return n==0;
}

template <typename K, typename V>
IteratorG<K, V> NodeMapG<K,V>::begin() const {
	return IteratorG<K, V>(header->next);
}

template <typename K, typename V>
IteratorG<K, V> NodeMapG<K,V>::end() const {
	return IteratorG<K, V>(trailer);
}

template<typename K, typename V>
IteratorG<K, V> NodeMapG<K, V>::find(const K &k) const {
	IteratorG<K,V> p(begin());
	for (; p != end(); ++p)
		if(p.v->elm.getK() == k)
			return p;
	return end();
}

template<typename K, typename V>
IteratorG<K, V> NodeMapG<K, V>::put(const K &k, const V &v) {
	IteratorG<K,V> p = find(k);
	if(p == end()){
		DNodeG<K,V>* w = p.v; // p’s node
		DNodeG<K,V>* u = w->prev; // p’s predecessor
		DNodeG<K,V>* new_node = new DNodeG<K,V>; // new node to insert
		new_node->elm.setKey(k);
		new_node->elm.setValue(v);
		new_node->next = w; w->prev = new_node; // link in v before w
		new_node->prev = u; u->next = new_node; // link in v after u
		n++;
		uniqueKeys++;
	}
	else{
    DNodeG<K,V>* w = p.v; // p’s node
		DNodeG<K,V>* u = w->next; // p’s predecessor
		DNodeG<K,V>* new_node = new DNodeG<K,V>; // new node to insert
		new_node->elm.setKey(k);
    new_node->elm.setValue(v);
    new_node->next = u;
    new_node->prev = w;
    w->next = new_node;
    u->prev = new_node;
	}

	return p;
}


template<typename K, typename V>
void NodeMapG<K, V>::erase(const K &k) {
	IteratorG<K,V> p(begin());
	for (; p != end(); ++p)
		if(p.v->elm.getK() == k)
			erase(p);
	IteratorG<K,V> a = find(k);
	if(a == end())
	   uniqueKeys--;
}

template<typename K, typename V>
void NodeMapG<K, V>::erase(const IteratorG<K, V> &p) {
	DNodeG<K,V>* v = p.v; // node to remove
	DNodeG<K,V>* w = v->next; // successor
	DNodeG<K,V>* u = v->prev; // predecessor
	u->next = w; w->prev = u; // unlink p
	delete v; // delete this node
	n--; // one fewer element
}

template<typename K, typename V>
void NodeMapG<K, V>::print(){
	IteratorG<K,V> p(begin());
	for (; p != end(); ++p)
		cout<< p.v->elm<< " <=> ";
	cout<<endl;
}


template<typename K, typename V>
void NodeMapG<K,V>::eraseFirst(const K& k)
{
    IteratorG<K,V> p(begin());
    for( ;k!= p.v->elm.getK(); ++p);
    
    erase(p);
    
}



template class NodeMapG<int,int>;
template class NodeMapG<int, string>;
template class NodeMapG<string, string>;
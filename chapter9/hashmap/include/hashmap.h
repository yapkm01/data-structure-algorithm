#ifndef HASHMAP_H
#define HASHMAP_H

#include <list>
#include <exception>
#include <fmt/core.h>
#include <map>
#include <vector>
#include <stdexcept>
#include "entry.h"

template <typename K, typename V, typename H>
class HashMap {
	public:
		typedef Entry<K,V> Entry;
		class Iterator;

		HashMap(int capacity=100);
		int size() const;
		bool empty() const;
		Iterator find(const K& k);
		Iterator put(const K&, const V& v);
		void erase(const K& k);
		void erase(const Iterator& i);
		Iterator begin();
		Iterator end();

	protected:
		typedef std::list<Entry> Bucket;
		typedef std::vector<Bucket> BktArray;
		typedef typename BktArray::iterator BItor;
		typedef typename Bucket::iterator EItor;

		Iterator finder(const K& k);
		Iterator inserter(const Iterator& p, const Entry& e);
		void eraser(const Iterator& p);

		static void nextEntry(Iterator& p) {
			++p.ent;
		}
		static bool endOfBkt(const Iterator& p) {
			return p.ent == p.bkt->end();
		}

	private:
		int n;
		H hash;
		BktArray B;

	public:	
		class Iterator {
			public:
				Iterator() = default;
				Iterator(std::list<Entry>::iterator it,
			 		 std::list<Entry>::iterator beginIt,
			 		 std::list<Entry>::iterator endIt) : _it(it), _beginIt(beginIt), _endIt(endIt) {}

				Entry& operator*() const;
				Entry* operator->() const;
				bool operator==(const Iterator& i) const;
				bool operator!=(const Iterator& i) const;
				Iterator& operator++();
				Iterator& operator--();

				friend class ListBasedMap<K,V>;
			private:
				std::list<Entry>::iterator _it;
				std::list<Entry>::iterator _beginIt;
				std::list<Entry>::iterator _endIt;
		};

		int size() const;
		bool empty() const;
		Iterator find(const K& k) const;
		Iterator put(const K& k, const V& v);
		void erase(const K& k);
		void erase(const Iterator& i);
		Iterator begin();
		Iterator end();

	private:
		std::list<Entry> listEntry;
		int n{0};
};

template <typename K, typename V>
typename ListBasedMap<K,V>::Entry& ListBasedMap<K,V>::Iterator::operator*() const {
	return *_it;
}

template <typename K, typename V>
typename ListBasedMap<K,V>::Entry* ListBasedMap<K,V>::Iterator::operator->() const {
	return &(**this);
}

template <typename K, typename V>
bool ListBasedMap<K,V>::Iterator::operator==(const Iterator& i) const {
	return _it == i._it;
}

template <typename K, typename V>
bool ListBasedMap<K,V>::Iterator::operator!=(const Iterator& i) const {
	return _it != i._it;
}

template <typename K, typename V>
typename ListBasedMap<K,V>::Iterator& ListBasedMap<K,V>::Iterator::operator++() {
	if (_it == _endIt) {
		throw std::out_of_range("Iterator cannot be incremented past the end.");
	}
	++_it;
	return *this;
}

template <typename K, typename V>
typename ListBasedMap<K,V>::Iterator& ListBasedMap<K,V>::Iterator::operator--() {
	if (_it == _beginIt) {
		throw std::out_of_range("Iterator cannot be decremented past the beginning.");
	}
	--_it;
	return *this;
}

template <typename K, typename V>
int ListBasedMap<K,V>::size() const {
	return n;
}

template <typename K, typename V>
bool ListBasedMap<K,V>::empty() const {
	return n == 0;
}

template <typename K, typename V>
typename ListBasedMap<K,V>::Iterator ListBasedMap<K,V>::begin() {
	return Iterator(listEntry.begin(), listEntry.begin(), listEntry.end());
}

template <typename K, typename V>
typename ListBasedMap<K,V>::Iterator ListBasedMap<K,V>::end() {
	return Iterator(listEntry.end(), listEntry.begin(), listEntry.end());
}

template <typename K, typename V>
typename ListBasedMap<K,V>::Iterator ListBasedMap<K,V>::find(const K& k) const {
	auto& entries = const_cast<ListBasedMap<K,V>*>(this)->listEntry;
	for (auto it = entries.begin(); it != entries.end(); ++it) {
		if (it->key() == k) {
			return Iterator(it, entries.begin(), entries.end());
		}
	}
	return Iterator(entries.end(), entries.begin(), entries.end());
}

template <typename K, typename V>
typename ListBasedMap<K,V>::Iterator ListBasedMap<K,V>::put(const K& k, const V& v) {
	for (auto it = listEntry.begin(); it != listEntry.end(); ++it) {
		if (it->key() == k) {
			it->setValue(v);
			return Iterator(it, listEntry.begin(), listEntry.end());
		}
	}
	listEntry.emplace_back(k,v);
	n++;
	auto it = listEntry.end();
	--it;
	return Iterator(it, listEntry.begin(), listEntry.end());
}

template <typename K, typename V>
void ListBasedMap<K,V>::erase(const K& k) {
	for (auto it = listEntry.begin(); it != listEntry.end(); ++it) {
		if (it->key() == k) {
			listEntry.erase(it);
			n--;
			return;
		}
	}
	throw std::runtime_error(fmt::format("element {} not found", k));
}

template <typename K, typename V>
void ListBasedMap<K,V>::erase(const typename ListBasedMap<K,V>::Iterator& i) {
	for (auto it = listEntry.begin(); it != listEntry.end(); ++it) {
		if (it == i._it) {
			listEntry.erase(it);
			n--;
			return;
		}
	}
}

#endif

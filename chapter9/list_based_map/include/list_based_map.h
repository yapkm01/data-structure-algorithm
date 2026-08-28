#ifndef MAP_H
#define MAP_H

#include <list>
#include <format>
#include <stdexcept>

template <typename K, typename V>
class ListBasedMap {
	public:
		class Entry {
			public:
				Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v) {}
				const K& key() const {return _key;}
				const V& value() const {return _value;}
				void setKey(const K& k) {_key = k;}
				void setValue(const V& v) {_value = v;}

				friend std::ostream& operator<<(std::ostream& os, const Entry& p) {
					return os << p._key << ": " << p._value;
				}
			private:
				K _key;
				V _value;
		};

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
	throw std::runtime_error(std::format("element {} not found", k));
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


#ifndef LIST_PRIORITY_QUEUE_H
#define LIST_PRIORITY_QUEUE_H

#include <list>
#include "comparator.h"

template <typename E>
class ListPriorityQueue {
	
	public:
		std::size_t size() const {
			return L.size();
		}
		bool empty() const {
			return L.empty();
		}
		void insert(const E& e) {
			typename std::list<E>::iterator p;
			p = L.begin();
			while (p != L.end() && !isLess(e, *p)) ++p;
			L.insert(p, e);
		}
		const E& min() const {
			return L.front();
		}
		void removeMin() {
			return L.pop_front();
		}

	private:
		std::list<E> L;
		Comparator <E> isLess;

};

#endif

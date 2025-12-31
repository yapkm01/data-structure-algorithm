
#ifndef VECTOR_COMPLETE_TREE_H
#define VECTOR_COMPLETE_TREE_H

#include <vector>

template <typename E>
class VectorCompleteTree {
	
	public:
		typedef typename std::vector<E>::iterator Position;
		VectorCompleteTree(): V(1) {};
		int size() const { return (int)(V.size() - 1); }
		Position left(const Position& p) { return pos(2 * idx(p)); }
		Position right(const Position& p) { return pos(2 * idx(p) + 1); }
		Position parent(const Position& p) { return pos(idx(p) / 2); }
		bool hasLeft(const Position& p) { return 2 * idx(p) <= size(); } 
		bool hasRight(const Position& p) { return 2 * idx(p) + 1 <= size(); } 
		bool isRoot(const Position& p) { return idx(p) == 1; } 
		Position root() { return pos(1); }
		Position last() { return pos(size()); }
		void addLast(const E& e) { V.push_back(e); }
		void removeLast() { V.pop_back(); }
		void swap(const Position& p, const Position& q) {
			E e = *q;
			*q = *p;
			*p = e;
		}

	protected:
		Position pos(int i) {
			return V.begin() + i;
		}
		int idx(const Position& p) const {
			return (int)(p - V.begin());
		}

	private:
		std::vector<E> V;

};

#endif

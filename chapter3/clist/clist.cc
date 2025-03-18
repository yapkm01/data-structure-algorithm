#include <iostream>
#include <string>
using namespace std;

template <typename E>
class CircleList;

template <typename E>
class CNode {
	friend class CircleList <E>;
	private:
	E e;
	CNode* next;
};

template <typename E>
class CircleList {
	public:
		CircleList();
		~CircleList();
		bool empty() const;
		const E front() const;
		const E back() const;
		void advance();
		void add (const E& e);
		void remove();
		void print() const;
	private:
		CNode<E>* cursor;
};

template <typename E>
CircleList<E>::CircleList() : cursor(nullptr) {}

template <typename E>
CircleList<E>::~CircleList() {
	while (!empty())
		remove();
}

template <typename E>
bool CircleList<E>::empty() const {
	return cursor  ==  nullptr;
}

template <typename E>
const E CircleList<E>::front() const {
	return cursor->next->e;
}

template <typename E>
const E CircleList<E>::back() const {
	return cursor->e;
}

template <typename E>
void CircleList<E>::advance() {
	cursor = cursor->next;
}

template <typename E>
void CircleList<E>::add (const E& e) {
	CNode<E>* v = new CNode<E>();
	v->e = e;
	if (cursor == nullptr) {
		v->next = v;
		cursor = v;
	} else {
		v->next = cursor->next;
		cursor->next = v;
	}
}

template <typename E>
void CircleList<E>::remove() {
	CNode<E>* old = cursor->next;
	if (old == cursor)
		cursor = nullptr;
	else
		cursor->next = old->next;
	delete old;
}

template <typename E>
void CircleList<E>::print() const {
	CNode<E>* cc = cursor->next;
	if (cc == cursor)
		cout << cc->e << endl;
	else {
		while (cc != cursor) {
			cout << cc->e << endl;
			cc = cc->next;
		}
		cout << cc->e << endl;
		cout << "*******" << endl;
	}
}

int main() {
	CircleList<string> playList;
	playList.add("Stayin Alive");
	playList.add("Le Freak");
	playList.add("Jive Talkin");
	playList.print();
	playList.advance();
	playList.advance();
	playList.print();
	playList.remove();
	playList.print();
	playList.add("Disco Inferno");
	playList.print();
	return 0;
}

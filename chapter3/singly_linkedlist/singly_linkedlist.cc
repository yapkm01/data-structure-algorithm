#include <iostream>
using namespace std;

template <typename E>
class SLinkedList;

template <typename E>
class SNode {
	friend class SLinkedList <E>;

	private:
	E elem;
	SNode<E>* next;
};

template <typename E>
class SLinkedList {
	public:
		SLinkedList();
		~SLinkedList();
		bool empty() const;
		const E& front() const;
		void addFront(const E& e);
		void removeFront();
		void print() const;
	private:
		SNode<E>* head;
};

template <typename E>
SLinkedList<E>::SLinkedList(): head{nullptr} {}

template <typename E>
bool SLinkedList<E>::empty() const {
	return head == nullptr;
}

template <typename E>
const E& SLinkedList<E>::front() const {
	return head->elem;
}

template <typename E>
SLinkedList<E>::~SLinkedList() {
	while (!empty()) removeFront();
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {
	SNode<E>* v = new SNode<E>;
	v->elem = e;
	v->next = head;
	head = v;
}

template <typename E>
void SLinkedList<E>::removeFront() {
	SNode<E>* old = head;
	head = old->next;
	delete old;
}

template <typename E>
void SLinkedList<E>::print() const {
	SNode<E>* pSNode = head;
	while (pSNode != nullptr) {
		cout << pSNode->elem << endl;
		pSNode = pSNode->next;
	}
}

int main() {
	SLinkedList <int> sLinkedList;
	sLinkedList.addFront(2);
	sLinkedList.addFront(1);
	sLinkedList.addFront(9);
	sLinkedList.print();

	return 0;
}

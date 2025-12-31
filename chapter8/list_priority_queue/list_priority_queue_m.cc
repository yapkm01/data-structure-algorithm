#include <iostream>
#include "list_priority_queue.h"
using namespace std;

int main() {
	list <int> l {9, 5, 7, 8, 11, 20, 3, 6, -1, -100, -20 };
	ListPriorityQueue <int> lpq;

	auto it = l.begin();
	while (it != l.end()) {
		lpq.insert(*it++);
		l.pop_front();
	}

	while (!lpq.empty()) {
		l.push_back(lpq.min());
		lpq.removeMin();
	}

	for (auto i = l.begin(); i != l.end(); i++) {
		cout << *i << " ";
	}

	cout << endl;
	return 0;
}

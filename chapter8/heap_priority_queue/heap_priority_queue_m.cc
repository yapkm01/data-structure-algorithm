#include <iostream>
#include "heap_priority_queue.h"
#include "comparator.h"
using namespace std;

int main() {

	Comparator<int> comp;
	HeapPriorityQueue<int, Comparator<int>> pq(comp);

	pq.insert(5);
	pq.insert(3);
	pq.insert(9);
	pq.insert(1);
	pq.insert(8);
	pq.insert(20);
	pq.insert(2);

	cout << "Minimum element: " << pq.min() << endl;
	while (!pq.empty()) {
		cout << "Removing minimum: " << pq.min() << endl;
		pq.removeMin();
	}
	return 0;

}


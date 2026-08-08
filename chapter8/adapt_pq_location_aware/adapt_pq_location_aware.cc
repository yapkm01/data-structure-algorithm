#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

struct Entry {
	int value;
	int index; // location in the heap
	Entry(int v, int i) : value(v), index(i) {}
};

// location-aware heapify=down
void static heapifyDown(vector<Entry*>& heap, int n, int i) {
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    // If left child is larger than root
    if (left_child < n && heap[left_child] > heap[largest]) {
        largest = left_child;
    }

    // If right child is larger than largest so far
    if (right_child < n && heap[right_child] > heap[largest]) {
        largest = right_child;
    }
    // If largest is not root
    if (largest != i) {
        swap(heap[i], heap[largest]);
	heap[i]->index = i;
        // Recursively heapify the affected sub-tree
        heapifyDown(heap, n, largest);
    }
}

void static heapifyUp(vector<Entry*>& heap, int i) {
	while (i > 0) {
		int parent = (i - 1) / 2;
		if (heap[i]->value > heap[parent]->value) {
			swap(heap[i], heap[parent]);
			heap[i]->index=i;
			heap[parent]->index=parent;
			i=parent;
		} else break;
	}
}

void static buildHeap(vector<Entry*>& heap) {
    int n = heap.size();
    // Index of last non-leaf node
    int start_idx = (n / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = start_idx; i >= 0; i--)
        heapifyDown(heap, n, i);

    for (int i = 0; i < n; ++i)
	    heap[i]->index = i;
}

void static printHeap(const string& notes, const vector<Entry*>& heap) {
    for (auto e : heap)
        cout << "Value: " << e->value << ", Index: " << e->index << endl;
    cout << endl;
}

int main() {
    vector<Entry*> heap;
    heap.push_back(new Entry(10,0));
    heap.push_back(new Entry(30,1));
    heap.push_back(new Entry(20,2));
    heap.push_back(new Entry(5,3));
    heap.push_back(new Entry(50,4));
    heap.push_back(new Entry(25,5));
    heap.push_back(new Entry(15,6));

    buildHeap(heap);

    printHeap("Heap values and their indices:", heap);

    // example: update value and re-heapify
    int idx = heap[3]->index;
    heap[3]->value = 40; // increase value
    heapifyDown(heap, heap.size(), idx); // heapify down in case value decreases
    heapifyUp(heap, idx); // heapify up in case value increases

    printHeap("\nAfter updating values:", heap);

    // cleanup
    for (auto e: heap) delete e;

    return 0;
}


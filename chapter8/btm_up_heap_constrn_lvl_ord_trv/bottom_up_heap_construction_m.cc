#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 
 * Using reversal order traversal
 */

// Function for down heap bubbling
void static heapifyDown(vector<int>& heap, int n, int i) {
    int largest = i; // Initialize largest as root
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
        // Recursively heapifyDown the affected sub-tree
        heapifyDown(heap, n, largest);
    }
}

void static buildHeap(vector<int>& heap) {
    int n = heap.size();
    // Index of last non-leaf node
    int start_idx = (n / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapifyDown each node
    for (int i = start_idx; i >= 0; i--)
        heapifyDown(heap, n, i);
}

void static printHeap(const vector<int>& heap) {
    for (int x : heap)
        cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> heap = {1, 23, 15, 4, 6, 18, 3};

    cout << "Original heapay: ";
    printHeap(heap);

    buildHeap(heap);

    cout << "Heap (Max-Heap): ";
    printHeap(heap);

    return 0;
}


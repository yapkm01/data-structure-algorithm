#include <iostream>
#include "linked_binary_tree.h"
using namespace std;

int main() {

	LinkedBinaryTree lbt;
	lbt.addRoot(10);
	LinkedBinaryTree::Position pr = lbt.root();
	lbt.createRecord(pr, 9);
	lbt.createRecord(pr, 20);
	lbt.createRecord(pr, 8);
	lbt.createRecord(pr, 15);
	lbt.createRecord(pr, 1);
	lbt.createRecord(pr, 55);
	lbt.createRecord(pr, 22);
	lbt.createRecord(pr, 33);
	lbt.createRecord(pr, 2);
	lbt.createRecord(pr, 14);

	auto pos = lbt.positions();
	auto cbeg = pos.cbegin();
	auto cend = pos.cend();

	for (; cbeg != cend; cbeg++) {
		cout <<	cbeg->operator*() << " ";
	}
	cout << endl;

	return 0;

}

#include <iostream>
#include "number_of_descendants.h"
using namespace std;

int main() {

	LinkedBinaryTree lbt;

	lbt.addRoot('B');
	LinkedBinaryTree::Position pr = lbt.root();
	lbt.expandExternal(pr, 'A', 'D');
	lbt.expandExternal(pr.right(), 'C', 'E');
	lbt.expandExternal(pr.right().left(), 'F', 'G');
	lbt.expandExternal(pr.right().left().right(), 'H', 'I');

	auto pos = lbt.positions(2);
	auto cbeg = pos.cbegin();
	auto cend = pos.cend();

	cout << "--------- node inorder traversal tree ----------" << endl;

	for (; cbeg != cend; cbeg++) {
		cbeg->print();
		cout << " ";
	}
	cout << endl;

	NumberOfDescendants numberOfDescendants;
	numberOfDescendants.execute(lbt);

	cout << endl;

}

#include <iostream>
#include "linked_binary_tree.h"
using namespace std;

int main() {

	LinkedBinaryTree lbt;
	lbt.addRoot();
	LinkedBinaryTree::Position pr = lbt.root();
	lbt.expandExternal(pr);	
	lbt.expandExternal(pr.left());	

	// 1-preorder 2-inorder 3-postorder
	int trv = 3;
	auto pos = lbt.positions(trv);
	auto cbeg = pos.cbegin();
	auto cend = pos.cend();

	if (trv == 1) cout << "preorder :- "; 
	else if (trv == 2) cout << "inorder :- ";
	else cout << "postorder :-";

	for (; cbeg != cend; cbeg++) {
		cout <<	cbeg->operator*() << " ";
	}
	cout << endl;

	return 0;

}

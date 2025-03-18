#include <iostream>
#include "euler_tour.h"
#include "linked_binary_tree.h"
#include "print_expression_tour.h"
#include "evaluate_expression_tour.h"
using namespace std;

int main() {

	LinkedBinaryTree lbt;

	lbt.addRoot('-');
	LinkedBinaryTree::Position pr = lbt.root();
	lbt.expandExternal(pr, '/', '+');
	lbt.expandExternal(pr.left(), '*', '+');
	lbt.expandExternal(pr.left().left(), '+', '3');
	lbt.expandExternal(pr.left().left().left(), '3', '1');
	lbt.expandExternal(pr.left().right(), '-', '2');
	lbt.expandExternal(pr.left().right().left(), '9', '5');
	lbt.expandExternal(pr.right(), '*', '6');
	lbt.expandExternal(pr.right().left(), '3', '-');
	lbt.expandExternal(pr.right().left().right(), '7', '4');

	auto pos = lbt.positions(2);
	auto cbeg = pos.cbegin();
	auto cend = pos.cend();

	cout << "--------- arithmetic expression tree ----------" << endl;

	for (; cbeg != cend; cbeg++) {
		cbeg->print();
		cout << " ";
	}
	cout << endl;

	cout << "--------- parenthezied arithmetic expression tree ----------" << endl;
	PrintExpressionTour printExpressionTour;
	printExpressionTour.execute(lbt);

	cout << "--------- value ----------" << endl;
	EvaluateExpressionTour evaluateExpressionTour;
	evaluateExpressionTour.execute(lbt);

	cout << endl;

}

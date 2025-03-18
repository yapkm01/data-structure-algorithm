#include <iostream>
#include "number_of_descendants.h"
using namespace std;

void NumberOfDescendants::eulerTour(const Position& p, int& globalCnt) const {
	Result r = initResult();
	if (p.isExternal())
		visitExternal(p, r, globalCnt);
	else {
		visitLeft(p, r, globalCnt);
		eulerTour(p.left(), globalCnt);
		visitBelow(p, r, globalCnt);
		eulerTour(p.right(), globalCnt);
		visitRight(p, r, globalCnt);
	}
}

void NumberOfDescendants::visitExternal(const Position& p, Result& r, int& globalCnt) const {
	cout << "Node "; p.print(); cout << " is an external node" << endl;
}


void NumberOfDescendants::visitLeft(const Position& p, Result& r, int& globalCnt) const {
	r.leftResult = globalCnt;
	cout << "Node "; p.print(); cout << " has counter " << globalCnt << " on the left" << endl;
}

void NumberOfDescendants::visitBelow(const Position& p, Result& r, int& globalCnt) const {
	r.rightResult = ++globalCnt;
	cout << "Node "; p.print(); cout << " has counter " << globalCnt << " from below" << endl;
}

void NumberOfDescendants::visitRight(const Position& p, Result& r, int& globalCnt) const {
	r.rightResult = ++globalCnt;
	cout << "Node "; p.print(); cout << " has counter " << globalCnt << " on the right" << endl;
	cout << "Node "; p.print(); cout << " has " << r.rightResult - r.leftResult << " descendants" << endl;
}

#include <iostream>
#include "include/list_based_map.h"
#include <map>
using namespace std;

int main() {
	ListBasedMap <int, string> lbm;
	auto it1 = lbm.put(1, "one");
	cout << "lbm.size() = " << lbm.size() << endl;
	cout << "lbm.empty() = " << lbm.empty() << endl;
	cout << "*it1 = " << *it1 << endl;
	lbm.put(1, "satu");
	cout << "it1->ley() = " << it1->key() << ": it1->value() = " << it1->value() << endl;
	lbm.put(2, "two");
	auto it2 = lbm.begin();
	cout << "*it2 = " << *it2 << endl;
	auto it3 = lbm.end();
	cout << "*(--it3) = " << *(--it3) << endl;
	cout << "----------------->" << endl;

	for (auto it4 = lbm.begin(); it4 != lbm.end(); ++it4) {
		cout << "*it4 = " << *it4 << endl;
	}
	lbm.find(2)->setValue("dua");
	for (auto it5 = lbm.begin(); it5 != lbm.end(); ++it5) {
		cout << "*it5 = " << *it5 << endl;
	}
	lbm.put(15, "fifteen");
	lbm.put(7, "seven");
	lbm.put(35, "thirty-five");
	lbm.erase(7);
	for (auto it6 = lbm.begin(); it6 != lbm.end(); ++it6) {
		cout << "*it6 = " << *it6 << endl;
	}
	try {
		lbm.erase(77);
	}catch (const exception& e) {
		cout << "Exception caught: " << e.what() << endl;
	}
	auto it7 = lbm.find(15);
	lbm.erase(it7);
	for (auto it8 = lbm.begin(); it8 != lbm.end(); ++it8) {
		cout << "*it8 = " << *it8 << endl;
	}
	auto it9 = lbm.find(35);
	auto it10 = lbm.begin();
	it9 == it10 ? cout << "it9 == it10" << endl : cout << "it9 != it10" << endl;
	it9 != it10 ? cout << "it9 != it10" << endl : cout << "it9 == it10" << endl;

	return 0;
}

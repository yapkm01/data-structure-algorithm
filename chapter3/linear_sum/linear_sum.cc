#include <iostream>
using namespace std;

int linearSum(int* p, int n) {
	if (n == 1)
		return p[0];
	else return linearSum(p, n-1) + p[n-1];
}

int main() {
	int arr [] = {2,5,4,5,6};
	int len = sizeof(arr) / sizeof (*arr);
	cout << linearSum(arr, len) << endl;
	return 0;
}

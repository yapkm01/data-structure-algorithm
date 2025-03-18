#include <iostream>
using namespace std;

void reverse_array(int*, int, int);

int main() {
	int dynamicArraySize = 4;
	// Notice that memory allocation below is dynamic since variable dynamicArraySize is not a constant.
	// This differs from a normal array where the size must be a constant
	int* ptr = new int[] {1, 2, 3, 4};
	reverse_array(ptr, 0, 3);
	cout << ptr[0] << "-" << ptr[1] << "-" << ptr[2] << "-" << ptr[3] << endl;
	return 0;
}

void reverse_array(int* ptr, int i, int j) {
	if (i < j) {
		int tmp = ptr[i];
		ptr[i] = ptr[j];
		ptr[j] = tmp;
		reverse_array(ptr, i+1, j-1);
	}
}

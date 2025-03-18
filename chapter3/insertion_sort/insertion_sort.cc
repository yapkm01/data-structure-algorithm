#include <iostream>
#include <cstring>
using namespace std;

void insertion_sort(char* pa, int n) {
	for (int i = 1; i < n; i++) {
		char cur = pa[i];
		int j = i - 1;
		while ((j >= 0) && (pa[j] > cur)) {
			pa[j + 1] = pa[j];
			j--;
		}	
		pa[j + 1] = cur;
	}
}

void print(const char* pa) {
	while (*pa) {
		cout << *pa << " ";
		pa++;
	}
	cout << endl;
}

int main() {
	char ca[] = {'B', 'A', 'D', 'C', '\0'};
	cout << "strlen(ca) :- " << strlen(ca) << endl;
	insertion_sort(ca, 4);
	print(ca);
}

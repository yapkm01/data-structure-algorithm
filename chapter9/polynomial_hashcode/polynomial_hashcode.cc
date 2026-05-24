#include <cstdlib>
#include <iostream>
using namespace std;

// Polynomial Hash function implementation using Horner's rule. [hash = hash * base + next_char] 
// Example 1: Evaluate p(x)=2x^3-6x^2+2x-1 at x=3
// CoefficientsL [a3,a2,a1,a0]=[2,-6,2,-1]
// 1. Nested structure: (((2).x-6).x+2).x-1
// 2. Iterative steps (x=3):
//    a. Initialize result=2(a3)
//    b. 2.3+(-6)=0
//    c. 0.3+2=2
//    d. 2.3+(-1)=5
// 3. Result=5

// Example 2 based on below feed data in main(): Evaluate p(x)=99x^2+97x+116 at x=31
// CoefficientsL [a2,a1,a0]=[99,97,116]
// 1. Nested structure: ((99).x+97).x+116
// 2. Iterative steps (x=31):
//    a. Initialize result=99(a2)
//    b. 99.31+97=3166
//    c. 3166.31+116=98262
// 3. Result=98262

static long long polynomial_hash(const string& s, int base) {
	long long hash_val = 0;
	for (char c:s) {
		int char_val = c;
		cout << "processing character " << c << " with char_val = " << (int) c << endl;
		hash_val = (hash_val * base + char_val);
	}
	return hash_val;
}

int main() {
	string my_string = "cat";
	int base = 31;
	int modulus = 1e9 + 7;

	long long hash = polynomial_hash(my_string, base);
	cout << "the polynomial hash of \"" << my_string << "\" is: " << hash << endl;
	int hash_mod = hash % modulus;
	cout << "the polynomial hash modulo " << modulus << " of hash code " << hash << " is: " << hash_mod << endl;

	return 0;
}

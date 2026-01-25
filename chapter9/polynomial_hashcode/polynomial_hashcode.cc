#include <cstdlib>
#include <iostream>
using namespace std;

// Traditional Polynomial Hash function implementation [hash = hash * base + next_char] 
long long polynomial_hash(const string& s, int base) {
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

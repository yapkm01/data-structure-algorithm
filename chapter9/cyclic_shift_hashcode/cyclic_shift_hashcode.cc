#include <cstdlib>
#include <iostream>
#include <cstring>
#include <functional>
using namespace std;

static int hash_code(unsigned int h) {
	hash<int> hasher;
	size_t hashed_value = hasher(h);
	return hashed_value;
}

// Cyclic Shift hash function implementation. hash = (hash << 5) | (hash >> 27)
static int cyclic_shift_hash(const char* p, int len) {
	unsigned int h = 0;
	for (int i = 0; i < len ; i++) {
		h = (h << 5) | (h >> 27); // 5-bit cyclic shift
                h += (unsigned int) p[i]; // add in next character
	}
	return hash_code(h);
}

int main() {
	const char* s = "cat";
	int modulus = 1e9 + 7;

	int hashed = cyclic_shift_hash(s, strlen(s));
        cout << "The cyclic shift hashed of " << s << " is: " << hashed << endl;
	int hashed_mod = hashed % modulus;
        cout << "The cyclic shift hashed modulues of hashed " << hashed << " is: " << hashed_mod << endl;
	return 0;
}

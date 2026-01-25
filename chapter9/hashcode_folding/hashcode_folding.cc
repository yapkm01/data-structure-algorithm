#include <cstdlib>
#include <iostream>
using namespace std;

// a custom hash function using the folding method (summing high and low bits)
int folding_hash(long long key) {
	// cast the lower 32 bits to an int
	int low_bits = static_cast<int>(key);
	// shift the key right by 32 bits to get the high 32 bits, then cast to an int
	int high_bits = static_cast<int>(key>>32);

	// sum the high and low order bits
	// the addition naturally wraps around if it exceeds the range of an int
	// which is a standard behavior in hashing to mix bits
	return low_bits + high_bits;
}

// example usage in a data structure (conceptual hashtable)
int main() {
	long long key1 =  1234567890123456789LL; // example large key
	long long key2 =  8876543210987654321LL; // example large key
	
	int hash_code1 = folding_hash(key1);
	int hash_code2 = folding_hash(key2);

	// using the hash code for a hash table (e.g. with a table size M)
	int table_size = 101; // example table size (often a prime number)
	int index1 = std::abs(hash_code1) % table_size;
	int index2 = std::abs(hash_code2) % table_size;

	cout << "original key1: " << key1 << endl;
	cout << "hash code 1 (int): " << hash_code1 << endl;
	cout << "table index 1: " << index1 << endl << endl;

	cout << "original key2: " << key2 << endl;
	cout << "hash code 2 (int): " << hash_code2 << endl;
	cout << "table index 2: " << index2 << endl;

	return 0;
}

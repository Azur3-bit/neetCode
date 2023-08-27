// -- essential_libraries_and_namespace
#include <iostream>
using namespace std;
// #include <math>

// -- additional_libraries
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <map>
#include <cmath>
#include <set>
#include <unordered_set>
#include <queue>
// -- additional_libraries -- azur3
#include "TimerClock.h" // For Performance Monitor
// Classes
class LRUCache {
public:
	LRUCache(int capacity) {
		// constructor Code
	}

	int get(int key) {
// -> retrieve element to
		// -> move back element
// -> if not present then return -1
	}

	void put(int key, int value) {
// -> add Node the the end of D_LL
	}
};
// Functions
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// -- Main Function code --
	LRUCache* obj = new LRUCache(capacity);
	int param_1 = obj->get(key);
	obj->put(key, value);

	return 0;
}

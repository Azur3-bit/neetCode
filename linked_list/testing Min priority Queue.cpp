// testing Min priority Queue
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

// Functions
template <typename type_2>
void _showVector(const vector<type_2> &nums)
{
	cout << ":: Printing Vector :: " << endl;
	cout << "{ ";
	for (type_2 it : nums)
	{
		cout << it << " ";
	}
	cout << "}";
	cout << endl;
	cout << ":: Vector Printed :: " << endl;
}
void _showPriority_queue(priority_queue<int, vector<int> , greater<int>> &pq) {
	cout << "prinitnig priority_queue\n";
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
}
void _showPriority_queue_pair(priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> &pq) {
	cout << "prinitnig priority_queue\n";
	while (!pq.empty()) {
		cout << pq.top().first << "\t" << pq.top().second << endl;
		pq.pop();
	}
}
int main(int argc, char const * argv[])
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// -- Main Function code --
	vector<int> nums = {10, 2, 3, 4, 5, 6,  7, 8, 9, 1};
	vector<int> nums_subpart = {1000, 200, 300, 400, 500, 600,  700, 800, 900, 1};
	_showVector(nums);

	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
	for (int i = 0 ; i < nums.size() ; i++) {
		pq.push(make_pair(nums[i], nums_subpart[i]));
	}
	_showPriority_queue_pair(pq);

	return 0;
}

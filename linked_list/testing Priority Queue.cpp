// testing Priority Queue
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
template <typename type_1>
void _input(vector<type_1> &nums)
{
	type_1 input;
	while (cin >> input)
	{
		nums.push_back(input);
		if (cin.peek() == '\n')
			break;
	}
	cout << endl;
}
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
void _showPriortiyQueue(priority_queue<int> &pq) {
	while (!pq.empty()) {
		if (pq.top() < 0 )
			cout << -1 * pq.top() << " ";
		else
			cout << pq.top() << " " ;
		pq.pop();
	}
	cout << "\nPriority Queue Printed\n";
}
void vector_priortiyQueue(const vector<int> &v , priority_queue<int> &pq) {
	for (int it : v)
		pq.push(it);
	_showPriortiyQueue(pq);
}
void vector_priortiyQueue_minQueue(const vector<int> &v, priority_queue<int> &pq) {
	for (auto it : v)
		pq.push((-1 * it));
	_showPriortiyQueue(pq);
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif

	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// -- Main Function code --

	cout << "Priortiy Queue Testing \n";
	vector<int> v {};
	priority_queue<int> max_pq {};
	priority_queue<int> min_pq {};
	_input(v);
	_showVector(v);
	vector_priortiyQueue(v, max_pq);
	vector_priortiyQueue_minQueue(v, min_pq);

	// create a priority Queue using a pair data structure

	return 0;
}

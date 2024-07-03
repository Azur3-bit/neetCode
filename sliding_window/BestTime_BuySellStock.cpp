// Essential libraries
#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
// Additional libraries
#include <stack>
#include <array>
#include <unordered_map>
#include <climits>
#include <unordered_set>
#include "TimerClock.h" // For Performance Monitor
using namespace std;
#define debug(x) cout << "\n"<<  #x  << " : " << x << endl;
// Operator overloads
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "[";
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)
			os << ", ";
	}
	os << "]";
	return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {
	T element;
	while (is >> element) {
		vec.push_back(element);
	}
	return is;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& m) {
	for (const auto& it : m)
		os << it.first << " : " << it.second << "\n";
	return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
	os << "[";
	for (auto it = s.begin(); it != s.end(); ++it) {
		os << *it;
		if (next(it) != s.end())
			os << ", ";
	}
	os << "]";
	return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
void sometime_correct_sometime_wrong(vector<int> &prices) {
	cout << "input vector ";
	debug(prices);

	int minimum = INT_MAX, maximum = 0, profit = 0, i = 0;
	int size = prices.size();
	cout << "---------------------\n";
	for (int i = 0; i < size - 1; i++) {
		int j = i + 1;
		if (minimum > min(minimum, prices[i])) {
			minimum = min(minimum, prices[i]);
			debug(prices[i]);
		}
		// else
		// continue;
		if (maximum < max(maximum, prices[j])) {
			maximum = max(maximum, prices[j]);
			debug(prices[j]);
		}
		profit = max(profit, maximum - minimum);
	}
	cout << "----------------final Answer\n";
	debug(maximum);
	debug(minimum);
	debug(profit);
}
// ------------------------------------------------------------------
void solve(vector<int> &prices) {
	// Main code goes here
	// sometime_correct_sometime_wrong(prices);
	if
	debug(prices.size());
	int front = 0;
	int profit = 0;
	int minimum = INT_MAX;
	// fixing the back pointer
	while (front < prices.size()) {
		// debug(prices[front]);
		int back = front + 1;
		minimum = min(minimum, prices[front]);
		profit = max(profit, prices[back] - minimum);
		front++;
		back++;
	}
	debug(minimum);
	debug(profit);
}
// ------------------------------------------------------------------
int main(int argc, char const * argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	// Faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// Main function code here
	int t = 1;
	// cin >> t;
	while (t--) {
		vector<int> v {};
		cin >> v;
		debug(v);
		solve(v);
	}
	return 0;
}

// ReverseNodes - subProblem - array
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
#include <unordered_set>
#include "TimerClock.h" // For Performance Monitor
using namespace std;
#define debug(x) cout << #x  << " : " << x << endl;
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
// vector<int> Reverse_kGroups(std::vector<int> nums) {
void _printingNestedVector(vector<vector<int>> &nums) {
	for (auto it : nums) {
		cout << nums << " " ;
	}
}
// reving vector
vector<int> Reving_vector(vector<int> nums) {
	int front = 0;
	int back = nums.size() - 1;
	while (front <= back) {
		debug(nums[front]);
		debug(nums[back]);
		swap(nums[front], nums[back]);
		front++;
		back--;
		cout << "------------------\n";
	}
	return nums;
}

void Reverse_kGroups(std::vector<int> nums) {
	// personal Notes
	// groups 				index
	// groups 1 = {1,2} 	0 , 1
	// groups 2 = {3,4} 	2 , 3
	// groups 3 = {5,6}		4 , 5
	// groups 4 = {6,7}		6 , 7
	// groups 5 = {8,9}		8 , 9
	int k = 2;
	int j = 0;
	int size = nums.size();
	debug(size);
	vector<vector<int>> ans{};
	vector<int> temp{};
	for (int i = 0; i < size ; i++) {
		temp.push_back(nums[i]);
		debug(temp);
		if (temp.size() == k ) {
			ans.push_back(temp);
			temp = {};
		}
	}
	_printingNestedVector(ans);
	for (int i = 0 ; i < ans.size(); i++) {
		ans[i] = Reving_vector(ans[i]);
	}
	cout << "\n------------------------------\n";
	for (auto it : ans) {
		for (int i : it)
			cout << i << " ";
	}
}
// ------------------------------------------------------------------
void solve() {
	// Main code goes here
	vector<int> nums = {1, 2, 3 , 4, 5, 6 , 7 , 8 , 9 , 10};
	// vector<int> nums {};
	// cin >> nums;
	// cout << nums;
	debug(nums);
	Reverse_kGroups(nums);
	// debug(nums);
	// Reving_vector(nums);
	// debug(nums);
}
// ------------------------------------------------------------------
int main(int argc, char const* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// freopen("input.txt", "w", stdout);

#endif
	// Faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// Main function code here
	int t = 1;
	// cin >> t;
	while (t--) {solve();}
	return 0;
}

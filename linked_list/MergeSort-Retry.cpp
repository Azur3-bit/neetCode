// MergeSort - Retry
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
void Merge(vector<int> &nums, int start, int mid, int end) {
	int right = start;
	int left = mid + 1;
	vector<int> ans(end - start + 1,  0);
	int index = 0;
	while (right <= mid && left <= end) {
		if (nums[right] <= nums[left])
			ans[index++] = nums[right++];
		else
			ans[index++] = nums[left++];
	}
	// adding rem elements
	while (right <= mid)
		ans[index++] = nums[right++];
	while (left <= end)
		ans[index++] = nums[left++];

	for (int i = start; i <= end ; i++) {
		nums[i] = ans[i - start];
	}
}
void ms(vector<int> &nums, int start, int end) {
	if (start == end)
		return;
	int mid = (start + end) / 2;
	ms(nums, start, mid);
	ms(nums, mid + 1, end);
	Merge(nums, start, mid, end);
}
// ------------------------------------------------------------------
void solve() {
	// Main code goes here
	std::vector<int> v;
	cin >> v ;
	vector<int> ex_vec = v ;
	cout << "  input Array : " << v  << "\n";
	int size = v.size() - 1;
	ms(v, 0, size);
	cout << "output vector : " << v  << "\n";
	sort(ex_vec.begin() , ex_vec.end());
	cout << "expted vector : " << ex_vec << "\n";

	if (ex_vec == v)
		cout << "=== correct ans\n";
	else
		cout << "=== wrong ans\n";
}
// ------------------------------------------------------------------
int main(int argc, char const* argv[]) {
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
	while (t--) {solve();}
	return 0;
}

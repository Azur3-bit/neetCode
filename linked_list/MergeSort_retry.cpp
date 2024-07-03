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
void merge(vector<int> &nums, int start, int mid, int end) {
	vector<int> ans(end - start + 1, 0);
	int left = start;
	int right = mid + 1;
	int index = 0;
	while (left <= mid && right <= end) {
		if (nums[left] <= nums[right]) {
			// cout << "inside condition\n";
			ans[index++] = nums[left++];
		}
		else
			ans[index++] = nums[right++];
	}
	// adding rem elements
	while (left <= mid)
		ans[index++] = nums[left++];
	while (right <= end)
		ans[index++] = nums[right++];
	// replacing elements in the original vector
	for (int i = start; i <= end; i++)
		nums[i] = ans[i - start];
}
vector<int> ms(vector<int> &nums, int start, int end) {
	if (start == end)
		return {};
	int mid = (start + end) / 2;
	ms(nums, start, mid);
	ms(nums, mid + 1, end);
	merge(nums, start, mid, end); return nums;
}
// ------------------------------------------------------------------
void solve() {
	// Main code goes here
	vector<int> tet_vec {};
	cin >> tet_vec;
	vector<int> exp_v = tet_vec;
	cout << "inp_vec : " << tet_vec << "\n";
	sort(exp_v.begin(), exp_v.end());
	vector<int> ans_vec = ms(tet_vec, 0, tet_vec.size() - 1);
	// cout << "receivd vector : " << v << "\n";
	debug(ans_vec);
	// cout << "expectd vector : " << exp_v << "\n";
	debug(tet_vec);
	if (tet_vec == exp_v)
		cout << "=== correct answer \n";
	else
		cout << "=== wrong answer\n";

	cout << "----------------\n";
	debug(ans_vec);
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

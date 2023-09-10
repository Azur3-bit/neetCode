// MergeSort
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

void Merge(vector<int> &arr, int low, int mid, int high) {
	vector<int> temp {};
	int left = low;
	int right = mid + 1;
	while (left <= mid && right <= high) {
		if (arr[left] <= arr[right]) {
			temp.push_back(arr[left]);
			left++;
		}
		else {
			temp.push_back(arr[right]);
			right++;
		}
	}
	// adding Remaining Elements
	while (left <= mid) {
		temp.push_back(arr[left]);
		left++;
	}
	while (right <= high) {
		temp.push_back(arr[right]);
		right++;
	}

	for (int i = low; i <= high ; i++) {
		arr[i] = temp[i - low];
	}


}

// merge Sort
void MS(vector<int> &arr , int low , int high ) {
	// Base Case -> Array is either of singular ELement or it might have zero
	// element
	if (low >= high)
		return;
	int mid = (low + high) / 2;
	MS(arr, low, mid);
	MS(arr , mid + 1 , high);

	Merge(arr, low, mid, high);

	// cout << arr << "\n";
}
// ------------------------------------------------------------------
void solve() {
	// Main code goes here
	cout << "working\n";
	// vector<int> arr  = {3, 1, 2, 4, 1, 5, 2, 6, 4};
	vector<int> arr {};
	cin >> arr;
	vector<int> org_array = arr ;
	cout << " input array : " << arr << "\n";
	int size = arr.size();
	int last = size - 1;
	MS(arr, 0 , last );
	cout << "obtaine temp : " << arr << "\n";
	sort(org_array.begin() , org_array.end());
	cout << "correct temp : " << org_array << "\n";
	// org_array.push_back(100);

	if (arr == org_array)
		cout << " === correct Output \n";
	else
		cout << " === wrong Output \n";


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

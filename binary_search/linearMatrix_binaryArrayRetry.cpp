// linearMatrix_binaryArray
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <array>
#include <unordered_map>
#include <unordered_set>
// #include "TimerClock.h" // For Performance Monitor
using namespace std;
#define dbg(x) cout <<  #x  << " : " << x << "\n";
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {os << "["; for (int i = 0; i < v.size(); ++i) {os << v[i]; if (i != v.size() - 1)os << ", ";} os << "]"; return os;}
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {T element; while (is >> element) {vec.push_back(element);} return is;}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& m) {cout << "---- Printing Ordered - Map\nKEY\tVALUE\n"; for (const auto& it : m)os << it.first << "\t" << it.second << "\n"; return os;}
template <typename T, typename S>
ostream& operator<<(ostream& os, const unordered_map<T, S>& m) {cout << "---- Printing Unordered - Map\nKEY\tVALUE\n"; for (const auto& it : m)os << it.first << "\t" << it.second << "\n"; return os;}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {os << "["; for (auto it = s.begin(); it != s.end(); ++it) {os << *it; if (next(it) != s.end())os << ", ";} os << "]"; return os;}
template <typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& s) {os << "["; for (auto it = s.begin(); it != s.end(); ++it) {os << *it; if (next(it) != s.end())os << ", ";} os << "]"; return os;}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& p) {os << "(" << p.first << ", " << p.second << ")"; return os;}
struct ListNode {int val; ListNode * next; ListNode (int _val) : val(_val), next(nullptr) {}};
void AddNode_end(ListNode *&head, int value) {ListNode *newNode = new ListNode(value); if (head == NULL) {head = newNode; return;} ListNode *temp = head; while (temp->next != NULL) {temp = temp->next;} temp->next = newNode;}
void _showLinkedList(ListNode *head) {while (head != NULL) {cout << head->val << " -> "; head = head->next;} cout << "NULL" << endl;}
void vec_linkedlist(ListNode*&head, vector<int> nums ) {for (auto it : nums) {AddNode_end(head, it);}}
// ------------------------------------------------------------------ solve
bool binarySearch(vector<int> &nums, int target) {
	dbg(nums);
	int l = 0;
	int r = nums.size() - 1;
	while (r - l > 1) {
		int mid = l + (r - l) / 2;
		if (nums[mid] < target)
			l = mid + 1;
		else
			r = mid;
	}
	// dbg(l);
	if (nums[l] == target) {
		cout << "element found at index : " << l << "\n";
		return true;
	}
	if (nums[r] == target) {
		cout << "element found at index : " << r << "\n";
		return true;
	}
	return false;
}
bool matrix(vector<vector<int>> &nums, int target) {
	int last_element_index = nums[0].size() - 1;
	for (int i = 0; i < nums.size(); i++) {
		dbg(nums[i][0]);
		dbg(nums[i][nums.size()]);
		if (target >= nums[i][0] && target <= nums[i][last_element_index]) {
			// if (target >= nums[i][0] && target >= nums[i][nums[0].size()]) {
			cout << "range found in the vector : " << i << "\n";
			dbg(nums[i]);
			int ans = binarySearch(nums[i], target);
			return ans;
		}
		cout << "----------------\n";
	}
	return false;
}
void solve() {
	int target = 3;
	// cout << "working \n";
	vector<vector<int>> nums = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
	dbg(nums);
	dbg(target);
	// testing binary Seach
	// vector<int> test = {1, 3, 5, 7};
	// dbg(test);
	int ans = matrix(nums, target);
	if (ans)
		cout << "*** main *** -- element found\n";
	else
		cout << "*** main *** -- element NOT found\n";
}
// ------------------------------------------------------------------ main
int main(int argc, char const* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while (t--) {solve();}
	return 0;
}

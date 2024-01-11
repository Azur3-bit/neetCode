// linearMatrix - binaryArray

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
	cout << "binarySeach in progress ... \n";
	dbg(nums);
	int l = 0;
	int h = nums.size() - 1;
	dbg(l);
	dbg(h);
	while (h - l > 1) {
		int mid = l + (h - l) / 2;
		if (nums[mid] <= target)
			l = mid + 1;
		else
			h = mid;
	}
	if (nums[h] == target) {
		cout << "element found in binarySeach at h\n";
		return true;
	}
	if (nums[l] == target) {
		cout << "element found in binarySeach at l\n";
		return true;
	}
	return false;
}
bool linearMatrix_binaryArray(vector<vector<int>> &nums, int target) {

	int rows = nums.size() - 1;
	int cols = nums[0].size() - 1 ;
	dbg(rows);
	dbg(cols);
	for (int i = 0; i <= rows; i++) {
		// if this is true then go ahead with binarySeach
		if (target >= nums[i][0] && target <= nums[i][cols]) {
			cout << "going ahead with binarySeach in col : " << i << "\n";
			bool ans = binarySearch(nums[i], target);
			return ans;
		}
	}
	return false;
}
void solve() {
	vector<vector<int>> nums = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
	int target = 100;
	dbg(nums);
	dbg(target);
	bool ans = linearMatrix_binaryArray(nums, target);
	if (ans)
		cout << "answer is true \n";
	else
		cout << "answer is false \n";
	// vector<int> test = {1, 3, 5, 7};
	// binarySearch(test, target);
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

// revise - search2dMatrix

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
bool linear_ans(vector<vector<int>> vec, int target) {
	dbg(vec);
	dbg(target);

	for (auto it : vec) {
		for (int i : it)
			if (i == target)
				return true;
	}
	return false;
}
bool bin_search(vector<int> vec, int target) {
	cout << "bin_search\n";
	int min = 0;
	int max = vec.size() - 1;
	while (max - min > 1) {
		int mid = min + (max - min) / 2;
		if (vec[mid] <= target)
			min = mid;
		else
			max = mid;
	}
	if (vec[min] == target)
		return true;
	if (vec[max] == target)
		return true;
	return false;
}
bool n_plus_logM_ans(vector<vector<int>> vec, int target) {
	dbg(target);
	int rows = vec.size() - 1;
	int cols = vec[0].size() - 1;
	dbg(rows);
	dbg(cols);
	int row = 0;
	for (int i = 0; i < cols; i++) {
		vector<int> curr_vec = vec[i];
		// dbg(curr_vec[0]);
		// dbg(curr_vec[cols]);
		if (curr_vec[0] <= target && curr_vec[cols] >= target) {
			dbg(curr_vec);
			bool final_answer = bin_search(curr_vec, target);
			return final_answer;
			// cout << "the answer might be in this vector, index : " << i << "\n";
			// dbg(curr_vec);
		}
		else {
			cout << "continue .. \n";
			continue;
		}
	}
	return false;
}
bool row_and_col(vector<vector<int>> nums, int target) {
	dbg(nums);
	dbg(target);
	int total_rows = nums.size() - 1, total_cols = nums[0].size() - 1;
	int row = 0 , col = total_cols;
	dbg(total_rows);
	dbg(total_cols);
	while (row <= total_rows && col > -1) {
		// cout << ".\n";
		if (nums[row][col] == target)
			return true;
		if (target > nums[row][col])
			row++;
		else
			col--;
	}
	return false;
}
void solve() {
	vector<vector<int>> vec = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
	// bool answer = linear_ans(vec, target);
	int target = 59;
	// bool answer = n_plus_logM_ans(vec, target);
	bool answer = row_and_col(vec, target);
	if (answer)
		cout << "++ value has been found in the matrix\n";
	else
		cout << "-- value has NOT been found in the matrix\n";
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

// true_and_false_binarySearch
// finding the first false in the array of elements consisting of only true and false

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
void printing_bool_vector(const vector<bool> &nums) {
	int ctr = 0;
	for (auto it : nums) {
		if (it == true)
			cout << ctr << ". true\n";
		else
			cout << ctr << ". false\n";
		++ctr;
	}
}
void printing_vector_using_index(const vector<bool> &ans, int start, int end) {
	cout << "[ ";
	for (int i = start; i < end; ++i) {
		cout << ans[i] << ", ";
	}
	cout << "]\n";
}
int finding_first_false(const vector<bool> &ans) {
	cout << "finding first false using binary Search \n";
	int start = -1;
	int end = ans.size();
	while (end - start > 1) {
		int mid = start + (end - start) / 2;
		if (ans[mid]) {
			start = mid;
		}
		else
			end = mid;
	}
	// print the index of first false
	cout <<  "index of first false : " << start << "\n";
	// print the index of last true
	return end;
}
void solve() {
	vector<bool> vec {};
	cin >> vec;
	dbg(vec);
	printing_bool_vector(vec);
	int first_false_index = finding_first_false(vec);
	cout << "The index of first false is : " << first_false_index << "\n";
}
// ------------------------------------------------------------------ main
int main(int argc, char const * argv[]) {
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

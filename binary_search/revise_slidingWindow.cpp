// revise_slidingWindow
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
void print_vector(vector<int> nums, int low, int high) {
	for (int i = low; i <= high; i++) {
		cout << nums[i] << " ";
	}
	cout << "\n";
}
bool check_palindrome(string s) {
	int low = 0;
	int high = s.size() - 1;
	dbg(s[high]);
	while (high > low) {
		if (s[low] != s[high])
			return false;
		low++;
		high--;
	}
	// cout << "end of palindrome\n";
	return true;
}
void print_String(string s, int min, int max) {
	for (int i = min; i <= max; i++) {
		cout << s[i] << " ";
	}
	cout << "end of string ... \n";
}
void sliding_window(string s) {
	// maintain size of 2
	dbg(s);
	int low = 0;
	int high = 0;
	int longest_answer = INT_MAX;
	// dbg(longest_answer);
	dbg(s.size() - 1);
	// print_String(s, low, high);
	int global_start = 0;
	while (global_start <= s.size() - 1) {
		// sliding window
		while ()
		}
	cout << "end \n";
}
void solve() {
	// vector<int> nums = {7, 1, 5, 3, 6, 4};
	string s = "babad";
	sliding_window(s);
	// int ans = check_palindrome(s);
	// if (ans)
	// 	cout << "palindrome\n";
	// else
	// 	cout << "not a palindrome\n";
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

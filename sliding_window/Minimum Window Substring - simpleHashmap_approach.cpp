// Minimum Window Substring

// simple HASH-Map Approach
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
char check_allElements(const unordered_map<int, char> &HM, string t) {
	return 'a';
}

void solve() {
	string s, t;
	cin >> s;
	cin >> t;
	dbg(s);
	dbg(t);
	// unordered_map<int, char> HM_core {};
	map<int, char> HM {};

#if 0
	// entering element in the core HashMap
	// not very usefull
	for (int i = 0; i < t.size(); i++) {
		HM_core.insert(make_pair(i, t[i]));
	}
	dbg(HM_core);
#endif
	// vector<vector<char, int>> vec_map {};
	for (int i = 0; i < t.size(); ++i) {
		int index = 0;
		char ele = t[i];
		cout << "finding element : " << ele << "\n";
		int size = s.size();
		while (size--) {
			if (s[index] == ele) {
				HM.insert(make_pair(index, s[index]));
			}
			++index;
		}
	}
	// creating set of all the elements in target string
	unordered_set<char> set_map {};
	for (auto it : t)
		set_map.insert(it);
	unordered_set<char> principle_setMap = set_map;
	cout << "\n";
	// getting the index of whole sequence by traversing the hashmap
	vector<pair<int, int>> sequence_numbers;
	for (auto it : HM) {
		char element = it.first;
		if (set_map.find(element) != set_map.end()) {
			set_map.erase(element);
		}
		if (set_map.empty()) {
			cout << "set_map found to be emp ty\n";
			set_map = principle_setMap;
			auto start = HM.begin()->first;
			sequence_numbers.push_back({start, it.first});
			HM.erase(start);
		}
	}
	dbg(sequence_numbers);
	dbg(set_map);
	dbg(HM);
}
// ------------------------------------------------------------------ main
int main(int argc, char const* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while (t--) {solve();}
	return 0;
}

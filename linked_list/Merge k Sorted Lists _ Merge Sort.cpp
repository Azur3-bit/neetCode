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
// structure of linked list
struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(nullptr) {}
};
// printing Linked list
void _showLinkedList(ListNode * head) {
	while (head) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "end\n";
}
void _showLinkedList_using_vector(vector<ListNode *> nums) {
	for (auto it : nums)
		_showLinkedList(it);
}
// ------------------------------------------------------------------
// ListNode *solve(vector<ListNode *> &nums) {
void solve(vector<ListNode *> &nums) {
	// Main code goes here
	cout << "merge sort K sorted Linked lists \n";
	_showLinkedList_using_vector(nums);

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
	// create all the linked list Nodes
	ListNode * first = new ListNode(1);
	ListNode * forth = new ListNode(4);
	ListNode * fifth = new ListNode(5);
	// linking
	first->next = forth;
	forth->next = fifth;
	fifth->next = nullptr;

	ListNode * first_1 = new ListNode(1);
	ListNode * third_1 = new ListNode(3);
	ListNode * forth_1 = new ListNode(4);

	// linking
	first_1->next = third_1;
	third_1->next = forth_1;
	forth_1->next = nullptr;

	ListNode * second_2 = new ListNode(2);
	ListNode * sixth_2 = new ListNode(6);
	// linking
	second_2->next = sixth_2;
	sixth_2->next = nullptr;

	// linking heads
	ListNode * head_1 = first;
	ListNode * head_2 = first_1;
	ListNode * head_3 = second_2;

	vector<ListNode *> nums = {first, first_1, second_2};
	while (t--) {solve(nums);}
	return 0;
}

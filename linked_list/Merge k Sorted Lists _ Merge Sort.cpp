// Merge K sorted Lists - MergeSort
// failed test case -> [[],[-1,5,11],[],[6,10]]
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
// structure of ListNode
struct ListNode {
	int val;
	ListNode * next;
	ListNode(int _val) : val(_val), next(nullptr)  {}
};
// show linked list
void _showLinkedList(ListNode * head) {
	while (head) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "end\n";
}
// Show linked list using vector
void _showLinkedList_using_vector(vector<ListNode *> nums) {
	for (auto it : nums)
		_showLinkedList(it);
}
ListNode * merge(ListNode *head_1 , ListNode * head_2) {
	ListNode * senHead = new ListNode(100);
	ListNode * curr = senHead;
	while (head_1 && head_2) {
		if (head_1->val < head_2->val) {
			curr->next = head_1;
			head_1 = head_1->next;
		}
		else {
			curr->next = head_2;
			head_2 = head_2->next;
		}
		curr = curr->next;
	}
	// Adding rem elements
	while (head_1) {
		curr->next = head_1;
		curr = curr->next;
		head_1 = head_1->next;
	}
	while (head_2) {
		curr->next = head_2;
		curr = curr->next;
		head_2 = head_2->next;
	}
	// returning value
	ListNode * mergeredList = senHead->next;
	delete senHead;
	return mergeredList;
}
ListNode * mergeSort(vector<ListNode *> &lists, int start, int end) {
// base case
	if (start == end)
		return lists[start];
	int mid = (start + end) >> 1;
	// debug(mid);
	ListNode * left = mergeSort(lists, start, mid);
	ListNode * right = mergeSort(lists, mid + 1, end);
	ListNode * result = merge(left, right);
	return result;
}

// ------------------------------------------------------------------
void solve(vector<ListNode *> &lists) {
	// Main code goes here
	ListNode * ans = mergeSort(lists, 0, lists.size() - 1);
	_showLinkedList(ans);
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
	ListNode * first_1 = nullptr;


	// Linked list - 2
	ListNode * first_2 = new ListNode(-1);
	ListNode * second_2 = new ListNode(5);
	ListNode * third_2 = new ListNode(11);

	// Linking linked list - 2
	first_2->next = second_2;
	second_2->next = third_2;
	third_2->next = nullptr;

	// linked list - 3
	ListNode * first_3 = nullptr;

	// Linked list - 3
	ListNode * first_4 = new ListNode(6);
	ListNode * second_4 = new ListNode(10);

	// Linking linked list - 2
	first_4->next = second_4;
	second_4->next = nullptr;


	ListNode * head_1 = first_1;
	ListNode * head_2 = first_2;
	ListNode * head_3 = first_3;
	ListNode * head_4 = first_4;

	vector<ListNode * > lists = {head_1, head_2, head_3, head_4};
	while (t--) {solve(lists);}
	return 0;
}

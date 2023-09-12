// revising_reving Linked list
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
	ListNode (int _val) : val(_val), next(nullptr) {}
};
// pritning Linked list
void _showLinkedList(ListNode * head) {
	while (head) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "nullptr\n";
}
ListNode * _revingLinkedList(ListNode *head) {
	if (head == nullptr)
		return nullptr;
	if (head->next == nullptr)
		return head;
	// temp = prevElement
	// currentEle = currNode
	ListNode * currNode = head;
	ListNode * temp = nullptr;
	while (currNode) {
		ListNode * nextNode = currNode->next;
		currNode->next = temp;

		// nextNode->next = currNode; -> creates cycle and hence programs goes into an infinte loop
		temp = currNode;
		currNode = nextNode;
	}
	head = temp;
	return head;
	// null -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null
	// temp  curr  nxt
}
// ------------------------------------------------------------------
void solve(ListNode * head) {
	// Main code goes here
	cout << "working fine\n";
	// __ create a linked list
	// __ insert nodes in it
	_showLinkedList(head);
	// reverse the linked list
	ListNode * newList = _revingLinkedList(head);
	_showLinkedList(newList);
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
	// ListNode
	ListNode * first = new ListNode(1);
	ListNode * second = new ListNode(2);
	ListNode * third = new ListNode(3);
	ListNode * forth = new ListNode(4);
	ListNode * fifth = new ListNode(5);
	ListNode * sixth = new ListNode(6);
	// linking Nodes
	first->next = second;
	second->next = third;
	third->next = forth;
	forth->next = fifth;
	fifth->next = sixth;
	sixth->next = nullptr;
	// linking HEAD
	ListNode * HEAD = first;
	while (t--) {solve(HEAD);}
	return 0;
}

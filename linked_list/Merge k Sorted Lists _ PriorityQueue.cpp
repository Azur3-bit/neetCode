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
// ------------------------------------------------------------------
struct ListNode {
	int val;
	ListNode * next;
	ListNode() : val(0) , next(nullptr) {}
	ListNode (int value) : val(value) , next(nullptr) {}
	ListNode (int value , ListNode * nxt) : val(value) , next(nxt) {}
};

// printing Linked list
void _showLinkedList(ListNode * head) {
	while (head) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "nullptr\n";
}

// printing Linked list using vector
void _showLinkedList_using_vector(vector<ListNode *> &lists) {
	for (auto it : lists) {
		_showLinkedList(it);
	}
}

// print Prioroty Queue
void _showPriortiyQueue(priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>> , greater<pair<int , ListNode *>>> &nums) {
	cout << "int\tListNode *\n";
	// cout << pq.top().first << "\t" << pq.top().second << "\n";
	while (!nums.empty()) {
		cout << nums.top().first << "\t" << nums.top().second << "\n";
		nums.pop();
	}
}

// ListNode * solve(vector<ListNode *> &lists) {

// #if 0
void solve(vector<ListNode *> &lists) {
	// Main code goes here

	// _showLinkedList(head_1);
	// _showLinkedList(head_2);
	// _showLinkedList(head_3);
	// cout << "printing using vector \n";
	_showLinkedList_using_vector(lists);

	// min heap has to be used
	// queue -> key(sort) , value(ListNode * ) [adddress]
	// link -> using an iterator one by one in the priority queue

	priority_queue<pair<int, ListNode *> , vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> nums {};

	for (auto it : lists) {
		ListNode * head = it;
		cout << "it : " << it << "\n";
		cout << "HEAD\n";
		while (head) {
			cout << head << " -> ";
			nums.push(make_pair(head->val , head));
			head = head->next;
		}
		cout << "end\n";
	}

	_showPriortiyQueue(nums);


}
// #endif
// ------------------------------------------------------------------
int main(int argc, char const * argv[]) {
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
	cout << "Priortiy Queue - Merge K sorted Linked List \n";

	// 	Linked list - 1
	ListNode * first_1 = new ListNode(1);
	ListNode * second_1 = new ListNode(4);
	ListNode * third_1 = new ListNode(3);
	// Linking Linked list - 1
	first_1->next = second_1;
	second_1->next = third_1;
	third_1->next = nullptr;

	// Linked list - 2
	ListNode * first_2 = new ListNode(1);
	ListNode * second_2 = new ListNode(3);
	ListNode * third_2 = new ListNode(4);

	// Linking linked list - 2
	first_2->next = second_2;
	second_2->next = third_2;
	third_2->next = nullptr;

	// linked list - 3
	ListNode * first_3 = new ListNode(2);
	ListNode * second_3 = new ListNode(6);

	// linking linked list - 3
	first_3->next = second_3;
	second_3->next = nullptr;

	ListNode * head_1 = first_1;
	ListNode * head_2 = first_2;
	ListNode * head_3 = first_3;

	vector<ListNode * > lists = {head_1, head_2, head_3};

#if 0
	// testing Priority Queue
	priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>> , greater<pair<int, ListNode *>>> pq {};


	cout << "first_1 : " << head_1 << endl;
	cout << "first_2 : " << head_2 << endl;
	cout << "first_3 : " << head_3 << endl;
	pq.push(make_pair(head_1->val , head_1));
	pq.push(make_pair(head_2->val , head_2));
	pq.push(make_pair(head_3->val , head_3));


	_showLinkedList_using_vector(lists);

	// printing Priority Queue one by one
	cout << "printing priority_queue one by one\n";
	_showPriortiyQueue(pq);

#endif
	while (t--) {solve(lists);}
	return 0;
}

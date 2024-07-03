// optimal ReverseNodes - subProblem - array

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
#define debug(x) cout << "\n"<<  #x  << " : " << x << endl;
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
// structur of linked list
struct ListNode {
	int val;
	ListNode * next;
	ListNode (int _val) : val(_val), next(nullptr) {}
};
// print linked list
void _showLinkedList(ListNode * head) {
	while (head) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "nullptr\n";
}
// printing nested Vector
void _showNestedVector(vector<vector<int>> &nums) {
	for (auto it : nums)
		cout << it ;
	cout << "\n";
}
// reving Linked list
// void Reving_linkedList(ListNode *&start) {
ListNode * Reving_linkedList(ListNode *&start, ListNode *&end) {
	// base cases
	if (start == nullptr || start->next == nullptr)
		return start;
	// n <- 1 <- 2 -> nullptr
	// 			 p   c    n
	ListNode * currNode = start;
	ListNode * p = nullptr;
	ListNode * actual_startNode = start;
	while (p != end) {
		ListNode * n = currNode->next;
		currNode->next = p;
		p = currNode;
		currNode = n;
	}
	start = p;
	// debug(start->val);
	// return p;
	return end;
	// retrurn value -> should return the new Head
}
// ------------------------------------------------------------------
ListNode * solve(ListNode *&head ) {
	// Main code goes here

	// Base Cases
	if (head == nullptr)
		return nullptr;
	if (head->next == nullptr)
		return head;
	// Normal Fucntion
	// creating a senHead
	ListNode *senHead = new ListNode(-100);
	senHead->next = head;
	// cout << "working on this \n";
	// _showLinkedList(senHead->next);
	// Getting all the subgroups for the linked list
	ListNode * currNode = head;
	int k = 2;
	int counter = 0;
	// ctr = 0
	vector<int> nums {};
	// nums = {}
	vector<vector<int>> ans{};
	vector<int> heads {};
	// ans = {}

// ************** ALGORITHM **************
	// iter - 1
	// 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
	// p1   p2   p3
	// Reverse list from p1 to p2
	// 2  	-> 	1 	-> 	null
	// return 	start
	// -> 3 -> 4 -> 5 -> nullptr
	// return->next = p3
	// 2 -> 1 -> 3 -> 4 -> 5 -> nullptr

	// iter - 2
	// 2 -> 1 -> 3 -> 4 -> 5 -> null
	// 			p1    p2   p3
	// reverse list from p1 to p2
	// 2 -> 1 ->	 4 -> 	3 ->
	// 			 	return  start
	// 2 -> 1 ->	 4 -> 	3 ->
	// return -> next = p3
	//  2 -> 1 ->	 4 -> 	3 -> 5 -> null

	// ---------------------------------------------------- start temp fuction
	// 1 -> 2 -> 3  -> nullptr
	// p1   p2   p3
	// creating new Linked list for testing
	ListNode * test_1 = new ListNode(1);
	ListNode * test_2 = new ListNode(2);
	ListNode * test_3 = new ListNode(3);
	// linking
	test_1 -> next = test_2;
	test_2 -> next = test_3;
	test_3 -> next = nullptr;
	cout << "printing test - 1\n";
	_showLinkedList(test_1);

	// pointers required
	ListNode * p1 = test_1;
	ListNode * prev_head = p1;
	ListNode * p2 = test_1->next;
	ListNode * p3 = p2->next;
	// storing Return Value
	ListNode * returnNode = Reving_linkedList(p1, p2);
	// creating senHead Linkage
	ListNode * newHead = returnNode; // creating senHead
	_showLinkedList(newHead);
	cout << "-----\n";
	// linking to rest of the linked list
	prev_head->next = p3;
	_showLinkedList(newHead);

	// follow up store the prev of rev(start) ka start ka prev for example senHead for first iteration and link the p1 to prev_start
	// ex: senHead->next = prev_start
	// -------------------------------------------------------- end temp fuction
	// while (currNode) {
	// 	// cout << "current Node => " << currNode->val << " ";
	// 	// ctr = 2
	// 	if (counter == k) {
	// 		// skip - 1
	// 		// group max size reached
	// 		debug(nums);
	// 		ans.push_back(nums);
	// 		heads.push_back(nums[nums.size() - 1]);
	// 		nums = {};
	// 		counter = 0;
	// 	}
	// 	// nums = {1 , 2}
	// 	nums.push_back(currNode->val);
	// 	// currNode = 2
	// 	counter++;
	// 	currNode = currNode->next;
	// }
	// cout << "final Groups of the linked list \n";
	// cout << nums;
	// cout << "printing ans \n";
	// _showNestedVector(ans);
	// cout << "printing all the heads of the linked list \n";
	// cout << heads;
	// temp function -----------------------

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

	ListNode * first = new ListNode(1);
	ListNode * second = new ListNode(2);
	ListNode * third = new ListNode(3);
	ListNode * forth = new ListNode(4);
	ListNode * fifth = new ListNode(5);
	// Linking Nodes
	first->next = second;
	second->next = third;
	third->next = forth;
	forth->next = fifth;
	fifth->next = nullptr;
	ListNode * head = first;
	// cin >> t;
	while (t--) {solve(head);}
#if 0
	// Debugging Code
	_showLinkedList(head);
	ListNode * end = third;
	Reving_linkedList(head, end);
	_showLinkedList(head);
#endif
	return 0;
}

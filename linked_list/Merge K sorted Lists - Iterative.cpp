// Merge K sorted Lists - Iterative
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
// structure of linked list
struct ListNode {
	int val;
	ListNode * next;
	ListNode(int _val) : val(_val), next(nullptr) {}
};
// print Linked list
void _showLinkedList(ListNode * head) {
	while (head) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "end\n";
}
// print linked list using vector
void _showLinkedList_using_vector(vector<ListNode *> nums) {
	for (auto it : nums)
		_showLinkedList(it);
}
ListNode * Merge(vector<ListNode *> &nums, int start, int mid, int end) {
	// debug(start);
	// debug(mid);
	// debug(end);
	ListNode * curr = new ListNode(100);
	ListNode * senHead = curr;
	// curr->next = senHead;
	ListNode * head_1 = nums[start];
	ListNode * head_2 = nums[mid + 1];
#if 0
	cout << "-----------------------------------TEST-2 \n";
	cout << "printing first linked list \n";
	for (int i = start; i <= mid; i++) {
		_showLinkedList(nums[i]);
	}
	cout << "printing second linked list \n";
	for (int i = mid + 1; i <= end; i++) {
		_showLinkedList(nums[i]);
	}
	cout << "-----------------------------------TEST-2 \n";
#endif
	cout << "head-1 : ";
	_showLinkedList(head_1);
	cout << "head-2 : ";
	_showLinkedList(head_2);
	while (head_1 && head_2) {
		// cout << "************* inside while loop \n";
		if (head_1->val > head_2->val) {
			senHead->next = head_2;
			senHead = senHead->next;
			head_2 = head_2->next;
		}
		else {
			senHead->next = head_1;
			senHead = senHead->next;
			head_1 = head_1->next;
		}
	}
	// adding rem Elements
	while (head_1) {
		// cout << "************* adding element " << head_2->val << "\n";
		senHead->next = head_1;
		head_1 = head_1->next;
		senHead = senHead->next;
	}
	// senHead->next = nullptr;
	while (head_2) {
		// cout << "===========================inside while loop \n";
		// cout << "************* adding element " << head_2->val << "\n";
		senHead->next = head_2;
		senHead = senHead->next;
		head_2 = head_2->next;
	}
	senHead->next = nullptr;
	ListNode * mergeList = curr->next;
	cout << "after Merging : ";
	_showLinkedList(mergeList);
	delete curr;
	return mergeList;
}
ListNode * MergeSort(vector<ListNode *> &nums, int start, int end) {
#if 0
	cout << "*/* ";
	debug(start);
	cout << "*/* ";
	debug(end);
	cout << "MergeSort Over linked list \n";
	cout << "-----------------------------------TEST-1\n";
	cout << "printing Current linked list \n";
	for (int i = start; i < end; i++) {
		_showLinkedList(nums[i]);
	}
	cout << "-----------------------------------TEST-1 \n";
#endif
	if (start == end)
		return nums[start];
	int mid = (start + end) / 2;
	MergeSort(nums, start, mid);
	MergeSort(nums, mid + 1 , end);
	return Merge(nums, start, mid, end);
}
// ------------------------------------------------------------------
void solve(vector<ListNode *> &lists) {
	// Main code goes here
	cout << "-------------------------\n";
	cout << "printing linked list \n";
	_showLinkedList_using_vector(lists);
	cout << "-------------------------\n";
	int size = lists.size();
	debug(size);
	ListNode * head = MergeSort(lists, 0, size - 1);
	cout << "answer : ";
	_showLinkedList(head);
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

	// 	Linked list - 1
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

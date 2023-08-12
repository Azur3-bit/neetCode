// Retry => reOrderLinkedList

// -- essential_libraries_and_namespace
#include <iostream>
using namespace std;
// #include <math>

// -- additional_libraries
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <map>
#include <cmath>
#include <set>
#include <unordered_set>
#include <queue>

// -- additional_libraries -- azur3
#include "TimerClock.h" // For Performance Monitor

// Classes

// Functions
// structure of linked list
struct ListNode {
	int val;
	ListNode * next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x ) : val(x), next(nullptr) {}
	ListNode(int x , ListNode*next) : val(0), next(next) {}
};
// creating a funciton to add nodes in a linked list
void AddNode_end(ListNode * &head, int val) {
	ListNode * newNode = new ListNode(val);
	if (head == nullptr) {
		head = newNode;
		return;
	}
	ListNode * temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
}
// traverse linked list
void _showLinkedList(ListNode *head) {
	while (head != nullptr) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "null\n";
}
// input vector
template <typename type_1>
void _input(vector<type_1> &nums)
{
	type_1 input;
	while (cin >> input)
	{
		nums.push_back(input);
		if (cin.peek() == '\n')
			break;
	}
	cout << endl;
}
// vector to linked list
void vec_linkedlist(ListNode *&head, vector<int> nums) {
	for (auto it : nums) {
		AddNode_end(head, it);
	}
	cout << "All Elements entered in the linked list\n";
}
// show vector
template <typename type_2>
void _showVector(const vector<type_2> &nums)
{
	cout << ":: Printing Vector :: " << endl;
	cout << "{ ";
	for (type_2 it : nums)
	{
		cout << it << " ";
	}
	cout << "}";
	cout << endl;
	cout << ":: Vector Printed :: " << endl;
}

void Reving_linkedList(ListNode *&head) {
	cout << "\nreving Linked List \n";
	ListNode * prev = nullptr;
	ListNode * curr = head;
	while (curr != nullptr) {
		ListNode * temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	head = prev;
}

ListNode*  Finding_mid_linkedList(ListNode * &head) {
	// cout << "\nfinding the middle of a linked list \n";
	ListNode *slow = head;
	ListNode *fast = head;
	// ListNode *slow = head;
	while (fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode * secondList = slow->next;
	// cout << "second List : " << head->next->val << endl;
	slow->next = nullptr;
	// cout << "value at mid : " << head->val << endl;
	return secondList;
}
void reOrder(ListNode*head) {
	// find and divide from mid of the linked list
	cout << " - reOrder - \n";
	ListNode * secondList = Finding_mid_linkedList(head);
	cout << "1st linked list : \n";
	_showLinkedList(head);
	cout << "2nd linked list : \n";
	_showLinkedList(secondList);
	// rev 2nd linked list
	Reving_linkedList(secondList);
	_showLinkedList(secondList);
	// combine both the linked list in zig zag manner
	// pointer manipulation
	ListNode * pri = head;
	while (head != nullptr && secondList != nullptr) {
		ListNode *p1 = head->next;
		ListNode *p2 = secondList->next;
		head->next = secondList;
		secondList->next = p1;
		head = p1;
		secondList = p2;
	}
	cout << "final Answer\n";
	_showLinkedList(pri);
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// -- Main Function code --
	ListNode *head = nullptr;
	vector<int> nums{};
	_input(nums);
	_showVector(nums);
	vec_linkedlist(head, nums);
	_showLinkedList(head);
	// Reving_linkedList(head);
	// _showLinkedList(head);
	// Finding_mid_linkedList(head);
	reOrder(head);
	return 0;
}

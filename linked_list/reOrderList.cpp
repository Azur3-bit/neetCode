// neetCode - reOrderList


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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// structure of node
struct ListNode {
	int val;
	ListNode *next;
// constructor of node
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode * next) : val(x), next(next) {}
};
//  insert at tail
void insertAt_tail(ListNode *&head, int val) {
	ListNode *newNode = new ListNode(val);
	ListNode *temp = head;
	if (head == nullptr) {
		head = newNode;
		return;
	}
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->next = nullptr;
}

// linked list traversal
void traverseLinkedList(ListNode *head) {
	while (head != nullptr) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "NULL\n";
}

// helper Funtions
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
//  vector to linked list
void vec_linkedlist(ListNode*&head, vector<int> nums ) {
	for (auto it : nums) {
		insertAt_tail(head, it);
	}
}

ListNode * reorderList(ListNode *head) {

	ListNode * linkedList_2 = nullptr;
	// base Condition
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	// finding the middle of the linked list
	ListNode * slow = head;
	ListNode * fast = head->next;
	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << "-- --- --- -- \n";
	cout << "middle point : " << slow->val << endl;
	linkedList_2 = slow->next;
	traverseLinkedList(linkedList_2);

	// Reversing Linked list

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

	vector<int> test{};
	ListNode *head = nullptr;
	// insertAt_tail(head, 1);
	// insertAt_tail(head, 2);
	// insertAt_tail(head, 3);
	// insertAt_tail(head, 4);
	// traverseLinkedList(head);

	_input(test);
	vec_linkedlist(head, test);
	traverseLinkedList(head);

	reorderList(head);

	return 0;
}

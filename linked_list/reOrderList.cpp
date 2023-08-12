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
void Reving_linkedList(ListNode * &head) {
	if (head == nullptr || head->next == nullptr) {
		return;
	}
	// currElement
	ListNode * currElement = head;
	// prevElement
	ListNode * prevElement = nullptr;
	while (currElement != nullptr) {
		ListNode * temp = currElement->next;
		currElement->next = prevElement;
		prevElement = currElement;
		currElement = temp;
	}
	head = prevElement;
}

void GettingAns_Vector(ListNode * linkedList_1, ListNode*linkedList_2) {
	vector<int> ansVector{};
	_showVector(ansVector);
	// manipulating Pointers
	while (linkedList_2 != nullptr) {
		ansVector.push_back(linkedList_1->val);
		linkedList_1 = linkedList_1->next;
		ansVector.push_back(linkedList_2->val);
		linkedList_2 = linkedList_2->next;
	}
	while (linkedList_1 != nullptr) {
		ansVector.push_back(linkedList_1->val);
		linkedList_1 = linkedList_1->next;
	}
	cout << "Printing Final answer\n";
	_showVector(ansVector);

}

ListNode * reorderList(ListNode *head) {
	ListNode * linkedList_2 = nullptr;
	// base Condition
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	ListNode * linkedList_1 = head;
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
	slow->next = nullptr;
	// Reversing Linked list
	Reving_linkedList(linkedList_2);
	cout << "Printing Reversed Linked List \n";
	traverseLinkedList(linkedList_2);
	// printing Both the linked list
	cout << "---- ---- ---- ---- ---- ----\n";
	traverseLinkedList(linkedList_1);
	cout << "linked list - 1\n ---- ---- ---- \n";
	traverseLinkedList(linkedList_2);
	cout << "linked list - 2\n" ;
	// printing all the head nodes
	cout << "---- ---- ---- ---- ---- ----\n";
	cout << "list_1.head : " << linkedList_1->val << "\nlist_2.head : " << linkedList_2->val << "\n---- ---- ---- ---- ---- ----\n";

	// getting output in a vector
	GettingAns_Vector(linkedList_1, linkedList_2);

	// checking Linked list pointer data
	cout << "linkedList_1.data : " << linkedList_1->val << endl;
	cout << "linkedList_2.data : " << linkedList_2->val << endl;

	// Modify linked list 1 by swaping items of linked list
	// linkedList_1 = linkedList_1->next;

	ListNode* pri = linkedList_1;
	while (linkedList_1 != nullptr && linkedList_2 != nullptr) {
		ListNode * pointer1 = linkedList_1->next;
		ListNode * pointer2 = linkedList_2->next;
		linkedList_1->next = linkedList_2;
		linkedList_2->next = pointer1;
		linkedList_1 = pointer1;
		linkedList_2 = pointer2;
	}
	// traverseLinkedList(pri);
	return pri;
}

void LeetCode_submission_reOrderLinkedList() {
	ListNode * linkedList_2 = nullptr;
	// base Condition
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	ListNode * linkedList_1 = head;
	// finding the middle of the linked list
	ListNode * slow = head;
	ListNode * fast = head->next;
	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	linkedList_2 = slow->next;
	slow->next = nullptr;
	Reving_linkedList(linkedList_2);
	ListNode* pri = linkedList_1;
	while (linkedList_1 != nullptr && linkedList_2 != nullptr) {
		ListNode * pointer1 = linkedList_1->next;
		ListNode * pointer2 = linkedList_2->next;
		linkedList_1->next = linkedList_2;
		linkedList_2->next = pointer1;
		linkedList_1 = pointer1;
		linkedList_2 = pointer2;
	}
	return pri;
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
#if 0
	insertAt_tail(head, 1);
	insertAt_tail(head, 2);
	insertAt_tail(head, 3);
	insertAt_tail(head, 4);
	traverseLinkedList(head);
#endif

	_input(test);
	vec_linkedlist(head, test);
	traverseLinkedList(head);

	ListNode *finalAnswer = reorderList(head);
	cout << "printing finalAnswer : \n";
	traverseLinkedList(finalAnswer);

	return 0;
}

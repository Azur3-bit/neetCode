// remove nth Node

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
// stucture to define a linked list
struct ListNode {
	int val;
	ListNode * next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x , ListNode* nxt) : val(x) , next(nxt) {}
};
// traverse linked list
void traverseLinkedList(ListNode*head) {
	cout << "printing Linked list \n";
	while (head != nullptr) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "null\n";
}
// insert node at the end of a linked list
void AddNode_end(ListNode*&head, int val ) {
	ListNode *newNode = new ListNode(val);
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
// vector input
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
// show Vector
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
// vector To linked list
void vec_linkedlist(ListNode *&head, const vector<int> &nums) {
	for (auto it : nums) {
		AddNode_end(head, it);
	}
	cout << "Elements entered in LinkedList\n";
}

ListNode* removeNthNode(ListNode *&head, int val) {

	// find position of the element
	ListNode *temp = head;
	int counter = 0;
	while (temp != nullptr) {
		counter++;
		temp = temp->next;
	}
	cout << "size of linked list : " << counter << endl;
	// pointer mainipulation
	temp = head;
	cout << "temp.val : " << temp->val << endl;
	if (val == counter) {
		cout << "Condi\n";
		ListNode * newHead = head->next;
		return newHead;
	}
	if (val > counter)
		cout << "-- value more than size !" << endl; return head;
	counter = counter - val - 1;
	while (counter--) {
		cout << "counter : " << counter << endl;
		temp = temp->next;
	}
	cout << "Value at counter : " << temp->val << endl;
	temp ->next = temp->next->next;
	return head;
}

ListNode* OnePass_removeNthNode(ListNode *&head, int n) {

// corner case
	if (head->next == nullptr || head == nullptr) {
		return head;
	}

	ListNode *forward = head;
	ListNode *back = head;
	for (int i = 0 ; i < n; i++) {
		forward = forward->next;
	}
	// cout << "forward.val : " << forward->val << endl;
	cout << "back.val : " << back->val << endl;

	cout << "head.val : " << head->val << endl;
	if (forward == nullptr) {
		cout << " -- head node has to be deleted : \n";
		head = head->next;
		return head;
	}

	while (forward->next != nullptr) {
		forward = forward->next;
		back = back->next;
	}
// corner case when head node has to be deleted
	cout << "new forward.val : " << forward->val << endl;
	cout << "new back.val : " << back->val << endl;

	back->next = back->next->next;
	return head;

}

int main(int argc, char const * argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// -- Main Function code --
	std::vector<int> v;
	_input(v);
	_showVector(v);
	ListNode*head = nullptr;
	vec_linkedlist(head, v);
	// _showLinkedList(head);
	traverseLinkedList(head);
	// cout << "working ! \n";

	// ListNode * newLinkedlist = removeNthNode(head, 6);
	// traverseLinkedList(newLinkedlist);

	ListNode *ans = OnePass_removeNthNode(head, 1);

	traverseLinkedList(head);



	// use two pointer approach to solve this problem
	return 0;
}

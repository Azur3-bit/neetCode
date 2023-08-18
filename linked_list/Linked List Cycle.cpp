// Linked List Cycle


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
// -_ Structure of linked list
struct ListNode {
	int val;
	ListNode * next;
	ListNode () : val(0), next(nullptr) {}
	ListNode (int value ) : val(value), next(nullptr) {}
	ListNode (int value , ListNode * nxt) : val(value), next(nxt) {}

};
// Functions

// -_ Adding NOdes in the linked lsit
void AddNode_end(ListNode * &head, int value) {
	ListNode * newNode = new ListNode(value);
	if (head == nullptr) {
		head = newNode;
		return;
	}
	ListNode * temp = head;

	while (temp->next != nullptr)
		temp = temp->next;
	temp->next = newNode;
}

// -_ show linked list
void _showLinkedList(ListNode * head) {
	cout << "printing Linked list\n";
	while (head != nullptr) {
		cout << head->val << " -> ";
		head = head -> next;
	}
	cout << "null\n";
	cout << "linked list printed\n";
}
// -_ vector to linked list
void vec_linkedlist(ListNode * head , std::vector<int> v) {
	for (auto it : v)
		AddNode_end(head, it);
	cout << "ELmenets entered in linked list \n";
}
// -_ vecInput
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
// -_ showVector
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

bool Solve(ListNode * head) {
	cout << "inside Solve Function \n";
	ListNode * fast = head->next;
	ListNode * slow = head;

	while (fast != nullptr && fast->next != nullptr) {
		if (fast == slow) {
			cout << "Loop Found \n";
			return true;
		}
		fast = fast->next->next;
		slow = slow->next;

	}
	cout << "loop Not Found \n";
	return false;
}

void testing(ListNode * head) {
	for (int i = 0; i < 20; i++) {
		cout << "i : " << i << " value : " << head->val << endl;
		head = head->next;
	}
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

	// Creating manual Linked list
	ListNode * head = nullptr;
	ListNode * first = new ListNode(3);
	ListNode * second = new ListNode(2);
	ListNode * third = new ListNode(0);
	ListNode * forth = new ListNode(-4);

// linking nodes
	head = first;
	first->next = second;
	second->next = third;
	third->next = forth;
	// forth->next = nullptr;
	forth->next = second;


	bool ansValue = Solve(head);
	cout << "Ans value : " << ansValue << endl;


	return 0;
}

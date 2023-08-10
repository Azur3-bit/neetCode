// -- essential_libraries_and_namespace

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
class node
{

public:
	int data;
	node *next;

	node(int value)
	{
		data = value;
		next = NULL;
	}
};

// Functions

void insertAt_tail(node *&head, int value)
{
	node *newNode = new node(value);

	if (head == NULL)
	{
		head = newNode;
		return;
	}

	node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

void _showLinkedList(node *head)
{
	while (head != NULL)
	{
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << "NULL" << endl
	     << endl;
}

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

// template <typename T>
void _showStack(stack<int>& numsSet) {
	std::cout << "-*-  -*- -*-" << std::endl;
	std::cout << "Printing stack" << std::endl;
	std::cout << std::endl;
	// std::cout << "{ ";

	while (!numsSet.empty()) {
		cout << numsSet.top() << endl;
		numsSet.pop();
	}
	// std::cout << " }" << std::endl;
	std::cout << "-*-  -*- -*-" << std::endl;
}

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

// -- linked list input
void input_LinkedList(node *&head, const vector<int> &nums ) {
	int s = nums.size();
	cout << "size : " << s << endl;
	int c = 0;
	for (int i : nums) {
		insertAt_tail(head, i);
		c++;
	}
	cout << "total Number of ELment Entered : " << c << endl;
}
// -- insert at head function
// -- maybe use a stack and create a new linked list
// -- two pointer approach
// --- ALGO recursive algorithm
// -- while temp-> next != NULL
// 			add current element as a new node in the linked list
void add_elementHead(node *&head, int Nodedata) {
	node *newNode = new node(Nodedata);
	if (head == nullptr) {
		cout << "Adding at head : " << Nodedata << endl;
		head = newNode;
		return;
	}
	cout << "Adding node at head : " << Nodedata << endl;
	newNode->next = head;
	head = newNode;
}
node * Reving_linkedList_recursive(node *head) {
	// -- Max complexity - O(n^2)
	node *REV_head = NULL;
	node *temp = head;
	while (temp != nullptr) {
		add_elementHead(REV_head, temp->data);
		cout << temp->data << " " << endl;
		temp = temp->next;
	}

	cout << "-- Fianl output --\n";

	_showLinkedList(REV_head);
	return REV_head;
}

node * Iterative_revingLinkedList(node *head) {
	cout << "-- iterative method -- " << endl;
	// using data structures to reverse a linked list
	stack<int> store{};
	node *traversal_stack = head;
	node *changing_data = head;
	node *finalTraversal = head;
	while (traversal_stack != nullptr) {
		store.push(traversal_stack->data);
		cout << "item : " << traversal_stack->data << endl;
		traversal_stack = traversal_stack->next;
	}
	while (changing_data != nullptr) {
		cout << "changing_data->data : " << changing_data->data << endl;
		changing_data->data = store.top();
		store.pop();
		changing_data = changing_data->next;
	}

	// while (finalTraversal != nullptr) {
	// 	cout << finalTraversal->data << " -> ";
	// 	finalTraversal = finalTraversal->next;
	// }

	return finalTraversal;

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
	// taking input in linked list using the provided vector -- maybe using vector


	vector<int> nums {};
	_input(nums);
	_showVector(nums);
	node *head = NULL;
	input_LinkedList(head, nums);
	_showLinkedList(head);

	Reving_linkedList_recursive(head);
	// add_elementHead(head, 0);
	// _showLinkedList(head);

	//  -- DONE with Recursive algo for reving a linked list
	// Iterative_revingLinkedList(head);

	cout << "-- reving linked list using stack -- \n";
	head = Iterative_revingLinkedList(head);
	cout << "-- Printing list main function -- \n";
	_showLinkedList(head);


	return 0;
}

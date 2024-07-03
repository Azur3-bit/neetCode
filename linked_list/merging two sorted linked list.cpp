// stucture of linked list
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

// merging two sorted linked list


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

void createLinkedList(node *&head, const vector<int> &nums) {
	node *temp = head;
	for (int it : nums) {
		// node * newNode = new node(it);
		insertAt_tail(head, it);
	}
}

// -- Combining sorted linked list

node * combiningSortedLinkedList(node * head1, node* head2, int size) {
	cout << "\n -- combiningSortedLinkedList -- " << endl;
	_showLinkedList(head1);
	_showLinkedList(head2);


	node * h1_traversal = head1;
	node * h2_traversal = head2;
	node * finalLinkedList = nullptr;
//  -- problem might be because of size -> use size -- instead of untill one linked list in finished
	while (h1_traversal != nullptr) {
		if ((h1_traversal->data) < (h2_traversal->data)) {
			insertAt_tail(finalLinkedList, h1_traversal->data);
			h1_traversal = h1_traversal->next;
		}
		if ((h1_traversal->data) > (h2_traversal->data)) {
			insertAt_tail(finalLinkedList, h2_traversal->data);
			h2_traversal = h2_traversal->next;
		}
	}
	cout << "final answer : " << endl;
	_showLinkedList(finalLinkedList);

	return finalLinkedList;

}

// -- trying this using a vector first

void vector_trail(vector<int> n1, vector<int> n2) {

	cout << " - trail -\n";
	for (int i = 0 ; i < n1.size(); i++) {

		if (n1[i] == n2[i]) {
			cout << n1[i] << " ";
			i++;
		}
	}
	cout << "\n * trail *\n";

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
	vector<int> v1{};
	_input(v1);
	vector<int> v2{};
	_input(v2);
	// printing vectors
	_showVector(v1);
	_showVector(v2);

	node * head1 = NULL;
	node * head2 = nullptr;

	createLinkedList(head1, v1);
	_showLinkedList(head1);
	createLinkedList(head2, v2);
	_showLinkedList(head2);


	// vector_trail(v1, v2);
	// -- Actual function call
	int ll_size = v1.size() + v2.size();
	cout << "final size : " << ll_size << endl;
	combiningSortedLinkedList(head1, head2, ll_size);

	int null_value = nullptr;
	cout << "null Ptr : " << null_value <<  endl;

	return 0;
}

// reving a linked list new Method

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
struct ListNode {
	int val;
	ListNode * next;
// constructors
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x) , next(nullptr) {}
	ListNode (int x , ListNode * nxt ) : val(x), next(nxt) {}
};
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

// -- add node to the end of a linked list
void insertAt_tail(ListNode *&head, int value) {
	ListNode * newNode = new ListNode(value);
	ListNode * temp = head;
	if (head == nullptr) {
		head = newNode;
		return;
	}
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void vec_linkedlist(ListNode*&head, vector<int> nums ) {
	for (auto it : nums) {
		insertAt_tail(head, it);
	}
}

void TraverseLinkedlist(ListNode *head) {
	while (head != nullptr) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "null" << endl;
}

void Rev_linkedlist(ListNode * &head ) {
	if (head == nullptr || head->next == nullptr) {
		return;
	}

	ListNode * curr = head;
	ListNode * prev = nullptr;
	// current
	while (curr != nullptr) {
		ListNode * temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	head = prev;
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
	vec_linkedlist(head, nums);
	TraverseLinkedlist(head);
	cout << "reving " << endl;
	Rev_linkedlist(head);
	TraverseLinkedlist(head);


	return 0;
}

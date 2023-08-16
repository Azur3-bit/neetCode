// add two number
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
// linklist structure
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Functions
// -_- Add Node at the end of the linked list
void AddNode_end(ListNode *&head, int val ) {
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
// -_- travserse linked list
void _showLinkedList(ListNode *head) {
	cout << "printing Linked list \n";
	while (head != nullptr) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "null\n";
}
// -_- vector input
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
// -_- show vector
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
// -_- vector to linked list
void vec_linkedlist(ListNode *&head, vector<int> nums ) {
	for (auto it : nums) {
		AddNode_end(head, it);
	}
	cout << "all elements entered in the linked list \n";
}

ListNode * AddTwoNumber(ListNode*l1, ListNode *l2) {
	ListNode * ans = new ListNode(0);
	ListNode * finalans = ans;
	int c = 0;
	while ((l1 != nullptr) || (l2 != nullptr)) {
		int sum = c;
		if (l1 != nullptr) {
			sum = sum + l1->val;
			l1 = l1->next;
		}
		if (l2 != nullptr) {
			sum = sum + l2->val;
			l2 = l2->next;
		}

// carry bit manipulation
		c = sum / 10;
		sum = sum % 10;
		AddNode_end(ans, sum);

	}
	if (c > 0) {
		AddNode_end(ans, c);
	}
	ListNode * result = finalans->next;
	delete finalans;
	return result;
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
	// input list 1 , list 2

	vector<int> v{};
	vector<int> n{};
	_input(v);
	cout << "printing first Vector \n";
	_input(n);
	_showVector(v);
	cout << "printing second Vector \n";

	_showVector(n);
	// converting both the vectors into linked list
	ListNode *v_11 = nullptr;
	ListNode *v_12 = nullptr;
	vec_linkedlist(v_11, v);
	vec_linkedlist(v_12, n);
	cout << "printing first linked list \n";
	_showLinkedList(v_11);
	cout << "printing second linked list \n";
	_showLinkedList(v_12);


	ListNode *ans = nullptr;
	_showLinkedList(ans);
	ans = AddTwoNumber(v_11, v_12);

	_showLinkedList(ans);
	return 0;
}

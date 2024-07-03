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
// - structure of ListNode

struct ListNode {
	int val;
	ListNode * next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int value ) : val(value ), next(nullptr) {}
	ListNode(int value , ListNode * nxy) : val(value ), next(nxy) {}

};
// Functions

// - add Node end input linked list
void AddNode_end(ListNode *&head, int value) {
	ListNode * newNode = new ListNode(value);
	if (head == nullptr) {
		head = newNode;
		return ;
	}
	ListNode * temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
}
// - traverse linked list
void _showLinkedList(ListNode*head) {
	cout << "printing linked list \n";
	while (head != nullptr) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "null\n";

}
//  - input vector
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
//  - show vector
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
// - vector to linked list
void vec_linkedlist(ListNode *&head , const vector<int> &nums) {
	for (auto it : nums) {
		cout << it << endl;
		AddNode_end(head, it);
	}
	cout << "Elements -> linked list (done)\n";

}
// - funciton to solve the actual problem

ListNode * answer(ListNode *l1, ListNode*l2) {
	ListNode * newhead = nullptr;
	int carry = 0;
	while ((l1 != nullptr) || (l2 != nullptr)) {
		int sum = carry;
		if (l1 != nullptr) {
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2 != nullptr) {
			sum += l2->val;
			l2 = l2->next;
		}
		carry = sum / 10;
		AddNode_end(newhead, sum % 10);
	}
	while (carry > 0) {
		AddNode_end(newhead, carry % 10);
		carry = carry / 10;

	}
	return newhead;
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
	vector<int> n{};
	vector<int> z{};
	_input(n);
	_input(z);

	cout << "\nprinting first vector \n";
	_showVector(n);
	cout << "\nprinting second vector \n";
	_showVector(z);

	ListNode * l1 = nullptr;
	ListNode * l2 = nullptr;
	vec_linkedlist(l1, n);
	vec_linkedlist(l2, z);

	_showLinkedList(l1);
	_showLinkedList(l2);

	ListNode * ans = nullptr;
	ans = answer(l1, l2);
	cout << "Printing final anwer -> \n";
	_showLinkedList(ans);
	return 0;
}

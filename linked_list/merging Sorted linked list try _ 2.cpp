// merging Sorted linked list try _ 2

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

class node {
public:

	int data;
	node * next;

	node (int val) {
		data = val;
		next = nullptr;
	}
};



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


void AddingNode_Vector(node *& head , const vector<int>&nums) {
	int size = nums.size();

	for (auto it : nums) {
		insertAt_tail(head, it);
	}
}


node * MergingSortedLinkedList(node *head_1, node *head_2) {

	vector<int> ans{};
	node * head = nullptr;
	node * temp_1 = head_1;
	node * temp_2 = head_2;

	while (temp_1 != nullptr && temp_2 != nullptr) {
		if ((temp_1->data) <= (temp_2->data)) {
			cout << "pushing : " << temp_1->data << endl;
			insertAt_tail(head, temp_1->data);
			ans.push_back(temp_1->data);
			temp_1 = temp_1->next;
		}
		else {
			cout << "pushing : " << temp_2->data << endl;
			insertAt_tail(head, temp_2->data);
			ans.push_back(temp_2->data);
			temp_2 = temp_2->next;
		}
	}
	_showVector(ans);

	// add all the remaining elments from both the linked list
	// cout << "temp_2 -> data : " << temp_2->data << endl;
	while (temp_2 != nullptr) {
		cout << "pushing : " << temp_2->data << endl;
		insertAt_tail(head, temp_2->data);
		ans.push_back(temp_2->data);
		temp_2 = temp_2->next;
	}

	while (temp_1 != nullptr) {
		cout << "pushing : " << temp_1->data << endl;
		insertAt_tail(head, temp_1->data);
		ans.push_back(temp_1->data);
		temp_1 = temp_1->next;
	}

	cout << "final Answer : " << endl;
	_showVector(ans);

	return head;


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

	node * head_1 = nullptr;
	node * head_2 = nullptr;

	vector<int> n1{};
	vector<int> n2{};
	_input(n1);
	_input(n2);

	_showVector(n1);
	_showVector(n2);

	AddingNode_Vector(head_1, n1);
	AddingNode_Vector(head_2, n2);
	_showLinkedList(head_1);
	_showLinkedList(head_2);

	// -- Actual Function To solve code
	node * answer = nullptr;
	answer = MergingSortedLinkedList(head_1, head_2);

	_showLinkedList(answer);


	return 0;
}

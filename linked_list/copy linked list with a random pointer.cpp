// copy linked list with a random pointer

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
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int x) {
		val = x;
		next = NULL;
		random = NULL;
	}
};
// Functions
// Add node in the linked list
void AddNode_end(Node *&head, int val) {
	Node * newNode = new Node(val);
	if (head == nullptr) {
		head = newNode;
		return;
	}
	Node * temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
}
// traverse linked list
void TraverseLinkedlist(Node *head) {
	cout << "printing linked list \n";
	// int node = 0;
	while (head != nullptr) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "null\n";
}
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
// vector to linked list
void vec_linkedlist(Node *&head, const vector<int> &v) {
	for (auto i : v) {
		AddNode_end(head, i);
	}
	cout << "Elements have been entered in linked list \n";
}

void Connecting_randomPointer(Node*&head, Node *&currNode, int n) {
	if (n == -1) {
		currNode->random = nullptr;
		return;
	}
	Node * findingLinkingNode = head;
	while (n--) {
		findingLinkingNode = findingLinkingNode->next;
	}
	// cout << "random of CurrentNode : " << currNode->val << endl;
	// cout << "linking to CurrentNode : " << findingLinkingNode->val << endl;

	currNode->random = findingLinkingNode;
}

Node * Parent_connecting_randomPOinters(Node *head, vector<int> &nums) {
	cout << "choosing CurrentNode\n";
	Node * curr = head;
	for (auto it : nums) {
		if (it < 0) {
			curr->random = nullptr;
			continue;
		}
		Connecting_randomPointer(head, curr, it);
		curr = curr->next;
	}
	return head;
}

void _showLinkedListModified(Node * head) {
	int index = 0;
	while (head->next != nullptr) {
		cout << " --- --- ---- ---- ---- \n";

		cout << "index : " << index << endl;
		cout << "data :" << head->val << endl;
		if (head->random == nullptr) {
			cout << "random : nullptr" << endl;
		}
		else {
			cout << "random : " << head->random->val << endl;
		}
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
	std::vector<int> v;
	_input(v);
	cout << "linklist Elements \n";
	_showVector(v);
	Node * head = nullptr;
	vec_linkedlist(head, v);
	TraverseLinkedlist(head);

	// connecting random pointers
	vector<int> randomValue{};
	cout << "randomm values vector : ";
	_input(randomValue);
	_showVector(randomValue);
	Node * input_LinkedList = Parent_connecting_randomPOinters(head, randomValue);

	_showLinkedListModified(input_LinkedList);

	return 0;
}

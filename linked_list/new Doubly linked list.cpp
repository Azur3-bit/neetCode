// new Doubly linked list

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
// _ Structure of doubly linked list
struct Node {
	int val;
	Node * next;
	Node * prev;
	Node() : val(0) , next(nullptr) , prev(nullptr) {}
	Node(int x) : val(x) , next(nullptr) , prev(nullptr) {}
	Node(int x , Node * nxt , Node * p) : val(0) , next(nxt) , prev(p) {}
};
// Functions
// _ add node at the end of Doubly linked list

void AddNode_end(Node * &head , int data) {
	Node * newNode = new Node(data);
	if (!head) {
		head = newNode;
		return;
	}
	if (head->next == nullptr) {
		head->next = newNode;
		newNode->prev = head;
		return;
	}
	Node * nxtTemp = head;
	while (nxtTemp->next != nullptr) {
		// prevTemp = prevTemp->next;
		nxtTemp = nxtTemp->next;
	}
	nxtTemp->next = newNode;
	newNode->prev = nxtTemp;

}
// _ Traverse linked list
void _showLinkedList(Node * head) {
	cout << "printing Linked list \n";
	while (head) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "end\n";
}
// _ return pointer to the end of the linked list

Node * PointerTo_end(Node * head) {
	while (head->next != nullptr)
		head = head->next;
	return head;
}
// _ traverse linked list in the reverse direction
void _revTraversalLinkedList(Node * head) {
	cout << "printing Rev linked list \n";
	cout << "Changed while condition \n";
	while (head) {
		cout << head->val << " -> ";
		head = head->prev;
	}
	cout << "end\n";
}

int main(int argc, char const *argv[])
{
// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
// #endif

	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// -- Main Function code --
	Node * head = nullptr;
	AddNode_end(head, 1);
	AddNode_end(head, 2);
	AddNode_end(head, 3);
	AddNode_end(head, 4);
	cout << "printing Link list main function\n";
	_showLinkedList(head);

	Node * end = PointerTo_end(head);
	// cout << end->prev->val  << endl;
	_revTraversalLinkedList(end);

	return 0;
}

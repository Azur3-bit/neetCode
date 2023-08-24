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
// creating a doubly linked list stucture
struct Node {
	int key;
	// int val;
	Node * next;
	Node * prev;

	Node() : key(0) , next(nullptr) , prev(nullptr) {}
	Node(int x) : key(x) , next(nullptr) , prev(nullptr) {}
	Node(int x , Node * pr , Node * nxt ) : key(x) , next(nxt) , prev (pr) {}
};

// Functions
// add node at the end of a doubly linked list
void AddNode_end_doubly(Node *&head, int data) {
	Node * newNode = new Node(data);
	newNode->prev = nullptr;
	newNode->next = nullptr;
	if (head == nullptr) {
		head = newNode;
		return;
	}
	Node * temp = head;
	Node * nextTemp = head->next;
	if (nextTemp == nullptr) {
		// temp->next = newNode;
		newNode->prev = temp;
		temp->next = newNode;
		nextTemp = newNode;
		return;
	}
	while (nextTemp->next != nullptr) {
		nextTemp = nextTemp->next;
	}
	nextTemp->next = newNode;
	newNode->prev = nextTemp;
	// temp->next = newNode;
}

// traverse a doubly linked list
void _showDoublyLinkedList(Node * head) {
	while (head != nullptr ) {
		cout << head->key << " -> ";
		head = head->next;
	}
	cout << "null" << endl;
}

Node * PointerTo_end(Node * head) {
	while (head->next != nullptr) {
		head = head->next;
	}
	cout << "--\n";
	return head;
}

void _revTraversalLinkedList(Node * head) {
	cout << "revTraversal \n";
	while (head != nullptr) {
		cout << head->key << " <-- " ;
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
	AddNode_end_doubly(head, 1);
	AddNode_end_doubly(head, 2);
	AddNode_end_doubly(head, 3);
	AddNode_end_doubly(head, 4);
	// AddNode_end_doubly(head, 5);

	_showDoublyLinkedList(head);

	Node * end_pointer = PointerTo_end(head);

	_revTraversalLinkedList(end_pointer);

	return 0;
}

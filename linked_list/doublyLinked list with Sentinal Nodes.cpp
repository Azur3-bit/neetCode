// doublyLinked list with Sentinal Nodes
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

struct Node {
	int val;
	int key;
	Node * next;
	Node * prev;
	Node(int _newKey, int _newVal) : val(_newVal) , key(_newKey) , next(nullptr) , prev(nullptr) {}
};

// Functions
// add new Node At the end of the linked list
void AddNode_end(Node * &senHead, Node *& senTail, int _newKey, int _newVal) {
	Node * newNode = new Node(_newKey , _newVal);
	if (senHead->next == senTail) {
		senHead->next = newNode;
		newNode->prev = senHead;
		newNode->next = senTail;
		senTail->prev = newNode;
	}

	Node * temp = senHead;
	while (temp->next->next != nullptr )
		temp = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
	newNode->next = senTail;
	senTail->prev = newNode;
}
// traverse linked list
void _showLinkedList(Node * senHead , Node * senTail) {
	cout << "\n--printing Linked list \n";
	Node * head = senHead;
	while (head != nullptr) {
		cout << " -- X -- \n";
		cout << "head->val : " <<  head->val  << "\nhead->key : " << head->key << endl;
		head = head->next;
	}
	cout << "--- == --- \nnull\n";
	cout << "linked list printed\n";
}
// pointer to the end of linked list
Node * endPointer(Node * senHead) {
	while (senHead->next != nullptr)
		senHead = senHead->next;
	return senHead;
}

// reverse traversal
void _revTraversalLinkedList(Node * tail) {
	while (tail != nullptr) {
		cout << "tail->val : " << tail->val  << "\ntail->key : " << tail->key << endl;
		tail = tail->prev;
	}
}

int main(int argc, char const *argv[])
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// -- Main Function code --

	Node * senHead = new Node(100, 100);
	cout <<  "senHead->val : " << senHead->val <<  "\nsenHead->key : " << senHead->key << endl;

	cout << " --- ---- --- --- ---- --- --- ---- --- \n";
	Node * senTail = new Node(-100, -100);
	cout <<  "senTail->val : " << senTail->val <<  "\nsenTail->key : " << senTail->key << endl;

	senHead->next = senTail;
	senTail->prev = senHead;

	cout << "printing senhead and sentail via each other \n";

	cout << "senHead->next->val : " << senHead->next->val  << endl;
	cout << "senTail->prev->val: " << senTail->prev->val << endl;


	AddNode_end(senHead, senTail, 1, 1);
	AddNode_end(senHead, senTail, 2, 2);

	_showLinkedList(senHead , senTail);

	Node * end_pointer = endPointer(senHead);
	cout << "end_pointer.val : " << end_pointer->val << endl;
	// _revTraversalLinkedList(end_pointer);
	cout << "end_pointer.prev.val : " << end_pointer->prev->val << endl;
	cout << "end_pointer.prev.prev.val : " << end_pointer->prev->prev->val << endl;	cout << "end_pointer.prev.prev.prev.val : " << end_pointer->prev->prev->prev->val << endl;
	return 0;
}

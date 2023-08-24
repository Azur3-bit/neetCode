// Doubly_linked list
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
// Structure of a linked list
struct ListNode {
	int val;
	ListNode * next;
	ListNode * prev;
	ListNode() : val(0) , next(nullptr) , prev(nullptr) {}
	ListNode(int x) : val(x) , next(nullptr) , prev(nullptr) {}
	ListNode(int x , ListNode * nxt , ListNode * p) : val(x) , next(nxt) , prev(p) {}
};

// Functions
// Adding ListNode To linked list
void AddNode_end(ListNode * &head, int data) {
	ListNode * newNode = new ListNode(data);
	if (head == nullptr) {
		head = newNode;
		return;
	}
	if (head->next == nullptr) {
		head->next = newNode;
		newNode->prev = head;
		return;
	}
	ListNode * temp = head->next;
	ListNode * PrevTemp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
		PrevTemp = PrevTemp->next;
	}
	newNode->prev = PrevTemp;
	temp->next = newNode;
}
// traversal of linked list

void _showDoublyLinkedList(ListNode * head) {
	cout << "Printing Doubly Linked list \n";
	while (head != nullptr) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "null\n";
}
// end pointer of linked list
// reverse linked list

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

	ListNode * head = nullptr;
	AddNode_end(head, 1);
	AddNode_end(head, 2);
	AddNode_end(head, 3);
	AddNode_end(head, 4);

	_showDoublyLinkedList(head);

	return 0;
}

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

int capacity_main = 2;
#if 0
class LRU {
public :
	int capacity ;
	LRU(int cap) {
		this->capacity = cap;
	}

	int get(int key) {

	}

};
#endif
struct Node {
	int key;
	int val;
	Node * next;
	Node * prev;
	Node(int _xKey , int _cValue ) : key(_xKey) , val(_cValue) , next(nullptr) , prev(nullptr) {}
};

// Functions
int get(Node * &head, unordered_map<int, Node *> HM , int capacity = capacity_main) {
	cout << "inside get function \n";
	cout << "capacity : " << capacity << endl;
}

// printing unordered_map
template <typename KeyType, typename ValueType>
void _showHashMap(unordered_map <KeyType, ValueType> &hashMap)
{
	std::cout << std::endl;
	std::cout << "-*-  -*- -*- " << std::endl;
	std::cout << "Printing HashMap" << std::endl;
	std::cout << std::endl;

	std::cout << "key\t\tvalue" << std::endl;
	std::cout << "----\t-----" << std::endl;

	for (const auto &it : hashMap)
	{
		std::cout << it.first << "\t\t" << it.second << std::endl;
	}

	std::cout << std::endl;
	std::cout << "HashMap Printed" << std::endl;
	std::cout << "-*-  -*- -*- " << std::endl;
	std::cout << std::endl;
}
// Printing HashMap
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

// show doubly linked list


Node * senTail = new Node(-100, -100);
// adding node to the end of the linked list
void AddNode_end(Node * &head, int _nodeValue , int _nodeKey) {
	Node * newNode = new Node(_nodeKey, _nodeValue);
	Node * temp = head;
	while (temp->next != senTail) {
		temp = temp->next;
	}
	// if (head->next->nexta == nullptr) {
	// 	head->next->next = newNode;
	// 	newNode->prev = head->next->next;

	// 	newNode->next = senTail;
	// 	senTail->prev = newNode;
	// }
	newNode->prev = temp;
	temp->next = newNode;

	// Adding Sentinel Tail Node
	newNode->next = senTail;
	senTail->prev->next = newNode;
	senTail->prev = newNode;
	// return senTail;
}

void _showDoublyLinkedList(Node * head) {
	cout << "printing Linked list \n";
	while (head->next != senTail) {
		cout << "key -> " << head->key << " || value -> " << head->val << endl;
		head = head->next;
		cout << " --- --- --- --- --- --- \n";
	}
	cout << "end\n";
}

int main(int argc, char const *argv[])
{
// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
// #endif
//
	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// -- Main Function code --

	// LRU -> first Maximum Storage size
	// if put then add element in the LRU
	// if get then counter++ and return element
	cout << "\n--- --- --- LRU Cache --- --- ---\n";
	Node * head = new Node(1000, 1000);
	Node * tail = nullptr;
	unordered_map<int, Node * > HM{};

	// --- get(head, HM);

// -- testing head and tail
	cout << "head.val : " << head->val << endl;
	cout << "head.key : " << head->key << endl;

// -- testing head.nxt
	// cout << "head.nxt : " << head->next << endl;
	AddNode_end(head, 1, 1);
	_showDoublyLinkedList(head);
	// cout << "head->next->key : " << 1head->next->key << endl;
	// cout << "head->next->val : " << 1head->next->val << endl;
	AddNode_end(head, 2, 2);
	AddNode_end(head, 3, 3);
	_showDoublyLinkedList(head);



	return 0;
}

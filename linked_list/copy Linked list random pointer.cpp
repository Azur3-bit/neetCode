// copy Linked list random pointer

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

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
// Functions
// -- traverse linked list
void traverseLinkedList(Node *head) {
	cout << "printing Linked list \n";
	while (head->next != nullptr) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "nullptr\n";
}
void _showHashMap(const std::map<int, Node *> hashMap)
{
	std::cout << std::endl;
	std::cout << "-*-  -*- -*- " << std::endl;
	std::cout << "Printing HashMap" << std::endl;
	std::cout << std::endl;

	std::cout << "Ele_i\tMem_Add" << std::endl;
	std::cout << "----\t-----" << std::endl;

	for (const auto &it : hashMap)
	{
		// std::cout << it.first << "\t\t" << std::endl;
		std::cout << it.first << "\t\t" << it.second << std::endl;
	}

	std::cout << std::endl;
	std::cout << "HashMap Printed" << std::endl;
	std::cout << "-*-  -*- -*- " << std::endl;
}
// -- add node in the end of linked list
void AddNode_end(Node *&head, int _val) {
	cout << "adding node \n";
	Node *newNode = new Node(_val);
	if (head == nullptr) {
		head = newNode;
		return;
	}
	Node *temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
}
// -- input vector
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
// -- vector to linked list
void vec_linkedlist(Node * &head, std::vector<int> v) {
	for (auto it : v) {
		AddNode_end(head, it);
	}
	cout << "All elements Entered in linked list \n";
}
// -- traverse vector
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

void Modified_traverseLinkedList(Node *head) {
	cout << "printing Linked list \n";
	int counter = 0;
	while (head != nullptr) {
		cout << " -- --- --- --- --- --\n";
		cout << "index : " << counter << endl;
		cout <<  "head.val : " << head->val << endl;
		cout <<  "head.random : " << head->random << endl;
		head = head->next;
		counter++;
	}
	cout << "----------------------------->\nnullptr\n";
}
map<int, Node *> StoringNodeLocation_usingHashMap(Node *head) {
	map<int, Node * > hashMap;

	int c = 0;
	while (head != nullptr) {
		hashMap.insert(make_pair(c, head));
		head = head->next;
		c++;
	}
	return hashMap;
}

// now link node with the index provided in the vector randomConnection
Node * Connecting_randomPointer(Node *&head, map<int, Node *> hashMap, const vector<int> &v) {
	Node * temp = head;
	for (int currNode_connection : v) {
		// search currNode_connection in the hashMap
#if 0
		if (hashMap.find(currNode_connection) != hashMap.end()) {
			cout << "printing node Location from hashmap : " << hashMap[currNode_connection].first->data << "\n";
		}
		else {
			continue;
		}
#endif
		cout << "hashMap[currNode_connection] : "  <<   hashMap[currNode_connection] << endl << endl;
		temp->random = hashMap[currNode_connection];
		temp = temp->next;
	}
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
	map<int, Node *> hashMap{};

	Node *head = nullptr;
	std::vector<int> v;
	_input(v);
	_showVector(v);
	vec_linkedlist(head, v);
	traverseLinkedList(head);
	cout << "printing Modified_traverseLinkedList \n";
	Modified_traverseLinkedList(head);

	hashMap = StoringNodeLocation_usingHashMap(head);
	_showHashMap(hashMap);

	// input Random Connection
	std::vector<int> randomConnection{};
	_input(randomConnection);
	cout << "printing random Connection vector\n";
	_showVector(randomConnection);

	cout << "\n-----------------------------\n";
	cout << "after connecting Random Pointers \n";
	Connecting_randomPointer(head, hashMap, randomConnection);

	// printing Modified linked list
	Modified_traverseLinkedList(head);


	return 0;
}

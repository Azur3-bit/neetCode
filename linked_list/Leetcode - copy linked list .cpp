// copy linked list Leetcode Submission
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
// create linked list

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
//  add node at the end of linked list
void AddNode_end(Node * &head, int x) {
	Node *newNode = new Node(x);
	if (head == nullptr) {
		head = newNode; return;
	}
	Node *temp = head;
	while (temp->next != nullptr)
		temp  = temp->next;
	temp->next = newNode;
}
// link list Traversal
void _showLinkedList(Node *head) {
	cout << "printing Link list \n";
	while (head != nullptr) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "null\n";
}

// Modified link list Traversal
void Modi_showLinkedList(Node *head) {
	cout << "printing Link list \n";
	while (head != nullptr) {
		cout << " --- --- --- ---- --- --- --- \n";
		cout << "head.val : " << head->val << endl;
		cout << "head.random : " << head->random << endl;
		// cout << head->random << endl;
		head = head->next ;
	}
	cout << "--- --- --- ---- --- --- ---> \n";
	cout << "null\n";
}
// vector to link list
template<typename type_1>
void vec_linkedlist(Node *&head, vector<type_1> &nums) {
	for (auto it : nums)
		AddNode_end(head, it);
	cout << "-- Elements have been entered in LinkList \n";
}
// vector input
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
// show vector
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
// show hashMap
// template <typename KeyType, typename ValueType>
void _showHashMap(std::map<int, Node *> &hashMap)
{
	std::cout << std::endl;
	std::cout << "-*-  -*- -*- " << std::endl;
	std::cout << "Printing HashMap" << std::endl;
	std::cout << std::endl;

	std::cout << "Value_i\t\tMem_add" << std::endl;
	std::cout << "------\t\t-------" << std::endl;

	for (const auto &it : hashMap)
	{
		std::cout << it.first << "\t\t\t" << it.second << std::endl;
	}

	std::cout << std::endl;
	std::cout << "HashMap Printed" << std::endl;
	std::cout << "-*-  -*- -*- " << std::endl;
	std::cout << std::endl;
}
// create hashMap to store all the index node
map<int, Node *> gen_hashMap(Node*head) {
	map<int, Node *> hashMap{};
	int c = 0;
	while (head != nullptr) {
		hashMap.insert(make_pair(c, head));
		head = head->next;
		c++;
	}
	cout << "inserting Node* of nullptr  \n";
	hashMap.insert(make_pair(c, head));
	return hashMap;
}
// link random pointer to Node * of HashMap
void LinkingRandom_pointer(Node *&head, vector<int> r, map<int, Node*> &hashMap) {
	Node *temp = head;
	for (auto it : r) {
		if (hashMap.find(it) != hashMap.end()) {
			temp->random = hashMap[it];
			temp = temp->next;
		}
	}
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// -- Main Function code --

	// get both the vectors :- v , r

	cout << "Working !" << endl;
	vector<int> v{};
	vector<int> r{};
	_input(v);
	_input(r);
	cout << "printing Link List vector \n";
	_showVector(v);
	cout << "printing random Link List vector \n";
	_showVector(r);
	Node * head = nullptr;
	vec_linkedlist(head, v);

	_showLinkedList(head);

	//checking current location of head
	cout << "head.val : " << head->val << endl;
	map<int, Node *> hashMap = gen_hashMap(head);
	_showHashMap(hashMap);


// print Modified Linked list
	Modi_showLinkedList(head);
// linking random POinter
	LinkingRandom_pointer(head, r, hashMap);
// print Modified Linked list
	Modi_showLinkedList(head);

	return 0;
}

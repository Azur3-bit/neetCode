// Sentinal Nodes D_LL
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
	Node(int _usrVal , int _usrKey) : val(_usrVal) , key(_usrKey) , next(nullptr) , prev(nullptr) {}
};
// Functions
Node * AddNode_end(Node * &senHead , Node * &senTail , int _usKey , int _usVal, unordered_map<int, Node *> & HM) {
	Node * newNode = new Node(_usVal , _usKey);
	HM.insert(make_pair(_usKey, newNode));
	if (senHead->next == senTail) {
		newNode->next = senTail;
		senTail->prev = newNode;
		senHead->next = newNode;
		newNode->prev = senHead;
		return newNode;
	}
	Node * temp = senHead;
	while (temp->next != senTail)
		temp = temp->next;
	senTail->prev = newNode;
	newNode->next = senTail;
	temp->next = newNode;
	newNode->prev = temp;
	return newNode;
}
void _showLinkedList(Node * senHead , Node * senTail ) {
	cout << "printing D _ Linked list \n";
	while (senHead != nullptr) {
		cout << " -- X --\n";
		cout << "senHead->val : " << senHead->val << endl;
		cout << "senHead->key : " << senHead->key <<  endl;
		senHead = senHead->next;
	}
	cout << "printing Linked list \n";
}
void _showLinkedList_add(Node * senHead , Node * senTail ) {
	cout << " --- Address --- printing D _ Linked list \n";
	while (senHead != nullptr) {
		cout << " -- X --\n";
		cout << "senHead.add : " << senHead << endl;
		cout << "senHead.add : " << senHead <<  endl;
		senHead = senHead->next;
	}
	cout << "printed Linked list - Address \n";
}

void _showLinkedList_inOrder(Node * senHead , Node * senTail) {
	cout << "printing Ordered Linked list \n";
	cout << "\n --- XXX --- \n";
	while (senHead) {
		cout << senHead->key << " -> " ;
		senHead = senHead->next;
	}
	cout << "nullptr\n";
}
void _revTraversalLinkedList(Node * senHead , Node * senTail) {
	cout << " -- printing Rev Linked list \n";
	while (senTail) {
		cout << "senTail.val : " << senTail->val  << endl;
		cout << "senTail.key : " << senTail->key  << endl;
		senTail = senTail->prev;
	}
	cout << " -- printed Rev Linked list \n";
}
template <typename KeyType, typename ValueType>
void _showHashMap(const unordered_map<KeyType, ValueType> &hashMap) {
	std::cout << std::endl;
	std::cout << "-*-  -*- -*- " << std::endl;
	std::cout << "Printing HashMap" << std::endl;
	std::cout << std::endl;
	std::cout << "key\t\tvalue" << std::endl;
	std::cout << "----\t-----" << std::endl;
	for (const auto &it : hashMap)
		std::cout << it.first << "\t\t" << it.second << std::endl;
	std::cout << std::endl;
	std::cout << "HashMap Printed" << std::endl;
	std::cout << "-*-  -*- -*- " << std::endl;
	std::cout << std::endl;
}
void Put(unordered_map<int, Node * > &HM , Node * &senHead, Node * &senTail , int _usKey , int _usVal , int maxSize) {
	if (maxSize <= HM.size()) {
		cout << "optimal Size \n";
		Node * newNode_add = AddNode_end(senHead, senTail, _usKey, _usVal, HM);
		HM.insert(make_pair(_usKey, newNode_add));
		Node * currNode = HM[_usKey];
		currNode->prev->next = currNode->next;
		currNode->next->prev = currNode->prev;
		return;
	}
	cout << " --- EVICT condition \n";
	Node * currNode = HM[_usKey];
	currNode->prev->next = currNode->next;
	currNode->next->prev = currNode->prev;
	currNode->prev = senTail->prev;
	senTail->prev->next = currNode;
	senTail->prev = currNode;
	currNode->next = senTail;
}

int Get(unordered_map<int, Node * > &HM , Node * senHead , Node* senTail , int _usrKey) {
	auto iter = HM.find(_usrKey);
	if (iter != HM.end()) {
		cout << "found Element :-> " << "iter->val : " << iter->val << iter->key << iter->key << endl;
	}

}
int main(int argc, char const *argv[]) {
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif
	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// -- Main Function code --
	// HashMap - int Node *
	unordered_map<int, Node *> HM{};
	Node * senHead = new Node(100, 100);
	Node * senTail = new Node(-100 , -100);
	senHead->next = senTail;
	senTail->prev = senHead;
	cout << "senHead.next : " << senHead->next->val << endl;
	cout << "senTail.prev : " << senTail->prev->val << endl;
// void AddNode_end(Node * &senHead , Node * &senTail , int _usKey , int _usVal, unordered_map<int, Node *> & HM) {
	AddNode_end(senHead, senTail, 1, 1 , HM);
	cout << "senHead.next : " << senHead->next->val << endl;
	cout << "senTail.prev : " << senTail->prev->val << endl;
	AddNode_end(senHead, senTail, 2, 2 , HM );
	AddNode_end(senHead, senTail, 3, 3, HM);
	_showLinkedList_add(senHead, senTail);
	_showLinkedList(senHead, senTail);
	_revTraversalLinkedList(senHead, senTail);
	_showHashMap(HM);
	_showLinkedList_inOrder(senHead, senTail);
	// 100 -> 1 -> 2 -> 3 -> -100 -> nullptr
	// Put(HM, senHead, senTail, 4, 4, 5);
	_showLinkedList_inOrder(senHead, senTail);
	// 100 -> 1 -> 3 -> 2 -> -100 -> nullptr
	return 0;
}

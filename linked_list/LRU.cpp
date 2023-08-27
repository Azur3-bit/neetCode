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
	Node(int _usrKey, int _usrVal):   key(_usrKey), val(_usrVal), next(nullptr) , prev(nullptr) {}
};
class LRUCache {
public:
	int cap;
	unordered_map<int, Node * > HM {};
	Node * senHead = new Node(100, 100);
	Node * senTail = new Node(-100, -100);
	LRUCache(int capacity) {
		cout << "\n--- --- construtor STARTS\n";
		senHead->next = senTail;
		senTail->prev = senHead;
		cap = capacity;
		cout << "--- --- construtor ENDS \n\n";
	}
	void move_back(int key) {
		cout << "--- move_back Function\n";
		Node * currNode = HM[key];
		currNode->next->prev = senHead;
		senHead->next = currNode->next->next;
		senTail->prev->next = currNode;
		currNode->prev = senTail->prev;
		currNode->next = senTail;
		senTail->prev = currNode;
	}
	int get(int key) {
// -> retrieve element to
		cout << "--- - Get Function\n";
		auto it = HM.find(key);
		if (it == HM.end()) {
			// -> if not present then return -1
			cout << "element does not exist in the HashMap\n";
			cout << "output -> -1\n";
			return -1;
		}
		if (it != HM.end()) {
			// -> move back element
			cout << "it.second.val : " << it->second->val << endl;
			move_back(key);
			// return it->second->val;
		}
	}
	// add node at the back of the Doubly Linkeed list
	void put(int key, int value) {
		cout << "-- -PUT Function\n";
// -> add Node the the end of D_LL
		int size = HM.size();
		cout << "hashMap.size -> " << size << endl;
		if (size <= cap) {
			Node * NewNode_add = AddNode_end(key, value);
			HM.insert(make_pair(key, NewNode_add));
			return;
		}
		// -> evict condition
		// -> remove senHead.next
		HM.erase(key);
		senHead->next->next = senHead->next;
		senHead->next->prev = senHead;
		// -> addNode_end -> newNode
		AddNode_end(key, value);
	}
	Node * AddNode_end(int key, int value) {
		cout << "--- AddNode_end\n";
		Node * newNode = new Node(key, value);
		senTail->prev->next = newNode;
		newNode->prev = senTail->prev;
		senTail->prev = newNode;
		newNode->next = senTail;
	}
	// printing Linked list
	void _showLinkedList_inOrder_forward() {
		cout << "printing Linked list -- forward\n";
		Node * temp = senHead;
		while (temp) {
			cout << temp->val << " -> " ;
			temp = temp->next;
		}
		cout << "nullptr\n";
	}
	void _showLinkedList_inOrder_backward() {
		cout << "printing Linked list -- backward\n";
		Node * temp = senTail;
		while (temp) {
			cout << temp->val << " -> " ;
			temp = temp->prev;
		}
		cout << "nullptr\n";
	}
};
// Functions
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
	int capacity = 2;
	// cin >> capacity;
	LRUCache* obj = new LRUCache(capacity);
	// int param_1 = obj->get(key);
	// obj->put(key, value);
	obj->put(1, 1);
	obj->put(2, 2);
	obj->get(1);
	obj->put(3, 3);
	obj->get(2);
	obj->put(4, 4);
	obj->get(1);
	obj->get(3);
	obj->get(4);
	// obj->_showLinkedList_inOrder_backward();
	// obj->_showLinkedList_inOrder_forward();
	// int result = obj->get(100);
	// cout << "result : " << result << endl;
	return 0;
}

// todo Remove data from hashMap as well
// Output
// [null,null,null,1,null,2,null,1,3,-1]
// Expected
// [null,null,null,1,null,-1,null,-1,3,4]

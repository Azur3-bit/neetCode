// merge k sorted List
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
#include "TimerClock.h" // For Performance Monitorss

// Classes
struct ListNode {
	int val;
	ListNode * next;
	ListNode() : val(0) , next(nullptr) {}
	ListNode(int x) : val(x) , next(nullptr)  {}
	ListNode(int x , ListNode * _next) : val(x) , next(_next)  {}
};

// Functions
// show linked List
void _showLinkedList(ListNode * head) {
	while (head) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "end\n";
}
// show priortiy Queue
void _showPriortiyQueue(priority_queue<int> pq) {
	cout << "\nprinting queue \n";
	while (!pq.empty()) {
		cout << -1 * pq.top() << " ";
		pq.pop();
	}
	cout << "\nqueue has been Printed\n";
}

void _showPriortiyQueue_paired(priority_queue<pair<int, ListNode *>> & pq) {
	cout << "printing Paired priority_queue\n";
	while (!pq.empty()) {
		cout << -1 * pq.top().first << "\t" << pq.top().second << endl;
		pq.pop();
	}
}
void _showLinkedList_using_vector(vector<ListNode * > &nums) {
	for (auto it : nums)
		_showLinkedList(it);
}


int main(int argc, char const * argv[])
{
// #ifndef ONLINE_JUDGE

	// this is a new line and i am testing this code
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// -- Main Function code --
	ListNode * first = new ListNode(1);
	ListNode * forth = new ListNode(4);
	ListNode * fifth = new ListNode(5);
	// linking
	first->next = forth;
	forth->next = fifth;
	fifth->next = nullptr;

	ListNode * first_1 = new ListNode(1);
	ListNode * third_1 = new ListNode(3);
	ListNode * forth_1 = new ListNode(4);

	// linking
	first_1->next = third_1;
	third_1->next = forth_1;
	forth_1->next = nullptr;

	ListNode * second_2 = new ListNode(2);
	ListNode * sixth_2 = new ListNode(6);
	// linking
	second_2->next = sixth_2;
	sixth_2->next = nullptr;

	// linking heads
	ListNode * head_1 = first;
	ListNode * head_2 = first_1;
	ListNode * head_3 = second_2;

	// vector<ListNode * > = {{1, 4, 5}, {1, 3, 4}, {2, 6}}

	cout << "first_1 : " << first_1 << endl;
	// prints the address of the node

	vector<ListNode *> nums = {first, first_1, second_2};
	cout << "\nprinting all the linked list\n";
	_showLinkedList(first);
	_showLinkedList(first_1);
	_showLinkedList(second_2);

	cout << "\nprinting Address of heads \n";
	cout << "first : " << first << endl;
	cout << "first_1 : " << first_1 << endl;
	cout << "second_2 : " << second_2 << endl << endl;

	priority_queue<pair<int, ListNode * >> pq {};
	pq.push(make_pair(-1, first));
	pq.push(make_pair(-2, first_1));
	pq.push(make_pair(-3, second_2));
	_showPriortiyQueue_paired(pq);
	// solution(nums, pq);

	return 0;
}

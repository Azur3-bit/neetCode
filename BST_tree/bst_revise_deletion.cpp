// bst_revise_deletion

// class creation
// insertion
// level order traversal
// deletion


// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <array>
#include <unordered_map>
#include <unordered_set>
// #include "TimerClock.h" // For Performance Monitor
using namespace std;
#define dbg(x) cout <<  #x  << " : " << x << "\n";
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {os << "["; for (int i = 0; i < v.size(); ++i) {os << v[i]; if (i != v.size() - 1)os << ", ";} os << "]"; return os;}
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {T element; while (is >> element) {vec.push_back(element);} return is;}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& m) {cout << "---- Printing Ordered - Map\nKEY\tVALUE\n"; for (const auto& it : m)os << it.first << "\t" << it.second << "\n"; return os;}
template <typename T, typename S>
ostream& operator<<(ostream& os, const unordered_map<T, S>& m) {cout << "---- Printing Unordered - Map\nKEY\tVALUE\n"; for (const auto& it : m)os << it.first << "\t" << it.second << "\n"; return os;}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {os << "["; for (auto it = s.begin(); it != s.end(); ++it) {os << *it; if (next(it) != s.end())os << ", ";} os << "]"; return os;}
template <typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& s) {os << "["; for (auto it = s.begin(); it != s.end(); ++it) {os << *it; if (next(it) != s.end())os << ", ";} os << "]"; return os;}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& p) {os << "(" << p.first << ", " << p.second << ")"; return os;}
struct ListNode {int val; ListNode * next; ListNode (int _val) : val(_val), next(nullptr) {}};
void AddNode_end(ListNode *&head, int value) {ListNode *newNode = new ListNode(value); if (head == NULL) {head = newNode; return;} ListNode *temp = head; while (temp->next != NULL) {temp = temp->next;} temp->next = newNode;}
void _showLinkedList(ListNode *head) {while (head != NULL) {cout << head->val << " -> "; head = head->next;} cout << "NULL" << endl;}
void vec_linkedlist(ListNode*&head, vector<int> nums ) {for (auto it : nums) {AddNode_end(head, it);}}
// ------------------------------------------------------------------ solve

// (done) create tree
// (done) vec to tree
// (done) insertion in tree
// (done) level order treaverasl in tree
// deletion in tree


class node {
public:
	int data;
	node * right;
	node * left;

	node(int da) : data(da), right(nullptr), left(nullptr) {}
};

// insertion in bst
node*  bst_insertion(node * root, int val) {
	if (root == nullptr) {
		root = new node(val);
		return root;
		// return root = new node(val);
	}
	if (root->data < val)
		root->right = bst_insertion(root->right, val);
	else
		root->left = bst_insertion(root->left, val);
	// return root;
}


void bst_vec_bst(node *&root, vector<int> nums) {
// node * bst_vec_bst(node * root, vector<int> nums) {
	for (auto it : nums)
		root = bst_insertion(root, it);
	cout << "all the nodes have been inserted in the bst\n";
	// return root;
}

// checking via Inorder traverasl
void inOrder_traversal(node * root) {
	if (root == nullptr)
		return;
	inOrder_traversal(root->left);
	cout << root->data << " ";
	inOrder_traversal(root->right);
}

void bst_level_order_traversal(node * root) {
	queue<node *> q {};
	q.push(root);
	while (!q.empty()) {
		int l_size = q.size();
		for (int i = 0; i < l_size; ++i) {
			node * tempNode = q.front();
			q.pop();
			cout << tempNode->data << " ";

			if (tempNode->left)
				q.push(tempNode->left);
			if (tempNode->right)
				q.push(tempNode->right);
		}
		cout << "\n";
	}
}

void deletion_bst(node * root, int val) {

}

void solve() {
	// cout << "node createed \n";

	node * root = nullptr;
	vector<int> nums {};
	cin >> nums;
	dbg(nums);



	bst_vec_bst(root, nums);

	// cout << "root->data : " << root->data;
	// cout << "\n";
	// cout << "root->right->data : " << root->right->data;
	// cout << "root->right->right->data : " << root->right->right->data;
	// cout << "root->left->data : " << root->left->data;
	bst_level_order_traversal(root);

	// inOrder_traversal(root);
}
// ------------------------------------------------------------------ main
int main(int argc, char const * argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while (t--) {solve();}
	return 0;
}

// insertion deletion and searching in BST

// Major todo
// --- adding a node iterativily
// --- finding a node iterativily
// ---

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

/*
									// TODO
	- (done) insertion
	- (done) traeversing inorder
	- (done) traeversing preorder
	- (done) traeversing postnorder
	- (done) book tracing - inOrder postOrder preOrder
	- (done) searching
	- (done) min/max
	- (done) deletion
*/

class node {
public:
	int data;
	node * right ;
	node * left ;

	// constructor
	node(int da ) : data(da), right(nullptr), left(nullptr) {}
};

// --- traversals
void bst_traversal_inOrder(node * root) {
	if (root == nullptr)
		return;
	bst_traversal_inOrder(root->left);
	cout << root->data << " ";
	bst_traversal_inOrder(root->right);
}

void bst_traversal_postOrder(node * root) {
	if (root == nullptr)
		return;
	bst_traversal_postOrder(root->left);
	bst_traversal_postOrder(root->right);
	cout << root->data << " ";
}

void bst_traversal_PreOrder(node * root) {
	if (root == nullptr)
		return;
	cout << root->data << " ";
	bst_traversal_PreOrder(root->left);
	bst_traversal_PreOrder(root->right);

}


void printingQueue_Nodes(queue<node *> q) {
	while (!q.empty()) {
		node * currentElemenet = q.front();
		q.pop();
		cout << currentElemenet->data << " ";
	}
	cout << "\n";
}

void bst_traversal_levelOrder(node * root) {
	cout << "\n\n\n ----- level order traversal function \n";
	if (root == nullptr)
		return;
	queue<node *> q {};
	q.push(root);

	while (!q.empty()) {
		int lvl_size = q.size();
		for (int i = 0; i < lvl_size; ++i) {
			node * tempNode = q.front();
			cout << tempNode->data << " ";
			q.pop();
			if (tempNode->left) {
				q.push(tempNode->left);
			}
			if (tempNode->right) {
				q.push(tempNode->right);
			}
		}
		cout << "\n";
	}
}
void levelOrderTraversal_correct_original(node* root) {
	if (root == nullptr)
		return;
	queue<node * > q {};
	q.push(root);
	// printingQueue_Nodes(q);
	while (!q.empty()) {
		int lvl_size = q.size();
		for (int i = 0; i < lvl_size; ++i) {
			node * tempNode = q.front();
			cout << tempNode->data << " ";
			q.pop();

			// adding all the elements from left and right
			if (tempNode->left)
				q.push(tempNode->left);
			if (tempNode->right)
				q.push(tempNode->right);
		}
		cout << "\n";
	}
}
// --- insertion
node * bst_insertNode(node * root, int d) {
	if (root == nullptr) {
		return root = new node(d);
	}

	if (root->data > d)
		root->left = bst_insertNode(root->left, d);
	else
		root->right = bst_insertNode(root->right, d);
}

void bst_vector(node * &root, vector<int> nums) {
	cout << "adding nodes to the root node ..\n";
	for (int it : nums) {
		cout << "adding node : " << it << "\n";
		root = bst_insertNode(root, it);
	}
	cout << "nodes added to the root node ..\n";
}

// --- UTILITY functions
bool bst_find_element(node * root, int num) {
	if (root == nullptr)
		return false;
	if (root->data == num)
		return true;
	if (root->data < num) {
		return bst_find_element(root->right, num);
	}
	if (root->data > num)
		return bst_find_element(root->left, num);
}

int max_value(node * root) {
	if (root->right == nullptr)
		return root->data;
	else
		return max_value(root->right);
}

int min_value(node * root) {
	if (root->left == nullptr)
		return root->data;
	else
		return min_value(root->left);
}


node * bst_findLastRightChild(node * root) {
	if (root->right == nullptr)
		return root;
	return bst_findLastRightChild(root->right);
}

node * helper_bst_delete_node(node * root) {

	// connection if any one side of the sub-tree is null
	// agar koi ek side null hai tho ovio ki opp. side se hi connection banega
	if (root->right == nullptr)
		return root->left;
	if (root->left == nullptr)
		return root->right;

	// current right
	node * currRight = root->right;
	// max value in the left sub tree
	node * max_value_left_subtree = bst_findLastRightChild(root->left);
	// connect LeftSubtree-MaxValue child to the right node of the current root node
	max_value_left_subtree->right = currRight;

	return root->left;

}
node * bst_delete_node(node * root, int val) {

	if (root == nullptr) { // agar mera root null hai tho return kar diya ki koi node nhi hai
		return nullptr;
	}
	if (root->data == val) {
		// agar root hi mera woh node hai jis ko delete karna hai
		return helper_bst_delete_node(root);
	}

	node * dummy = root; // kyuki root pe traversal hoga and dummy woh node hoga jis ko hum fianlly delete karenge
	while (root != nullptr) {

		if (root->data < val) {
			if (root->right != nullptr && root->right->data == val) {
				root->right = helper_bst_delete_node(root->right);
				break;
			}
			else {
				root = root->right;
			}
		}
		else {
			if (root->left != nullptr && root->left->data == val) {
				root->left = helper_bst_delete_node(root->left);
				break;
			}
			else {
				root = root->left;
			}
		}
	}
	return dummy;
}

// --- main execution
void solve() {
	// vector<int> nums = {10, 8, 21, 7, 27, 5, 4, 3};
	vector<int> nums {};
	cin >> nums;
	dbg(nums);

	node * root = nullptr;
	bst_vector(root, nums);

	cout << "\nPrinting tree in - IN Order\n";
	bst_traversal_inOrder(root);

	cout << "\n\nPrinting tree in - PRE Order\n";
	bst_traversal_PreOrder(root);


	cout << "\n\nPrinting tree in - POST Order\n";
	bst_traversal_postOrder(root);


	cout << "\n\nfinding element in bst \n";
	int element_to_be_found = 100;
	bool ans_find_element = bst_find_element(root, element_to_be_found);
	if (ans_find_element)
		cout << "++ present\n";
	else
		cout << "-- absent\n";


	cout << "\nfinding max value ...\n";
	int ans_max_value = max_value(root);
	dbg(ans_max_value);

	cout << "\nfinding min value ...\n";
	int ans_min_value = min_value(root);
	dbg(ans_min_value);


	cout << "\n Printing level Order Traversal \n";
	bst_traversal_levelOrder(root);

	// cout << "correct level Order Traversal\n";
	// levelOrderTraversal_correct_original(root);


	// ------ deletion of node
	// -- both the childs are null
	// node * deleteNode_both_null_call = deleteNode_both_null(root, 3);

	cout << "main :: root->data : " << root->data << "\n";

	// root = bst_delete_node(root, 3);
	// root = bst_delete_node(root, 99);
	root = bst_delete_node(root, 5);
	bst_traversal_levelOrder(root);

}
// ------------------------------------------------------------------ main
int main(int argc, char const * argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while (t--) {solve();}
	return 0;
}

// All_Nodes_Distance_K_in_Binary_Tree

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
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::stack<T>& s) {std::stack<T> temp = s; os << "["; while (!temp.empty()) {os << temp.top(); temp.pop(); if (!temp.empty()) {os << ", ";}} os << "]"; return os;}
// --- Linked list
struct ListNode {int val; ListNode * next; ListNode (int _val) : val(_val), next(nullptr) {}};
void AddNode_end(ListNode *&head, int value) {ListNode *newNode = new ListNode(value); if (head == NULL) {head = newNode; return;} ListNode *temp = head; while (temp->next != NULL) {temp = temp->next;} temp->next = newNode;}
void _showLinkedList(ListNode *head) {while (head != NULL) {cout << head->val << " -> "; head = head->next;} cout << "NULL" << endl;}
void vec_linkedlist(ListNode*&head, vector<int> nums ) {for (auto it : nums) {AddNode_end(head, it);}}
// --- tree
class treenode {public: int val; treenode * right ; treenode * left ; treenode(int da ) : val(da), right(nullptr), left(nullptr) {}};
void bst_traversal_inOrder(treenode * root) {if (root == nullptr) {return;} bst_traversal_inOrder(root->left); cout << root->val << " "; bst_traversal_inOrder(root->right);}
void bst_traversal_postOrder(treenode * root) {if (root == nullptr) {return;} bst_traversal_postOrder(root->left); bst_traversal_postOrder(root->right); cout << root->val << " ";}
void bst_traversal_PreOrder(treenode * root) {if (root == nullptr) {return;} cout << root->val << " "; bst_traversal_PreOrder(root->left); bst_traversal_PreOrder(root->right);}
void bst_levelOrder(treenode * root) {if (root == nullptr) {return;} queue<treenode *> q {}; q.push(root); while (!q.empty()) {int lvl_size = q.size(); for (int i = 0; i < lvl_size; ++i) {treenode * temptreenode = q.front(); cout << temptreenode->val << " "; q.pop(); if (temptreenode->left) {q.push(temptreenode->left);} if (temptreenode->right) {q.push(temptreenode->right);}} cout << "\n";}}
treenode * bst_inserttreenode(treenode * root, int d) {if (root == nullptr) {return root = new treenode(d);} if (root->val > d) {root->left = bst_inserttreenode(root->left, d);} else {root->right = bst_inserttreenode(root->right, d);}}
void bst_vector(treenode * &root, vector<int> nums) {for (int it : nums) {root = bst_inserttreenode(root, it);} cout << "nodes added to bst !\n";}
treenode* createBinaryTree(const vector<int>& vec) {if (vec.empty()) {return nullptr;} treenode* root = new treenode(vec[0]); vector<treenode*> nodes; nodes.push_back(root); for (int i = 1; i < vec.size(); ++i) {treenode* node = nullptr; if (vec[i] != -1) {node = new treenode(vec[i]); nodes.push_back(node);} treenode* parent = nodes[(i - 1) / 2]; if (i % 2 == 1) {parent->left = node;} else {parent->right = node;}} return root;}

// ------------------------------------------------------------------ solve
treenode * get_to_targetNode(treenode * root, map<treenode *, int> hm, int e) {
	for (auto it : hm) {
		if (it.second == e) {
			return it.first;
		}
	}
	return nullptr;
}
void helper_map(treenode * root, map<treenode *, int> &hm) {
	if (!root)
		return;
	helper_map(root->left, hm);
	hm[root] = root->val;
	helper_map(root->right, hm);
}

void createParentMap(treenode * root, map<treenode *, treenode *> &parentMap) {
	if (!root)
		return;
	// levelOrder Traversal
	queue<treenode *> q{};
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			treenode * node = q.front();
			q.pop();
			if (node->left) {
				parentMap[node->left] = node;
				q.push(node->left);
			}
			if (node->right) {
				parentMap[node->right] = node;
				q.push(node->right);
			}
		}
	}
}
vector<int> answer(treenode * root, int target_node, int distance) {
	if (root == nullptr)
		return {};
	map<treenode *, int> h_map {};
	helper_map(root, h_map);
	dbg(h_map);
	// node pointer
	treenode * target = get_to_targetNode(root, h_map, target_node);
	dbg(target->val);
	dbg(distance);
	cout << "\n";

	// Actual solution start
	map<treenode *, treenode *> parentMap {};
	createParentMap(root, parentMap);
	dbg(parentMap);

	map<treenode *, bool> visisted {};
	vector<vector<int>> ans {};
	queue<treenode *> q{};
	q.push(target);
	visisted[target] = true;
	while (!q.empty()) {
		int size = q.size();
		vector<int> temp_ans{};
		for (int i = 0; i < size; i++) {
			treenode * node = q.front();
			q.pop();
			if (node->left && !visisted[node->left]) {
				q.push(node->left);
				visisted[node->left] = true;
				temp_ans.push_back(node->left->val);
			}
			if (node->right && !visisted[node->right]) {
				q.push(node->right);
				visisted[node->right] = true;
				temp_ans.push_back(node->right->val);
			}
			if (parentMap.find(node) != parentMap.end()) {
				treenode * parent_node = parentMap[node];
				if (!visisted[parent_node]) {
					q.push(parent_node);
					visisted[parent_node] = true;
					temp_ans.push_back(parent_node->val);
				}
			}
		}
		ans.push_back(temp_ans);
	}

	dbg(ans);
	return ans[distance - 1];
}

void solve() {
	int target_node;
	cin >> target_node;
	int distance;
	cin >> distance;
	vector<int> v {};
	cin >> v;
	treenode * root = createBinaryTree(v);
	bst_levelOrder(root);
	cout << "----------------------------------\n";

	vector<int> ans = answer(root, target_node, distance);
	dbg(ans);
}
// ------------------------------------------------------------------ main
int main(int argc, char const* argv[]) {
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

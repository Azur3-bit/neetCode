// finding a element in the ordered map
// finding a element in the unordered map


// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <typeinfo>
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
class treenode {public: int data; treenode * right ; treenode * left ; treenode(int da ) : data(da), right(nullptr), left(nullptr) {}};
void bst_traversal_inOrder(treenode * root) {if (root == nullptr) {return;} bst_traversal_inOrder(root->left); cout << root->data << " "; bst_traversal_inOrder(root->right);}
void bst_traversal_postOrder(treenode * root) {if (root == nullptr) {return;} bst_traversal_postOrder(root->left); bst_traversal_postOrder(root->right); cout << root->data << " ";}
void bst_traversal_PreOrder(treenode * root) {if (root == nullptr) {return;} cout << root->data << " "; bst_traversal_PreOrder(root->left); bst_traversal_PreOrder(root->right);}
void bst_levelOrder(treenode * root) {if (root == nullptr) {return;} queue<treenode *> q {}; q.push(root); while (!q.empty()) {int lvl_size = q.size(); for (int i = 0; i < lvl_size; ++i) {treenode * temptreenode = q.front(); cout << temptreenode->data << " "; q.pop(); if (temptreenode->left) {q.push(temptreenode->left);} if (temptreenode->right) {q.push(temptreenode->right);}} cout << "\n";}}
treenode * bst_inserttreenode(treenode * root, int d) {if (root == nullptr) {return root = new treenode(d);} if (root->data > d) {root->left = bst_inserttreenode(root->left, d);} else {root->right = bst_inserttreenode(root->right, d);}}
void bst_vector(treenode * &root, vector<int> nums) {for (int it : nums) {root = bst_inserttreenode(root, it);} cout << "nodes added to bst !\n";}
// ------------------------------------------------------------------ solve
vector<int> element_withSameFreq(map<int, int> HM, int freq) {
	vector<int> ans {};
	for (auto it : HM) {
		if (it.second == freq)
			ans.push_back(it.first);
	}
	return ans;
}

void solve_without_order_lower_and_higer() {
	vector<int> nums {};
	cin >> nums;
	dbg(nums);
	map<int, int> HM{};
	for (auto it : nums)
		HM[it]++;
	dbg(HM);
	vector<pair<int, int>> freq_ele {};
	for (auto it : HM) {
		freq_ele.push_back(make_pair(it.second, it.first));
	}
	dbg(freq_ele);
	sort(freq_ele.begin(), freq_ele.end());
	dbg(freq_ele);
	vector<int> res {};
	for (auto i = (int)freq_ele.size() - 1; i >= 0; i--) {
		cout << " i : " << freq_ele[i].first << "\n";
		for (int j = 0; j < freq_ele[i].first; j++) {
			res.push_back(freq_ele[i].second);
		}
	}
	dbg(res);
}



vector<int> elements_with_freq_func(unordered_map<int, int> HM, int data) {
	vector<int> ans {};
	for (auto it : HM) {
		if (it.second == data)
			ans.push_back(it.first);
	}


	sort(ans.begin(), ans.end());
	return ans;
}

void solve() {
	vector<int> nums{};
	cin >> nums ;
	dbg(nums);
	unordered_map<int, int> HM{};
	for (auto it : nums)
		HM[it]++ ;
	dbg(HM);
	set<int> freq {};
	for (auto it : HM) {
		freq.insert(it.second);
	}
	dbg(freq);
	vector<int> res {};
	for (auto i = freq.rbegin(); i != freq.rend(); i++) {
		int currFreq = *i;
		vector<int> elements_with_freq {};
		elements_with_freq =  elements_with_freq_func(HM, currFreq);
		dbg(elements_with_freq);
		dbg(currFreq);

		// -- unoptimized
		// for (int j = 0; j < (int)elements_with_freq.size(); j++) {
		// 	dbg(j);
		// 	int temp = currFreq;
		// 	dbg(elements_with_freq[j]);
		// 	while (temp > 0) {
		// 		dbg(temp);
		// 		dbg(currFreq);
		// 		res.push_back(elements_with_freq[j]);
		// 		temp--;
		// 	}
		// }

		for (auto element : elements_with_freq) {
			for (int j = 0; j < currFreq; j++)
				res.push_back(element);
		}

	}
	dbg(res);
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

// Minimum Window Substring
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
// implementing is window valid
bool isValid(unordered_map<char, int>s_HM, unordered_map<char, int> t_HM) {
	cout << "-------------------------\n";
	dbg(s_HM);
	// dbg(t_HM);
	cout << "-------------------------\n";
	for (auto it : t_HM) {
		// cout << "checking element : " << it.first << "\n";
		char element_tobeFound = it.first;
		if (t_HM.find(element_tobeFound) != s_HM.end()) {
			// element found -> checking its freq
			if (it.second <= s_HM[element_tobeFound]) {
				// cout << "element found with same freq\n";
			}
			else {
				cout << "element found without same freq -- " << it.first << "\n";
				return false;
			}
		}
		// cout << "element not found \n";
		// return false;
	}
	return true;
}
void printWindow(int a, int z, string s) {
	for (int i = a; i <= z; i++) {
		cout << s[i] << " ";
	}
	cout << "\n";
}

void solve() {
	string s, t;
	cin >> s;
	cin >> t;
	dbg(s);
	dbg(t);

	unordered_map<char, int> s_HM{};
	unordered_map<char, int> t_HM{};
	vector<pair<int, int>> ans {};
	vector<int> size_ans{};
	// adding all the elments of t into the hashMap
	for (auto it : t)
		t_HM[it]++;
	dbg(t_HM);

	// sliding window intialization
	int i = 0;
	int j = 0;
	int ans_i = 0, ans_j = 0;

	int curr_windowSize = INT_MAX;
	while (j < s.size()) {
		// cout << "inside while loop \n";
		s_HM[s[j]]++;
		if (!isValid(s_HM, t_HM)) {
			printWindow(i, j, s);
			++j;
		}
		if (isValid(s_HM, t_HM)) {
			cout << "valid window hit \n";
			dbg(i);
			dbg(j);
			// break;
			// pushing a possiable answer in the vector

			if (curr_windowSize > (j - i + 1)) {
				cout << "breakPoint - 1\n";
				curr_windowSize = min(curr_windowSize, (j - i + 1));
				ans_i = i;
				ans_j = j;
			}
			ans.push_back(make_pair(i, j));
			size_ans.push_back(j - i + 1);
			// cout << "------------------------ DEBUGGING \n";
			printWindow(i, j, s);
			while (isValid(s_HM, t_HM)) {
				// debuging
				ans.push_back(make_pair(i, j));
				size_ans.push_back(j - i + 1);
				dbg(s_HM);
				s_HM[s[i]]--;
				++i;
				printWindow(i, j, s);
				if (curr_windowSize > (j - i + 1)) {
					cout << "BreakPoint-2\n";
					curr_windowSize = min(curr_windowSize, (j - i + 1));
					ans_i = i;
					ans_j = j;
				}
			}
			// cout << "------------------------ DEBUGGING \n";
			cout << "invalid window achived\n";
			dbg(i);
			dbg(j);
			++j;
			// break;
		}
	}
	dbg(ans);
	cout << "\n";
	dbg(size_ans);
	// auto final_ans = ;
	cout << "final answer : " << *min_element(size_ans.begin(), size_ans.end()) << "\n";

	// attempting answer format
	dbg(--ans_i);
	dbg(ans_j);
	// getting all the elements in the final answer range
	string answerString = "";
	for (int i = ans_i; i <= ans_j; i++)
		answerString += s[i];
	dbg(answerString);
	// return answerString;
#if 0
	// adding all the elements of s into the hashMap
	for (auto it : s)
		s_HM[it]++;
	dbg(s_HM);

	// testing isValid Function
	bool ans = isValid(s_HM, t_HM);
	if (ans == true)
		cout << "windoww is valid \n";
	else
		cout << "windoww is In - valid \n";
#endif
}
// ------------------------------------------------------------------ main
int main(int argc, char const* argv[]) {
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

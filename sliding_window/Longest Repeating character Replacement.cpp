// failed testCase ->
// 1
// AABABBA

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
#define dbg(x) cout << "\n"<<  #x  << " : " << x << "\n";
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
void maxOccurenedElement_in_HashMap(const unordered_map<char, int> &HM, int &maxOcc_count, char &pass_maxOccurenedElement_char) {
	if (HM.empty()) {
		maxOcc_count = 0;
		pass_maxOccurenedElement_char = ' ';
		return;
	}
	dbg(HM);
	auto max_count = HM.begin()->second;
	char maxOccurenedElement = HM.begin()->first;
	dbg(max_count);
	// dbg()
	for (auto it : HM) {
		cout << "element : " << it.first << " occurened_count : " << it.second << "\n";
		if (it.second > max_count) {
			cout << "current max occurened elment : " << maxOccurenedElement;
			maxOccurenedElement = it.first;
			cout << " changing to :-> " << maxOccurenedElement << "\n";
			max_count = it.second;
		}
	}
	pass_maxOccurenedElement_char = maxOccurenedElement;
	maxOcc_count = max_count;
#if 0
	cout << "\n------ ANSWER ---- \n";
	cout << "maxOccurenedElement : " << maxOccurenedElement;
	cout << "\nmax count : " << maxOcc_count;
	cout << "\n";
	// cout << "\n\n--------------------------------------- Debugging \n\n";
	// return ;
#endif
}
void _printCurrentWindow(int a, int b, string s) {
	cout << "\t-- Printing Window\n";
	for (int i = a; i <= b; i++) {
		cout << s[i] << " ";
	}
	cout << "\n";
}
bool _isWindowValid(int k, int i, int j, int max_count) {
	int windowSize = j - i + 1;
	if (windowSize - max_count <= k)
		return true;
	return false;
}
void solve() {
	string s;
	int k;
	cin >> k;
	cin >> s;
	dbg(s);
	dbg(k);
	cout << "=======================================\n\n";
	cout << "\t\tsliding window\n";
	// sliding window
	int i = 0;
	int j = 0;
	vector<int> final_ans {};
	int maxOCC_count = 0;
	char maxOccurenedElement_char = 'a';
	unordered_map<char, int> HM {} ;
	while (j < s.size()) {
		cout << s[j] << " ";
		_printCurrentWindow(i, j, s);
		HM[s[j]]++;
		dbg(HM);
		maxOccurenedElement_in_HashMap(HM, maxOCC_count, maxOccurenedElement_char);
		bool answer_isValid = _isWindowValid(k, i, j, maxOCC_count);
		if (_isWindowValid(k, i, j, maxOCC_count) || (s[j] == maxOccurenedElement_char))
			++j;
		while (_isWindowValid(k, i, j, maxOCC_count) == false) {
			HM[s[i]]--;
			++i;
		}
		final_ans.push_back(j - i + 1);
	}
	dbg(final_ans);
	cout << "answer : " << *max_element(final_ans.begin(), final_ans.end());
	// return final_ans;
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


#if 0
	unordered_map<char, int> HM {};
	string  s = "ioioiooioioiopp";
	for (auto it : s) {
		HM[it]++;
	}
	dbg(HM);
	int maxOcc_count = 0;
	char maxOcc_char = 'a';
	maxOccurenedElement_in_HashMap(HM, maxOcc_count, maxOcc_char);
	char fixedElement_char = maxOcc_char;
	cout << "elment occured the most -> fixedElement_char : " << fixedElement_char << "\n";
	cout << "number of fixed characters - maxOcc_count -> " << maxOcc_count << "\n";
#endif


	return 0;
}

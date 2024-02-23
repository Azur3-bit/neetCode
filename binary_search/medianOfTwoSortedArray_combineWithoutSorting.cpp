// medianOfTwoSortedArray_combineWithoutSorting
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
double median(vector<int>nums1, vector<int> nums2) {
	dbg(nums1);
	dbg(nums2);
	int totalSize = nums1.size() + nums2.size();
	dbg(totalSize);
	vector<int> nums {};
	// have to pointer compare untill on of the array gets complete
	int size_1 = nums1.size();
	int size_2 = nums2.size();
	int ptr1 = 0;
	int ptr2 = 0;
	while (ptr1 != nums1.size() && ptr2 != nums2.size()) {
		// compare and go ahead
		// break;
		cout << nums1[ptr1] << " -- " << nums2[ptr2] << "\n";
		if (nums1[ptr1] < nums2[ptr2]) {
			cout << "pushing .. . " << nums1[ptr1] << "\n";
			nums.push_back(nums1[ptr1]);
			ptr1++;
		}
		else if (nums1[ptr1] >= nums2[ptr2]) {
			cout << "pushing .. . " << nums2[ptr2] << "\n";
			nums.push_back(nums2[ptr2]);
			ptr2++;
		}
	}
	while (ptr2 != nums2.size())
		nums.push_back(nums2[ptr2++]);
	while (ptr1 != nums1.size())
		nums.push_back(nums1[ptr1++]);
	dbg(nums);
	double ans = 0;
	// if (nums.size() % 2 == 0 ) {
	// 	int first_index = (int)nums.size() / 2;
	// 	int second_index = ((int)nums.size() / 2) - 1;
	// 	cout << "size is even \n";
	// 	ans = ((double)nums[first_index] + (double)nums[second_index]) / 2;
	// 	cout << nums[first_index] << " + " << nums[second_index] << " /2 = " << (double)ans << "\n";
	// }

	// else {
	// 	cout << "size is odd\n";
	// 	ans = nums[(int)nums.size() / 2];
	// 	cout << "answer : " << ans << "\n";
	// }
	return nums.size() % 2 == 0 ? ((double)nums[(int)nums.size() / 2] + (double)nums[((int)nums.size() / 2) - 1]) / 2 : ans = nums[(int)nums.size() / 2];
}
void solve() {
	// vector<int> nums1 = {1, 3};
	// vector<int> nums2 = {2};
	vector<int> nums1 = {1, 2, 10};
	vector<int> nums2 = {2, 3, 4};
	double ans = median(nums1, nums2);
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

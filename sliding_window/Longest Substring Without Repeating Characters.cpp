// Essential libraries
#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <climits>
#include <queue>
// Additional libraries
#include <stack>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include "TimerClock.h" // For Performance Monitor
using namespace std;
#define debug(x) cout << "\n"<<  #x  << " : " << x << endl;
// Operator overloads
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "[";
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)
			os << ", ";
	}
	os << "]";
	return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {
	T element;
	while (is >> element) {
		vec.push_back(element);
	}
	return is;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& m) {
	for (const auto& it : m)
		os << it.first << " : " << it.second << "\n";
	return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
	os << "[";
	for (auto it = s.begin(); it != s.end(); ++it) {
		os << *it;
		if (next(it) != s.end())
			os << ", ";
	}
	os << "]";
	return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
// ------------------------------------------------------------------
void solve() {
	// Main code goes here
	string s;
	cin >> s;
	debug(s);

	// 0 	1 	2 	3 	4 	5 	6 	7
	// a 	b 	c 	a 	b 	c 	b 	b
	// 		front
	// 			back

	// a
	int size = s.size();
	if (size <= 1) {
		cout << "size - 1\n";
		return ;
	}
	if (size == 2) {
		int res = (count(s.begin(), s.end(), s[0]));
		if (res >= 2 ) {
			cout << "size - 2 repeated\n";
			return ;
		}
		cout << "size - 2 non repeated\n";
		return ;
	}
	int front = 0;
	int back = 1;
	vector<int> ans{};
	debug(size);
	char s_first = s[0];
	string s_temp = "";
	s_temp += s_first;
	debug(s[front]);
	debug(s[back]);
	while (front <= size && back <= size) {
		debug(s_temp);
		// cout << "going Inside Loop ----\n";
		for (int i = 0; i < s_temp.size(); i++) {
			// cout << s_temp[i] << " ";s
			int counter = count(s_temp.begin(), s_temp.end(), s_temp[i]);
			if (counter > 1) {
				ans.push_back(back - front);
				s_temp = s_temp.substr(1);
				front++;
			}
		}
		debug(front);
		debug(back);
		if (front == size) {
			ans.push_back(s[back]);
		}
		s_temp += s[back];
		back++;
	}
	cout << ans ;
	int maxi = *max_element(ans.begin(), ans.end());
	debug(maxi);
	// return maxi;
}
// ------------------------------------------------------------------
int main(int argc, char const* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	// Faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// Main function code here
	int t = 1;
	// cin >> t;
	while (t--) {solve();}
	return 0;
}

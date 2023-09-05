// -- essential_libraries_and_namespace
#include <iostream>
using namespace std;
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
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{	// << opertor overloading vector output
	os << "[";
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)
			os << ", ";
	}
	os << "]\n";
	return os;
}
template <typename T>
std::istream& operator>>(std::istream& input, std::vector<T>& vec) {
	T element; // >> opertor overloading vector input
	while (input >> element) {
		vec.push_back(element);
	}
	return input;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v)
{	// << opertor overloading map output
	for (auto it : v)
		os << it.first << " : "
		   << it.second << "\n";
	return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v)
{	// << opertor overloading set output
	os << "[";
	for (auto it : v) {
		os << it;
		if (it != *v.rbegin())
			os << ", ";
	}
	os << "]\n";
	return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v)
{	// << opertor overloading pair output
	os << "(";
	os << v.first << ", "
	   << v.second << ")";
	return os;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// -- Main Function code --

	return 0;
}

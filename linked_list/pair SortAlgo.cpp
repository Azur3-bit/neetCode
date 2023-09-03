// testing sorting pair<int, Node * >

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
#include "TimerClock.h" // For Performance Monitor

// Classes

// Functions
template<typename type_1 , typename type_2>
void pairSort(vector<pair<type_1, type_2>> &nums) {
	cout << "inside pair sort\n";
	sort(nums.begin(), nums.end());
	for (auto it : nums) {
		cout << it.first << "\t" << it.second << endl;
	}
	return;
}
void testing_pairSort_int_int() {
	vector<pair<int, int>> nums{};
	nums.push_back(make_pair(1, 5000));
	nums.push_back(make_pair(5, 500));
	nums.push_back(make_pair(3, 300));
	nums.push_back(make_pair(2, 200));
	nums.push_back(make_pair(4, 400));
	nums.push_back(make_pair(1, 500));
	pairSort(nums);
}
void testing_pairSort_string_string() {
	vector<pair<string, string>> strs{};
	strs.push_back(make_pair("abc", "asdf"));
	strs.push_back(make_pair("zbc", "asdflll"));
	strs.push_back(make_pair("bvc", "asdfl"));
	strs.push_back(make_pair("lkj", "asdfll"));

	pairSort(strs);
}
int main(int argc, char const *argv[])
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// -- Main Function code --
	cout << "testing Pair sort using int , int \n";
	testing_pairSort_int_int();
	cout << "testing Pair sort using string , string \n";
	testing_pairSort_string_string();

	return 0;
}

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
template <typename type_1>
void _input(vector<type_1> &nums)
{
	type_1 input;
	while (cin >> input)
	{
		nums.push_back(input);
		if (cin.peek() == '\n')
			break;
	}
	cout << endl;
}
template <typename T>
void _showSet(const std::set<T>& numsSet) {
	std::cout << "-*-  -*- -*-" << std::endl;
	std::cout << "Printing Set" << std::endl;
	std::cout << std::endl;
	std::cout << "{ ";
	for (auto it = numsSet.begin(); it != numsSet.end(); ++it) {
		std::cout << *it;
		if (std::next(it) != numsSet.end())
			std::cout << ", ";
	}
	std::cout << " }" << std::endl;
	std::cout << "-*-  -*- -*-" << std::endl;
}
template <typename type_2>
void _showVector(const vector<type_2> &nums)
{
	cout << ":: Printing Vector :: " << endl;
	cout << "{ ";
	for (type_2 it : nums)
	{
		cout << it << " ";
	}
	cout << "}";
	cout << endl;
	cout << ":: Vector Printed :: " << endl;
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

	vector<int> nums;
	_input(nums);
	_showVector(nums);


	set<int> set_1 = {1, 23, 55};
	_showSet(set_1);



	return 0;
}
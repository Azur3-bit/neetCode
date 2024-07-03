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

int answer(vector<int> &nums) {

	// Creating a fast And a Slow Pointer

	int fast = nums[0];
	int slow = nums[0];


	fast = nums[nums[fast]];
	slow = nums[slow];

	while (fast != slow) {
		fast = nums[nums[fast]];
		slow = nums[slow];
	}
	fast = nums[0];
	while (fast != slow) {
		fast = nums[fast];
		slow = nums[slow];
	}
	return fast;
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

	vector<int> nums {};
	_input(nums);
	_showVector(nums);

	int ans = answer(nums);
	cout << "ans : " << ans << endl;
	return 0;
}

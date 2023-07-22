// longestConsecutive
// -- essential_libraries_and_namespace
#include <iostream>
using namespace std;

// -- additional_libraries
#include <vector>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
// -- additional_libraries -- azur3
#include "TimerClock.h"

// Classes

//  -- Prints Vector
void _showVector(const vector<int> &nums)
{
	cout << ":: Printing Vector :: \n";
	cout << "{";
	for (int it : nums)
	{
		cout << it << " ";
	}
	cout << "}";
}

//  -- Prints Set
void _showSet(const set<int> &setNums)
{
	cout << ":: Printing Set :: \n";
	cout << "{";
	for (int it : setNums)
	{
		cout << it << " ";
	}
	cout << "}";
}

// Functions

void _consecutiveSequence(vector<int> &nums)
{
	set<int> setNums{};
	int counter = 0;
	cout << ":: Pushing Elements into an Ordered Set :: \n";
	for (int i = 0; i < nums.size();i++)
	{
		setNums.insert(nums[i]);
	}

	// -- Working Fine 
	// cout << "-- -- --- --- -- -- \n";
	// _showSet(setNums);
	// -- Working Fine 


}

// TODO Check weather sets also have indexing values


int main(int argc, char const *argv[])
{

	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// -- Main Function code --

	vector<int> nums = {100, 4, 200, 1, 3, 2};
	// _showVector(nums);
	_consecutiveSequence(nums);

	return 0;
}
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

// -- Printing HashMap
void _showHashMap(map<int, bool> &hashMap)
{
	std::cout << ":: Printing HashMap :: \n";
	std::cout << "Key \t Value\n";
	for (auto it : hashMap)
	{
		std::cout << it.first << "\t" << it.second << "\n";
	}
}

//  -- Prints Vector
void _showVector(const vector<int> &nums)
{
	std::cout << ":: Printing Vector :: \n";
	std::cout << "{";
	for (int it : nums)
	{
		std::cout << it << " ";
	}
	std::cout << "}";
}

//  -- Prints Set
void _showSet(const set<int> &setNums)
{
	std::cout << ":: Printing Set :: \n";
	std::cout << "{";
	for (int it : setNums)
	{
		std::cout << it << " ";
	}
	std::cout << "}";
}

// Functions

void _consecutiveSequence(vector<int> &nums)
{

	map<int, bool> hashMap{};
	for (int it : nums)
	{
		hashMap[it] = false;
	}
	// -- Working Fine
	// std::cout << "-- -- --- --- -- -- \n";
	// _showSet(setNums);
	// -- Working Fine

	_showHashMap(hashMap);
	int maxCounter = 0;
	int itera = 1;

	for (auto it : hashMap)
	{
		int curr_key = it.first;
		std::cout << "Current Key -> " << curr_key << endl;
		if (it.second == false)
		{
			auto prevElemment = hashMap.find(curr_key - 1);

			if (prevElemment != hashMap.end())
			{
				it.second = true;

				std::cout << "--- " << endl;

				std::cout << "batch -> " << curr_key << endl;
				std::cout << "Changing in " << prevElemment->second << " to true '1' " << endl;
				// std::cout << prevElemment->first << endl;

				++maxCounter;
				prevElemment->second = true;
			}

			auto nxtElement = hashMap.find(curr_key + 1);
			if (nxtElement != hashMap.end())
			{
				++maxCounter;
				nxtElement->second = true;
				std::cout << "Changing in " << prevElemment->second << "to true '1' " << endl;
				std::cout << "--- " << endl;
			}
			std::cout << "-- * -- Iteration " << itera << endl;
			_showHashMap(hashMap);
		}
	}
	std::cout << "Max Counter : " << maxCounter + 1;
}

// TODO Check weather sets also have indexing values

int main(int argc, char const *argv[])
{

	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// -- Main Function code --

	// TestCase - 1
	// vector<int> nums = {100, 4, 200, 1, 3, 2};

	// TestCase - 2
	// vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

	// TestCase - 3
	std::cout << "Entered Vector " << endl;
	vector<int> nums = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
	_showVector(nums);

	std::cout << "\nvector After Sorting" << endl;
	sort(nums.begin(), nums.end());
	_showVector(nums);
	std::cout << endl;

	// _showVector(nums);
	_consecutiveSequence(nums);

	return 0;
}
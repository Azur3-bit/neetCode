// neetCode - TwoSum
#include <iostream>
using namespace std;

// additional_libraries
#include <vector>
#include <array>
#include <unordered_map>
#include <map>
#include <set>

// Classes

// Functions

class Solution
{
public:
	vector<int> twoSumTwoPass(vector<int> &nums, int target)
	{
		unordered_map<int, int> numMap;
		int n = nums.size();

		// Build the hash table
		for (int i = 0; i < n; i++)
		{
			numMap[nums[i]] = i;
		}

		// Find the complement
		for (int i = 0; i < n; i++)
		{
			int complement = target - nums[i];
			if (numMap.count(complement) && numMap[complement] != i)
			{
				return {i, numMap[complement]};
			}
		}

		return {}; // No solution found
	}

	vector<int> twoSumOnePass(vector<int> &nums, int target)
	{
		unordered_map<int, int> numMap;
		int n = nums.size();

		for (int i = 0; i < n; i++)
		{
			int complement = target - nums[i];
			if (numMap.count(complement))
			{
				return {numMap[complement], i};
			}
			numMap[nums[i]] = i;
		}

		return {}; // No solution found
	}
};

void PrintingVector(vector<int> nums)
{
	cout << "Printing vector " << endl;
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		cout << nums[i] << "\n";
	}
}

int main(int argc, char const *argv[])
{
	// Main Code Function
	Solution obj;
	vector<int> nums = {1, 2, 3, 4, 5};
	vector<int> Solution;
	Solution = obj.twoSumOnePass(nums, 7);
	PrintingVector(Solution);

	return 0;
}
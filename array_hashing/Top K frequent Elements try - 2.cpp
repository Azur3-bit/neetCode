// Top K frequent Elements try - 2

// -- essential_libraries_and_namespace
#include <iostream>
using namespace std;

// -- additional_libraries
#include <vector>
// #include <utilities>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
// -- additional_libraries --azure
#include "TimerClock.h"

// Classes

// Functions

void ShowHashMap(unordered_map<int, int> hashMap)
{
	cout << "\t\t\t"
		 << "______ Printing UnOrdered Hash-Map ______"
		 << "\n";
	cout << "\n";
	// cout << "\n";

	cout << "\t\t\t\tKEY"
		 << "\t\t"
		 << "VAL"
		 << "\n";
	cout << "\t\t\t\t---"
		 << "\t\t"
		 << "---"
		 << "\n";
	for (auto it : hashMap)
	{
		cout << "\t\t\t\t" << it.first << "\t\t" << it.second;
		// showNestedVector(it.second);
		cout << endl;
	}

	cout << "\n";
	// cout << "\n";
	cout << "\t\t\t"
		 << "______ UnOrdered Hash-Map Printed ______ "
		 << "\n";
}

// ShowHashMap With 2nd Element As vector

void ShowVectorHashMap(const map<int, vector<int>> &BucketHashMap)
{

	cout << "\n";
	// cout << "\n";
	cout << "\t\t\t"
		 << "______ Printing UnOrdered Vector-Hash-Map ______ "
		 << "\n";
	cout << "\t\t\t\tKEY"
		 << "\t\t"
		 << "VAL"
		 << "\n";
	cout << "\t\t\t\t---"
		 << "\t\t"
		 << "---"
		 << "\n";

	for (auto it : BucketHashMap)
	{
		cout <<"\t\t\t\t" << it.first << " \t\t ";
		// vector<int> temp = it.second;

		cout << "[ ";
		for (auto i : it.second)
		{
			cout << i << " ";
		}
		cout << "] ";
		cout << endl;
	}

	cout << "\n";
	// cout << "\n";
	cout << "\t\t\t"
		 << "______ UnOrdered Vector-Hash-Map Printed ______ "
		 << "\n";
}

void ShowVector(const vector<int> &nums)
{
	cout << "\t\t--- Printing Vector ---\n";
	cout << "\t\t";
	for (int it : nums)
	{
		cout << "\t" << it << " ";
	}

	cout << "\n\t\t--- Vector Printed ---\n";
}

void TopK_FrequentElement(const vector<int> &nums, int &k)
{

	unordered_map<int, int> HashMap;
	vector<int> max;

	vector<int> result;

	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		// int currentElement = nums[i];

		cout << "Selected Element : " << nums[i] << "\n";
		int current_count = count(nums.begin(), nums.end(), nums[i]);
		HashMap.insert(pair<int, int>(nums[i], current_count));
		// HashMap[nums[i]] = current_count;
		max.push_back(current_count);
	}

	ShowVector(nums);
	// ShowVector(max);
	sort(max.begin(), max.end());
	int max_size = max.size();
	int largestElement = max[max_size - 1];
	cout << "largestElement : " << largestElement << "\n";

	// Bucket Method

	map<int, vector<int>> BucketMap{};

	for (int i = 0; i < size; i++)
	{
		BucketMap[i] ;
	}

	ShowVectorHashMap(BucketMap);

	// Creating Buckets

	ShowHashMap(HashMap);

	// return result;
}

int main(int argc, char const *argv[])
{

	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// -- Main Code Function

	vector<int> nums = {4, 1, -1, 2, -1, 2, 3};
	// vector<int> nums = {1,1,1,2,2,3};
	// vector<int> nums = {-1, -1};
	// vector<int> nums = {1, 1, 1, 2, 2, 3};
	int k = 2;

	TopK_FrequentElement(nums, k);

	return 0;
}
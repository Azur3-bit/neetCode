// Two Sum - Browser Solution Practice - Quick Shot

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

void ShowVector(vector<int> nums)
{

	int size = nums.size();

	cout << "Printing Vector"
		 << "\n";

	for (int i = 0; i < size; i++)
	{
		cout << nums[i] << "\n";
	}
	cout << "Printing Vector Completed ..."
		 << "\n";
}

// Printing HashMap
void ShowHashMap(unordered_map<int, int> HashMap)
{

	cout << "Key"
		 << "\t"
		 << "Value"
		 << "\n";
	for (auto it : HashMap)
	{
		cout << it.first << "\t" << it.second << "\n";
	}
}

// Solution Funtion for 2 Sum
void SolutionTwoPass(vector<int> nums, int target)
{

	vector<int> result;

	unordered_map<int, int> Hashmap;

	int size = nums.size();

	for (int i = 0; i < size; i++)
	{
		// finding the number that has to be founded in the map

		Hashmap[nums[i]] = i;
	}

	for (int i = 0; i < size; i++)
	{

		int complement = target - nums[i];
		if (Hashmap.count(complement) && Hashmap[complement] != i)
		{
			// result.push_back(i);
			cout << i << "----";
			// result.push_back(Hashmap[complement]);
			cout << Hashmap[complement];
			// return result;
			break;
		}
	}
	// return result;
}

void SolutionOnePass(vector<int> nums, int target)
{

	int size = nums.size();

	unordered_map<int, int> HashMap;

	int iterationCount = 0;
	for (int i = 0; i < size; i++)
	{
		// finding the Complement
		iterationCount++;
		int complement = target - nums[i];
		HashMap[nums[i]] = i;
		if (HashMap.count(complement) && HashMap[complement] != i)
		{
			cout << "Value by the Function :: " << HashMap.count(complement) << endl;
			cout << i << "====" << HashMap[complement] << "\n";
			// break;
		}

		cout << "Printing HashMap" << endl;
		ShowHashMap(HashMap);
		cout << "\t\t\t-------------------------" << endl;

		cout << "\t\t\tIteration Count " << iterationCount << endl;
		cout << "\t\t\t-------------------------" << endl;
		cout << endl;
		cout << "Value by the Function - hashMap[complement] ::" << HashMap[complement] << endl;
		cout << "-------------------------" << endl;
		cout << "Value by the Function - i  :: " << i << endl;
		cout << "-------------------------" << endl;
		cout << "Value by the Function - count[complement] :: " << HashMap.count(complement) << endl;
		cout << "-------------------------" << endl;
	}
}

int main()
{
	// Main Code Function
	//  0  1  2  3  4
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << "\t\t:: Printing HashMap ::" << endl;
	ShowVector(nums);
	// ShowVector(nums);
	cout << "\t\t::Using OnePass ::" << endl;
	SolutionOnePass(nums, 6);
	cout << "\t\t::Using TwoPass ::" << endl;
	SolutionTwoPass(nums, 6);

	return 0;
}
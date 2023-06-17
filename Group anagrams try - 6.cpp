// Group anagrams try - 6

// Sorting String Vector Approach
// ? Algorithm START

// select 1 element
// find its value
// Loop Start

// now check for elements with the same value using find().
// if Found then push it in a vector result.
// and popout those elemets which have been found using erase().
// complete the loop to find all elements.
// Loop end

// select 2nd element and so on ...
// ? Algorithm END

// finding size of the map

// ShowUnorderedMap(UnOrderedMap);

// Problem Description
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

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

// Classes

// Functions

// --- Function ___ Show NestedVector

void showNestedVector(const vector<vector<string>> &temp)
{
	cout << "Printing Nested Vector "
		 << "\n";
	cout << "{ ";
	for (auto it : temp)
	{
		cout << "{ ";
		for (auto i : it)
		{
			cout << i << " ";
		}
		cout << "} ";
	}
	cout << "} ";
}

// --- Function ___ Show Vector
void ShowVector(vector<string> strs)
{
	for (auto it : strs)
	{
		cout << it << "\n";
	}
}

// --- Function ___ Show unOrderedMap
void ShowUnorderedMap(const unordered_map<string, string> &strs)
{

	cout << "\t\t\t"
		 << "______ Printing Unordered Hash-Map ______"
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
	for (auto it : strs)
	{
		cout << "\t\t\t\t" << it.first << "\t\t" << it.second << "\n";
	}

	cout << "\n";
	// cout << "\n";
	cout << "\t\t\t"
		 << "______ Unordered Hash-Map Printed ______ "
		 << "\n";
}

// --- Function ___ Solution Vector
void solution(vector<string> strs)
{
	unordered_map<string, string> UnOrderedMap;
	vector<string> copyStirng = strs;
	vector<vector<string>> result;
	// vector<vector<string>> result;
	int size = strs.size();
	for (int i = 0; i < size; i++)
	{
		// cout << "Sorting : - " << strs[i] << "\n";
		sort(copyStirng[i].begin(), copyStirng[i].end());
	}
	for (int i = 0; i < strs.size(); i++)
	{
		UnOrderedMap[strs[i]] = copyStirng[i];
	}

	ShowUnorderedMap(UnOrderedMap);

	for (auto it : UnOrderedMap)
	{
		vector<string> temp = {};
		int size = UnOrderedMap.size();
		for (auto i : UnOrderedMap)
		{
			if (i.second == it.second)
			{
				i.second = "Done";
				temp.push_back(i.first);
			}
		}
		result.push_back(temp);
	}

	showNestedVector(result);
}

int main()
{

	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// -- Main Code Function
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	// cout << "Working :: " << endl;
	solution(strs);
	// ShowVector(strs);

	return 0;
}
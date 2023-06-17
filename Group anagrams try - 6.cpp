// Group anagrams try - 6

// Sorting String Vector Approach

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

	// Sorting Entire String
	// sort(strs.begin(), strs.end());
	// ShowVector(strs);
	unordered_map<string, string> UnOrderedMap;
	vector<string> copyStirng = strs;
	vector<vector<string>> result;
	int size = strs.size();
	for (int i = 0; i < size; i++)
	{
		cout << "Sorting : - " << strs[i] << "\n";
		sort(copyStirng[i].begin(), copyStirng[i].end());

		// UnOrderedMap[strs[i]] =
	}

	for (int i = 0; i < strs.size(); i++)
	{
		UnOrderedMap[strs[i]] = copyStirng[i];
	}
	// cout << "---UnSorted---"
	// 	 << "\n";
	// cout << "\n";
	// ShowVector(strs);
	// cout << "\n";
	// cout << "---Sorted---"
	// 	 << "\n";
	// ShowVector(copyStirng);


	// ? Algorithm START 

	// select 1 element
	// find its value
	// Loop Start

	// now check for elements with the same value using find().
	// if Found then push it in a vector result.
	// and popout those elemets which have been found using erase().
	// complete the loop to find all elements.
	// Loop end

	// select 2nd element
	// ? Algorithm END 

	// finding size of the map
	int sizeMp = UnOrderedMap.size();
	cout << "Size : " << size;

	// ShowUnorderedMap(UnOrderedMap);

	unordered_map<string, string>::iterator it = UnOrderedMap.begin();
	while (sizeMp--)
	{
		vector<string> temp = {};
		string firstElemntValue = it->second;
		// Checking Elements With same value;
		unordered_map<string, string>::iterator itForKeyelement = UnOrderedMap.find(firstElemntValue);
		string valueByIt = itForKeyelement->second;
		string keyByIt = itForKeyelement->first;
		if (valueByIt == firstElemntValue)
		{
			temp.push_back(keyByIt);
			UnOrderedMap.erase(keyByIt);
		}
		result.push_back(temp);
		itForKeyelement++;
	}

	for (auto itKeyElement : UnOrderedMap)
	{
		vector<string> temp = {};
		string firstElementValue = it->second;
		string firstElementKey = it->first;
		unordered_map<string, string>::iterator itForKeyelement = UnOrderedMap.find(firstElementValue);
		string convertedFoundKey = itForKeyelement->first;
		if (convertedFoundKey == firstElementKey)
		{
			temp.push_back(firstElementValue);
			UnOrderedMap.erase(firstElementKey);
			itForKeyelement++;
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
	solution(strs);
	// ShowVector(strs);

	return 0;
}
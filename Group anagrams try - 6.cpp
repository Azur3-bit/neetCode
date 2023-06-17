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

	for (int i = 0; i < strs.size(); i++)
	{
		cout << "Sorting : - " << strs[i] << "\n";
		sort(copyStirng[i].begin(), copyStirng[i].end());

		// UnOrderedMap[strs[i]] =
	}

	for (int i = 0; i < strs.size(); i++)
	{
		UnOrderedMap[strs[i]] = copyStirng[i];
	}
	cout << "---UnSorted---"
		 << "\n";
	cout << "\n";
	ShowVector(strs);
	cout << "\n";
	cout << "---Sorted---"
		 << "\n";
	ShowVector(copyStirng);

	ShowUnorderedMap(UnOrderedMap);
}

int main(int argc, char const *argv[])
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
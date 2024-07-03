// Group anagrams - LeetCode - neetCode

// Solution Working but Not Very Efficent and cannot solve all test cases.

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

void ShowNestedVector(const vector<vector<string>> &vec)
{

	cout << "-- Printing Vector -- "
		 << "\n";

	cout << "[";
	for (auto i : vec)
	{
		// cout << "[";
		for (auto j : i)
		{
			cout << j << " ";
		}
		// cout << "]";
	}
	cout << "]";
	cout << "\n";
	cout << "-- Vector Printed -- "
		 << "\n";
}

void ShowHashMap(const unordered_map<string, int> &hm)
{

	cout << "-- Printing hashMap -- "
		 << "\n";

	cout << "Key"
		 << "\t\t"
		 << "Value"
		 << "\n";

	for (auto it : hm)
	{
		cout << it.first << "\t\t" << it.second << "\n";
	}
	cout << "-- HashMap Printed -- "
		 << "\n";
}
void ShowOrderedHashMap(const map<int, string> &hm)
{

	cout << "-- Printing Ordered hashMap -- "
		 << "\n";

	cout << "Key"
		 << "\t\t"
		 << "Value"
		 << "\n";

	for (auto it : hm)
	{
		cout << it.first << "\t\t" << it.second << "\n";
	}
	cout << "-- HashMap Ordered Printed -- "
		 << "\n";
}

void solution(const vector<string> &str)
{
	unordered_map<string, int> hm;
	map<int, string> orderedMap;
	int size = str.size();
	vector<vector<string>> result;
	// cout << "...inside Solution function... " << endl;
	for (int i = 0; i < size; i++)
	{
		string CurrentWord = str[i];
		int currentWordLength = 0;
		int lenghtOfCurrentWord = CurrentWord.size();
		for (int j = 0; j < lenghtOfCurrentWord; j++)
		{
			cout << "Current Word :- " << CurrentWord << "\n";
			int lenght = CurrentWord[j];
			cout << "Current Word letter :- " << CurrentWord[j] << "\n";
			cout << "Lenght : " << lenght << "\n";
			currentWordLength = lenght + currentWordLength;
		}
		hm[CurrentWord] = currentWordLength;
		orderedMap[currentWordLength] = CurrentWord;
	}
	ShowHashMap(hm);
	ShowOrderedHashMap(orderedMap);
	cout << ":: -- UnOrdered HashMap -- :: " << endl;
	cout << ":: -- Ordered HashMap -- :: " << endl;

	for (auto it : orderedMap)
	{
		vector<string> temp = {};
		for (auto i : hm)
		{
			// vector<string> temp = {};
			int currentkey = it.first;
			int CompartiveKey = i.second;
			// cout << "Current Key :- " << currentkey << " ___ ";
			// //  << "\n";
			// cout << "Compartitive Key  :- " << CompartiveKey
			// 	 << "\n";

			if (currentkey == CompartiveKey)
			{
				// cout << "Item PushedBack : - " << i.first << "\n";
				temp.push_back({i.first});
			}
			// temp2.push_back(temp);
			result.push_back(temp);
		}
	}
	// return result;
	ShowNestedVector(result);
}

int main(int argc, char const *argv[])
{

	// -- faster I/O operations
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// -- Main Code Function
	vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
	// solpush_backpush_backpush_backution(str);
	// vector<vector<string>> rahul;
	// rahul.push_back({"1", "2", "3"});
	// rahul.push_back({"4", "5", "6"});
	// ShowNestedVector(rahul);
	solution(str);
	return 0;
}
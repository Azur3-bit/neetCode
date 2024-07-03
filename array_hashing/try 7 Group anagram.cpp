// try 7 Group anagram

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

// Printing Unordered Map
void ShowBeautifulUnorderedMap(const unordered_map<string, vector<string>> &strs)
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
        cout << "\t\t\t\t" << it.first << "\t\t";
        // showNestedVector(it.second);
        vector<string> tempo = it.second;
        for (auto i : tempo)
        {
            // cout << "[ ";
            cout << i << " ";
            // cout << "] ";
        }
        cout << endl;
    }

    cout << "\n";
    // cout << "\n";
    cout << "\t\t\t"
         << "______ Unordered Hash-Map Printed ______ "
         << "\n";
}
void showNestedVector(const vector<vector<string>> &temp)
{
    cout << "\n";
    cout << "\n";
    cout << "Printing Nested Vector "
         << "\n";
    cout << "\n";
    cout << "\t\t{ ";
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

void Solution(const vector<string> &strs)
{

    unordered_map<string, vector<string>> mp{};
    vector<vector<string>> res;
    for (string s : strs)
    {
        string t = s;
        sort(t.begin(), t.end());
        mp[t].push_back(s);
    }
    ShowBeautifulUnorderedMap(mp);

    // getting the Final Answer

    for (auto &it : mp)
    {
        res.push_back(it.second);
    }

    showNestedVector(res);
}

int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Code Function

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution(strs);

    return 0;
}
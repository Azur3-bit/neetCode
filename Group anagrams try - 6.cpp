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

void ShowVector(vector<string> strs){
    for(auto it : strs){
        cout << it << " ";
    }
}

vector<string> solution(vector<string> &strs){
    sort(strs.begin(), strs.end());
    // ShowVector(strs);
    return strs;
}

int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Code Function

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    solution(strs);
    ShowVector(strs);

    return 0;
}
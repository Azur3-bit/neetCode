// Group anagrams
// LeetCode Problem
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

// Traversing Vector

void traverseVector(const vector<string> &Vec)
{
    cout << "\t\t-- Printing Vector -- "
         << "\n";
    for (auto it : Vec)
    {
        cout << it << "\n";
    }
    cout << "\t\t-- Vector Printed -- "
         << "\n";
}

void Solution(vector<string> inputString)
{

    cout << "Without Sorting "
         << "\n";
    traverseVector(inputString);
    int size = inputString.size();
    // vector<string> sortedVectorString = {};
    // sort(inputString.begin(), inputString.end());
    // cout << "After Sorting "
    //  << "\n";

    for (int i = 0; i < size; i++)
    {
        string CurrentElement = inputString[i];
        cout << "Sorting Element => " << CurrentElement << "\n";
        sort(CurrentElement.begin(), CurrentElement.end());
    }
    cout << "After Sorting " << endl;
    traverseVector(inputString);
}

int main()
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Code Function

    // ["eat","tea","tan","ate","nat","bat"]
    // traverseVector(stgs);
    vector<string> stgs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution(stgs);

    return 0;
}
// LeetCode Solution Section For Grouped anagram

#include <iostream>
using namespace std;

// additional_libraries
#include <vector>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <map>
#include <set>

// Classes

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> groups;
        for (const string &str : strs)
        {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            groups[sortedStr].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto &pair : groups)
        {
            result.push_back(pair.second);
        }

        return result;
    }
};

// Functions

int main(int argc, char const *argv[])
{
    // Main Code Function

    

    return 0;
}

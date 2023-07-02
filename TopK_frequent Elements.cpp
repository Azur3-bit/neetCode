// TopK_frequent Elements
// // INPUT :
// Input - 1: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Input - 2: nums = [1], k = 1
// Output: [1]

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
#include <queue>
// -- additional_libraries --azure
#include "TimerClock.h"

// Classes

// Functions

void _showMap(const unordered_map<int, int> &nums)
{
    cout << "Key"
         << "\t\t"
         << "Value\n";
    for (auto it : nums)
    {
        cout << it.first << "\t\t" << it.second << "\n";
    }
}

vector<int> TopKFreqElements(const vector<int> &nums, int k)
{
    vector<int> result{};
    unordered_map<int, int> mp{};

    // Calculating Number of Occurance of each element
    for (int it : nums)
    {
        int curr_count = count(nums.begin(), nums.end(), it);
        mp[it] = curr_count;
    }
    // Pushing it into a priority Queue - Min Heap

    _showMap(mp);

    

    return result;
}

int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Code Function

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    TopKFreqElements(nums, k);

    return 0;
}
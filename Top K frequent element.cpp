// Top K frequent element

// Given an integer array nums and an integer k, return the k most frequent elements.
// You may return the answer in any order.

// Example 1:-

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Example 2:-
// Input: nums = [1], k = 1
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

#include "TimerClock.h"

// Classes

// Functions

void ShowHashMap(map<int, int> hashMap)
{
    cout << "\t\t\t"
         << "______ Printing Ordered Hash-Map ______"
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
    for (auto it : hashMap)
    {
        cout << "\t\t\t\t" << it.first << "\t\t" << it.second;
        // showNestedVector(it.second);
        cout << endl;
    }

    cout << "\n";
    // cout << "\n";
    cout << "\t\t\t"
         << "______ Ordered Hash-Map Printed ______ "
         << "\n";
}

// Printing Vector
void ShowVector(const vector<int> &nums)
{
    cout << "\t\t--- Printing Vector ---\n";

    for (int it : nums)
    {
        cout << it << " ";
    }

    cout << "\t\t--- Vector Printed ---\n";
}

// Actual Solution Function
vector<int> topKFrequentElement(const vector<int> &nums, int k)
{

    cout << ":: inside Function ::"
         << "\n";

    map<int, int> hashMap{};
    vector<int> result = {};
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {

        int currentNumber = nums[i];

        // Counting NUmber of Occurance of that number
        hashMap[currentNumber] = count(nums.begin(), nums.end(), currentNumber);
    }

    ShowVector(nums);

    ShowHashMap(hashMap);
    map<int, int>::iterator it = hashMap.begin();
   
    while (k--)
    {
        result.push_back(it->first);
        it++;
    }
    return result;



// Problem Solution 
#if 0
{
    // ? Algorithm For Problem Solution
    values are not sorted 
     appr-1 : Sort by values - Personal Solution

     appr-2 : create a pair of list with key and val and then Sort them - neetCode

     appr-3 : MAX_heap - neetCode and leetCode Discuss Section 

     appr-3 : bucket Sort (learn) - neetCode
}

#endif

#if 0

    // ? Basic ALgorithm Process Analysis  (-- BAPA --)
    // number - 1
    int count_1 = count(nums.begin(),nums.end(),1);
    cout << "count_1 : " << count_1 << "\n";

    // number - 2
    int count_2 = count(nums.begin(),nums.end(),2);
    cout << "count_2 : " << count_2 << "\n";
    
    // number - 3
    int count_3 = count(nums.begin(),nums.end(),3);
    cout << "count_3 : " << count_3 << "\n";
#endif
}

int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Code Function

    vector<int> nums = {4,1,-1,2,-1,2,3};
    int k = 2;
    // topKFrequentElement(nums, k);

    vector<int> result;
    result = topKFrequentElement(nums, k);
    ShowVector(result);

    return 0;
}
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
    cout << "Key \t\t Value\n";
    for (auto it : nums)
    {
        cout << it.first << "\t\t" << it.second << "\n";
    }
}

void _showVectorPairQueue(priority_queue<pair<int, int>, vector<pair<int, int>>> &pmq)
{
    cout << "Pmq.first \t\t Pmq.second\n";
    // cout << "Size : " << pmq.size();
    while (!pmq.empty())
    {
        pair<int, int> curr_element = pmq.top();
        cout << curr_element.first << "\t\t" << curr_element.second << "\n";
        pmq.pop();
    }
}

void _showVector(const vector<int> &nums)
{
    cout << "result \n";
    for (int it : nums)
    {
        cout << it << " ";
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
    // _showMap(mp);

    // Pushing it into a priority Queue - Min Heap
    priority_queue<pair<int, int>, vector<pair<int, int>>> pqm{};
    for (auto it : mp)
    {
        // Swaping First and Second
        int first = it.first;
        int second = it.second;
        pair<int, int> swaped_FisrtSecond = pair<int, int>(second, first);
        pqm.push(swaped_FisrtSecond);
    }

    // _showVectorPairQueue(pqm);

    // Getting Top K elements into the Priortiy Queue
    while (k--)
    {
        pair<int, int> TopElement;
        TopElement = pqm.top();
        result.push_back(TopElement.second);
        pqm.pop();
    }

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

    vector<int> result = TopKFreqElements(nums, k);
    _showVector(result);

    return 0;
}
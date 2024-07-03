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
#include <unordered_set>
#include <queue>
// -- additional_libraries -- azur3
#include "TimerClock.h"

// Classes

// Functions

// Enters Inputs in a vector
void _enterFileVector(vector<int> &nums)
{
    int input;
    // vector<int> nums;
    while (std::cin >> input)
    {
        nums.push_back(input);
    }
}

// -- Prints Vector
void _showVector(vector<int> &nums)
{
    for (int it : nums)
    {
        cout << it << " ";
    }
}

void _showSet(set<int> &numSet)
{
    cout << "\n:Printing Set :\n";
    cout << "\n{ ";
    for (int it : numSet)
    {
        cout << it << " ";
    }
    cout << "} \n";
    cout << "\n--- Printed Set --- \n";
}

int consecutiveNumbers(vector<int> &nums)
{
    int finalCounter = 0;
    set<int> numSet{};
    for (int it : nums)
    {
        numSet.insert(it);
    }

    int counter = 0;
    for (int it : numSet)
    {
        int prevElement = it - 1;
        int nextElement = it + 1;

        if (numSet.find(prevElement) != numSet.end())
        {
            ++counter;
        }

        if((numSet.find(nextElement) != numSet.end())){
            ++counter;
        }
    }
    cout << "\nFinal Counter : " << finalCounter << endl;
    _showSet(numSet);
    return finalCounter;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Function code --

    // -= VectorCode Start
    vector<int> nums;
    _enterFileVector(nums);
    _showVector(nums);
    // -= VectorCode Ends

    //  --Actual Funtion Code
    consecutiveNumbers(nums);

    return 0;
}
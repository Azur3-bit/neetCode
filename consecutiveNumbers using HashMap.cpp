// consecutiveNumbers using HashMap
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
void _inputVector(vector<int> &nums)
{
    int input;
    while (cin >> input)
    {
        nums.push_back(input);
    }
    cout << endl;
}



void _showVector(vector<int> &nums)
{
    cout << ":: Printing Vector :: " << endl;
    cout << "{ ";
    for (int it : nums)
    {
        cout << it << " ";
    }
    cout << "}";
    cout << endl;
    cout << ":: Vector Printed :: ";
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
    // string name;
    // cin >> name;
    // cout << "Hello master ! " << name;

    // vector<int> nums = {1,2,3,4};
    vector<int> nums{};
    _inputVector(nums);
    _showVector(nums);

    return 0;
}
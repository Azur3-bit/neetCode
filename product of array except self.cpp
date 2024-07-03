// product of array except self

// Input: nums = [1,2,3,4]
// Output:       [24,12,8,6]

// Input: nums = [-1,1,0,-3,3]
// Output:       [0,0,9,0,0]

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
// -- additional_libraries -- azur3
#include "TimerClock.h"

// Classes

// Functions
void _showVector(vector<int> &nums)
{
    cout << "Printing Vector \n";
    for (int it : nums)
    {
        cout << it << " ";
    }
    cout << "\nVector Printed \n";
}

void prod_exceptSelf(vector<int> &nums, int size)
{

    vector<int> result(size,1);
    _showVector(nums);

    int PreIndex = 1;
    for (int i = 0; i < size;i++){
        result[i] = PreIndex;
        PreIndex = nums[i] * PreIndex;
    }
    _showVector(result);

    int PostIndex = 1;
    for(int j = size - 1; j >= 0;j--){
        // cout << "Index Rev Loop :: ";
        result[j] = result[j] * PostIndex ;
        PostIndex = nums[j] * PostIndex;
    }
    _showVector(result);
}

int main()
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "Inside Main Code \n";

    // -- Main Function code --
    vector<int> nums = {1, 2, 3, 4};

    // int size = nums.size();
    // vector<int> result =
    prod_exceptSelf(nums, nums.size());
    // _showVector(result);

    return 0;
}
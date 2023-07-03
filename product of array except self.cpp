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
    void _showVector(const vector<int> &nums){
        cout << "Printing Vector \n";
        for (int it : nums){
            cout << it << " ";
        }
        cout << "Vector Printed \n";
    }


    vector<int> prod_exceptSelf(vector<int> &nums){
        vector<int> result{};

        int preIndex = 1;
        for (int i = 0; i < nums.size();i++){
            result[i] = preIndex;
            preIndex = preIndex * nums[i];
        }
        _showVector(result);
    }

int main(int argc, char const *argv[])
{

    // -- faster I/O operations 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Function code --
    vector<int> nums = {1, 2, 3, 4};
    prod_exceptSelf(nums);

    return 0;
}
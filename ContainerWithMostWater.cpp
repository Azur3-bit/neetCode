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
    template <typename type_1>
    void _input(vector<type_1> &nums)
    {
        type_1 input;
        while (cin >> input)
        {
            nums.push_back(input);
        }
        cout << endl;
    }

    template <typename type_2>
    void _showVector(const vector<type_2> &nums)
    {
        cout << ":: Printing Vector :: " << endl;
        cout << "{ ";
        for (type_2 it : nums)
        {
            cout << it << " ";
        }
        cout << "}";
        cout << endl;
        cout << ":: Vector Printed :: " << endl;
    }

// BRUTEFORCE - HIT AND TRAIL
void containerWithMostWater(vector<int> &nums){


    



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
    vector<int> nums{};

    _input(nums);
    


    return 0;
}
// carFleet_new.cpp

// Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

// -- essential_libraries_and_namespace
#include <iostream>
using namespace std;

// -- additional_libraries
#include <vector>
#include <string>
#include <stack>
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

    int target = 12;

    vector<int> postion = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    // cout << "Working !" << endl;

    cout << "postion !" << endl;
    _showVector(postion);
    cout << "speed !" << endl;

    _showVector(speed);

    return 0;
}
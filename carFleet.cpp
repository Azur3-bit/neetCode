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

template <typename type_1>
void _input(vector<type_1> &nums)
{
    type_1 input;
    while (cin >> input)
    {
        nums.push_back(input);
        if (cin.peek() == '\n')
            break;
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
template <typename type_3>
void _showSet(const unordered_set<type_3> &nums)
{
    cout << ":: Printing Set :: " << endl;
    cout << "{ ";
    for (type_3 it : nums)
    {
        cout << it << " ";
    }
    cout << "}";
    cout << endl;
    cout << ":: Set Printed :: " << endl;
}

void carFleet(int target, vector<int> position, vector<int> speed)
{

    // rather than using a set use a stack or array

    // use this may this may help
    // All the car will take a time to reach the target and
    // time = velocity/(length to the finish)
    // car with the smaller time will reach the car with higher time create a fleet

    // take in count the slowest car for making a car fleet 


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

    vector<int> position{};
    vector<int> speed{};
    _input(position);
    cout << "Positions :: " << endl;
    _showVector(position);
    _input(speed);
    cout << "Speed :: " << endl;
    _showVector(speed);

    carFleet(target, position, speed);
    return 0;
}

// app - 1
// find the total time required by a car to reach finish line
// find some sort of stack usage
// --

// -- approch - 2
// --> starting
// add all the element in the stack by thier position

// --> middle
// and at each iteration increase the value of the car by its speed
// if the speed is equal to any car above its position mark that car
// as bottle neck car
// --> end
// if at finish line i.e target then label it as fleet and increase
// thier value by a constant number.
// --
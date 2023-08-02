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

void _showStack(stack<int> stk)
{

    cout << ":: printing stack :: " << endl;
    while (!stk.empty())
    {
        cout << stk.top() << endl;
        stk.pop();
    }
    cout << ":: stack Printed :: " << endl;
}

int carFleet(const vector<int> &speed, const vector<int> &postion, int target)
{

    // calculating time to reach
    int size = speed.size();
    vector<int> timeToTarget(size, 0);

    for (int i = 0; i < size; i++)
    {
        timeToTarget[i] = (target - postion[i]) / speed[i];
    }

    _showVector(timeToTarget);
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

    cout << "target : " << target << endl;
    cout << "postion !" << endl;
    _showVector(postion);
    cout << "speed !" << endl;

    _showVector(speed);

    // testing stack
    stack<int> temp;
    temp.push(1);
    temp.push(2);
    temp.push(3);
    temp.push(4);
    temp.push(5);

    _showStack(temp);

    carFleet(speed, postion, target);

    return 0;
}
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

// template<typename T1>
void _showVectorPair(vector<pair<int, int>> &temp)
{

    cout << "printing vector pair " << endl;

    for (auto it : temp)
    {
        cout << it.first << " " << it.second << endl;
    }
    cout << "vector pair printed " << endl;
}

int carFleet(const vector<int> &speed, const vector<int> &postion, int target)
{

    // stack intialization
    stack<int> finalStack{};

    // calculating time to reach
    int size = speed.size();
    vector<int> timeToTarget(size, 0);
    vector<pair<int, int>> postion_time{};

    for (int i = 0; i < size; i++)
    {
        postion_time.push_back(make_pair(postion[i], ((target - postion[i]) / speed[i])));
    }

    _showVectorPair(postion_time);

    sort(postion_time.begin(), postion_time.end());
    _showVectorPair(postion_time);

    finalStack.push(postion_time[size - 1].second);

    cout << " -- Stack -- " << endl;
    _showStack(finalStack);

    cout << " -- Loop -- " << endl;
    for (int i = size - 1; i >= 0; i--)
    {
        cout << postion_time[i].first << " " << postion_time[i].second << endl;

        if (finalStack.top() < postion_time[i].second)
        {
            cout << "pushing : " << postion_time[i].second << endl;
            finalStack.push(postion_time[i].second);
        }
    }

    cout << "Elements : " << finalStack.size() << endl;
}

int LeetcodeSubmission(const vector<int> &speed, const vector<int> &postion, int target)
{

    // calculating time to reach
    int size = speed.size();

    vector<pair<int, double>> postion_time;

    for (int i = 0; i < size; i++)
    {
        postion_time.push_back(make_pair(postion[i], (double)(target - postion[i]) / speed[i]));
    }
    sort(postion_time.begin(), postion_time.end());
    int currentTime = 0;
    double fleetCounter = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        if (postion_time[i].second > currentTime)
        {
            currentTime = postion_time[i].second;
            fleetCounter++;
        }
    }
    return fleetCounter;
}

int a_carFleet(const vector<int> &speed, const vector<int> &position, int target)
{
    int size = speed.size();
    vector<pair<int, double>> position_time;

    for (int i = 0; i < size; i++)
    {
        position_time.push_back(make_pair(position[i], (double)(target - position[i]) / speed[i]));
    }

    sort(position_time.begin(), position_time.end());

    int fleetCount = 0;
    double currentTime = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        if (position_time[i].second > currentTime)
        {
            currentTime = position_time[i].second;
            fleetCount++;
        }
    }

    return fleetCount;
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

    int target = 10;

    vector<int> postion = {6, 8};
    vector<int> speed = {3, 2};

    // cout << "Working !" << endl;

    cout << "target : " << target << endl;
    cout << "postion !" << endl;
    _showVector(postion);
    cout << "speed !" << endl;

    _showVector(speed);

    // // testing stack
    // stack<int> temp;
    // temp.push(1);
    // temp.push(2);
    // temp.push(3);
    // temp.push(4);
    // temp.push(5);

    // _showStack(temp);

    // carFleet(speed, postion, target);
    cout << LeetcodeSubmission(speed, postion, target) << endl;

    return 0;
}
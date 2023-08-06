// finding minimum element till now

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

void _showStack(stack<int> &nums)
{

    cout << ":: printing Stack ::\n";

    while (!nums.empty())
    {
        cout << nums.top() << endl;
        nums.pop();
    }
    cout << ":: Stack printed ::\n";
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

vector<int> minElement(vector<int> &nums)
{

    stack<int> stk{};

    vector<int> ans{};
    // stk.push(-1);

    // int index = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        while (!stk.empty() && nums[i] <= stk.top())
        {
            stk.pop();
        }

        if (stk.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            cout << "breakPoint - 1" << endl;
            ans.push_back(stk.top());
        }
        stk.push(nums[i]);
    }

    return ans;
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

    stack<int> stk{};

    stk.push(2);
    stk.push(1);
    stk.push(5);
    stk.push(6);
    stk.push(2);
    stk.push(3);

    _showStack(stk);

    vector<int> nums = {2, 1, 5, 6, 2, 3};

    vector<int> ans = minElement(nums);

    _showVector(ans);
    return 0;
}
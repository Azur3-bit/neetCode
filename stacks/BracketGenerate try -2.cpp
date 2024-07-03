// BracketGenerate

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
        cout << it << " ,";
    }
    cout << "}";
    cout << endl;
    cout << ":: Vector Printed :: " << endl;
}

// BackTracing
void RecursiveSolution(vector<string> &result, int n, int open, int close, string ans)
{

    if ((open == n) && (close == n))
    {
        result.push_back(ans);
        return;
    }

    if (open < n)
    {
        ans.push_back('(');
        RecursiveSolution(result, n, open + 1, close, ans);
        ans.pop_back();
    }

    if (close < open)
    {
        ans.push_back(')');
        RecursiveSolution(result, n, open, close + 1, ans);
        ans.pop_back();
    }
}

vector<string> GenerateParenthesis(int n)
{

    vector<string> result{};
    RecursiveSolution(result, n, 0, 0, "");

    return result;
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

    // cout << "Entered Value : " << n;
    // int test;
    // cin >> test;

    // while (test--)
    // {
    int n;
    cin >> n;
    vector<string> res = GenerateParenthesis(n);
    _showVector(res);
    // }

    return 0;
}
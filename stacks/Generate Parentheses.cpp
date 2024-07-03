// Generate Parentheses

// Intution - BackTracking

// Define choice
// Define Constraints - have to be very precise
// goal - exit condition

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

// neetcode -- void generate(int n, int open, int close, string str, vector<string>& result) {

// NeetCode Solution

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

void generateParenthesis(vector<string> &result, int n, string strResult, int currOpen, int currClose)
{
    if (currOpen == n && currClose == n)
    {
        // cout << "Answer : " << strResult << endl;
        result.push_back(strResult);
        return;
    }
    if (currOpen < n)
    {
        // strResult + "(";
        generateParenthesis(result, n, strResult + '(', currOpen + 1, currClose);
        // strResult.pop_back();
    }
    else if (currClose < currOpen)
    {
        // strResult + ")";
        generateParenthesis(result, n, strResult + ')', currOpen, currClose + 1);
        // strResult.pop_back();
    }
}
vector<string> GenerateAnswer(int n)
{
    vector<string> result;
    generateParenthesis(result, n, "", 0, 0);
    _showVector(result);
    return result;
}

/* // ? algorithm
first element has to be an open bracket
Base case -= Exit condition -
if (maxOpen == maxClose == n)
    pushback in the vector<string>
    return
constraints -
putting close bracket
putting open bracket
if(currOpen >= currClose)
    {
    can put close bracket
    increment close+1
    }
if(currOpen <= MaxOpen){
    can put open Bracket
    increment open+1
}
*/
// ? Algorithm Ends

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

    int n = 3;
    // cin >> n;

    int currOpen = 0;
    int currClose = 0;

    // Solution obj;
    vector<string> finalRes{};
    string result = "";
    vector<string> vecResult{};

    // NEETCODE_generateParenthesis(n);

    finalRes = GenerateAnswer(n);
    // obj.generateParenthesis(n);

    return 0;
}
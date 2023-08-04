// Largest Rectangle in Histogram

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

void largestRectangleArea()
{

    /* // ? Algorithm -- complex and requires more memory -- must 

        traverse for(i,n)
        if(current > top && stack.size() == 1)
            push current
        else
            empty stack
            push element

        width = size
        final answer = min(top1 , top2) // stack elments only two       elements
        final answer  = final answer * width
    */

   

}

void largestRectangleAreatry_1(vector<int> &heights)
{

    /*
     *algo - 2 -- simple and optimized -- excuted -- heap overflow
        find max of the array
        check if right is bigger or left is bigger of the max element
        return the greater area

    */
    cout << "working " << endl;
    _showVector(heights);
    int left = 0, right = heights[1], forMax = heights[0];
    for (int i = 0; i < heights.size() - 1; i++)
    {
        if (heights[i] > heights[i - 1])
        {
            forMax = heights[i];
            right = heights[i + 1];
            left = heights[i - 1];
        }
    }
    cout << "for max element : " << forMax << endl;
    cout << "for max element - right: " << right << endl;
    cout << "for max element - left : " << left << endl;

    int count = max(right, left);

    int answer = min(count, forMax);

    cout << "count : " << count << endl;
    cout << "answer : " << answer << endl;
    count = answer * 2;
    cout << "final Answer : " << answer * 2 << endl;
    // return count * 2;
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

    vector<int> nums;
    _input(nums);

    _showVector(nums);
    largestRectangleAreatry_1(nums);

    return 0;
}
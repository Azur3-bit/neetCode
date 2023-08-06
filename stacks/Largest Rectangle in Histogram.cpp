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

    std::cout << endl;
}

void _showStack(stack<pair<int, int>> &nums)
{

    cout << ":: printing Stack ::\n";

    cout << "first\tsecond\n";
    while (!nums.empty())
    {
        cout << nums.top().first << "\t\t" << nums.top().second << endl;
        nums.pop();
    }
    cout << ":: Stack printed ::\n";
}

template <typename type_2>
void _showVector(const vector<type_2> &nums)
{

    std::cout << ":: Printing Vector :: " << endl;

    std::cout << "{ ";
    for (type_2 it : nums)
    {

        std::cout << it << " ";
    }
    std::cout << "}";

    std::cout << endl;

    std::cout << ":: Vector Printed :: " << endl;
}

/* // ? Algorithm -- complex and requires more memory -- must

    traverse for(i,n)
    if(current > top && stack.size() == 1)
        push current
    else
        empty stack
        push element

    width = size
    final answer = min(top1 , top2) // stack elments only two elements
    final answer  = final answer * width
*/

void largestRectangleArea(vector<int> &nums)
{

    stack<pair<int, int>> prevStk{};
    stack<pair<int, int>> nxtStk{};
    vector<int> prevSmaller{};
    vector<int> nxtSmaller(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        while (!prevStk.empty() && nums[i] <= prevStk.top().first)
            prevStk.pop();
        if (prevStk.empty())
            prevSmaller.push_back(-1);
        else
        {
            prevSmaller.push_back(prevStk.top().second);
            prevStk.push(make_pair(nums[i], i));
        }
        prevStk.push(make_pair(nums[i], i));
    }
    _showVector(prevSmaller);

    // --  Next smaller code

    cout << "size : " << nums.size() << endl;
    _showStack(prevStk);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int currEle = nums[i];
        cout << "Current ELement : " << currEle << endl;
        while (!nxtStk.empty() && currEle <= nxtStk.top().first)
            nxtStk.pop();
        if (nxtStk.empty())
            nxtSmaller[i] = nums.size();
        else
        {
            // nxtSmaller.push_back(i);
            nxtSmaller[i] = nxtStk.top().second;
            nxtStk.push(make_pair(nums[i], i));
        }
        nxtStk.push(make_pair(nums[i], i));
    }

    cout << "Printing nxt smaller vector : " << endl;
    _showVector(nxtSmaller);

    // vector<int> prevSmaller{};
    // vector<int> nxtSmaller(nums.size());

    int maxArea = 0;
    for (int i = 0; i < prevSmaller.size(); i++)
    {
        int t_MaxArea = (((nxtSmaller[i] - prevSmaller[i]) - 1) * nums[i]);
        maxArea = max(t_MaxArea, maxArea);
    }

    cout << "final Answer : " << maxArea << endl;
}

void largestRectangleAreatry_1(vector<int> &heights)
{

    /*
     *algo - 2 -- simple and optimized -- excuted -- heap overflow
        find max of the array
        check if right is bigger or left is bigger of the max element
        return the greater area

    */

    std::cout << "working " << endl;
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

    std::cout << "for max element : " << forMax << endl;

    std::cout << "for max element - right: " << right << endl;

    std::cout << "for max element - left : " << left << endl;

    int count = max(right, left);

    int answer = min(count, forMax);

    std::cout << "count : " << count << endl;

    std::cout << "answer : " << answer << endl;
    count = answer * 2;

    std::cout << "final Answer : " << answer * 2 << endl;
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
    // largestRectangleAreatry_1(nums);

    std::cout << "try - 2" << endl;
    largestRectangleArea(nums);

    return 0;
}
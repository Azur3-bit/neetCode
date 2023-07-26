// Problem desc

// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6

// Explanation: The above elevation map (black section) is
// represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case,
// 6 units of rain water (blue section) are being trapped.

// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

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
void _input(vector<type_1> &height)
{
    type_1 input;
    while (cin >> input)
    {
        height.push_back(input);
    }
    cout << endl;
}

template <typename type_2>
void _showVector(const vector<type_2> &height)
{
    cout << ":: Printing Vector :: " << endl;
    cout << "{ ";
    for (type_2 it : height)
    {
        cout << it << " ";
    }
    cout << "}";
    cout << endl;
    cout << ":: Vector Printed :: " << endl;
}

void TrappingRainWater(vector<int> &height)
{

    cout << ":: Inside TrappingRainWater function :: " << endl;
    _showVector(height);

    // Declarations

    // ? temp - ALGO
    // iterting i to n
    // finding both right and left maximum pillar
    // finding the minimum of both left and right
    // if (water[i] > 0) { input it into the water vector}
    // finally find the sum of the whole water Vector
    // return Sum

    cout << "-- -- --- Tester -- -- --- " << endl;
    int sum = 0;

    for (int i = 1; i < height.size() - 1; i++)
    {
        int currWaterQuan = 0;
        int left_max = 0;
        int right_max = 0;
        // finding both the left and right max using pointer
        int left = i - 1;
        int right = i + 1;

        while (left >= 0)
        {
            left_max = max(height[left], left_max);
            left--;
        }
        // printing Left Max Element of height[i]

        while (right <= height.size() - 1)
        {

            right_max = max(height[right], right_max);
            right++;
        }
        // cout << left_max << " -> " << height[i] << " <- " << right_max << endl;

        // finding Water Quantity

        currWaterQuan = min(left_max, right_max) - height[i];
        // cout << "Current Water Qantitiy  _*_ : " << currWaterQuan << endl;
        currWaterQuan = max(currWaterQuan, 0);
        sum += currWaterQuan;
    }

    // printing Total Water Qantity
    cout << "Total Water Quantity : " << sum << endl;
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
    vector<int> height{};

    _input(height);
    TrappingRainWater(height);

    return 0;
}
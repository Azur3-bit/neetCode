// 3Sum Two pointers

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
void _input(vector<type_1> &nums)
{
    type_1 input;
    while (cin >> input)
    {
        nums.push_back(input);
    }
    std::cout << endl;
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
    std::cout << ":: Vector Printed :: ";
}

void _showNestedVector(vector<vector<int>> &nums)
{
    std::cout << ":: Printing Nested Vector :: " << endl;
    std::cout << "{ ";
    for (auto it : nums)
    {
        std::cout << "{ ";
        for (int ij : it)
        {
            std::cout << ij << " ";
        }
        std::cout << "} ";
    }
    std::cout << "} ";
    std::cout << ":: Printed Nested Vector :: " << endl;
}

void _3Sum(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++)
    {
        vector<int> ansVector{};
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k)
        {
            if (nums[i] + nums[j] + nums[k] == 0)
            {
                ansVector.push_back(i);
                ansVector.push_back(k);
                ansVector.push_back(j);
                result.push_back(ansVector);
            }

            else if (nums[i] + nums[j] + nums[k] > 0)
            {
                k--;
            }
            else if (nums[i] + nums[j] + nums[k] < 0){
                j++;
            }
        }
    }

    _showNestedVector(result);
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

    // -- Main Function code --'
    vector<int> nums{};
    _input(nums);
    _showVector(nums);

    _3Sum(nums);
    return 0;
}
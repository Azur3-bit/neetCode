// three Sum Try - 2
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
    cout << endl;
}

template <typename type_2>
void _showVector(vector<type_2> &nums)
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

void _showNestedVector(vector<vector<int>> &vec)
{
    cout << "{ ";
    for (vector<int> it : vec)
    {
        cout << "{ ";
        for (int iter : it)
        {
            cout << iter << " ";
        }
        cout << "}";
    }
    cout << "}";
}

vector<vector<int>> threeSumSelfTry(vector<int> &nums)
{

    vector<vector<int>> result{};

    _showVector(nums);
    // Sorting vector
    sort(nums.begin(), nums.end());
    cout << "\n\t:: Sorting Vector :: " << endl;
    cout << ":: -- -- -- -- -- -- -- :: " << endl;
    _showVector(nums);

    cout << "i\t\tj\t\tk\t\tsum" << endl;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            int k = nums.size() - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                cout << nums[i] << "\t\t" << nums[j] << "\t\t " << nums[k] << "\t\t" << sum << endl;

                if (sum == 0)
                {
#if 0
                    cout << " -- ---- -- - - - - - -\n";
                    cout << "Result _ * _" << nums[i] << "\t\t" << nums[j] << "\t\t " << nums[k] << endl;
                    cout << " -- ---- -- - - - - - -\n";
#endif
                    result.push_back({nums[i], nums[j], nums[k]});

                    while (j < k && nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1])
                    {
                        k--;
                    }

                    j++;
                    k--;
                }

                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
    }

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

    vector<int> nums;
    _input(nums);
    vector<vector<int>> result = threeSumSelfTry(nums);

    cout << "-- -- -- -- -- -- " << endl;
    cout << "-- Final Output -- " << endl;
    cout << "-- -- -- -- -- -- " << endl;

    _showNestedVector(result);

    return 0;
}
// Matrix Row_Col formula
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
#include <queue>
// -- additional_libraries -- azur3
#include "TimerClock.h"

// Classes

// Functions

// -- traverse nested vector
void _traverseNestedVector(vector<vector<int>> &traVec)
{
    cout << "\n ::Printing Nested Vector :: \n ";
    for (vector<int> it : traVec)
    {
        cout << "{ ";
        for (int i : it)
        {
            cout << i << " ";
        }
        cout << "}";
        cout << endl;
    }
}

// -- Matrix Formula
void _matrixRowColGenerator(vector<vector<int>> &vec)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int k = (((i / 3) * 3) + (j / 3)) ;
            cout << k << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Function code --

    // cout << "Working";

vector<vector<int>> usr_input = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {10, 20, 30, 40, 50, 60, 70, 80, 90},
    {11, 12, 13, 14, 15, 16, 17, 18, 19},

    {101, 201, 301, 401, 501, 601, 701, 801, 901},
    {102, 202, 302, 402, 502, 602, 702, 802, 902},
    {103, 203, 303, 403, 503, 603, 703, 803, 903},

    {100, 200, 300, 400, 500, 600, 700, 800, 900},
    {110, 210, 310, 41, 510, 610, 710, 810, 910},
    {1001, 2001, 3001, 4001, 5001, 6001, 7001, 8001, 9001},
};

    _traverseNestedVector(usr_input);
    _matrixRowColGenerator(usr_input);
    return 0;
}
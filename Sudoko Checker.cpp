// Sudoko Checker
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
// -- additional_libraries -- azur3-bit
#include "TimerClock.h"

// Classes

// Functions
// -- Function to traverse nested Vector
void _traverseNestedVector(vector<vector<int>> &temp)
{
    cout << "\n:: Printing Nested Vector :: \n";
    cout << "{ ";
    cout << endl;
    for (vector<int> tempItr : temp)
    {
        cout << "{ ";
        for (int it : tempItr)
        {
            cout << it << " ";
        }
        cout << "} ";
        cout << endl;
    }
    cout << "} \n";
}

// -- Traversing Vector
void _traverseVector(vector<int> &singVec)
{
    cout << "Printing a Non - Nested Vector\n";
    cout << "{ ";
    for (int it : singVec)
    {
        cout << it << " ";
    }
    cout << "} ";
}

// -- Traverse Set
void _traverseSet(set<int> &usr_set)
{
    cout << "\n:: Printing Set :: \n";
    for (int it : usr_set)
    {
        cout << it << " ";
    }
    cout << "\n:: Set Printed :: \n";
}

// -- Checking Row
bool _checkingRow(vector<vector<int>> usr_input)
{
    cout << "\nChecking Row\n";
    for (int i = 0; i < 9; i++)
    {
        set<int> rowSet{};
        int counter = 0;
        vector<int> curr_vector = usr_input[i];
        for (int j = 0; j < 9; j++)
        {
            if (curr_vector[j] >= 0 && curr_vector[j] < 10)
            {
                rowSet.insert(curr_vector[j]);
                counter++;
            }
        }
        if (counter != rowSet.size())
            return false;
    }
}

// -- Column Checker
bool _checkingCol(vector<vector<int>> &usr_input)
{
    cout << "\nChecking Column \n";

    // cout << "\n printing Matrix Column-Wise \n";
    set<int> temp_set;
    for (int i = 0; i < 9; i++)
    {
        temp_set = {};
        int counter = 0;
        for (int j = 0; j < 9; j++)
        {
            int curr_element = usr_input[j][i];
            if (curr_element >= 0 && curr_element < 10)
            {
                temp_set.insert(usr_input[j][i]);
                counter++;
            }
        }

        if (counter != temp_set.size())
            return false;
    }
}

void _matrixRowColGenerator(vector<vector<int>> &vec)
{
    vector<vector<int>> divEleCollection = {
        {}, // --> 1
        {}, // --> 2
        {}, // --> 3
        {}, // --> 4
        {}, // --> 5
        {}, // --> 6
        {}, // --> 7
        {}, // --> 8
        {}, // --> 9
    };

    int k = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            k = (((i / 3) * 3) + (j / 3));
            cout << " Pushing : " << vec[i][j] << " in : " << k << "\n";
            divEleCollection[k].push_back(vec[i][j]);
        }
        cout << "\n\t-- -- --- -- -- -- ";

        cout << "\n\t-- Printing Kth Part of Vector -- ";
        _traverseVector(divEleCollection[k]);

        cout << endl;
    }
}

// * Done -- Verified after using this function
void TestFunction()
{
    vector<vector<int>> divEleCollection = {{}, {}, {}};
    divEleCollection[0].push_back(0);
    divEleCollection[1].push_back(1);
    divEleCollection[2].push_back(2);

    // Traversing divEleCollection
    _traverseNestedVector(divEleCollection);
}

int main()
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Function code --

    vector<vector<int>> usr_input = {
        // <-- ROW - 1 -->
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {10, 20, 30, 40, 50, 60, 70, 80, 90},
        {11, 12, 13, 14, 15, 16, 17, 18, 19},
        // <-- ROW - 2 -->
        {101, 201, 301, 401, 501, 601, 701, 801, 901},
        {102, 202, 302, 402, 502, 602, 702, 802, 902},
        {103, 203, 303, 403, 503, 603, 703, 803, 903},
        // <-- ROW - 3 -->
        {100, 200, 300, 400, 500, 600, 700, 800, 900},
        {110, 210, 310, 41, 510, 610, 710, 810, 910},
        {1001, 2001, 3001, 4001, 5001, 6001, 7001, 8001, 9001},
    };

    // _traverseNestedVector(usr_input);
    // _checkingRow(usr_input);
    // _checkingCol(usr_input);
    _matrixRowColGenerator(usr_input);

    // TestFunction();
    return 0;
}
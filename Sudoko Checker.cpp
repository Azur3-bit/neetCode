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
    for (vector<int> tempItr : temp)
    {
        cout << "{ ";
        for (int it : tempItr)
        {
            cout << it << " ";
        }
        cout << "} ";
    }
    cout << "} ";
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

// -- Checking Row
void _checkingRow(vector<vector<int>> usr_input)
{
    cout << "\nChecking Row\n";
    for (int i = 0; i < 3; i++)
    {
        set<int> rowSet{};
        int counter = 0;
        vector<int> curr_vector = usr_input[i];
        for (int j = 0; j < 3; j++)
        {
            if (curr_vector[j] >= 0 && curr_vector[j] < 10)
            {
                rowSet.insert(curr_vector[j]);
                counter++;
            }
        }

        // -- Debug Code
        // cout << "\n----------\n";
        // cout << "set Size : " << rowSet.size() << endl;
        // cout << "Counter : " << counter << endl;
        // cout << "\n----------\n";
        // -- Debug Code

        if (counter != rowSet.size())
        {
            cout << ":: Size is not Equal to counter :: \n";
        }
        else
        {

            cout << "\nEverything is Good :: ";
            _traverseVector(curr_vector);
        }
    }
}

// -- Column Checker
void _checkingCol(vector<vector<int>> &usr_input)
{
    cout << "\nChecking Column \n";
    vector<int> tmep;

    cout << "\n printing Matrix Column-Wise \n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << usr_input[j][i] << " ";
            // tmep.push_back(usr_input[j][i]);
        }
        cout << endl;
    }
    // _traverseVector(tmep);
}

int main()
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Function code --

    vector<vector<int>> usr_input = {{1, 2, 1}, {4, 5, 6}, {7, 8, 9}};
    // _traverseNestedVector(usr_input);
    // _checkingRow(usr_input);
    _checkingCol(usr_input);
    return 0;
}
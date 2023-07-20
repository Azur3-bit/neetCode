// Sudoko Checker
// -- Input
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// -- Output
// True(bool)
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

// -- Traversing a Vector of Unordered Set
void _traverseVectorSet(vector<unordered_set<long int>> &usr_dataSet)
{
    // Printing a vector of Sets
    int ctr = 0;
    for (unordered_set<long int> vec : usr_dataSet)
    {
        cout << "Size of " << ctr << " : " << vec.size() << endl;
        ctr++;
        cout << "{ ";
        for (int it : vec)
        {
            cout << it << " ";
        }
        cout << "}";
        cout << "\n--- --- --- --- ";
        cout << endl;
    }
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

/*
Todo -- Problem - Counter is not reliable for cross
todo                checking either Create multiple sets of find other solutions
*/
bool _matrixRowColGenerator(vector<vector<int>> &vec)
{
    vector<set<int>> divEleCollection(9);

    // int k = 0;
    // bool flagBit = true;
    for (int i = 0; i < 9; i++)
    {
        int ctr = 0;
        for (int j = 0; j < 9; j++)
        {
            // ctr = 0;
            int k = (((i / 3) * 3) + (j / 3));

            if (vec[i][j] >= 0 && vec[i][j] < 10)
            {
                cout << " Pushing : " << vec[i][j] << " in : " << k << "\n";
                ctr++;
                divEleCollection[k].insert(vec[i][j]);
            }
            cout << "Counter : " << ctr << endl;
            cout << "divEleCollection[k].size() : " << divEleCollection[k].size() << "\n";
            if (divEleCollection[k].size() != ctr)
            {
                // flagBit = false;
                cout << "\n|| Error : divEleCollection[k].size() != counter ||  in " << k << endl;
                return false;
            }
        }
    }
}

// -- repeated Funtion to find Div using Row and Col
void _matrixDicGenerator(vector<vector<long int>> &usr_input)
{
    // -- Create a data structure to store their values properly
    // -- options -- 1. set 2. maps (finalized unordered Set)

    // -- Problem -- Keep track of both number of members and the actual set of values

    vector<unordered_set<long int>> MapingSet(9);

    // Checking Code till now
    cout << "\n-- Code Checker ---" << endl;
    _traverseVectorSet(MapingSet);
    cout << "-- Code Checker ---\n"
         << endl;

    // printing divs after Calculation
    // * divs Printed Sucessfully
    int counterPrincipal = 0;
    int counter = 0;
    int k;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (usr_input[i][j] >= 0 && usr_input[i][j] < 10000)
            {
                counter++;
                // cout << usr_input[i][j] << " ";
                k = (i / 3) * 3 + j / 3;
                MapingSet[k].insert(usr_input[i][j]);
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {

        counterPrincipal++;
        if (counter == MapingSet[i].size())
        {
            cout << "Sucessfull in " << k << " Attempt : " << counterPrincipal << endl;
        }
        else
        {
            cout << "Caution ! un-Sucessfull in " << k << " Attempt : " << counterPrincipal << endl;
        }
        cout << endl;
    }

    // Printing Every Divisions
    // _traverseVectorSet(MapingSet);
}

// * Done -- Verified after using this function
void TestFunction()
{
    // vector<vector<int>> divEleCollection = {{}, {}, {}};
    vector<vector<int>> divEleCollection(9, vector<int>(9, -1));

    // Traversing divEleCollection
    _traverseNestedVector(divEleCollection);
}

int main()
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Function code --

    vector<vector<long int>> usr_input = {
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
    // _matrixRowColGenerator(usr_input);
    _matrixDicGenerator(usr_input);
    // TestFunction();

#if 0
    if ((_matrixRowColGenerator(usr_input) && _checkingCol(usr_input) && _checkingRow(usr_input)))
    {
        cout << "\n:: Valid Sudoku :: \n";
    }
    else
    {
        cout << "\n:: In - Valid Sudoku :: \n";
    }
#endif

    return 0;
}
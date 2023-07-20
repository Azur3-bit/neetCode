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

void _showBoard(vector<vector<int>> &board)
{
    cout << ": Printing borad :\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // -- Main Function code --

    vector<vector<int>> board(3, vector<int>(3));

    for (int i = 0; i < 3; i++)
    {
        int current_input;
        for (int j = 0; j < 3; j++)
        {
            // cout << "Enter item at position : " << i << "," << j << ": ";
            cin >> current_input;
            board[i][j] = current_input;
        }
    }
    _showBoard(board);

    return 0;
}

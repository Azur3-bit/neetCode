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

#define row 9
#define col 9

// Classes

// Functions

void _showBoard(vector<vector<char>> &board)
{
    cout << ": Printing borad :\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void _showSet(unordered_set<char> &usr_set)
{
    cout << ":: Printing Set :: \n";
    for (char it : usr_set)
    {
        cout << it << " ";
    }
    // cout << endl;
}

void _showVector(const vector<int> &vec)
{
    cout << "Printing Vector \n";
    for (int i : vec)
    {
        cout << i << " ";
    }
}

void _showVectorSet(vector<unordered_set<char>> &vecSet)
{
    cout << "Printing Vector Set \n";
    cout << "{ ";
    for (unordered_set<char> it : vecSet)
    {
        cout << "{ ";
        for (char ij : it)
        {
            cout << ij << " ";
        }
        cout << "} \n";
    }
    cout << " }\n";
}

// -- Actual Function
bool isValidSuduko(const vector<vector<char>> &board)
{
    // -- Function Global
    vector<unordered_set<char>> divBoard(9);
    vector<int> k_divs(9);

    for (int i = 0; i < 9; i++)
    {
        unordered_set<char> rowSet{};
        unordered_set<char> colSet{};
        int rowCounter = 0;
        int colCounter = 0;
        for (int j = 0; j < 9; j++)
        {
            // int rowElement =board[i][j];
            // int colElement = board[j][i];

            if (board[i][j] > '0' && board[i][j] <= '9')
            {

                int div = (i / 3) * 3 + (j / 3);
                // cout << div << " ";
                divBoard[div].insert(board[i][j]);
                k_divs[div]++;

                rowCounter++;
                rowSet.insert(board[i][j]);
            }
            if (board[j][i] > '0' && board[j][i] <= '9')
            {
                colCounter++;
                colSet.insert(board[j][i]);
            }
        }

        //         // TODO -- Important Code Starts
        // -- Checks if size is Equal to the Counter
        cout << "divBoard[i].size : " << divBoard[i].size() << endl;
        cout << "k_divs[i] : " << k_divs[i] << endl;
        if (divBoard[i].size() != k_divs[i])
        {
            return false;
        }

        // cout << "1" << endl;
        if (rowCounter != rowSet.size() || colCounter != colSet.size())
        {
            cout << "ERROR -- size and Counter are not equal ! ";
            return false;
        }

        // Checking For Every Div
        //         vector<unordered_set<char>> divBoard(9);
        //         vector<int> k_divs(9);

        //         // TODO -- Important Code Ends
    }
    return true;

    // _showVectorSet(divBoard);
    // -- Div Block
    // _showVector(k_divs);
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    // -- Main Function code --

    vector<vector<char>> board =
        {{'.', '4', '.', '.', '.', '.', '.', '.', '.'},
         {'.', '.', '4', '.', '.', '.', '.', '.', '.'},
         {'.', '.', '.', '1', '.', '.', '7', '.', '.'},
         {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
         {'.', '.', '.', '3', '.', '.', '.', '6', '.'},
         {'.', '.', '.', '.', '.', '6', '.', '9', '.'},
         {'.', '.', '.', '.', '1', '.', '.', '.', '.'},
         {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
         {'.', '.', '.', '8', '.', '.', '.', '.', '.'}};

#if 0
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char>> board = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
#endif

    // _showBoard(board);
    // bool result =
    isValidSuduko(board);
    // cout << "result : " << result;

    // // -- Testing VecSet Function
    // vector<unordered_set<char>> temp;
    // // = {
    // //     {'1', '2'},
    // //     {'3', '4'},
    // //     {'5', '6'}};

    // unordered_set<char> s1 = {'1', '2'};
    // unordered_set<char> s2 = {'3', '4'};
    // unordered_set<char> s3 = {'5', '6'};
    // temp.push_back(s1);
    // temp.push_back(s2);
    // temp.push_back(s3);
    // _showVectorSet(temp);

    // // --Testing Funciton

    return 0;
}

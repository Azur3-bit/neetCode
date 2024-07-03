// Suduko Col Checker
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
void _showNestedVector(vector<vector<int>> &nums)
{
    cout << "[ \n";
    for (auto it : nums)
    {
        cout << "[ ";
        for (int ij : it)
        {
            cout << ij << " \t";
        }
        cout << "], ";
        cout << endl;
    }
    cout << "] \n";
}

void _showVector(vector<int> &nums)
{
    cout << "\nPrinting Vector \n";
    for (auto it : nums)
    {
        cout << it << " ";
    }
}

void _showSet(std::set<int> &set_1)
{
    cout << "\n Printing Set \n";
    for (int it : set_1)
    {
        cout << it << " ";
    }
}

void checkingOccurace_row(vector<vector<int>> &nums)
{

    cout << "Occurance of Every Element in Column. ";
    cout << "\n-------------------------------------- \n";
    int i = 1;
    for (auto it : nums)
    {
        for (auto ij : it)
        {
            int current_element = ij;
            int count_curr_element = count(it.begin(), it.end(), current_element);
            if (count_curr_element > 1)
            {
                cout << "ERROR ! \n";
                cout << i << ". Count : " << count_curr_element << "\n";
                return;
            }
            i++;
        }
    }
    cout << "\nColumn is fine !\n";
}

void checkingOccurance_col(vector<vector<int>> &nums)
{
    std::set<int> s1;
    // vector<int> _disCol;
    cout << "_disCol :: \n";
    _showSet(s1);
    // _showVector(_disCol);
    cout << endl;

    // traversing Matrix Col Wise
    // cout << ": traversing Matrix Col Wise : \n";
    int iteration = 0;
    for (int i = 0; i < 3; i++)
    {
        int count = 0;
        for (int j = 0; j < 3; j++)
        {
            // cout << nums[j][i] << " ";
            if ((nums[j][i] >= 0) && (nums[j][i] <= 300))
            {
                count++;
                s1.insert(nums[j][i]);
            }
        }
        iteration++;
        int actualSize = s1.size();
        if (count != actualSize)
        {
            // TODO -- First Check the set Behavior
            // ? --- *** Sub_Alogirthm ***---
            // ? using a Brilliant Idea
            // ? Checking The Number of ELements that has be pushed in the set
            // ? if the total number of elements in the set is equal to the number
            // ?      of elements that has to be pushed in the set
            // ?  then all the elements are distinct
            // ? Else One of the element is repeated

            cout << "Iteration : " << iteration;
            cout << "\nAll Elements are not Distinct\n";
            // cout << "Size of the Set : " << actualSize << "\n";
            // cout << "Number of items Inserted in the set : " << count << "\n";
        }
        _showSet(s1);
        // _showVector(_disCol);
        s1 = {};
    }

#if 0
    cout << ":: Columns :: " << endl;
    vector<int> col_1 = nums[0];
    vector<int> col_2 = nums[1];
    vector<int> col_3 = nums[2];
    cout << endl;

    // cout << "First Column : \n";
    for (int it : col_1)
    {
        cout << it << " \t";
    }
    cout << endl;
    // cout << "Second Column : \n";
    for (int ij : col_2)
    {
        cout << ij << " \t";
    }
    cout << endl;
    // cout << "Third Column : \n";
    for (int ik : col_3)
    {
        cout << ik << " \t";
    }
    cout << endl;
    cout << endl;
    cout << endl;

    
    for (int i = 0; i < 3; i++)
    {
        if ((col_1[i] != col_2[i]) || (col_1[i] != col_3[i]) || (col_2[i] != col_3[i]))
        {
            cout << "checking : " << col_1[i] << " " << col_2[i] << " " << col_3[i]<<endl;
            cout << "Good Going !\n";
        }
        else
        {
            cout << "Error !\n";
        }
    }
#endif
}

// void checking_SubSquare(vector<vector<int>> &nums)
void checking_SubSquare()
{
    vector<vector<int>> sub_vec(4);
    sub_vec[0] = {1, 2, 3, 4};
    sub_vec[1] = {10, 20, 30, 40};
    sub_vec[2] = {100, 200, 300, 400};
    sub_vec[3] = {1000, 2000, 3000, 4000};

    cout << " -- *** Nested VECTOR *** --\n";
    _showNestedVector(sub_vec);
    cout << " -- *** Nested VECTOR *** --\n";

    for (int i = 0; i < 4; i++)
    {
        cout << "\n --- *** Current Vector *** --- ";
        vector<int> currentVector = sub_vec[i];
        _showVector(currentVector);
        // cout << "\n --- *** Current Vector *** --- \n";
        // for (int j = 0; j < 4; j++)
        // {
        //     cout << "item : " << i << " , " << j << "\n";
        //     cout << "Division : " << i / j << endl;
        //     cout << "--- --- --- --- --- --- \n";
        // }
    }
}
int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Function code --
    vector<vector<int>> nums = {{1, 2, 3}, {10, 20, 30}, {100, 200, 300}};

    cout << "\n\n:: User Entered vector ::\n";
    cout << "\n--------------\n";
    _showNestedVector(nums);
    cout << "--------------\n";
    // _showNestedVector(nums);
    // checkingOccurace_row(nums);
    // checkingOccurance_col(nums);

    checking_SubSquare();

    return 0;
}
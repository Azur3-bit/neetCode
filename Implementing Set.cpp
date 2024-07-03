// Implementing Set
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

void _showSet(set<int> &temp)
{
    cout << "\n :: Printing Set :: \n";
    for (int it : temp)
    {
        cout << it << " \n";
    }
    cout << "\n :: Set Printed :: \n";

    cout << "Function -- Totol Elements Inside Set " << temp.size();
}

int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Function code --

    set<int> set_1{};
    int count = 0;

    for (int i = 0; i <= 10; i++)
    {
        count++;
        set_1.insert(i);
    }

    set_1.insert(1);
    count++;
    cout << "Total Items inserted : " << count;
    
    _showSet(set_1);
    return 0;
}
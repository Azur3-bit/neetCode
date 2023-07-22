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

void _showSet(const set<int> &usr_Set)
{
    cout << ":: Printing Set ::\n";
    for (int it : usr_Set)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Function code --

    set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    _showSet(s1);

    return 0;
}
// Implementing Buckets - Self 

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
// -- additional_libraries --azure 
#include "TimerClock.h"

    // Classes
    
    // Functions



void ShowHashMap(map<int, int> hashMap)
{
    cout << "\t\t\t"
         << "______ Printing Ordered Hash-Map ______"
         << "\n";
    cout << "\n";
    // cout << "\n";

    cout << "\t\t\t\tKEY"
         << "\t\t"
         << "VAL"
         << "\n";
    cout << "\t\t\t\t---"
         << "\t\t"
         << "---"
         << "\n";
    for (auto it : hashMap)
    {
        cout << "\t\t\t\t" << it.first << "\t\t" << it.second;
        // showNestedVector(it.second);
        cout << endl;
    }

    cout << "\n";
    // cout << "\n";
    cout << "\t\t\t"
         << "______ Ordered Hash-Map Printed ______ "
         << "\n";
}


int main(int argc, char const *argv[])
{

    // -- faster I/O operations 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Code Function

    map<int, int> HashMap{};

    HashMap = {
        {1, 100},
        {2, 200},
        {3, 300},
        {4, 400},
        {5, 500},
    };

    ShowHashMap(HashMap);

    return 0;
}
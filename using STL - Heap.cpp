// using Stl for Heap - priority Queue

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
// -- additional_libraries --azure
#include "TimerClock.h"

// Classes

// Functions

int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Code Function

    priority_queue<int> pq;
    pq.push(90);
    pq.push(100);
    pq.push(110);
    pq.push(1);
    pq.push(10);

    // printing the priority Queue

    cout << "Element on Top " << pq.top() << "\n";

    // Printing whole Priortiy Queue

    cout << "\t\t --:-: Printing Whole Priority Queue :-:-- "
         << "\n";

    while (pq.size())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    
    
    return 0;
}
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

// Classes

// Functions

// Travering map
void traverseMap(unordered_map<char, int> defalutInputedMap)
{
    cout << "\t\t -- Printing Map --"
         << "\n";
    cout << "KEY"
         << "\t\t"
         << "VALUE";
    for (auto iteratorAssigned : defalutInputedMap)
    {
        cout << iteratorAssigned.first << "\t\t" << iteratorAssigned.second << "\n";
    }
    cout << "\t\t -- Map Printed --"
         << "\n";
}

int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Code Function
    unordered_map<char, int> um = {
        {'a', 1},   
        {'b', 2},
        {'c', 3},
        {'d', 4},
        {'e', 5}};

    traverseMap(um);

    for (auto it : um)
    {
        cout << " -- Element "
             << "[" << it.first << " : "
             << it.second << "] "
             << "is in -- \t"
             << um.bucket(it.first) << " bucket." << endl;
    }
    int bucketCount = um.bucket_count();
    cout << "Bucket Count : " << bucketCount;

    return 0;
}
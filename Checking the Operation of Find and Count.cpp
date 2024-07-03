// Checking the Operation of Find and Count Funtion

#include <iostream>
using namespace std;

// additional_libraries
#include <vector>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <map>
#include <set>

// Classes

// Functions

// Traversing Hashmap

void traverseHashMap(unordered_map<string, int> temp)
{
    cout << "   Key"
         << "\t\t\t"
         << "Value"
         << endl;
    int i = 1;
    for (auto it : temp)
    {
        cout << i << ". " << it.first << "\t\t" << it.second << endl;
        i++;
    }
    cout << endl;
}

// Grouping Elements in the unordered Map with same Value

vector<string> groupMap(unordered_map<string, int> temp)
{
    for (auto it : temp)
    {
        
    }
}

int main(int argc, char const *argv[])
{
    // Main Code Function

    unordered_map<string, int> hashMap;
    hashMap["rahul"] = 99;
    hashMap["manoj"] = 91;
    hashMap["vishwas"] = 95;
    hashMap["birju"] = 99;

    traverseHashMap(hashMap);
    cout << ":: Using Count Funtion :: " << endl;

    int count = hashMap.count("birju");
    cout << "Count is : " << count;

    // cout << "using "
    cout << ":: Using FIND Funtion :: " << endl;
    unordered_map<string, int>::iterator it;

    return 0;
}
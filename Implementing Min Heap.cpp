// Implementing Min Heap similar to TopK_frequent Element

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

void ShowHashMap(map<int, int> hashMap)
{
    cout << "\t\t\t"
         << "______ Printing UnOrdered Hash-Map ______"
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
         << "______ UnOrdered Hash-Map Printed ______ "
         << "\n";
}

int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Code Function

    // Elements - 3,2,1
    // Occurance - 1,2,3

    // Actual Array inputed :- {1,1,1,2,2,3}

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> occurance = {1, 2, 3};
    vector<int> Elements = {3, 2, 1};

    map<int, int> HashMap{};

    // inputing Values in Hashmap w.r.t there keys
    cout << " :: Inputing in HashMap :: \n";

    for (int i = 0; i < nums.size(); i++)
    {
        HashMap[nums[i]] = count(nums.begin(), nums.end(), nums[i]);
    }

    // Printing HashMap

    ShowHashMap(HashMap);

    return 0;
}
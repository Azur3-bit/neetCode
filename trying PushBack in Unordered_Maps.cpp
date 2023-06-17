// trying PushBack in Unordered_Maps

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

void ShowUnorderedMap(const unordered_map<string,vector<int>> &temp){

    cout << "KEY" << "\t" << "VAL" << endl;
    for (auto it : temp)
    {
        cout << it.first << "\t" ;
        // cout << it.second << endl;
        vector<int> tempo = it.second;
        for(auto i : tempo){
            // cout << "[ ";
            cout << i << " ";
            // cout << "] ";
        }
        cout << endl;
    }
}


int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Code Function

    unordered_map<string, vector<int>> um;
    // vector<string> phoneNumber = {"1", "2", "3"};

    um["rahul"].push_back(1);
    um["rahul"].push_back(2);
    um["rahul"].push_back(3);

    ShowUnorderedMap(um);

    return 0;
}

// Output/
// F:\neetCode>a.exe
// KEY     VAL
// rahul   1 2 3

// F:\neetCode>
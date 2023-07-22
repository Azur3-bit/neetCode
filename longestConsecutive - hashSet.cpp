// longestConsecutive - hashSet
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

    void _showSet(set<int> &nums){
        cout << "Printing Set " << endl;
        for(int it : nums){
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

    set<int> s1 = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    _showSet(s1);

    return 0;
}
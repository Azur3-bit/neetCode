// Learning Priority queue

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

void _showPriortiyQueue(priority_queue<int> &pq){
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    
}

void priorityQueue(const vector<int> &nums)
{
    priority_queue<int> pq;
    for (int it : nums){
        pq.push(it);
    }
    _showPriortiyQueue(pq);
}

int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Code Function
    vector<int> nums = {100, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    priorityQueue(nums);
    return 0;
}
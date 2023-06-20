// deletion in Heaps

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

class Heaps
{
public:
    int size = 0;
    int array[30];

    void insert_heaps(int value)
    {
        size++;
        int index = size;
        array[size] = value;

        while (index > 1)
        {
            int parent_index = index / 2;
            if (array[parent_index] > array[index])
            {
                swap(array[parent_index], array[index]);
                index = parent_index;
            }
            else
                return;
        }
    }
};

// Functions

int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Code Function

    return 0;
}
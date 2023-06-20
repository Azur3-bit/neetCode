// insertion in heaps practice - 3

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

class Heaps_DevCreated_underWay
{
public:
    int array[30];
    int size = 0;

    Heaps_DevCreated_underWay(){
        array[0] = -1;
        size = 0;
    }

    void InsertionInHeaps(int value)
    {
        size++;
        int index = size;
        array[size] = value;

        while (index > 1)
        {
            int parent_value_index = index / 2;
            if (array[parent_value_index] > array[index])
            {
                swap(array[parent_value_index], array[index]);
                index = parent_value_index;
            }
            else
            {
                return;
            }
        }
    }

    // Funtion to Print Heaps

    void PrintHeaps(){
        for (int i = 1; i < size + 1;i++){
            cout << array[i] << " ";
        }
    }
};

// Functions

main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Code Function

    Heaps_DevCreated_underWay hps;
    hps.InsertionInHeaps(10);
    hps.InsertionInHeaps(11);
    hps.InsertionInHeaps(17);
    hps.InsertionInHeaps(19);
    hps.InsertionInHeaps(12);
    hps.InsertionInHeaps(13);
    hps.InsertionInHeaps(10);

    hps.InsertionInHeaps(8);

    hps.PrintHeaps();

    return 0;
}
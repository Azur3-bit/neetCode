// insertion in Heap - C++
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

class heaps
{
public:
    int array[30];
    int size = 0;

    void insertion_inHeaps(int user_value)
    {

        size++;
        int index = size;
        array[size] = user_value;
        while (index > 1)
        {
            int parent_index = index / 2;
            if (array[parent_index] > array[index])
            {
                swap(array[index], array[parent_index]);
                index = parent_index;
            }
            else
            {
                return;
            }
        }
    }

    void ShowHeap()
    {
        std::cout << "\t\t-- Printing Heap -- "
                  << "\n";
        for (int i = 1; i < size + 1; i++)
        {
            cout << array[i] << " ";
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

    heaps Obj_ofHeap;
    Obj_ofHeap.insertion_inHeaps(2);
    Obj_ofHeap.insertion_inHeaps(3);
    Obj_ofHeap.insertion_inHeaps(4);
    Obj_ofHeap.insertion_inHeaps(5);
    Obj_ofHeap.insertion_inHeaps(10);

    Obj_ofHeap.insertion_inHeaps(1);
    Obj_ofHeap.ShowHeap();

    return 0;
}
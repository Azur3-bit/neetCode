// insertion in Heaps - try_2 -- self

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

class Heaps_DevCreated
{

public:
    int array[30];
    int size = 0;

    void Insert_inHeaps(int value_unitx32)
    {
        size++;
        int index = size;
        array[size] = value_unitx32;

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

    void ShowHeaps_DevCreated()
    {
        cout << "\n";
        cout << "\t\t--_ Printing Heap _-- " << endl;
        cout << "\n";
        cout << "\t\t";

        for (int i = 1; i < size + 1; i++)
        {
            cout << array[i] << " ";
        }
        cout << "\n";
        cout << "\n\t\t-- Heap __ Printed -- " << endl;
    }
};

// Functions

int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Code Function

    Heaps_DevCreated userCreatedUser;
    userCreatedUser.Insert_inHeaps(1);
    userCreatedUser.Insert_inHeaps(2);
    userCreatedUser.Insert_inHeaps(3);
    userCreatedUser.Insert_inHeaps(4);
    userCreatedUser.Insert_inHeaps(5);
    userCreatedUser.Insert_inHeaps(7);
    userCreatedUser.Insert_inHeaps(8);
    userCreatedUser.Insert_inHeaps(9);
    userCreatedUser.Insert_inHeaps(10);

    userCreatedUser.ShowHeaps_DevCreated();

    // userCreatedUser.

    return 0;
}
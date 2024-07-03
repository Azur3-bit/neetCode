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

class Heaps_DevCreated
{
public:
    int size = 0;
    int array[30];

    void Insert_inHeaps(int value)
    {
        size++;
        int index = size;
        array[size] = value;

        while (index > 1)
        {
            int parent_index = index / 2;
            if (array[index] > array[parent_index])
            {
                swap(array[parent_index], array[index]);
                index = parent_index;
            }
            else
                return;
        }
    }

    void ShowHeap()
    {
        for (int i = 1; i < size + 1; i++)
        {
            cout << array[i] << " ";
        }
    }

    void deletion()
    {

        // base Case
        if (size == 0)
        {
            cout << ":: Nothing to delete :: ";
            return;
        }

        // Copy the same element
        array[1] = array[size];
        // removing the element by decrementing the size of the array
        size--;

        // moving the elements to thier exact position
        // making all the necessary conditions
        int index = 1;

        while (index < size)
        {

            int right = index * 2;
            int left = (index * 2) + 1;

            if ((index < size) && (array[index] < array[right]))
            {
                swap(array[index], array[right]);
                index = right;
            }
            else if ((index < size) && (array[index] < array[left]))
            {
                swap(array[index], array[right]);
                index = left;
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

    {
        timer Time;
        // Creating Obj
        Heaps_DevCreated userCreatedUser;
        userCreatedUser.Insert_inHeaps(50);
        userCreatedUser.Insert_inHeaps(55);
        userCreatedUser.Insert_inHeaps(53);
        userCreatedUser.Insert_inHeaps(52);
        userCreatedUser.Insert_inHeaps(54);
        // userCreatedUser.Insert_inHeaps(7);
        // userCreatedUser.Insert_inHeaps(8);
        // userCreatedUser.Insert_inHeaps(9);
        // userCreatedUser.Insert_inHeaps(10);n

        // Printing Heap
        userCreatedUser.ShowHeap();

        // Deleting root Element of the heap
        userCreatedUser.deletion();
        cout << endl;
        userCreatedUser.ShowHeap();
        // userCreatedUser.ShowHeap();
    }

    // Printing Heap

    return 0;
}
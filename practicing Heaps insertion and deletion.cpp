// practicing Heaps insertion and deletion

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

    void insertion(int value)
    {
        size++;
        int index = size;
        array[index] = value;

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

    void ShowHeap()
    {
        for (int i = 1; i < size + 1; i++)
        {
            cout << array[i] << " ";
        }
        cout << "\n";
    }
};

// Functions
int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Code Function

    Heaps user_createdHeap;
    user_createdHeap.insertion(1);
    user_createdHeap.insertion(2);
    user_createdHeap.insertion(3);
    user_createdHeap.insertion(4);
    user_createdHeap.insertion(90);

    user_createdHeap.ShowHeap();

    return 0;
}
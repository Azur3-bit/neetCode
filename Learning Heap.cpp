// ?        -- Learning Heap --

// *           Love babbar --- https://www.youtube.com/watch?v=NKJnHewiGdc

// TODO -- Checklist --
// What are Heaps
// Max heap
// min heap
// insertion
// deletion
// Heapify Algorithm
// Heap Sort
// Priority Queue
// Priority Queue - Min Heap
// Priority Queue - Max Heap

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

class Heap
{
public:
    int array[10];
    int size = 0;

    void insert_2(int user_input_Val_bitx32)
    {
        // Enter Code here
        size++;
        array[size] = user_input_Val_bitx32;
        int index = size;
        while (index > 1)
        {

            int parent_element = index / 2;
            if (array[index] > array[parent_element])
            {
                swap(array[index], array[parent_element]);
                index = parent_element;
            }
            else
            {
                return;
            }
        }
    }

    void printHeap(int array[])
    {
        int curret_size = size;

        for (int i = 1; i < size + 1; i++)
        {
            cout << array[i] << " ";
        }
    }

    // void insert(int value)
    // {

    //     // Incrementing the size of the array cuz a new element is added to the heap

    //     size++;
    //     int index = size;
    //     array[index] = value;

    //     while (index > 1)
    //     {
    //         // finding the parent element
    //         int parent_element = index / 2;
    //         if (array[index] > array[parent_element])
    //         {
    //             swap(array[index], array[parent_element]);
    //             index = parent_element;
    //         }
    //         else
    //         {
    //             return;
    //         }
    //     }
    // }

    void showHeap(int Array[])
    {
        // int size = Array.size();

        for (int i = 1; i < size + 1; i++)
        {
            std::cout << Array[i] << " ";
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

    // creating a object for class Heap - hp;
    Heap hp;
    hp.insert_2(60);
    hp.insert_2(50);
    hp.insert_2(40);
    hp.insert_2(30);
    hp.insert_2(20);

    hp.printHeap(hp.array);
    return 0;
}

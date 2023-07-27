// Implementing Stacks and its functions
// -- essential_libraries_and_namespace
#include <iostream>
using namespace std;

// -- additional_libraries
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
// -- additional_libraries -- azur3
#include "TimerClock.h"
#define size 10

// Classes

class Stack
{
public:
    int top = -1;
    int arr[size];

    bool isEmpty()
    {
        if (top == -1)
        {
            cout << "Stack is Empty " << endl;
            return true;
        }
        return false;
    }

    void isFull()
    {
        if (top == size - 1)
        {
            cout << "Stack is FULL" << endl;
        }
    }

    void Peek()
    {
        if (top != -1)
        {
            cout << arr[top] << endl;
        }
    }

    void push(int value)
    {
        if (top >= size - 1)
        {
            cout << "OverFlow Condition" << endl;
        }
        else
        {
            cout << "Element pushed in the stack " << value << endl;
            arr[++top] = value;
        }
    }

    void popElement()
    {
        if (top <= -1)
        {
            cout << "UnderFlow Condition " << endl;
        }
        else
        {
            // int element_poped = arr[top];
            // cout << "Element Poped" << element_poped << endl;
            top--;
        }
    }

    void showStack()
    {
        cout << "-- Printing Stack -- " << endl;
        while (!isEmpty())
        {
            Peek();
            popElement();
        }
        cout << "-- Stack Printed -- " << endl;
    }
};

// Functions

int main(int argc, char const *argv[])
{

    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Function code --

    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.push(8);
    s1.push(9);
    s1.push(10);
    s1.push(11);
    s1.popElement();

    s1.showStack();

    return 0;
}
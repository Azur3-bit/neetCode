// linked list try

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

// Classes

struct node
{
    int data;
    node *next;
};

void TraverseLL(node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
    cout << "\nEnd of linked list " << endl;
}

void insert(node *ptr, int data)
{
}
// Functions

int main(int argc, char const *argv[])
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Function code --

    return 0;
}
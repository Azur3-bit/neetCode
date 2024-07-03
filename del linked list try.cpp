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
    cout << "End of linked list " << endl;
}

node *findItem(node *ptr, int findItem)
{
    while (ptr->data != findItem)
    {
        // cout << ptr->data << endl;
        ptr = ptr->next;
    }
    cout << "\nReached Element " << endl;
    cout << "Item at this Node : " << ptr->data << endl;
    return ptr;
}

void insert(node *ptr, int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    cout << "reached Node " << endl;

    ptr->next = newNode;
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

    node *first = new node;
    node *second = new node;
    node *third = new node;
    node *forth = new node;
    node *fifth = new node;

    // linkage
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;

    // Data item
    first->data = 1;
    second->data = 2;
    third->data = 3;
    forth->data = 4;
    fifth->data = 5;

    // Travese Linked list
    TraverseLL(first);
    // insert(first, 6);
    // TraverseLL(first);

    node *delPtr = findItem(first, 3);
    delete delPtr;
    TraverseLL(first);

    return 0;
}
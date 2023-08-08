// linkedlist boilerplate

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
#include <cmath>
#include <set>
#include <unordered_set>
#include <queue>
// -- additional_libraries -- azur3
#include "TimerClock.h"

// -- Classes

class node
{

public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

// -- Functions

void insertAt_tail(node *&head, int value)
{
    node *newNode = new node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void _showLinkedList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl
         << endl;
}

void insert_Head(node *&head, int value)
{

    node *newNode = new node(value);
    newNode->next = head;
    head = newNode;
}

void searchingAValue(node *head, int val)
{
    int counter = 0;
    while (head->data != val)
    {
        counter++;
        head = head->next;
        if (head == NULL)
        {
            cout << "end of linked list \n";
            return;
        }
    }

    cout << "element : " << val << " at : " << counter << endl;
}

void insertNode_Between(node *&head, int value, int after_Value)
{
    node *temp = head;
    node *temp1 = head;

    node *newNode = new node(value);

    while (temp->data !=  after_Value)
    {
        if (temp->next == NULL)
        {
            cout << "End of linked list " << endl;
            return;
        }
        temp = temp->next;
        // temp1 = temp1->next;
    }
    temp1 = temp->next;
    temp->next = newNode;
    newNode->next = temp1;
}

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

    node *head = NULL;
    insertAt_tail(head, 100);
    insertAt_tail(head, 200);
    insertAt_tail(head, 300);
    insertAt_tail(head, 400);
    insertAt_tail(head, 500);

    _showLinkedList(head);

    insert_Head(head, 0);
    _showLinkedList(head);

    // insert_Head(head, -1);
    // _showLinkedList(head);

    searchingAValue(head, 400);

    insertNode_Between(head, 201, 200);
    _showLinkedList(head);

    cout << "Working now as !" << endl;

    std::vector<int> v = {1, 2, 3, 4, 5};
    for (auto it : v) {
        cout << it << endl;
    }

    cout << "Working !!" << endl;

    return 0;
}

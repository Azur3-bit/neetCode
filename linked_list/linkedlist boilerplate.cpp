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


// insert node at tail
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


// traversal linked list
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

// insert node at head
void insert_Head(node *&head, int value)
{

    node *newNode = new node(value);
    newNode->next = head;
    head = newNode;
}

// searching a node in the linked list
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

// insert node in between nodes of linked list
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

// delete node from head of linked list
void Delete_Node_Head(node * &head) {
#if 0
    // not - by reference code
    node *temp = head;
    temp = temp->next;
    head->next = temp;
    return temp;
#endif
    cout << "delete Node" << endl;
    // return head ;

    node * temp = head;
    head = head->next;
    cout << "Address of temp " << &temp << endl;
    delete temp;
    cout << "Checking at he address of temp " << endl;
    cout << temp->data << endl;
    cout << " -- -- --  " << endl;
}

// delete node with given value
void Delete_Node_after_Element(node *&head, int item) {

    // problems => infinte loop
    // problems => what if elemnt does not exist in the linked list

    node * temp_previousElement = head;
    // node * temp_nxtElement = head;
    int counter = 1;
    while (temp_previousElement->next != nullptr && temp_previousElement->next->data != item ) {
        temp_previousElement = temp_previousElement->next;
        counter++;
    }
    cout << "Element after nodes : " << counter << endl;
    if (temp_previousElement->next != nullptr) {
        node * node_delete = temp_previousElement->next;
        cout << "data of node to be deleted : " << node_delete->data << endl;
        temp_previousElement->next = node_delete->next;
        delete node_delete;
        cout << " -- node has been deleted !" << endl;
    }
    else {
        cout << "node not found !" << endl;
    }
}

//  -- Delete node at the tail
void Delete_Node_Tail(node *head) {
    node * temp = head;
    int c = 1;
    while (temp->next->next != nullptr) {
        temp = temp->next;
        c++;
    }
    node *nodeDel = temp;
    nodeDel = nodeDel->next;
    cout << "node which will be deleted : " << nodeDel->data << endl;
    temp->next = nullptr;
    delete nodeDel;
    // cout << " -- -- \n";
    // cout << "Current Node : " << temp->data << endl;
    // cout << "lenght of linked list : " << c << endl;
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
    cout << " -- Deletion in Linked list \n";
    cout << "deleting node from head !" << endl;
    Delete_Node_Head(head);
    _showLinkedList(head);

    Delete_Node_after_Element(head, 201);
    _showLinkedList(head);

    Delete_Node_Tail(head);
    _showLinkedList(head);
    cout << "done !" << endl;
    // std::vector<int> v = {1, 2, 3, 4, 5};
    // for (auto it : v) {
    //     cout << it << endl;
    // }
    // cout << "Working !!" << endl;

    return 0;
}

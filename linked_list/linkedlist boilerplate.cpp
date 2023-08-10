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

class ListNode
{

public:
    int val;
    ListNode *next;

    ListNode(int value)
    {
        val = value;
        next = NULL;
    }
};

// -- Functions


// insert ListNode at tail
void insertAt_tail(ListNode *&head, int value)
{
    ListNode *ListNode = new ListNode(value);

    if (head == NULL)
    {
        head = ListNode;
        return;
    }

    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ListNode;
}


// traversal linked list
void _showLinkedList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl
         << endl;
}

// insert ListNode at head
void insert_Head(ListNode *&head, int value)
{

    ListNode *ListNode = new ListNode(value);
    ListNode->next = head;
    head = ListNode;
}

// searching a ListNode in the linked list
void searchingAValue(ListNode *head, int val)
{
    int counter = 0;
    while (head->val != val)
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

// insert ListNode in between ListNodes of linked list
void ListNode_Between(ListNode *&head, int value, int after_Value)
{
    ListNode *temp = head;
    ListNode *temp1 = head;

    ListNode *ListNode = new ListNode(value);

    while (temp->val !=  after_Value)
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
    temp->next = ListNode;
    ListNode->next = temp1;
}

// delete ListNode from head of linked list
void ListNode_Head(ListNode * &head) {
#if 0
    // not - by reference code
    ListNode *temp = head;
    temp = temp->next;
    head->next = temp;
    return temp;
#endif
    cout << "delete ListNode" << endl;
    // return head ;

    ListNode * temp = head;
    head = head->next;
    cout << "Address of temp " << &temp << endl;
    delete temp;
    cout << "Checking at he address of temp " << endl;
    cout << temp->val << endl;
    cout << " -- -- --  " << endl;
}

// delete ListNode with given value
void ListNode_after_Element(ListNode *&head, int item) {

    // problems => infinte loop
    // problems => what if elemnt does not exist in the linked list

    ListNode * temp_previousElement = head;
    // ListNode * temp_nxtElement = head;
    int counter = 1;
    while (temp_previousElement->next != nullptr && temp_previousElement->next->val != item ) {
        temp_previousElement = temp_previousElement->next;
        counter++;
    }
    cout << "Element after ListNodes : " << counter << endl;
    if (temp_previousElement->next != nullptr) {
        ListNode * ListNode_delete = temp_previousElement->next;
        cout << "val of ListNode to be deleted : " << ListNode_delete->val << endl;
        temp_previousElement->next = ListNode_delete->next;
        delete ListNode_delete;
        cout << " -- ListNode has been deleted !" << endl;
    }
    else {
        cout << "ListNode not found !" << endl;
    }
}

//  -- Delete ListNode at the tail
void ListNode_Tail(ListNode *head) {
    ListNode * temp = head;
    int c = 1;
    while (temp->next->next != nullptr) {
        temp = temp->next;
        c++;
    }
    ListNode *ListNodeDel = temp;
    ListNodeDel = ListNodeDel->next;
    cout << "ListNode which will be deleted : " << ListNodeDel->val << endl;
    temp->next = nullptr;
    delete ListNodeDel;
    // cout << " -- -- \n";
    // cout << "Current ListNode : " << temp->val << endl;
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
    ListNode *head = NULL;
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
    ListNode_Between(head, 201, 200);
    _showLinkedList(head);
    cout << " -- Deletion in Linked list \n";
    cout << "deleting ListNode from head !" << endl;
    ListNode_Head(head);
    _showLinkedList(head);

    ListNode_after_Element(head, 201);
    _showLinkedList(head);

    ListNode_Tail(head);
    _showLinkedList(head);
    cout << "done !" << endl;
    // std::vector<int> v = {1, 2, 3, 4, 5};
    // for (auto it : v) {
    //     cout << it << endl;
    // }
    // cout << "Working !!" << endl;

    return 0;
}

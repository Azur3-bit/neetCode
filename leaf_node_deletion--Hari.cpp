// actual code -- Haary

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
// #include "TimerClock.h"

// Classes

// Functions

#include <iostream>
#include <queue>
#include "TimerClock.h"
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void takeinput(Node *&root)
{
    int data;
    cin >> data;
    queue<Node *> q;
    root = new Node(data);
    q.push(root);

    // Hari Code - Change 1 - simple kar rahe hai code ko -1 ki statement mei null kar diye hai

    if (data == -1)
    {
        root = NULL;
        return;
    }

    while (!q.empty())
    {
        int Nodedata;
        Node *temp = q.front();
        q.pop();

        cout << "Enter the left of " << temp->data << endl;
        cin >> Nodedata;
        if (Nodedata != -1)
        {
            temp->left = new Node(Nodedata);
            q.push(temp->left);
        }

        cout << "Enter the right of " << temp->data << endl;
        cin >> Nodedata;
        if (Nodedata != -1)
        {
            temp->right = new Node(Nodedata);
            q.push(temp->right);
        }
    }
}

// Level-wise printing.
void Levelprinting(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    // Edge Case -- If the tree is empty
    if (root == NULL)
    {
        cout << "Tree is empty " << endl;
        return;
    }

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

// Created Fucntion To find the Parent Node -- Azur3
Node *BaapNode(Node *root, int data)
{
    Node *tempParent = root;
    Node *Biological_Papaji = NULL;

    while (tempParent != NULL)
    {
        if (tempParent->data == data)
        {
            return Biological_Papaji;
        }
        else if (data < tempParent->data)
        {
            Biological_Papaji = tempParent;
            tempParent = tempParent->left;
        }
        else if (data > tempParent->data)
        {
            Biological_Papaji = tempParent;
            tempParent = tempParent->right;
        }
    }
    return NULL;
}

Node *searching(Node *root, int data)
{
    Node *temp = root;
    if (temp == NULL)
    {
        cout << "Node not available ";
        return NULL;
    }
    else
    {
        if (data == temp->data)
        {
            cout << "\n-- -- - - - - - - - \n";
            cout << "\n-- azur3 -- Node has been found !\n";
            cout << "\n-- -- - - - - - - - \n";
            return temp;
        }
        else if (data < temp->data)
        {
            return searching(temp->left, data);
        }
        else if (data > temp->data)
        {
            return searching(temp->right, data);
        }
    }

    return temp;
}

// deleting the given node.

// Made Changes in Delete_Node -- Azur3
void Delete_Node(Node *&root, int num)
{
    // nam badal diya hai prev to _prev_temp_NodeTobeDeleted
    Node *_prev_temp_NodeTobeDeleted = searching(root, num);

    // Finding its parent

    Node *baap = BaapNode(root, num);
    Node *prev = NULL;

    if (root == NULL)
    {
        cout << "Tree is empty " << endl;
        return;
    }

    if (_prev_temp_NodeTobeDeleted->left == NULL && _prev_temp_NodeTobeDeleted->right == NULL)
    {

        if (baap->left == _prev_temp_NodeTobeDeleted)
        {
            cout << "\n-- -- - - - - - - - \n";
            cout << "\n-- azur3 -- Node has been found !\n";
            cout << "\n-- -- - - - - - - - \n";
            baap->left = NULL;
            delete _prev_temp_NodeTobeDeleted;
            // _prev_temp_NodeTobeDeleted = NULL;
            return;
        }
        if (baap->right == _prev_temp_NodeTobeDeleted)
        {
            cout << "\n-- -- - - - - - - - \n";
            cout << "\n-- azur3 -- Node has been found !\n";
            cout << "\n-- -- - - - - - - - \n";
            baap->right = NULL;
            delete _prev_temp_NodeTobeDeleted;
            // _prev_temp_NodeTobeDeleted = NULL;
            return;
        }
    }
    Node *temp1 = _prev_temp_NodeTobeDeleted->left;
    while (temp1->right != NULL)
    {
        prev = temp1;
        temp1 = temp1->right;
    }

    if (temp1->left != NULL)
    {
        _prev_temp_NodeTobeDeleted->data = temp1->data;
        temp1->data = temp1->left->data;
        temp1->left = NULL;
        delete prev->right;
    }
    else if (temp1->right == NULL && temp1->left == NULL)

    {
        cout << "else if right if NULL " << endl;
        _prev_temp_NodeTobeDeleted->data = temp1->data;
        delete temp1;
    }
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Function code --

    // ex: 50 25 75 20 30 70 80 15 23 28 40 65 72 76 85 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Enter the root data ";
    // Node *root = insertTree(root);

    Node *root;
    takeinput(root);
    Levelprinting(root);

    // deleting node.
    int num = 0;
    cout << "Enter the number to delete from the tree ";
    cin >> num;
    Delete_Node(root, num);

    cout << "Azur3 -- Printing Tree after Deletion !! \n\n";
    Levelprinting(root);
    return 0;
}
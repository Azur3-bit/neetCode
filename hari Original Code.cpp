// hari Original Code

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

// Functions

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
// void Delete_Node(Node *&root, int num)
// {
//     Node *temp = searching(root, num);
//     Node *prev = NULL;

//     if (root == NULL)
//     {
//         cout << "Tree is empty " << endl;
//         return;
//     }

//     if (temp->left == NULL && temp->right == NULL)
//     {
//         delete temp;
//         temp = NULL;
//         return;
//     }
//     Node *temp1 = temp->left;
//     while (temp1->right != NULL)
//     {
//         prev = temp1;
//         temp1 = temp1->right;
//     }

//     if (temp1->left != NULL)
//     {
//         temp->data = temp1->data;
//         temp1->data = temp1->left->data;
//         temp1->left = NULL;
//         delete prev->right;
//         temp1->left = NULL;
//     }
//     else if (temp1->right == NULL && temp1->left == NULL)

//     {
//         cout << "else if right if NULL " << endl;
//         temp->data = temp1->data;
//         delete temp1;
//     }
// }

void Delete_Node(Node *&root, int num)
{
    Node *temp = searching(root, num);
    Node *prev = NULL;

    if (root == NULL)
    {
        cout << "Tree is empty " << endl;
        return;
    }

    if (temp->left == NULL && temp->right == NULL)
    {
        // Node to be deleted has no children
        if (temp == root)
        {
            delete root;
            root = NULL;
        }
        else
        {
            delete temp;
            temp = NULL;
        }
        return;
    }
    else if (temp->right == NULL)
    {
        // Node has only left child.
        Node *temp1 = temp->left;
        temp->data = temp1->data;
        temp->left = temp1->left;
        temp->right = temp1->right;
        delete temp1;
    }
    else
    {
        // Node has both left and right children.
        Node *temp1 = temp->left;
        while (temp1->right != NULL)
        {
            prev = temp1;
            temp1 = temp1->right;
        }
        temp->data = temp1->data;
        if (prev != NULL)
            prev->right = temp1->left;
        else
            temp->left = temp1->left;
        delete temp1;
    }
}

int main()
{ // ex: 50 25 75 20 30 70 80 15 23 28 40 65 72 76 85 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Function code --

    cout << "Enter the root data ";
    // Node *root = insertTree(root);

    Node *root;
    takeinput(root);
    Levelprinting(root);

    // deleting node.
    int num = 0;
    // cout << "Enter the number to delete from the tree ";
    // cin >> num;
    // Delete_Node(root, num);

    Node *delPtr = searching(root, 85);
    delete delPtr;
    Levelprinting(root);

    return 0;
}
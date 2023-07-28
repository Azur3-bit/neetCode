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
    if (data == -1)
    {
        root = NULL;
        return;
    }
    root = new Node(data);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter the left of " << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->left = new Node(data);
            q.push(temp->left);
        }

        cout << "Enter the right of " << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
}

// Level-wise printing.
void Levelprinting(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty " << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

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

Node *searchParent(Node *root, int data)
{
    Node *temp = root;
    Node *parent = NULL;
    while (temp != NULL)
    {
        if (data == temp->data)
        {
            return parent;
        }
        else if (data < temp->data)
        {
            parent = temp;
            temp = temp->left;
        }
        else
        {
            parent = temp;
            temp = temp->right;
        }
    }
    return NULL;
}

// Deleting the given node.
Node *Delete_Node(Node *&root, int num)
{
    Node *parent = searchParent(root, num);
    if (parent == NULL)
    {
        cout << "Node not available" << endl;
        return root;
    }

    Node *nodeToDelete;
    if (parent->left != NULL && parent->left->data == num)
    {
        nodeToDelete = parent->left;
    }
    else if (parent->right != NULL && parent->right->data == num)
    {
        nodeToDelete = parent->right;
    }
    else
    {
        cout << "Node not available" << endl;
        return root;
    }

    // Case 1: Node to delete has no children.
    if (nodeToDelete->left == NULL && nodeToDelete->right == NULL)
    {
        if (parent->left == nodeToDelete)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        delete nodeToDelete;
    }
    // Case 2: Node to delete has one child.
    else if (nodeToDelete->left == NULL)
    {
        if (parent->left == nodeToDelete)
        {
            parent->left = nodeToDelete->right;
        }
        else
        {
            parent->right = nodeToDelete->right;
        }
        delete nodeToDelete;
    }
    else if (nodeToDelete->right == NULL)
    {
        if (parent->left == nodeToDelete)
        {
            parent->left = nodeToDelete->left;
        }
        else
        {
            parent->right = nodeToDelete->left;
        }
        delete nodeToDelete;
    }
    // Case 3: Node to delete has two children.
    else
    {
        // Find the minimum value node in the right subtree (or the maximum value node in the left subtree).
        Node *minRightSubtree = nodeToDelete->right;
        while (minRightSubtree->left != NULL)
        {
            minRightSubtree = minRightSubtree->left;
        }

        // Copy the data from the minimum value node to the node to be deleted.
        nodeToDelete->data = minRightSubtree->data;

        // Now, delete the minimum value node in the right subtree.
        // This will either be a case with one child or no child (already handled).
        root = Delete_Node(root, minRightSubtree->data);
    }

    return root;
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

    cout << "Enter the root data: ";
    Node *root = NULL;
    takeinput(root);
    Levelprinting(root);

    // Deleting node.
    int num = 0;
    cout << "Enter the number to delete from the tree: ";
    cin >> num;
    root = Delete_Node(root, num);
    Levelprinting(root);

    return 0;
}

#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printBST(TreeNode* root) {
    if (root == nullptr)
        return;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int prevLevel = -1;

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int level = q.front().second;
        q.pop();

        if (level != prevLevel) {
            cout << endl; // Move to the next level
            prevLevel = level;
        }

        cout << setw(4 * level + 2) << node->val;

        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }
    cout << endl;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(21);
    root->right->left = new TreeNode(27);
    root->right->right = new TreeNode(5);
    root->left->left->left = new TreeNode(5);
    root->left->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(23);
    root->left->right->right = new TreeNode(99);
    root->right->right->left = new TreeNode(1000);
    root->left->left->left->left = new TreeNode(4);
    root->left->left->left->left->left = new TreeNode(3);

    cout << "Binary Search Tree Visualization:" << endl;
    printBST(root);

    // Free memory (not necessary in this example but good practice)
    // You can use a function for memory deallocation
    delete root->left->left->left->left->left;
    delete root->left->left->left->left;
    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

#include <bits/stdc++.h>  // includes all standard C++ libraries
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * Inverts a binary tree (produces its mirror image).
     *
     * Approach:
     * - Recursively swap the left and right child of each node.
     *
     * Time Complexity: O(n) — we visit every node exactly once.
     * Space Complexity: O(h) — due to recursive stack where h is the height of the tree.
     */
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;  // base case: empty subtree

        // swap left and right children
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        // recursively invert left and right subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers (like <iostream>, <vector>, etc.) in a single line.

using namespace std;
    ✅ Allows using names like vector, cout, etc., without writing std::vector explicitly.

struct TreeNode {
    ✅ Defines a structure to represent a binary tree node.

int val;
    ✅ Holds the value of the current node.

TreeNode *left;
TreeNode *right;
    ✅ Pointers to the left and right children of the node.

TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ✅ Default constructor: initializes val = 0 and both children as nullptr.

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ✅ Constructor to initialize val and set children as nullptr.

TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ✅ Constructor to initialize val, left child, and right child.

class Solution {
    ✅ Defines the Solution class.

public:
    ✅ Public methods of the class.

TreeNode* invertTree(TreeNode* root)
    ✅ Function that returns the root of the inverted tree.

if (!root) return nullptr;
    ✅ Base case: if the current node is nullptr, return nullptr.

TreeNode* tmp = root->left;
    ✅ Store the left child in a temporary pointer.

root->left = root->right;
root->right = tmp;
    ✅ Swap the left and right children.

invertTree(root->left);
invertTree(root->right);
    ✅ Recursively invert the left and right subtrees.

return root;
    ✅ Return the (inverted) root of this subtree.

*/

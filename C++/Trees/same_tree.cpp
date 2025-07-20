#include <bits/stdc++.h> 
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
     * Check if two binary trees are identical.
     *
     * Two binary trees are considered the same if:
     * - they are structurally identical
     * - their corresponding nodes have the same value
     *
     * Time Complexity: O(min(n, m)) where n and m are number of nodes in the two trees.
     * Space Complexity: O(min(h1, h2)) where h1 and h2 are the heights of the two trees (due to recursion).
     */
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: if both trees are empty, they are identical
        if (!p && !q) return true;

        // If one tree is empty or values differ, they are not identical
        if (!p || !q || p->val != q->val) return false;

        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers (iostream, vector, etc.) in one line.

using namespace std;
    ✅ Allows us to write names like vector, cout without the std:: prefix.

struct TreeNode {
    ✅ Defines the binary tree node structure.

int val;
    ✅ Stores the value of the node.

TreeNode *left, *right;
    ✅ Pointers to the left and right children of the node.

TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ✅ Default constructor: sets value = 0 and children = nullptr.

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ✅ Constructor with value x and null children.

TreeNode(int x, TreeNode *left, TreeNode *right)
    ✅ Constructor with value x and specified left & right children.

class Solution {
    ✅ Defines the Solution class.

public:
    ✅ Public methods of the Solution class.

bool isSameTree(TreeNode* p, TreeNode* q)
    ✅ Function to check if trees rooted at p and q are identical.

if (!p && !q) return true;
    ✅ If both nodes are null, the trees are identical here.

if (!p || !q || p->val != q->val) return false;
    ✅ If one is null, or their values differ, trees are not identical.

return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    ✅ Recursively check left and right subtrees.

*/

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
     * Check if subRoot is a subtree of root.
     *
     * A subtree of a binary tree is a tree that consists of a node in the main tree and all its descendants.
     *
     * Time Complexity: O(m * n) where m is the number of nodes in root and n is the number in subRoot.
     * Space Complexity: O(min(h1, h2)) where h1, h2 are heights of root and subRoot.
     */
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Base case: empty subtree is always a subtree
        if (!subRoot) return true;

        // If main tree is empty but subtree is not → not a subtree
        if (!root) return false;

        // If the trees rooted at current nodes are identical
        if (sameTree(root, subRoot)) return true;

        // Otherwise, check if subtree exists in left or right subtree of root
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    /**
     * Helper function to check if two trees are identical.
     */
    bool sameTree(TreeNode* s, TreeNode* t) {
        // If both trees are empty → identical
        if (!s && !t) return true;

        // If both are non-null and values match → check subtrees
        if (s && t && s->val == t->val) {
            return sameTree(s->left, t->left) && sameTree(s->right, t->right);
        }

        // Otherwise → not identical
        return false;
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers in one line.

using namespace std;
    ✅ Allows you to write names like vector, cout without std:: prefix.

struct TreeNode {
    ✅ Defines a binary tree node structure.

int val;
    ✅ Holds the value of the current node.

TreeNode *left, *right;
    ✅ Pointers to left and right children of the node.

TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ✅ Default constructor: sets value = 0 and children = null.

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ✅ Constructor: initializes node with value x.

TreeNode(int x, TreeNode *left, TreeNode *right)
    ✅ Constructor: initializes node with value x and given left & right children.

class Solution {
    ✅ Defines the Solution class.

public:
    ✅ Public methods that can be called from outside the class.

bool isSubtree(TreeNode* root, TreeNode* subRoot)
    ✅ Function to check if subRoot is a subtree of root.

if (!subRoot) return true;
    ✅ If subRoot is null → always a subtree.

if (!root) return false;
    ✅ If root is null but subRoot is not → cannot be a subtree.

if (sameTree(root, subRoot)) return true;
    ✅ If the current trees rooted at root & subRoot are identical → return true.

return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    ✅ Otherwise, check recursively in left and right subtrees.

private:
    ✅ Helper functions (accessible only inside this class).

bool sameTree(TreeNode* s, TreeNode* t)
    ✅ Checks if two trees are identical.

if (!s && !t) return true;
    ✅ Both nodes null → identical.

if (s && t && s->val == t->val)
    ✅ Both exist and values are same → check children.

return sameTree(s->left, t->left) && sameTree(s->right, t->right);
    ✅ Both subtrees must also be identical.

return false;
    ✅ Otherwise → not identical.

*/

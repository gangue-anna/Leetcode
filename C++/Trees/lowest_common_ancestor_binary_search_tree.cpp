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
     * Finds the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.
     * 
     * Approach:
     * - Traverse starting from root.
     * - If both p and q are greater than current node, go to right child.
     * - If both are less than current node, go to left child.
     * - If they are on opposite sides or equal to current → current is LCA.
     *
     * Time Complexity: O(h), where h = height of the tree.
     * Space Complexity: O(1), iterative approach uses constant space.
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while (curr) {
            if (p->val > curr->val && q->val > curr->val) {
                // Both nodes are in the right subtree
                curr = curr->right;
            }
            else if (p->val < curr->val && q->val < curr->val) {
                // Both nodes are in the left subtree
                curr = curr->left;
            }
            else {
                // Nodes are on different sides or one is equal → LCA
                return curr;
            }
        }

        return nullptr; // Should never reach here if both nodes are guaranteed to exist
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers.

using namespace std;
    ✅ Allows you to use standard library names (like cout, vector) without std:: prefix.

struct TreeNode {
    ✅ Defines the binary tree node structure.

int val;
    ✅ Value stored in the node.

TreeNode *left, *right;
    ✅ Pointers to the left and right child nodes.

TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ✅ Default constructor: value=0, children=null.

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ✅ Constructor: initializes value with x, children=null.

TreeNode(int x, TreeNode *left, TreeNode *right)
    ✅ Constructor: initializes value with x, assigns left & right children.

class Solution {
    ✅ Defines the Solution class.

public:
    ✅ Public methods of the class.

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    ✅ Function to find the LCA of nodes p and q in the BST.

TreeNode* curr = root;
    ✅ Start traversal from the root.

while (curr) {
    ✅ Loop until current node becomes null.

if (p->val > curr->val && q->val > curr->val)
    ✅ Both nodes are greater than current → move right.

curr = curr->right;
    ✅ Move to right subtree.

else if (p->val < curr->val && q->val < curr->val)
    ✅ Both nodes are less than current → move left.

curr = curr->left;
    ✅ Move to left subtree.

else
    ✅ Nodes are on opposite sides or one matches → found LCA.

return curr;
    ✅ Return the lowest common ancestor.

return nullptr;
    ✅ Fallback: if not found (theoretically unreachable if inputs are valid).

*/

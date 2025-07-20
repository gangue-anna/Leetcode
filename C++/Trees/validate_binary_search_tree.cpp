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
     * Efficient Approach:
     * - Validate that each node's value is strictly between given bounds.
     * - Left subtree must have all nodes < current node.
     * - Right subtree must have all nodes > current node.
     * 
     * Time Complexity: O(N), each node visited once.
     * Space Complexity: O(H), where H is the height of the tree (recursion stack).
     */
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }

private:
    bool valid(TreeNode* node, long left, long right) {
        if (!node) return true;

        // Node's value must lie between left and right bounds
        if (!(left < node->val && node->val < right)) return false;

        // Recursively check left and right subtrees with updated bounds
        return valid(node->left, left, node->val) &&
               valid(node->right, node->val, right);
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers.

using namespace std;
    ✅ Allows writing std::vector, std::cout etc., without std:: prefix.

struct TreeNode {
    ✅ Defines the structure for a binary tree node.

int val;
    ✅ Integer value of this node.

TreeNode *left, *right;
    ✅ Pointers to left and right children.

TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ✅ Default constructor: value 0, children nullptr.

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ✅ Constructor that sets value and nullptr children.

TreeNode(int x, TreeNode *left, TreeNode *right)
    ✅ Constructor that sets value and given left/right children.

class Solution {
    ✅ Defines the Solution class.

public:
    ✅ Public functions accessible outside the class.

bool isValidBST(TreeNode* root)
    ✅ Function that starts the recursion with the entire tree and extreme bounds.

return valid(root, LONG_MIN, LONG_MAX);
    ✅ Calls helper with root and bounds (-∞, +∞) (LONG_MIN and LONG_MAX).

private:
    ✅ Private helper function only used internally.

bool valid(TreeNode* node, long left, long right)
    ✅ Recursive function that checks if the subtree rooted at `node` is a valid BST
       within the bounds (`left`, `right`).

if (!node) return true;
    ✅ Base case: null nodes are valid BSTs.

if (!(left < node->val && node->val < right)) return false;
    ✅ If node violates the BST property, return false.

return valid(node->left, left, node->val) &&
       valid(node->right, node->val, right);
    ✅ Recur on left subtree with updated upper bound (current value).
       Recur on right subtree with updated lower bound (current value).
       Both must be valid.

*/

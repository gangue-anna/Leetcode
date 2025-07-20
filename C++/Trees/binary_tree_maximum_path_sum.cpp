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
     * Finds the maximum path sum in a binary tree.
     * 
     * Approach:
     * - Use DFS to compute maximum path sum from each node.
     * - At each node:
     *      → compute left & right max path sums (ignoring negative paths).
     *      → update the global maximum if path through current node is better.
     *      → return max path sum starting from current node and going down one side (to parent).
     *
     * Time Complexity: O(N), where N = number of nodes (each node visited once).
     * Space Complexity: O(H), where H = height of tree (recursion stack).
     */
    int maxPathSum(TreeNode* root) {
        int res = root->val; // Initialize result with root's value
        dfs(root, res);
        return res;
    }

private:
    // Helper DFS function
    int dfs(TreeNode* node, int &res) {
        if (!node) return 0;

        int leftMax = max(0, dfs(node->left, res));  // max path sum on left (ignore if negative)
        int rightMax = max(0, dfs(node->right, res)); // max path sum on right (ignore if negative)

        // Path through current node (can include both left and right)
        res = max(res, node->val + leftMax + rightMax);

        // Return max path sum without split (for parent recursion)
        return node->val + max(leftMax, rightMax);
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers.

using namespace std;
    ✅ Avoids typing std:: everywhere.

struct TreeNode { ... }
    ✅ Defines the binary tree node structure with val, left, and right.

TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ✅ Default constructor initializes val to 0 and children to nullptr.

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ✅ Constructor with a value and null children.

TreeNode(int x, TreeNode *left, TreeNode *right)
    ✅ Constructor with a value and specific left & right children.

class Solution { ... }
    ✅ Defines the Solution class.

int maxPathSum(TreeNode* root)
    ✅ Public method to compute maximum path sum.

int res = root->val;
    ✅ Initialize result with root’s value.

dfs(root, res);
    ✅ Call helper function to perform DFS.

return res;
    ✅ Return the computed maximum path sum.

private:
    ✅ Defines private helper functions that can only be called internally.

int dfs(TreeNode* node, int &res)
    ✅ Recursive helper to compute maximum path sum at each node.
    ✅ Passes `res` by reference to keep track of global maximum.

if (!node) return 0;
    ✅ Base case: null node contributes 0.

int leftMax = max(0, dfs(node->left, res));
    ✅ Compute left max path sum, ignoring negative values.

int rightMax = max(0, dfs(node->right, res));
    ✅ Compute right max path sum, ignoring negative values.

res = max(res, node->val + leftMax + rightMax);
    ✅ Update global result if path through current node is better.

return node->val + max(leftMax, rightMax);
    ✅ Return max path sum without split for parent recursion.

*/

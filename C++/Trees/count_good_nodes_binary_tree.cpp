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
     * Counts the number of 'good' nodes in the binary tree.
     *
     * A node is good if no node on the path from the root to that node has a value greater than it.
     *
     * Approach:
     * - Use DFS recursively.
     * - Pass down the maximum value encountered so far.
     * - At each node, if its value >= maxSoFar, it's a good node.
     *
     * Time Complexity: O(n), where n is the number of nodes.
     * Space Complexity: O(h), where h is the height of the tree (due to recursion stack).
     */
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

private:
    // Helper function for DFS
    int dfs(TreeNode* node, int maxVal) {
        if (!node) return 0;

        int res = 0;

        if (node->val >= maxVal) {
            res = 1; // This node is good
        }

        // Update maxVal for the path
        maxVal = max(maxVal, node->val);

        // Recur on left and right subtrees
        res += dfs(node->left, maxVal);
        res += dfs(node->right, maxVal);

        return res;
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers in one line.

using namespace std;
    ✅ Allows usage of standard library names without writing std::.

struct TreeNode {
    ✅ Defines a binary tree node structure.

int val;
    ✅ Value of the node.

TreeNode *left, *right;
    ✅ Pointers to the left and right children.

TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ✅ Default constructor: value=0, children=nullptr.

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ✅ Constructor with value x and nullptr children.

TreeNode(int x, TreeNode *left, TreeNode *right)
    ✅ Constructor with value x, left and right pointers set.

class Solution {
    ✅ Defines a class that contains the solution.

public:
    ✅ Public access specifier.

int goodNodes(TreeNode* root)
    ✅ Function that starts the DFS and returns the count of good nodes.

return dfs(root, root->val);
    ✅ Calls the helper with the root and its value as the initial max.

private:
    ✅ Private helper function not accessible outside the class.

int dfs(TreeNode* node, int maxVal)
    ✅ Recursive DFS function taking current node and max seen so far.

if (!node) return 0;
    ✅ Base case: null node contributes 0.

int res = 0;
    ✅ Stores number of good nodes from current subtree.

if (node->val >= maxVal) res = 1;
    ✅ If current node's value >= max so far, count it as good.

maxVal = max(maxVal, node->val);
    ✅ Update the max value along the path.

res += dfs(node->left, maxVal);
res += dfs(node->right, maxVal);
    ✅ Recur on left and right subtrees and sum their results.

return res;
    ✅ Return the count for this subtree.

*/

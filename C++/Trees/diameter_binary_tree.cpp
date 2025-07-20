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
     * Returns the diameter (longest path between any two nodes) of the binary tree.
     *
     * Approach:
     * - Use DFS to compute the height of each subtree.
     * - At each node, update the max diameter as left height + right height + 2 (number of edges).
     *
     * Time Complexity: O(n) — visit every node once.
     * Space Complexity: O(h) — due to recursion stack (h = height of tree).
     */
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;  // to store maximum diameter found

        dfs(root, res);
        return res;
    }

private:
    /**
     * Helper DFS function: computes the height of subtree rooted at 'node'
     * and updates the diameter along the way.
     */
    int dfs(TreeNode* node, int& res) {
        if (!node) return -1;  // base case: empty node has height -1

        int left = dfs(node->left, res);   // height of left subtree
        int right = dfs(node->right, res); // height of right subtree

        // update maximum diameter if path through this node is larger
        res = max(res, 2 + left + right);

        return 1 + max(left, right);  // return height of this node
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ libraries (like <vector>, <queue>, <iostream>, etc.)

using namespace std;
    ✅ Allows using names like vector, cout without std:: prefix.

struct TreeNode {
    ✅ Defines a binary tree node structure.

int val;
    ✅ Value of the node.

TreeNode *left, *right;
    ✅ Pointers to the left and right child nodes.

TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ✅ Default constructor: sets val=0 and children to null.

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ✅ Constructor with value and null children.

TreeNode(int x, TreeNode *left, TreeNode *right)
    ✅ Constructor with value and specified children.

class Solution {
    ✅ Defines the Solution class.

public:
    ✅ Public methods accessible from outside the class.

int diameterOfBinaryTree(TreeNode* root)
    ✅ Function that calculates the diameter of the tree.

int res = 0;
    ✅ Variable to store the maximum diameter found.

dfs(root, res);
    ✅ Call helper function to start DFS traversal.

return res;
    ✅ Return the computed diameter.

private:
    ✅ Private helper methods only used internally.

int dfs(TreeNode* node, int& res)
    ✅ DFS helper function, also updates res.

if (!node) return -1;
    ✅ Base case: null node has height -1.

int left = dfs(node->left, res);
int right = dfs(node->right, res);
    ✅ Recursively compute heights of left and right subtrees.

res = max(res, 2 + left + right);
    ✅ Update the diameter if this path is longer.

return 1 + max(left, right);
    ✅ Return the height of this node.

*/

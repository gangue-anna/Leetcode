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
     * Find maximum depth of a binary tree using iterative DFS.
     *
     * Strategy:
     * - Use a stack to perform depth-first traversal.
     * - At each step, track the depth of the current node.
     * - Update the maximum depth whenever visiting a node.
     *
     * Time Complexity: O(n) — visit each node once.
     * Space Complexity: O(h) — maximum stack size equals height of tree.
     */
    int maxDepth(TreeNode* root) {
    if (!root) return 0;

    stack<pair<TreeNode*, int>> stk;
    stk.push({root, 1});
    int res = 0;

    while (!stk.empty()) {
        pair<TreeNode*, int> top = stk.top(); // C++11 style
        stk.pop();

        TreeNode* node = top.first;
        int depth = top.second;

        if (node) {
            res = max(res, depth);

            if (node->right) stk.push({node->right, depth + 1});
            if (node->left) stk.push({node->left, depth + 1});
        }
    }

    return res;

    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers (like <vector>, <stack>, <iostream> etc.)

using namespace std;
    ✅ Allows you to use standard library names without writing std:: before them.

struct TreeNode {
    ✅ Defines a structure to represent a binary tree node.

int val;
    ✅ Holds the integer value of the current node.

TreeNode *left, *right;
    ✅ Pointers to the left and right child nodes.

TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ✅ Default constructor: value = 0, children are null.

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ✅ Constructor with only value.

TreeNode(int x, TreeNode *left, TreeNode *right)
    ✅ Constructor with value and pointers to left and right children.

class Solution {
    ✅ Defines the Solution class.

public:
    ✅ Public methods that can be accessed outside the class.

int maxDepth(TreeNode* root)
    ✅ Function to compute the maximum depth of the binary tree.

if (!root) return 0;
    ✅ If root is null, tree is empty, depth is 0.

stack<pair<TreeNode*, int>> stk;
    ✅ Stack to store pairs of (node, depth).

stk.push({root, 1});
    ✅ Push the root node with depth 1.

int res = 0;
    ✅ Variable to store maximum depth found.

while (!stk.empty())
    ✅ Loop until the stack becomes empty.

auto [node, depth] = stk.top();
    ✅ Structured binding: get the top element (node & depth).

stk.pop();
    ✅ Remove the top element.

if (node)
    ✅ If the node is not null.

res = max(res, depth);
    ✅ Update the maximum depth if current depth is larger.

if (node->right) stk.push({node->right, depth + 1});
if (node->left) stk.push({node->left, depth + 1});
    ✅ Push right and left children with updated depth.

return res;
    ✅ Return the maximum depth of the tree.

*/

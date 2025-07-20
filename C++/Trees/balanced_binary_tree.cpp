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
     * Check if a binary tree is height-balanced.
     *
     * Approach:
     * - Use DFS to check if left and right subtrees are balanced.
     * - Also compute height of each subtree.
     * - A tree is balanced if:
     *    * left subtree is balanced
     *    * right subtree is balanced
     *    * |height(left) - height(right)| ≤ 1
     *
     * Time Complexity: O(n) — we visit every node once.
     * Space Complexity: O(h) — stack space for recursion, h = height of tree.
     */
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }

private:
    /**
     * Helper function.
     * Returns a pair: {is_balanced, height}
     */
    pair<bool, int> dfs(TreeNode* node) {
        if (!node) return {true, 0};  // base case: empty tree is balanced, height = 0

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        bool balanced = (left.first && right.first && abs(left.second - right.second) <= 1);
        int height = 1 + max(left.second, right.second);

        return {balanced, height};
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers in one line.

using namespace std;
    ✅ Lets you use standard library names without writing std:: explicitly.

struct TreeNode {
    ✅ Defines a binary tree node structure.

int val;
    ✅ Holds the value of the node.

TreeNode *left, *right;
    ✅ Pointers to left and right children of the node.

TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ✅ Default constructor: initializes value=0 and children to null.

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ✅ Constructor with value, children default to null.

TreeNode(int x, TreeNode *left, TreeNode *right)
    ✅ Constructor with value and given left/right children.

class Solution {
    ✅ Defines the Solution class.

public:
    ✅ Public methods accessible outside the class.

bool isBalanced(TreeNode* root)
    ✅ Checks if the tree rooted at 'root' is balanced.

return dfs(root).first;
    ✅ Calls the helper and returns the 'is_balanced' part of the result.

private:
    ✅ Private helper methods (not accessible outside the class).

pair<bool, int> dfs(TreeNode* node)
    ✅ Helper function returning {is_balanced, height}.

if (!node) return {true, 0};
    ✅ If the node is null: tree is balanced, height is 0.

auto left = dfs(node->left);
auto right = dfs(node->right);
    ✅ Recursively compute left and right subtree info.

bool balanced = (left.first && right.first && abs(left.second - right.second) <= 1);
    ✅ A tree is balanced if both subtrees are balanced and their heights differ ≤ 1.

int height = 1 + max(left.second, right.second);
    ✅ Height of current tree = 1 + max(left & right subtree heights).

return {balanced, height};
    ✅ Return the result for current node.

*/

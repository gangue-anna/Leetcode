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
     * Reconstructs binary tree from preorder and inorder traversal.
     *
     * Approach:
     * - First element of preorder is the root.
     * - Find root in inorder to split into left & right subtrees.
     * - Recurse on left and right subtrees.
     *
     * Time Complexity: O(n^2) (finding index in `inorder` at each level)
     * Space Complexity: O(n) (recursion stack + tree nodes)
     */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        // First element in preorder is always the root
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of root in inorder to split left & right subtrees
        auto it = find(inorder.begin(), inorder.end(), rootVal);
        int mid = distance(inorder.begin(), it);

        // Construct vectors for left & right subtrees
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + mid);
        vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
        vector<int> rightPre(preorder.begin() + 1 + mid, preorder.end());
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);

        return root;
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard headers.

using namespace std;
    ✅ Use standard namespace to avoid typing std:: everywhere.

struct TreeNode { ... }
    ✅ Defines the binary tree node structure.

TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ✅ Default constructor: value = 0, children = nullptr.

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ✅ Constructor with value, children = nullptr.

TreeNode(int x, TreeNode *left, TreeNode *right)
    ✅ Constructor with value and pointers to left & right child.

class Solution { ... }
    ✅ Defines the Solution class which contains buildTree.

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    ✅ Method to build binary tree from preorder & inorder.

if (preorder.empty() || inorder.empty())
    ✅ Base case: if input lists are empty, return nullptr.

int rootVal = preorder[0];
    ✅ The first element of preorder is the root value.

TreeNode* root = new TreeNode(rootVal);
    ✅ Create a new TreeNode with the root value.

auto it = find(inorder.begin(), inorder.end(), rootVal);
    ✅ Find iterator pointing to root in inorder list.

int mid = distance(inorder.begin(), it);
    ✅ Get index (distance from start) of root in inorder list.

vector<int> leftPre(...), leftIn(...), rightPre(...), rightIn(...)
    ✅ Create sub-vectors for left & right subtrees from preorder and inorder.

root->left = buildTree(leftPre, leftIn);
    ✅ Recursively build left subtree.

root->right = buildTree(rightPre, rightIn);
    ✅ Recursively build right subtree.

return root;
    ✅ Return the constructed tree's root.

*/

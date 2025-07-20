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
     * Return the rightmost node value at each level (right side view).
     *
     * Approach:
     * - Use BFS with a queue to traverse level by level.
     * - At each level, keep track of the last node encountered.
     * - After finishing each level, add that rightmost node's value to result.
     *
     * Time Complexity: O(n), where n = number of nodes.
     * Space Complexity: O(n), for queue and result vector.
     */
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;                      // Stores the rightmost nodes
        if (!root) return res;               // Empty tree => empty result

        queue<TreeNode*> q;                 // Queue for BFS
        q.push(root);

        while (!q.empty()) {
            int qLen = q.size();            // Number of nodes at current level
            TreeNode* rightSide = nullptr;  // To store rightmost node at this level

            for (int i = 0; i < qLen; ++i) {
                TreeNode* node = q.front(); // Get the front node
                q.pop();

                if (node) {
                    rightSide = node;       // Update rightmost node at this level
                    if (node->left) q.push(node->left);   // Push left child if exists
                    if (node->right) q.push(node->right); // Push right child if exists
                }
            }

            if (rightSide) res.push_back(rightSide->val); // Save rightmost node's value
        }

        return res;  // Return the final right side view
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers.

using namespace std;
    ✅ Allows you to use names from the standard library without `std::` prefix.

struct TreeNode {
    ✅ Defines a binary tree node.

int val;
    ✅ Value of the node.

TreeNode *left, *right;
    ✅ Pointers to the left and right children.

TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ✅ Default constructor: value = 0, children = null.

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ✅ Constructor that initializes node with value x.

TreeNode(int x, TreeNode *left, TreeNode *right)
    ✅ Constructor that initializes node with value x and specific children.

class Solution {
    ✅ Defines a class with the solution method.

public:
    ✅ Public access specifier.

vector<int> rightSideView(TreeNode* root)
    ✅ Function returning a vector of integers representing right side view.

vector<int> res;
    ✅ Vector to store rightmost nodes' values.

if (!root) return res;
    ✅ If the tree is empty, return empty vector.

queue<TreeNode*> q;
    ✅ Queue for BFS traversal.

q.push(root);
    ✅ Push root node to start BFS.

while (!q.empty()) {
    ✅ Process nodes level by level as long as queue is not empty.

int qLen = q.size();
    ✅ Number of nodes at current level.

TreeNode* rightSide = nullptr;
    ✅ Pointer to store rightmost node at current level.

for (int i = 0; i < qLen; ++i) {
    ✅ Loop through all nodes at current level.

TreeNode* node = q.front();
    ✅ Get the front node from the queue.

q.pop();
    ✅ Remove the front node from queue.

if (node) {
    ✅ If node is not null.

rightSide = node;
    ✅ Update rightmost node.

if (node->left) q.push(node->left);
    ✅ If left child exists, add to queue.

if (node->right) q.push(node->right);
    ✅ If right child exists, add to queue.

if (rightSide) res.push_back(rightSide->val);
    ✅ After level ends, add rightmost node's value to result.

return res;
    ✅ Return the result vector.

*/

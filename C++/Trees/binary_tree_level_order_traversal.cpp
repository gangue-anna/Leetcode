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
     * Perform level order (BFS) traversal of a binary tree.
     *
     * Approach:
     * - Use a queue to keep track of nodes at the current level.
     * - Process each level fully before moving to the next.
     * - Collect values of each level into a vector.
     *
     * Time Complexity: O(n), where n = number of nodes (each node is visited once)
     * Space Complexity: O(n), for the queue and result storage
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;          // To store the final result
        if (!root) return res;           // If tree is empty, return empty vector

        queue<TreeNode*> q;              // Queue to facilitate BFS
        q.push(root);                    // Start with the root node

        while (!q.empty()) {            // Continue until all nodes are processed
            int qLen = q.size();         // Number of nodes at current level
            vector<int> level;           // To store values of current level

            for (int i = 0; i < qLen; ++i) {
                TreeNode* node = q.front(); // Get the front node in the queue
                q.pop();                    // Remove it from queue

                level.push_back(node->val); // Add its value to current level

                if (node->left) q.push(node->left);   // Add left child if exists
                if (node->right) q.push(node->right); // Add right child if exists
            }

            res.push_back(level);         // Add current level to result
        }

        return res;                       // Return the complete level order traversal
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers.

using namespace std;
    ✅ Allows standard library names without prefix (like vector, queue, cout).

struct TreeNode {
    ✅ Defines a binary tree node structure.

int val;
    ✅ Value of the node.

TreeNode *left, *right;
    ✅ Pointers to the left and right child nodes.

TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ✅ Default constructor: initializes val=0, children=null.

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ✅ Constructor: initializes value with x.

TreeNode(int x, TreeNode *left, TreeNode *right)
    ✅ Constructor: initializes value, left, and right pointers.

class Solution {
    ✅ Defines a class containing the solution function.

public:
    ✅ Public access modifier: method is accessible outside the class.

vector<vector<int>> levelOrder(TreeNode* root)
    ✅ Function that returns a 2D vector (list of levels).

vector<vector<int>> res;
    ✅ Vector to store the result.

if (!root) return res;
    ✅ If the tree is empty, return empty result.

queue<TreeNode*> q;
    ✅ Declare a queue to facilitate BFS traversal.

q.push(root);
    ✅ Push the root node to start BFS.

while (!q.empty()) {
    ✅ Loop as long as there are nodes in the queue.

int qLen = q.size();
    ✅ Get number of nodes at current level.

vector<int> level;
    ✅ Vector to hold current level's node values.

for (int i = 0; i < qLen; ++i) {
    ✅ Process all nodes at current level.

TreeNode* node = q.front();
    ✅ Get the node at the front of the queue.

q.pop();
    ✅ Remove the front node from the queue.

level.push_back(node->val);
    ✅ Add node's value to current level.

if (node->left) q.push(node->left);
    ✅ If left child exists, add it to queue.

if (node->right) q.push(node->right);
    ✅ If right child exists, add it to queue.

res.push_back(level);
    ✅ Append the level to result.

return res;
    ✅ Return the final level-order traversal.

*/

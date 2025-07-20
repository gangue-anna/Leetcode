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
     * Finds the k-th smallest element in a BST.
     * 
     * Approach:
     * - Use an iterative in-order traversal (left-root-right) using a stack.
     * - In-order traversal of BST gives nodes in ascending order.
     * - Count nodes while traversing; when count == k, return the node's value.
     *
     * Time Complexity: O(H + k), where H is the height of the tree.
     * Space Complexity: O(H), stack space.
     */
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;  // stack to store nodes
        TreeNode* curr = root;
        int count = 0;

        while (curr != nullptr || !st.empty()) {
            // Go as left as possible
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // Visit the node
            curr = st.top(); st.pop();
            count++;

            if (count == k) {
                return curr->val;
            }

            // Move to right subtree
            curr = curr->right;
        }

        // If k is invalid (greater than number of nodes)
        throw invalid_argument("k is larger than the number of nodes in the tree");
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers.

using namespace std;
    ✅ Allows using std::vector, std::stack etc., without std:: prefix.

struct TreeNode {
    ✅ Defines a structure for a binary tree node.

int val;
    ✅ Holds the value of the node.

TreeNode *left, *right;
    ✅ Pointers to left and right child nodes.

TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ✅ Default constructor, value 0, no children.

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ✅ Constructor: sets value to x, no children.

TreeNode(int x, TreeNode *left, TreeNode *right)
    ✅ Constructor: sets value and given left/right pointers.

class Solution {
    ✅ Defines the Solution class.

public:
    ✅ Public functions accessible outside the class.

int kthSmallest(TreeNode* root, int k)
    ✅ Function to find the k-th smallest element.

stack<TreeNode*> st;
    ✅ Stack to simulate recursion for in-order traversal.

TreeNode* curr = root;
    ✅ Start traversal at root.

int count = 0;
    ✅ Counter for visited nodes.

while (curr != nullptr || !st.empty())
    ✅ Loop as long as there are nodes left to process.

while (curr != nullptr)
    ✅ Go to the leftmost node.

st.push(curr);
    ✅ Save current node in the stack.

curr = curr->left;
    ✅ Move to left child.

curr = st.top(); st.pop();
    ✅ Visit the top node from stack.

count++;
    ✅ Increment the counter.

if (count == k) return curr->val;
    ✅ If k-th node reached, return its value.

curr = curr->right;
    ✅ Otherwise, move to right subtree.

throw invalid_argument("...")
    ✅ If k > number of nodes, throw an exception.

*/

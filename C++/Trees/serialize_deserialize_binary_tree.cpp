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

class Codec {
public:
    /**
     * Serializes a tree to a single string.
     * 
     * Approach:
     * - Use preorder DFS traversal.
     * - If a node is null, append "N" to the string.
     * - Otherwise, append its value and recursively process left and right children.
     * 
     * Time: O(n) — visits every node once.
     * Space: O(n) — stores the result string and recursion stack.
     */
    string serialize(TreeNode* root) {
        string res;
        dfsSerialize(root, res);
        if (!res.empty() && res.back() == ',') res.pop_back(); // remove trailing comma
        return res;
    }

    /**
     * Deserializes a string to a tree.
     * 
     * Approach:
     * - Split the string on commas into tokens.
     * - Use a helper function to construct the tree recursively.
     * - Increment index as you consume tokens.
     * 
     * Time: O(n) — visits every node once.
     * Space: O(n) — recursion stack + tokens vector.
     */
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        int index = 0;
        return dfsDeserialize(tokens, index);
    }

private:
    void dfsSerialize(TreeNode* node, string &res) {
        if (!node) {
            res += "N,";
            return;
        }
        res += to_string(node->val) + ",";
        dfsSerialize(node->left, res);
        dfsSerialize(node->right, res);
    }

    TreeNode* dfsDeserialize(vector<string> &tokens, int &i) {
        if (i >= tokens.size() || tokens[i] == "N") {
            i++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(tokens[i++]));
        node->left = dfsDeserialize(tokens, i);
        node->right = dfsDeserialize(tokens, i);
        return node;
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers.

using namespace std;
    ✅ Avoids prefixing standard library names with std::.

struct TreeNode { ... }
    ✅ Defines a binary tree node with int val, and left & right pointers.

TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ✅ Default constructor initializes val=0 and children to nullptr.

TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ✅ Constructor that sets val=x.

TreeNode(int x, TreeNode *left, TreeNode *right)
    ✅ Constructor that sets val=x, left, and right children.

class Codec { ... }
    ✅ Defines the Codec class with public & private methods.

string serialize(TreeNode* root)
    ✅ Public method that serializes tree into a string.

dfsSerialize(root, res);
    ✅ Helper method that appends node values to res string.

if (!node) { res += "N,"; return; }
    ✅ If node is null, add "N" and stop.

res += to_string(node->val) + ",";
    ✅ Append node’s value as string.

TreeNode* deserialize(string data)
    ✅ Public method to deserialize a string back into tree.

stringstream ss(data);
    ✅ Create stream to split string by ','.

getline(ss, token, ',')
    ✅ Read tokens one by one until end.

int index = 0;
    ✅ Start at first token.

dfsDeserialize(tokens, index);
    ✅ Build tree recursively.

if (tokens[i] == "N")
    ✅ If token is "N", return nullptr.

TreeNode* node = new TreeNode(stoi(tokens[i++]));
    ✅ Create new node from integer value.

node->left = dfsDeserialize(tokens, i);
node->right = dfsDeserialize(tokens, i);
    ✅ Build left & right children recursively.

return node;
    ✅ Return the rebuilt tree node.

*/

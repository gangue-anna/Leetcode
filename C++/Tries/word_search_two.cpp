#include <bits/stdc++.h>
using namespace std;

// Trie Node class
class TrieNode {
public:
    unordered_map<char, TrieNode*> children; // maps each character to its child node
    bool isWord;                             // flag to mark end of a word

    TrieNode() {
        isWord = false;
    }

    // Function to insert a word into the Trie
    void addWord(const string& word) {
        TrieNode* curr = this;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        /*
        Approach:
        - Build a Trie with all words.
        - Start DFS from each cell to explore possible words.
        - Use a set to store unique results.
        - Backtrack properly to unmark visited cells.

        Time Complexity:
        - Building Trie: O(S), where S = total length of all words.
        - DFS: O(M * N * 4^L), where M,N = board size, L = max word length.
        Total: O(S + M * N * 4^L)

        Space Complexity:
        - Trie: O(S)
        - Visited set: O(M*N)
        - Recursion stack: O(L)
        */

        TrieNode* root = new TrieNode();

        // Insert all words into the Trie
        for (const string& word : words) {
            root->addWord(word);
        }

        int ROWS = board.size();
        int COLS = board[0].size();

        set<string> res;                // to avoid duplicates
        vector<vector<bool>> visit(ROWS, vector<bool>(COLS, false)); // visited cells

        // DFS function
        function<void(int, int, TrieNode*, string)> dfs =
            [&](int r, int c, TrieNode* node, string word) {
                // boundary or visited or char not in trie
                if (r < 0 || c < 0 || r >= ROWS || c >= COLS || visit[r][c] ||
                    node->children.find(board[r][c]) == node->children.end()) {
                    return;
                }

                visit[r][c] = true;
                node = node->children[board[r][c]];
                word += board[r][c];

                if (node->isWord) {
                    res.insert(word);
                }

                // explore 4 directions
                dfs(r - 1, c, node, word);
                dfs(r + 1, c, node, word);
                dfs(r, c - 1, node, word);
                dfs(r, c + 1, node, word);

                visit[r][c] = false; // backtrack
            };

        // Start DFS from each cell
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                dfs(r, c, root, "");
            }
        }

        return vector<string>(res.begin(), res.end());
    }
};

/*
================ LINE BY LINE SYNTAX EXPLANATION =====================

#include <bits/stdc++.h>
- Includes all standard C++ libraries.

using namespace std;
- Avoids prefixing std:: everywhere.

class TrieNode
- Defines a class to represent each node in the Trie.

unordered_map<char, TrieNode*> children;
- Maps each character to its corresponding child TrieNode.

bool isWord;
- Marks if the current node is the end of a valid word.

TrieNode()
- Constructor initializing isWord to false.

void addWord(const string& word)
- Inserts a word into the Trie.

TrieNode* curr = this;
- Pointer to traverse the Trie starting from root.

if (curr->children.find(c) == curr->children.end())
- If the character c is not a child, create a new TrieNode.

curr = curr->children[c];
- Move to the child node.

curr->isWord = true;
- After the last character, mark this node as a word.

class Solution
- Main solution class.

vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
- Main function to find all words.

TrieNode* root = new TrieNode();
- Create an empty Trie.

for (const string& word : words)
- Loop over all words to insert into Trie.

int ROWS = board.size(), COLS = board[0].size();
- Get board dimensions.

set<string> res;
- To store unique found words.

vector<vector<bool>> visit(ROWS, vector<bool>(COLS, false));
- 2D vector to keep track of visited cells.

function<void(int, int, TrieNode*, string)> dfs =
- Define a recursive lambda function for DFS.

if (r < 0 || c < 0 || r >= ROWS || c >= COLS || visit[r][c] ...)
- Base case: out of bounds, already visited, or invalid path.

visit[r][c] = true;
- Mark current cell as visited.

word += board[r][c];
- Append current character to the path.

if (node->isWord)
- If this node marks the end of a word, add to result.

dfs(r-1, c, node, word), dfs(r+1, c, node, word) ...
- Recursively explore all 4 directions.

visit[r][c] = false;
- Backtrack by unmarking the current cell.

for (int r = 0; r < ROWS; ++r)
- Start DFS from every cell in the board.

return vector<string>(res.begin(), res.end());
- Convert set to vector and return.

=======================================================================
*/


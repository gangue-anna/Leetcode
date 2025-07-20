#include <bits/stdc++.h>
using namespace std;

// TrieNode class to represent each node of the Trie
class TrieNode {
public:
    unordered_map<char, TrieNode*> children; // maps character to next node
    bool word; // marks if this node represents end of a word

    TrieNode() {
        word = false; // initially not the end of any word
    }
};

class WordDictionary {
private:
    TrieNode* root;

    /**
     * Recursive DFS helper to search for a word/pattern.
     * Handles '.' wildcard which matches any character.
     */
    bool dfs(int j, string& word, TrieNode* curr) {
        for (int i = j; i < word.size(); ++i) {
            char c = word[i];

            if (c == '.') {
                // Wildcard: try all possible children
                for (auto& p : curr->children) {
                    TrieNode* child = p.second;
                    if (dfs(i + 1, word, child)) {
                        return true;
                }   
}
                return false; // no matching path
            } else {
                // Regular character
                if (curr->children.find(c) == curr->children.end()) {
                    return false; // path does not exist
                }
                curr = curr->children[c];
            }
        }
        return curr->word; // reached end of word?
    }

public:
    /**
     * WordDictionary: Trie with support for '.' wildcard in search.
     * 
     * Time Complexity:
     *  - addWord: O(m), m = length of the word
     *  - search: O(26^m) worst case (due to wildcards), O(m) best case
     * 
     * Space Complexity:
     *  - Worst: O(ALPHABET_SIZE * N * M)
     */

    WordDictionary() {
        root = new TrieNode(); // initialize root node
    }

    /**
     * Adds a word into the Trie.
     * Time: O(m)
     * Space: O(m) in worst case when creating all new nodes
     */
    void addWord(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->word = true; // mark end of word
    }

    /**
     * Searches for a word or pattern (with '.' wildcard).
     * Time: O(26^m) worst case, O(m) best case
     * Space: O(m) due to recursion
     */
    bool search(string word) {
        return dfs(0, word, root);
    }
};


/*
=======================================================================
Line-by-line Explanation:
-----------------------------------------------------------------------

#include <bits/stdc++.h>
- Includes all standard C++ libraries.

using namespace std;
- Avoids writing std:: repeatedly.

class TrieNode {
- Defines a TrieNode that holds children and a flag for end-of-word.

unordered_map<char, TrieNode*> children;
- Maps a character to its child TrieNode.

bool word;
- Indicates if this node is the end of a valid word.

TrieNode() { word = false; }
- Constructor initializes word = false.

class WordDictionary {
- Defines the WordDictionary class with all required methods.

TrieNode* root;
- Pointer to the root of the Trie.

bool dfs(int j, string& word, TrieNode* curr)
- Helper function to recursively search for the word.
- Handles '.' by iterating through all children.

WordDictionary() {
  root = new TrieNode();
}
- Initializes the root node when creating a WordDictionary.

void addWord(string word)
- Inserts a word into the Trie.

bool search(string word)
- Searches for a word in the Trie, calling dfs().

for (char c : word)
- Range-based loop over characters of the word.

if (curr->children.find(c) == curr->children.end())
- Checks if character c exists in children map.

curr->children[c] = new TrieNode();
- Creates a new TrieNode if not present.

return dfs(0, word, root);
- Starts DFS traversal at index 0 from root.

for (auto& p : curr->children) 
    // Iterates over all children nodes (p.second is the child TrieNode*).

=======================================================================
Time Complexity:
-----------------------------------------------------------------------
addWord:  O(m), where m = length of word.
search:   O(26^m) worst case (due to wildcards), O(m) best case.

Space Complexity:
-----------------------------------------------------------------------
- Worst case: O(ALPHABET_SIZE * N * M)
  where:
  ALPHABET_SIZE = number of possible characters (26 for lowercase),
  N = number of words,
  M = average length of words.
- Recursion stack in search adds O(m) space.

=======================================================================
*/


#include <bits/stdc++.h>
using namespace std;

// TrieNode class to represent each node of the Trie
class TrieNode {
public:
    unordered_map<char, TrieNode*> children; // map from character to next TrieNode
    bool endOfWord; // marks if the current node is the end of a word

    TrieNode() {
        endOfWord = false; // initialize endOfWord to false
    }
};

class PrefixTree {
private:
    TrieNode* root; // root of the Trie

public:
    /**
     * Trie (Prefix Tree) implementation.
     * Supports insert, search, and startsWith operations.
     * 
     * Time Complexity:
     *   - insert: O(m), where m = length of the word
     *   - search: O(m)
     *   - startsWith: O(m)
     * 
     * Space Complexity:
     *   - Worst case: O(ALPHABET_SIZE * N * M)
     *     (each node can have up to 26 pointers, for N words each of length M)
     */

    PrefixTree() {
        root = new TrieNode(); // initialize root
    }

    // Inserts a word into the trie
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode(); // create new node if not exists
            }
            curr = curr->children[c]; // move to next node
        }
        curr->endOfWord = true; // mark end of the word
    }

    // Returns true if the word exists in the trie
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false; // if character not found
            }
            curr = curr->children[c];
        }
        return curr->endOfWord; // only true if it's end of a word
    }

    // Returns true if any word in the trie starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false; // prefix does not exist
            }
            curr = curr->children[c];
        }
        return true; // prefix exists
    }
};


/*
============================================================
Line-by-line Explanation:
------------------------------------------------------------

#include <bits/stdc++.h>
- Includes all standard C++ libraries.

using namespace std;
- Avoids writing std:: repeatedly.

class TrieNode {
- Defines a TrieNode class to represent each node of the Trie.

unordered_map<char, TrieNode*> children;
- Maps a character to its corresponding child node.

bool endOfWord;
- Marks whether this node represents the end of a word.

TrieNode() { endOfWord = false; }
- Constructor initializes endOfWord to false.

class PrefixTree {
- Defines the PrefixTree class which contains all operations.

TrieNode* root;
- Pointer to the root node of the Trie.

PrefixTree() {
  root = new TrieNode();
}
- Constructor initializes the root node.

void insert(string word) {
- Inserts a word into the Trie.

for (char c : word) {
  if (curr->children.find(c) == curr->children.end()) {
      curr->children[c] = new TrieNode();
  }
  curr = curr->children[c];
}
- Traverse or create nodes for each character of the word.

curr->endOfWord = true;
- Mark the last node as the end of the word.

bool search(string word) {
- Checks if a word exists in the Trie.

bool startsWith(string prefix) {
- Checks if any word starts with the given prefix.

return true;
- If we reach the end of the prefix, it exists.

============================================================
Time Complexity:
------------------------------------------------------------
insert:      O(m), where m = length of the word.
search:      O(m)
startsWith:  O(m)

Space Complexity:
------------------------------------------------------------
- Worst case: O(ALPHABET_SIZE * N * M)
  where:
  ALPHABET_SIZE = number of possible characters (e.g., 26 for lowercase letters),
  N = number of words,
  M = average length of words.

============================================================
*/


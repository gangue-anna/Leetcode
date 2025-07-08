class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False

class PrefixTree:
    """
    Trie (Prefix Tree) implementation supporting insert, search, and prefix search.
    Time Complexity:
        - insert: O(m) where m is the length of the word
        - search: O(m)
        - startsWith: O(m)
    Space Complexity:
        - O(ALPHABET_SIZE * N * M) in worst case
    """
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.endOfWord = True

    def search(self, word: str) -> bool:
        curr = self.root
        for c in word:
            if c not in curr.children:
                return False
            curr = curr.children[c]
        return curr.endOfWord
    
    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        for c in prefix:
            if c not in curr.children:
                return False
            curr = curr.children[c]
        return True

# -------------------
# Test Cases
# -------------------
def test_prefix_tree():
    trie = PrefixTree()
    trie.insert("apple")
    trie.insert("app")
    trie.insert("banana")
    trie.insert("")  # Insert empty string
    # Exact search
    assert trie.search("apple") == True
    assert trie.search("app") == True
    assert trie.search("banana") == True
    assert trie.search("") == True
    # Not present
    assert trie.search("appl") == False
    assert trie.search("ban") == False
    assert trie.search("bananaa") == False
    # Prefix search
    assert trie.startsWith("app") == True
    assert trie.startsWith("ban") == True
    assert trie.startsWith("") == True
    assert trie.startsWith("a") == True
    assert trie.startsWith("b") == True
    assert trie.startsWith("c") == False
    print("All test cases passed!")

if __name__ == "__main__":
    test_prefix_tree()        
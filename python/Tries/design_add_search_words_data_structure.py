class TrieNode:
    """
    Represents a node in the Trie data structure for Word Dictionary.
    
    Attributes:
        children (dict): Dictionary mapping characters to child TrieNodes
        word (bool): Flag indicating if this node represents the end of a word
    """
    def __init__(self):
        self.children = {} 
        self.word = False

class WordDictionary:
    """
    Implementation of a Word Dictionary that supports adding words and searching with wildcards.
    
    This data structure extends the basic Trie to support pattern matching with '.' wildcards.
    It's useful for:
    - Autocomplete with partial matching
    - Pattern matching in text processing
    - Word games like Wordle
    - Search functionality with wildcards
    
    Time Complexity:
        - addWord: O(m) where m is the length of the word
        - search: O(26^m) in worst case where m is the length of the word
                 (due to wildcard '.' that can match any character)
                 O(m) in best case when no wildcards are present
    
    Space Complexity:
        - O(ALPHABET_SIZE * N * M) where:
          - ALPHABET_SIZE is the number of possible characters (26 for lowercase letters)
          - N is the number of words
          - M is the average length of words
        - In worst case: O(ALPHABET_SIZE * N * M) when no words share prefixes
        - In best case: O(ALPHABET_SIZE * M) when all words share the same prefix
    """

    def __init__(self):
        """
        Initialize an empty Word Dictionary with a root node.
        
        Time Complexity: O(1)
        Space Complexity: O(1)
        """
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        """
        Add a word to the dictionary.
        
        Algorithm:
        1. Start from the root node
        2. For each character in the word:
           - If the character doesn't exist as a child, create a new TrieNode
           - Move to the child node
        3. Mark the final node as the end of a word
        
        Args:
            word (str): The word to add to the dictionary
            
        Time Complexity: O(m) where m is the length of the word
        Space Complexity: O(m) in worst case when no existing path exists
        """
        curr = self.root

        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.word = True

    def search(self, word: str) -> bool:
        """
        Search for a word in the dictionary. Supports '.' wildcard that matches any character.
        
        Algorithm:
        1. Use DFS to traverse the Trie
        2. For each character in the search pattern:
           - If it's a '.', try all possible children recursively
           - If it's a regular character, follow that specific path
        3. Return True if we reach the end and the final node is marked as end of word
        
        Args:
            word (str): The word/pattern to search for (can contain '.' wildcards)
            
        Returns:
            bool: True if the word/pattern exists in the dictionary, False otherwise
            
        Time Complexity: O(26^m) in worst case where m is the length of the word
                        (when the word contains many '.' wildcards)
                        O(m) in best case when no wildcards are present
        Space Complexity: O(m) due to recursion stack depth
        """
        def dfs(j, root):
            curr = root
            
            for i in range(j, len(word)):
                c = word[i]

                if c == ".":
                    # Wildcard case: try all possible children
                    for child in curr.children.values():
                        if dfs(i + 1, child):
                            return True
                    return False
                else:
                    # Regular character case: follow specific path
                    if c not in curr.children:
                        return False
                    curr = curr.children[c]
            return curr.word
        
        return dfs(0, self.root)

# -------------------
# Test Cases
# -------------------
def test_word_dictionary():
    wd = WordDictionary()
    # Add words
    wd.addWord("bad")
    wd.addWord("dad")
    wd.addWord("mad")
    wd.addWord("pad")
    wd.addWord("baddy")
    wd.addWord("")  # Add empty string
    # Exact matches
    assert wd.search("bad") == True
    assert wd.search("dad") == True
    assert wd.search("mad") == True
    assert wd.search("pad") == True
    assert wd.search("baddy") == True
    assert wd.search("") == True
    # Not present
    assert wd.search("badd") == False
    assert wd.search("bads") == False
    assert wd.search("b") == False
    # Wildcard matches
    assert wd.search(".ad") == True
    assert wd.search("b..") == True
    assert wd.search("..d") == True
    assert wd.search("baddy") == True
    assert wd.search("ba..y") == True
    assert wd.search(".....") == True
    assert wd.search("..") == False
    # Wildcard not present
    assert wd.search("..z") == False
    # Edge cases
    assert wd.search(".") == False
    assert wd.search("....") == False
    print("All test cases passed!")

if __name__ == "__main__":
    test_word_dictionary()
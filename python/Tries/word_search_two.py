from typing import List

class Trienode:
    def __init__(self):
        # Dictionary to store child nodes for each character
        self.children = {}
        # Flag to indicate if this node represents the end of a word
        self.isWord = False
    
    def addWord(self, word):
        # Add a word to the trie
        curr = self
        for c in word:
            # Create a new node if the character doesn't exist
            if c not in curr.children:
                curr.children[c] = Trienode()
            curr = curr.children[c]
        # Mark the end of the word
        curr.isWord = True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        """
        Finds all words from the list that can be formed in the board by sequentially adjacent letters.
        Uses a Trie for efficient prefix search and DFS for board traversal.
        Time Complexity: O(N * 4^L), where N is the number of cells and L is the max word length.
        Space Complexity: O(T + N), where T is total Trie nodes and N is the board size.
        """
        # Create the root of the trie
        root = Trienode()
        # Add all words to the trie
        for w in words:
            root.addWord(w)
        ROWS, COLS = len(board), len(board[0])
        # Set to store found words (using set to avoid duplicates)
        res, visit = set(), set()
        def dfs(r, c, node, word):
            # Base case: out of bounds, already visited, or character not in trie
            if (r < 0 or c < 0 or 
                r == ROWS or c == COLS or 
                (r,c) in visit or board[r][c] not in node.children):
                return 
            # Mark current position as visited
            visit.add((r, c))
            # Move to the child node for the current character
            node = node.children[board[r][c]]
            # Add current character to the word
            word += board[r][c]
            # If we've found a complete word, add it to results
            if node.isWord:
                res.add(word)
            # Explore all four directions: up, down, left, right
            dfs(r - 1, c, node, word)
            dfs(r + 1, c, node, word)
            dfs(r, c - 1, node, word)
            dfs(r, c + 1, node, word)
            # Backtrack: unmark current position
            visit.remove((r, c))
        # Start DFS from every cell in the board
        for r in range(ROWS):
            for c in range(COLS):
                dfs(r, c, root, "")
        return list(res)

# -------------------
# Test Cases
# -------------------
def test_find_words():
    s = Solution()
    # Test case 1: Example
    board = [
        ["o","a","a","n"],
        ["e","t","a","e"],
        ["i","h","k","r"],
        ["i","f","l","v"]
    ]
    words = ["oath","pea","eat","rain"]
    result = s.findWords(board, words)
    assert set(result) == {"oath", "eat"}
    # Test case 2: Single letter board and word
    board = [["a"]]
    words = ["a", "b"]
    result = s.findWords(board, words)
    assert set(result) == {"a"}
    # Test case 3: No words found
    board = [["a","b"],["c","d"]]
    words = ["efg","xyz"]
    result = s.findWords(board, words)
    assert set(result) == set()
    # Test case 4: All words found
    board = [["a","b"],["c","d"]]
    words = ["ab","ac","ad","bd","cd","abc","abcd"]
    result = s.findWords(board, words)
    assert set(result) == {"ab","bd","cd"}
    # Test case 5: Empty board
    board = []
    words = ["a"]
    try:
        s.findWords(board, words)
        assert False, "Should raise IndexError"
    except Exception:
        pass
    print("All test cases passed!")

if __name__ == "__main__":
    test_find_words()
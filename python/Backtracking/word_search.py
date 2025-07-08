from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        """
        Approach:
        - Use backtracking (DFS) to search for the word in the board.
        - For each cell, start a DFS if the first letter matches.
        - At each step, mark the cell as visited (using a set), and try all four directions.
        - If the word is found, return True. If not, backtrack and try other paths.
        - Restore the cell's state after backtracking.

        Time Complexity: O(m * n * 4^L), where m and n are the board dimensions and L is the length of the word.
        Space Complexity: O(L), for the recursion stack and path set.
        """
        ROWS, COLS = len(board), len(board[0])
        path = set()

        def dfs(r, c, i):
            if i == len(word):
                return True
            if (r < 0 or c < 0 or r >= ROWS or c >= COLS or word[i] != board[r][c] or (r,c) in path):
                return False

            path.add((r, c))
            res = (dfs(r + 1, c, i + 1) or dfs(r - 1, c, i + 1) or dfs(r, c + 1, i + 1) or dfs(r, c - 1, i + 1)) 

            path.remove((r,c))
            return res
        
        for r in range(ROWS):
            for c in range(COLS):
                if dfs(r, c, 0):
                    return True
        return False

# -------------------
# Test Cases
# -------------------
def test_word_search():
    sol = Solution()
    # Test case 1: Example from Leetcode
    board1 = [
        ["A","B","C","E"],
        ["S","F","C","S"],
        ["A","D","E","E"]
    ]
    assert sol.exist(board1, "ABCCED") == True
    assert sol.exist(board1, "SEE") == True
    assert sol.exist(board1, "ABCB") == False
    # Test case 2: Single letter
    board2 = [["A"]]
    assert sol.exist(board2, "A") == True
    assert sol.exist(board2, "B") == False
    # Test case 3: Word longer than board
    board3 = [["A","B"],["C","D"]]
    assert sol.exist(board3, "ABCDE") == False
    print("All test cases passed!")

if __name__ == "__main__":
    test_word_search()
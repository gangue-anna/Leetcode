from typing import List

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Approach:
        - Use DFS to mark unsurrounded 'O's (connected to the border) as temporary ('T').
        - Convert all remaining 'O's (surrounded) to 'X'.
        - Convert all 'T's back to 'O'.
        - This ensures only surrounded regions are captured.

        Time Complexity: O(m * n), where m and n are the board dimensions (each cell visited at most once).
        Space Complexity: O(m * n), for the recursion stack in the worst case.
        """
        rows, cols = len(board), len(board[0])

        def capture(r, c):
            if (r < 0 or c < 0 or r == rows or c == cols or board[r][c] != 'O'):
                return
            board[r][c] = 'T'
            capture(r + 1, c)
            capture(r - 1, c)
            capture(r, c + 1)
            capture(r, c - 1)
                 
        # 1. (DFS) Capture unsurrounded regions (O -> T)
        for r in range(rows):
            for c in range(cols):
                if (board[r][c] == 'O' and (r in [0, rows - 1] or c in [0, cols - 1])):
                    capture(r, c)

        # 2. Capture the surrounded regions (O -> X)
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == "O":
                    board[r][c] = 'X'

        # 3. Uncapture unsurrounded regions (T -> O)
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == "T":
                    board[r][c] = 'O'

# -------------------
# Test Cases
# -------------------
def test_solve_surrounded_regions():
    sol = Solution()
    # Test case 1: Example from Leetcode
    board1 = [
        ["X","X","X","X"],
        ["X","O","O","X"],
        ["X","X","O","X"],
        ["X","O","X","X"]
    ]
    sol.solve(board1)
    assert board1 == [
        ["X","X","X","X"],
        ["X","X","X","X"],
        ["X","X","X","X"],
        ["X","O","X","X"]
    ]
    # Test case 2: All 'O's
    board2 = [["O","O"],["O","O"]]
    sol.solve(board2)
    assert board2 == [["O","O"],["O","O"]]
    # Test case 3: All 'X's
    board3 = [["X","X"],["X","X"]]
    sol.solve(board3)
    assert board3 == [["X","X"],["X","X"]]
    # Test case 4: Surrounded single 'O'
    board4 = [["X","X","X"],["X","O","X"],["X","X","X"]]
    sol.solve(board4)
    assert board4 == [["X","X","X"],["X","X","X"],["X","X","X"]]
    # Test case 5: Empty board
    board5 = []
    # Should not raise error
    try:
        sol.solve(board5)
        assert board5 == []
    except Exception:
        assert False, "Should not raise exception on empty board"
    print("All test cases passed!")

if __name__ == "__main__":
    test_solve_surrounded_regions()

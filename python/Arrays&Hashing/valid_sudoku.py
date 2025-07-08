from typing import List
from collections import defaultdict

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        """
        Approach:
        - Use three sets for each row, column, and 3x3 square to track seen numbers.
        - For each cell, if it's not empty, check if the number is already in the corresponding row, column, or square.
        - If so, return False. Otherwise, add the number to the sets.
        - If no duplicates are found, return True.

        Time Complexity: O(1), since the board size is fixed (9x9 = 81 cells).
        Space Complexity: O(1), since the sets store at most 9 numbers for each row, column, and square.
        """
        cols = defaultdict(set)
        rows = defaultdict(set)
        squares = defaultdict(set) # key: (row//3, col//3)
        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    continue
                if (board[r][c] in rows[r] or 
                    board[r][c] in cols[c] or 
                    board[r][c] in squares[r//3, c//3]):
                    return False
                cols[c].add(board[r][c])
                rows[r].add(board[r][c])
                squares[r//3, c//3].add(board[r][c])
        return True

# -------------------
# Test Cases
# -------------------
def test_valid_sudoku():
    sol = Solution()
    # Test case 1: Valid board
    board1 = [
        ["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]
    assert sol.isValidSudoku(board1) == True
    # Test case 2: Invalid due to row
    board2 = [
        ["8","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]
    assert sol.isValidSudoku(board2) == False
    # Test case 3: Invalid due to column
    board3 = [
        ["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        ["5",".",".",".","8",".",".","7","9"]
    ]
    assert sol.isValidSudoku(board3) == False
    # Test case 4: Invalid due to square
    board4 = [
        ["5","3",".",".","7",".",".",".","."],
        ["6",".","3","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]
    assert sol.isValidSudoku(board4) == False
    print("All test cases passed!")

if __name__ == "__main__":
    test_valid_sudoku() 
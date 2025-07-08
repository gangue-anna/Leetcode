from typing import List

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        """
        Approach:
        - Use backtracking to try placing a queen in each row.
        - Use sets to track which columns, positive diagonals (r+c), and negative diagonals (r-c) are under attack.
        - For each row, try every column. If it's not under attack, place a queen and recurse to the next row.
        - If all rows are filled, add the board configuration to the result.
        - Backtrack by removing the queen and updating the sets.

        Time Complexity: O(n!), since there are n choices for the first row, n-1 for the second, etc.
        Space Complexity: O(n^2), for the board and result storage.
        """
        col = set()
        posDiag = set() #(r + c)
        negDiag = set() #(r - c)

        res = []
        board = [["."] * n for i in range(n)]

        def backtrack(r):
            if r == n:
                copy = ["".join(row) for row in board]
                res.append(copy)
                return 
            for c in range(n):
                if c in col or (r + c) in posDiag or (r - c) in negDiag:
                    continue
                
                col.add(c)
                posDiag.add(r + c)
                negDiag.add(r - c)
                board[r][c] = "Q"

                backtrack(r + 1)

                col.remove(c)
                posDiag.remove(r + c)
                negDiag.remove(r - c)
                board[r][c] = "."

        backtrack(0)
        return res

# -------------------
# Test Cases
# -------------------
def test_n_queens():
    sol = Solution()
    # Test case 1: n = 4 (classic)
    result1 = sol.solveNQueens(4)
    expected1 = [
        [".Q..","...Q","Q...","..Q."],
        ["..Q.","Q...","...Q",".Q.."]
    ]
    assert sorted(result1) == sorted(expected1)
    # Test case 2: n = 1
    assert sol.solveNQueens(1) == [["Q"]]
    # Test case 3: n = 2 (no solution)
    assert sol.solveNQueens(2) == []
    # Test case 4: n = 3 (no solution)
    assert sol.solveNQueens(3) == []
    print("All test cases passed!")

if __name__ == "__main__":
    test_n_queens()
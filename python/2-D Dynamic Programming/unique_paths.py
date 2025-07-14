class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        """
        Find the number of unique paths from top-left to bottom-right in an m x n grid.
        You can only move down or right at any point in time.
        
        Approach:
        - Use dynamic programming with space optimization.
        - Initialize the bottom row with 1s (only one way to reach each cell in the last row).
        - For each row from bottom to top:
          - Create a new row starting with 1s.
          - For each cell (except the last), the number of paths equals:
            paths from right + paths from below (which is the value from the previous row).
        - Return the value at the top-left corner.
        
        Time Complexity: O(m * n)
        - We iterate through each cell in the grid once
        
        Space Complexity: O(n)
        - We only store two rows at a time (current and previous)
        
        Args:
            m: int - Number of rows
            n: int - Number of columns
        Returns:
            int - Number of unique paths from top-left to bottom-right
        """
        row = [1] * n  # Initialize the bottom row with 1s

        for i in range(m - 1):
            newRow = [1] * n  # Initialize new row with 1s
            for j in range(n - 2, -1, -1):
                # Number of paths = paths from right + paths from below
                newRow[j] = newRow[j + 1] + row[j]
            row = newRow  # Update the current row
        return row[0]  # Return the value at the top-left corner

# -------------------
# Test Cases
# -------------------
def test_unique_paths():
    s = Solution()
    # Test case 1: Basic case
    assert s.uniquePaths(3, 7) == 28, "Failed on (3, 7)"
    # Test case 2: Square grid
    assert s.uniquePaths(3, 3) == 6, "Failed on (3, 3)"
    # Test case 3: Single row
    assert s.uniquePaths(1, 5) == 1, "Failed on (1, 5)"
    # Test case 4: Single column
    assert s.uniquePaths(5, 1) == 1, "Failed on (5, 1)"
    # Test case 5: 2x2 grid
    assert s.uniquePaths(2, 2) == 2, "Failed on (2, 2)"
    # Test case 6: Large grid
    assert s.uniquePaths(7, 3) == 28, "Failed on (7, 3)"
    # Test case 7: Single cell
    assert s.uniquePaths(1, 1) == 1, "Failed on (1, 1)"
    print("All test cases passed!")

if __name__ == "__main__":
    test_unique_paths()
        
from typing import List
    
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        """
        Approach:
        - First, use binary search to find the correct row where the target could be (since each row is sorted and the first element of each row is greater than the last of the previous row).
        - Then, use binary search within that row to find the target.
        - Return True if found, otherwise False.

        Time Complexity: O(log m + log n) = O(log(mn)), where m is the number of rows and n is the number of columns.
        Space Complexity: O(1).
        """
        rows, cols = len(matrix), len(matrix[0])
        top, bot = 0, rows - 1
        while  top <= bot:
            row = (top + bot) // 2
            if target > matrix[row][-1]:
                top = row + 1
            elif target < matrix[row][0]:
                bot = row - 1
            else: 
                break
        if not (top <= bot):
            return False
        row = (top + bot) // 2
        l, r = 0, cols - 1
        while l <= r:
            m = (l + r) // 2
            if target > matrix[row][m]:
                l = m + 1
            elif target < matrix[row][m]:
                r = m - 1
            else:
                return True
        return False

# -------------------
# Test Cases
# -------------------
def test_search_2D_matrix():
    sol = Solution()
    # Test case 1: Example from Leetcode
    matrix1 = [
        [1,3,5,7],
        [10,11,16,20],
        [23,30,34,60]
    ]
    assert sol.searchMatrix(matrix1, 3) == True
    assert sol.searchMatrix(matrix1, 13) == False
    # Test case 2: Single row
    matrix2 = [[1,2,3,4,5]]
    assert sol.searchMatrix(matrix2, 4) == True
    assert sol.searchMatrix(matrix2, 6) == False
    # Test case 3: Single column
    matrix3 = [[1],[3],[5]]
    assert sol.searchMatrix(matrix3, 3) == True
    assert sol.searchMatrix(matrix3, 2) == False
    # Test case 4: 1x1 matrix
    matrix4 = [[42]]
    assert sol.searchMatrix(matrix4, 42) == True
    assert sol.searchMatrix(matrix4, 7) == False
    print("All test cases passed!")

if __name__ == "__main__":
    test_search_2D_matrix()

from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Set entire row and column to zero if an element is zero.
        
        Approach:
        1. Use the first row and first column as markers to track which rows/columns should be zeroed
        2. Use an additional variable to track if the first row itself should be zeroed
        3. First pass: Mark rows and columns that need to be zeroed
        4. Second pass: Apply the zeroing based on the markers
        
        Algorithm:
        - Use matrix[0][c] to mark if column c should be zeroed
        - Use matrix[r][0] to mark if row r should be zeroed (except row 0)
        - Use rowZero variable to track if row 0 should be zeroed
        - Apply zeroing in reverse order to avoid overwriting markers
        
        Time Complexity: O(m × n) where m is rows and n is columns
        - We make two passes through the matrix
        - Each pass visits each element once
        
        Space Complexity: O(1) - we only use a constant amount of extra space
        - Only one additional variable (rowZero)
        - All markers are stored in the matrix itself
        
        Args:
            matrix: 2D list representing the matrix to modify in-place
        """
        ROWS, COLS = len(matrix), len(matrix[0])
        rowZero = False  # Track if the first row should be zeroed

        # First pass: Determine which rows and columns need to be zeroed
        for r in range(ROWS):
            for c in range(COLS):
                if matrix[r][c] == 0:
                    # Mark column c to be zeroed (using first row as marker)
                    matrix[0][c] = 0

                    # Mark row r to be zeroed (using first column as marker)
                    if r > 0:
                        matrix[r][0] = 0
                    else:
                        # If element in first row is zero, mark entire first row
                        rowZero = True
        
        # Second pass: Apply zeroing to all elements except first row and column
        for r in range(1, ROWS):
            for c in range(1, COLS):
                # If either the row or column marker is zero, set element to zero
                if matrix[0][c] == 0 or matrix[r][0] == 0:
                    matrix[r][c] = 0
        
        # Handle the first column (matrix[0][0] was used as a marker)
        if matrix[0][0] == 0:
            for r in range(ROWS):
                matrix[r][0] = 0
        
        # Handle the first row if it needs to be zeroed
        if rowZero:
            for c in range(COLS):
                matrix[0][c] = 0


def test_set_matrix_zeroes():
    """Test cases for the set matrix zeroes function"""
    
    def print_matrix(matrix, title=""):
        """Helper function to print matrix in a readable format"""
        if title:
            print(f"\n{title}")
        for row in matrix:
            print(row)
    
    # Test Case 1: Basic case with zeros
    print("=" * 60)
    print("TEST CASE 1: Basic Case with Zeros")
    print("=" * 60)
    
    matrix1 = [
        [1, 1, 1],
        [1, 0, 1],
        [1, 1, 1]
    ]
    print_matrix(matrix1, "Original Matrix:")
    
    Solution().setZeroes(matrix1)
    print_matrix(matrix1, "After setZeroes:")
    
    expected1 = [
        [1, 0, 1],
        [0, 0, 0],
        [1, 0, 1]
    ]
    print_matrix(expected1, "Expected result:")
    print(f"Test 1 Passed: {matrix1 == expected1}")
    
    # Test Case 2: Zero in first row and column
    print("\n" + "=" * 60)
    print("TEST CASE 2: Zero in First Row and Column")
    print("=" * 60)
    
    matrix2 = [
        [0, 1, 2, 0],
        [3, 4, 5, 2],
        [1, 3, 1, 5]
    ]
    print_matrix(matrix2, "Original Matrix:")
    
    Solution().setZeroes(matrix2)
    print_matrix(matrix2, "After setZeroes:")
    
    expected2 = [
        [0, 0, 0, 0],
        [0, 4, 5, 0],
        [0, 3, 1, 0]
    ]
    print_matrix(expected2, "Expected result:")
    print(f"Test 2 Passed: {matrix2 == expected2}")
    
    # Test Case 3: All zeros
    print("\n" + "=" * 60)
    print("TEST CASE 3: All Zeros")
    print("=" * 60)
    
    matrix3 = [
        [0, 0, 0],
        [0, 0, 0],
        [0, 0, 0]
    ]
    print_matrix(matrix3, "Original Matrix:")
    
    Solution().setZeroes(matrix3)
    print_matrix(matrix3, "After setZeroes:")
    
    expected3 = [
        [0, 0, 0],
        [0, 0, 0],
        [0, 0, 0]
    ]
    print_matrix(expected3, "Expected result:")
    print(f"Test 3 Passed: {matrix3 == expected3}")
    
    # Test Case 4: No zeros
    print("\n" + "=" * 60)
    print("TEST CASE 4: No Zeros")
    print("=" * 60)
    
    matrix4 = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    print_matrix(matrix4, "Original Matrix:")
    
    Solution().setZeroes(matrix4)
    print_matrix(matrix4, "After setZeroes:")
    
    expected4 = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    print_matrix(expected4, "Expected result:")
    print(f"Test 4 Passed: {matrix4 == expected4}")
    
    # Test Case 5: Single element matrix
    print("\n" + "=" * 60)
    print("TEST CASE 5: Single Element Matrix")
    print("=" * 60)
    
    matrix5 = [[0]]
    print_matrix(matrix5, "Original Matrix:")
    
    Solution().setZeroes(matrix5)
    print_matrix(matrix5, "After setZeroes:")
    
    expected5 = [[0]]
    print_matrix(expected5, "Expected result:")
    print(f"Test 5 Passed: {matrix5 == expected5}")
    
    # Test Case 6: Zero in corner
    print("\n" + "=" * 60)
    print("TEST CASE 6: Zero in Corner")
    print("=" * 60)
    
    matrix6 = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 0]
    ]
    print_matrix(matrix6, "Original Matrix:")
    
    Solution().setZeroes(matrix6)
    print_matrix(matrix6, "After setZeroes:")
    
    expected6 = [
        [1, 2, 0],
        [4, 5, 0],
        [0, 0, 0]
    ]
    print_matrix(expected6, "Expected result:")
    print(f"Test 6 Passed: {matrix6 == expected6}")
    
    # Test Case 7: Multiple zeros
    print("\n" + "=" * 60)
    print("TEST CASE 7: Multiple Zeros")
    print("=" * 60)
    
    matrix7 = [
        [1, 0, 1],
        [0, 1, 1],
        [1, 1, 0]
    ]
    print_matrix(matrix7, "Original Matrix:")
    
    Solution().setZeroes(matrix7)
    print_matrix(matrix7, "After setZeroes:")
    
    expected7 = [
        [0, 0, 0],
        [0, 0, 0],
        [0, 0, 0]
    ]
    print_matrix(expected7, "Expected result:")
    print(f"Test 7 Passed: {matrix7 == expected7}")
    
    # Test Case 8: Large matrix
    print("\n" + "=" * 60)
    print("TEST CASE 8: Large Matrix")
    print("=" * 60)
    
    matrix8 = [
        [1, 2, 3, 4],
        [5, 0, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 16]
    ]
    print_matrix(matrix8, "Original Matrix:")
    
    Solution().setZeroes(matrix8)
    print_matrix(matrix8, "After setZeroes:")
    
    expected8 = [
        [1, 0, 3, 4],
        [0, 0, 0, 0],
        [9, 0, 11, 12],
        [13, 0, 15, 16]
    ]
    print_matrix(expected8, "Expected result:")
    print(f"Test 8 Passed: {matrix8 == expected8}")
    
    print("\n" + "=" * 60)
    print("ALL TESTS COMPLETED")
    print("=" * 60)


if __name__ == "__main__":
    test_set_matrix_zeroes()
        
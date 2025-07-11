from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Rotate a 2D matrix 90 degrees clockwise in-place.
        
        Approach:
        1. Use a layer-by-layer rotation approach
        2. For each layer, rotate 4 elements at a time in a cycle
        3. Start from the outermost layer and work inward
        4. For each position in the current layer, swap 4 elements:
           - top-left -> top-right -> bottom-right -> bottom-left -> top-left
        
        Time Complexity: O(n²) where n is the size of the matrix
        - We need to visit each element once
        - For an n×n matrix, we have n² elements
        
        Space Complexity: O(1) - we only use a constant amount of extra space
        - Only storing one temporary variable (topLeft)
        - All operations are done in-place
        
        Args:
            matrix: 2D list representing the matrix to rotate
        """
        l, r = 0, len(matrix) - 1

        while l < r:
            # Process each element in the current layer
            for i in range(r - l):
                top, bottom = l, r

                # Save the top-left element
                topLeft = matrix[top][l + i]

                # Move bottom-left into top-left
                matrix[top][l + i] = matrix[bottom - i][l]

                # Move bottom-right to bottom-left
                matrix[bottom - i][l] = matrix[bottom][r - i]

                # Move top-right into bottom-right
                matrix[bottom][r - i] = matrix[top + i][r]

                # Move the saved top-left into top-right
                matrix[top + i][r] = topLeft
            
            # Move to the next inner layer
            r -= 1
            l += 1


def test_rotate_image():
    """Test cases for the rotate image function"""
    
    def print_matrix(matrix, title=""):
        """Helper function to print matrix in a readable format"""
        if title:
            print(f"\n{title}")
        for row in matrix:
            print(row)
    
    # Test Case 1: 2x2 matrix
    print("=" * 50)
    print("TEST CASE 1: 2x2 Matrix")
    print("=" * 50)
    
    matrix1 = [
        [1, 2],
        [3, 4]
    ]
    print_matrix(matrix1, "Original 2x2 Matrix:")
    
    Solution().rotate(matrix1)
    print_matrix(matrix1, "After 90° rotation:")
    
    expected1 = [
        [3, 1],
        [4, 2]
    ]
    print_matrix(expected1, "Expected result:")
    print(f"Test 1 Passed: {matrix1 == expected1}")
    
    # Test Case 2: 3x3 matrix
    print("\n" + "=" * 50)
    print("TEST CASE 2: 3x3 Matrix")
    print("=" * 50)
    
    matrix2 = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    print_matrix(matrix2, "Original 3x3 Matrix:")
    
    Solution().rotate(matrix2)
    print_matrix(matrix2, "After 90° rotation:")
    
    expected2 = [
        [7, 4, 1],
        [8, 5, 2],
        [9, 6, 3]
    ]
    print_matrix(expected2, "Expected result:")
    print(f"Test 2 Passed: {matrix2 == expected2}")
    
    # Test Case 3: 4x4 matrix
    print("\n" + "=" * 50)
    print("TEST CASE 3: 4x4 Matrix")
    print("=" * 50)
    
    matrix3 = [
        [5, 1, 9, 11],
        [2, 4, 8, 10],
        [13, 3, 6, 7],
        [15, 14, 12, 16]
    ]
    print_matrix(matrix3, "Original 4x4 Matrix:")
    
    Solution().rotate(matrix3)
    print_matrix(matrix3, "After 90° rotation:")
    
    expected3 = [
        [15, 13, 2, 5],
        [14, 3, 4, 1],
        [12, 6, 8, 9],
        [16, 7, 10, 11]
    ]
    print_matrix(expected3, "Expected result:")
    print(f"Test 3 Passed: {matrix3 == expected3}")
    
    # Test Case 4: 1x1 matrix (edge case)
    print("\n" + "=" * 50)
    print("TEST CASE 4: 1x1 Matrix (Edge Case)")
    print("=" * 50)
    
    matrix4 = [[42]]
    print_matrix(matrix4, "Original 1x1 Matrix:")
    
    Solution().rotate(matrix4)
    print_matrix(matrix4, "After 90° rotation:")
    
    expected4 = [[42]]
    print_matrix(expected4, "Expected result:")
    print(f"Test 4 Passed: {matrix4 == expected4}")
    
    # Test Case 5: 5x5 matrix
    print("\n" + "=" * 50)
    print("TEST CASE 5: 5x5 Matrix")
    print("=" * 50)
    
    matrix5 = [
        [1, 2, 3, 4, 5],
        [6, 7, 8, 9, 10],
        [11, 12, 13, 14, 15],
        [16, 17, 18, 19, 20],
        [21, 22, 23, 24, 25]
    ]
    print_matrix(matrix5, "Original 5x5 Matrix:")
    
    Solution().rotate(matrix5)
    print_matrix(matrix5, "After 90° rotation:")
    
    expected5 = [
        [21, 16, 11, 6, 1],
        [22, 17, 12, 7, 2],
        [23, 18, 13, 8, 3],
        [24, 19, 14, 9, 4],
        [25, 20, 15, 10, 5]
    ]
    print_matrix(expected5, "Expected result:")
    print(f"Test 5 Passed: {matrix5 == expected5}")
    
    print("\n" + "=" * 50)
    print("ALL TESTS COMPLETED")
    print("=" * 50)


if __name__ == "__main__":
    test_rotate_image()

from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        """
        Return all elements of the matrix in spiral order.
        
        Approach:
        1. Use four pointers to track boundaries: left, right, top, bottom
        2. Traverse the matrix in four directions: right, down, left, up
        3. After each direction, update the corresponding boundary
        4. Continue until all elements are visited
        
        Algorithm:
        - Right: top row from left to right, then increment top
        - Down: right column from top to bottom, then decrement right
        - Left: bottom row from right to left, then decrement bottom
        - Up: left column from bottom to top, then increment left
        
        Time Complexity: O(m × n) where m is rows and n is columns
        - We visit each element exactly once
        - Total elements = m × n
        
        Space Complexity: O(1) excluding the output array
        - We only use a constant amount of extra space for pointers
        - The result array is required by the problem (O(m×n) output space)
        
        Args:
            matrix: 2D list representing the matrix
            
        Returns:
            List of integers in spiral order
        """
        res = []
        left, right = 0, len(matrix[0])
        top, bottom = 0, len(matrix)

        while left < right and top < bottom:
            # Get every element in the top row (left to right)
            for i in range(left, right):
                res.append(matrix[top][i])
            top += 1  # Move top boundary down

            # Get every element in the right column (top to bottom)
            for i in range(top, bottom):
                res.append(matrix[i][right - 1])
            right -= 1  # Move right boundary left

            # Check if we still have elements to process
            if not (left < right and top < bottom):
                break

            # Get every element in the bottom row (right to left)
            for i in range(right - 1, left - 1, -1):
                res.append(matrix[bottom - 1][i])
            bottom -= 1  # Move bottom boundary up

            # Get every element in the left column (bottom to top)
            for i in range(bottom - 1, top - 1, -1):
                res.append(matrix[i][left])
            left += 1  # Move left boundary right

        return res


def test_spiral_matrix():
    """Test cases for the spiral matrix function"""
    
    def print_matrix(matrix, title=""):
        """Helper function to print matrix in a readable format"""
        if title:
            print(f"\n{title}")
        for row in matrix:
            print(row)
    
    # Test Case 1: 3x3 matrix
    print("=" * 60)
    print("TEST CASE 1: 3x3 Matrix")
    print("=" * 60)
    
    matrix1 = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    print_matrix(matrix1, "Input Matrix:")
    
    result1 = Solution().spiralOrder(matrix1)
    expected1 = [1, 2, 3, 6, 9, 8, 7, 4, 5]
    
    print(f"Spiral Order: {result1}")
    print(f"Expected:     {expected1}")
    print(f"Test 1 Passed: {result1 == expected1}")
    
    # Test Case 2: 3x4 matrix
    print("\n" + "=" * 60)
    print("TEST CASE 2: 3x4 Matrix")
    print("=" * 60)
    
    matrix2 = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12]
    ]
    print_matrix(matrix2, "Input Matrix:")
    
    result2 = Solution().spiralOrder(matrix2)
    expected2 = [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
    
    print(f"Spiral Order: {result2}")
    print(f"Expected:     {expected2}")
    print(f"Test 2 Passed: {result2 == expected2}")
    
    # Test Case 3: 4x3 matrix
    print("\n" + "=" * 60)
    print("TEST CASE 3: 4x3 Matrix")
    print("=" * 60)
    
    matrix3 = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
        [10, 11, 12]
    ]
    print_matrix(matrix3, "Input Matrix:")
    
    result3 = Solution().spiralOrder(matrix3)
    expected3 = [1, 2, 3, 6, 9, 12, 11, 10, 7, 4, 5, 8]
    
    print(f"Spiral Order: {result3}")
    print(f"Expected:     {expected3}")
    print(f"Test 3 Passed: {result3 == expected3}")
    
    # Test Case 4: 1x1 matrix (edge case)
    print("\n" + "=" * 60)
    print("TEST CASE 4: 1x1 Matrix (Edge Case)")
    print("=" * 60)
    
    matrix4 = [[42]]
    print_matrix(matrix4, "Input Matrix:")
    
    result4 = Solution().spiralOrder(matrix4)
    expected4 = [42]
    
    print(f"Spiral Order: {result4}")
    print(f"Expected:     {expected4}")
    print(f"Test 4 Passed: {result4 == expected4}")
    
    # Test Case 5: 1x4 matrix (single row)
    print("\n" + "=" * 60)
    print("TEST CASE 5: 1x4 Matrix (Single Row)")
    print("=" * 60)
    
    matrix5 = [[1, 2, 3, 4]]
    print_matrix(matrix5, "Input Matrix:")
    
    result5 = Solution().spiralOrder(matrix5)
    expected5 = [1, 2, 3, 4]
    
    print(f"Spiral Order: {result5}")
    print(f"Expected:     {expected5}")
    print(f"Test 5 Passed: {result5 == expected5}")
    
    # Test Case 6: 4x1 matrix (single column)
    print("\n" + "=" * 60)
    print("TEST CASE 6: 4x1 Matrix (Single Column)")
    print("=" * 60)
    
    matrix6 = [[1], [2], [3], [4]]
    print_matrix(matrix6, "Input Matrix:")
    
    result6 = Solution().spiralOrder(matrix6)
    expected6 = [1, 2, 3, 4]
    
    print(f"Spiral Order: {result6}")
    print(f"Expected:     {expected6}")
    print(f"Test 6 Passed: {result6 == expected6}")
    
    # Test Case 7: 2x2 matrix
    print("\n" + "=" * 60)
    print("TEST CASE 7: 2x2 Matrix")
    print("=" * 60)
    
    matrix7 = [
        [1, 2],
        [3, 4]
    ]
    print_matrix(matrix7, "Input Matrix:")
    
    result7 = Solution().spiralOrder(matrix7)
    expected7 = [1, 2, 4, 3]
    
    print(f"Spiral Order: {result7}")
    print(f"Expected:     {expected7}")
    print(f"Test 7 Passed: {result7 == expected7}")
    
    # Test Case 8: 4x4 matrix
    print("\n" + "=" * 60)
    print("TEST CASE 8: 4x4 Matrix")
    print("=" * 60)
    
    matrix8 = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 16]
    ]
    print_matrix(matrix8, "Input Matrix:")
    
    result8 = Solution().spiralOrder(matrix8)
    expected8 = [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
    
    print(f"Spiral Order: {result8}")
    print(f"Expected:     {expected8}")
    print(f"Test 8 Passed: {result8 == expected8}")
    
    print("\n" + "=" * 60)
    print("ALL TESTS COMPLETED")
    print("=" * 60)


if __name__ == "__main__":
    test_spiral_matrix()
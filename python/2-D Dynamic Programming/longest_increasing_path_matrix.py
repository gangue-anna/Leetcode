from typing import List

class Solution:
    """
    Longest Increasing Path in a Matrix
    
    Problem: Given an m x n integers matrix, return the length of the longest 
    increasing path in matrix. From each cell, you can either move in four 
    directions: left, right, up, or down. You may not move diagonally or move 
    outside the boundary (i.e., wrap-around is not allowed).
    
    Example: matrix = [[9,9,4],[6,6,8],[2,1,1]]
    Output: 4 (Longest path: 1 → 2 → 6 → 9)
    
    Approach: Dynamic Programming with DFS
    - Use DFS with memoization to explore all possible paths from each cell
    - For each cell, try moving in all four directions (up, down, left, right)
    - Only move to cells with strictly greater values (increasing path)
    - Memoize results to avoid recalculating the same subproblems
    - The state is represented by (row, col) position
    
    Time Complexity: O(m * n) where m and n are the dimensions of the matrix
    Space Complexity: O(m * n) for memoization cache
    """
    
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        # Check for empty matrix
        if not matrix or not matrix[0]:
            return 0
            
        # Get matrix dimensions
        ROWS, COLS = len(matrix), len(matrix[0])
        
        # Memoization cache: (row, col) -> length of longest increasing path from this cell
        dp = {}
        
        def dfs(r, c, preVal):
            """
            DFS helper function to find longest increasing path from current cell
            
            Args:
                r: Current row position
                c: Current column position
                preVal: Value of previous cell in the path
            
            Returns:
                Length of longest increasing path from current cell
            """
            # Base cases: out of bounds or not increasing
            if (r < 0 or r == ROWS or
                c < 0 or c == COLS or 
                matrix[r][c] <= preVal):
                return 0
                
            # Return cached result if already computed
            if (r, c) in dp:
                return dp[(r, c)]

            # Start with current cell (length 1)
            res = 1
            
            # Try all four directions: down, up, right, left
            res = max(res, 1 + dfs(r + 1, c, matrix[r][c]))  # Down
            res = max(res, 1 + dfs(r - 1, c, matrix[r][c]))  # Up
            res = max(res, 1 + dfs(r, c + 1, matrix[r][c]))  # Right
            res = max(res, 1 + dfs(r, c - 1, matrix[r][c]))  # Left
            
            # Cache the result
            dp[(r, c)] = res
            return res
        
        # Try starting from every cell in the matrix
        for r in range(ROWS):
            for c in range(COLS):
                dfs(r, c, -1)  # Start with -1 as previous value (less than any cell)
                
        return max(dp.values())


class Solution2:
    """
    Longest Increasing Path in a Matrix
    
    Problem: Given an m x n integers matrix, return the length of the longest 
    increasing path in matrix.
    
    Approach: Topological Sort with BFS
    - Build a graph where each cell points to its neighbors with greater values
    - Use topological sort to find the longest path in the DAG
    - This approach is more efficient for very large matrices
    
    Time Complexity: O(m * n)
    Space Complexity: O(m * n)
    """
    
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix or not matrix[0]:
            return 0
            
        ROWS, COLS = len(matrix), len(matrix[0])
        
        # Build adjacency list and in-degree count
        graph = {}
        in_degree = {}
        
        # Initialize
        for r in range(ROWS):
            for c in range(COLS):
                graph[(r, c)] = []
                in_degree[(r, c)] = 0
        
        # Build edges (cell -> neighbors with greater values)
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for r in range(ROWS):
            for c in range(COLS):
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if (0 <= nr < ROWS and 0 <= nc < COLS and 
                        matrix[nr][nc] > matrix[r][c]):
                        graph[(r, c)].append((nr, nc))
                        in_degree[(nr, nc)] += 1
        
        # Topological sort with BFS
        queue = [(r, c) for r in range(ROWS) for c in range(COLS) if in_degree[(r, c)] == 0]
        max_length = 0
        length = {pos: 1 for pos in queue}
        
        while queue:
            new_queue = []
            for r, c in queue:
                for nr, nc in graph[(r, c)]:
                    in_degree[(nr, nc)] -= 1
                    # Use .get() with default value to avoid KeyError
                    current_length = length.get((nr, nc), 0)
                    length[(nr, nc)] = max(current_length, length[(r, c)] + 1)
                    if in_degree[(nr, nc)] == 0:
                        new_queue.append((nr, nc))
            queue = new_queue
            max_length = max(max_length, max(length.values()) if length else 0)
            
        return max_length


# Test cases
def test_longest_increasing_path():
    """Test cases for Longest Increasing Path in Matrix problem"""
    
    # Test case 1: Basic case
    print("Test 1: matrix=[[9,9,4],[6,6,8],[2,1,1]]")
    sol1 = Solution()
    sol2 = Solution2()
    matrix1 = [[9,9,4],[6,6,8],[2,1,1]]
    result1 = sol1.longestIncreasingPath(matrix1)
    result2 = sol2.longestIncreasingPath(matrix1)
    expected = 4  # Longest path: 1 → 2 → 6 → 9
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 1 passed\n")
    
    # Test case 2: Single element
    print("Test 2: matrix=[[1]]")
    matrix2 = [[1]]
    result1 = sol1.longestIncreasingPath(matrix2)
    result2 = sol2.longestIncreasingPath(matrix2)
    expected = 1  # Single element has path length 1
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 2 passed\n")
    
    # Test case 3: All same values
    print("Test 3: matrix=[[1,1],[1,1]]")
    matrix3 = [[1,1],[1,1]]
    result1 = sol1.longestIncreasingPath(matrix3)
    result2 = sol2.longestIncreasingPath(matrix3)
    expected = 1  # No increasing path possible
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 3 passed\n")
    
    # Test case 4: Strictly increasing
    print("Test 4: matrix=[[1,2,3],[4,5,6],[7,8,9]]")
    matrix4 = [[1,2,3],[4,5,6],[7,8,9]]
    result1 = sol1.longestIncreasingPath(matrix4)
    result2 = sol2.longestIncreasingPath(matrix4)
    expected = 5  # Longest path: 1→2→3→6→9 (length 5)
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 4 passed\n")
    
    # Test case 5: Strictly decreasing
    print("Test 5: matrix=[[9,8,7],[6,5,4],[3,2,1]]")
    matrix5 = [[9,8,7],[6,5,4],[3,2,1]]
    result1 = sol1.longestIncreasingPath(matrix5)
    result2 = sol2.longestIncreasingPath(matrix5)
    expected = 5  # Longest path: 1→2→3→6→9 (length 5)
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 5 passed\n")
    
    # Test case 6: Single row
    print("Test 6: matrix=[[1,2,3,4,5]]")
    matrix6 = [[1,2,3,4,5]]
    result1 = sol1.longestIncreasingPath(matrix6)
    result2 = sol2.longestIncreasingPath(matrix6)
    expected = 5  # Can follow the sequence 1→2→3→4→5
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 6 passed\n")
    
    # Test case 7: Single column
    print("Test 7: matrix=[[1],[2],[3],[4],[5]]")
    matrix7 = [[1],[2],[3],[4],[5]]
    result1 = sol1.longestIncreasingPath(matrix7)
    result2 = sol2.longestIncreasingPath(matrix7)
    expected = 5  # Can follow the sequence 1→2→3→4→5
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 7 passed\n")
    
    # Test case 8: Complex path
    print("Test 8: matrix=[[3,4,5],[3,2,6],[2,2,1]]")
    matrix8 = [[3,4,5],[3,2,6],[2,2,1]]
    result1 = sol1.longestIncreasingPath(matrix8)
    result2 = sol2.longestIncreasingPath(matrix8)
    expected = 4  # Longest path: 1 → 2 → 3 → 4 or similar
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 8 passed\n")
    
    # Test case 9: Large matrix
    print("Test 9: matrix=[[1,2,3,4],[5,6,7,8],[9,10,11,12]]")
    matrix9 = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    result1 = sol1.longestIncreasingPath(matrix9)
    result2 = sol2.longestIncreasingPath(matrix9)
    expected = 6  # Longest path: 1→2→3→4→8→12 (length 6)
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 9 passed\n")
    
    # Test case 10: Spiral pattern
    print("Test 10: matrix=[[1,2,3],[8,9,4],[7,6,5]]")
    matrix10 = [[1,2,3],[8,9,4],[7,6,5]]
    result1 = sol1.longestIncreasingPath(matrix10)
    result2 = sol2.longestIncreasingPath(matrix10)
    expected = 9  # Can follow the spiral: 1→2→3→4→5→6→7→8→9
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 10 passed\n")
    
    # Test case 11: Empty matrix
    print("Test 11: matrix=[]")
    matrix11 = []
    result1 = sol1.longestIncreasingPath(matrix11)
    result2 = sol2.longestIncreasingPath(matrix11)
    expected = 0  # Empty matrix has no path
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 11 passed\n")
    
    # Test case 12: All zeros
    print("Test 12: matrix=[[0,0],[0,0]]")
    matrix12 = [[0,0],[0,0]]
    result1 = sol1.longestIncreasingPath(matrix12)
    result2 = sol2.longestIncreasingPath(matrix12)
    expected = 1  # No increasing path possible
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 12 passed\n")
    
    print("All tests passed!")


if __name__ == "__main__":
    test_longest_increasing_path()
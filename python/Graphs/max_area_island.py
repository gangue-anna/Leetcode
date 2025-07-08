"""
Max Area of Island (DFS)
Approach: DFS to explore each island, counting area, and tracking the maximum found.
Time Complexity: O(m * n) where m and n are the grid dimensions (each cell visited at most once).
Space Complexity: O(m * n) for the recursion stack and visited set.
"""
from typing import List

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        
        rows, cols = len(grid), len(grid[0])
        visit = set()  # Set to track visited cells

        def dfs(r, c):
            # If out of bounds, water, or already visited, return 0
            if (r < 0 or r == rows or c < 0 or c == cols or grid[r][c] == 0 or (r, c) in visit):
                return 0
            
            visit.add((r, c))
            # Count current cell and explore all 4 directions
            return (1 + dfs(r + 1, c) +
                        dfs(r - 1, c) +
                        dfs(r, c + 1) +
                        dfs(r, c - 1))

        max_area = 0
        for r in range(rows):
            for c in range(cols):
                max_area = max(max_area, dfs(r, c))
        return max_area
            
# -------------------
# Test Cases
# -------------------
def test_max_area_of_island():
    sol = Solution()
    # Test case 1: Example from Leetcode
    grid1 = [
        [0,0,1,0,0,0,0,1,0,0,0,0,0],
        [0,0,0,0,0,0,0,1,1,1,0,0,0],
        [0,1,1,0,1,0,0,0,0,0,0,0,0],
        [0,1,0,0,1,1,0,0,1,0,1,0,0],
        [0,1,0,0,1,1,0,0,1,1,1,0,0],
        [0,0,0,0,0,0,0,0,0,0,1,0,0]
    ]
    assert sol.maxAreaOfIsland(grid1) == 6
    # Test case 2: All water
    grid2 = [[0,0,0],[0,0,0]]
    assert sol.maxAreaOfIsland(grid2) == 0
    # Test case 3: All land
    grid3 = [[1,1],[1,1]]
    assert sol.maxAreaOfIsland(grid3) == 4
    # Test case 4: Single cell island
    grid4 = [[1,0],[0,0]]
    assert sol.maxAreaOfIsland(grid4) == 1
    # Test case 5: No grid
    grid5 = []
    assert sol.maxAreaOfIsland(grid5) == 0
    print("All test cases passed!")

if __name__ == "__main__":
    test_max_area_of_island()
        
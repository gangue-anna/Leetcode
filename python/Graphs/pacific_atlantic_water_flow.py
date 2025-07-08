"""
Pacific Atlantic Water Flow
Approach: DFS from ocean borders, marking reachable cells for each ocean. The intersection gives cells that can reach both oceans.
Time Complexity: O(m * n) where m and n are the grid dimensions (each cell visited at most twice).
Space Complexity: O(m * n) for the recursion stack and visited sets.
"""
from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows, cols = len(heights), len(heights[0])
        pac, atl = set(), set()  # Sets to keep track of cells reachable by Pacific and Atlantic

        def dfs(r, c, visit, prevHeight):
            # If out of bounds, already visited, or cannot flow from prevHeight, return
            if ((r, c) in visit or 
                r < 0 or c < 0 or r == rows or c == cols or
                heights[r][c] < prevHeight):
                return
            visit.add((r, c))
            # Explore all 4 directions
            dfs(r + 1, c, visit, heights[r][c])
            dfs(r - 1, c, visit, heights[r][c])
            dfs(r, c + 1, visit, heights[r][c])
            dfs(r, c - 1, visit, heights[r][c])

        # Start DFS from Pacific (top and left borders) and Atlantic (bottom and right borders)
        for c in range(cols):
            dfs(0, c, pac, heights[0][c])  # Top row (Pacific)
            dfs(rows - 1, c, atl, heights[rows - 1][c])  # Bottom row (Atlantic)

        for r in range(rows):
            dfs(r, 0, pac, heights[r][0])  # Left column (Pacific)
            dfs(r, cols - 1, atl, heights[r][cols - 1])  # Right column (Atlantic)
        
        # Cells reachable by both oceans
        res = []
        for r in range(rows):
            for c in range(cols):
                if (r, c) in pac and (r, c) in atl:
                    res.append([r, c])
        return res

# -------------------
# Test Cases
# -------------------
def test_pacific_atlantic():
    sol = Solution()
    # Test case 1: Example from Leetcode
    heights1 = [
        [1,2,2,3,5],
        [3,2,3,4,4],
        [2,4,5,3,1],
        [6,7,1,4,5],
        [5,1,1,2,4]
    ]
    result1 = sol.pacificAtlantic(heights1)
    expected1 = [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
    assert sorted(result1) == sorted(expected1)
    # Test case 2: All same height
    heights2 = [[1,1],[1,1]]
    result2 = sol.pacificAtlantic(heights2)
    expected2 = [[0,0],[0,1],[1,0],[1,1]]
    assert sorted(result2) == sorted(expected2)
    # Test case 3: Single cell
    heights3 = [[42]]
    assert sol.pacificAtlantic(heights3) == [[0,0]]
    # Test case 4: No water flow
    heights4 = [[10,9,8],[7,6,5],[4,3,2]]
    assert sol.pacificAtlantic(heights4) == [[0,0],[0,1],[0,2],[1,0],[2,0]]
    print("All test cases passed!")

if __name__ == "__main__":
    test_pacific_atlantic()
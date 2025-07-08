from typing import List
from collections import deque

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        """
        Approach:
        - Use BFS to traverse each island in the grid.
        - For each unvisited '1', start a BFS and mark all connected land as visited.
        - Count the number of BFS runs (islands).

        Time Complexity: O(m * n), where m and n are the grid dimensions (each cell visited at most once).
        Space Complexity: O(m * n), for the visited set and BFS queue in the worst case.
        """
        if not grid:
            return 0
        rows, cols = len(grid), len(grid[0])
        visit = set()
        islands = 0
        def bfs(r, c):
            q = deque()
            visit.add((r, c))
            q.append((r, c))
            while q:
                row, col = q.popleft()
                directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
                for dr, dc in directions:
                    nr, nc = row + dr, col + dc
                    if (nr in range(rows) and
                        nc in range(cols) and 
                        grid[nr][nc] == "1" and
                        (nr, nc) not in visit):
                        q.append((nr, nc))
                        visit.add((nr, nc))
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1" and (r, c) not in visit:
                    bfs(r, c)
                    islands += 1
        return islands

# -------------------
# Test Cases
# -------------------
def test_num_islands():
    sol = Solution()
    # Test case 1: Example from Leetcode
    grid1 = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
    ]
    assert sol.numIslands(grid1) == 1
    # Test case 2: Multiple islands
    grid2 = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
    ]
    assert sol.numIslands(grid2) == 3
    # Test case 3: All water
    grid3 = [["0","0"],["0","0"]]
    assert sol.numIslands(grid3) == 0
    # Test case 4: All land
    grid4 = [["1","1"],["1","1"]]
    assert sol.numIslands(grid4) == 1
    # Test case 5: Empty grid
    grid5 = []
    assert sol.numIslands(grid5) == 0
    print("All test cases passed!")

if __name__ == "__main__":
    test_num_islands()



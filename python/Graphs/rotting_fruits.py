"""
Rotting Oranges (BFS)
Approach: Multi-source BFS from all initially rotten oranges, spreading rot to adjacent fresh oranges each minute.
Time Complexity: O(m * n) where m and n are the grid dimensions (each cell visited at most once).
Space Complexity: O(m * n) for the queue and visited cells.
"""
from typing import List
from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = deque()  # Queue for BFS
        time, fresh = 0, 0  # Time counter and fresh orange counter

        rows, cols = len(grid), len(grid[0])
        # Count fresh oranges and enqueue rotten ones
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    fresh += 1
                if grid[r][c] == 2:
                    q.append([r, c])

        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]  # 4-directional movement
        
        # BFS: spread rot minute by minute
        while q and fresh > 0:
            for i in range(len(q)):
                r, c = q.popleft()
                for dr, dc in directions:
                    row, col = dr + r, dc + c 
                    # If in bounds and fresh, make rotten
                    if(row < 0 or row == len(grid) or
                       col < 0 or col == len(grid[0]) or
                       grid[row][col] != 1):
                        continue
                    grid[row][col] = 2
                    q.append([row, col])
                    fresh -= 1
            time += 1  # Increment time after each round
        # If all fresh oranges are rotten, return time; else, return -1
        return time if fresh == 0 else -1

# -------------------
# Test Cases
# -------------------
def test_oranges_rotting():
    sol = Solution()
    # Test case 1: Example from Leetcode
    grid1 = [
        [2,1,1],
        [1,1,0],
        [0,1,1]
    ]
    assert sol.orangesRotting([row[:] for row in grid1]) == 4
    # Test case 2: Impossible to rot all
    grid2 = [
        [2,1,1],
        [0,1,1],
        [1,0,1]
    ]
    assert sol.orangesRotting([row[:] for row in grid2]) == -1
    # Test case 3: All already rotten
    grid3 = [
        [0,2]
    ]
    assert sol.orangesRotting([row[:] for row in grid3]) == 0
    # Test case 4: No oranges
    grid4 = [
        [0,0],
        [0,0]
    ]
    assert sol.orangesRotting([row[:] for row in grid4]) == 0
    # Test case 5: Single fresh orange, no rotten
    grid5 = [
        [1]
    ]
    assert sol.orangesRotting([row[:] for row in grid5]) == -1
    print("All test cases passed!")

if __name__ == "__main__":
    test_oranges_rotting()
    
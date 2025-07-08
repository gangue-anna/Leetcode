"""
Walls and Gates (BFS)
Approach: Multi-source BFS from all gates (0s), filling each empty room with its distance to the nearest gate.
Time Complexity: O(m * n) where m and n are the grid dimensions (each cell visited at most once).
Space Complexity: O(m * n) for the queue and visited set.
"""
from typing import List
from collections import deque

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        rows, cols = len(grid), len(grid[0])
        visit = set()  # Visited cells
        q = deque()    # Queue for BFS

        def addRoom(r, c):
            # Add a room to the queue if it's in bounds, not visited, and not a wall
            if (r < 0 or r == rows or c < 0 or c == cols or (r, c) in visit or grid[r][c] == -1):
                return
            visit.add((r, c))
            q.append([r, c])

        # Enqueue all gates (cells with 0)
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    q.append([r, c])
                    visit.add((r, c))
        dist = 0
        # BFS: expand from all gates simultaneously
        while q:
            for i in range(len(q)):
                r, c = q.popleft()
                grid[r][c] = dist  # Fill distance

                addRoom(r + 1, c)
                addRoom(r - 1, c)
                addRoom(r, c + 1)
                addRoom(r, c - 1)
            dist += 1

# -------------------
# Test Cases
# -------------------
def test_islands_and_treasure():
    sol = Solution()
    INF = 2147483647
    # Test case 1: Example from Leetcode
    grid1 = [
        [INF,  -1,    0,  INF],
        [INF, INF, INF,  -1],
        [INF,  -1, INF,  -1],
        [0,    -1, INF, INF]
    ]
    expected1 = [
        [3,  -1,  0,  1],
        [2,   2,  1, -1],
        [1,  -1,  2, -1],
        [0,  -1,  3,  4]
    ]
    sol.islandsAndTreasure(grid1)
    assert grid1 == expected1
    # Test case 2: All walls
    grid2 = [[-1, -1], [-1, -1]]
    expected2 = [[-1, -1], [-1, -1]]
    sol.islandsAndTreasure(grid2)
    assert grid2 == expected2
    # Test case 3: All gates
    grid3 = [[0, 0], [0, 0]]
    expected3 = [[0, 0], [0, 0]]
    sol.islandsAndTreasure(grid3)
    assert grid3 == expected3
    # Test case 4: No gates
    grid4 = [[INF, INF], [INF, INF]]
    expected4 = [[INF, INF], [INF, INF]]
    sol.islandsAndTreasure(grid4)
    assert grid4 == expected4
    # Test case 5: Single cell gate
    grid5 = [[0]]
    expected5 = [[0]]
    sol.islandsAndTreasure(grid5)
    assert grid5 == expected5
    print("All test cases passed!")

if __name__ == "__main__":
    test_islands_and_treasure()

from typing import List
import heapq

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        """
        Given an N x N grid where each square grid[r][c] represents the elevation at that point,
        return the least time required to swim from the top left to the bottom right.
        You can swim to 4-directionally adjacent squares if the elevation is at most the current time.
        The time taken is the maximum elevation encountered along the path.

        Approach:
        - Use a variation of Dijkstra's algorithm (min-heap/priority queue) to always expand the lowest elevation cell reachable.
        - At each step, move to the neighbor with the smallest possible elevation/time.
        - The answer is the first time we reach the bottom-right cell.

        Time Complexity: O(N^2 * log N)
            - Each cell is pushed/popped from the heap at most once (N^2 cells)
            - Each heap operation is O(log N^2) = O(log N)
        Space Complexity: O(N^2)
            - For the visited set and the heap
        """
        N = len(grid)
        visit = set()
        minH = [[grid[0][0], 0, 0]] # (time or max-height, r, c)
        directions =[[0, 1], [0, -1], [1, 0], [-1, 0]]
        
        visit.add((0, 0))
        while minH:
            t, r, c = heapq.heappop(minH)

            # If we've reached the bottom-right cell, return the time (max elevation on path)
            if r == N - 1 and c == N - 1:
                return t
            
            # Explore all 4 directions
            for dr, dc in directions:
                neiR, neiC = r + dr, c + dc
                # Check bounds and if already visited
                if (neiR < 0 or neiC < 0 or neiR == N or neiC == N or (neiR, neiC) in visit):
                    continue
                visit.add((neiR, neiC))
                # The time to enter the neighbor is the max of current time and neighbor's elevation
                heapq.heappush(minH, [max(t, grid[neiR][neiC]), neiR, neiC])      
        # If unreachable (should not happen for valid inputs)
        return -1  


def test_swim_in_water():
    solution = Solution()
    # Test case 1: Simple 2x2 grid
    grid1 = [
        [0, 2],
        [1, 3]
    ]
    expected1 = 3
    result1 = solution.swimInWater(grid1)
    print(f"Test 1: {result1 == expected1}, Expected: {expected1}, Got: {result1}")

    # Test case 2: 3x3 grid
    grid2 = [
        [0, 1, 2],
        [3, 4, 5],
        [6, 7, 8]
    ]
    expected2 = 8
    result2 = solution.swimInWater(grid2)
    print(f"Test 2: {result2 == expected2}, Expected: {expected2}, Got: {result2}")

    # Test case 3: Path with detour
    grid3 = [
        [0, 2, 1, 3],
        [2, 3, 4, 4],
        [3, 2, 5, 5],
        [6, 7, 8, 9]
    ]
    expected3 = 9  # Corrected expected value
    result3 = solution.swimInWater(grid3)
    print(f"Test 3: {result3 == expected3}, Expected: {expected3}, Got: {result3}")

    # Test case 4: Single cell
    grid4 = [[0]]
    expected4 = 0
    result4 = solution.swimInWater(grid4)
    print(f"Test 4: {result4 == expected4}, Expected: {expected4}, Got: {result4}")

    # Test case 5: 2x2 grid, must wait
    grid5 = [
        [0, 100],
        [1, 2]
    ]
    expected5 = 2  # Corrected expected value
    result5 = solution.swimInWater(grid5)
    print(f"Test 5: {result5 == expected5}, Expected: {expected5}, Got: {result5}")

if __name__ == "__main__":
    test_swim_in_water()  
from typing import List
import heapq

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        """
        Find the minimum cost to connect all points using Manhattan distance.
        
        Approach: Prim's Algorithm for Minimum Spanning Tree (MST)
        1. Build adjacency list with Manhattan distances between all point pairs
        2. Use Prim's algorithm with min-heap to find MST
        3. Start from point 0, add edges with minimum cost until all points connected
        
        Time Complexity: O(n² log n)
        - Building adjacency list: O(n²) for all point pairs
        - Prim's algorithm: O(n² log n) in worst case
          - Each point can be processed at most n times
          - Each heap operation is O(log n)
        
        Space Complexity: O(n²)
        - Adjacency list: O(n²) for storing all edges
        - Min-heap: O(n²) in worst case
        - Visit set: O(n)
        """
        N = len(points)
        
        # Build adjacency list: {point_index: [[cost, neighbor_point], ...]}
        # Each point connects to all other points with Manhattan distance cost
        adj = {i: [] for i in range(N)}
        for i in range(N):
            x1, y1 = points[i]
            for j in range(i + 1, N):
                x2, y2 = points[j]
                # Manhattan distance: |x1-x2| + |y1-y2|
                dist = abs(x1 - x2) + abs(y1 - y2)
                adj[i].append([dist, j])
                adj[j].append([dist, i])
        
        # Prim's Algorithm Implementation
        res = 0  # Total minimum cost
        visit = set()  # Track visited points
        minH = [[0, 0]]  # Min-heap: [cost, point_index], start with point 0
        
        # Continue until all points are connected (MST has N-1 edges)
        while len(visit) < N:
            cost, i = heapq.heappop(minH)  # Get minimum cost edge
            
            # Skip if point already visited (avoid cycles)
            if i in visit:
                continue
                
            # Add cost to result and mark point as visited
            res += cost
            visit.add(i)
            
            # Add all unvisited neighbors to heap
            for neiCost, nei in adj[i]:
                if nei not in visit:
                    heapq.heappush(minH, [neiCost, nei])
        
        return res


# Test cases
def test_min_cost_connect_points():
    """Test cases for minCostConnectPoints function"""
    solution = Solution()
    
    # Test case 1: Simple 3-point triangle
    points1 = [[0, 0], [2, 2], [3, 10]]
    expected1 = 13  # Connect (0,0) to (2,2) = 4, then (2,2) to (3,10) = 9
    result1 = solution.minCostConnectPoints(points1)
    print(f"Test 1: {result1 == expected1}, Expected: {expected1}, Got: {result1}")
    
    # Test case 2: 4 points in square
    points2 = [[3, 12], [-2, 5], [-4, 1]]
    expected2 = 18  # Minimum spanning tree cost
    result2 = solution.minCostConnectPoints(points2)
    print(f"Test 2: {result2 == expected2}, Expected: {expected2}, Got: {result2}")
    
    # Test case 3: Single point
    points3 = [[0, 0]]
    expected3 = 0  # No connections needed
    result3 = solution.minCostConnectPoints(points3)
    print(f"Test 3: {result3 == expected3}, Expected: {expected3}, Got: {result3}")
    
    # Test case 4: Two points
    points4 = [[0, 0], [1, 1]]
    expected4 = 2  # Manhattan distance between points
    result4 = solution.minCostConnectPoints(points4)
    print(f"Test 4: {result4 == expected4}, Expected: {expected4}, Got: {result4}")
    
    # Test case 5: Points in line
    points5 = [[0, 0], [1, 0], [2, 0], [3, 0]]
    expected5 = 3  # Connect consecutive points: 1+1+1 = 3
    result5 = solution.minCostConnectPoints(points5)
    print(f"Test 5: {result5 == expected5}, Expected: {expected5}, Got: {result5}")


if __name__ == "__main__":
    test_min_cost_connect_points()

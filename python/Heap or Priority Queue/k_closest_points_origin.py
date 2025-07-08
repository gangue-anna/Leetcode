from typing import List
import heapq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        """
        Finds the k closest points to the origin (0, 0) using a max-heap of size k.
        
        Approach:
        1. Iterate through each point and compute its squared Euclidean distance from the origin.
        2. Use a max-heap (simulated with negative distances) to keep track of the k closest points seen so far.
        3. For each point:
           - Push (negative distance, point) onto the heap.
           - If the heap size exceeds k, pop the farthest point (the largest negative distance).
        4. After processing all points, the heap contains the k closest points.
        5. Extract and return the points from the heap.

        Time Complexity:
            - O(n log k) where n is the number of points
              (Each push/pop operation is O(log k), and we do this for each point)
        Space Complexity:
            - O(k) for the heap
            - O(k) for the result list
            - Total: O(k)
        """
        # Max-heap to keep the k closest points (store negative distances)
        max_heap = []
        for point in points:
            distance = -(point[0]**2 + point[1]**2)  # Negative for max-heap
            heapq.heappush(max_heap, (distance, point))
            if len(max_heap) > k:
                heapq.heappop(max_heap)  # Remove the farthest point
        # Extract the points from the heap
        return [item[1] for item in max_heap]

# --- Alternate Solution ---
class Solution2:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        """
        Finds the k closest points to the origin (0, 0) using a min-heap of all points.
        
        Approach:
        1. Compute the squared Euclidean distance for each point and pair it with the point.
        2. Heapify the list of (distance, point) pairs to create a min-heap.
        3. Pop k elements from the heap, which will be the k closest points.
        4. Return the points.

        Time Complexity:
            - O(n + k log n): heapify is O(n), each pop is O(log n), k times
        Space Complexity:
            - O(n) for the heap
            - O(k) for the result list
        """
        dist = []
        for point in points:
            distance = point[0]**2 + point[1]**2
            dist.append((distance, point))
        heapq.heapify(dist)
        result = []
        for _ in range(k):
            result.append(heapq.heappop(dist)[1])
        return result

# -------------------
# Test Cases
# -------------------
def test_k_closest_points():
    s1 = Solution()
    s2 = Solution2()
    # Test case 1: Basic
    points = [[1,3],[-2,2],[2,-2]]
    k = 2
    expected = [[-2,2],[2,-2]]
    out1 = s1.kClosest(points, k)
    out2 = s2.kClosest(points, k)
    assert sorted(map(tuple, out1)) == sorted(map(tuple, expected))
    assert sorted(map(tuple, out2)) == sorted(map(tuple, expected))
    # Test case 2: k = 1
    points = [[3,3],[5,-1],[-2,4]]
    k = 1
    expected = [[3,3]]
    out1 = s1.kClosest(points, k)
    out2 = s2.kClosest(points, k)
    assert sorted(map(tuple, out1)) == sorted(map(tuple, expected))
    assert sorted(map(tuple, out2)) == sorted(map(tuple, expected))
    # Test case 3: All points at origin
    points = [[0,0],[0,0],[0,0]]
    k = 2
    expected = [[0,0],[0,0]]
    out1 = s1.kClosest(points, k)
    out2 = s2.kClosest(points, k)
    assert len(out1) == 2 and all(p == [0,0] for p in out1)
    assert len(out2) == 2 and all(p == [0,0] for p in out2)
    # Test case 4: k equals number of points
    points = [[1,2],[2,1],[3,3]]
    k = 3
    expected = [[1,2],[2,1],[3,3]]
    out1 = s1.kClosest(points, k)
    out2 = s2.kClosest(points, k)
    assert sorted(map(tuple, out1)) == sorted(map(tuple, expected))
    assert sorted(map(tuple, out2)) == sorted(map(tuple, expected))
    # Test case 5: Negative coordinates
    points = [[-5,-4],[2,3],[0,0]]
    k = 2
    expected = [[0,0],[2,3]]
    out1 = s1.kClosest(points, k)
    out2 = s2.kClosest(points, k)
    assert sorted(map(tuple, out1)) == sorted(map(tuple, expected))
    assert sorted(map(tuple, out2)) == sorted(map(tuple, expected))
    print("All test cases passed!")

if __name__ == "__main__":
    test_k_closest_points()
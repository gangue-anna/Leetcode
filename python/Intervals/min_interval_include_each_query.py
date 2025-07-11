from typing import List
import heapq

class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        """
        For each query, find the length of the smallest interval from intervals that contains the query.
        If no such interval exists, return -1 for that query.
        
        Approach:
        - Sort intervals by their start point.
        - For each query (in sorted order), add all intervals whose start <= query to a min-heap (by interval length).
        - Remove from the heap any intervals whose end < query (they can't cover the query).
        - The top of the heap (if any) is the smallest interval covering the query.
        - Store results in a dictionary for each query, then return results in the original query order.
        
        Time Complexity: O((N + Q) log N), where N = len(intervals), Q = len(queries)
        - Sorting intervals: O(N log N)
        - Sorting queries: O(Q log Q)
        - Each interval is pushed/popped from the heap at most once: O(N log N)
        - Each query processes the heap: O(Q log N)
        
        Space Complexity: O(N + Q)
        - Heap can store up to N intervals
        - Result dictionary and output list store up to Q results
        
        Args:
            intervals: List[List[int]] - List of intervals [start, end]
            queries: List[int] - List of query points
        Returns:
            List[int] - For each query, the length of the smallest covering interval or -1
        """
        intervals.sort()
        
        minHeap = []  # Min-heap of (interval length, interval end)
        res, i = {}, 0

        for q in sorted(queries):
            # Add all intervals starting before or at q
            while i < len(intervals) and intervals[i][0] <= q:
                l, r = intervals[i]
                heapq.heappush(minHeap, (r - l + 1, r))
                i += 1
            
            # Remove intervals that end before q
            while minHeap and minHeap[0][1] < q:
                heapq.heappop(minHeap)
            # The top of the heap is the smallest interval covering q
            res[q] = minHeap[0][0] if minHeap else -1
        
        # Return results in the original query order
        return [res[q] for q in queries]

# -------------------
# Test Cases
# -------------------
def test_min_interval():
    s = Solution()
    # Test case 1: Basic case
    intervals = [[1,4],[2,4],[3,6],[4,4]]
    queries = [2,3,4,5]
    assert s.minInterval(intervals, queries) == [3, 3, 1, 4], "Failed on basic case"
    # Test case 2: No interval covers query
    intervals = [[1,2],[3,4]]
    queries = [0,5]
    assert s.minInterval(intervals, queries) == [-1, -1], "Failed on no coverage"
    # Test case 3: All intervals cover all queries
    intervals = [[1,10],[2,9],[3,8]]
    queries = [4,5,6]
    assert s.minInterval(intervals, queries) == [6, 6, 6], "Failed on all cover"
    # Test case 4: Overlapping intervals, different lengths
    intervals = [[1,5],[2,6],[3,7]]
    queries = [4]
    assert s.minInterval(intervals, queries) == [5], "Failed on overlapping intervals"
    # Test case 5: Single interval, single query
    intervals = [[1,1]]
    queries = [1]
    assert s.minInterval(intervals, queries) == [1], "Failed on single interval/query"
    # Test case 6: Query at interval boundary
    intervals = [[1,3],[2,4]]
    queries = [1,4]
    assert s.minInterval(intervals, queries) == [3, 3], "Failed on boundary queries"
    # Test case 7: Empty intervals
    intervals = []
    queries = [1,2,3]
    assert s.minInterval(intervals, queries) == [-1, -1, -1], "Failed on empty intervals"
    print("All test cases passed!")

if __name__ == "__main__":
    test_min_interval()



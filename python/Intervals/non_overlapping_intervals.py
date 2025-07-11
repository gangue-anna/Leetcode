from typing import List

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        """
        Find the minimum number of intervals to remove to make the rest non-overlapping.
        
        Approach:
        - Sort the intervals by their start time (default sort).
        - Iterate through the intervals, keeping track of the end of the previous interval.
        - If the current interval starts after or at the end of the previous, update prevEnd.
        - If the current interval overlaps, increment the removal count and update prevEnd to the minimum end (greedy choice to keep the interval with the earliest end).
        
        Time Complexity: O(N log N), where N is the number of intervals
        - Sorting takes O(N log N)
        - The iteration is O(N)
        
        Space Complexity: O(1)
        - Only a constant amount of extra space is used
        
        Args:
            intervals: List[List[int]] - List of intervals
        Returns:
            int - Minimum number of intervals to remove
        """
        intervals.sort()

        res = 0
        prevEnd = intervals[0][1]

        for start, end in intervals[1:]:
            if start >= prevEnd:
                # No overlap, move prevEnd forward
                prevEnd = end
            else:
                # Overlap, increment removal count and keep the interval with the earliest end
                res += 1
                prevEnd = min(end, prevEnd)
        return res

# -------------------
# Test Cases
# -------------------
def test_erase_overlap_intervals():
    s = Solution()
    # Test case 1: Overlapping intervals
    assert s.eraseOverlapIntervals([[1,2],[2,3],[3,4],[1,3]]) == 1, "Failed on basic overlap"
    # Test case 2: No overlap
    assert s.eraseOverlapIntervals([[1,2],[2,3],[3,4]]) == 0, "Failed on no overlap"
    # Test case 3: All overlap
    assert s.eraseOverlapIntervals([[1,100],[1,11],[11,22],[2,12]]) == 2, "Failed on all overlap"
    # Test case 4: Single interval
    assert s.eraseOverlapIntervals([[1,2]]) == 0, "Failed on single interval"
    # Test case 5: Nested intervals
    assert s.eraseOverlapIntervals([[1,10],[2,3],[3,4],[4,5]]) == 1, "Failed on nested intervals"
    # Test case 6: Unsorted input
    assert s.eraseOverlapIntervals([[5,6],[1,3],[2,4]]) == 1, "Failed on unsorted input"
    print("All test cases passed!")

if __name__ == "__main__":
    test_erase_overlap_intervals()
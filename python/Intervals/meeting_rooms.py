from typing import List

class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        """
        Determine if a person can attend all meetings (i.e., no overlaps between intervals).
        
        Approach:
        - Sort the intervals by their start time.
        - Iterate through the sorted intervals and check if any interval starts before the previous one ends.
        - If any such overlap is found, return False (cannot attend all meetings).
        - If no overlaps are found, return True.
        
        Time Complexity: O(n log n), where n is the number of intervals
        - Sorting the intervals takes O(n log n)
        - The overlap check is O(n)
        
        Space Complexity: O(1) (ignoring input)
        - Sorting is in-place and only a constant amount of extra space is used
        
        Args:
            intervals: List[Interval] - List of meeting intervals
        Returns:
            bool - True if a person can attend all meetings, False otherwise
        """
        if not intervals:
            return True
        intervals.sort(key=lambda x: x.start)  # Sort by start time
        for i in range(1, len(intervals)):
            # If the current meeting starts before the previous one ends, there is an overlap
            if intervals[i-1].end > intervals[i].start:
                return False
        return True

# -------------------
# Test Cases
# -------------------
def test_meeting_rooms():
    s = Solution()
    # Test case 1: No overlap
    intervals = [Interval(0, 30), Interval(35, 40), Interval(45, 50)]
    assert s.canAttendMeetings(intervals) == True, "Failed on no overlap"
    # Test case 2: Overlap
    intervals = [Interval(0, 30), Interval(25, 40)]
    assert s.canAttendMeetings(intervals) == False, "Failed on overlap"
    # Test case 3: Single interval
    intervals = [Interval(5, 10)]
    assert s.canAttendMeetings(intervals) == True, "Failed on single interval"
    # Test case 4: Empty list
    intervals = []
    assert s.canAttendMeetings(intervals) == True, "Failed on empty list"
    # Test case 5: Touching intervals (no overlap)
    intervals = [Interval(1, 5), Interval(5, 10)]
    assert s.canAttendMeetings(intervals) == True, "Failed on touching intervals"
    # Test case 6: Multiple overlaps
    intervals = [Interval(1, 4), Interval(2, 5), Interval(7, 9)]
    assert s.canAttendMeetings(intervals) == False, "Failed on multiple overlaps"
    # Test case 7: All intervals overlap
    intervals = [Interval(1, 10), Interval(2, 9), Interval(3, 8)]
    assert s.canAttendMeetings(intervals) == False, "Failed on all overlap"
    # Test case 8: Intervals with same start and end
    intervals = [Interval(1, 1), Interval(2, 2), Interval(3, 3)]
    assert s.canAttendMeetings(intervals) == True, "Failed on zero-length intervals"
    print("All test cases passed!")

if __name__ == "__main__":
    test_meeting_rooms()
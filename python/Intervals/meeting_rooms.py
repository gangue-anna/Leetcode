from typing import List

class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end


class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        """
        Determine if a person can attend all meetings (no overlaps).
        Approach:
        - Sort intervals by start time.
        - Check for any overlap between consecutive intervals.
        - If any overlap, return False. Otherwise, return True.
        Time Complexity: O(n log n) for sorting
        Space Complexity: O(1) (ignoring input)
        """
        if not intervals:
            return True
        intervals.sort(key=lambda x: x.start)
        for i in range(1, len(intervals)):
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
    assert s.canAttendMeetings(intervals) == True
    # Test case 2: Overlap
    intervals = [Interval(0, 30), Interval(25, 40)]
    assert s.canAttendMeetings(intervals) == False
    # Test case 3: Single interval
    intervals = [Interval(5, 10)]
    assert s.canAttendMeetings(intervals) == True
    # Test case 4: Empty list
    intervals = []
    assert s.canAttendMeetings(intervals) == True
    # Test case 5: Touching intervals (no overlap)
    intervals = [Interval(1, 5), Interval(5, 10)]
    assert s.canAttendMeetings(intervals) == True
    # Test case 6: Multiple overlaps
    intervals = [Interval(1, 4), Interval(2, 5), Interval(7, 9)]
    assert s.canAttendMeetings(intervals) == False
    print("All test cases passed!")

if __name__ == "__main__":
    test_meeting_rooms()
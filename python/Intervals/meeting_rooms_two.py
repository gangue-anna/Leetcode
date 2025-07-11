from typing import List

# Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        """
        Find the minimum number of meeting rooms required to accommodate all meetings.
        
        Approach:
        - Extract and sort the start and end times of all intervals separately.
        - Use two pointers to traverse the start and end times:
          - If the next meeting starts before the earliest ending meeting ends, increment room count.
          - Otherwise, a meeting has ended, so decrement room count and move the end pointer.
        - Track the maximum number of rooms needed at any time.
        
        Time Complexity: O(N log N), where N is the number of intervals
        - Sorting the start and end times takes O(N log N)
        - The two-pointer traversal is O(N)
        
        Space Complexity: O(N)
        - Storing the start and end times arrays
        
        Args:
            intervals: List[Interval] - List of meeting intervals
        Returns:
            int - Minimum number of meeting rooms required
        """
        start = sorted([i.start for i in intervals])
        end = sorted([i.end for i in intervals])

        res, count = 0, 0
        s, e = 0, 0

        while s < len(intervals):
            # If the next meeting starts before the earliest ending meeting ends, need a new room
            if start[s] < end[e]:
                s += 1
                count += 1
            else:
                # A meeting has ended, free up a room
                e += 1
                count -= 1
            res = max(res, count)
        return res

# -------------------
# Test Cases
# -------------------
def test_min_meeting_rooms():
    s = Solution()
    # Test case 1: No overlap
    intervals = [Interval(0, 30), Interval(35, 40), Interval(45, 50)]
    assert s.minMeetingRooms(intervals) == 1, "Failed on no overlap"
    # Test case 2: Overlap
    intervals = [Interval(0, 30), Interval(25, 40)]
    assert s.minMeetingRooms(intervals) == 2, "Failed on overlap"
    # Test case 3: All overlap
    intervals = [Interval(0, 10), Interval(0, 10), Interval(0, 10)]
    assert s.minMeetingRooms(intervals) == 3, "Failed on all overlap"
    # Test case 4: Single interval
    intervals = [Interval(5, 10)]
    assert s.minMeetingRooms(intervals) == 1, "Failed on single interval"
    # Test case 5: Touching intervals (no overlap)
    intervals = [Interval(1, 5), Interval(5, 10), Interval(10, 15)]
    assert s.minMeetingRooms(intervals) == 1, "Failed on touching intervals"
    # Test case 6: Multiple overlaps
    intervals = [Interval(1, 4), Interval(2, 5), Interval(7, 9)]
    assert s.minMeetingRooms(intervals) == 2, "Failed on multiple overlaps"
    # Test case 7: Empty list
    intervals = []
    assert s.minMeetingRooms(intervals) == 0, "Failed on empty list"
    print("All test cases passed!")

if __name__ == "__main__":
    test_min_meeting_rooms()
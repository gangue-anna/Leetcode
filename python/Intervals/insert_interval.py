from typing import List

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        """
        Insert a new interval into a list of non-overlapping intervals and merge if necessary.
        
        Approach:
        - Iterate through the intervals:
          - If the new interval ends before the current interval starts, insert the new interval and return the result with the rest of the intervals appended.
          - If the new interval starts after the current interval ends, add the current interval to the result.
          - If the intervals overlap, merge them by updating the new interval to the min start and max end.
        - After the loop, add the last new interval (which may have been merged multiple times).
        
        Time Complexity: O(N), where N is the number of intervals
        - Each interval is visited at most once
        
        Space Complexity: O(N)
        - The result list stores up to N+1 intervals
        
        Args:
            intervals: List[List[int]] - List of non-overlapping intervals sorted by start time
            newInterval: List[int] - The interval to insert
        Returns:
            List[List[int]] - The merged list of intervals
        """
        res = []
        
        for i in range(len(intervals)):
            # If newInterval is before the current interval, insert and return
            if newInterval[1] < intervals[i][0]:
                res.append(newInterval)
                return res + intervals[i: ]
            # If newInterval is after the current interval, add current interval
            elif newInterval[0] > intervals[i][1]:
                res.append(intervals[i])
            else:
                # Overlapping intervals, merge them
                newInterval = [min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])]

        # Add the last interval (merged or not)
        res.append(newInterval)   
        return res

# -------------------
# Test Cases
# -------------------
def test_insert_interval():
    s = Solution()
    # Test case 1: Insert with no overlap
    assert s.insert([[1,3],[6,9]], [2,5]) == [[1,5],[6,9]], "Failed on [[1,3],[6,9]], [2,5]"
    # Test case 2: Insert at the end
    assert s.insert([[1,2],[3,5],[6,7],[8,10],[12,16]], [17,19]) == [[1,2],[3,5],[6,7],[8,10],[12,16],[17,19]], "Failed on insert at end"
    # Test case 3: Insert at the beginning
    assert s.insert([[3,5],[6,7],[8,10],[12,16]], [1,2]) == [[1,2],[3,5],[6,7],[8,10],[12,16]], "Failed on insert at beginning"
    # Test case 4: Insert with full overlap
    assert s.insert([[1,2],[3,5],[6,7],[8,10],[12,16]], [4,8]) == [[1,2],[3,10],[12,16]], "Failed on full overlap"
    # Test case 5: Insert with partial overlap
    assert s.insert([[1,5]], [2,3]) == [[1,5]], "Failed on partial overlap"
    # Test case 6: Insert with no intervals
    assert s.insert([], [5,7]) == [[5,7]], "Failed on empty intervals"
    # Test case 7: Insert covers all
    assert s.insert([[2,3],[5,7]], [1,10]) == [[1,10]], "Failed on insert covers all"
    # Test case 8: Insert in the middle
    assert s.insert([[1,2],[3,5],[6,7],[8,10],[12,16]], [7,8]) == [[1,2],[3,5],[6,10],[12,16]], "Failed on insert in the middle"
    print("All test cases passed!")

if __name__ == "__main__":
    test_insert_interval()

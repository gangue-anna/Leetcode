from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        """
        Merge all overlapping intervals in a list of intervals.
        
        Approach:
        - Sort the intervals by their start time.
        - Initialize the output list with the first interval.
        - Iterate through the remaining intervals:
          - If the current interval overlaps with the last interval in output, merge them by updating the end.
          - Otherwise, append the current interval to output.
        - Return the merged list.
        
        Time Complexity: O(N log N), where N is the number of intervals
        - Sorting the intervals takes O(N log N)
        - The merge pass is O(N)
        
        Space Complexity: O(N)
        - The output list stores up to N intervals
        
        Args:
            intervals: List[List[int]] - List of intervals
        Returns:
            List[List[int]] - Merged list of intervals
        """
        intervals.sort(key = lambda i: i[0])  # Sort by start time
        output = [intervals[0]]

        for start, end in intervals[1: ]:
            lastEnd = output[-1][1]

            if start <= lastEnd:
                # Overlapping intervals, merge them
                output[-1][1] = max(lastEnd, end)
            else:
                # No overlap, add new interval
                output.append([start, end])
            
        return output

# -------------------
# Test Cases
# -------------------
def test_merge_intervals():
    s = Solution()
    # Test case 1: Overlapping intervals
    assert s.merge([[1,3],[2,6],[8,10],[15,18]]) == [[1,6],[8,10],[15,18]], "Failed on overlapping intervals"
    # Test case 2: No overlap
    assert s.merge([[1,2],[3,4],[5,6]]) == [[1,2],[3,4],[5,6]], "Failed on no overlap"
    # Test case 3: All intervals overlap
    assert s.merge([[1,4],[2,3],[3,5]]) == [[1,5]], "Failed on all overlap"
    # Test case 4: Single interval
    assert s.merge([[1,5]]) == [[1,5]], "Failed on single interval"
    # Test case 5: Already merged
    assert s.merge([[1,5],[6,8]]) == [[1,5],[6,8]], "Failed on already merged"
    # Test case 6: Nested intervals
    assert s.merge([[1,10],[2,3],[4,5],[6,7]]) == [[1,10]], "Failed on nested intervals"
    # Test case 7: Unsorted input
    assert s.merge([[5,6],[1,3],[2,4]]) == [[1,4],[5,6]], "Failed on unsorted input"
    print("All test cases passed!")

if __name__ == "__main__":
    test_merge_intervals()
 

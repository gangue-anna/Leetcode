from typing import List

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        """
        Find the area of the largest rectangle in a histogram.
        Approach:
        - Use a monotonic stack to keep track of increasing heights.
        - For each bar, pop from stack until the current bar is taller, calculating area for each popped bar.
        - After processing all bars, calculate area for remaining bars in stack.
        Time Complexity: O(n)
        Space Complexity: O(n)
        """
        maxArea = 0
        stack = [] # pair: [index, height]
        for i, h in enumerate(heights):
            start = i
            while stack and stack[-1][1] > h:
                index, height = stack.pop()
                maxArea = max(maxArea, height * (i - index))
                start = index
            stack.append((start, h))
        for i, h in stack:
            maxArea = max(maxArea, h * (len(heights) - i))
        return maxArea

# -------------------
# Test Cases
# -------------------
def test_largest_rectangle_area():
    s = Solution()
    # Test case 1: Example
    assert s.largestRectangleArea([2,1,5,6,2,3]) == 10
    # Test case 2: All same height
    assert s.largestRectangleArea([2,2,2,2]) == 8
    # Test case 3: Increasing heights
    assert s.largestRectangleArea([1,2,3,4,5]) == 9
    # Test case 4: Decreasing heights
    assert s.largestRectangleArea([5,4,3,2,1]) == 9
    # Test case 5: Single bar
    assert s.largestRectangleArea([7]) == 7
    # Test case 6: Empty list
    assert s.largestRectangleArea([]) == 0
    # Test case 7: Zero heights
    assert s.largestRectangleArea([0,0,0]) == 0
    print("All test cases passed!")

if __name__ == "__main__":
    test_largest_rectangle_area()

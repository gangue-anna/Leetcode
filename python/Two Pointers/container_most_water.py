from typing import List

class Solution:
    def maxArea(self, heights: List[int]) -> int:
        """
        Find the maximum area of water a container can store using two pointers.
        Time Complexity: O(n)
        Space Complexity: O(1)
        """
        # Initialize max_area to track the largest area found
        max_area = 0

        # Initialize two pointers at both ends of the array
        l, r = 0, len(heights) - 1
        
        # Continue until pointers meet
        while l < r:
            # Calculate width (distance between pointers)
            width = r - l

            # Calculate height (minimum of the two lines)
            height = min(heights[l], heights[r])

            # Calculate current area
            area = width * height
            # Update max_area if current area is larger
            max_area = max(area, max_area)

            # Move the pointer pointing to the shorter line
            # This is because:
            # 1. The area is limited by the shorter line
            # 2. Moving the shorter line might give us a better area
            # 3. Moving the longer line can only decrease the area
            if heights[l] < heights[r]:
                l += 1
            elif heights[l] > heights[r]:
                r -= 1
            else:
                # If both lines are equal, move either pointer
                # (in this case, we move the left pointer)
                l += 1
        
        return max_area

# -------------------
# Test Cases
# -------------------
def test_max_area():
    s = Solution()
    # Test case 1: Example
    heights = [1,8,6,2,5,4,8,3,7]
    assert s.maxArea(heights) == 49
    # Test case 2: Two lines
    heights = [1,1]
    assert s.maxArea(heights) == 1
    # Test case 3: Increasing heights
    heights = [1,2,3,4,5]
    assert s.maxArea(heights) == 6
    # Test case 4: Decreasing heights
    heights = [5,4,3,2,1]
    assert s.maxArea(heights) == 6
    # Test case 5: All same height
    heights = [3,3,3,3]
    assert s.maxArea(heights) == 9
    # Test case 6: Single line (invalid, should be 0)
    heights = [5]
    assert s.maxArea(heights) == 0
    # Test case 7: Empty input
    heights = []
    assert s.maxArea(heights) == 0
    print("All test cases passed!")

if __name__ == "__main__":
    test_max_area()
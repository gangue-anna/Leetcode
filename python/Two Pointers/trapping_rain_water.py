from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        """
        Compute how much water can be trapped after raining using two pointers.
        Time Complexity: O(n)
        Space Complexity: O(1)
        """
        # Edge case: empty array
        if not height:
            return 0
        # Initialize two pointers and their max heights
        l, r = 0, len(height) - 1
        leftMax, rightMax = height[l], height[r]
        res = 0
        # Continue until pointers meet
        while l < r:
            # If left max is smaller, process left side
            # This is because the water level is limited by the smaller max
            if leftMax < rightMax:
                l += 1 
                leftMax = max(leftMax, height[l])
                res += leftMax - height[l]
            # If right max is smaller or equal, process right side
            else:
                r -= 1
                rightMax = max(rightMax, height[r])
                res += rightMax - height[r]
        return res

# -------------------
# Test Cases
# -------------------
def test_trap():
    s = Solution()
    # Test case 1: Example
    height = [0,1,0,2,1,0,1,3,2,1,2,1]
    assert s.trap(height) == 6
    # Test case 2: No water
    height = [0,1,2,3,4]
    assert s.trap(height) == 0
    # Test case 3: All same height
    height = [2,2,2,2]
    assert s.trap(height) == 0
    # Test case 4: Single bar
    height = [4]
    assert s.trap(height) == 0
    # Test case 5: Empty input
    height = []
    assert s.trap(height) == 0
    # Test case 6: Multiple valleys
    height = [4,2,0,3,2,5]
    assert s.trap(height) == 9
    print("All test cases passed!")

if __name__ == "__main__":
    test_trap()

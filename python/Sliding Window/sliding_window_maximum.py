from typing import List
from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        """
        Find maximum values in sliding windows of size k using a simple approach.
        
        Approach:
        1. Slide a window of size k through the array
        2. For each window, find the maximum value
        3. Append maximum to result array
        4. Move window one position to the right
        
        Time Complexity: O(n*k) where n is length of nums
        - For each window (n-k+1 windows), we find max in O(k) time
        
        Space Complexity: O(1) excluding output array
        - Only use a few variables regardless of input size
        """
        if not nums or k == 0:
            return []
            
        result = []  # Store maximum values for each window
        
        # Slide window through array
        for i in range(len(nums) - k + 1):
            # Find maximum in current window
            window_max = max(nums[i:i+k])
            result.append(window_max)
            
        return result

class Solution2:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        """
        Find maximum values in sliding windows of size k using a deque for O(n) time.
        Approach:
        - Use a deque to store indices of useful elements for each window.
        - Remove indices that are out of the current window or less than the current value.
        Time Complexity: O(n)
        Space Complexity: O(k)
        """
        if not nums or k == 0:
            return []
        result = []
        dq = deque()  # Store indices
        for i, num in enumerate(nums):
            # Remove indices out of window
            while dq and dq[0] < i - k + 1:
                dq.popleft()
            # Remove indices whose values are less than current num
            while dq and nums[dq[-1]] < num:
                dq.pop()
            dq.append(i)
            # Append max for current window
            if i >= k - 1:
                result.append(nums[dq[0]])
        return result

# -------------------
# Test Cases
# -------------------
def test_sliding_window_maximum():
    s1 = Solution()
    s2 = Solution2()
    # Test case 1: Basic
    nums = [1,3,-1,-3,5,3,6,7]
    k = 3
    expected = [3,3,5,5,6,7]
    assert s1.maxSlidingWindow(nums, k) == expected
    assert s2.maxSlidingWindow(nums, k) == expected
    # Test case 2: k = 1
    nums = [4,2,12,3]
    k = 1
    expected = [4,2,12,3]
    assert s1.maxSlidingWindow(nums, k) == expected
    assert s2.maxSlidingWindow(nums, k) == expected
    # Test case 3: k equals array length
    nums = [9,11]
    k = 2
    expected = [11]
    assert s1.maxSlidingWindow(nums, k) == expected
    assert s2.maxSlidingWindow(nums, k) == expected
    # Test case 4: All elements same
    nums = [2,2,2,2]
    k = 2
    expected = [2,2,2]
    assert s1.maxSlidingWindow(nums, k) == expected
    assert s2.maxSlidingWindow(nums, k) == expected
    # Test case 5: Empty array
    nums = []
    k = 3
    expected = []
    assert s1.maxSlidingWindow(nums, k) == expected
    assert s2.maxSlidingWindow(nums, k) == expected
    print("All test cases passed!")

if __name__ == "__main__":
    test_sliding_window_maximum()
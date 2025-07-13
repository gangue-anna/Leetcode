from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        """
        Find the contiguous subarray with the largest sum (Kadane's Algorithm).
        
        Approach:
        - Initialize maxSub to the first element (handles all-negative arrays).
        - Use curSum to track the current subarray sum.
        - For each number:
          - If curSum is negative, reset it to 0 (start a new subarray).
          - Add the current number to curSum.
          - Update maxSub if curSum is greater than maxSub.
        - Return maxSub as the result.
        
        Time Complexity: O(N), where N is the length of nums
        - We iterate through the array once
        
        Space Complexity: O(1)
        - Only a constant amount of extra space is used
        
        Args:
            nums: List[int] - List of integers
        Returns:
            int - Maximum subarray sum
        """
        maxSub = nums[0]
        curSum = 0

        for n in nums:
            if curSum < 0:
                curSum = 0  # Start a new subarray if the current sum is negative
            curSum += n
            maxSub = max(maxSub, curSum)
        return maxSub

# -------------------
# Test Cases
# -------------------
def test_max_subarray():
    s = Solution()
    # Test case 1: Mixed positive and negative
    assert s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]) == 6, "Failed on mixed array"
    # Test case 2: All positive
    assert s.maxSubArray([1,2,3,4,5]) == 15, "Failed on all positive"
    # Test case 3: All negative
    assert s.maxSubArray([-1,-2,-3,-4]) == -1, "Failed on all negative"
    # Test case 4: Single element
    assert s.maxSubArray([5]) == 5, "Failed on single element"
    # Test case 5: Single negative element
    assert s.maxSubArray([-5]) == -5, "Failed on single negative element"
    # Test case 6: Large negative followed by positives
    assert s.maxSubArray([-10,2,3,4]) == 9, "Failed on large negative followed by positives"
    # Test case 7: Zeros and positives
    assert s.maxSubArray([0,0,0,1]) == 1, "Failed on zeros and positives"
    # Test case 8: Zeros and negatives
    assert s.maxSubArray([0,0,0,-1]) == 0, "Failed on zeros and negatives"
    print("All test cases passed!")

if __name__ == "__main__":
    test_max_subarray()
from typing import List

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # LIS[i]: length of the longest increasing subsequence starting at index i
        LIS = [1] * len(nums)

        # Iterate backwards through the array
        for i in range(len(nums) - 1, -1, -1):
            for j in range(i + 1, len(nums)):
                # If nums[j] can extend the subsequence at i
                if nums[i] < nums[j]:
                    LIS[i] = max(LIS[i], 1 + LIS[j])
        
        # The answer is the maximum value in LIS
        return max(LIS)

# Time Complexity: O(n^2), where n is the length of nums. Two nested loops.
# Space Complexity: O(n), for the LIS array.

# -------------------
# Test Cases
# -------------------
def test_length_of_lis():
    s = Solution()
    # Test case 1: Example from Leetcode
    assert s.lengthOfLIS([10,9,2,5,3,7,101,18]) == 4  # [2,3,7,101]
    # Test case 2: All increasing
    assert s.lengthOfLIS([1,2,3,4,5]) == 5
    # Test case 3: All decreasing
    assert s.lengthOfLIS([5,4,3,2,1]) == 1
    # Test case 4: Single element
    assert s.lengthOfLIS([7]) == 1
    # Test case 5: Duplicates
    assert s.lengthOfLIS([2,2,2,2,2]) == 1
    # Test case 6: Mixed
    assert s.lengthOfLIS([0,1,0,3,2,3]) == 4
    print("All test cases passed!")

if __name__ == "__main__":
    test_length_of_lis()

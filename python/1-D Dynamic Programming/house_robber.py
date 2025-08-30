from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        # rob1: max money that can be robbed up to the house before the previous one
        # rob2: max money that can be robbed up to the previous house
        rob1, rob2 = 0, 0

        # Iterate through each house's money
        for n in nums:
            # For each house, decide to either:
            # 1. Rob it (add current house's money to rob1, which is the max up to house i-2)
            # 2. Skip it (keep rob2, which is the max up to house i-1)
            temp = max(n + rob1, rob2)
            rob1 = rob2  # Move rob2 to rob1 for next iteration
            rob2 = temp  # Update rob2 to the new max
        return rob2  # rob2 contains the max money that can be robbed

# Time Complexity: O(n), where n is the number of houses (nums)
# Space Complexity: O(1), since only two variables are used regardless of input size

class Solution2:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        if len(nums) == 2:
            return max(nums[0], nums[1])

        dp = [0] * len(nums)
        dp[0] = nums[0]
        dp[1] = max(nums[1], nums[0])
        n = len(nums)

        for i in range(2, n):
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1])
        
        return dp[n - 1]

# -------------------
# Test Cases
# -------------------
def test_house_robber():
    s = Solution()
    # Test case 1: Example from Leetcode
    assert s.rob([1,2,3,1]) == 4  # Rob house 1 and 3 (1 + 3)
    # Test case 2: Another example
    assert s.rob([2,7,9,3,1]) == 12  # Rob house 1, 3, 5 (2 + 9 + 1)
    # Test case 3: Single house
    assert s.rob([5]) == 5
    # Test case 4: Two houses
    assert s.rob([2,1]) == 2
    # Test case 5: All houses have same value
    assert s.rob([2,2,2,2]) == 4
    # Test case 6: Empty list
    assert s.rob([]) == 0
    print("All test cases passed!")

if __name__ == "__main__":
    test_house_robber()

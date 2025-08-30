from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        # Edge case: if there is only one house, rob it
        if len(nums) == 1:
            return nums[0]
        # In a circular street, the first and last houses are adjacent.
        # So, we can't rob both. We consider two scenarios:
        # 1. Rob houses from 0 to n-2 (exclude last house)
        # 2. Rob houses from 1 to n-1 (exclude first house)
        # The answer is the max of these two scenarios.
        return max(self.helper(nums[1:]), self.helper(nums[:-1]))

    def helper(self, nums):
        # Standard House Robber I DP for a linear street
        rob1, rob2  = 0, 0
        for n in nums:
            # For each house, decide to rob it (rob1 + n) or skip it (rob2)
            newRob = max(rob1 + n, rob2)
            rob1 = rob2
            rob2 = newRob
        return rob2

# Time Complexity: O(n), where n is the number of houses (nums)
# Space Complexity: O(1), since only a constant amount of space is used

class Solution2:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        if len(nums) == 2:
            return max(nums[0], nums[1])

        def rob_linear(houses):
            n = len(houses)
            dp = [0] * n
            dp[0] = houses[0]
            dp[1] = max(houses[0], houses[1])
            
            for i in range(2, n):
                dp[i] = max(houses[i] + dp[i - 2], dp[i - 1])
            
            return dp[-1]

        # Case 1: Exclude last house
        rob1 = rob_linear(nums[:-1])
        # Case 2: Exclude first house
        rob2 = rob_linear(nums[1:])
        
        return max(rob1, rob2)

# -------------------
# Test Cases
# -------------------
def test_house_robber_two():
    s = Solution()
    # Test case 1: Example from Leetcode
    assert s.rob([2,3,2]) == 3  # Rob house 2
    # Test case 2: Another example
    assert s.rob([1,2,3,1]) == 4  # Rob house 2 and 4
    # Test case 3: Single house
    assert s.rob([5]) == 5
    # Test case 4: Two houses
    assert s.rob([2,3]) == 3
    # Test case 5: All houses have same value
    assert s.rob([2,2,2,2]) == 4
    # Test case 6: Empty list
    assert s.rob([]) == 0
    print("All test cases passed!")

if __name__ == "__main__":
    test_house_robber_two()

from typing import List

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # If the total sum is odd, we cannot partition into two equal subsets
        if sum(nums) % 2:
            return False
        
        # dp: set of all possible subset sums
        dp = set()
        dp.add(0)
        target = sum(nums) // 2

        # Iterate through the numbers backwards
        for i in range(len(nums) - 1, -1, -1):
            nextDP = set()
            for t in dp:
                # If we can reach the target sum, return True
                if (t + nums[i]) == target:
                    return True
                # Add both possibilities: including or excluding nums[i]
                nextDP.add(t + nums[i])
                nextDP.add(t)
            dp = nextDP
        # After processing all numbers, check if target is in dp
        return True if target in dp else False

# Time Complexity: O(n * s), where n is the number of elements and s is the target sum (sum(nums)//2).
# Space Complexity: O(s), for the set of possible subset sums.

# -------------------
# Test Cases
# -------------------
def test_partition_equal_subset_sum():
    s = Solution()
    # Test case 1: Example from Leetcode
    assert s.canPartition([1,5,11,5]) == True  # [1,5,5] and [11]
    # Test case 2: Cannot partition
    assert s.canPartition([1,2,3,5]) == False
    # Test case 3: All elements same
    assert s.canPartition([2,2,2,2]) == True
    # Test case 4: Single element
    assert s.canPartition([1]) == False
    # Test case 5: Empty list
    assert s.canPartition([]) == True  # Trivially partitionable
    # Test case 6: Large input, possible
    assert s.canPartition([100,100]) == True
    print("All test cases passed!")

if __name__ == "__main__":
    test_partition_equal_subset_sum()



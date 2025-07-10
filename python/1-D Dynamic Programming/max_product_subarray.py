from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # res: stores the maximum product found so far
        res = max(nums)
        # curMin, curMax: track the minimum and maximum product ending at the current position
        curMin, curMax = 1, 1

        for n in nums:
            if n == 0:
                # Reset when encountering zero, as product will be zero
                curMin, curMax = 1, 1
                continue
            temp = curMax * n
            # curMax: max product ending here (could be n, n*curMax, or n*curMin)
            curMax = max(n * curMax, n * curMin, n)
            # curMin: min product ending here (could be n, n*curMax, or n*curMin)
            curMin = min(temp, n * curMin, n)
            # Update result with the best found so far
            res = max(res, curMax, curMin)
        return res

# Time Complexity: O(n), where n is the length of nums. We traverse the list once.
# Space Complexity: O(1), since only a constant amount of extra space is used.

# -------------------
# Test Cases
# -------------------
def test_max_product_subarray():
    s = Solution()
    # Test case 1: Example from Leetcode
    assert s.maxProduct([2,3,-2,4]) == 6  # [2,3]
    # Test case 2: Contains zero
    assert s.maxProduct([-2,0,-1]) == 0
    # Test case 3: All negative numbers
    assert s.maxProduct([-2,-3,-4]) == 12  # [-2,-3,-4]
    # Test case 4: Single element
    assert s.maxProduct([0]) == 0
    assert s.maxProduct([5]) == 5
    # Test case 5: Mix of positive and negative
    assert s.maxProduct([2,-5,-2,-4,3]) == 24  # [-2,-4,3]
    # Test case 6: All zeros
    assert s.maxProduct([0,0,0]) == 0
    print("All test cases passed!")

if __name__ == "__main__":
    test_max_product_subarray()

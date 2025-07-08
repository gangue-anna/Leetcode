from typing import List

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        """
        Approach:
        - Use the sum formula for the first n natural numbers: sum = n*(n+1)//2
        - Subtract the sum of the input array from the expected sum to find the missing number.
        - This is more efficient than removing elements from a list.

        Time Complexity: O(n)
        Space Complexity: O(1)
        """
        n = len(nums)
        expected_sum = n * (n + 1) // 2
        actual_sum = sum(nums)
        return expected_sum - actual_sum
    
class Solution2:
    def missingNumber(self, nums: List[int]) -> int:
        """
        Approach:
        - Use a single variable to accumulate the difference between indices and values, starting from n.
        - The result will be the missing number.

        Time Complexity: O(n)
        Space Complexity: O(1)
        """
        res = len(nums)
        for i in range(len(nums)):
            res += (i - nums[i])
        return res

# -------------------
# Test Cases
# -------------------
def test_missing_number():
    s1 = Solution()
    s2 = Solution2()
    # Test case 1: Example from Leetcode
    nums1 = [3,0,1]
    assert s1.missingNumber(nums1) == 2
    assert s2.missingNumber(nums1) == 2
    # Test case 2: No missing (should not happen per constraints)
    nums2 = [0,1,2,3]
    assert s1.missingNumber(nums2) == 4
    assert s2.missingNumber(nums2) == 4
    # Test case 3: Missing 0
    nums3 = [1,2,3]
    assert s1.missingNumber(nums3) == 0
    assert s2.missingNumber(nums3) == 0
    # Test case 4: Missing n
    nums4 = [0,1,2]
    assert s1.missingNumber(nums4) == 3
    assert s2.missingNumber(nums4) == 3
    # Test case 5: Single element
    nums5 = [0]
    assert s1.missingNumber(nums5) == 1
    assert s2.missingNumber(nums5) == 1
    print("All test cases passed!")

if __name__ == "__main__":
    test_missing_number()
        
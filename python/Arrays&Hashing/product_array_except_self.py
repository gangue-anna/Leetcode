from typing import List

class Solution:
    def productExceptSelf(self, nums : List[int]) -> List[int]:
        """
        Approach:
        - Use two arrays (prefix and suffix) to store the product of all elements to the left and right of each index.
        - prefix[i] contains the product of all elements to the left of i.
        - suffix[i] contains the product of all elements to the right of i.
        - The result for each index is prefix[i] * suffix[i].
        - This avoids using division and handles zeros in the input.

        Time Complexity: O(n), where n is the length of nums (three passes through the array).
        Space Complexity: O(n), for the prefix, suffix, and result arrays. Can be optimized to O(1) extra space (excluding output).
        """
        prefix = [1] * len(nums)
        suffix = [1] * len(nums)

        for i, n in enumerate(nums):
            if i == 0:
                pass
            else:
                prefix[i] = prefix[i-1] * nums[i-1]

        for i in range(len(nums)-1, -1, -1):
            if i == len(nums)-1:
                pass
            else:
                suffix[i] = suffix[i+1] * nums[i+1]

        result = []
        for i in range(len(nums)):
            result.append(prefix[i] * suffix[i])
        return result

# -------------------
# Test Cases
# -------------------
def test_product_array_except_self():
    sol = Solution()
    # Test case 1: Example from Leetcode
    nums1 = [1,2,3,4]
    assert sol.productExceptSelf(nums1) == [24,12,8,6]
    # Test case 2: Contains zero
    nums2 = [0,1,2,3]
    assert sol.productExceptSelf(nums2) == [6,0,0,0]
    # Test case 3: All ones
    nums3 = [1,1,1,1]
    assert sol.productExceptSelf(nums3) == [1,1,1,1]
    # Test case 4: Single element
    nums4 = [42]
    assert sol.productExceptSelf(nums4) == [1]
    # Test case 5: Two elements
    nums5 = [2,3]
    assert sol.productExceptSelf(nums5) == [3,2]
    print("All test cases passed!")

if __name__ == "__main__":
    test_product_array_except_self()

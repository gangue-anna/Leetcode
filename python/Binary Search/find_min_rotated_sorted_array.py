from typing import List

class Solution:
    def findMin(self, nums: List[int]) -> int:
        """
        Approach:
        - Handles edge cases: single element and not rotated.
        - Uses linear search to find the inflection point where the next element is smaller than the current.
        - Returns the minimum element found.

        Time Complexity: O(n) in the worst case (linear search).
        Space Complexity: O(1).
        """
        # Edge case: array with one element
        if len(nums) == 1:
            return nums[0]
        # Edge case: array is not rotated
        if nums[0] < nums[-1]:
            return nums[0]
        # Linear search approach
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                return nums[i + 1]
        return nums[0]

class Solution2:
    def findMin(self, nums: List[int]) -> int:
        """
        Approach:
        - Uses binary search to find the minimum in a rotated sorted array.
        - Compares middle element with left and right to determine which side to search next.
        - Updates the result with the minimum value found so far.

        Time Complexity: O(log n) (binary search).
        Space Complexity: O(1).
        """
        res = nums[0]
        l, r = 0, len(nums) - 1
        while l <= r:
            if nums[l] < nums[r]:
                res = min(res, nums[l])
                break
            m = (l + r) // 2
            res = min(res, nums[m])
            if nums[m] >= nums[l]:
                l = m + 1
            else:
                r = m - 1
        return res

# -------------------
# Test Cases
# -------------------
def test_find_min_rotated_sorted_array():
    s1 = Solution()
    s2 = Solution2()
    # Test case 1: Rotated array
    nums1 = [3,4,5,1,2]
    assert s1.findMin(nums1) == 1
    assert s2.findMin(nums1) == 1
    # Test case 2: Not rotated
    nums2 = [1,2,3,4,5]
    assert s1.findMin(nums2) == 1
    assert s2.findMin(nums2) == 1
    # Test case 3: Single element
    nums3 = [42]
    assert s1.findMin(nums3) == 42
    assert s2.findMin(nums3) == 42
    # Test case 4: Two elements, rotated
    nums4 = [2,1]
    assert s1.findMin(nums4) == 1
    assert s2.findMin(nums4) == 1
    # Test case 5: Large rotation
    nums5 = [5,6,7,8,9,1,2,3,4]
    assert s1.findMin(nums5) == 1
    assert s2.findMin(nums5) == 1
    print("All test cases passed!")

if __name__ == "__main__":
    test_find_min_rotated_sorted_array()


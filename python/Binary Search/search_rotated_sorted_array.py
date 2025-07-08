from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        """
        Approach:
        - Use binary search to find the target in a rotated sorted array.
        - At each step, determine which half (left or right) is sorted.
        - If the target is in the sorted half, search there; otherwise, search the other half.
        - Continue until the target is found or the search space is empty.

        Time Complexity: O(log n)
        Space Complexity: O(1)
        """
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            # Found target
            if target == nums[mid]:
                return mid
            # Left portion is sorted
            if nums[l] <= nums[mid]:
                # Check if target is in left portion
                if nums[l] <= target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            # Right portion is sorted
            else:
                # Check if target is in right portion
                if nums[mid] < target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
        return -1

# -------------------
# Test Cases
# -------------------
def test_search_rotated_sorted_array():
    sol = Solution()
    # Test case 1: Example from Leetcode
    nums1 = [4,5,6,7,0,1,2]
    assert sol.search(nums1, 0) == 4
    assert sol.search(nums1, 3) == -1
    # Test case 2: Not rotated
    nums2 = [1,2,3,4,5]
    assert sol.search(nums2, 3) == 2
    # Test case 3: Single element, found
    nums3 = [42]
    assert sol.search(nums3, 42) == 0
    # Test case 4: Single element, not found
    nums4 = [42]
    assert sol.search(nums4, 7) == -1
    # Test case 5: Empty array
    nums5 = []
    assert sol.search(nums5, 1) == -1
    print("All test cases passed!")

if __name__ == "__main__":
    test_search_rotated_sorted_array()
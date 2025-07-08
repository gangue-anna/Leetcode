from typing import List

class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        """
        Approach:
        - Use a hash set to track seen numbers.
        - If a number is already in the set, return True (duplicate found).
        - Otherwise, add the number to the set.
        - If no duplicates are found, return False.

        Time Complexity: O(n), where n is the length of nums (set operations are O(1) on average).
        Space Complexity: O(n), for the hash set.
        """
        hashset = set()
        for n in nums:
            if n in hashset:
                return True
            hashset.add(n)
        return False

class Solution2:
    def hasDuplicate(self, nums: List[int]) -> bool:
        """
        Approach:
        - Sort the array and check for consecutive duplicates.
        - If any two consecutive numbers are equal, return True.
        - Otherwise, return False.

        Time Complexity: O(n log n), due to sorting.
        Space Complexity: O(1) if sorting in place, O(n) if not.
        """
        nums.sort()
        i = 0
        while i < len(nums) - 1:
            if nums[i] == nums[i + 1]:
                return True
            i += 1
        return False

# -------------------
# Test Cases
# -------------------
def test_contains_duplicate():
    s1 = Solution()
    s2 = Solution2()
    # Test case 1: Contains duplicate
    nums1 = [1, 2, 3, 1]
    assert s1.hasDuplicate(nums1) == True
    assert s2.hasDuplicate(nums1) == True
    # Test case 2: No duplicate
    nums2 = [1, 2, 3, 4]
    assert s1.hasDuplicate(nums2) == False
    assert s2.hasDuplicate(nums2) == False
    # Test case 3: Empty list
    nums3 = []
    assert s1.hasDuplicate(nums3) == False
    assert s2.hasDuplicate(nums3) == False
    # Test case 4: Single element
    nums4 = [42]
    assert s1.hasDuplicate(nums4) == False
    assert s2.hasDuplicate(nums4) == False
    # Test case 5: All duplicates
    nums5 = [7, 7, 7, 7]
    assert s1.hasDuplicate(nums5) == True
    assert s2.hasDuplicate(nums5) == True
    print("All test cases passed!")

if __name__ == "__main__":
    test_contains_duplicate()
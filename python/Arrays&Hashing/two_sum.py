from typing import List 

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        Approach:
        - Use a hash map to store the index of each number as we iterate through the list.
        - For each number, check if (target - number) exists in the map.
        - If it does, return the indices. Otherwise, add the number and its index to the map.
        - Assumes exactly one solution exists (per Leetcode problem statement).

        Time Complexity: O(n), where n is the length of nums.
        Space Complexity: O(n), for the hash map.
        """
        prevMap = {}
        for i, n in enumerate(nums):
            diff = target - n
            if diff in prevMap:
                return [prevMap[diff], i]
            prevMap[n] = i
        # If no solution exists, return an empty list (for robustness)
        return []

# -------------------
# Test Cases
# -------------------
def test_two_sum():
    sol = Solution()
    # Test case 1: Example from Leetcode
    nums1 = [2,7,11,15]
    assert sol.twoSum(nums1, 9) == [0,1]
    # Test case 2: Negative numbers
    nums2 = [3,2,4]
    assert sol.twoSum(nums2, 6) == [1,2]
    # Test case 3: Multiple pairs, returns first found
    nums3 = [3,3]
    assert sol.twoSum(nums3, 6) == [0,1]
    # Test case 4: No solution (should return empty list)
    nums4 = [1,2,3]
    assert sol.twoSum(nums4, 7) == []
    # Test case 5: Single element (no solution)
    nums5 = [42]
    assert sol.twoSum(nums5, 42) == []
    print("All test cases passed!")

if __name__ == "__main__":
    test_two_sum()
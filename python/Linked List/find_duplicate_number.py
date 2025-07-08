from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        """
        Find the duplicate number in an array using Floyd's Tortoise and Hare (cycle detection).
        Approach:
        - Treat the array as a linked list where the value at each index is the next node.
        - Use slow and fast pointers to find the intersection point (cycle).
        - Then, use a second pointer to find the entrance to the cycle (duplicate number).
        Time Complexity: O(n)
        Space Complexity: O(1)
        """
        slow, fast = 0, 0
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        
        slow2 = 0
        while True:
            slow = nums[slow]
            slow2 = nums[slow2]
            if slow == slow2:
                return slow

# -------------------
# Test Cases
# -------------------
def test_find_duplicate():
    s = Solution()
    # Test case 1: Basic
    nums = [1,3,4,2,2]
    assert s.findDuplicate(nums) == 2
    # Test case 2: Duplicate is smallest
    nums = [3,1,3,4,2]
    assert s.findDuplicate(nums) == 3
    # Test case 3: All numbers are the same
    nums = [2,2,2,2,2]
    assert s.findDuplicate(nums) == 2
    # Test case 4: Duplicate at the end
    nums = [1,4,6,3,2,5,6]
    assert s.findDuplicate(nums) == 6
    # Test case 5: Minimum size
    nums = [1,1]
    assert s.findDuplicate(nums) == 1
    print("All test cases passed!")

if __name__ == "__main__":
    test_find_duplicate()
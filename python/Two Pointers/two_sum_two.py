from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        """
        Find two numbers in a sorted array that add up to the target using two pointers.
        Returns 1-based indices.
        Time Complexity: O(n)
        Space Complexity: O(1)
        """
        # Initialize two pointers: left at start, right at end
        l, r = 0, len(numbers) - 1
        
        # Continue until pointers meet
        while l < r:
            # If sum is greater than target, move right pointer left
            # (to get a smaller sum)
            if numbers[l] + numbers[r] > target:
                r = r - 1
            # If sum is less than target, move left pointer right
            # (to get a larger sum)
            elif numbers[l] + numbers[r] < target:
                l = l + 1
            # If sum equals target, return 1-based indices
            else:
                return [l+1, r+1]
        raise ValueError("No solution found")

# -------------------
# Test Cases
# -------------------
def test_two_sum():
    s = Solution()
    # Test case 1: Example
    numbers = [2,7,11,15]
    target = 9
    assert s.twoSum(numbers, target) == [1,2]
    # Test case 2: Negative numbers
    numbers = [-3,0,3,4]
    target = 0
    assert s.twoSum(numbers, target) == [1,3]
    # Test case 3: Duplicates
    numbers = [1,1,2,3]
    target = 2
    assert s.twoSum(numbers, target) == [1,2]
    # Test case 4: Large input
    numbers = [1,2,3,4,4,9,56,90]
    target = 8
    assert s.twoSum(numbers, target) == [4,5]
    # Test case 5: Only two elements
    numbers = [1,2]
    target = 3
    assert s.twoSum(numbers, target) == [1,2]
    print("All test cases passed!")

if __name__ == "__main__":
    test_two_sum()
            
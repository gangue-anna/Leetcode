from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        """
        Approach:
        - Use a hash map to count occurrences of each number.
        - Return the number that appears only once.

        Time Complexity: O(n)
        Space Complexity: O(n)
        """
        numCount = {}
        # Count occurrences of each number
        for num in nums:
            numCount[num] = numCount.get(num, 0) + 1
        
        # Find the number that appears only once
        for num, count in numCount.items():
            if count == 1:
                return num
        
        return 0  # or appropriate default value if no single number found
    
class Solution2:
    def singleNumber(self, nums: List[int]) -> int:
        """
        Approach:
        - Use XOR to find the single number. All pairs cancel out, leaving the unique number.

        Time Complexity: O(n)
        Space Complexity: O(1)
        """
        res = 0
        for n in nums:
            res = n ^ res
        return res

# -------------------
# Test Cases
# -------------------
def test_single_number():
    s1 = Solution()
    s2 = Solution2()
    # Test case 1: Example from Leetcode
    nums1 = [2,2,1]
    assert s1.singleNumber(nums1) == 1
    assert s2.singleNumber(nums1) == 1
    # Test case 2: Single element
    nums2 = [42]
    assert s1.singleNumber(nums2) == 42
    assert s2.singleNumber(nums2) == 42
    # Test case 3: Negative numbers
    nums3 = [-1, -1, -2]
    assert s1.singleNumber(nums3) == -2
    assert s2.singleNumber(nums3) == -2
    # Test case 4: Larger array
    nums4 = [4,1,2,1,2]
    assert s1.singleNumber(nums4) == 4
    assert s2.singleNumber(nums4) == 4
    # Test case 5: All numbers are the same except one
    nums5 = [7,7,7,8,7]
    assert s1.singleNumber(nums5) == 8
    assert s2.singleNumber(nums5) == 8
    print("All test cases passed!")

if __name__ == "__main__":
    test_single_number()
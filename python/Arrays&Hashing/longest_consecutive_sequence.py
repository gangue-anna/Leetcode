from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        """
        Approach:
        - Use a set to allow O(1) lookups for each number.
        - For each number, check if it is the start of a sequence (num - 1 not in set).
        - If so, count the length of the consecutive sequence starting from that number.
        - Track the maximum sequence length found.

        Time Complexity: O(n), where n is the number of elements in nums (each number is processed at most twice).
        Space Complexity: O(n), for the set storing all numbers.
        """
        numSet = set(nums)
        max_size = 0  # Initialize to 0 for empty array case
        
        for num in numSet:
            # Check if this is the start of a sequence
            if num - 1 not in numSet:
                curr_size = 1
                # Count how long the sequence is
                while num + 1 in numSet:
                    curr_size += 1
                    num += 1
                max_size = max(max_size, curr_size)
                
        return max_size

# -------------------
# Test Cases
# -------------------
def test_longest_consecutive_sequence():
    sol = Solution()
    # Test case 1: Example from Leetcode
    nums1 = [100, 4, 200, 1, 3, 2]
    assert sol.longestConsecutive(nums1) == 4  # Sequence: 1,2,3,4
    # Test case 2: No consecutive sequence
    nums2 = [10, 5, 100]
    assert sol.longestConsecutive(nums2) == 1
    # Test case 3: Empty list
    nums3 = []
    assert sol.longestConsecutive(nums3) == 0
    # Test case 4: All elements consecutive
    nums4 = [1, 2, 3, 4, 5]
    assert sol.longestConsecutive(nums4) == 5
    # Test case 5: Duplicates in input
    nums5 = [1, 2, 2, 3]
    assert sol.longestConsecutive(nums5) == 3
    print("All test cases passed!")

if __name__ == "__main__":
    test_longest_consecutive_sequence()
from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        """
        Binary search implementation to find target in sorted array.
        
        Approach:
        1. Initialize left and right pointers to start and end of array
        2. While left <= right (search space is valid):
           - Calculate middle index using integer division
           - If target found at middle, return its index
           - If target < middle value, search left half
           - If target > middle value, search right half
        3. If target not found, return -1
        
        Key Points:
        - Array must be sorted
        - Each iteration reduces search space by half
        - Integer division ensures we don't get stuck in infinite loop
        - Left <= right condition ensures we check the last element
        
        Time Complexity: O(log n) - search space halves each iteration
        Space Complexity: O(1) - only uses pointers
        """
        # Initialize pointers to start and end of array
        l, r = 0, len(nums) - 1
        
        # Continue while search space is valid
        while l <= r:
            # Calculate middle index using integer division
            # This ensures we don't get stuck in infinite loop
            mid = (l + r) // 2
            
            # If target found at middle, return its index
            if target == nums[mid]:
                return mid
            # If target is less than middle value, search left half
            elif target < nums[mid]:
                r = mid - 1
            # If target is greater than middle value, search right half
            else:
                l = mid + 1
                
        # Target not found in array
        return -1

# -------------------
# Test Cases
# -------------------
def test_binary_search():
    sol = Solution()
    # Test case 1: Example from Leetcode
    nums1 = [-1,0,3,5,9,12]
    assert sol.search(nums1, 9) == 4
    # Test case 2: Target not in array
    nums2 = [1,2,3,4,5]
    assert sol.search(nums2, 6) == -1
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
    test_binary_search()

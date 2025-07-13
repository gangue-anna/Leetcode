from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        """
        Find the minimum number of jumps to reach the last index.
        
        Approach:
        - Use a sliding window approach with left (l) and right (r) pointers.
        - For each window, find the farthest position that can be reached from any position in the current window.
        - Move the left pointer to the next position after the current right pointer.
        - Move the right pointer to the farthest position found.
        - Increment the jump count for each window.
        - Continue until the right pointer reaches or exceeds the last index.
        
        Time Complexity: O(N), where N is the length of nums
        - Each position is visited at most once
        
        Space Complexity: O(1)
        - Only a constant amount of extra space is used
        
        Args:
            nums: List[int] - List of non-negative integers representing maximum jump length
        Returns:
            int - Minimum number of jumps to reach the last index
        """
        res = 0
        l = r = 0

        while r < len(nums) - 1:
            farthest = 0
            # Find the farthest position that can be reached from the current window
            for i in range(l, r + 1):
                farthest = max(farthest, i + nums[i])
            l = r + 1  # Move left pointer to the next position
            r = farthest  # Move right pointer to the farthest position
            res += 1  # Increment jump count
        return res

# -------------------
# Test Cases
# -------------------
def test_jump():
    s = Solution()
    # Test case 1: Minimum jumps
    assert s.jump([2,3,1,1,4]) == 2, "Failed on [2,3,1,1,4]"
    # Test case 2: Single jump
    assert s.jump([2,3,0,1,4]) == 2, "Failed on [2,3,0,1,4]"
    # Test case 3: Single element
    assert s.jump([0]) == 0, "Failed on [0]"
    # Test case 4: Two elements
    assert s.jump([1,2]) == 1, "Failed on [1,2]"
    # Test case 5: Large jumps
    assert s.jump([5,0,0,0]) == 1, "Failed on [5,0,0,0]"
    # Test case 6: Multiple jumps needed
    assert s.jump([1,1,1,1,1]) == 4, "Failed on [1,1,1,1,1]"
    # Test case 7: Optimal path
    assert s.jump([2,0,0]) == 1, "Failed on [2,0,0]"
    # Test case 8: Complex path
    assert s.jump([1,2,3,4,5]) == 3, "Failed on [1,2,3,4,5]"
    print("All test cases passed!")

if __name__ == "__main__":
    test_jump()
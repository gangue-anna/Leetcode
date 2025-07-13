from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        """
        Determine if you can reach the last index starting from index 0.
        
        Approach:
        - Start from the last index and work backwards.
        - For each position, check if you can reach the current goal from that position.
        - If you can reach the goal from position i, update the goal to i.
        - If the goal becomes 0, you can reach the last index.
        
        Time Complexity: O(N), where N is the length of nums
        - We iterate through the array once from the end
        
        Space Complexity: O(1)
        - Only a constant amount of extra space is used
        
        Args:
            nums: List[int] - List of non-negative integers representing maximum jump length
        Returns:
            bool - True if you can reach the last index, False otherwise
        """
        goal = len(nums) - 1

        for i in range(len(nums) - 1, -1, -1):
            # If you can reach the current goal from position i, update the goal to i
            if i + nums[i] >= goal:
                goal = i
        
        # If the goal is 0, you can reach the last index
        return True if goal == 0 else False

# -------------------
# Test Cases
# -------------------
def test_can_jump():
    s = Solution()
    # Test case 1: Can reach the end
    assert s.canJump([2,3,1,1,4]) == True, "Failed on [2,3,1,1,4]"
    # Test case 2: Cannot reach the end
    assert s.canJump([3,2,1,0,4]) == False, "Failed on [3,2,1,0,4]"
    # Test case 3: Single element
    assert s.canJump([0]) == True, "Failed on [0]"
    # Test case 4: All zeros except last
    assert s.canJump([0,0,0,1]) == False, "Failed on [0,0,0,1]"
    # Test case 5: Can jump directly to end
    assert s.canJump([5,0,0,0]) == True, "Failed on [5,0,0,0]"
    # Test case 6: Large jumps
    assert s.canJump([2,0,0]) == True, "Failed on [2,0,0]"
    # Test case 7: Cannot jump from first position
    assert s.canJump([0,1,2]) == False, "Failed on [0,1,2]"
    # Test case 8: Multiple paths
    assert s.canJump([1,2,3,4,5]) == True, "Failed on [1,2,3,4,5]"
    print("All test cases passed!")

if __name__ == "__main__":
    test_can_jump()

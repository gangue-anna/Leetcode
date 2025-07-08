from typing import List

class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        """
        Finds all unique combinations in nums where the numbers sum to target.
        Each number in nums may be used an unlimited number of times.
        
        Approach:
        - Use backtracking (DFS) to explore all possible combinations.
        - At each step, decide to include the current number (and stay at the same index, since repeats are allowed),
          or skip to the next index.
        - If the running total equals the target, add a copy of the current combination to the result.
        - If the running total exceeds the target or the index is out of bounds, backtrack.
        
        Time Complexity:
            - O(2^(t/m)), where t is the target and m is the minimal value in nums.
              (The number of combinations can be exponential in the worst case.)
        Space Complexity:
            - O(target/min(nums)) for the recursion stack (depth of the tree).
            - O(number of valid combinations * average length of combination) for the result storage.
        """
        res = []

        def dfs(i, curr, total):
            if total == target:
                res.append(curr.copy())  # Found a valid combination
                return
            if i >= len(nums) or total > target:
                return 
            # Include nums[i] (can reuse same element)
            curr.append(nums[i])
            dfs(i, curr, total + nums[i])
            curr.pop()  # Backtrack
            # Exclude nums[i] and move to next
            dfs(i + 1, curr, total)

        dfs(0, [], 0)
        return res

# -------------------
# Test Cases
# -------------------
def test_combination_sum():
    sol = Solution()
    # Test case 1: Example from Leetcode
    nums1 = [2,3,6,7]
    target1 = 7
    result1 = sol.combinationSum(nums1, target1)
    assert sorted([tuple(sorted(x)) for x in result1]) == sorted([tuple(sorted(x)) for x in [[2,2,3],[7]]])
    # Test case 2: No solution
    nums2 = [2,4]
    target2 = 7
    assert sol.combinationSum(nums2, target2) == []
    # Test case 3: Single element, can be used multiple times
    nums3 = [3]
    target3 = 9
    assert sol.combinationSum(nums3, target3) == [[3,3,3]]
    # Test case 4: Empty nums
    nums4 = []
    target4 = 7
    assert sol.combinationSum(nums4, target4) == []
    # Test case 5: Target is zero
    nums5 = [1,2,3]
    target5 = 0
    assert sol.combinationSum(nums5, target5) == [[]]
    print("All test cases passed!")

if __name__ == "__main__":
    test_combination_sum()
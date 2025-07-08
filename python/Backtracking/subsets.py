from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        """
        Approach:
        - Use backtracking (DFS) to generate all possible subsets.
        - At each index, decide to include or exclude the current element.
        - When the end of the list is reached, add the current subset to the result.

        Time Complexity: O(2^n), where n is the length of nums (number of subsets).
        Space Complexity: O(2^n * n), for the result list (all subsets) and recursion stack.
        """
        res = []
        subset = []
        def dfs(i):
            if i >= len(nums):
                res.append(subset.copy())
                return 
            subset.append(nums[i])
            dfs(i + 1)
            subset.pop()
            dfs(i + 1)
        dfs(0)
        return res

# -------------------
# Test Cases
# -------------------
def test_subsets():
    sol = Solution()
    # Test case 1: Example from Leetcode
    nums1 = [1,2,3]
    result1 = sol.subsets(nums1)
    expected1 = [
        [],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]
    ]
    assert sorted([tuple(sorted(x)) for x in result1]) == sorted([tuple(sorted(x)) for x in expected1])
    # Test case 2: Single element
    nums2 = [42]
    assert sol.subsets(nums2) == [[],[42]]
    # Test case 3: Empty list
    nums3 = []
    assert sol.subsets(nums3) == [[]]
    print("All test cases passed!")

if __name__ == "__main__":
    test_subsets()
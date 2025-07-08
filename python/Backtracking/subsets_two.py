from typing import List

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        """
        Approach:
        - Sort the input to group duplicates together.
        - Use backtracking to generate all possible subsets.
        - At each index, decide to include or exclude the current element.
        - When excluding, skip all consecutive duplicates to avoid duplicate subsets.
        - When the end of the list is reached, add the current subset to the result.

        Time Complexity: O(2^n), where n is the length of nums (number of subsets).
        Space Complexity: O(2^n * n), for the result list (all subsets) and recursion stack.
        """
        res = []
        nums.sort()

        def backtrack(i, subset):
            if i == len(nums):
                res.append(subset[::])
                return
            
            #All subsets that include nums[i]
            subset.append(nums[i])
            backtrack(i + 1, subset)
            subset.pop()

            #All subsets that do not include nums[i]
            while i + 1 < len(nums) and nums[i] == nums[i + 1]:
                i += 1
            backtrack(i + 1, subset)
        backtrack(0, [])
        return res

# -------------------
# Test Cases
# -------------------
def test_subsets_with_dup():
    sol = Solution()
    # Test case 1: Example from Leetcode
    nums1 = [1,2,2]
    result1 = sol.subsetsWithDup(nums1)
    expected1 = [[],[1],[1,2],[1,2,2],[2],[2,2]]
    assert sorted([tuple(sorted(x)) for x in result1]) == sorted([tuple(sorted(x)) for x in expected1])
    # Test case 2: All unique
    nums2 = [1,2,3]
    result2 = sol.subsetsWithDup(nums2)
    expected2 = [[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]]
    assert sorted([tuple(sorted(x)) for x in result2]) == sorted([tuple(sorted(x)) for x in expected2])
    # Test case 3: All duplicates
    nums3 = [2,2,2]
    result3 = sol.subsetsWithDup(nums3)
    expected3 = [[],[2],[2,2],[2,2,2]]
    assert sorted([tuple(sorted(x)) for x in result3]) == sorted([tuple(sorted(x)) for x in expected3])
    # Test case 4: Empty list
    nums4 = []
    assert sol.subsetsWithDup(nums4) == [[]]
    print("All test cases passed!")

if __name__ == "__main__":
    test_subsets_with_dup()
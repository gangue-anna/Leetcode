from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        """
        Approach:
        - Use recursion to generate all permutations of the input list.
        - For each element, remove it from the list, generate all permutations of the remaining list, and append the removed element to each permutation.
        - Base case: if the list has one element, return it as the only permutation.
        - Restore the list after each recursive call to maintain state.

        Time Complexity: O(n!), where n is the length of nums (number of permutations).
        Space Complexity: O(n!), for the result list and recursion stack.
        """
        res = []
        if len(nums) == 1:
            return [nums[:]]
        for i in range(len(nums)):
            n = nums.pop(0)
            perms = self.permute(nums)
            for perm in perms:
                perm.append(n)
            res.extend(perms)
            nums.append(n)
        return res

# -------------------
# Test Cases
# -------------------
def test_permutations():
    sol = Solution()
    # Test case 1: Example from Leetcode
    nums1 = [1,2,3]
    result1 = sol.permute(nums1)
    expected1 = [
        [1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]
    ]
    assert sorted([tuple(x) for x in result1]) == sorted([tuple(x) for x in expected1])
    # Test case 2: Single element
    nums2 = [42]
    assert sol.permute(nums2) == [[42]]
    # Test case 3: Two elements
    nums3 = [0,1]
    result3 = sol.permute(nums3)
    expected3 = [[0,1],[1,0]]
    assert sorted([tuple(x) for x in result3]) == sorted([tuple(x) for x in expected3])
    print("All test cases passed!")

if __name__ == "__main__":
    test_permutations()
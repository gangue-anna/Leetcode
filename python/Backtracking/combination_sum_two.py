from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        """
        Approach:
        - Sort the candidates to handle duplicates easily.
        - Use backtracking to explore all unique combinations that sum to the target.
        - At each step, skip duplicate numbers to avoid duplicate combinations.
        - Each number can only be used once per combination (move to i+1 in recursion).
        - If the running total equals the target, add the current combination to the result.
        - If the running total exceeds the target, backtrack.

        Time Complexity: O(2^n), where n is the number of candidates (worst case: all subsets).
        Space Complexity: O(n), for the recursion stack and current combination.
        """
        candidates.sort()
        res = []
        def backtrack(curr, pos, target):
            if target == 0:
                res.append(curr.copy())
                return
            if target < 0:
                return
            prev = -1
            for i in range(pos, len(candidates)):
                if candidates[i] == prev:
                    continue
                curr.append(candidates[i]) 
                backtrack(curr, i + 1, target - candidates[i])
                curr.pop()
                prev = candidates[i]
        backtrack([], 0, target)
        return res

# -------------------
# Test Cases
# -------------------
def test_combination_sum2():
    sol = Solution()
    # Test case 1: Example from Leetcode
    candidates1 = [10,1,2,7,6,1,5]
    target1 = 8
    result1 = sol.combinationSum2(candidates1, target1)
    expected1 = [[1,1,6],[1,2,5],[1,7],[2,6]]
    assert sorted([sorted(x) for x in result1]) == sorted([sorted(x) for x in expected1])
    # Test case 2: No solution
    candidates2 = [2,4,6]
    target2 = 5
    assert sol.combinationSum2(candidates2, target2) == []
    # Test case 3: Single element, can be used once
    candidates3 = [3]
    target3 = 3
    assert sol.combinationSum2(candidates3, target3) == [[3]]
    # Test case 4: Empty candidates
    candidates4 = []
    target4 = 7
    assert sol.combinationSum2(candidates4, target4) == []
    # Test case 5: Target is zero
    candidates5 = [1,2,3]
    target5 = 0
    assert sol.combinationSum2(candidates5, target5) == [[]]
    print("All test cases passed!")

if __name__ == "__main__":
    test_combination_sum2()
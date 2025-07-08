from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        """
        Generate all combinations of n pairs of valid parentheses using backtracking.
        Approach:
        - Use a stack to build the current string.
        - At each step, add '(' if we have not used all opens, add ')' if it would not exceed opens.
        - Add to result when both open and close counts reach n.
        Time Complexity: O(2^n * n) (Catalan number growth)
        Space Complexity: O(n) for the stack, O(2^n * n) for the result
        """
        stack = []
        res = []

        def backtrack(openN, closedN):
            if openN == closedN == n:
                res.append("".join(stack))
                return

            if openN < n:
                stack.append("(")
                backtrack(openN + 1, closedN)
                stack.pop()

            if closedN < openN:
                stack.append(")")
                backtrack(openN, closedN + 1)
                stack.pop()

        backtrack(0, 0)
        return res

# -------------------
# Test Cases
# -------------------
def test_generate_parenthesis():
    s = Solution()
    # Test case 1: n = 1
    assert sorted(s.generateParenthesis(1)) == ["()"]
    # Test case 2: n = 2
    assert sorted(s.generateParenthesis(2)) == ["(())", "()()"]
    # Test case 3: n = 3
    assert sorted(s.generateParenthesis(3)) == ["((()))","(()())","(())()","()(())","()()()"]
    # Test case 4: n = 0 (edge case)
    assert sorted(s.generateParenthesis(0)) == [""]
    print("All test cases passed!")

if __name__ == "__main__":
    test_generate_parenthesis()


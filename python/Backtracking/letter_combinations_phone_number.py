from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        """
        Approach:
        - Use backtracking to generate all possible letter combinations for the given digit string.
        - For each digit, try every possible letter and recursively build the string.
        - When the current string length equals the input length, add it to the result.
        - Handles empty input by returning an empty list.

        Time Complexity: O(4^n), where n is the length of digits (each digit can map to up to 4 letters).
        Space Complexity: O(4^n), for the result list and recursion stack.
        """
        res = []
        digitToChar = {"2" : "abc",
                       "3" : "def",
                       "4" : "ghi",
                       "5" : "jkl",
                       "6" : "mno",
                       "7" : "pqrs",
                       "8" : "tuv",
                       "9" : "wxyz"}
        
        def backtrack(i, curStr):
            if len(curStr) == len(digits):
                res.append(curStr)
                return
            
            for c in digitToChar[digits[i]]:
                backtrack(i + 1, curStr + c)
            
        if digits:
            backtrack(0, "")
        return res

# -------------------
# Test Cases
# -------------------
def test_letter_combinations():
    sol = Solution()
    # Test case 1: Example from Leetcode
    digits1 = "23"
    result1 = sol.letterCombinations(digits1)
    expected1 = ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    assert sorted(result1) == sorted(expected1)
    # Test case 2: Empty input
    digits2 = ""
    assert sol.letterCombinations(digits2) == []
    # Test case 3: Single digit
    digits3 = "2"
    assert sorted(sol.letterCombinations(digits3)) == sorted(["a","b","c"])
    # Test case 4: Digits with 4 letters
    digits4 = "79"
    result4 = sol.letterCombinations(digits4)
    assert len(result4) == 16  # 4*4
    # Test case 5: All digits
    digits5 = "234"
    result5 = sol.letterCombinations(digits5)
    assert len(result5) == 27  # 3*3*3
    print("All test cases passed!")

if __name__ == "__main__":
    test_letter_combinations()
from typing import List

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        """
        Approach:
        - Use backtracking (DFS) to explore all possible partitions of the string.
        - At each step, try every possible substring starting at the current index.
        - If the substring is a palindrome, add it to the current partition and recurse.
        - If the end of the string is reached, add the current partition to the result.
        - Use a helper function to check if a substring is a palindrome.

        Time Complexity: O(2^n * n), where n is the length of s (there are 2^n possible partitions, and each palindrome check is O(n)).
        Space Complexity: O(n) for the recursion stack, plus O(2^n * n) for the result storage.
        """
        res = []
        part = []

        def dfs(i):
            if i >= len(s):
                res.append(part.copy())
                return
            for j in range(i, len(s)):
                if self.isPali(s, i, j):
                    part.append(s[i : j + 1])
                    dfs(j + 1)
                    part.pop()
        dfs(0)
        return res
    
    def isPali(self, s, l, r):
        while l < r:
            if s[l] != s[r]:
                return False
            l, r = l + 1, r - 1
        return True
    
# -------------------
# Test Cases
# -------------------
def test_palindrome_partitioning():
    sol = Solution()
    # Test case 1: Example from Leetcode
    s1 = "aab"
    result1 = sol.partition(s1)
    expected1 = [["a","a","b"],["aa","b"]]
    assert sorted([sorted(x) for x in result1]) == sorted([sorted(x) for x in expected1])
    # Test case 2: Single character
    s2 = "a"
    assert sol.partition(s2) == [["a"]]
    # Test case 3: All palindromes
    s3 = "aaa"
    result3 = sol.partition(s3)
    expected3 = [["a","a","a"],["a","aa"],["aa","a"],["aaa"]]
    assert sorted([sorted(x) for x in result3]) == sorted([sorted(x) for x in expected3])
    # Test case 4: No palindromic partition except single letters
    s4 = "abc"
    assert sol.partition(s4) == [["a","b","c"]]
    # Test case 5: Empty string
    s5 = ""
    assert sol.partition(s5) == [[]]
    print("All test cases passed!")

if __name__ == "__main__":
    test_palindrome_partitioning()
    
class Solution:
    """
    Distinct Subsequences - Count number of ways to form t from s
    
    Problem: Given two strings s and t, return the number of distinct subsequences 
    of s which equals t. A subsequence of a string is a new string generated from 
    the original string with some characters (can be none) deleted without changing 
    the relative order of the remaining characters.
    
    Example: s = "rabbbit", t = "rabbit"
    Output: 3
    Explanation: There are 3 ways to form "rabbit" from "rabbbit":
    1. "rabbbit" -> "rabbit" (delete 'b' at index 3)
    2. "rabbbit" -> "rabbit" (delete 'b' at index 4) 
    3. "rabbbit" -> "rabbit" (delete 'b' at index 5)
    
    Approach: Dynamic Programming with Memoization
    - Use DFS with memoization to explore all possible subsequence combinations
    - At each step, we can either use the current character from s or skip it
    - If characters match, we can either use the match or skip it
    - If characters don't match, we must skip the current character from s
    - The state is represented by (i, j) where i is position in s, j is position in t
    
    Time Complexity: O(len(s) * len(t))
    Space Complexity: O(len(s) * len(t)) for memoization cache
    """
    
    def numDistinct(self, s: str, t: str) -> int:
        # Memoization cache: (i, j) -> number of ways to form t[j:] from s[i:]
        cache = {}

        def dfs(i, j):
            """
            DFS helper function to find number of ways to form t[j:] from s[i:]
            
            Args:
                i: Current position in string s
                j: Current position in string t
            
            Returns:
                Number of ways to form t[j:] from s[i:]
            """
            # Base case: we've matched all characters in t
            if j == len(t):
                return 1
                
            # Base case: we've exhausted s but haven't matched all of t
            if i == len(s):
                return 0
                
            # Return cached result if already computed
            if (i, j) in cache:
                return cache[(i, j)]
                
            # If characters match, we have two options:
            # 1. Use the match: continue with both i+1 and j+1
            # 2. Skip the match: continue with i+1 but keep j
            if s[i] == t[j]:
                cache[(i, j)] = dfs(i + 1, j + 1) + dfs(i + 1, j)
            else:
                # If characters don't match, we must skip current character from s
                cache[(i, j)] = dfs(i + 1, j)
                
            return cache[(i, j)]
            
        return dfs(0, 0)


class Solution2:
    """
    Distinct Subsequences - Count number of ways to form t from s
    
    Problem: Given two strings s and t, return the number of distinct subsequences 
    of s which equals t.
    
    Approach: Bottom-up Dynamic Programming
    - Use 2D DP table where dp[i][j] = ways to form t[0:j] from s[0:i]
    - Fill the table bottom-up, building solutions from smaller substrings
    - For each position, consider both using and not using the current character
    
    Time Complexity: O(len(s) * len(t))
    Space Complexity: O(len(s) * len(t)) for DP table
    """
    
    def numDistinct(self, s: str, t: str) -> int:
        # DP table: dp[i][j] = ways to form t[0:j] from s[0:i]
        dp = [[0] * (len(t) + 1) for _ in range(len(s) + 1)]
        
        # Base case: empty string can form empty string in 1 way
        for i in range(len(s) + 1):
            dp[i][0] = 1
            
        # Fill the DP table
        for i in range(1, len(s) + 1):
            for j in range(1, len(t) + 1):
                # Start with the result from not using current character from s
                dp[i][j] = dp[i-1][j]
                
                # If characters match, add ways from using the match
                if s[i-1] == t[j-1]:
                    dp[i][j] += dp[i-1][j-1]
                    
        return dp[len(s)][len(t)]


# Test cases
def test_distinct_subsequences():
    """Test cases for Distinct Subsequences problem"""
    
    # Test case 1: Basic case
    print("Test 1: s='rabbbit', t='rabbit'")
    sol1 = Solution()
    sol2 = Solution2()
    result1 = sol1.numDistinct("rabbbit", "rabbit")
    result2 = sol2.numDistinct("rabbbit", "rabbit")
    expected = 3  # 3 ways to form "rabbit" from "rabbbit"
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 1 passed\n")
    
    # Test case 2: Single character
    print("Test 2: s='abc', t='a'")
    result1 = sol1.numDistinct("abc", "a")
    result2 = sol2.numDistinct("abc", "a")
    expected = 1  # One way: use the first 'a'
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 2 passed\n")
    
    # Test case 3: Multiple matches
    print("Test 3: s='aaa', t='a'")
    result1 = sol1.numDistinct("aaa", "a")
    result2 = sol2.numDistinct("aaa", "a")
    expected = 3  # Three ways: use any of the three 'a's
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 3 passed\n")
    
    # Test case 4: No match
    print("Test 4: s='abc', t='d'")
    result1 = sol1.numDistinct("abc", "d")
    result2 = sol2.numDistinct("abc", "d")
    expected = 0  # No way to form 'd' from 'abc'
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 4 passed\n")
    
    # Test case 5: Empty target
    print("Test 5: s='abc', t=''")
    result1 = sol1.numDistinct("abc", "")
    result2 = sol2.numDistinct("abc", "")
    expected = 1  # One way: delete all characters
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 5 passed\n")
    
    # Test case 6: Empty source
    print("Test 6: s='', t='abc'")
    result1 = sol1.numDistinct("", "abc")
    result2 = sol2.numDistinct("", "abc")
    expected = 0  # No way to form 'abc' from empty string
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 6 passed\n")
    
    # Test case 7: Both empty
    print("Test 7: s='', t=''")
    result1 = sol1.numDistinct("", "")
    result2 = sol2.numDistinct("", "")
    expected = 1  # One way: empty from empty
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 7 passed\n")
    
    # Test case 8: Complex case
    print("Test 8: s='babgbag', t='bag'")
    result1 = sol1.numDistinct("babgbag", "bag")
    result2 = sol2.numDistinct("babgbag", "bag")
    expected = 5  # 5 ways to form "bag" from "babgbag"
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 8 passed\n")
    
    # Test case 9: Same string
    print("Test 9: s='abc', t='abc'")
    result1 = sol1.numDistinct("abc", "abc")
    result2 = sol2.numDistinct("abc", "abc")
    expected = 1  # One way: use all characters in order
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 9 passed\n")
    
    # Test case 10: Repeated characters
    print("Test 10: s='aaaa', t='aa'")
    result1 = sol1.numDistinct("aaaa", "aa")
    result2 = sol2.numDistinct("aaaa", "aa")
    expected = 6  # 6 ways: choose any 2 positions from 4
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 10 passed\n")
    
    # Test case 11: Long strings
    print("Test 11: s='aaaaaaaaaa', t='aaa'")
    result1 = sol1.numDistinct("aaaaaaaaaa", "aaa")
    result2 = sol2.numDistinct("aaaaaaaaaa", "aaa")
    expected = 120  # C(10,3) = 120 ways to choose 3 positions from 10
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 11 passed\n")
    
    # Test case 12: No subsequence possible
    print("Test 12: s='abc', t='cab'")
    result1 = sol1.numDistinct("abc", "cab")
    result2 = sol2.numDistinct("abc", "cab")
    expected = 0  # Cannot form "cab" from "abc" (wrong order)
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 12 passed\n")
    
    print("All tests passed!")


if __name__ == "__main__":
    test_distinct_subsequences()
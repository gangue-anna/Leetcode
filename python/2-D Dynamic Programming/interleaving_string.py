class Solution:
    """
    Interleaving String - Check if s3 is formed by interleaving s1 and s2
    
    Problem: Given three strings s1, s2, and s3, determine if s3 is formed by 
    interleaving s1 and s2. An interleaving of two strings s and t is a 
    configuration where they are divided into non-empty substrings such that:
    s = s1 + s2 + ... + sn
    t = t1 + t2 + ... + tm
    |n - m| <= 1
    The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
    
    Example: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
    Output: True (aadbbcbcac = aabcc + dbbca interleaved)
    
    Approach: Dynamic Programming with Memoization
    - Use DFS with memoization to explore all possible interleaving combinations
    - At each step, we can either take the next character from s1 or s2
    - Keep track of current positions in s1 (i) and s2 (j)
    - The current position in s3 is always i + j
    - Memoize results to avoid recalculating the same subproblems
    - Early length check for efficiency
    
    Time Complexity: O(len(s1) * len(s2))
    Space Complexity: O(len(s1) * len(s2)) for memoization cache
    """
    
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        # Early check: lengths must add up
        if len(s1) + len(s2) != len(s3):
            return False
            
        # Memoization cache: (i, j) -> can interleave from position i in s1 and j in s2
        dp = {}
        
        def dfs(i, j):
            """
            DFS helper function to check if s3 can be formed by interleaving
            s1[i:] and s2[j:]
            
            Args:
                i: Current position in s1
                j: Current position in s2
            
            Returns:
                True if s3[i+j:] can be formed by interleaving s1[i:] and s2[j:]
            """
            # Base case: both strings are exhausted, check if s3 is also exhausted
            if i == len(s1) and j == len(s2):
                return True
                
            # Return cached result if already computed
            if (i, j) in dp:
                return dp[(i, j)]
            
            # Try taking next character from s1 if available and matches s3
            if i < len(s1) and s1[i] == s3[i+j] and dfs(i+1, j):
                return True
                
            # Try taking next character from s2 if available and matches s3
            if j < len(s2) and s2[j] == s3[i+j] and dfs(i, j+1):
                return True
                
            # If neither option works, mark as impossible
            dp[(i,j)] = False
            return False
        
        return dfs(0,0)


class Solution2:
    """
    Interleaving String - Check if s3 is formed by interleaving s1 and s2
    
    Problem: Given three strings s1, s2, and s3, determine if s3 is formed by 
    interleaving s1 and s2.
    
    Approach: Bottom-up Dynamic Programming (Reverse Fill)
    - Use 2D DP table where dp[i][j] = can form s3[i+j:] using s1[i:] and s2[j:]
    - Fill the table in reverse order, starting from the end
    - For each position, check if we can take from s1 or s2 if characters match
    - This approach avoids the need to handle base cases separately
    
    Time Complexity: O(len(s1) * len(s2))
    Space Complexity: O(len(s1) * len(s2)) for DP table
    """
    
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        # Early check: lengths must add up
        if len(s1) + len(s2) != len(s3):
            return False
            
        # DP table: dp[i][j] = can form s3[i+j:] using s1[i:] and s2[j:]
        dp = [[False] * (len(s2) + 1) for i in range((len(s1) + 1))]
        
        # Base case: empty strings can form empty string
        dp[len(s1)][len(s2)] = True

        # Fill table in reverse order
        for i in range(len(s1), -1, -1):
            for j in range(len(s2), -1, -1):
                # Try taking next character from s1 if available and matches s3
                if i < len(s1) and s1[i] == s3[i + j] and dp[i + 1][j]:
                    dp[i][j] = True
                    
                # Try taking next character from s2 if available and matches s3
                if j < len(s2) and s2[j] == s3[i + j] and dp[i][j + 1]:
                    dp[i][j] = True
                    
        return dp[0][0]


# Test cases
def test_interleaving_string():
    """Test cases for Interleaving String problem"""
    
    # Test case 1: Basic case
    print("Test 1: s1='aabcc', s2='dbbca', s3='aadbbcbcac'")
    sol1 = Solution()
    sol2 = Solution2()
    result1 = sol1.isInterleave("aabcc", "dbbca", "aadbbcbcac")
    result2 = sol2.isInterleave("aabcc", "dbbca", "aadbbcbcac")
    expected = True  # Can be interleaved
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 1 passed\n")
    
    # Test case 2: Impossible interleaving
    print("Test 2: s1='aabcc', s2='dbbca', s3='aadbbbaccc'")
    result1 = sol1.isInterleave("aabcc", "dbbca", "aadbbbaccc")
    result2 = sol2.isInterleave("aabcc", "dbbca", "aadbbbaccc")
    expected = False  # Cannot be interleaved
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 2 passed\n")
    
    # Test case 3: Empty strings
    print("Test 3: s1='', s2='', s3=''")
    result1 = sol1.isInterleave("", "", "")
    result2 = sol2.isInterleave("", "", "")
    expected = True  # Empty strings can form empty string
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 3 passed\n")
    
    # Test case 4: One empty string
    print("Test 4: s1='abc', s2='', s3='abc'")
    result1 = sol1.isInterleave("abc", "", "abc")
    result2 = sol2.isInterleave("abc", "", "abc")
    expected = True  # Can form using only s1
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 4 passed\n")
    
    # Test case 5: Length mismatch
    print("Test 5: s1='abc', s2='def', s3='abcdefg'")
    result1 = sol1.isInterleave("abc", "def", "abcdefg")
    result2 = sol2.isInterleave("abc", "def", "abcdefg")
    expected = False  # Lengths don't add up
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 5 passed\n")
    
    # Test case 6: Simple case
    print("Test 6: s1='a', s2='b', s3='ab'")
    result1 = sol1.isInterleave("a", "b", "ab")
    result2 = sol2.isInterleave("a", "b", "ab")
    expected = True  # Can interleave as 'ab'
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 6 passed\n")
    
    # Test case 7: Same characters
    print("Test 7: s1='aaa', s2='aaa', s3='aaaaaa'")
    result1 = sol1.isInterleave("aaa", "aaa", "aaaaaa")
    result2 = sol2.isInterleave("aaa", "aaa", "aaaaaa")
    expected = True  # Can interleave as 'aaaaaa'
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 7 passed\n")
    
    # Test case 8: Different characters
    print("Test 8: s1='abc', s2='def', s3='abcdef'")
    result1 = sol1.isInterleave("abc", "def", "abcdef")
    result2 = sol2.isInterleave("abc", "def", "abcdef")
    expected = True  # Can interleave as 'abcdef'
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 8 passed\n")
    
    # Test case 9: Complex interleaving
    print("Test 9: s1='aabcc', s2='dbbca', s3='aadbbcbcac'")
    result1 = sol1.isInterleave("aabcc", "dbbca", "aadbbcbcac")
    result2 = sol2.isInterleave("aabcc", "dbbca", "aadbbcbcac")
    expected = True  # Complex but valid interleaving
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 9 passed\n")
    
    # Test case 10: Single characters
    print("Test 10: s1='a', s2='b', s3='ba'")
    result1 = sol1.isInterleave("a", "b", "ba")
    result2 = sol2.isInterleave("a", "b", "ba")
    expected = True  # Can interleave as 'ba'
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 10 passed\n")
    
    # Test case 11: Same characters
    print("Test 11: s1='aa', s2='aa', s3='aaaa'")
    result1 = sol1.isInterleave("aa", "aa", "aaaa")
    result2 = sol2.isInterleave("aa", "aa", "aaaa")
    expected = True  # Can interleave as 'aaaa'
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 11 passed\n")
    
    # Test case 12: Character mismatch
    print("Test 12: s1='abc', s2='def', s3='abxdef'")
    result1 = sol1.isInterleave("abc", "def", "abxdef")
    result2 = sol2.isInterleave("abc", "def", "abxdef")
    expected = False  # 'x' doesn't match any character
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 12 passed\n")
    
    # Test case 13: Multiple valid interleavings
    print("Test 13: s1='ab', s2='cd', s3='abcd'")
    result1 = sol1.isInterleave("ab", "cd", "abcd")
    result2 = sol2.isInterleave("ab", "cd", "abcd")
    expected = True  # Can interleave as 'abcd'
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 13 passed\n")
    
    # Test case 14: All same character
    print("Test 14: s1='aaa', s2='aaa', s3='aaaaaa'")
    result1 = sol1.isInterleave("aaa", "aaa", "aaaaaa")
    result2 = sol2.isInterleave("aaa", "aaa", "aaaaaa")
    expected = True  # Can interleave as 'aaaaaa'
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 14 passed\n")
    
    print("All tests passed!")


if __name__ == "__main__":
    test_interleaving_string()
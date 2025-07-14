class Solution:
    """
    Regular Expression Matching
    
    Problem: Given an input string s and a pattern p, implement regular expression 
    matching with support for '.' and '*'.
    - '.' Matches any single character
    - '*' Matches zero or more of the preceding element
    
    Example: s = "aa", p = "a*"
    Output: True (a* matches "aa")
    
    Approach: Dynamic Programming with Memoization
    - Use DFS with memoization to explore all possible matching combinations
    - Handle three cases: exact match, dot match, and star match
    - For star matches, try both zero and one-or-more occurrences
    - Memoize results to avoid recomputation
    - State: (i, j) = can match s[i:] with p[j:]
    
    Time Complexity: O(m * n) where m = len(s), n = len(p)
    Space Complexity: O(m * n) for memoization cache
    """
    
    def isMatch(self, s: str, p: str) -> bool:
        # Memoization cache: (i, j) -> can match s[i:] with p[j:]
        cache = {}

        def dfs(i, j):
            # Check memoization cache first to avoid recomputation
            if (i, j) in cache:
                return cache[(i, j)]
            
            """
            DFS helper to check if s[i:] matches p[j:]
            Args:
                i: current position in string s
                j: current position in pattern p
            Returns:
                True if s[i:] matches p[j:], False otherwise
            """
            # Base case: both strings exhausted
            if i >= len(s) and j >= len(p):
                return True
            # Base case: pattern exhausted but string not
            if j >= len(p):
                return False
            
            # Check if current characters match (exact or dot)
            match = i < len(s) and (s[i] == p[j] or p[j] == ".")
            
            # Handle star pattern (zero or more occurrences)
            if (j + 1) < len(p) and p[j + 1] == "*":
                # Try zero occurrences (skip current pattern) or one-or-more occurrences
                # Cache the result to avoid recomputing this subproblem
                cache[(i, j)] = dfs(i, j + 2) or (match and dfs(i + 1, j))
                return cache[(i, j)]
            
            # Handle exact/dot match (move both pointers)
            if match:
                # Cache the result for exact/dot match
                cache[(i, j)] = dfs(i + 1, j + 1)
                return cache[(i, j)]
            
            # No match possible - cache the result
            cache[(i, j)] = False
            return False
        
        return dfs(0, 0)

# Test cases
def test_regular_expression_matching():
    """Test cases for Regular Expression Matching problem"""
    
    # Test case 1: Basic exact match
    print("Test 1: s='aa', p='a'")
    sol = Solution()
    result = sol.isMatch("aa", "a")
    expected = False  # 'a' doesn't match 'aa'
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 1 passed\n")
    
    # Test case 2: Star pattern
    print("Test 2: s='aa', p='a*'")
    result = sol.isMatch("aa", "a*")
    expected = True  # 'a*' matches 'aa'
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 2 passed\n")
    
    # Test case 3: Dot pattern
    print("Test 3: s='ab', p='a.'")
    result = sol.isMatch("ab", "a.")
    expected = True  # 'a.' matches 'ab'
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 3 passed\n")
    
    # Test case 4: Complex star pattern
    print("Test 4: s='aab', p='c*a*b'")
    result = sol.isMatch("aab", "c*a*b")
    expected = True  # 'c*a*b' matches 'aab'
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 4 passed\n")
    
    # Test case 5: No match
    print("Test 5: s='mississippi', p='mis*is*p*.'")
    result = sol.isMatch("mississippi", "mis*is*p*.")
    expected = False  # Pattern doesn't match
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 5 passed\n")
    
    # Test case 6: Empty strings
    print("Test 6: s='', p=''")
    result = sol.isMatch("", "")
    expected = True  # Empty matches empty
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 6 passed\n")
    
    # Test case 7: Empty string with pattern
    print("Test 7: s='', p='a*'")
    result = sol.isMatch("", "a*")
    expected = True  # 'a*' can match zero 'a's
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 7 passed\n")
    
    # Test case 8: String with empty pattern
    print("Test 8: s='a', p=''")
    result = sol.isMatch("a", "")
    expected = False  # Empty pattern doesn't match non-empty string
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 8 passed\n")
    
    # Test case 9: Multiple stars
    print("Test 9: s='aaa', p='a*a*a*'")
    result = sol.isMatch("aaa", "a*a*a*")
    expected = True  # Multiple stars can match
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 9 passed\n")
    
    # Test case 10: Dot with star
    print("Test 10: s='ab', p='.*'")
    result = sol.isMatch("ab", ".*")
    expected = True  # '.*' matches any string
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 10 passed\n")
    
    # Test case 11: Complex pattern
    print("Test 11: s='ab', p='.*c'")
    result = sol.isMatch("ab", ".*c")
    expected = False  # '.*c' doesn't match 'ab'
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 11 passed\n")
    
    # Test case 12: Edge case with stars
    print("Test 12: s='a', p='ab*'")
    result = sol.isMatch("a", "ab*")
    expected = True  # 'ab*' matches 'a' (b* matches zero b's)
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 12 passed\n")
    
    print("All tests passed!")


if __name__ == "__main__":
    test_regular_expression_matching()
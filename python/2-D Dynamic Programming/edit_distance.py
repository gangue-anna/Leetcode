class Solution:
    """
    Edit Distance (Levenshtein Distance)
    
    Problem: Given two strings word1 and word2, return the minimum number of operations
    required to convert word1 to word2. You may perform the following operations:
    - Insert a character
    - Delete a character
    - Replace a character
    
    Example: word1 = "horse", word2 = "ros"
    Output: 3 (horse -> rorse -> rose -> ros)
    
    Approach: Bottom-up Dynamic Programming
    - Use a 2D DP table where cache[i][j] = min edit distance to convert word1[i:] to word2[j:]
    - Fill the table from the end of the strings to the beginning
    - If characters match, no operation needed; else, consider insert, delete, replace
    - Base cases: converting empty suffixes
    
    Time Complexity: O(m * n) where m = len(word1), n = len(word2)
    Space Complexity: O(m * n) for the DP table
    """
    
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        # Initialize DP table with zeros (int, not float)
        cache = [[0] * (n + 1) for _ in range(m + 1)]
        
        # Base cases: converting to/from empty string
        for j in range(n + 1):
            cache[m][j] = n - j  # Insert all remaining characters of word2
        for i in range(m + 1):
            cache[i][n] = m - i  # Delete all remaining characters of word1
        
        # Fill the table bottom-up
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if word1[i] == word2[j]:
                    # Characters match, no operation needed
                    cache[i][j] = cache[i + 1][j + 1]
                else:
                    # Consider insert, delete, replace
                    insert = cache[i][j + 1]      # Insert word2[j] into word1
                    delete = cache[i + 1][j]      # Delete word1[i]
                    replace = cache[i + 1][j + 1] # Replace word1[i] with word2[j]
                    cache[i][j] = 1 + min(insert, delete, replace)
        
        return cache[0][0]


# Test cases
def test_edit_distance():
    """Test cases for Edit Distance problem"""
    
    # Test case 1: Basic case
    print("Test 1: word1='horse', word2='ros'")
    sol = Solution()
    result = sol.minDistance("horse", "ros")
    expected = 3  # horse -> rorse -> rose -> ros
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 1 passed\n")
    
    # Test case 2: Identical strings
    print("Test 2: word1='intention', word2='intention'")
    result = sol.minDistance("intention", "intention")
    expected = 0  # No operations needed
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 2 passed\n")
    
    # Test case 3: One empty string
    print("Test 3: word1='', word2='abc'")
    result = sol.minDistance("", "abc")
    expected = 3  # Insert all characters
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 3 passed\n")
    
    # Test case 4: Both empty strings
    print("Test 4: word1='', word2=''")
    result = sol.minDistance("", "")
    expected = 0  # No operations needed
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 4 passed\n")
    
    # Test case 5: Replace all characters
    print("Test 5: word1='abc', word2='def'")
    result = sol.minDistance("abc", "def")
    expected = 3  # Replace each character
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 5 passed\n")
    
    # Test case 6: Insert and delete
    print("Test 6: word1='abc', word2='ab'")
    result = sol.minDistance("abc", "ab")
    expected = 1  # Delete 'c'
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 6 passed\n")
    
    # Test case 7: Insert at beginning
    print("Test 7: word1='bc', word2='abc'")
    result = sol.minDistance("bc", "abc")
    expected = 1  # Insert 'a' at beginning
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 7 passed\n")
    
    # Test case 8: Complex case
    print("Test 8: word1='intention', word2='execution'")
    result = sol.minDistance("intention", "execution")
    expected = 5  # Standard example
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 8 passed\n")
    
    print("All tests passed!")


if __name__ == "__main__":
    test_edit_distance()

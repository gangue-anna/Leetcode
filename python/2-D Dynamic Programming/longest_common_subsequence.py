class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        """
        Find the length of the longest common subsequence between two strings.
        A subsequence is a sequence that appears in the same relative order but not necessarily contiguous.
        
        Approach:
        - Use dynamic programming with a 2D table.
        - dp[i][j] represents the length of LCS of text1[i:] and text2[j:].
        - Fill the table from bottom-right to top-left.
        - If characters match: dp[i][j] = 1 + dp[i+1][j+1]
        - If characters don't match: dp[i][j] = max(dp[i][j+1], dp[i+1][j])
        - Return dp[0][0] as the final result.
        
        Time Complexity: O(m * n), where m and n are the lengths of text1 and text2
        - We fill the entire DP table
        
        Space Complexity: O(m * n)
        - We store the entire DP table
        
        Args:
            text1: str - First string
            text2: str - Second string
        Returns:
            int - Length of the longest common subsequence
        """
        dp = [[0 for j in range(len(text2) + 1)] for i in range(len(text1) + 1)]

        for i in range(len(text1) - 1, -1, -1):
            for j in range(len(text2) - 1, -1, -1):
                if text1[i] == text2[j]:
                    # Characters match, add 1 to the diagonal value
                    dp[i][j] = 1 + dp[i + 1][j + 1]
                else:
                    # Characters don't match, take max of right and down values
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j])
                    
        return dp[0][0]

# -------------------
# Test Cases
# -------------------
def test_longest_common_subsequence():
    s = Solution()
    # Test case 1: Basic case
    assert s.longestCommonSubsequence("abcde", "ace") == 3, "Failed on 'abcde', 'ace'"
    # Test case 2: No common subsequence
    assert s.longestCommonSubsequence("abc", "def") == 0, "Failed on 'abc', 'def'"
    # Test case 3: Identical strings
    assert s.longestCommonSubsequence("abc", "abc") == 3, "Failed on 'abc', 'abc'"
    # Test case 4: One string is empty
    assert s.longestCommonSubsequence("abc", "") == 0, "Failed on 'abc', ''"
    # Test case 5: Both strings are empty
    assert s.longestCommonSubsequence("", "") == 0, "Failed on '', ''"
    # Test case 6: Complex case
    assert s.longestCommonSubsequence("bsbininm", "jmjkbkjkv") == 1, "Failed on 'bsbininm', 'jmjkbkjkv'"
    # Test case 7: Long strings
    assert s.longestCommonSubsequence("abcba", "abcbcba") == 5, "Failed on 'abcba', 'abcbcba'"
    print("All test cases passed!")

if __name__ == "__main__":
    test_longest_common_subsequence()
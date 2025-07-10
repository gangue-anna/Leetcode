class Solution:
    def longestPalindrome(self, s: str) -> str:
        # res: stores the longest palindromic substring found so far
        res = ""
        # resLen: stores the length of the longest palindrome
        resLen = 0

        for i in range(len(s)):
            # Check for odd-length palindromes centered at i
            l, r = i, i
            while l >= 0 and r < len(s) and s[l] == s[r]:
                # Update result if a longer palindrome is found
                if (r - l + 1) > resLen:
                    res = s[l : r + 1]
                    resLen  = r - l + 1
                l -= 1
                r += 1
            
            # Check for even-length palindromes centered between i and i+1
            l, r = i, i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if (r - l + 1) > resLen:
                    res = s[l : r + 1]
                    resLen  = r - l + 1
                l -= 1
                r += 1
        
        return res

# Time Complexity: O(n^2), where n is the length of the string. For each character, we expand around the center up to n times.
# Space Complexity: O(1), since we use only a constant amount of extra space (excluding the output string).

# -------------------
# Test Cases
# -------------------
def test_longest_palindromic_substring():
    s = Solution()
    # Test case 1: Example from Leetcode
    assert s.longestPalindrome("babad") in ["bab", "aba"]  # Both are valid
    # Test case 2: Another example
    assert s.longestPalindrome("cbbd") == "bb"
    # Test case 3: Single character
    assert s.longestPalindrome("a") == "a"
    # Test case 4: All characters same
    assert s.longestPalindrome("aaaa") == "aaaa"
    # Test case 5: No palindrome longer than 1
    assert s.longestPalindrome("abcde") in ["a", "b", "c", "d", "e"]
    # Test case 6: Empty string
    assert s.longestPalindrome("") == ""
    print("All test cases passed!")

if __name__ == "__main__":
    test_longest_palindromic_substring()
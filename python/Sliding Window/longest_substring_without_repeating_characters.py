class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        """
        Find the length of the longest substring without repeating characters (brute force with substring).
        Time Complexity: O(n^2)
        Space Complexity: O(n)
        """
        subStr = ""
        max_size = 0
        for c in s:
            if c not in subStr:
                subStr += c
                max_size = max(max_size, len(subStr))
            else:
                # Instead of resetting to empty, start from after the first occurrence
                subStr = subStr[subStr.index(c) + 1:] + c
                max_size = max(max_size, len(subStr))
        
        return max_size

class Solution2:
    def lengthOfLongestSubstring(self, s: str) -> int:
        """
        Find the length of the longest substring without repeating characters (optimized sliding window).
        Time Complexity: O(n)
        Space Complexity: O(n)
        """
        # Set to keep track of unique characters in current window
        charSet = set()
        # Left pointer of sliding window
        l = 0
        # Track maximum length found
        res = 0

        # Right pointer moves through the string
        for r in range(len(s)):
            # If current character is in set, remove characters from left
            # until we remove the first occurrence of current character
            while s[r] in charSet:
                charSet.remove(s[l])
                l += 1
            # Add current character to set
            charSet.add(s[r])
            # Update maximum length (r - l + 1 is current window size)
            res = max(res, r - l + 1)
        return res

# -------------------
# Test Cases
# -------------------
def test_longest_substring_without_repeating_characters():
    s1 = Solution()
    s2 = Solution2()
    # Test case 1: Basic
    assert s1.lengthOfLongestSubstring("abcabcbb") == 3
    assert s2.lengthOfLongestSubstring("abcabcbb") == 3
    # Test case 2: All same character
    assert s1.lengthOfLongestSubstring("bbbbb") == 1
    assert s2.lengthOfLongestSubstring("bbbbb") == 1
    # Test case 3: Empty string
    assert s1.lengthOfLongestSubstring("") == 0
    assert s2.lengthOfLongestSubstring("") == 0
    # Test case 4: All unique
    assert s1.lengthOfLongestSubstring("abcdef") == 6
    assert s2.lengthOfLongestSubstring("abcdef") == 6
    # Test case 5: Repeats at the end
    assert s1.lengthOfLongestSubstring("pwwkew") == 3
    assert s2.lengthOfLongestSubstring("pwwkew") == 3
    # Test case 6: Single character
    assert s1.lengthOfLongestSubstring("a") == 1
    assert s2.lengthOfLongestSubstring("a") == 1
    print("All test cases passed!")

if __name__ == "__main__":
    test_longest_substring_without_repeating_characters()
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        """
        Find the length of the longest substring that can be obtained by replacing at most k characters so all characters are the same.
        Approach:
        - Use sliding window and a hashmap to count character frequencies.
        - Track the max frequency in the window.
        - If window size minus max frequency > k, shrink window from the left.
        Time Complexity: O(n)
        Space Complexity: O(1) (since alphabet size is constant)
        """
        # Dictionary to store count of each character in current window
        count = {}
        res = 0
        l = 0
        max_freq = 0  # Track maximum frequency in current window

        for r in range(len(s)):
            # Update count of current character
            count[s[r]] = 1 + count.get(s[r], 0)
            # Update max frequency
            max_freq = max(max_freq, count[s[r]])

            # If window size minus max frequency is greater than k,
            # we need to shrink the window
            while (r - l + 1) - max_freq > k:
                count[s[l]] -= 1
                l += 1

            # Update result with current window size
            res = max(res, r - l + 1)
        
        return res

# -------------------
# Test Cases
# -------------------
def test_character_replacement():
    s = Solution()
    # Test case 1: Basic
    assert s.characterReplacement("ABAB", 2) == 4
    # Test case 2: Replace all
    assert s.characterReplacement("AABABBA", 1) == 4
    # Test case 3: No replacements needed
    assert s.characterReplacement("AAAA", 2) == 4
    # Test case 4: k = 0
    assert s.characterReplacement("AABABBA", 0) == 2
    # Test case 5: Empty string
    assert s.characterReplacement("", 2) == 0
    # Test case 6: All unique
    assert s.characterReplacement("ABCDE", 1) == 2
    print("All test cases passed!")

if __name__ == "__main__":
    test_character_replacement()

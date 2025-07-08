class Solution:
    def minWindow(self, s: str, t: str) -> str:
        """
        Find the minimum window in s that contains all characters in t.
        
        Approach:
        1. Use sliding window with two pointers
        2. Track character frequencies in both t and current window
        3. Expand window until all characters are found
        4. Contract window to find minimum valid window
        
        Time Complexity: O(n) where n is length of s
        Space Complexity: O(k) where k is number of unique characters in t
        """
        if t == "": return ""

        # Initialize frequency maps
        countT = {}  # Frequency map for string t
        window = {}  # Frequency map for current window

        # Count frequencies in t
        for c in t:
            countT[c] = 1 + countT.get(c,0)

        have = 0  # Number of characters that match required frequency
        need = len(countT)  # Number of unique characters needed
        res, resLen = [-1, -1], float("infinity")  # Track minimum window
        l = 0  # Left pointer

        # Slide window
        for r in range(len(s)):
            c = s[r]
            window[c] = 1 + window.get(c,0)

            # If current character matches required frequency, increment have
            if c in countT and window[c] == countT[c]:
                have += 1

            # Try to minimize window while maintaining all required characters
            while have == need:
                # Update result if current window is smaller
                if (r - l + 1) < resLen:
                    res = [l,r]
                    resLen = r - l + 1

                # Remove leftmost character from window
                window[s[l]] -= 1
                if s[l] in countT and window[s[l]] < countT[s[l]]:
                    have -= 1
                l += 1
            
        l, r = res
        return s[l: r+1] if resLen != float("infinity") else ""

# -------------------
# Test Cases
# -------------------
def test_minimum_window_substring():
    s = Solution()
    # Test case 1: Basic
    assert s.minWindow("ADOBECODEBANC", "ABC") == "BANC"
    # Test case 2: t is longer than s
    assert s.minWindow("A", "AA") == ""
    # Test case 3: t is empty
    assert s.minWindow("A", "") == ""
    # Test case 4: s is empty
    assert s.minWindow("", "A") == ""
    # Test case 5: All characters same
    assert s.minWindow("AAAAA", "AA") == "AA"
    # Test case 6: No valid window
    assert s.minWindow("ABC", "D") == ""
    # Test case 7: Multiple valid windows, return smallest
    assert s.minWindow("aaflslflsldkalskaaa", "aaa") == "aaa"
    print("All test cases passed!")

if __name__ == "__main__":
    test_minimum_window_substring()
        
class Solution:
    def countSubstrings(self, s: str) -> int:
        # res: stores the total number of palindromic substrings
        res = 0
        
        for i in range(len(s)):
            # Check for odd-length palindromes centered at i
            l = r = i
            while l >= 0 and r < len(s) and s[l] == s[r]:
                res += 1
                l -= 1
                r += 1

            # Check for even-length palindromes centered between i and i+1
            l, r = i, i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                res += 1
                l -= 1
                r += 1
        return res

# Time Complexity: O(n^2), where n is the length of the string. For each character, we expand around the center up to n times.
# Space Complexity: O(1), since only a constant amount of extra space is used.

# Better modularity of code
class Solution2:
    def countSubstrings(self, s: str) -> int:
        # res: stores the total number of palindromic substrings
        res = 0
        
        for i in range(len(s)):
            # Count odd-length palindromes centered at i
            res += self.countPali(s, i, i)
            # Count even-length palindromes centered between i and i+1
            res += self.countPali(s, i, i + 1)
        
        return res
        
    def countPali(self, s, l, r):
        # Helper function to count palindromes expanding from the center (l, r)
        res = 0
        while l >= 0 and r < len(s) and s[l] == s[r]:
            res += 1
            l -= 1
            r += 1
        return res

# Time Complexity: O(n^2), where n is the length of the string. For each character, we expand around the center up to n times.
# Space Complexity: O(1), since only a constant amount of extra space is used.

# -------------------
# Test Cases
# -------------------
def test_palindromic_substrings():
    s1 = Solution()
    s2 = Solution2()
    # Test case 1: Example from Leetcode
    assert s1.countSubstrings("abc") == 3
    assert s2.countSubstrings("abc") == 3
    # Test case 2: Another example
    assert s1.countSubstrings("aaa") == 6
    assert s2.countSubstrings("aaa") == 6
    # Test case 3: Single character
    assert s1.countSubstrings("a") == 1
    assert s2.countSubstrings("a") == 1
    # Test case 4: All characters different
    assert s1.countSubstrings("abcd") == 4
    assert s2.countSubstrings("abcd") == 4
    # Test case 5: Empty string
    assert s1.countSubstrings("") == 0
    assert s2.countSubstrings("") == 0
    print("All test cases passed!")

if __name__ == "__main__":
    test_palindromic_substrings()

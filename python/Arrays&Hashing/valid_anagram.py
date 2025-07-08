class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        """
        Approach:
        - If the lengths differ, return False immediately.
        - Count the frequency of each character in both strings using dictionaries.
        - Compare the two dictionaries; if they are equal, the strings are anagrams.

        Time Complexity: O(n), where n is the length of the strings.
        Space Complexity: O(1), since the alphabet size is fixed (26 lowercase letters), or O(k) for k unique characters.
        """
        if len(s) != len(t):
            return False
        countS, countT = {}, {}
        for i in range(len(s)):
            countS[s[i]] = 1 + countS.get(s[i], 0)
            countT[t[i]] = 1 + countT.get(t[i], 0)
        return countS == countT

# -------------------
# Test Cases
# -------------------
def test_valid_anagram():
    sol = Solution()
    # Test case 1: Example from Leetcode
    assert sol.isAnagram("anagram", "nagaram") == True
    # Test case 2: Not anagrams
    assert sol.isAnagram("rat", "car") == False
    # Test case 3: Empty strings
    assert sol.isAnagram("", "") == True
    # Test case 4: Different lengths
    assert sol.isAnagram("a", "ab") == False
    # Test case 5: Unicode characters
    assert sol.isAnagram("你好", "好你") == True
    print("All test cases passed!")

if __name__ == "__main__":
    test_valid_anagram()
    
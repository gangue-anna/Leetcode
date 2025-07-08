from typing import List

class Solution:
    def encode(self, strs : List[str]) -> str:
        """
        Approach:
        - For each string, prepend its length and a special delimiter (e.g., '#') before the string itself.
        - Concatenate all such encoded strings into a single string.
        - This allows us to uniquely decode each string, even if it contains the delimiter.

        Time Complexity: O(N), where N is the total number of characters in all strings.
        Space Complexity: O(N), for the result string.
        """
        res = ""
        for s in strs:
            res += str(len(s)) + '#' + s
        return res
    
    def decode(self, s : str) -> List[str]:
        """
        Approach:
        - Parse the encoded string by reading the length before each '#', then extract the substring of that length.
        - Repeat until the end of the string.

        Time Complexity: O(N), where N is the length of the encoded string.
        Space Complexity: O(N), for the result list.
        """
        res, i = [], 0
        while i < len(s):
            j = i 
            while s[j] != "#":
                j += 1
            length = int(s[i:j])
            res.append(s[j+1 : j+1+length])
            i = j + 1 + length
        return res

# -------------------
# Test Cases
# -------------------
def test_encode_decode_strings():
    sol = Solution()
    # Test case 1: Basic strings
    strs1 = ["hello", "world"]
    encoded1 = sol.encode(strs1)
    assert sol.decode(encoded1) == strs1
    # Test case 2: Strings with special characters
    strs2 = ["a#b#c", "##", "123"]
    encoded2 = sol.encode(strs2)
    assert sol.decode(encoded2) == strs2
    # Test case 3: Empty list
    strs3 = []
    encoded3 = sol.encode(strs3)
    assert sol.decode(encoded3) == strs3
    # Test case 4: List with empty strings
    strs4 = ["", "abc", ""]
    encoded4 = sol.encode(strs4)
    assert sol.decode(encoded4) == strs4
    # Test case 5: Single long string
    strs5 = ["a" * 1000]
    encoded5 = sol.encode(strs5)
    assert sol.decode(encoded5) == strs5
    print("All test cases passed!")

if __name__ == "__main__":
    test_encode_decode_strings()
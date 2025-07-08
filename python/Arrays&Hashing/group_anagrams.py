from typing import List
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        """
        Approach:
        - For each string, count the frequency of each character (assuming lowercase English letters).
        - Use the tuple of counts as a key in a dictionary to group anagrams together.
        - Return the grouped anagrams as a list of lists.

        Time Complexity: O(N * K), where N is the number of strings and K is the maximum length of a string.
        Space Complexity: O(N * K), for the result and the hash map.
        """
        res = defaultdict(list)
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord("a")] += 1 # ord() returns the ASCII value of the character.
            res[tuple(count)].append(s) # Use tuple as key since lists are not hashable.
        return list(res.values())

# -------------------
# Test Cases
# -------------------
def test_group_anagrams():
    sol = Solution()
    # Test case 1: Basic anagrams
    strs1 = ["eat", "tea", "tan", "ate", "nat", "bat"]
    result1 = sol.groupAnagrams(strs1)
    assert sorted([sorted(group) for group in result1]) == sorted([sorted(group) for group in [["eat","tea","ate"],["tan","nat"],["bat"]]])
    # Test case 2: Single string
    strs2 = ["abc"]
    assert sol.groupAnagrams(strs2) == [["abc"]]
    # Test case 3: Empty list
    strs3 = []
    assert sol.groupAnagrams(strs3) == []
    # Test case 4: All strings are anagrams
    strs4 = ["abc", "bca", "cab"]
    result4 = sol.groupAnagrams(strs4)
    assert sorted([sorted(group) for group in result4]) == [["abc", "bca", "cab"]]
    # Test case 5: No anagrams
    strs5 = ["a", "b", "c"]
    result5 = sol.groupAnagrams(strs5)
    assert sorted([sorted(group) for group in result5]) == [["a"], ["b"], ["c"]]
    print("All test cases passed!")

if __name__ == "__main__":
    test_group_anagrams()
    
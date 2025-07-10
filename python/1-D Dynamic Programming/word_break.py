from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # dp[i]: True if s[i:] can be segmented into words from wordDict
        dp = [False] * (len(s) + 1)
        dp[len(s)] = True  # Base case: empty string can always be segmented

        # Iterate backwards through the string
        for i in range(len(s) - 1, -1, -1):
            for w in wordDict:
                # If the word w matches the substring starting at i
                if (i + len(w)) <= len(s) and s[i: i + len(w)] == w:
                    # If the rest of the string can be segmented, mark dp[i] as True
                    dp[i] = dp[i + len(w)]
                if dp[i]:  # Early break if we found a valid segmentation
                    break
        return dp[0]

# Time Complexity: O(n * m * k), where n = len(s), m = len(wordDict), k = average word length in wordDict.
# Space Complexity: O(n), for the dp array.

# -------------------
# Test Cases
# -------------------
def test_word_break():
    s = Solution()
    # Test case 1: Example from Leetcode
    assert s.wordBreak("leetcode", ["leet", "code"]) == True
    # Test case 2: Another example
    assert s.wordBreak("applepenapple", ["apple", "pen"]) == True
    # Test case 3: No valid segmentation
    assert s.wordBreak("catsandog", ["cats", "dog", "sand", "and", "cat"]) == False
    # Test case 4: Single word
    assert s.wordBreak("apple", ["apple"]) == True
    # Test case 5: Empty string
    assert s.wordBreak("", ["a"]) == True
    # Test case 6: WordDict contains empty string
    assert s.wordBreak("a", [""]) == False
    print("All test cases passed!")

if __name__ == "__main__":
    test_word_break()
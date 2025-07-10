class Solution:
    def numDecodings(self, s: str) -> int:
        # dp[i]: number of ways to decode the substring s[i:]
        # Base case: an empty string has 1 way to decode
        dp = {len(s) : 1}

        def dfs(i):
            # If we've already computed dp[i], return it
            if i in dp:
                return dp[i]
            # If the current character is '0', it can't be decoded
            if s[i] == "0":
                return 0
            
            # Decode one character
            res = dfs(i + 1)
            # Decode two characters if it's valid (10-26)
            if (i + 1 < len(s) and (s[i] == "1" or
                s[i] == "2" and s[i + 1] in "0123456")):
                res += dfs(i + 2)
            dp[i] = res
            return res
        
        return dfs(0)

# Time Complexity: O(n), where n is the length of s. Each index is computed at most once due to memoization.
# Space Complexity: O(n), for the recursion stack and memoization dictionary.

class Solution2:
    def numDecodings(self, s: str) -> int:
        # dp[i]: number of ways to decode the substring s[i:]
        # Base case: an empty string has 1 way to decode
        dp = {len(s) : 1}

        # Iterate backwards through the string
        for i in range(len(s) - 1, -1, -1):
            # If the current character is '0', it can't be decoded
            if s[i] == "0":
                dp[i] = 0
            else:
                # Decode one character
                dp[i] = dp[i + 1]
            
            # Decode two characters if it's valid (10-26)
            if (i + 1 < len(s) and (s[i] == "1" or
                s[i] == "2" and s[i + 1] in "0123456")):
                dp[i] += dp[i + 2]
        return dp[0]

# Time Complexity: O(n), where n is the length of s. Each index is visited once in the loop.
# Space Complexity: O(n), for the dp dictionary.

# -------------------
# Test Cases
# -------------------
def test_decode_ways():
    s1 = Solution()
    s2 = Solution2()
    # Test case 1: Example from Leetcode
    assert s1.numDecodings("12") == 2  # "AB", "L"
    assert s2.numDecodings("12") == 2
    # Test case 2: Another example
    assert s1.numDecodings("226") == 3  # "BBF", "BZ", "VF"
    assert s2.numDecodings("226") == 3
    # Test case 3: String with '0'
    assert s1.numDecodings("06") == 0
    assert s2.numDecodings("06") == 0
    # Test case 4: Single character
    assert s1.numDecodings("1") == 1
    assert s2.numDecodings("1") == 1
    # Test case 5: Empty string
    assert s1.numDecodings("") == 1  # By convention, empty string has 1 way
    assert s2.numDecodings("") == 1
    # Test case 6: Long string
    assert s1.numDecodings("11106") == 2
    assert s2.numDecodings("11106") == 2
    print("All test cases passed!")

if __name__ == "__main__":
    test_decode_ways()
            
class Solution:
    def climbStairs(self, n: int) -> int:
        """
        Given n stairs, return the number of distinct ways to climb to the top.
        Each time you can climb 1 or 2 steps.

        Approach:
        - This is a classic dynamic programming problem (Fibonacci sequence).
        - Let dp[i] be the number of ways to reach step i.
        - dp[i] = dp[i-1] + dp[i-2] (from one step below or two steps below)
        - We optimize space by only keeping the last two results (one, two).

        Time Complexity: O(n)
            - We iterate once from 0 to n-1.
        Space Complexity: O(1)
            - Only two variables are used for state.
        """
        p, q = 1, 1 #0th Step = 1 way, 1st Step = 1 way
        
        if n == 0:
            return p
        if n == 1:
            return q
        
        for i in range(n - 1):
            temp = p
            p = q
            q = temp + q
        return q

class Solution2:
    def climbStairs(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[n] = 1
        dp[n - 1] = 1

        for i in range(n-2, -1, -1):
            dp[i] = dp[i + 1] + dp[i + 2]
        
        return dp[0]

def test_climb_stairs():
    solution = Solution()
    # Test case 1: n = 2
    n1 = 2
    expected1 = 2  # (1+1, 2)
    result1 = solution.climbStairs(n1)
    print(f"Test 1: {result1 == expected1}, Expected: {expected1}, Got: {result1}")

    # Test case 2: n = 3
    n2 = 3
    expected2 = 3  # (1+1+1, 1+2, 2+1)
    result2 = solution.climbStairs(n2)
    print(f"Test 2: {result2 == expected2}, Expected: {expected2}, Got: {result2}")

    # Test case 3: n = 4
    n3 = 4
    expected3 = 5
    result3 = solution.climbStairs(n3)
    print(f"Test 3: {result3 == expected3}, Expected: {expected3}, Got: {result3}")

    # Test case 4: n = 1
    n4 = 1
    expected4 = 1
    result4 = solution.climbStairs(n4)
    print(f"Test 4: {result4 == expected4}, Expected: {expected4}, Got: {result4}")

    # Test case 5: n = 5
    n5 = 5
    expected5 = 8
    result5 = solution.climbStairs(n5)
    print(f"Test 5: {result5 == expected5}, Expected: {expected5}, Got: {result5}")

if __name__ == "__main__":
    test_climb_stairs()

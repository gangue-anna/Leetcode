from typing import List

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # dp[a]: minimum number of coins needed to make amount 'a'
        # Initialize dp array with amount+1 (impossible high value)
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0  # Base case: 0 coins needed to make amount 0

        # Build up the dp array from 1 to amount
        for a in range(1, amount + 1):
            for c in coins:
                if a - c >= 0:
                    # If we can use coin c, update dp[a] if using c results in fewer coins
                    dp[a] = min(dp[a], 1 + dp[a - c])

        # If dp[amount] was not updated, return -1 (not possible to make amount)
        return dp[amount] if dp[amount] != amount + 1 else -1

# Time Complexity: O(amount * n), where n is the number of coins.
# Space Complexity: O(amount), for the dp array.

# -------------------
# Test Cases
# -------------------
def test_coin_change():
    s = Solution()
    # Test case 1: Example from Leetcode
    assert s.coinChange([1,2,5], 11) == 3  # 11 = 5 + 5 + 1
    # Test case 2: No solution
    assert s.coinChange([2], 3) == -1
    # Test case 3: Single coin, exact match
    assert s.coinChange([1], 0) == 0
    # Test case 4: Single coin, multiple needed
    assert s.coinChange([1], 2) == 2
    # Test case 5: Multiple coins, amount is a coin
    assert s.coinChange([2,5,10,1], 10) == 1
    # Test case 6: Large amount, multiple coins
    assert s.coinChange([1,2,5], 100) == 20
    print("All test cases passed!")

if __name__ == "__main__":
    test_coin_change()
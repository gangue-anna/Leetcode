from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        Find the maximum profit you can achieve from buying and selling stocks with cooldown.
        You cannot buy on the next day after selling (cooldown period).
        
        Approach:
        - Use dynamic programming with memoization.
        - State: (i, buying) where i is the current day and buying is a boolean.
        - If buying: can either buy (move to next day) or cooldown (skip current day).
        - If selling: can either sell (move to day after next due to cooldown) or cooldown.
        - Use memoization to avoid recalculating the same states.
        - Return the maximum profit starting from day 0 with buying state.
        
        Time Complexity: O(n), where n is the number of days
        - Each state is calculated at most once due to memoization
        
        Space Complexity: O(n)
        - The memoization cache stores at most O(n) states
        
        Args:
            prices: List[int] - List of stock prices for each day
        Returns:
            int - Maximum profit achievable
        """
        # State - Buying or Selling?
        # If Buy -> i + 1
        # If Sell -> i + 2

        dp = {} # key = (i, buying), val = max_profit

        def dfs(i, buying):
            # Base case: if we've reached the end of prices
            if i >= len(prices):
                return 0
            # If we've already calculated this state, return cached result
            if (i, buying) in dp:
                return dp[(i, buying)]
            
            # Cooldown: skip current day
            cooldown = dfs(i + 1, buying)
            if buying:
                # If we're in buying state, we can either buy or cooldown
                buy = dfs(i + 1, not buying) - prices[i]
                dp[(i, buying)] = max(buy, cooldown)
            else:
                # If we're in selling state, we can either sell or cooldown
                # After selling, we must skip the next day (cooldown)
                sell = dfs(i + 2, not buying) + prices[i]
                dp[(i, buying)] = max(sell, cooldown)
            return dp[(i, buying)]
        
        return dfs(0, True)

# -------------------
# Test Cases
# -------------------
def test_max_profit():
    s = Solution()
    # Test case 1: Basic case
    assert s.maxProfit([1,2,3,0,2]) == 3, "Failed on [1,2,3,0,2]"
    # Test case 2: Increasing prices
    assert s.maxProfit([1,2,3,4,5]) == 4, "Failed on [1,2,3,4,5]"
    # Test case 3: Decreasing prices
    assert s.maxProfit([5,4,3,2,1]) == 0, "Failed on [5,4,3,2,1]"
    # Test case 4: Single price
    assert s.maxProfit([1]) == 0, "Failed on [1]"
    # Test case 5: Two prices
    assert s.maxProfit([1,2]) == 1, "Failed on [1,2]"
    # Test case 6: Empty list
    assert s.maxProfit([]) == 0, "Failed on []"
    # Test case 7: Complex case
    assert s.maxProfit([6,1,3,2,4,7]) == 6, "Failed on [6,1,3,2,4,7]"
    print("All test cases passed!")

if __name__ == "__main__":
    test_max_profit()

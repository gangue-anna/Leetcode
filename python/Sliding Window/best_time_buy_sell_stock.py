from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        Find the maximum profit from a single buy and sell of stock.
        Approach:
        - Use two pointers (buy and sell) to track the minimum price and the best profit.
        - Move the sell pointer forward, updating buy pointer if a lower price is found.
        Time Complexity: O(n)
        Space Complexity: O(1)
        """
        l, r = 0, 1  # l = buy pointer, r = sell pointer
        max_profit = 0
        
        # Slide the window until we reach the end
        while r < len(prices):
            # If current price is higher than buy price, calculate profit
            if prices[l] < prices[r]:
                profit = prices[r] - prices[l]
                max_profit = max(profit, max_profit)
            else:
                # If current price is lower, update buy pointer
                # This is because we found a better buying point
                l = r
            r += 1  # Always move sell pointer forward
        
        return max_profit

# -------------------
# Test Cases
# -------------------
def test_max_profit():
    s = Solution()
    # Test case 1: Increasing prices
    assert s.maxProfit([1,2,3,4,5]) == 4
    # Test case 2: Decreasing prices
    assert s.maxProfit([5,4,3,2,1]) == 0
    # Test case 3: Fluctuating prices
    assert s.maxProfit([7,1,5,3,6,4]) == 5
    # Test case 4: Single price
    assert s.maxProfit([5]) == 0
    # Test case 5: Empty list
    assert s.maxProfit([]) == 0
    # Test case 6: Two prices, profit
    assert s.maxProfit([1,2]) == 1
    # Test case 7: Two prices, no profit
    assert s.maxProfit([2,1]) == 0
    print("All test cases passed!")

if __name__ == "__main__":
    test_max_profit()
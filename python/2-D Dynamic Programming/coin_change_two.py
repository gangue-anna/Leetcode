from typing import List

class Solution:
    """
    Coin Change II - Number of Ways to Make Amount
    
    Problem: Given an array of coins and an amount, find the number of different ways
    to make up that amount using the coins. Each coin can be used unlimited times.
    
    Approach: Top-down Dynamic Programming with Memoization
    - Use DFS with memoization to explore all possible combinations
    - At each step, we can either use the current coin or skip to the next coin
    - Memoize results to avoid recalculating the same subproblems
    
    Time Complexity: O(amount * len(coins))
    Space Complexity: O(amount * len(coins)) for memoization cache
    """
    
    def change(self, amount: int, coins: List[int]) -> int:
        # Memoization cache to store computed results
        cache = {}

        def dfs(i, a):
            """
            DFS helper function to find number of ways to make amount
            
            Args:
                i: Current coin index
                a: Current accumulated amount
            
            Returns:
                Number of ways to make the target amount from current state
            """
            # Base case: we've reached the target amount
            if a == amount:
                return 1
            # Base case: we've exceeded the target amount
            if a > amount:
                return 0
            # Base case: we've used all coins but haven't reached target
            if i == len(coins):
                return 0
            # Return cached result if already computed
            if (i, a) in cache:
                return cache[(i, a)]
            
            # Two choices:
            # 1. Use current coin (stay at same index, add coin value)
            # 2. Skip current coin (move to next index, keep same amount)
            cache[(i, a)] = dfs(i, a + coins[i]) + dfs(i + 1, a)
            return cache[(i, a)]
            
        return dfs(0, 0)
    
class Solution2:
    """
    Coin Change II - Number of Ways to Make Amount
    
    Problem: Given an array of coins and an amount, find the number of different ways
    to make up that amount using the coins. Each coin can be used unlimited times.
    
    Approach: Bottom-up Dynamic Programming
    - Use 2D DP table where dp[a][i] = number of ways to make amount 'a' 
      using coins from index 'i' onwards
    - Fill the table bottom-up, building solutions from smaller amounts
    - For each amount and coin index, we can either use the current coin or skip it
    
    Time Complexity: O(amount * len(coins))
    Space Complexity: O(amount * len(coins)) for DP table
    """
    
    def change(self, amount: int, coins: List[int]) -> int:
        # DP table: dp[a][i] = ways to make amount 'a' using coins[i:]
        dp = [[0] * (len(coins) + 1) for i in range(amount + 1)]
        
        # Base case: there's 1 way to make amount 0 (use no coins)
        dp[0] = [1] * (len(coins) + 1)

        # Fill DP table bottom-up
        for a in range(1, amount + 1):
            for i in range(len(coins) - 1, -1, -1):
                # Start with the result from skipping current coin
                dp[a][i] = dp[a][i + 1]
                
                # If we can use current coin, add ways from using it
                if a - coins[i] >= 0:
                    dp[a][i] += dp[a - coins[i]][i]
                    
        return dp[amount][0]


class Solution3:
    """
    Coin Change II - Number of Ways to Make Amount
    
    Problem: Given an array of coins and an amount, find the number of different ways
    to make up that amount using the coins. Each coin can be used unlimited times.
    
    Approach: Space-Optimized Bottom-up Dynamic Programming
    - Use 1D DP array where dp[a] = number of ways to make amount 'a'
    - Process coins in reverse order to avoid overcounting
    - For each coin, update the DP array by considering both using and not using the coin
    - This approach uses only O(amount) space instead of O(amount * len(coins))
    
    Time Complexity: O(amount * len(coins))
    Space Complexity: O(amount) - optimized space usage
    """
    
    def change(self, amount: int, coins: List[int]) -> int:
        # 1D DP array: dp[a] = ways to make amount 'a'
        dp = [0] * (amount + 1)
        # Base case: there's 1 way to make amount 0 (use no coins)
        dp[0] = 1

        # Process coins in reverse order to avoid overcounting
        for i in range(len(coins) - 1, -1, -1):
            # Create new DP array for current coin
            nextDP = [0] * (amount + 1)
            # Base case: always 1 way to make amount 0
            nextDP[0] = 1

            # For each amount, calculate ways using current coin
            for a in range(1, amount + 1):
                # Start with ways from not using current coin
                nextDP[a] = dp[a]
                
                # If we can use current coin, add ways from using it
                if a - coins[i] >= 0:
                    nextDP[a] += nextDP[a - coins[i]]
                    
            # Update DP array for next iteration
            dp = nextDP
            
        return dp[amount]


# Test cases
def test_coin_change_two():
    """Test cases for Coin Change II problem"""
    
    # Test case 1: Basic case
    print("Test 1: amount=5, coins=[1,2,5]")
    sol1 = Solution()
    sol2 = Solution2()
    sol3 = Solution3()
    result1 = sol1.change(5, [1, 2, 5])
    result2 = sol2.change(5, [1, 2, 5])
    result3 = sol3.change(5, [1, 2, 5])
    expected = 4  # Ways: [1,1,1,1,1], [1,1,1,2], [1,2,2], [5]
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    print(f"Solution3 result: {result3}, Expected: {expected}")
    assert result1 == expected and result2 == expected and result3 == expected
    print("✓ Test 1 passed\n")
    
    # Test case 2: Amount 0
    print("Test 2: amount=0, coins=[1,2,5]")
    result1 = sol1.change(0, [1, 2, 5])
    result2 = sol2.change(0, [1, 2, 5])
    result3 = sol3.change(0, [1, 2, 5])
    expected = 1  # One way: use no coins
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    print(f"Solution3 result: {result3}, Expected: {expected}")
    assert result1 == expected and result2 == expected and result3 == expected
    print("✓ Test 2 passed\n")
    
    # Test case 3: Impossible amount
    print("Test 3: amount=3, coins=[2]")
    result1 = sol1.change(3, [2])
    result2 = sol2.change(3, [2])
    result3 = sol3.change(3, [2])
    expected = 0  # No way to make 3 with only coin 2
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    print(f"Solution3 result: {result3}, Expected: {expected}")
    assert result1 == expected and result2 == expected and result3 == expected
    print("✓ Test 3 passed\n")
    
    # Test case 4: Single coin type
    print("Test 4: amount=10, coins=[1]")
    result1 = sol1.change(10, [1])
    result2 = sol2.change(10, [1])
    result3 = sol3.change(10, [1])
    expected = 1  # Only one way: use ten 1's
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    print(f"Solution3 result: {result3}, Expected: {expected}")
    assert result1 == expected and result2 == expected and result3 == expected
    print("✓ Test 4 passed\n")
    
    # Test case 5: Larger amount
    print("Test 5: amount=10, coins=[1,2,5]")
    result1 = sol1.change(10, [1, 2, 5])
    result2 = sol2.change(10, [1, 2, 5])
    result3 = sol3.change(10, [1, 2, 5])
    expected = 10  # Multiple ways to make 10
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    print(f"Solution3 result: {result3}, Expected: {expected}")
    assert result1 == expected and result2 == expected and result3 == expected
    print("✓ Test 5 passed\n")
    
    # Test case 6: Empty coins array
    print("Test 6: amount=5, coins=[]")
    result1 = sol1.change(5, [])
    result2 = sol2.change(5, [])
    result3 = sol3.change(5, [])
    expected = 0  # No coins available
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    print(f"Solution3 result: {result3}, Expected: {expected}")
    assert result1 == expected and result2 == expected and result3 == expected
    print("✓ Test 6 passed\n")
    
    # Test case 7: Large coins
    print("Test 7: amount=500, coins=[3,5,7,8,9,10,11]")
    result1 = sol1.change(500, [3, 5, 7, 8, 9, 10, 11])
    result2 = sol2.change(500, [3, 5, 7, 8, 9, 10, 11])
    result3 = sol3.change(500, [3, 5, 7, 8, 9, 10, 11])
    # All solutions should return the same result
    print(f"Solution1 result: {result1}")
    print(f"Solution2 result: {result2}")
    print(f"Solution3 result: {result3}")
    assert result1 == result2 == result3
    print("✓ Test 7 passed\n")
    
    # Test case 8: All coins larger than amount
    print("Test 8: amount=3, coins=[5,7,10]")
    result1 = sol1.change(3, [5, 7, 10])
    result2 = sol2.change(3, [5, 7, 10])
    result3 = sol3.change(3, [5, 7, 10])
    expected = 0  # No way to make 3 with coins >= 5
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    print(f"Solution3 result: {result3}, Expected: {expected}")
    assert result1 == expected and result2 == expected and result3 == expected
    print("✓ Test 8 passed\n")
    
    # Test case 9: Exact match with one coin
    print("Test 9: amount=5, coins=[5]")
    result1 = sol1.change(5, [5])
    result2 = sol2.change(5, [5])
    result3 = sol3.change(5, [5])
    expected = 1  # One way: use one coin of value 5
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    print(f"Solution3 result: {result3}, Expected: {expected}")
    assert result1 == expected and result2 == expected and result3 == expected
    print("✓ Test 9 passed\n")
    
    print("All tests passed!")


if __name__ == "__main__":
    test_coin_change_two()

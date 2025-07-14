from typing import List

class Solution:
    """
    Burst Balloons - Maximum Coins
    
    Problem: Given n balloons, each with a number on it, burst them to maximize coins.
    When you burst balloon i, you get nums[left] * nums[i] * nums[right] coins, where
    left and right are the adjacent balloons (not yet burst). The boundaries are treated
    as 1 (i.e., nums[-1] = nums[n] = 1). Return the maximum coins you can collect.
    
    Example: nums = [3,1,5,8]
    Output: 167
    Explanation: Burst order 1, 5, 3, 8 yields 167 coins.
    
    Approach: Dynamic Programming with Memoization (Interval DP)
    - Add 1 to both ends of nums to handle boundaries
    - Use DFS with memoization to try all possible last balloons to burst in interval [l, r]
    - For each interval, try bursting each balloon last and recursively solve subproblems
    - Memoize results to avoid recomputation
    - State: (l, r) = max coins for bursting all balloons in interval [l, r]
    
    Time Complexity: O(n^3) where n = len(nums)
    Space Complexity: O(n^2) for memoization cache
    """
    
    def maxCoins(self, nums: List[int]) -> int:
        # Add 1 to both ends to handle boundaries
        nums = [1] + nums + [1]
        dp = {}  # Memoization cache: (l, r) -> max coins for interval [l, r]

        def dfs(l, r):
            """
            DFS helper to compute max coins for bursting balloons in interval [l, r]
            Args:
                l: left index (inclusive)
                r: right index (inclusive)
            Returns:
                Maximum coins for bursting all balloons in [l, r]
            """
            # Base case: no balloons to burst
            if l > r:
                return 0
            # Return cached result if already computed
            if (l, r) in dp:
                return dp[(l, r)]

            max_coins = 0
            # Try bursting each balloon in [l, r] last
            for i in range(l, r + 1):
                # Coins from bursting balloon i last in this interval
                coins = nums[l - 1] * nums[i] * nums[r + 1]
                # Add coins from subproblems (left and right intervals)
                coins += dfs(l, i - 1) + dfs(i + 1, r)
                max_coins = max(max_coins, coins)
            dp[(l, r)] = max_coins
            return max_coins

        # Start with the interval covering the original nums
        return dfs(1, len(nums) - 2)


# Test cases
def test_burst_balloons():
    """Test cases for Burst Balloons problem"""
    
    # Test case 1: Basic case
    print("Test 1: nums=[3,1,5,8]")
    sol = Solution()
    result = sol.maxCoins([3,1,5,8])
    expected = 167  # Optimal burst order yields 167 coins
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 1 passed\n")
    
    # Test case 2: Single balloon
    print("Test 2: nums=[1]")
    result = sol.maxCoins([1])
    expected = 1  # Only one balloon, coins = 1*1*1
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 2 passed\n")
    
    # Test case 3: Two balloons
    print("Test 3: nums=[1,5]")
    result = sol.maxCoins([1,5])
    expected = 10  # Burst 1 then 5: 1*1*5 + 1*5*1 = 5 + 5 = 10
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 3 passed\n")
    
    # Test case 4: All ones
    print("Test 4: nums=[1,1,1,1]")
    result = sol.maxCoins([1,1,1,1])
    expected = 4  # Each burst gives 1, total 4
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 4 passed\n")
    
    # Test case 5: Empty array
    print("Test 5: nums=[]")
    result = sol.maxCoins([])
    expected = 0  # No balloons to burst
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 5 passed\n")
    
    # Test case 6: Increasing values
    print("Test 6: nums=[1,2,3,4,5]")
    result = sol.maxCoins([1,2,3,4,5])
    expected = 110  # Optimal burst order yields 110 coins
    print(f"Result: {result}, Expected: {expected}")
    assert result == expected
    print("✓ Test 6 passed\n")
    
    # Test case 7: Large values
    print("Test 7: nums=[9,76,64,21,97]")
    result = sol.maxCoins([9,76,64,21,97])
    # We don't check expected value here, just ensure no error and result is int
    print(f"Result: {result}, Type: {type(result)}")
    assert isinstance(result, int)
    print("✓ Test 7 passed\n")
    
    print("All tests passed!")


if __name__ == "__main__":
    test_burst_balloons()
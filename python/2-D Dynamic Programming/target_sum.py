from typing import List

class Solution:
    """
    Target Sum - Number of Ways to Achieve Target
    
    Problem: Given an array of integers and a target sum, find the number of ways to 
    assign '+' and '-' signs to each number so that the resulting expression equals 
    the target sum.
    
    Example: nums = [1,1,1,1,1], target = 3
    Output: 5 ways
    -1+1+1+1+1 = 3
    +1-1+1+1+1 = 3
    +1+1-1+1+1 = 3
    +1+1+1-1+1 = 3
    +1+1+1+1-1 = 3
    
    Approach: Dynamic Programming with Memoization
    - Use backtracking with memoization to explore all possible sign combinations
    - At each index, we can either add or subtract the current number
    - Memoize results to avoid recalculating the same subproblems
    - The state is represented by (index, current_total)
    
    Time Complexity: O(n * sum_range) where sum_range is the range of possible totals
    Space Complexity: O(n * sum_range) for memoization cache
    """
    
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        # Memoization cache: (index, total) -> number of ways
        dp = {}

        def backtrack(i, total):
            """
            Backtracking helper function to find ways to achieve target
            
            Args:
                i: Current index in nums array
                total: Current accumulated sum
            
            Returns:
                Number of ways to achieve target from current state
            """
            # Base case: reached end of array
            if i == len(nums):
                return 1 if total == target else 0
                
            # Return cached result if already computed
            if (i, total) in dp:
                return dp[(i, total)]

            # Two choices for current number:
            # 1. Add the current number (+)
            # 2. Subtract the current number (-)
            dp[(i, total)] = (backtrack(i + 1, total + nums[i]) + 
                             backtrack(i + 1, total - nums[i]))

            return dp[(i, total)]
        
        return backtrack(0, 0)


class Solution2:
    """
    Target Sum - Number of Ways to Achieve Target
    
    Problem: Given an array of integers and a target sum, find the number of ways to 
    assign '+' and '-' signs to each number so that the resulting expression equals 
    the target sum.
    
    Approach: Mathematical Optimization
    - Convert the problem to a subset sum problem
    - Let S be the sum of all numbers, P be the sum of positive numbers
    - Then: P - (S - P) = target => 2P = S + target => P = (S + target) / 2
    - Find the number of ways to select a subset with sum P
    - This reduces the problem to finding subsets that sum to (S + target) / 2
    
    Time Complexity: O(n * sum_range)
    Space Complexity: O(sum_range) - optimized space usage
    """
    
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        # Calculate total sum of all numbers
        total_sum = sum(nums)
        
        # If target is larger than total sum, impossible
        if abs(target) > total_sum:
            return 0
            
        # Calculate the subset sum we need to find
        # P - (S - P) = target => 2P = S + target => P = (S + target) / 2
        subset_sum = (total_sum + target) // 2
        
        # If subset_sum is not an integer, impossible
        if (total_sum + target) % 2 != 0:
            return 0
            
        # Use 1D DP to find ways to make subset_sum
        dp = [0] * (subset_sum + 1)
        dp[0] = 1  # Base case: one way to make sum 0
        
        # For each number, update DP array
        for num in nums:
            # Process in reverse to avoid using same number multiple times
            for i in range(subset_sum, num - 1, -1):
                dp[i] += dp[i - num]
                
        return dp[subset_sum]


# Test cases
def test_target_sum():
    """Test cases for Target Sum problem"""
    
    # Test case 1: Basic case
    print("Test 1: nums=[1,1,1,1,1], target=3")
    sol1 = Solution()
    sol2 = Solution2()
    result1 = sol1.findTargetSumWays([1, 1, 1, 1, 1], 3)
    result2 = sol2.findTargetSumWays([1, 1, 1, 1, 1], 3)
    expected = 5  # 5 ways: -1+1+1+1+1, +1-1+1+1+1, +1+1-1+1+1, +1+1+1-1+1, +1+1+1+1-1
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 1 passed\n")
    
    # Test case 2: Single number
    print("Test 2: nums=[1], target=1")
    result1 = sol1.findTargetSumWays([1], 1)
    result2 = sol2.findTargetSumWays([1], 1)
    expected = 1  # One way: +1
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 2 passed\n")
    
    # Test case 3: Single number, negative target
    print("Test 3: nums=[1], target=-1")
    result1 = sol1.findTargetSumWays([1], -1)
    result2 = sol2.findTargetSumWays([1], -1)
    expected = 1  # One way: -1
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 3 passed\n")
    
    # Test case 4: Impossible target
    print("Test 4: nums=[1,2], target=5")
    result1 = sol1.findTargetSumWays([1, 2], 5)
    result2 = sol2.findTargetSumWays([1, 2], 5)
    expected = 0  # Impossible to make 5 with 1 and 2
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 4 passed\n")
    
    # Test case 5: Zero target
    print("Test 5: nums=[1,1,1], target=0")
    result1 = sol1.findTargetSumWays([1, 1, 1], 0)
    result2 = sol2.findTargetSumWays([1, 1, 1], 0)
    expected = 0  # Impossible to make 0 with three 1's
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 5 passed\n")
    
    # Test case 6: Multiple ways
    print("Test 6: nums=[1,2,3], target=0")
    result1 = sol1.findTargetSumWays([1, 2, 3], 0)
    result2 = sol2.findTargetSumWays([1, 2, 3], 0)
    expected = 2  # Ways: +1+2-3=0, -1-2+3=0
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 6 passed\n")
    
    # Test case 7: Empty array
    print("Test 7: nums=[], target=0")
    result1 = sol1.findTargetSumWays([], 0)
    result2 = sol2.findTargetSumWays([], 0)
    expected = 1  # One way: empty expression equals 0
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 7 passed\n")
    
    # Test case 8: Large numbers
    print("Test 8: nums=[1,2,3,4,5], target=3")
    result1 = sol1.findTargetSumWays([1, 2, 3, 4, 5], 3)
    result2 = sol2.findTargetSumWays([1, 2, 3, 4, 5], 3)
    # Both solutions should return the same result
    print(f"Solution1 result: {result1}")
    print(f"Solution2 result: {result2}")
    assert result1 == result2
    print("✓ Test 8 passed\n")
    
    # Test case 9: All zeros
    print("Test 9: nums=[0,0,0], target=0")
    result1 = sol1.findTargetSumWays([0, 0, 0], 0)
    result2 = sol2.findTargetSumWays([0, 0, 0], 0)
    expected = 8  # 2^3 = 8 ways since each 0 can be +0 or -0
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 9 passed\n")
    
    # Test case 10: Large target
    print("Test 10: nums=[1,2,3,4,5], target=15")
    result1 = sol1.findTargetSumWays([1, 2, 3, 4, 5], 15)
    result2 = sol2.findTargetSumWays([1, 2, 3, 4, 5], 15)
    expected = 1  # One way: +1+2+3+4+5=15
    print(f"Solution1 result: {result1}, Expected: {expected}")
    print(f"Solution2 result: {result2}, Expected: {expected}")
    assert result1 == expected and result2 == expected
    print("✓ Test 10 passed\n")
    
    print("All tests passed!")


if __name__ == "__main__":
    test_target_sum()

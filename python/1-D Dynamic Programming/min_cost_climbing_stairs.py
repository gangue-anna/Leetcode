from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        """
        Given an array cost where cost[i] is the cost of step i, return the minimum cost to reach the top of the floor.
        You can start from step 0 or step 1, and at each move, you can climb one or two steps.

        Approach:
        - Dynamic Programming (bottom-up):
            - We append a 0 to the end of the cost array to represent the "top" (no cost to step off the stairs).
            - For each step from the end to the start, update cost[i] to be the cost of stepping on it plus the minimum cost of the next one or two steps.
            - The answer is the minimum of starting at step 0 or step 1.

        Time Complexity: O(n)
            - We iterate through the cost array once.
        Space Complexity: O(1)
            - We modify the input array in place (no extra space).
        """
        cost.append(0)  # Add a step for the "top" (no cost)

        for i in range(len(cost) - 3, -1, -1):
            # Update cost[i] to be the cost of this step plus the cheaper of the next two steps
            cost[i] += min(cost[i + 1], cost[i + 2])

        return min(cost[0], cost[1])  # Start from step 0 or 1, whichever is cheaper


def test_min_cost_climbing_stairs():
    solution = Solution()
    # Test case 1: Simple case
    cost1 = [10, 15, 20]
    expected1 = 15
    result1 = solution.minCostClimbingStairs(cost1.copy())
    print(f"Test 1: {result1 == expected1}, Expected: {expected1}, Got: {result1}")

    # Test case 2: Longer stairs
    cost2 = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    expected2 = 6
    result2 = solution.minCostClimbingStairs(cost2.copy())
    print(f"Test 2: {result2 == expected2}, Expected: {expected2}, Got: {result2}")

    # Test case 3: Only two steps
    cost3 = [0, 1]
    expected3 = 0
    result3 = solution.minCostClimbingStairs(cost3.copy())
    print(f"Test 3: {result3 == expected3}, Expected: {expected3}, Got: {result3}")

    # Test case 4: All costs the same
    cost4 = [5, 5, 5, 5]
    expected4 = 10
    result4 = solution.minCostClimbingStairs(cost4.copy())
    print(f"Test 4: {result4 == expected4}, Expected: {expected4}, Got: {result4}")

    # Test case 5: Single step
    cost5 = [7]
    expected5 = 0  # You can start at step 1 (which doesn't exist), so cost is 0
    result5 = solution.minCostClimbingStairs(cost5.copy())
    print(f"Test 5: {result5 == expected5}, Expected: {expected5}, Got: {result5}")

if __name__ == "__main__":
    test_min_cost_climbing_stairs()

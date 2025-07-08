from typing import List

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        """
        Find the cheapest price from src to dst with at most k stops using a modified Bellman-Ford algorithm.
        
        Approach:
        - Use dynamic programming (Bellman-Ford) to relax all edges up to k+1 times (since k stops = k+1 edges).
        - For each iteration, use a temporary array to avoid using updated values within the same round.
        - After k+1 rounds, prices[dst] will hold the minimum cost if reachable within k stops.
        - If unreachable, return -1.

        Time Complexity: O(k * E), where E = number of flights (edges)
            - For each of k+1 rounds, we process all flights.
        Space Complexity: O(n)
            - For the prices and temporary arrays (n = number of cities)
        """
        prices = [float("inf")] * n
        prices[src] = 0

        for i in range(k + 1):
            tmpPrices = prices.copy()  # Use a copy to prevent in-round updates

            for s, d, p in flights: # s = source, d = destination, p = price
                if prices[s] == float("inf"):
                    continue  # Skip if source is not reachable
                if prices[s] + p < tmpPrices[d]:
                    tmpPrices[d] = prices[s] + p  # Relax edge if cheaper
            
            prices = tmpPrices  # Update prices for next round

        return -1 if prices[dst] == float("inf") else int(prices[dst])


def test_find_cheapest_price():
    solution = Solution()
    # Test case 1: Simple direct flight
    n1 = 3
    flights1 = [[0, 1, 100], [1, 2, 100], [0, 2, 500]]
    src1, dst1, k1 = 0, 2, 1
    expected1 = 200
    result1 = solution.findCheapestPrice(n1, flights1, src1, dst1, k1)
    print(f"Test 1: {result1 == expected1}, Expected: {expected1}, Got: {result1}")

    # Test case 2: No path within k stops
    n2 = 3
    flights2 = [[0, 1, 100], [1, 2, 100], [0, 2, 500]]
    src2, dst2, k2 = 0, 2, 0
    expected2 = 500
    result2 = solution.findCheapestPrice(n2, flights2, src2, dst2, k2)
    print(f"Test 2: {result2 == expected2}, Expected: {expected2}, Got: {result2}")

    # Test case 3: Unreachable destination
    n3 = 4
    flights3 = [[0, 1, 100], [1, 2, 100]]
    src3, dst3, k3 = 0, 3, 1
    expected3 = -1
    result3 = solution.findCheapestPrice(n3, flights3, src3, dst3, k3)
    print(f"Test 3: {result3 == expected3}, Expected: {expected3}, Got: {result3}")

    # Test case 4: Multiple paths, must choose cheapest
    n4 = 5
    flights4 = [[0, 1, 100], [1, 2, 100], [0, 2, 500], [2, 3, 100], [3, 4, 100], [1, 4, 600]]
    src4, dst4, k4 = 0, 4, 2
    expected4 = 400
    result4 = solution.findCheapestPrice(n4, flights4, src4, dst4, k4)
    print(f"Test 4: {result4 == expected4}, Expected: {expected4}, Got: {result4}")

    # Test case 5: Zero stops, only direct flights allowed
    n5 = 3
    flights5 = [[0, 1, 100], [1, 2, 100], [0, 2, 500]]
    src5, dst5, k5 = 0, 1, 0
    expected5 = 100
    result5 = solution.findCheapestPrice(n5, flights5, src5, dst5, k5)
    print(f"Test 5: {result5 == expected5}, Expected: {expected5}, Got: {result5}")

if __name__ == "__main__":
    test_find_cheapest_price()

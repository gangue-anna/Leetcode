from typing import List
import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        """
        Simulate the process of smashing the two heaviest stones until one or none is left.
        Approach:
        - Use a max-heap (invert values for heapq) to always access the two largest stones.
        - Pop the two largest stones, smash them:
            - If they are not equal, push the difference back into the heap.
            - If equal, both are destroyed.
        - Repeat until at most one stone remains.
        - Return the last stone's weight or 0 if none remain.
        Time Complexity: O(n log n)
        Space Complexity: O(n)
        """
        stones = [-s for s in stones]
        heapq.heapify(stones)
        while len(stones) > 1:
            first = -heapq.heappop(stones)
            second = -heapq.heappop(stones)
            if first != second:
                heapq.heappush(stones, -(first - second))
        return -stones[0] if stones else 0

# -------------------
# Test Cases
# -------------------
def test_last_stone_weight():
    s = Solution()
    # Test case 1: Example
    stones = [2,7,4,1,8,1]
    assert s.lastStoneWeight(stones) == 1
    # Test case 2: All stones same
    stones = [5,5,5,5]
    assert s.lastStoneWeight(stones) == 0
    # Test case 3: Only one stone
    stones = [10]
    assert s.lastStoneWeight(stones) == 10
    # Test case 4: Two stones, different weights
    stones = [7,3]
    assert s.lastStoneWeight(stones) == 4
    # Test case 5: No stones
    stones = []
    assert s.lastStoneWeight(stones) == 0
    print("All test cases passed!")

if __name__ == "__main__":
    test_last_stone_weight()
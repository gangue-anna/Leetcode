from typing import List

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        """
        Approach:
        - Use binary search to find the minimum eating speed (k) such that Koko can finish all piles within h hours.
        - For each candidate speed k, calculate the total hours needed (using ceiling division for each pile).
        - If the total hours is less than or equal to h, try a smaller k; otherwise, try a larger k.
        - The answer is the smallest k that works.

        Time Complexity: O(n log m), where n is the number of piles and m is the max pile size (search space for k).
        Space Complexity: O(1).
        """
        l, r = 1, max(piles)
        res = r
        while l <= r:
            k = (l + r) // 2
            hours = 0
            for p in piles:
                # Using integer division for ceiling division
                hours += (p + k - 1) // k
            if hours <= h:
                res = min(res, k)
                r = k - 1
            else:
                l = k + 1
        return res

# -------------------
# Test Cases
# -------------------
def test_min_eating_speed():
    sol = Solution()
    # Test case 1: Example from Leetcode
    piles1 = [3,6,7,11]
    h1 = 8
    assert sol.minEatingSpeed(piles1, h1) == 4
    # Test case 2: Only one pile
    piles2 = [30]
    h2 = 5
    assert sol.minEatingSpeed(piles2, h2) == 6
    # Test case 3: Large h (can eat at speed 1)
    piles3 = [1,1,1,1]
    h3 = 10
    assert sol.minEatingSpeed(piles3, h3) == 1
    # Test case 4: h equals number of piles
    piles4 = [5,7,8,10]
    h4 = 4
    assert sol.minEatingSpeed(piles4, h4) == 10
    # Test case 5: All piles same size
    piles5 = [5,5,5,5]
    h5 = 4
    assert sol.minEatingSpeed(piles5, h5) == 5
    print("All test cases passed!")

if __name__ == "__main__":
    test_min_eating_speed()
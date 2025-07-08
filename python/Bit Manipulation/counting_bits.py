from typing import List

class Solution:
    def countBits(self, n: int) -> List[int]:
        """
        Approach:
        - Use dynamic programming to count the number of 1's in the binary representation for each number from 0 to n.
        - For each i, find the largest power of two less than or equal to i (offset).
        - The number of 1's in i is 1 + the number of 1's in (i - offset).
        - This works because (i - offset) removes the highest set bit from i.

        Time Complexity: O(n)
        Space Complexity: O(n)
        """
        dp = [0] * (n + 1)
        offset = 1

        for i in range(1, n + 1):
            if offset * 2 == i:
                offset = i
            dp[i] = 1 + dp[i - offset]
        return dp

# -------------------
# Test Cases
# -------------------
def test_count_bits():
    sol = Solution()
    # Test case 1: Example from Leetcode
    assert sol.countBits(2) == [0,1,1]
    # Test case 2: n = 5
    assert sol.countBits(5) == [0,1,1,2,1,2]
    # Test case 3: n = 0
    assert sol.countBits(0) == [0]
    # Test case 4: n = 1
    assert sol.countBits(1) == [0,1]
    # Test case 5: n = 10
    assert sol.countBits(10) == [0,1,1,2,1,2,2,3,1,2,2]
    print("All test cases passed!")

if __name__ == "__main__":
    test_count_bits()



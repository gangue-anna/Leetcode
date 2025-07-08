class Solution:
    def getSum(self, a: int, b: int) -> int:
        """
        Approach:
        - Use bitwise operations to add two integers without using the '+' operator.
        - sum without carry = a ^ b
        - carry = (a & b) << 1
        - Repeat the process until there is no carry.
        - Use a mask to handle 32-bit integer overflow and negative numbers in Python.

        Time Complexity: O(1) (at most 32 iterations for 32-bit integers)
        Space Complexity: O(1)
        """
        mask = 0xffffffff
        while (mask & b) > 0:
            a, b = a ^ b, (a & b) << 1
        # Handle negative numbers
        return (mask & a) if a <= 0x7fffffff else ~(mask ^ a)

# -------------------
# Test Cases
# -------------------
def test_get_sum():
    sol = Solution()
    # Test case 1: Example from Leetcode
    assert sol.getSum(1, 2) == 3
    # Test case 2: Negative and positive
    assert sol.getSum(-2, 3) == 1
    # Test case 3: Both negative
    assert sol.getSum(-1, -1) == -2
    # Test case 4: Zero
    assert sol.getSum(0, 0) == 0
    # Test case 5: Large numbers
    assert sol.getSum(123456, 654321) == 777777
    print("All test cases passed!")

if __name__ == "__main__":
    test_get_sum()

import math

class Solution:
    def reverse(self, x: int) -> int:
        """
        Approach:
        - Extract digits from the input integer one by one (using modulo and division).
        - Build the reversed number digit by digit.
        - Check for overflow/underflow before each step (32-bit signed integer range).
        - Handles negative numbers correctly.

        Time Complexity: O(log |x|), where x is the input integer (number of digits).
        Space Complexity: O(1).
        """
        MIN = -2147483648 # -2^31
        MAX = 2147483647 # 2^31 - 1
        res = 0
        while x:
            digit = int(math.fmod(x, 10)) # Handles negative numbers correctly
            x = int(x / 10)
            if (res > MAX // 10 or 
                (res == MAX // 10 and digit >= MAX % 10)):
                return 0
            if (res < MIN // 10 or 
                (res == MIN // 10 and digit <= MIN % 10)):
                return 0
            res = (res * 10) + digit
        return res

# -------------------
# Test Cases
# -------------------
def test_reverse_integer():
    sol = Solution()
    # Test case 1: Example from Leetcode
    assert sol.reverse(123) == 321
    # Test case 2: Negative number
    assert sol.reverse(-123) == -321
    # Test case 3: Ends with zero
    assert sol.reverse(120) == 21
    # Test case 4: Overflow
    assert sol.reverse(1534236469) == 0
    # Test case 5: Zero
    assert sol.reverse(0) == 0
    print("All test cases passed!")

if __name__ == "__main__":
    test_reverse_integer()
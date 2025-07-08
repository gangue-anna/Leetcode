class Solution:
    def myPow(self, x: float, n: int) -> float:
        """
        Compute x raised to the power n (x^n) using fast exponentiation.
        Approach:
        - Use recursion or iteration with exponentiation by squaring for O(log n) time.
        - Handle negative exponents by inverting x and making n positive.
        Time Complexity: O(log n)
        Space Complexity: O(1) (iterative)
        """
        if n == 0:
            return 1.0
        neg = n < 0
        n = abs(n)
        result = 1.0
        while n:
            if n % 2 == 1:
                result *= x
            x *= x
            n //= 2
        return 1.0 / result if neg else result

# -------------------
# Test Cases
# -------------------
def test_pow_x_n():
    s = Solution()
    # Test case 1: Positive exponent
    assert abs(s.myPow(2.0, 10) - 1024.0) < 1e-9
    # Test case 2: Negative exponent
    assert abs(s.myPow(2.0, -2) - 0.25) < 1e-9
    # Test case 3: Zero exponent
    assert abs(s.myPow(2.0, 0) - 1.0) < 1e-9
    # Test case 4: x = 0
    assert abs(s.myPow(0.0, 5) - 0.0) < 1e-9
    # Test case 5: n = 1
    assert abs(s.myPow(3.5, 1) - 3.5) < 1e-9
    # Test case 6: n = -1
    assert abs(s.myPow(3.5, -1) - (1/3.5)) < 1e-9
    # Test case 7: Large exponent
    assert abs(s.myPow(1.00001, 123456) - pow(1.00001, 123456)) < 1e-5
    print("All test cases passed!")

if __name__ == "__main__":
    test_pow_x_n()
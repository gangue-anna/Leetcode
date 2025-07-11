class Solution:
    def myPow(self, x: float, n: int) -> float:
        """
        Compute x raised to the power n (x^n) using fast exponentiation (iterative).
        
        Approach:
        - Use exponentiation by squaring to reduce the number of multiplications.
        - If n is negative, invert x and use the absolute value of n.
        - Multiply result by x when n is odd, otherwise square x and halve n.
        
        Time Complexity: O(log n)
        - Each step halves n, so the number of steps is proportional to log n.
        
        Space Complexity: O(1)
        - Only a constant amount of extra space is used (iterative version).
        
        Args:
            x: float - the base
            n: int - the exponent
        Returns:
            float - the result of x raised to the power n
        """
        if n == 0:
            return 1.0
        neg = n < 0
        n = abs(n)
        result = 1.0
        while n:
            if n % 2 == 1:
                result *= x  # Multiply result by x if n is odd
            x *= x          # Square x
            n //= 2         # Halve n
        return 1.0 / result if neg else result

class Solution2:
    def myPow(self, x: float, n: int) -> float:
        """
        Compute x raised to the power n (x^n) using fast exponentiation (recursive).
        
        Approach:
        - Use recursion with exponentiation by squaring.
        - If n is negative, invert x and use the absolute value of n.
        - Base cases: x^0 = 1, x^1 = x, 0^n = 0 for n > 0
        - For even n, recursively compute (x*x)^(n//2)
        - For odd n, multiply x by the result of the even case
        
        Time Complexity: O(log n)
        - Each recursive call halves n.
        
        Space Complexity: O(log n)
        - Due to recursion stack.
        
        Args:
            x: float - the base
            n: int - the exponent
        Returns:
            float - the result of x raised to the power n
        """
        def helper(x, n):
            if x == 0:
                return 0
            if n == 0:
                return 1
            res = helper(x * x, n // 2)
            return x * res if n % 2 else res
        res = helper(x, abs(n))
        return res if n >= 0 else 1 / res

# -------------------
# Test Cases
# -------------------
def test_pow_x_n():
    s = Solution()
    s2 = Solution2()
    def check_all(method):
        # Test case 1: Positive exponent
        assert abs(method(2.0, 10) - 1024.0) < 1e-9, "Failed on (2.0, 10)"
        # Test case 2: Negative exponent
        assert abs(method(2.0, -2) - 0.25) < 1e-9, "Failed on (2.0, -2)"
        # Test case 3: Zero exponent
        assert abs(method(2.0, 0) - 1.0) < 1e-9, "Failed on (2.0, 0)"
        # Test case 4: x = 0, n > 0
        assert abs(method(0.0, 5) - 0.0) < 1e-9, "Failed on (0.0, 5)"
        # Test case 5: n = 1
        assert abs(method(3.5, 1) - 3.5) < 1e-9, "Failed on (3.5, 1)"
        # Test case 6: n = -1
        assert abs(method(3.5, -1) - (1/3.5)) < 1e-9, "Failed on (3.5, -1)"
        # Test case 7: Large exponent
        assert abs(method(1.00001, 123456) - pow(1.00001, 123456)) < 1e-5, "Failed on (1.00001, 123456)"
    check_all(s.myPow)
    check_all(s2.myPow)
    print("All test cases passed for both Solution and Solution2!")

if __name__ == "__main__":
    test_pow_x_n()
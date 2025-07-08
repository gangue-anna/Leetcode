class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        """
        Multiply two non-negative integers represented as strings.
        Approach:
        - Convert each character to its integer value.
        - Build the integer values for num1 and num2.
        - Multiply the two integers and return the result as a string.
        Time Complexity: O(n + m), where n and m are the lengths of num1 and num2
        Space Complexity: O(1) (ignoring input/output string sizes)
        """
        def helper(c):
            return ord(c) - ord('0')
        n1 = 0
        for ch in num1:
            n1 = n1 * 10 + helper(ch)
        n2 = 0
        for ch in num2:
            n2 = n2 * 10 + helper(ch)
        return str(n1 * n2)

# -------------------
# Test Cases
# -------------------
def test_multiply_strings():
    s = Solution()
    # Test case 1: Basic
    assert s.multiply("2", "3") == "6"
    # Test case 2: Larger numbers
    assert s.multiply("123", "456") == "56088"
    # Test case 3: One number is zero
    assert s.multiply("0", "12345") == "0"
    assert s.multiply("12345", "0") == "0"
    # Test case 4: Both numbers are zero
    assert s.multiply("0", "0") == "0"
    # Test case 5: Single digit
    assert s.multiply("9", "9") == "81"
    # Test case 6: Different lengths
    assert s.multiply("12", "3456") == "41472"
    # Test case 7: Very large numbers
    a = "987654321"
    b = "123456789"
    assert s.multiply(a, b) == str(int(a) * int(b))
    print("All test cases passed!")

if __name__ == "__main__":
    test_multiply_strings()
            

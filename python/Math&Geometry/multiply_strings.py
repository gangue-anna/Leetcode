class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        """
        Multiply two non-negative integers represented as strings.
        
        Approach:
        - Convert each character to its integer value using ASCII math.
        - Build the integer values for num1 and num2 by iterating through the strings.
        - Multiply the two integers and return the result as a string.
        
        Time Complexity: O(n + m), where n and m are the lengths of num1 and num2
        - We iterate through both strings once to build the numbers
        - Multiplication of two integers of length n and m is O(n + m) in Python (arbitrary precision)
        
        Space Complexity: O(1) (ignoring input/output string sizes)
        - Only a constant amount of extra space is used for computation
        - The result string is required by the problem
        
        Args:
            num1: str - first non-negative integer as a string
            num2: str - second non-negative integer as a string
        Returns:
            str - the product as a string
        """
        def helper(c):
            return ord(c) - ord('0')
        n1 = 0
        for ch in num1:
            n1 = n1 * 10 + helper(ch)  # Build integer from string
        n2 = 0
        for ch in num2:
            n2 = n2 * 10 + helper(ch)  # Build integer from string
        return str(n1 * n2)

class Solution2:
    def multiply(self, num1: str, num2: str) -> str:
        """
        Multiply two non-negative integers represented as strings using manual digit-by-digit multiplication (like on paper).
        
        Approach:
        - Reverse both strings to simplify position handling (least significant digit first)
        - Use an array to store intermediate results for each digit multiplication
        - For each digit in num1 and num2, multiply and add to the correct position in the result array
        - Handle carry for each position
        - Remove leading zeros and convert the result array back to a string
        
        Time Complexity: O(n * m), where n and m are the lengths of num1 and num2
        - We multiply every digit in num1 by every digit in num2
        
        Space Complexity: O(n + m)
        - The result array can be at most n + m digits
        
        Args:
            num1: str - first non-negative integer as a string
            num2: str - second non-negative integer as a string
        Returns:
            str - the product as a string
        """
        if "0" in [num1, num2]:
            return "0"

        res = [0] * (len(num1) + len(num2))
        num1, num2 = num1[:: -1], num2[:: -1]

        for i1 in range(len(num1)):
            for i2 in range(len(num2)):
                digit = int(num1[i1]) * int(num2[i2])
                
                res[i1 + i2] += digit
                res[i1 + i2 + 1] += (res[i1 + i2] // 10)  # Carry to next position
                res[i1 + i2] = res[i1 + i2] % 10           # Remainder stays

        res, beg = res[:: -1], 0
        while beg < len(res) and res[beg] == 0:
            beg += 1

        res = map(str, res[beg: ]) 
        return "".join(res)
        
# -------------------
# Test Cases
# -------------------
def test_multiply_strings():
    s = Solution()
    s2 = Solution2()
    def check_all(method):
        # Test case 1: Basic
        assert method("2", "3") == "6", "Failed on ('2', '3')"
        # Test case 2: Larger numbers
        assert method("123", "456") == "56088", "Failed on ('123', '456')"
        # Test case 3: One number is zero
        assert method("0", "12345") == "0", "Failed on ('0', '12345')"
        assert method("12345", "0") == "0", "Failed on ('12345', '0')"
        # Test case 4: Both numbers are zero
        assert method("0", "0") == "0", "Failed on ('0', '0')"
        # Test case 5: Single digit
        assert method("9", "9") == "81", "Failed on ('9', '9')"
        # Test case 6: Different lengths
        assert method("12", "3456") == "41472", "Failed on ('12', '3456')"
        # Test case 7: Very large numbers
        a = "987654321"
        b = "123456789"
        assert method(a, b) == str(int(a) * int(b)), "Failed on very large numbers"
        # Test case 8: One is one
        assert method("1", "99999") == "99999", "Failed on ('1', '99999')"
        assert method("99999", "1") == "99999", "Failed on ('99999', '1')"
        # Test case 9: Both single digit
        assert method("7", "8") == "56", "Failed on ('7', '8')"
    check_all(s.multiply)
    check_all(s2.multiply)
    print("All test cases passed for both Solution and Solution2!")

if __name__ == "__main__":
    test_multiply_strings()
            

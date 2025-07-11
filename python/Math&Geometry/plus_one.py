from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        """
        Add one to a number represented as a list of digits.
        
        Approach:
        - Convert the list of digits to an integer by iterating through the list and building the number.
        - Add one to the integer.
        - Convert the result back to a list of digits by converting to string and mapping back to integers.
        
        Time Complexity: O(n), where n is the number of digits
        - We iterate through the digits to build the number and again to convert back to a list
        
        Space Complexity: O(n)
        - The result list and string conversion use O(n) space
        
        Args:
            digits: List[int] - The input number as a list of digits
        Returns:
            List[int] - The incremented number as a list of digits
        """
        num = 0
        size = len(digits)
        for i in range(size):
            num += digits[i] * (10 ** (size - i - 1))  # Build the integer from digits
        num = num + 1
        res = list(map(int, str(num)))  # Convert back to list of digits
        return res

class Solution2:
    def plusOne(self, digits: List[int]) -> List[int]:
        """
        Add one to a number represented as a list of digits, handling carry without converting to integer.
        
        Approach:
        - Reverse the digits to process from least significant digit
        - Add one and handle carry as needed
        - If carry remains after processing all digits, append 1
        - Reverse the result to restore original order
        
        Time Complexity: O(n)
        Space Complexity: O(n)
        """
        digits = digits[:: -1]  # Reverse the digits
        carry, i = 1, 0
        while carry:
            if i < len(digits):
                if digits[i] == 9:
                    digits[i] = 0
                else:
                    digits[i] += 1
                    carry = 0
            else:
                digits.append(1)
                carry = 0
            i += 1
        return digits[:: -1]  # Reverse back to original order

# -------------------
# Test Cases
# -------------------
def test_plus_one():
    s = Solution()
    s2 = Solution2()
    def check_all(method):
        # Test case 1: Basic
        assert method([1,2,3]) == [1,2,4], f"Failed on [1,2,3]"
        # Test case 2: Carry over
        assert method([9]) == [1,0], f"Failed on [9]"
        # Test case 3: Multiple carry overs
        assert method([9,9,9]) == [1,0,0,0], f"Failed on [9,9,9]"
        # Test case 4: Zero
        assert method([0]) == [1], f"Failed on [0]"
        # Test case 5: Large number
        assert method([4,3,2,1]) == [4,3,2,2], f"Failed on [4,3,2,1]"
        # Test case 6: All nines
        assert method([9,9]) == [1,0,0], f"Failed on [9,9]"
        # Test case 8: Single digit not nine
        assert method([5]) == [6], f"Failed on [5]"
        # Test case 9: Two digits, last is nine
        assert method([2,9]) == [3,0], f"Failed on [2,9]"
        # Test case 10: Very large input
        big = [9]*1000
        expected = [1]+[0]*1000
        assert method(big) == expected, f"Failed on 1000 nines"
    check_all(s.plusOne)
    check_all(s2.plusOne)
    print("All test cases passed for both Solution and Solution2!")

if __name__ == "__main__":
    test_plus_one()
        

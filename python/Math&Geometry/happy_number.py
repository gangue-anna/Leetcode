class Solution:
    def isHappy(self, n: int) -> bool:
        """
        Determine if a number is a happy number.
        
        Approach:
        1. Use a set to keep track of numbers we've seen to detect cycles
        2. Repeatedly replace the number with the sum of the squares of its digits
        3. If we reach 1, the number is happy
        4. If we see a number we've seen before, there's a cycle and the number is not happy
        
        Time Complexity: O(log n)
        - Each sum of squares operation reduces the number of digits
        - The process converges quickly to 1 or a cycle
        - In practice, the number of unique numbers seen is small (bounded by 243 for base 10)
        
        Space Complexity: O(log n)
        - The set stores previously seen numbers (at most a small constant number)
        
        Args:
            n: Integer to check for happiness
        Returns:
            True if n is a happy number, False otherwise
        """
        visit = set()

        while n not in visit:
            visit.add(n)
            n = self.sumOfSquares(n)

            if n == 1:
                return True

        return False

    def sumOfSquares(self, n : int) -> int:
        """
        Helper function to compute the sum of the squares of the digits of n
        """
        output = 0
        
        while n:
            digit = n % 10
            digit = digit ** 2
            output += digit
            n = n // 10
        return output


def test_happy_number():
    """Test cases for the happy number function"""
    
    # Test Case 1: Happy number (19)
    n1 = 19
    result1 = Solution().isHappy(n1)
    expected1 = True
    print(f"Test 1 - Input: {n1}, Output: {result1}, Expected: {expected1}, Passed: {result1 == expected1}")
    
    # Test Case 2: Not a happy number (2)
    n2 = 2
    result2 = Solution().isHappy(n2)
    expected2 = False
    print(f"Test 2 - Input: {n2}, Output: {result2}, Expected: {expected2}, Passed: {result2 == expected2}")
    
    # Test Case 3: Happy number (1)
    n3 = 1
    result3 = Solution().isHappy(n3)
    expected3 = True
    print(f"Test 3 - Input: {n3}, Output: {result3}, Expected: {expected3}, Passed: {result3 == expected3}")
    
    # Test Case 4: Not a happy number (4)
    n4 = 4
    result4 = Solution().isHappy(n4)
    expected4 = False
    print(f"Test 4 - Input: {n4}, Output: {result4}, Expected: {expected4}, Passed: {result4 == expected4}")
    
    # Test Case 5: Large happy number (100)
    n5 = 100
    result5 = Solution().isHappy(n5)
    expected5 = True
    print(f"Test 5 - Input: {n5}, Output: {result5}, Expected: {expected5}, Passed: {result5 == expected5}")
    
    # Test Case 6: Large happy number (1111111)
    n6 = 1111111
    result6 = Solution().isHappy(n6)
    expected6 = True
    print(f"Test 6 - Input: {n6}, Output: {result6}, Expected: {expected6}, Passed: {result6 == expected6}")
    
    # Test Case 7: Edge case (0)
    n7 = 0
    result7 = Solution().isHappy(n7)
    expected7 = False
    print(f"Test 7 - Input: {n7}, Output: {result7}, Expected: {expected7}, Passed: {result7 == expected7}")


if __name__ == "__main__":
    test_happy_number()


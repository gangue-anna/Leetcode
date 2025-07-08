from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        """
        Add one to a number represented as a list of digits.
        Approach:
        - Convert the list of digits to an integer.
        - Add one.
        - Convert the result back to a list of digits.
        Time Complexity: O(n)
        Space Complexity: O(n)
        """
        num = 0
        size = len(digits)
        for i in range(size):
            num += digits[i] * (10 ** (size - i - 1))  # Fix: exponent should be (size - i - 1)
        num = num + 1
        res = list(map(int, str(num)))
        return res

# -------------------
# Test Cases
# -------------------
def test_plus_one():
    s = Solution()
    # Test case 1: Basic
    assert s.plusOne([1,2,3]) == [1,2,4]
    # Test case 2: Carry over
    assert s.plusOne([9]) == [1,0]
    # Test case 3: Multiple carry overs
    assert s.plusOne([9,9,9]) == [1,0,0,0]
    # Test case 4: Zero
    assert s.plusOne([0]) == [1]
    # Test case 5: Large number
    assert s.plusOne([4,3,2,1]) == [4,3,2,2]
    # Test case 6: All nines
    assert s.plusOne([9,9]) == [1,0,0]
    print("All test cases passed!")

if __name__ == "__main__":
    test_plus_one()
        

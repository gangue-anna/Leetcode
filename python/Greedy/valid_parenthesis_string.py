class Solution:
    def checkValidString(self, s: str) -> bool:
        """
        Check if a string with parentheses and asterisks (*) can be made valid.
        '*' can be treated as '(', ')', or empty string.
        
        Approach:
        - Use two variables to track the minimum and maximum number of unmatched left parentheses.
        - For each character:
          - '(': increment both min and max
          - ')': decrement both min and max
          - '*': can be '(', ')', or empty, so min-1 and max+1
        - If max becomes negative, return False (too many closing parentheses).
        - If min becomes negative, reset it to 0 (we can't have negative unmatched parentheses).
        - At the end, check if min is 0 (all parentheses can be balanced).
        
        Time Complexity: O(N), where N is the length of the string
        - We iterate through the string once
        
        Space Complexity: O(1)
        - Only a constant amount of extra space is used
        
        Args:
            s: str - String containing '(', ')', and '*'
        Returns:
            bool - True if the string can be made valid, False otherwise
        """
        leftMin, leftMax = 0, 0

        for c in s:
            if c == "(":
                leftMin, leftMax = leftMin + 1, leftMax + 1
            elif c == ')':
                leftMin, leftMax = leftMin - 1, leftMax - 1
            else:  # c == '*'
                leftMin, leftMax = leftMin - 1, leftMax + 1
            if leftMax < 0:
                return False
            if leftMin < 0:
                leftMin = 0

        return leftMin == 0

# -------------------
# Test Cases
# -------------------
def test_check_valid_string():
    s = Solution()
    # Test case 1: Valid string
    assert s.checkValidString("()") == True, "Failed on '()'"
    # Test case 2: Valid with asterisks
    assert s.checkValidString("(*)") == True, "Failed on '(*)'"
    # Test case 3: Valid with multiple asterisks
    assert s.checkValidString("(*))") == True, "Failed on '(*))'"
    # Test case 4: Invalid string
    assert s.checkValidString("((()") == False, "Failed on '((()'"
    # Test case 5: Invalid with asterisks
    assert s.checkValidString("((*)))") == True, "Failed on '((*)))'"
    # Test case 6: Empty string
    assert s.checkValidString("") == True, "Failed on empty string"
    # Test case 7: Only asterisks
    assert s.checkValidString("***") == True, "Failed on '***'"
    # Test case 8: Complex case
    assert s.checkValidString("((*))") == True, "Failed on '((*))'"
    print("All test cases passed!")

if __name__ == "__main__":
    test_check_valid_string() 
class Solution:
    def isValid(self, s: str) -> bool:
        """
        Check if the input string of parentheses is valid.
        Approach:
        - Use a stack to track opening brackets.
        - For each closing bracket, check if it matches the top of the stack.
        - If stack is empty at the end, the string is valid.
        Time Complexity: O(n)
        Space Complexity: O(n)
        """
        stack = []
        closeToOpen = {")" : "(", "}" : "{", "]" : "["}

        for c in s:
            if c in closeToOpen:
                if stack and stack[-1] == closeToOpen[c]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)
        return True if not stack else False

# -------------------
# Test Cases
# -------------------
def test_valid_parentheses():
    s = Solution()
    # Test case 1: Basic valid
    assert s.isValid("()") == True
    assert s.isValid("()[]{}") == True
    # Test case 2: Invalid
    assert s.isValid("(]") == False
    assert s.isValid("([)]") == False
    # Test case 3: Empty string
    assert s.isValid("") == True
    # Test case 4: Only opening
    assert s.isValid("(((((") == False
    # Test case 5: Only closing
    assert s.isValid("]]]]") == False
    # Test case 6: Nested valid
    assert s.isValid("({[]})") == True
    # Test case 7: Single character
    assert s.isValid("(") == False
    assert s.isValid(")") == False
    print("All test cases passed!")

if __name__ == "__main__":
    test_valid_parentheses()
    
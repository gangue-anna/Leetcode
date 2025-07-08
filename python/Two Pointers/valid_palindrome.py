class Solution:
    def isPalindrome(self, s: str) -> bool:
        """
        Check if a string is a palindrome, considering only alphanumeric characters and ignoring cases.
        Time Complexity: O(n)
        Space Complexity: O(1)
        """
        # Initialize two pointers: left at start, right at end
        l, r = 0, len(s) - 1
        
        # Continue until pointers meet in the middle
        while l < r:
            # Skip non-alphanumeric characters from left
            while l < r and not self.alphaNum(s[l]):
                l += 1
            # Skip non-alphanumeric characters from right
            while r > l and not self.alphaNum(s[r]):
                r -= 1

            # Compare characters (case-insensitive)
            if s[l].lower() != s[r].lower():
                return False
            # Move pointers towards center
            l, r = l + 1, r - 1
        return True    

    def alphaNum(self, c):
        # Check if character is alphanumeric using ASCII values
        return ((ord("A") <= ord(c) <= ord("Z")) or  # Uppercase letters
                (ord("0") <= ord(c) <= ord("9")) or  # Numbers
                (ord("a") <= ord(c) <= ord("z")))    # Lowercase letters

# -------------------
# Test Cases
# -------------------
def test_is_palindrome():
    s = Solution()
    # Test case 1: Example
    assert s.isPalindrome("A man, a plan, a canal: Panama") == True
    # Test case 2: Not a palindrome
    assert s.isPalindrome("race a car") == False
    # Test case 3: Empty string
    assert s.isPalindrome("") == True
    # Test case 4: Only non-alphanumeric
    assert s.isPalindrome("!!!") == True
    # Test case 5: Single character
    assert s.isPalindrome("a") == True
    # Test case 6: Numbers
    assert s.isPalindrome("12321") == True
    assert s.isPalindrome("1231") == False
    # Test case 7: Mixed case
    assert s.isPalindrome("AbBa") == True
    print("All test cases passed!")

if __name__ == "__main__":
    test_is_palindrome()
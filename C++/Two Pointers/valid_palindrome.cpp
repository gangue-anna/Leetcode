#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Check if string is palindrome (alphanumeric chars only, case insensitive)
     * 
     * Approach:
     * - Two pointers: left at start, right at end
     * - Skip non-alphanumeric characters
     * - Compare characters case-insensitively
     * - Move towards center
     * 
     * Time: O(n) - single pass through string
     * Space: O(1) - only two pointers used
     */
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric from left
            while (left < right && !isAlphaNum(s[left])) {
                left++;
            }
            
            // Skip non-alphanumeric from right
            while (right > left && !isAlphaNum(s[right])) {
                right--;
            }
            
            // Compare characters case-insensitively
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        return true;
    }

private:
    bool isAlphaNum(char c) {
        return (isdigit(c) || isalpha(c));
    }
};

/*
 * Detailed C++ Syntax Explanation:
 * 
 * 1. String Operations:
 *    s.length()      // Get string length
 *    s[left]         // Access character at index
 *    tolower(c)      // Convert char to lowercase
 * 
 * 2. Character Functions:
 *    isdigit(c)      // Check if char is digit (0-9)
 *    isalpha(c)      // Check if char is letter (a-z,A-Z)
 * 
 * 3. Pointers/Indices:
 *    int left = 0    // Start of string
 *    int right = s.length() - 1  // End of string
 * 
 * 4. While Loop:
 *    while (left < right)  // Continue until pointers meet
 * 
 * 5. Private Helper:
 *    bool isAlphaNum(char c)  // Class member function
 *    - Returns true if c is letter or digit
 * 
 * Note: This implementation:
 * - Uses C++ standard library functions instead of ASCII values
 * - Has same O(n) time complexity as Python version
 * - Maintains O(1) space complexity
 */

#include <bits/stdc++.h>        
using namespace std;

class Solution {
public:
    /*
     * Problem: Find longest substring where k character replacements make all chars same
     * 
     * Approach:
     * - Use sliding window with character frequency map
     * - Track maximum frequency in current window
     * - If (window size - max frequency) > k, shrink window
     * - Update result with valid window sizes
     * 
     * Time: O(n) - single pass through string
     * Space: O(1) - array of size 26 for uppercase letters
     */
    int characterReplacement(string s, int k) {
        // Array to count frequencies (for uppercase letters A-Z)
        vector<int> count(26, 0);
        int result = 0;
        int left = 0;
        int maxFreq = 0;
        
        // Expand window with right pointer
        for (int right = 0; right < s.length(); right++) {
            // Update frequency of current character
            count[s[right] - 'A']++;
            // Update maximum frequency in current window
            maxFreq = max(maxFreq, count[s[right] - 'A']);
            
            // If window invalid (too many replacements needed)
            while ((right - left + 1) - maxFreq > k) {
                // Decrease frequency of leftmost char
                count[s[left] - 'A']--;
                left++;
            }
            
            // Update result with current valid window size
            result = max(result, right - left + 1);
        }
        
        return result;
    }
};

/*
 * Detailed C++ Syntax Explanation for Beginners:
 * 
 * 1. Vector Initialization:
 *    vector<int> count(26, 0)  // Size 26 array filled with zeros
 *    - Used instead of Python dictionary
 *    - Index 0-25 represents A-Z
 * 
 * 2. Character to Index:
 *    s[right] - 'A'    // Convert char to 0-25 index
 *    - 'A' is ASCII 65, so 'A'-'A'=0, 'B'-'A'=1, etc.
 * 
 * 3. String Operations:
 *    s.length()        // Get string length
 *    s[index]          // Access character at position
 * 
 * 4. Window Size:
 *    right - left + 1  // Current window size
 *    - +1 because positions are zero-based
 * 
 * 5. Standard Library:
 *    max(a, b)         // Returns larger of two values
 * 
 * 6. Variables:
 *    maxFreq           // Most frequent char count
 *    result           // Longest valid substring
 * 
 * Note: This implementation:
 * - Uses array instead of hashmap for O(1) space
 * - Maintains O(n) time complexity
 * - Handles uppercase English letters only
 */

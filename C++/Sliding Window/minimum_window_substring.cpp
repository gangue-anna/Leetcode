#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Find minimum window in s containing all characters from t
     * 
     * Approach:
     * - Use sliding window with character frequency maps
     * - Expand window until all needed chars found
     * - Contract window to minimize while maintaining chars
     * - Track minimum valid window found
     * 
     * Time: O(n) where n is length of s
     * Space: O(k) where k is unique chars in t
     */
    string minWindow(string s, string t) {
        // Edge case: empty target string
        if (t.empty()) return "";
        
        // Initialize frequency maps
        unordered_map<char, int> countT, window;
        
        // Count frequencies in t
        for (char c : t) {
            countT[c]++;
        }
        
        // Track window stats
        int have = 0;              // Chars with required frequency
        int need = countT.size();  // Unique chars needed
        int left = 0;              // Left pointer
        int minLen = INT_MAX;      // Length of minimum window
        int resultStart = 0;       // Start of minimum window
        
        // Slide window
        for (int right = 0; right < s.length(); right++) {
            // Add right char to window
            char c = s[right];
            window[c]++;
            
            // Check if current char matches required frequency
            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }
            
            // Try to minimize window
            while (have == need) {
                // Update result if current window smaller
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    resultStart = left;
                }
                
                // Remove leftmost char from window
                char leftChar = s[left];
                window[leftChar]--;
                
                if (countT.count(leftChar) && 
                    window[leftChar] < countT[leftChar]) {
                    have--;
                }
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(resultStart, minLen);
    }
};

/*
 * Detailed C++ Syntax Explanation for Beginners:
 * 
 * 1. Hash Map Operations:
 *    unordered_map<char, int>  // Hash map declaration
 *    map[key]++               // Increment count for key
 *    map.count(key)          // Check if key exists
 *    map.size()              // Number of unique keys
 * 
 * 2. String Operations:
 *    s.empty()               // Check if string empty
 *    s.length()              // Get string length
 *    s.substr(pos, len)      // Get substring
 * 
 * 3. Integer Limits:
 *    INT_MAX                 // Maximum integer value
 * 
 * 4. Window Variables:
 *    have                    // Current matching chars
 *    need                    // Required matching chars
 *    minLen                  // Smallest valid window
 * 
 * 5. Result Handling:
 *    ternary operator ? :    // Conditional return
 * 
 * Note: This implementation:
 * - Uses hash maps for O(1) lookups
 * - Maintains O(n) time complexity
 * - Uses O(k) space for frequency maps
 */

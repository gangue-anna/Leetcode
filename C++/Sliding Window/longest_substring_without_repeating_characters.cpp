#include <bits/stdc++.h>
using namespace std;   

class Solution {
public:
    /*
     * Problem: Find longest substring without repeating characters
     * 
     * Approach 1: String Manipulation
     * - Build substring by adding characters
     * - If character exists, truncate string after its first occurrence
     * - Track maximum length seen
     * 
     * Time: O(n^2) - string operations are costly
     * Space: O(n) - for storing substring
     */
    int lengthOfLongestSubstring(string s) {
        string subStr = "";
        int maxSize = 0;
        
        for (char c : s) {
            // Find position of character in current substring
            size_t pos = subStr.find(c);
            
            if (pos == string::npos) {
                // Character not found, append it
                subStr += c;
            }
            else {
                // Character found, truncate string and append
                subStr = subStr.substr(pos + 1) + c;
            }
            
            maxSize = max(maxSize, (int)subStr.length());
        }
        
        return maxSize;
    }
};

class Solution2 {
public:
    /*
     * Problem: Find longest substring without repeating characters
     * 
     * Approach 2: Sliding Window with Set
     * - Use set to track characters in current window
     * - Move right pointer, adding characters
     * - If duplicate found, remove from left until unique
     * - Track maximum window size
     * 
     * Time: O(n) - single pass through string
     * Space: O(min(m,n)) where m is charset size
     */
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0;
        int result = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // Remove characters from left while current char exists
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            
            // Add current character to set
            charSet.insert(s[right]);
            
            // Update maximum length
            result = max(result, right - left + 1);
        }
        
        return result;
    }
};

/*
 * Detailed C++ Syntax Explanation for Beginners:
 * 
 * 1. String Operations:
 *    string subStr = ""    // Empty string initialization
 *    subStr.find(c)        // Find character in string
 *    string::npos          // Returned when character not found
 *    subStr.substr(pos)    // Get substring from position
 *    subStr += c           // Append character to string
 * 
 * 2. Set Operations:
 *    unordered_set<char>   // Hash set for characters
 *    set.find(c)          // Look for character in set
 *    set.end()            // Iterator to end of set
 *    set.insert(c)        // Add character to set
 *    set.erase(c)         // Remove character from set
 * 
 * 3. Type Conversions:
 *    (int)subStr.length() // Convert size_t to int
 * 
 * 4. Standard Library:
 *    max(a, b)            // Returns larger of two values
 * 
 * 5. For Loop Types:
 *    for (char c : s)     // Range-based for string
 *    for (int i = 0; ...) // Traditional indexed loop
 * 
 * Note: Solution2 is more efficient because:
 * - Uses O(n) time complexity
 * - Avoids expensive string operations
 * - Uses hash set for O(1) lookups
 */

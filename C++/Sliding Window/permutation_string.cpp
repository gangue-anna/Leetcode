#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Check if s2 contains any permutation of s1
     * 
     * Approach:
     * - Use sliding window with character frequency arrays
     * - Compare window frequencies with s1 frequencies
     * - Slide window and update frequencies
     * 
     * Time: O(n) where n is length of s2
     * Space: O(1) - fixed size arrays for char counts
     */
    bool checkInclusion(string s1, string s2) {
        // Early return if s1 is longer than s2
        if (s1.length() > s2.length()) return false;
        
        // Initialize frequency arrays for lowercase letters
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);
        
        // Count frequencies for first window
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }
        
        // Check first window
        if (s1Count == s2Count) return true;
        
        // Slide window and check each position
        for (int i = s1.length(); i < s2.length(); i++) {
            // Add new character to window
            s2Count[s2[i] - 'a']++;
            
            // Remove character that's no longer in window
            s2Count[s2[i - s1.length()] - 'a']--;
            
            // Check if current window matches
            if (s1Count == s2Count) return true;
        }
        
        return false;
    }
};

/*
 * Detailed C++ Syntax Explanation for Beginners:
 * 
 * 1. Vector Operations:
 *    vector<int> s1Count(26, 0)  // Create array of 26 zeros
 *    s1Count == s2Count          // Compare entire arrays
 * 
 * 2. String Operations:
 *    s1.length()                 // Get string length
 *    s2[i]                       // Access character at index
 * 
 * 3. Character to Index:
 *    s1[i] - 'a'                // Convert char to 0-25 index
 *    - 'a' is ASCII 97, so 'a'-'a'=0, 'b'-'a'=1, etc.
 * 
 * 4. Window Operations:
 *    i - s1.length()            // Get start of window
 *    s2Count[char]++            // Add char to window
 *    s2Count[char]--            // Remove char from window
 * 
 * 5. Return Values:
 *    return true/false          // Boolean result
 * 
 * Key Differences from Python:
 * - Uses fixed arrays instead of dictionaries
 * - Direct character-to-index mapping
 * - No need to handle zero counts (array maintains zeros)
 * - Vector comparison instead of dictionary comparison
 */

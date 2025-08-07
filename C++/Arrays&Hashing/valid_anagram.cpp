#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Check if two strings are anagrams
     * Two strings are anagrams if they have same characters with same frequencies
     * 
     * Approach:
     * 1. First check if strings have same length (if not, can't be anagrams)
     * 2. Use hash map to track character frequencies:
     *    - Increment count for chars in string s
     *    - Decrement count for chars in string t
     * 3. If strings are anagrams, all counts should be zero
     * 
     * Time Complexity: O(n) where n is length of strings
     * - Initial length check: O(1)
     * - Single pass through both strings: O(n)
     * - Final verification of counts: O(k) where k is unique chars
     * - HashMap operations (insert/lookup) are O(1) average case
     * 
     * Space Complexity: O(k) where k is number of unique characters
     * - HashMap stores at most k character-count pairs
     * - For lowercase English letters, k ≤ 26, so effectively O(1)
     */
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        unordered_map<char, int> charCount;
        
        for (int i = 0; i < s.size(); i++) {
            charCount[s[i]]++;
            charCount[t[i]]--;
        }
        
        for (const auto& pair : charCount) {
            if (pair.second != 0) {
                return false;
            }
        }
        return true;  // Add this line to return true when strings are anagrams
    }
};

/*
 * Detailed C++ Syntax Explanation for Beginners:
 * 
 * 1. Headers and Namespace:
 *    #include <bits/stdc++.h>   // Includes all standard libraries
 *    using namespace std;       // Makes std:: prefix optional
 * 
 * 2. Class Structure:
 *    class Solution {          // Defines a class named Solution
 *    public:                   // Makes members accessible from outside
 * 
 * 3. Function Declaration:
 *    bool                     // Return type (true/false)
 *    isAnagram(               // Function name
 *        string s,           // First string parameter
 *        string t)           // Second string parameter
 * 
 * 4. Size Check:
 *    s.size()                // Returns length of string
 *    if (s.size() != t.size()) // Compare lengths
 * 
 * 5. HashMap Declaration:
 *    unordered_map<char, int> // Key: character, Value: count
 *    charCount                // Variable name
 * 
 * 6. Character Counting:
 *    charCount[s[i]]++       // Increment count for char in s
 *    charCount[t[i]]--       // Decrement count for char in t
 * 
 * 7. Range-based For Loop:
 *    for (const auto& pair : charCount)
 *    - const: makes pair read-only
 *    - auto: automatic type deduction
 *    - &: reference to avoid copying
 *    - pair: current key-value pair
 *    - charCount: container being iterated
 * 
 * 8. Map Access:
 *    pair.second              // Accesses the count (value)
 *    pair.first              // Would access the character (key)
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count1(26), count2(26);

        if(s.size() != t.size()){
            return false;
        }
        
        for(int i = 0; i < s.size(); i++){
            count1[s[i] - 'a']++;
        }
        for(int i = 0; i < s.size(); i++){
            count2[t[i] - 'a']++;
        }
        for(int i = 0; i<26;i++){
            if (count1[i] != count2[i]){
                return false;
                break;
            }
        }
        return true;
    }
};

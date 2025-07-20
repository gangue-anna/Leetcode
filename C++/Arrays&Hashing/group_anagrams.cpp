#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Group Anagrams
     * 
     * Approach:
     * - Create unique key for each anagram group using character counts
     * - Use hash map to group strings with same character frequency
     * - For each string:
     *   1. Count frequency of each character (a-z)
     *   2. Create key from count array
     *   3. Add string to corresponding group
     * 
     * Time Complexity: O(n * k)
     * - n = number of strings
     * - k = maximum length of a string
     * - For each string, we count k characters
     * - Creating key takes O(1) as count array is fixed size (26)
     * 
     * Space Complexity: O(n * k)
     * - Storing all strings in hash map
     * - Each string appears exactly once
     */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (const string& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            
            string key;
            for (int n : count) {
                key += to_string(n) + "#";
            }
            
            groups[key].push_back(s);
        }
        
        vector<vector<string>> result;
        for (const auto& pair : groups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};

/*
 * Detailed Syntax Explanation:
 * 
 * 1. Function Declaration:
 *    vector<vector<string>> groupAnagrams(vector<string>& strs)
 *    - Returns nested vector of strings (groups of anagrams)
 *    - Takes reference to vector of strings as input
 *    - & prevents copying of input vector
 * 
 * 2. HashMap Declaration:
 *    unordered_map<string, vector<string>> groups
 *    - Key: string (character frequency signature)
 *    - Value: vector of strings (anagram group)
 *    - O(1) average lookup/insert
 * 
 * 3. Character Counting:
 *    vector<int> count(26, 0)
 *    - Fixed size array for lowercase letters
 *    - Initialized with zeros
 *    count[c - 'a']++
 *    - Maps 'a'-'z' to indices 0-25
 * 
 * 4. Key Generation:
 *    string key
 *    key += to_string(n) + "#"
 *    - Converts count array to string
 *    - Uses "#" as delimiter between counts
 * 
 * 5. Group Storage:
 *    groups[key].push_back(s)
 *    - Adds string to its anagram group
 *    - Creates new vector if key doesn't exist
 * 
 * 6. Result Collection:
 *    for (const auto& pair : groups)
 *    - Iterates through all groups
 *    - pair.first is key (unused)
 *    - pair.second is vector of anagrams
 */
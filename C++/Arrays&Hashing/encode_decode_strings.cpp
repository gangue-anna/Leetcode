#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Encode and decode strings
     * 
     * Approach:
     * - Encode: Prepend each string with its length and '#' delimiter
     * - Decode: Parse length before '#', then extract substring
     * 
     * Time Complexity: O(N) where N is total length of all strings
     * Space Complexity: O(N) for storing encoded/decoded strings
     */
    string encode(vector<string>& strs) {
        string res = "";
        for (const string& s : strs) {
            res += to_string(s.length()) + '#' + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        
        while (i < s.length()) {
            // Find position of delimiter
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            
            // Extract length and string
            int length = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, length));
            
            // Move to next string
            i = j + 1 + length;
        }
        return res;
    }
};

/*
 * Detailed C++ Syntax Explanation:
 * 
 * 1. String Operations:
 *    to_string(s.length())   // Convert number to string
 *    s.substr(pos, len)      // Extract substring from position pos of length len
 *    stoi(str)               // Convert string to integer
 * 
 * 2. Vector Operations:
 *    res.push_back(str)      // Add string to result vector
 * 
 * 3. Range-based For Loop:
 *    for (const string& s : strs)
 *    - const: makes s read-only
 *    - string&: reference to avoid copying
 *    - strs: vector being iterated
 * 
 * 4. String Concatenation:
 *    res += str              // Append str to res
 * 
 * 5. Length/Size:
 *    s.length()              // Get string length
 *    vector.size()           // Get vector size
 */

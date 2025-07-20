#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Check if string of parentheses is valid
     * 
     * Approach:
     * - Use stack to track opening brackets
     * - Match closing brackets with top of stack
     * - Empty stack at end means valid string
     * 
     * Time: O(n) - process each character once
     * Space: O(n) - stack can store up to n/2 brackets
     */
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        for (char c : s) {
            // If closing bracket found
            if (closeToOpen.count(c)) {
                // Check if stack has matching opening bracket
                if (!st.empty() && st.top() == closeToOpen[c]) {
                    st.pop();
                } else {
                    return false;
                }
            }
            // If opening bracket, add to stack
            else {
                st.push(c);
            }
        }
        
        // Valid if stack is empty
        return st.empty();
    }
};

/*
 * Detailed C++ Syntax Explanation for Beginners:
 * 
 * 1. Stack Operations:
 *    stack<char>         // Stack declaration for characters
 *    st.push(c)         // Add element to top
 *    st.pop()           // Remove top element
 *    st.top()           // Access top element
 *    st.empty()         // Check if stack empty
 * 
 * 2. Hash Map Operations:
 *    unordered_map<char, char>  // Hash map declaration
 *    map.count(key)     // Check if key exists (returns 0 or 1)
 *    map[key]           // Access value for key
 * 
 * 3. String Iteration:
 *    for (char c : s)   // Range-based for loop
 *    - char c: current character
 *    - s: string being iterated
 * 
 * 4. Map Initialization:
 *    {{')', '('}, ...}  // List of key-value pairs
 * 
 * Note: This implementation:
 * - Uses stack for O(n) time complexity
 * - Uses hash map for O(1) bracket matching
 * - Handles all types of brackets
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Evaluate Reverse Polish Notation (RPN)
     * 
     * Approach:
     * - Use stack to track numbers during evaluation
     * - For each token:
     *   - If number: push to stack
     *   - If operator: pop two operands, apply operator, push result
     * 
     * Time: O(n) where n is number of tokens
     * Space: O(n) for stack in worst case
     */
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& token : tokens) {
            // If token is operator
            if (token == "+" || token == "-" || 
                token == "*" || token == "/") {
                
                // Pop operands in correct order
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();
                
                // Apply operator and push result
                if (token == "+") {
                    st.push(op1 + op2);
                }
                else if (token == "-") {
                    st.push(op1 - op2);
                }
                else if (token == "*") {
                    st.push(op1 * op2);
                }
                else if (token == "/") {
                    st.push(op1 / op2);  // Integer division
                }
            }
            // If token is number
            else {
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};

/*
 * Detailed C++ Syntax Explanation for Beginners:
 * 
 * 1. Stack Operations:
 *    stack<int> st        // Declare integer stack
 *    st.push(val)        // Add value to top
 *    st.top()            // Get top value
 *    st.pop()            // Remove top value
 * 
 * 2. String Operations:
 *    token == "+"        // String comparison
 *    stoi(token)         // Convert string to integer
 * 
 * 3. Range-based For Loop:
 *    for (const string& token : tokens)
 *    - const: token won't be modified
 *    - string&: reference to avoid copying
 *    - tokens: container being iterated
 * 
 * 4. Vector Parameter:
 *    vector<string>& tokens
 *    - Reference to vector of strings
 * 
 * Note: This implementation:
 * - Handles both operators and numbers
 * - Maintains operator precedence through stack
 * - Uses integer division (truncates towards zero)
 */

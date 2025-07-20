#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    /*
     * Helper function for backtracking
     * openN: count of open parentheses used
     * closedN: count of closed parentheses used
     * curr: current string being built
     * result: vector to store all valid combinations
     * n: total pairs needed
     */
    void backtrack(int openN, int closedN, string& curr, 
                  vector<string>& result, int n) {
        // Base case: used all parentheses
        if (openN == closedN && openN == n) {
            result.push_back(curr);
            return;
        }
        
        // Can add open parenthesis if we haven't used all
        if (openN < n) {
            curr.push_back('(');
            backtrack(openN + 1, closedN, curr, result, n);
            curr.pop_back();  // Backtrack by removing
        }
        
        // Can add closing parenthesis if it wouldn't exceed opens
        if (closedN < openN) {
            curr.push_back(')');
            backtrack(openN, closedN + 1, curr, result, n);
            curr.pop_back();  // Backtrack by removing
        }
    }

public:
    /*
     * Generate all valid combinations of n pairs of parentheses
     * Time: O(2^n * n) - Catalan number growth
     * Space: O(n) for recursion, O(2^n * n) for result
     */
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(0, 0, current, result, n);
        return result;
    }
};

/*
 * Detailed C++ Syntax Explanation for Beginners:
 * 
 * 1. Class Structure:
 *    private:          // Helper functions and members
 *    public:           // Interface accessible outside
 * 
 * 2. Vector Operations:
 *    vector<string>    // Dynamic array of strings
 *    result.push_back()  // Add element to end
 * 
 * 3. String Operations:
 *    string current    // String to build combinations
 *    curr.push_back()  // Add character to end
 *    curr.pop_back()   // Remove last character
 * 
 * 4. Function Parameters:
 *    string& curr     // Reference to avoid copying
 *    vector<string>& result  // Reference to store results
 * 
 * 5. Backtracking Pattern:
 *    - Make change (push)
 *    - Recurse
 *    - Undo change (pop)
 * 
 * 6. Base Case:
 *    if (openN == closedN && openN == n)  // Valid combination
 * 
 * Note: This implementation:
 * - Uses recursion for backtracking
 * - Builds strings character by character
 * - Maintains valid parentheses property
 */

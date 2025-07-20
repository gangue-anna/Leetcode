#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Product of Array Except Self
     * 
     * Approach:
     * - Calculate prefix products (all elements to left)
     * - Calculate suffix products (all elements to right)
     * - Result for each index is prefix[i] * suffix[i]
     * 
     * Time Complexity: O(n) - three passes through array
     * Space Complexity: O(n) - for prefix and suffix arrays
     */
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize prefix and suffix arrays with 1s
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        
        // Calculate prefix products
        for (int i = 0; i < n; i++) {
            if (i == 0) continue;
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        
        // Calculate suffix products
        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) continue;
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        
        // Calculate final result
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = prefix[i] * suffix[i];
        }
        
        return result;
    }
};

/*
 * Detailed C++ Syntax Explanation:
 * 
 * 1. Vector Declaration:
 *    vector<int> prefix(n, 1)   // Create vector of size n filled with 1s
 *    vector<int> result(n)      // Create vector of size n (default 0s)
 * 
 * 2. Size Access:
 *    nums.size()                // Get size of vector
 * 
 * 3. For Loops:
 *    for (int i = 0; i < n; i++)    // Forward iteration
 *    for (int i = n-1; i >= 0; i--) // Backward iteration
 * 
 * 4. Vector Access:
 *    nums[i]                    // Access element at index i
 *    prefix[i-1]               // Access previous element
 * 
 * 5. Continue Statement:
 *    if (i == 0) continue;     // Skip rest of loop for first element
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Find maximum profit from single buy-sell stock transaction
     * 
     * Approach:
     * - Use sliding window with two pointers (buy and sell)
     * - Left pointer tracks minimum price seen
     * - Right pointer looks for selling opportunities
     * - Update max profit when higher selling price found
     * - Move buy pointer when lower price found
     * 
     * Time: O(n) - single pass through array
     * Space: O(1) - only using two pointers and variables
     */
    int maxProfit(vector<int>& prices) {
        // Edge case: empty array or single price
        if (prices.size() < 2) return 0;
        
        // Initialize pointers and max profit
        int buy = 0;          // Buy pointer (left)
        int sell = 1;         // Sell pointer (right)
        int maxProfit = 0;    // Track maximum profit
        
        // Continue until sell pointer reaches end
        while (sell < prices.size()) {
            // If profitable, calculate profit
            if (prices[buy] < prices[sell]) {
                int profit = prices[sell] - prices[buy];
                maxProfit = max(maxProfit, profit);
            }
            else {
                // Found lower price, update buy pointer
                buy = sell;
            }
            // Always move sell pointer forward
            sell++;
        }
        
        return maxProfit;
    }
};

/*
 * Detailed C++ Syntax Explanation for Beginners:
 * 
 * 1. Vector Operations:
 *    prices.size()     // Get array length
 *    prices[index]     // Access element at index
 * 
 * 2. Variable Declarations:
 *    int buy = 0      // Buy pointer at start
 *    int sell = 1     // Sell pointer one step ahead
 *    int maxProfit = 0  // Track best profit found
 * 
 * 3. Standard Library:
 *    max(a, b)        // Returns larger of two values
 * 
 * 4. Edge Case Check:
 *    if (prices.size() < 2)  // Check if array too small
 *    return 0                // Return early if invalid
 * 
 * 5. Profit Calculation:
 *    prices[sell] - prices[buy]  // Current profit
 *    max(maxProfit, profit)      // Update if better
 * 
 * 6. While Loop:
 *    while (sell < prices.size())  // Continue until end
 *    sell++                        // Move window forward
 * 
 * Note: This implementation:
 * - Uses O(n) time by processing each price once
 * - Uses O(1) space with only variables
 * - Handles edge cases properly
 */

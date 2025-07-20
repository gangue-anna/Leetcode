#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Simple Approach: Check each window (not efficient)
     * Time: O(n*k) where n is array length
     * Space: O(1) excluding output array
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty() || k == 0) return {};
        
        vector<int> result;
        
        // Slide window through array
        for (int i = 0; i <= nums.size() - k; i++) {
            // Find maximum in current window
            int windowMax = nums[i];
            for (int j = i; j < i + k; j++) {
                windowMax = max(windowMax, nums[j]);
            }
            result.push_back(windowMax);
        }
        
        return result;
    }
};

class Solution2 {
public:
    /*
     * Optimized Approach: Using deque for O(n) time
     * - Maintain decreasing order of values in deque
     * - Store indices instead of values for window bounds check
     * 
     * Time: O(n) - each element pushed/popped at most once
     * Space: O(k) - deque stores at most k elements
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty() || k == 0) return {};
        
        vector<int> result;
        deque<int> dq;  // Store indices
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove indices outside current window
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            // Remove indices with smaller values
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // Add current index
            dq.push_back(i);
            
            // Add maximum for current window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};

/*
 * Detailed C++ Syntax Explanation for Beginners:
 * 
 * 1. Vector Operations:
 *    vector<int>              // Dynamic array declaration
 *    nums.empty()             // Check if vector empty
 *    nums.size()              // Get vector length
 *    result.push_back(val)    // Add element to vector
 * 
 * 2. Deque Operations:
 *    deque<int>              // Double-ended queue
 *    dq.empty()              // Check if deque empty
 *    dq.front()              // Get first element
 *    dq.back()               // Get last element
 *    dq.pop_front()          // Remove first element
 *    dq.pop_back()           // Remove last element
 *    dq.push_back(val)       // Add element at end
 * 
 * 3. Loop Constructs:
 *    for (int i = 0; i < n; i++)  // Standard for loop
 *    while (!dq.empty())          // While loop with condition
 * 
 * 4. Standard Library:
 *    max(a, b)               // Returns larger value
 * 
 * Note: Solution2 is more efficient because:
 * - Uses O(n) time instead of O(n*k)
 * - Maintains deque of potential maximums
 * - Processes each element only once
 */

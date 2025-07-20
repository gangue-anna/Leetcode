#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Find two numbers in sorted array that sum to target
     * Return 1-based indices of the two numbers
     * 
     * Approach:
     * - Use two pointers: left at start, right at end
     * - If sum > target, move right pointer left (decrease sum)
     * - If sum < target, move left pointer right (increase sum)
     * - If sum = target, return indices (1-based)
     * 
     * Time: O(n) - single pass through array
     * Space: O(1) - only two pointers used
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Initialize pointers
        int left = 0;
        int right = numbers.size() - 1;
        
        while (left < right) {
            int currSum = numbers[left] + numbers[right];
            
            if (currSum > target) {
                right--;  // Need smaller sum
            }
            else if (currSum < target) {
                left++;   // Need larger sum
            }
            else {
                // Found solution, return 1-based indices
                return {left + 1, right + 1};
            }
        }
        
        // No solution found (though problem guarantees one exists)
        return {};
    }
};

/*
 * Detailed C++ Syntax Explanation:
 * 
 * 1. Vector Operations:
 *    numbers.size()   // Get array length
 *    numbers[left]    // Access element at index
 * 
 * 2. Pointer/Index Variables:
 *    int left = 0    // Start of array
 *    int right = numbers.size() - 1  // End of array
 * 
 * 3. While Loop:
 *    while (left < right)  // Continue until pointers meet
 * 
 * 4. Return Statement:
 *    return {left + 1, right + 1}  // Returns vector from initializer list
 *    return {};  // Returns empty vector
 * 
 * 5. Vector<int>:
 *    - Return type specifying vector of integers
 *    - Used for returning pair of indices
 */

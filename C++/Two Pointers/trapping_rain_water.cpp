#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Calculate how much water can be trapped after raining
     * 
     * Approach:
     * - Use two pointers (left and right) from array ends
     * - Track maximum height seen from left and right
     * - Process smaller max height side first
     * - Water at position = min(leftMax, rightMax) - height[i]
     * 
     * Time: O(n) - single pass through array
     * Space: O(1) - only using pointers and variables
     */
    int trap(vector<int>& height) {
        // Edge case: empty array
        if (height.empty()) return 0;
        
        // Initialize pointers and result
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int result = 0;
        
        // Process until pointers meet
        while (left < right) {
            // Process left side if left max is smaller
            if (leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                result += leftMax - height[left];
            }
            // Process right side if right max is smaller or equal
            else {
                right--;
                rightMax = max(rightMax, height[right]);
                result += rightMax - height[right];
            }
        }
        
        return result;
    }
};

/*
 * Detailed C++ Syntax Explanation:
 * 
 * 1. Vector Operations:
 *    height.empty()     // Check if vector is empty
 *    height.size()      // Get array length
 *    height[index]      // Access element at index
 * 
 * 2. Variable Declarations:
 *    int left = 0      // Left pointer starting at beginning
 *    int right = n-1   // Right pointer starting at end
 *    int result = 0    // Accumulate trapped water
 * 
 * 3. Standard Library:
 *    max(a, b)         // Returns larger of two values
 * 
 * 4. Edge Case:
 *    if (height.empty()) return 0;  // Early return for empty input
 * 
 * 5. Water Calculation:
 *    leftMax - height[left]    // Water trapped at left position
 *    rightMax - height[right]  // Water trapped at right position
 * 
 * 6. Two Pointer Movement:
 *    left++    // Move left pointer right
 *    right--   // Move right pointer left
 * 
 * Note: This solution achieves:
 * - O(n) time complexity by visiting each element at most once
 * - O(1) space complexity by using only variables
 */

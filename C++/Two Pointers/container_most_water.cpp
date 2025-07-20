#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Find container with most water using two vertical lines
     * 
     * Approach:
     * - Use two pointers at array ends
     * - Calculate area: width * min height
     * - Move pointer with shorter height inward
     * - Track maximum area seen
     * 
     * Time: O(n) - single pass through array
     * Space: O(1) - only two pointers used
     */
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int left = 0;
        int right = heights.size() - 1;
        
        while (left < right) {
            // Calculate current area
            int width = right - left;
            int height = min(heights[left], heights[right]);
            int area = width * height;
            
            // Update maximum area
            maxArea = max(maxArea, area);
            
            // Move pointer with shorter height
            if (heights[left] < heights[right]) {
                left++;
            }
            else if (heights[left] > heights[right]) {
                right--;
            }
            else {
                // If heights are equal, move either pointer
                left++;
            }
        }
        
        return maxArea;
    }
};

/*
 * Detailed C++ Syntax Explanation:
 * 
 * 1. Vector Operations:
 *    heights.size()   // Get array length
 *    heights[left]    // Access element at index
 * 
 * 2. Standard Library Functions:
 *    min(a, b)       // Returns smaller of two values
 *    max(a, b)       // Returns larger of two values
 * 
 * 3. Variable Declarations:
 *    int maxArea = 0  // Track maximum area found
 *    int left = 0     // Left pointer at start
 *    int right = n-1  // Right pointer at end
 * 
 * 4. Area Calculation:
 *    width = right - left      // Distance between lines
 *    height = min(h1, h2)      // Shorter line limits water
 *    area = width * height     // Rectangle area formula
 */

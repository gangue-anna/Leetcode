#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
         * Optimized Binary Search Approach for Finding Median of Two Sorted Arrays
         * 
         * Key Fix: Proper binary search bounds and termination condition
         * The previous version had issues with infinite loops and incorrect bounds.
         * 
         * Algorithm:
         * 1. Always search on the shorter array (nums1)
         * 2. Use binary search to find correct partition point
         * 3. Partition both arrays so that:
         *    - Left partition has (m+n+1)/2 elements total
         *    - max(left_part) ≤ min(right_part)
         * 4. Calculate median based on total length (odd/even)
         * 
         * Time Complexity: O(log(min(m,n)))
         * Space Complexity: O(1)
         */
        
        // Ensure nums1 is the shorter array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        
        // Binary search on the shorter array
        int left = 0, right = m;
        
        while (left <= right) {
            // Partition points
            int partitionX = (left + right) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;
            
            // Edge elements around partitions
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
            
            // Check if we found the correct partition
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // We have partitioned arrays correctly
                if ((m + n) % 2 == 0) {
                    // Even length: average of two middle elements
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    // Odd length: the middle element
                    return max(maxLeftX, maxLeftY);
                }
            }
            // Adjust partition
            else if (maxLeftX > minRightY) {
                // We are too far on right side for partitionX. Go on left side.
                right = partitionX - 1;
            }
            else {
                // We are too far on left side for partitionX. Go on right side.
                left = partitionX + 1;
            }
        }
        
        // This should never be reached if input is valid
        return 0.0;
    }
};

/*
 * DETAILED C++ SYNTAX EXPLANATION - FIXED VERSION:
 * 
 * KEY FIXES MADE:
 * 
 * 1. PROPER BINARY SEARCH BOUNDS:
 *    - Changed from searching indices to searching partition points
 *    - left = 0, right = m (where m is size of shorter array)
 *    - This allows partitionX to be 0 to m (inclusive), representing 0 to m elements
 * 
 * 2. CORRECT PARTITION CALCULATION:
 *    - partitionX = number of elements from nums1 in left part
 *    - partitionY = number of elements from nums2 in left part
 *    - Total left elements = (m + n + 1) / 2 ensures proper split for odd/even
 * 
 * 3. SAFER BOUNDARY HANDLING:
 *    - Use INT_MIN and INT_MAX instead of INFINITY
 *    - More reliable for integer comparisons
 *    - Prevents floating-point comparison issues
 * 
 * 4. GUARANTEED TERMINATION:
 *    - Proper while loop condition: while (left <= right)
 *    - Correct binary search updates ensure convergence
 *    - No infinite loop possible
 * 
 * Line 18: if (nums1.size() > nums2.size()) {
 * - Ensures nums1 is always the shorter array
 * - Recursive call swaps the arrays if needed
 * - Critical for algorithm correctness and efficiency
 * 
 * Line 22-23: int m = nums1.size(); int n = nums2.size();
 * - Store array sizes in variables for cleaner code
 * - m = size of shorter array, n = size of longer array
 * 
 * Line 26: int left = 0, right = m;
 * - IMPORTANT: right = m (not m-1)
 * - We're searching partition points, not array indices
 * - partitionX can be 0 (no elements from nums1) to m (all elements from nums1)
 * 
 * Line 28: while (left <= right) {
 * - Standard binary search termination condition
 * - Loop continues until search space is exhausted
 * - Guaranteed to terminate unlike the previous while(true)
 * 
 * Line 30: int partitionX = (left + right) / 2;
 * - partitionX = number of elements from nums1 to include in left partition
 * - If partitionX = 2, then nums1[0] and nums1[1] are in left partition
 * 
 * Line 31: int partitionY = (m + n + 1) / 2 - partitionX;
 * - partitionY = number of elements from nums2 to include in left partition
 * - Total left elements = partitionX + partitionY = (m + n + 1) / 2
 * - "+1" ensures left partition has same size or one more element than right
 * 
 * Line 34: int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
 * - If partitionX = 0, no elements from nums1 in left partition
 * - Otherwise, rightmost element from nums1 in left partition is nums1[partitionX-1]
 * - INT_MIN used as sentinel (guaranteed smaller than any real element)
 * 
 * Line 35: int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
 * - If partitionX = m, all elements from nums1 are in left partition
 * - Otherwise, leftmost element from nums1 in right partition is nums1[partitionX]
 * - INT_MAX used as sentinel (guaranteed larger than any real element)
 * 
 * Line 37-38: Similar logic for nums2 partitions
 * - maxLeftY = rightmost element from nums2 in left partition
 * - minRightY = leftmost element from nums2 in right partition
 * 
 * Line 41: if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
 * - Valid partition condition: all left elements ≤ all right elements
 * - Cross-comparison ensures proper ordering across both arrays
 * 
 * Line 43-44: if ((m + n) % 2 == 0) {
 * - Check if total length is even
 * - Even: median = average of two middle elements
 * - Odd: median = the single middle element
 * 
 * Line 45: return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
 * - Even case: average of largest left element and smallest right element
 * - "/ 2.0" ensures floating-point division
 * 
 * Line 47: return max(maxLeftX, maxLeftY);
 * - Odd case: largest element in left partition is the median
 * - Left partition has one more element than right partition
 * 
 * Line 51: else if (maxLeftX > minRightY) {
 * - nums1 contributes too many large elements to left partition
 * - Need to move partition point left (include fewer elements from nums1)
 * 
 * Line 53: right = partitionX - 1;
 * - Standard binary search: search left half
 * 
 * Line 55-57: else clause
 * - nums1 contributes too few elements to left partition
 * - Need to move partition point right (include more elements from nums1)
 * - left = partitionX + 1: search right half
 * 
 * WHY THE PREVIOUS VERSION TIMED OUT:
 * 
 * 1. INFINITE LOOP RISK:
 *    - while(true) with complex termination conditions
 *    - Edge cases could prevent proper convergence
 * 
 * 2. INCORRECT BOUNDS:
 *    - Searching array indices instead of partition points
 *    - Could miss valid partitions or search invalid ranges
 * 
 * 3. FLOATING-POINT ISSUES:
 *    - Using INFINITY in integer comparisons
 *    - Potential precision problems with very large numbers
 * 
 * 4. COMPLEX POINTER LOGIC:
 *    - Unnecessary pointer swapping added complexity
 *    - Simple recursive call is cleaner and more reliable
 * 
 * PERFORMANCE IMPROVEMENTS IN FIXED VERSION:
 * 
 * 1. GUARANTEED TERMINATION:
 *    - Proper binary search bounds ensure O(log m) iterations
 *    - No risk of infinite loops
 * 
 * 2. CLEANER LOGIC:
 *    - Direct array access instead of pointer dereferencing
 *    - Simpler boundary handling with INT_MIN/INT_MAX
 * 
 * 3. BETTER EDGE CASE HANDLING:
 *    - Proper partition point calculation handles all array sizes
 *    - Robust boundary checks prevent out-of-bounds access
 * 
 * 4. OPTIMIZED RECURSION:
 *    - Single recursive call to ensure shorter array is first
 *    - No repeated swapping or complex pointer management
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
         * Binary Search in Rotated Sorted Array
         * 
         * Problem: Search for a target value in a rotated sorted array
         * Example: [4,5,6,7,0,1,2] rotated from [0,1,2,4,5,6,7]
         * 
         * Key Insight: Even though the array is rotated, at least one half 
         * of any subarray will always be properly sorted. We can use this
         * property to determine which half to search.
         * 
         * Algorithm:
         * 1. Use binary search with left and right pointers
         * 2. Calculate middle index
         * 3. If middle element equals target, return index
         * 4. Determine which half is sorted:
         *    - If left half is sorted (nums[left] <= nums[mid]):
         *      * Check if target lies within the sorted left half
         *      * If yes, search left half; otherwise search right half
         *    - If right half is sorted:
         *      * Check if target lies within the sorted right half  
         *      * If yes, search right half; otherwise search left half
         * 5. Repeat until target found or search space exhausted
         * 
         * Time Complexity: O(log n) - Binary search eliminates half the array each time
         * Space Complexity: O(1) - Only using constant extra space for variables
         */
        
        // Initialize binary search pointers
        int l = 0, r = nums.size() - 1;
        
        // Binary search loop
        while (l <= r) {
            // Calculate middle index (safe from integer overflow)
            int mid = l + (r - l) / 2;
            
            // Target found at middle position
            if (target == nums[mid]) {
                return mid;
            }
            
            // Check if left portion is sorted
            // Note: We use <= because when l == mid, left portion has only one element
            if (nums[l] <= nums[mid]) {
                // Left portion is sorted: nums[l] to nums[mid] is in ascending order
                
                // Check if target lies within the sorted left portion
                // Target must be >= nums[l] and < nums[mid] to be in left portion
                if (nums[l] <= target && target < nums[mid]) {
                    // Target is in left portion, search left half
                    r = mid - 1;
                } else {
                    // Target is not in left portion, search right half
                    l = mid + 1;
                }
            } 
            // Right portion is sorted
            else {
                // Right portion is sorted: nums[mid] to nums[r] is in ascending order
                
                // Check if target lies within the sorted right portion
                // Target must be > nums[mid] and <= nums[r] to be in right portion
                if (nums[mid] < target && target <= nums[r]) {
                    // Target is in right portion, search right half
                    l = mid + 1;
                } else {
                    // Target is not in right portion, search left half
                    r = mid - 1;
                }
            }
        }
        
        // Target not found in the array
        return -1;
    }
};

/*
 * DETAILED C++ SYNTAX EXPLANATION FOR BEGINNERS:
 * 
 * Line 1: #include <bits/stdc++.h>
 * - This is a non-standard header that includes most common C++ standard libraries
 * - It includes <iostream>, <vector>, <algorithm>, etc. all at once
 * - Convenient for competitive programming but not recommended for production code
 * - Alternative: Include specific headers like #include <vector>, #include <iostream>
 * 
 * Line 2: using namespace std;
 * - Allows us to use standard library functions without "std::" prefix
 * - Without this, we'd need to write "std::vector" instead of just "vector"
 * - Makes code cleaner but can cause naming conflicts in large projects
 * 
 * Line 4: class Solution {
 * - Declares a class named "Solution"
 * - Classes are templates for creating objects that contain data and functions
 * - Everything inside the curly braces belongs to this class
 * 
 * Line 5: public:
 * - Access specifier that makes the following members publicly accessible
 * - Without "public:", the search function would be private (inaccessible from outside)
 * - Other access specifiers: "private:" (only class can access), "protected:" (class and derived classes)
 * 
 * Line 6: int search(vector<int>& nums, int target) {
 * - "int" = return type (function returns an integer)
 * - "search" = function name
 * - "vector<int>&" = first parameter type (reference to vector of integers)
 * - "&nums" = reference parameter (avoids copying entire vector, more efficient)
 * - "int target" = second parameter (integer value to search for)
 * 
 * Line 29: int l = 0, r = nums.size() - 1;
 * - Declares two integer variables in one statement
 * - "l" initialized to 0 (left pointer)
 * - "r" initialized to nums.size() - 1 (right pointer, last valid index)
 * - "nums.size()" returns the number of elements in the vector
 * - Subtract 1 because array indexing starts from 0
 * 
 * Line 32: while (l <= r) {
 * - while loop that continues as long as condition (l <= r) is true
 * - Loop body executes repeatedly until condition becomes false
 * - When l > r, it means search space is exhausted
 * 
 * Line 34: int mid = l + (r - l) / 2;
 * - Calculates middle index using overflow-safe formula
 * - Equivalent to (l + r) / 2 but prevents integer overflow for very large numbers
 * - "/" performs integer division (truncates decimal part)
 * 
 * Line 37: if (target == nums[mid]) {
 * - if statement checks if condition in parentheses is true
 * - "==" is comparison operator (checks equality)
 * - "nums[mid]" accesses element at index mid
 * - Square brackets [] are used for array/vector indexing
 * 
 * Line 38: return mid;
 * - Returns the value of mid to whoever called this function
 * - Function execution ends immediately when return is encountered
 * 
 * Line 42: if (nums[l] <= nums[mid]) {
 * - "<=" means "less than or equal to"
 * - Checks if left portion is sorted by comparing boundary elements
 * 
 * Line 46: if (nums[l] <= target && target < nums[mid]) {
 * - "&&" is logical AND operator
 * - Both conditions must be true for the entire expression to be true
 * - Checks if target falls within the range [nums[l], nums[mid])
 * 
 * Line 48: r = mid - 1;
 * - Updates right pointer to search left half
 * - "-1" because we already checked mid, so exclude it
 * 
 * Line 50: l = mid + 1;
 * - Updates left pointer to search right half
 * - "+1" because we already checked mid, so exclude it
 * 
 * Line 52: else {
 * - else clause executes when the if condition is false
 * - In this case, when left portion is not sorted (right portion is sorted)
 * 
 * Line 56: if (nums[mid] < target && target <= nums[r]) {
 * - Checks if target falls within the sorted right portion
 * - Range is (nums[mid], nums[r]] (exclusive of mid, inclusive of r)
 * 
 * Line 65: return -1;
 * - Returns -1 to indicate target was not found
 * - This line executes only if while loop ends without finding target
 * 
 * Line 66: }
 * - Closing brace for the search function
 * 
 * Line 67: };
 * - Closing brace for the Solution class
 * - Semicolon is mandatory after class definition in C++
 * 
 * IMPORTANT C++ CONCEPTS DEMONSTRATED:
 * 
 * 1. References (&):
 *    - "vector<int>& nums" means nums is a reference to the original vector
 *    - No copying occurs, making it memory efficient
 *    - Changes to nums would affect the original (though we don't modify it here)
 * 
 * 2. Vector Indexing:
 *    - vectors use 0-based indexing like arrays
 *    - nums[0] is first element, nums[size-1] is last element
 *    - Out-of-bounds access leads to undefined behavior
 * 
 * 3. Integer Division:
 *    - "/" with integers truncates towards zero
 *    - 7/2 = 3 (not 3.5)
 * 
 * 4. Logical Operators:
 *    - && (AND): both conditions must be true
 *    - || (OR): at least one condition must be true  
 *    - ! (NOT): flips true/false
 * 
 * 5. Comparison Operators:
 *    - == (equal), != (not equal)
 *    - < (less than), <= (less than or equal)
 *    - > (greater than), >= (greater than or equal)
 * 
 * ALGORITHM EFFICIENCY:
 * - Time: O(log n) because we eliminate half the search space each iteration
 * - Space: O(1) because we only use a constant amount of extra variables
 * - Much faster than linear search O(n) for large arrays
 */
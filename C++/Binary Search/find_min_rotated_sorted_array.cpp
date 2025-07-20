#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        /*
         * Binary Search Approach to Find Minimum in Rotated Sorted Array
         * 
         * Key Insight: In a rotated sorted array, one half is always sorted.
         * We can use this property to eliminate half of the search space in each iteration.
         * 
         * Algorithm:
         * 1. Initialize result with first element and set left/right pointers
         * 2. While left <= right:
         *    - If left portion is sorted (nums[left] < nums[right]), 
         *      the minimum is at nums[left], update result and break
         *    - Calculate middle index
         *    - Update result with minimum of current result and nums[mid]
         *    - If left half is sorted (nums[mid] >= nums[left]):
         *      minimum must be in right half, so move left = mid + 1
         *    - Otherwise, minimum is in left half, so move right = mid - 1
         * 3. Return the minimum found
         * 
         * Time Complexity: O(log n) - Binary search eliminates half the array each iteration
         * Space Complexity: O(1) - Only using constant extra space for variables
         */
        
        // Initialize result with the first element
        int res = nums[0];
        
        // Set up binary search pointers
        int l = 0, r = nums.size() - 1;
        
        // Binary search loop
        while (l <= r) {
            // If the current subarray is sorted (not rotated)
            // then the leftmost element is the minimum
            if (nums[l] < nums[r]) {
                res = min(res, nums[l]);
                break; // We found the minimum, exit loop
            }
            
            // Calculate middle index
            int m = l + (r - l) / 2; // Prevents integer overflow
            
            // Update result with the smaller value between current result and middle element
            res = min(res, nums[m]);
            
            // Determine which half to search next
            if (nums[m] >= nums[l]) {
                // Left half is sorted, minimum must be in right half
                l = m + 1;
            } else {
                // Right half is sorted, minimum must be in left half
                r = m - 1;
            }
        }
        
        return res;
    }
};

/*
 * DETAILED C++ SYNTAX EXPLANATION FOR BEGINNERS:
 * 
 * Line 1: #include <vector>
 * - This includes the vector header file which provides the vector container
 * - vector is like a dynamic array that can grow/shrink in size
 * 
 * Line 2: #include <algorithm>
 * - This includes algorithm header for utility functions like min()
 * - min() function returns the smaller of two values
 * 
 * Line 3: using namespace std;
 * - This allows us to use standard library functions without "std::" prefix
 * - Instead of writing "std::vector", we can just write "vector"
 * 
 * Line 5: class Solution {
 * - Declares a class named "Solution"
 * - Classes are blueprints for creating objects with data and methods
 * 
 * Line 6: public:
 * - Access specifier meaning the following members are accessible from outside the class
 * - Without this, the findMin function would be private (inaccessible)
 * 
 * Line 7: int findMin(vector<int> &nums) {
 * - "int" = return type (function returns an integer)
 * - "findMin" = function name
 * - "vector<int>" = parameter type (vector of integers)
 * - "&nums" = reference parameter (avoids copying the entire vector, more efficient)
 * - The "&" makes it a reference, so we work directly with the original vector
 * 
 * Line 24: int res = nums[0];
 * - Declares an integer variable "res" and initializes it with first element
 * - "nums[0]" accesses the first element (arrays/vectors are 0-indexed in C++)
 * 
 * Line 27: int l = 0, r = nums.size() - 1;
 * - Declares two integer variables in one line
 * - "nums.size()" returns the number of elements in the vector
 * - "nums.size() - 1" gives us the last valid index
 * 
 * Line 30: while (l <= r) {
 * - while loop continues as long as condition (l <= r) is true
 * - Loop body executes repeatedly until condition becomes false
 * 
 * Line 33: if (nums[l] < nums[r]) {
 * - if statement checks condition in parentheses
 * - Only executes the code block if condition is true
 * 
 * Line 34: res = min(res, nums[l]);
 * - min() function returns the smaller of two values
 * - Updates res with the minimum value between current res and nums[l]
 * 
 * Line 35: break;
 * - Immediately exits the while loop
 * - Control jumps to the first statement after the loop
 * 
 * Line 39: int m = l + (r - l) / 2;
 * - Calculates middle index using safe formula to avoid integer overflow
 * - Alternative to (l + r) / 2 which might overflow for large numbers
 * 
 * Line 42: res = min(res, nums[m]);
 * - Updates result with minimum of current result and middle element
 * 
 * Line 45-51: if-else statement
 * - if condition is true, execute first block (lines 47-48)
 * - otherwise (else), execute second block (lines 50-51)
 * 
 * Line 54: return res;
 * - Returns the value of res to whoever called this function
 * - Function execution ends here
 * 
 * Line 55: }
 * - Closing brace for the findMin function
 * 
 * Line 56: };
 * - Closing brace for the Solution class
 * - Semicolon is required after class definition in C++
 * 
 * MEMORY AND PERFORMANCE NOTES:
 * - Using "vector<int> &nums" (reference) avoids copying the entire array
 * - Binary search reduces time from O(n) linear search to O(log n)
 * - Only using a few integer variables, so space complexity is O(1)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /**
         * Binary search implementation to find target in sorted array.
         * 
         * Approach:
         * 1. Initialize left and right pointers to start and end of array
         * 2. While left <= right (search space is valid):
         *    - Calculate middle index avoiding integer overflow
         *    - If target found at middle, return its index
         *    - If target < middle value, search left half by moving right pointer
         *    - If target > middle value, search right half by moving left pointer
         * 3. If target not found after exhausting search space, return -1
         * 
         * Key Points:
         * - Array must be sorted for binary search to work
         * - Each iteration reduces search space by half
         * - Use l + (r - l) / 2 to avoid potential integer overflow
         * - Left <= right condition ensures we check even single-element ranges
         * 
         * Time Complexity: O(log n) - search space halves each iteration
         *   - In worst case, we need at most log₂(n) comparisons
         *   - Example: array of 1000 elements needs at most 10 comparisons
         * 
         * Space Complexity: O(1) - only uses constant extra space for pointers
         *   - No recursion or additional data structures needed
         */
        
        // Initialize pointers to start and end of array
        int left = 0;                           // Left boundary of search space
        int right = nums.size() - 1;            // Right boundary of search space
        
        // Continue while search space is valid (at least one element to check)
        while (left <= right) {
            // Calculate middle index avoiding integer overflow
            // Using (left + right) / 2 could overflow if left + right > INT_MAX
            int mid = left + (right - left) / 2;
            
            // If target found at middle position, return its index
            if (nums[mid] == target) {
                return mid;
            }
            // If target is less than middle value, search left half
            else if (target < nums[mid]) {
                // Exclude middle and everything to its right
                right = mid - 1;
            }
            // If target is greater than middle value, search right half
            else {
                // Exclude middle and everything to its left
                left = mid + 1;
            }
        }
        
        // Target not found in array after exhausting all possibilities
        return -1;
    }
};

/*
=== C++ SYNTAX EXPLANATION FOR BEGINNERS ===

1. int search(vector<int>& nums, int target)
   - Function declaration with return type int
   - vector<int>& nums: reference to vector of integers (original vector, not a copy)
   - int target: integer value we're searching for (passed by value)
   - & (reference) avoids copying the entire vector, improving efficiency

2. int left = 0;
   - Declares integer variable named 'left' and initializes it to 0
   - This represents the leftmost index of our current search range
   - In C++, variables must be declared with their type (int, double, etc.)

3. int right = nums.size() - 1;
   - nums.size() returns the number of elements in the vector
   - size() returns type size_t (unsigned integer), but implicitly converts to int
   - Subtract 1 because array indices start from 0, so last index is size-1

4. while (left <= right)
   - while loop continues as long as condition is true
   - left <= right means there's at least one element in our search range
   - When left > right, search space is empty (no more elements to check)

5. int mid = left + (right - left) / 2;
   - Calculates middle index of current search range
   - (right - left) / 2 gives half the distance between left and right
   - Adding to left gives us the middle position
   - This formula avoids integer overflow that could occur with (left + right) / 2

6. if (nums[mid] == target)
   - if statement checks if condition is true
   - nums[mid] accesses element at index mid using [] operator
   - == is equality comparison operator (different from = which is assignment)

7. return mid;
   - return statement exits function and sends back the value mid
   - This immediately stops execution and returns the found index

8. else if (target < nums[mid])
   - else if provides alternative condition to check
   - < is less-than comparison operator
   - Only executes if the previous if condition was false

9. right = mid - 1;
   - Assignment statement (= operator)
   - Updates right pointer to exclude middle element and everything to its right
   - mid - 1 because we know target isn't at mid, so we don't need to check it again

10. else
    - else clause handles remaining case (target > nums[mid])
    - Executes when neither if nor else if conditions were true

11. left = mid + 1;
    - Updates left pointer to exclude middle element and everything to its left
    - Similar logic to right = mid - 1, but moving left boundary instead

12. return -1;
    - Returns -1 to indicate target was not found
    - This is a common convention: -1 means "not found" since valid indices are >= 0

=== KEY C++ CONCEPTS USED ===

- Variables: Must be declared with type (int, double, bool, etc.)
- Vector: Dynamic array with size() method and [] indexing
- References (&): Allow functions to work with original data without copying
- Operators: 
  * Arithmetic: +, -, *, /
  * Comparison: ==, <, >, <=, >=, !=
  * Assignment: =
- Control Flow:
  * while loops: repeat while condition is true
  * if/else if/else: conditional execution
  * return: exit function with a value
- Integer Division: / operator with integers gives integer result (truncated)

=== ALGORITHM VISUALIZATION EXAMPLE ===

Let's trace through searching for target = 7 in array [1, 3, 5, 7, 9, 11]:

Initial: left = 0, right = 5, array = [1, 3, 5, 7, 9, 11]

Iteration 1:
- mid = 0 + (5-0)/2 = 2
- nums[2] = 5, target = 7
- 7 > 5, so search right half
- left = mid + 1 = 3

Iteration 2: left = 3, right = 5
- mid = 3 + (5-3)/2 = 4  
- nums[4] = 9, target = 7
- 7 < 9, so search left half
- right = mid - 1 = 3

Iteration 3: left = 3, right = 3
- mid = 3 + (3-3)/2 = 3
- nums[3] = 7, target = 7
- Found! Return 3

Total comparisons: 3 (much better than checking all 6 elements!)

=== WHY BINARY SEARCH IS EFFICIENT ===

Linear Search (checking each element):
- Best case: O(1) - target is first element
- Worst case: O(n) - target is last element or not present
- Average case: O(n/2) ≈ O(n)

Binary Search (halving search space):
- Best case: O(1) - target is middle element
- Worst case: O(log n) - need to halve log₂(n) times
- Average case: O(log n)

For 1 million elements:
- Linear search: up to 1,000,000 comparisons
- Binary search: at most 20 comparisons!

The trade-off: array must be sorted, but if you do many searches,
the sorting cost is amortized across all searches.
*/
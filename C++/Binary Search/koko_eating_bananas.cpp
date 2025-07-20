#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        /**
         * Find the minimum eating speed such that Koko can finish all bananas within h hours.
         * 
         * Problem Understanding:
         * - Koko eats bananas at speed k (bananas per hour)
         * - Each hour, she can choose a pile and eat at most k bananas from it
         * - If pile has fewer than k bananas, she eats the whole pile and waits
         * - Goal: find minimum k such that all piles are finished within h hours
         * 
         * Approach - Binary Search on Answer:
         * 1. Search space: k ranges from 1 (minimum possible) to max(piles) (maximum needed)
         * 2. For each candidate speed k:
         *    - Calculate total hours needed using ceiling division for each pile
         *    - If total hours <= h: k might work, try smaller k (search left)
         *    - If total hours > h: k is too slow, try larger k (search right)
         * 3. Keep track of the minimum valid k found
         * 
         * Key Insight: This is a "minimum value that satisfies condition" problem.
         * We use binary search to efficiently find the minimum k.
         * 
         * Time Complexity: O(n * log m)
         *   - n = number of piles (we iterate through all piles for each k)
         *   - m = max pile size (search space for k is [1, max(piles)])
         *   - log m iterations of binary search, each taking O(n) time
         * 
         * Space Complexity: O(1) - only uses constant extra space for variables
         */
        
        // Define search space for eating speed k
        int left = 1;                           // Minimum possible eating speed
        int right = *max_element(piles.begin(), piles.end()); // Maximum pile size
        int result = right;                     // Initialize result to maximum (worst case)
        
        // Binary search for minimum valid eating speed
        while (left <= right) {
            int k = left + (right - left) / 2;  // Current eating speed to test
            long long totalHours = 0;           // Total hours needed at speed k
            
            // Calculate total hours needed for all piles at speed k
            for (int pile : piles) {
                // Ceiling division: (pile + k - 1) / k
                // This calculates how many hours needed for current pile
                // Examples: pile=10, k=3 → (10+3-1)/3 = 12/3 = 4 hours
                //          pile=9, k=3 → (9+3-1)/3 = 11/3 = 3 hours
                totalHours += (pile + k - 1) / k;
            }
            
            // Check if current speed k is valid
            if (totalHours <= h) {
                // Speed k works! But maybe we can go slower
                result = min(result, k);         // Update our best answer
                right = k - 1;                  // Try smaller speeds (search left)
            } else {
                // Speed k is too slow, need to eat faster
                left = k + 1;                   // Try larger speeds (search right)
            }
        }
        
        return result;
    }
};

/*
=== C++ SYNTAX EXPLANATION FOR BEGINNERS ===

1. int minEatingSpeed(vector<int>& piles, int h)
   - Function returns int (the minimum eating speed)
   - vector<int>& piles: reference to vector of integers (pile sizes)
   - int h: maximum hours available (passed by value)
   - & avoids copying the entire vector, improving performance

2. int left = 1;
   - Declares integer variable 'left' and initializes to 1
   - This represents minimum possible eating speed (at least 1 banana per hour)
   - In C++, variables must be explicitly declared with their type

3. *max_element(piles.begin(), piles.end())
   - max_element() finds iterator pointing to maximum element
   - piles.begin(): iterator pointing to first element of vector
   - piles.end(): iterator pointing to position after last element
   - * (dereference operator) gets the actual value from the iterator
   - This finds the largest pile size in the vector

4. int result = right;
   - Initializes result to the maximum possible value (right)
   - This serves as our "worst case" answer that we'll try to improve

5. while (left <= right)
   - Continue binary search while search space is valid
   - When left > right, we've found our answer

6. int k = left + (right - left) / 2;
   - Calculates middle value (candidate eating speed)
   - Overflow-safe version of (left + right) / 2
   - This is the eating speed we're currently testing

7. long long totalHours = 0;
   - long long is a larger integer type than int
   - Used to prevent overflow when summing hours for many piles
   - Can store much larger numbers than regular int

8. for (int pile : piles)
   - Range-based for loop (C++11 feature)
   - Iterates through each element in piles vector
   - 'pile' is a copy of each element (not a reference)
   - Equivalent to: for (int i = 0; i < piles.size(); i++) { int pile = piles[i]; ... }

9. totalHours += (pile + k - 1) / k;
   - += is compound assignment operator (equivalent to: totalHours = totalHours + ...)
   - (pile + k - 1) / k implements ceiling division
   - Regular division (/) with integers truncates down, but we need to round up
   - Adding (k-1) before dividing effectively rounds up

10. if (totalHours <= h)
    - Checks if current eating speed k allows finishing within h hours
    - <= means "less than or equal to"

11. result = min(result, k);
    - min() function returns the smaller of two values
    - Updates result only if current k is better (smaller) than previous best
    - Keeps track of the minimum valid eating speed found so far

12. right = k - 1;
    - Updates right boundary to exclude current k and search for smaller speeds
    - Since k works, maybe an even smaller speed also works

13. else { left = k + 1; }
    - Handles case where k is too slow (totalHours > h)
    - Updates left boundary to search for larger (faster) speeds
    - k + 1 because we know k doesn't work

=== KEY C++ CONCEPTS USED ===

- Vector: Dynamic array with .begin(), .end(), .size() methods
- Iterators: Objects that point to positions in containers
- Range-based for loop: Modern C++ way to iterate through containers
- max_element(): STL algorithm to find maximum element
- Dereference operator (*): Gets value from iterator/pointer
- long long: Extended integer type for larger numbers
- Compound operators: += for addition assignment
- min() function: Standard library utility to find minimum

=== CEILING DIVISION EXPLANATION ===

Why use (pile + k - 1) / k for ceiling division?

Regular integer division truncates (rounds down):
- 10 / 3 = 3 (but we need 4 hours to eat 10 bananas at speed 3)
- 9 / 3 = 3 (exactly 3 hours needed)

Ceiling division rounds up:
- (10 + 3 - 1) / 3 = 12 / 3 = 4 ✓
- (9 + 3 - 1) / 3 = 11 / 3 = 3 ✓

The formula works because:
- If pile is exactly divisible by k: (pile + k - 1) / k = pile / k
- If pile has remainder: the extra (k-1) pushes it to the next integer

Alternative approaches:
1. Using floating point: ceil((double)pile / k) - but requires <cmath>
2. Using conditional: (pile % k == 0) ? pile/k : pile/k + 1 - more complex

=== ALGORITHM VISUALIZATION EXAMPLE ===

Consider piles = [3, 6, 7, 11], h = 8
Goal: Find minimum k such that Koko can eat all bananas in 8 hours

Initial: left = 1, right = 11 (max pile size)

Iteration 1: k = (1 + 11) / 2 = 6
- Pile 3: (3+6-1)/6 = 8/6 = 1 hour
- Pile 6: (6+6-1)/6 = 11/6 = 1 hour  
- Pile 7: (7+6-1)/6 = 12/6 = 2 hours
- Pile 11: (11+6-1)/6 = 16/6 = 2 hours
- Total: 1+1+2+2 = 6 hours <= 8 ✓
- k=6 works! Try smaller: right = 5, result = 6

Iteration 2: k = (1 + 5) / 2 = 3  
- Pile 3: (3+3-1)/3 = 5/3 = 1 hour
- Pile 6: (6+3-1)/3 = 8/3 = 2 hours
- Pile 7: (7+3-1)/3 = 9/3 = 3 hours  
- Pile 11: (11+3-1)/3 = 13/3 = 4 hours
- Total: 1+2+3+4 = 10 hours > 8 ✗
- k=3 too slow! Try larger: left = 4

Iteration 3: k = (4 + 5) / 2 = 4
- Pile 3: (3+4-1)/4 = 6/4 = 1 hour
- Pile 6: (6+4-1)/4 = 9/4 = 2 hours
- Pile 7: (7+4-1)/4 = 10/4 = 2 hours
- Pile 11: (11+4-1)/4 = 14/4 = 3 hours  
- Total: 1+2+2+3 = 8 hours <= 8 ✓
- k=4 works! Try smaller: right = 3, result = 4

Iteration 4: left = 4, right = 3
- left > right, so stop

Answer: k = 4 (minimum eating speed)

=== WHY BINARY SEARCH WORKS HERE ===

This problem has a key property: if eating speed k works, then any speed > k also works.
This creates a "monotonic" property:
- Speeds [1, 2, 3] might be too slow (don't work)  
- Speeds [4, 5, 6, 7, 8, 9, 10, 11] all work

We're looking for the boundary point - the minimum speed that works.
Binary search efficiently finds this boundary in O(log m) time instead of 
testing each speed linearly in O(m) time.
*/
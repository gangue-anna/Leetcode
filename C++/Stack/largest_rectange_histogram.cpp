#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /**
         * Find the area of the largest rectangle in a histogram.
         * 
         * Approach - Monotonic Stack:
         * 1. Use a stack to maintain bars in increasing order of height
         * 2. For each bar:
         *    - While current bar is shorter than stack top:
         *      * Pop from stack and calculate area using popped bar as height
         *      * Width = current index - index of popped bar
         *      * Update start index to handle extended rectangles
         *    - Push current bar with (potentially updated) start index
         * 3. After processing all bars, calculate areas for remaining bars in stack
         *    - These bars can extend to the end of the histogram
         * 
         * Key Insight: When we pop a bar, it means we found the right boundary 
         * where this bar's height can no longer be maintained. The left boundary 
         * is determined by when this bar was originally pushed (or extended).
         * 
         * Time Complexity: O(n) - each bar is pushed and popped at most once
         * Space Complexity: O(n) - stack can contain at most n bars
         */
        
        int maxArea = 0;                                // Track maximum area found
        stack<pair<int, int>> st;                       // Stack stores [index, height] pairs
        
        // Process each bar in the histogram
        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i];                         // Current bar height
            int start = i;                              // Starting index for current bar
            
            // Pop bars taller than current bar and calculate their areas
            while (!st.empty() && st.top().second > h) {
                pair<int, int> topPair = st.top();      // Get top element
                st.pop();                               // Remove it from stack
                
                int index = topPair.first;              // Index of popped bar
                int height = topPair.second;            // Height of popped bar
                
                // Calculate area: height * width
                // Width = current position - starting position of popped bar
                int area = height * (i - index);
                maxArea = max(maxArea, area);
                
                // Extend current bar's start to popped bar's position
                // This allows current bar to use the width of popped bars
                start = index;
            }
            
            // Push current bar with its (potentially extended) start position
            st.push(make_pair(start, h));
        }
        
        // Calculate areas for remaining bars in stack
        // These bars can extend to the end of histogram
        while (!st.empty()) {
            pair<int, int> topPair = st.top();
            st.pop();
            
            int index = topPair.first;
            int height = topPair.second;
            
            // Width = total length - starting position of this bar
            int area = height * (heights.size() - index);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};

/*
=== C++ SYNTAX EXPLANATION FOR BEGINNERS ===

1. int largestRectangleArea(vector<int>& heights)
   - Function returns int (integer)
   - Takes a reference to vector of integers as parameter
   - & means reference - we work with original vector, not a copy
   - This avoids unnecessary copying of potentially large data

2. int maxArea = 0;
   - Declares and initializes integer variable maxArea to 0
   - This will track the maximum rectangle area found so far

3. stack<pair<int, int>> st;
   - Declares a stack that stores pairs of integers
   - Each pair contains [index, height] information
   - stack follows LIFO (Last In, First Out) principle

4. for (int i = 0; i < heights.size(); i++)
   - Standard for loop iterating through vector indices
   - i starts at 0, continues while i < vector size, increments i each iteration
   - heights.size() returns the number of elements in the vector

5. int h = heights[i];
   - Creates integer variable h and assigns it the height at index i
   - heights[i] accesses the element at position i in the vector

6. while (!st.empty() && st.top().second > h)
   - While loop with two conditions connected by AND (&&)
   - !st.empty(): checks if stack is NOT empty (! is negation operator)
   - st.top(): returns reference to top element of stack (doesn't remove it)
   - .second: accesses the second element of a pair (the height)

7. pair<int, int> topPair = st.top();
   - Creates a pair variable and copies the top stack element into it
   - pair<int, int> means it holds two integers
   - We copy it because st.pop() will remove it from stack

8. st.pop();
   - Removes the top element from stack
   - Important: C++ pop() doesn't return the removed element
   - That's why we use st.top() first to get the element

9. int index = topPair.first;
   - Extracts the first element of the pair (the index)
   - .first accesses the first component of a pair

10. int height = topPair.second;
    - Extracts the second element of the pair (the height)
    - .second accesses the second component of a pair

11. int area = height * (i - index);
    - Calculates rectangle area using height × width
    - Width is the difference between current position and bar's start position
    - Parentheses ensure subtraction happens before multiplication

12. maxArea = max(maxArea, area);
    - max() function returns the larger of two values
    - Updates maxArea if current area is larger
    - This is equivalent to: if (area > maxArea) maxArea = area;

13. st.push(make_pair(start, h));
    - push() adds element to top of stack
    - make_pair() creates a pair object from two values
    - Adds current bar's information to stack

14. while (!st.empty())
    - Processes remaining elements in stack after main loop
    - These represent bars that weren't popped during main processing

15. int area = height * (heights.size() - index);
    - Calculates area for remaining bars
    - Width extends to end of histogram: total_length - start_position
    - heights.size() gives total number of bars

=== KEY C++ CONCEPTS USED ===

- Vector: Dynamic array with size(), [] access, and automatic memory management
- Stack: LIFO container with push(), pop(), top(), empty() operations
- Pair: Container holding exactly two values, accessed via .first and .second
- References (&): Allow functions to modify original data without copying
- Iterators: Objects pointing to container positions (used internally by size())
- Max function: Standard library utility to find maximum of two values
- Make_pair: Utility function to create pair objects easily

=== ALGORITHM VISUALIZATION EXAMPLE ===

Consider heights = [2, 1, 5, 6, 2, 3]

Step-by-step execution:
1. i=0, h=2: Stack empty, push (0,2)
   Stack: [(0,2)]

2. i=1, h=1: Stack top height=2 > 1, so pop and calculate
   Area = 2 * (1-0) = 2, start=0
   Push (0,1)
   Stack: [(0,1)]

3. i=2, h=5: Stack top height=1 < 5, push (2,5)
   Stack: [(0,1), (2,5)]

4. i=3, h=6: Stack top height=5 < 6, push (3,6)
   Stack: [(0,1), (2,5), (3,6)]

5. i=4, h=2: Stack top height=6 > 2, pop and calculate
   Area = 6 * (4-3) = 6, start=3
   Stack top height=5 > 2, pop and calculate
   Area = 5 * (4-2) = 10, start=2
   Push (2,2)
   Stack: [(0,1), (2,2)]

6. i=5, h=3: Stack top height=2 < 3, push (5,3)
   Stack: [(0,1), (2,2), (5,3)]

7. Process remaining stack:
   - (5,3): Area = 3 * (6-5) = 3
   - (2,2): Area = 2 * (6-2) = 8
   - (0,1): Area = 1 * (6-0) = 6

Maximum area found: 10

The algorithm efficiently finds that the largest rectangle has area 10
(height=5, width=2, spanning indices 2-3 in the original histogram).
*/
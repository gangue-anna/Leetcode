#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /**
         * Search for target in a 2D matrix with special properties:
         * - Each row is sorted in ascending order
         * - First integer of each row > last integer of previous row
         * - Effectively, the entire matrix can be viewed as one sorted array
         * 
         * Approach - Two Binary Searches:
         * 1. First binary search: Find the correct row where target could exist
         *    - Compare target with first and last elements of middle row
         *    - If target > last element: search lower rows (target is too big for current row)
         *    - If target < first element: search upper rows (target is too small for current row)
         *    - Otherwise: target could be in this row, break and search within row
         * 
         * 2. Second binary search: Search within the identified row
         *    - Standard binary search within the row to find exact target
         * 
         * Time Complexity: O(log m + log n) = O(log(mn))
         *   - First binary search: O(log m) where m = number of rows
         *   - Second binary search: O(log n) where n = number of columns
         *   - Since the matrix has mn elements total, this equals O(log(mn))
         * 
         * Space Complexity: O(1) - only uses constant extra space for pointers
         */
        
        int rows = matrix.size();           // Number of rows in matrix
        int cols = matrix[0].size();        // Number of columns in matrix
        
        // Phase 1: Binary search to find the correct row
        int top = 0;                        // Top boundary for row search
        int bot = rows - 1;                 // Bottom boundary for row search
        
        while (top <= bot) {
            int row = top + (bot - top) / 2; // Middle row (avoiding overflow)
            
            // If target is greater than last element of middle row
            // Target must be in a lower row (if it exists)
            if (target > matrix[row][cols - 1]) {
                top = row + 1;
            }
            // If target is less than first element of middle row  
            // Target must be in an upper row (if it exists)
            else if (target < matrix[row][0]) {
                bot = row - 1;
            }
            // Target could be in this row (target >= first element && target <= last element)
            else {
                break;
            }
        }
        
        // Check if we found a valid row
        if (!(top <= bot)) {
            return false;  // No valid row found, target doesn't exist
        }
        
        // Phase 2: Binary search within the identified row
        int row = top + (bot - top) / 2;    // The row where target could be
        int left = 0;                       // Left boundary for column search
        int right = cols - 1;               // Right boundary for column search
        
        while (left <= right) {
            int mid = left + (right - left) / 2;  // Middle column
            
            // If target is greater than middle element, search right half
            if (target > matrix[row][mid]) {
                left = mid + 1;
            }
            // If target is less than middle element, search left half
            else if (target < matrix[row][mid]) {
                right = mid - 1;
            }
            // Target found!
            else {
                return true;
            }
        }
        
        // Target not found in the identified row
        return false;
    }
};

/*
=== C++ SYNTAX EXPLANATION FOR BEGINNERS ===

1. bool searchMatrix(vector<vector<int>>& matrix, int target)
   - Function returns bool (boolean: true or false)
   - vector<vector<int>>& matrix: reference to 2D vector (matrix)
   - vector<vector<int>> means "vector of vectors of integers"
   - & makes it a reference to avoid copying the entire matrix
   - int target: the value we're searching for

2. int rows = matrix.size();
   - matrix.size() returns number of rows (outer vector size)
   - Assigns this value to integer variable 'rows'
   - size() method returns the number of elements in a vector

3. int cols = matrix[0].size();
   - matrix[0] accesses the first row (vector at index 0)
   - .size() on that row gives number of columns
   - Assumes matrix is not empty and all rows have same number of columns

4. int top = 0;
   - Declares integer variable 'top' and initializes to 0
   - Represents the upper boundary of our search range for rows

5. int bot = rows - 1;
   - 'bot' represents bottom boundary (last valid row index)
   - rows - 1 because indices start from 0, so last index is size - 1

6. while (top <= bot)
   - Continue loop while there's a valid search range
   - When top > bot, we've exhausted all possibilities

7. int row = top + (bot - top) / 2;
   - Calculates middle row index
   - Equivalent to (top + bot) / 2 but avoids potential integer overflow
   - Integer division automatically truncates decimal part

8. if (target > matrix[row][cols - 1])
   - matrix[row][cols - 1] accesses last element of row 'row'
   - [row] selects the row, [cols - 1] selects last column in that row
   - cols - 1 because last column index is (number of columns - 1)

9. else if (target < matrix[row][0])
   - matrix[row][0] accesses first element of row 'row'
   - [row] selects the row, [0] selects first column (index 0)

10. else { break; }
    - else handles the case where target could be in current row
    - break statement immediately exits the while loop
    - Used when we found the correct row and want to stop searching

11. if (!(top <= bot))
    - ! is the logical NOT operator
    - !(top <= bot) is equivalent to (top > bot)
    - Checks if the search failed to find a valid row

12. return false;
    - Immediately exits function and returns the boolean value false
    - Indicates target was not found

13. int left = 0, right = cols - 1;
    - Declares two integer variables in one statement
    - left initialized to 0, right initialized to cols - 1
    - These are boundaries for searching within a row

14. int mid = left + (right - left) / 2;
    - Calculates middle column index within the current row
    - Same overflow-safe formula as used for row calculation

15. if (target > matrix[row][mid])
    - matrix[row][mid] accesses element at row 'row', column 'mid'
    - Double indexing: first [] selects row, second [] selects column

16. left = mid + 1;
    - Updates left boundary to exclude middle and search right half
    - mid + 1 because we know target is not at mid

17. right = mid - 1;
    - Updates right boundary to exclude middle and search left half
    - mid - 1 because we know target is not at mid

18. return true;
    - Returns boolean true when target is found
    - Immediately exits function

=== KEY C++ CONCEPTS USED ===

- 2D Vector: vector<vector<int>> represents a matrix/2D array
- Double Indexing: matrix[row][col] to access specific element
- Boolean Type: bool can be true or false
- References: & parameter avoids copying large data structures
- Logical Operators: ! (NOT), && (AND), || (OR)
- Control Flow: while loops, if/else if/else, break statement
- Integer Division: Automatic truncation of decimal part
- Method Chaining: matrix[0].size() calls size() on the first row

=== ALGORITHM VISUALIZATION EXAMPLE ===

Consider matrix = [[1,4,7,11], [2,5,8,12], [3,6,9,16], [10,13,14,17]]
Searching for target = 5

Matrix visualization:
Row 0: [1,  4,  7,  11]
Row 1: [2,  5,  8,  12] 
Row 2: [3,  6,  9,  16]
Row 3: [10, 13, 14, 17]

Phase 1 - Find correct row:
Initial: top = 0, bot = 3

Iteration 1: 
- row = (0 + 3) / 2 = 1
- target = 5, matrix[1][3] = 12, matrix[1][0] = 2
- 5 <= 12 and 5 >= 2, so target could be in row 1
- Break out of loop

Phase 2 - Search within row 1: [2, 5, 8, 12]
Initial: left = 0, right = 3

Iteration 1:
- mid = (0 + 3) / 2 = 1  
- matrix[1][1] = 5, target = 5
- Found! Return true

Total comparisons: 2 (much better than checking all 16 elements!)

=== WHY THIS APPROACH IS EFFICIENT ===

Naive approach: Check every element
- Time: O(mn) where m = rows, n = columns
- For 1000x1000 matrix: up to 1,000,000 comparisons

Binary search approach: Two binary searches  
- Time: O(log m + log n) = O(log(mn))
- For 1000x1000 matrix: at most 10 + 10 = 20 comparisons

The key insight: The matrix properties allow us to treat it as a 
conceptually "flattened" sorted array and use binary search twice
instead of searching linearly through each element.
*/
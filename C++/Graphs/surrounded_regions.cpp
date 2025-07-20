#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Surrounded Regions Problem (LeetCode 130)
     * 
     * PROBLEM: Capture all regions of 'O' that are 4-directionally surrounded by 'X'.
     * A region is captured by flipping all 'O's in that region to 'X'.
     * 
     * APPROACH:
     * Instead of finding surrounded regions directly (which is complex), we find 
     * UNSURROUNDED regions and preserve them, then capture everything else.
     * 
     * Algorithm:
     * 1. Find all 'O's connected to the border (these are NOT surrounded)
     * 2. Mark these unsurrounded 'O's as temporary 'T' using DFS
     * 3. Convert all remaining 'O's to 'X' (these are surrounded)
     * 4. Convert all 'T's back to 'O' (restore unsurrounded regions)
     * 
     * Why this works:
     * - Any 'O' connected to a border 'O' cannot be surrounded
     * - By marking these first, we identify what NOT to capture
     * - Everything else can be safely captured
     * 
     * TIME COMPLEXITY: O(m * n)
     * - Each cell is visited at most once during DFS traversal
     * - Three passes through the entire board: O(m * n) each
     * - Total: O(m * n)
     * 
     * SPACE COMPLEXITY: O(m * n)
     * - Recursion stack depth in worst case (when entire board is 'O'): O(m * n)
     * - No additional data structures used
     */
    void solve(vector<vector<char>>& board) {
        // Handle edge cases
        if (board.empty() || board[0].empty()) {
            return;
        }
        
        int rows = board.size();        // Get number of rows
        int cols = board[0].size();     // Get number of columns
        
        // Step 1: Find and mark all unsurrounded 'O's (connected to border)
        // Check all border cells and start DFS from border 'O's
        
        // Check top and bottom rows
        for (int c = 0; c < cols; c++) {
            // Top row
            if (board[0][c] == 'O') {
                capture(board, 0, c, rows, cols);
            }
            // Bottom row  
            if (board[rows - 1][c] == 'O') {
                capture(board, rows - 1, c, rows, cols);
            }
        }
        
        // Check left and right columns
        for (int r = 0; r < rows; r++) {
            // Left column
            if (board[r][0] == 'O') {
                capture(board, r, 0, rows, cols);
            }
            // Right column
            if (board[r][cols - 1] == 'O') {
                capture(board, r, cols - 1, rows, cols);
            }
        }
        
        // Step 2: Capture all surrounded regions (remaining 'O's -> 'X')
        // Step 3: Restore unsurrounded regions ('T' -> 'O')
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';    // Surrounded 'O' becomes 'X'
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O';    // Unsurrounded 'T' becomes 'O'
                }
            }
        }
    }
    
private:
    /**
     * DFS helper function to mark unsurrounded regions
     * 
     * @param board: Reference to the game board
     * @param r: Current row position
     * @param c: Current column position  
     * @param rows: Total number of rows
     * @param cols: Total number of columns
     * 
     * This function marks all 'O's connected to the current position as 'T'
     * (temporary marker for unsurrounded regions)
     */
    void capture(vector<vector<char>>& board, int r, int c, int rows, int cols) {
        // Base cases for DFS termination:
        // 1. Out of bounds (row or column invalid)
        // 2. Current cell is not 'O' (already processed or is 'X')
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O') {
            return;
        }
        
        // Mark current 'O' as temporary 'T' (unsurrounded)
        board[r][c] = 'T';
        
        // Recursively explore all 4 directions
        capture(board, r + 1, c, rows, cols);  // Down
        capture(board, r - 1, c, rows, cols);  // Up
        capture(board, r, c + 1, rows, cols);  // Right  
        capture(board, r, c - 1, rows, cols);  // Left
    }
};

/*
DETAILED C++ SYNTAX EXPLANATION FOR BEGINNERS:

LINE-BY-LINE BREAKDOWN:

1. #include <bits/stdc++.h>
   - This is a non-standard header that includes most C++ standard library headers
   - Commonly used in competitive programming for convenience
   - In production code, you should include specific headers like <vector>, <iostream>, etc.

2. using namespace std;
   - Allows us to use standard library functions without "std::" prefix
   - Example: We can write "vector" instead of "std::vector"

3. class Solution {
   - Defines a class named "Solution"
   - Classes are blueprints for creating objects
   - Contains data members and member functions

4. public:
   - Access specifier meaning these members can be accessed from outside the class
   - Other access specifiers: private (only within class), protected (within class and derived classes)

5. void solve(vector<vector<char>>& board) {
   - Function declaration breakdown:
     * void: Return type (returns nothing)
     * solve: Function name
     * vector<vector<char>>: 2D vector of characters (dynamic 2D array)
     * &: Reference operator - avoids copying, works directly with original data
     * board: Parameter name

6. if (board.empty() || board[0].empty()) {
   - board.empty(): Checks if vector has zero elements
   - ||: Logical OR operator  
   - board[0]: Access first row of 2D vector
   - Checks if board is empty or first row is empty

7. return;
   - Early exit from void function (no value returned)
   - Used for edge case handling

8. int rows = board.size();
   - int: Integer data type
   - board.size(): Returns number of elements in vector (number of rows)
   - =: Assignment operator

9. for (int c = 0; c < cols; c++) {
   - C++ for loop syntax:
     * int c = 0: Initialize counter variable c to 0
     * c < cols: Condition to continue loop
     * c++: Increment c by 1 after each iteration (post-increment)

10. if (board[0][c] == 'O') {
    - board[0][c]: Access element at row 0, column c
    - ==: Equality comparison operator (not assignment!)
    - 'O': Character literal (single quotes for characters)

11. capture(board, 0, c, rows, cols);
    - Function call passing 5 arguments
    - board: Passed by reference (original data modified)
    - 0, c, rows, cols: Passed by value (copies of values)

12. } else if (board[r][c] == 'T') {
    - else if: Chain multiple conditions
    - Only executes if previous if condition was false

13. board[r][c] = 'X';
    - Assignment: Set board element at position [r][c] to character 'X'
    - =: Assignment operator (modifies the value)

14. private:
    - Access specifier: members only accessible within the same class
    - Helper functions are often private

15. void capture(vector<vector<char>>& board, int r, int c, int rows, int cols) {
    - Private helper function
    - Same syntax as public functions but only accessible within class

16. if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O') {
    - Multiple conditions with OR operators
    - <, >=: Comparison operators
    - !=: Not equal operator
    - This checks bounds and cell value in one condition

17. board[r][c] = 'T';
    - Direct assignment to 2D vector element
    - Modifies original board since passed by reference

18. capture(board, r + 1, c, rows, cols);
    - Recursive function call (function calls itself)
    - r + 1: Arithmetic expression for next row
    - Each recursive call explores a different direction

KEY C++ CONCEPTS USED:
- vector<T>: Dynamic array (can grow/shrink at runtime)
- 2D vector: vector<vector<T>> creates a matrix-like structure
- References (&): Avoids copying large objects, works with original data
- Recursion: Function calling itself with modified parameters
- Class structure: public/private members for encapsulation
- Character literals: 'O', 'X', 'T' (single quotes for characters)
- Bounds checking: Essential for preventing array access errors
- DFS traversal: Systematic exploration of connected components
*/
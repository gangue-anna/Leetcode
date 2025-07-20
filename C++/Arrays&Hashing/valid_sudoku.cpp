#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Validate if a Sudoku board is valid
     * 
     * Approach:
     * - Use hash sets to track numbers in each row, column, and 3x3 square
     * - Check each cell: if number exists in any set, board is invalid
     * - Otherwise add number to corresponding sets
     * 
     * Time Complexity: O(1) - board is fixed 9x9 size
     * Space Complexity: O(1) - sets store max 9 numbers each
     */
    bool isValidSudoku(vector<vector<char>>& board) {
        // Hash sets to store seen numbers for each row, column, and square
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> squares(9);
        
        // Check each cell in the board
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char curr = board[r][c];
                if (curr == '.') continue;
                
                // Calculate square index (0-8) from row and column
                int squ = (r/3) * 3 + (c/3);
                
                // Check if number already exists in any set
                if (rows[r].count(curr) || 
                    cols[c].count(curr) || 
                    squares[squ].count(curr)) {
                    return false;
                }
                
                // Add number to all three sets
                rows[r].insert(curr);
                cols[c].insert(curr);
                squares[squ].insert(curr);
            }
        }
        return true;
    }
};

/*
 * Detailed C++ Syntax Explanation:
 * 
 * 1. Vector of Sets:
 *    vector<unordered_set<char>> rows(9)
 *    - Creates 9 empty hash sets for rows/cols/squares
 *    - unordered_set provides O(1) lookup/insert
 * 
 * 2. Board Access:
 *    board[r][c]    // Access cell at row r, column c
 *    char curr      // Current cell value
 * 
 * 3. Set Operations:
 *    set.count(curr)   // Check if element exists (returns 0 or 1)
 *    set.insert(curr)  // Add element to set
 * 
 * 4. Square Index:
 *    (r/3) * 3 + (c/3)
 *    - Maps (r,c) to 0-8 index for squares
 *    - Integer division for block number
 */

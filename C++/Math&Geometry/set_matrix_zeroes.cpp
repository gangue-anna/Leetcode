#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
         * Approach:
         * 1️⃣ Use the first row and first column of the matrix itself as markers for rows & columns that should be zeroed.
         * 2️⃣ Use a separate boolean `rowZero` to remember if the first row itself should become all zeros.
         * 
         * First pass:
         * - Traverse the matrix.
         * - If any element is 0, mark its row and column by setting matrix[r][0] and matrix[0][c] to 0.
         * - Also check if the first row has any zero and record it in `rowZero`.
         *
         * Second pass:
         * - Traverse the matrix (excluding first row & column) and set matrix[r][c] to 0 if its row or column is marked.
         *
         * Finally:
         * - If matrix[0][0] == 0 → zero out the first column.
         * - If `rowZero` → zero out the first row.
         *
         * Time Complexity: O(m × n)
         * - Two passes over the matrix.
         *
         * Space Complexity: O(1)
         * - Uses only one extra variable `rowZero`.
         */

        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        bool rowZero = false;

        // First pass: mark rows and columns
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    if (r > 0) {
                        matrix[r][0] = 0;
                    } else {
                        rowZero = true;
                    }
                }
            }
        }

        // Second pass: zero cells based on markers
        for (int r = 1; r < ROWS; ++r) {
            for (int c = 1; c < COLS; ++c) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        // Zero first column if needed
        if (matrix[0][0] == 0) {
            for (int r = 0; r < ROWS; ++r) {
                matrix[r][0] = 0;
            }
        }

        // Zero first row if needed
        if (rowZero) {
            for (int c = 0; c < COLS; ++c) {
                matrix[0][c] = 0;
            }
        }
    }
};

/*
 * 📖 Line-by-line explanation:
 *
 * #include <bits/stdc++.h>               → Includes all standard C++ libraries.
 * using namespace std;                  → Allows direct use of std:: names.
 *
 * class Solution { … };                 → Defines the Solution class.
 *
 * void setZeroes(vector<vector<int>>& matrix)
 *                                       → Function that modifies matrix in-place.
 *
 * int ROWS = matrix.size();            → Get number of rows.
 * int COLS = matrix[0].size();         → Get number of columns.
 * bool rowZero = false;                → Flag to track if first row should be zeroed.
 *
 * First nested loop:                   → Iterate through every cell of the matrix.
 * if (matrix[r][c] == 0)              → If cell is 0:
 *   matrix[0][c] = 0;                → Mark the entire column to be zeroed.
 *   if (r > 0)                       → If not in the first row:
 *     matrix[r][0] = 0;            → Mark the entire row to be zeroed.
 *   else                            → If in the first row:
 *     rowZero = true;             → Remember to zero first row later.
 *
 * Second nested loop:                 → Process all cells except first row & column.
 * if (matrix[0][c] == 0 || matrix[r][0] == 0)
 *                                     → If this row or column is marked:
 *   matrix[r][c] = 0;              → Set this cell to 0.
 *
 * if (matrix[0][0] == 0)              → Check if first column needs to be zeroed:
 *   for each row: matrix[r][0] = 0;
 *
 * if (rowZero)                        → If first row needs to be zeroed:
 *   for each col: matrix[0][c] = 0;
 *
 */

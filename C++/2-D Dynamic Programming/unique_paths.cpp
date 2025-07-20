#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
            Problem:
            - Count the number of unique paths from top-left to bottom-right in an m x n grid.
            - You can only move either down or right.

            Approach:
            - Use dynamic programming with space optimization.
            - We only need to keep track of the current row and the row below it.
            - Start with the bottom row initialized to 1s.
            - Work our way up the grid by filling each row based on the values from the row below and the cell to the right.

            Time Complexity: O(m * n)
                - We visit every cell exactly once.

            Space Complexity: O(n)
                - Only two rows of size n are used.
        */

        vector<int> row(n, 1);  // Initialize the bottom row with 1s (only one path to each cell in bottom row)

        // Iterate from the second-to-last row to the top row
        for (int i = 0; i < m - 1; i++) {
            vector<int> newRow(n, 1);  // Start a new row with 1s

            // Fill the row from right to left (excluding last column)
            for (int j = n - 2; j >= 0; j--) {
                // Current cell = paths from the right + paths from the cell below
                newRow[j] = newRow[j + 1] + row[j];
            }

            row = newRow;  // Move up: current row becomes the previous row
        }

        return row[0];  // Top-left corner value is the answer
    }
};

/*
================ LINE-BY-LINE SYNTAX EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ headers (vector, iostream, etc.)

using namespace std;
    - Allows you to use standard library names (like vector) without prefixing with std::.

class Solution {
    - Defines a class named Solution.

public:
    - Public access modifier. Makes the following methods accessible from outside the class.

int uniquePaths(int m, int n)
    - Function returns an integer and takes two integers (rows and columns) as input.

vector<int> row(n, 1);
    - Creates a vector of size n initialized with all elements as 1.

for (int i = 0; i < m - 1; i++)
    - Loop over each row from bottom to top (excluding bottom row already initialized).

vector<int> newRow(n, 1);
    - Creates a new vector for the current row, initialized with 1.

for (int j = n - 2; j >= 0; j--)
    - Loop over each cell in the current row from right to left, skipping the last column.

newRow[j] = newRow[j + 1] + row[j];
    - Update the current cell as the sum of right cell and the cell below.

row = newRow;
    - Assign the newly computed row to be the "previous" row for the next iteration.

return row[0];
    - Return the number of unique paths starting from the top-left corner.

*/

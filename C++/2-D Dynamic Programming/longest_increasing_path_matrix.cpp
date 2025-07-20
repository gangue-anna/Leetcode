#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        /*
            Approach:
            - Use DFS with memoization (DP) to explore all increasing paths.
            - From each cell, try moving in all 4 directions if the next cell is greater.
            - Memoize the result of each cell to avoid recomputation.
            - Time: O(m * n)
            - Space: O(m * n) (DP table + recursion stack)
        */

        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0)); // DP table to memoize results
        int maxLen = 0;

        // Helper lambda for DFS
        function<int(int, int)> dfs = [&](int r, int c) {
            if (dp[r][c] != 0) return dp[r][c]; // Already computed

            int length = 1; // Minimum path length is 1 (the cell itself)

            vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
            for (auto &dir : directions) {
                int dr = dir.first, dc = dir.second;
                int nr = r + dr, nc = c + dc;
                 if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    matrix[nr][nc] > matrix[r][c]) {
                    length = max(length, 1 + dfs(nr, nc));
                }
            }


            dp[r][c] = length;
            return dp[r][c];
        };

        // Start DFS from every cell
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                maxLen = max(maxLen, dfs(r, c));
            }
        }

        return maxLen;
    }
};

/*
=================== LINE-BY-LINE EXPLANATION ===================

#include <bits/stdc++.h>
    - Includes all standard C++ libraries (vector, string, algorithm, etc.)

using namespace std;
    - Allows using standard library names (like vector, cout) without 'std::' prefix.

class Solution {
    - Defines a class named Solution.

public:
    - Public section of the class (accessible from outside).

int longestIncreasingPath(vector<vector<int>>& matrix)
    - Function that returns the length of longest increasing path.
    - Takes a 2D vector (matrix) of integers by reference as input.

if (matrix.empty() || matrix[0].empty()) return 0;
    - If matrix is empty or has no columns, return 0 immediately.

int rows = matrix.size(), cols = matrix[0].size();
    - rows: number of rows in matrix
    - cols: number of columns in matrix

vector<vector<int>> dp(rows, vector<int>(cols, 0));
    - 2D DP table initialized with zeros.
    - dp[r][c] stores the longest increasing path starting from cell (r,c).

int maxLen = 0;
    - Variable to keep track of maximum path length found.

function<int(int, int)> dfs = [&](int r, int c) { ... };
    - Defines a lambda function named dfs for recursive DFS.
    - Takes current row (r) and column (c) as input.
    - [&] means it captures variables by reference.

if (dp[r][c] != 0) return dp[r][c];
    - If result for cell (r,c) is already computed, return it.

int length = 1;
    - Start with path length of 1 (the cell itself).

vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    - Defines 4 possible moves: down, up, right, left.

for (auto [dr, dc] : directions) { ... }
    - For each direction, compute next cell (nr, nc).

if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] > matrix[r][c])
    - Check if next cell is inside bounds and has a greater value.

length = max(length, 1 + dfs(nr, nc));
    - Update maximum length by exploring next cell.

dp[r][c] = length;
    - Save the computed result in dp table.

for (int r = 0; r < rows; ++r)
    - Loop through each row.

for (int c = 0; c < cols; ++c)
    - Loop through each column.

maxLen = max(maxLen, dfs(r, c));
    - Compute longest path starting at (r,c) and update maxLen.

return maxLen;
    - Return the longest increasing path length found.
*/


#include <bits/stdc++.h>
using namespace std;

/**
 * Approach:
 * - Perform DFS starting from every cell in the board.
 * - At each cell, check if the current letter matches the word[i].
 * - Mark the cell as visited and explore in all 4 directions.
 * - Backtrack by unmarking the cell if the path does not lead to a solution.
 *
 * Time Complexity: O(m * n * 4^L), where m = rows, n = cols, L = word.length()
 * Space Complexity: O(L), for recursion stack and path tracking.
 */

class Solution {
public:
    int ROWS, COLS;

    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int i) {
        if (i == word.size()) return true;  // word is completely matched

        // If out of bounds or mismatch or already visited
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != word[i]) {
            return false;
        }

        char temp = board[r][c]; // save the original character
        board[r][c] = '#';       // mark as visited

        // Explore in all 4 directions
        bool found =
            dfs(board, word, r + 1, c, i + 1) ||
            dfs(board, word, r - 1, c, i + 1) ||
            dfs(board, word, r, c + 1, i + 1) ||
            dfs(board, word, r, c - 1, i + 1);

        board[r][c] = temp;      // backtrack: restore the original character
        return found;
    }
};

/*
------------------------------------------------------
📄 Line-by-Line C++ Syntax Explanation:
------------------------------------------------------

#include <bits/stdc++.h>
    → Includes all standard C++ libraries (vector, string, iostream, etc.) in one line.

using namespace std;
    → So we don’t need to prefix std:: before every type.

class Solution { ... };
    → Defines a class named Solution.

int ROWS, COLS;
    → Member variables to store board dimensions.

bool exist(vector<vector<char>>& board, string word)
    → Public method that checks if the word exists in the board.

board.size()
    → Number of rows in the board.

board[0].size()
    → Number of columns in the board.

for (int r = 0; r < ROWS; r++) { ... }
    → Iterate through each row.

for (int c = 0; c < COLS; c++) { ... }
    → Iterate through each column.

if (dfs(board, word, r, c, 0)) { return true; }
    → Start DFS from each cell; if word is found, return true.

return false;
    → If no path found after all cells, return false.

bool dfs(vector<vector<char>>& board, string& word, int r, int c, int i)
    → Private recursive helper function for DFS.

if (i == word.size()) return true;
    → Base case: matched entire word.

if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != word[i])
    → If out of bounds or mismatch, return false.

char temp = board[r][c];
    → Save current cell value.

board[r][c] = '#';
    → Mark the cell as visited.

bool found = dfs(...) || dfs(...) || dfs(...) || dfs(...);
    → Explore all four directions.

board[r][c] = temp;
    → Restore cell’s original value for backtracking.

return found;
    → Return true if word found along this path.
------------------------------------------------------

⏱ Complexity:
- Time: O(m * n * 4^L), where m = rows, n = cols, L = word.length()
- Space: O(L), maximum depth of recursion stack.
------------------------------------------------------
*/


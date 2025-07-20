#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // sets to keep track of columns and diagonals under attack
        unordered_set<int> cols;
        unordered_set<int> posDiag; // r + c
        unordered_set<int> negDiag; // r - c

        vector<vector<string>> res; // to store the final results
        vector<string> board(n, string(n, '.')); // initialize empty board

        // helper function for backtracking
        function<void(int)> backtrack = [&](int r) {
            if (r == n) {
                res.push_back(board); // if all rows are filled, save the board
                return;
            }

            for (int c = 0; c < n; ++c) {
                // if this position is attacked, skip
                if (cols.count(c) || posDiag.count(r + c) || negDiag.count(r - c))
                    continue;

                // place the queen
                cols.insert(c);
                posDiag.insert(r + c);
                negDiag.insert(r - c);
                board[r][c] = 'Q';

                backtrack(r + 1); // move to next row

                // backtrack: remove queen and mark cell as empty again
                cols.erase(c);
                posDiag.erase(r + c);
                negDiag.erase(r - c);
                board[r][c] = '.';
            }
        };

        backtrack(0); // start from row 0
        return res;
    }
};

/*
=====================================
Time Complexity:
-------------------------------------
- In the worst case, the algorithm explores all possible ways to place `n` queens.
- First row has `n` choices, second row ≤ (n-1), third row ≤ (n-2), … 
- Total number of configurations explored in the worst case is roughly `n!` (factorial).
- Therefore: **O(n!)**

Space Complexity:
-------------------------------------
- Board: O(n^2) to store the board (`vector<string>`).
- Result: Can be up to O(n!) * O(n) because there can be up to `n!` solutions and each takes O(n) space.
- Auxiliary data (cols, posDiag, negDiag, recursion stack): O(n).
- Overall: **O(n^2 + n! * n)**

=====================================
Line-by-line Explanation:
-------------------------------------
#include <bits/stdc++.h>
- Includes all standard C++ libraries.

using namespace std;
- Avoids writing std:: repeatedly.

class Solution {
- Defines the Solution class.

vector<vector<string>> solveNQueens(int n) {
- Public method that returns all solutions to the n-queens problem.

unordered_set<int> cols;
- Tracks which columns already have queens.

unordered_set<int> posDiag;
- Tracks positive diagonals (r + c).

unordered_set<int> negDiag;
- Tracks negative diagonals (r - c).

vector<vector<string>> res;
- Stores all valid board configurations.

vector<string> board(n, string(n, '.'));
- Initializes the chess board with '.' (empty).

function<void(int)> backtrack = [&](int r) {
- Defines a recursive lambda function to backtrack starting from row r.

if (r == n) {
- If we've placed queens in all rows, save the board.

for (int c = 0; c < n; ++c) {
- Try all columns in the current row.

if (cols.count(c) || posDiag.count(r + c) || negDiag.count(r - c))
- Skip if column or diagonal is under attack.

cols.insert(c);
posDiag.insert(r + c);
negDiag.insert(r - c);
board[r][c] = 'Q';
- Place queen and mark the column and diagonals.

backtrack(r + 1);
- Recurse to the next row.

cols.erase(c);
posDiag.erase(r + c);
negDiag.erase(r - c);
board[r][c] = '.';
- Backtrack: remove the queen and unmark.

};

backtrack(0);
- Start the backtracking from row 0.

return res;
- Return all solutions.

};
-------------------------------------
*/

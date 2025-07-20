#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*
         * Approach:
         * - Use four pointers to track the current boundaries: left, right, top, bottom
         * - Traverse in spiral order:
         *   → Right: top row (left → right), then move top boundary down
         *   ↓ Down: right column (top → bottom), then move right boundary left
         *   ← Left: bottom row (right → left), then move bottom boundary up
         *   ↑ Up: left column (bottom → top), then move left boundary right
         * - Repeat until all elements are visited.
         *
         * Time Complexity: O(m × n), where m = rows, n = columns
         * - Each element is visited exactly once.
         *
         * Space Complexity: O(1) (excluding the output array)
         * - Only a constant number of pointers are used.
         */

        vector<int> res;

        if (matrix.empty()) return res;

        int left = 0, right = matrix[0].size();   // left and right boundaries
        int top = 0, bottom = matrix.size();      // top and bottom boundaries

        while (left < right && top < bottom) {
            // Traverse top row (left → right)
            for (int i = left; i < right; ++i) {
                res.push_back(matrix[top][i]);
            }
            ++top;  // move top boundary down

            // Traverse right column (top → bottom)
            for (int i = top; i < bottom; ++i) {
                res.push_back(matrix[i][right - 1]);
            }
            --right;  // move right boundary left

            // Check if there are elements left
            if (!(left < right && top < bottom)) break;

            // Traverse bottom row (right → left)
            for (int i = right - 1; i >= left; --i) {
                res.push_back(matrix[bottom - 1][i]);
            }
            --bottom;  // move bottom boundary up

            // Traverse left column (bottom → top)
            for (int i = bottom - 1; i >= top; --i) {
                res.push_back(matrix[i][left]);
            }
            ++left;  // move left boundary right
        }

        return res;
    }
};

/*
 * Line-by-line explanation:
 *
 * #include <bits/stdc++.h>                     → Includes all standard C++ libraries.
 * using namespace std;                        → Allows using std library symbols without prefix.
 *
 * class Solution { … };                       → Defines the Solution class.
 *
 * vector<int> spiralOrder(vector<vector<int>>& matrix)
 *                                             → Function that returns the elements in spiral order.
 *
 * vector<int> res;                            → To store the result.
 *
 * if (matrix.empty()) return res;            → Edge case: if matrix is empty, return empty result.
 *
 * int left = 0, right = matrix[0].size();    → Initialize left & right boundaries.
 * int top = 0, bottom = matrix.size();       → Initialize top & bottom boundaries.
 *
 * while (left < right && top < bottom) {    → While there are elements to process:
 *
 * for (int i = left; i < right; ++i)       → Traverse top row from left to right.
 * res.push_back(matrix[top][i]);          → Add each element to result.
 * ++top;                                  → Move top boundary down.
 *
 * for (int i = top; i < bottom; ++i)     → Traverse right column from top to bottom.
 * res.push_back(matrix[i][right-1]);    → Add each element.
 * --right;                              → Move right boundary left.
 *
 * if (!(left < right && top < bottom)) break; → Check if there are still layers left.
 *
 * for (int i = right-1; i >= left; --i) → Traverse bottom row from right to left.
 * res.push_back(matrix[bottom-1][i]);
 * --bottom;                             → Move bottom boundary up.
 *
 * for (int i = bottom-1; i >= top; --i) → Traverse left column from bottom to top.
 * res.push_back(matrix[i][left]);
 * ++left;                               → Move left boundary right.
 *
 * return res;                           → Return the result.
 *
 */

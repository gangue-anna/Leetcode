#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
         * Approach:
         * - Rotate the matrix layer by layer (outermost to innermost).
         * - For each layer, rotate 4 elements at a time in a cycle.
         * - Swap: top-left → bottom-left → bottom-right → top-right → top-left.
         *
         * Time Complexity: O(n^2), where n = matrix.size()
         * - Every element is moved exactly once.
         *
         * Space Complexity: O(1)
         * - In-place rotation using a temporary variable.
         */

        int l = 0;                    // left boundary of current layer
        int r = matrix.size() - 1;   // right boundary of current layer

        while (l < r) {
            // Rotate elements in the current layer
            for (int i = 0; i < r - l; ++i) {
                int top = l;         // top boundary
                int bottom = r;      // bottom boundary

                // Save the top-left element
                int topLeft = matrix[top][l + i];

                // Move bottom-left → top-left
                matrix[top][l + i] = matrix[bottom - i][l];

                // Move bottom-right → bottom-left
                matrix[bottom - i][l] = matrix[bottom][r - i];

                // Move top-right → bottom-right
                matrix[bottom][r - i] = matrix[top + i][r];

                // Move saved top-left → top-right
                matrix[top + i][r] = topLeft;
            }

            // Move to next inner layer
            ++l;
            --r;
        }
    }
};

/*
 * Line-by-line explanation of the syntax:
 *
 * #include <bits/stdc++.h>                      → Includes all standard C++ headers.
 * using namespace std;                         → So we can use standard library names without std::.
 *
 * class Solution { … };                        → Defines the Solution class.
 *
 * void rotate(vector<vector<int>>& matrix) {   → Method to rotate the matrix, passed by reference.
 *
 * int l = 0, r = matrix.size() - 1;           → Initialize left (l) and right (r) pointers for layers.
 *
 * while (l < r) {                             → Process layers until l and r meet.
 *
 * for (int i = 0; i < r - l; ++i) {          → Iterate through elements in the current layer.
 *
 * int top = l, bottom = r;                   → Set top and bottom boundaries of current layer.
 *
 * int topLeft = matrix[top][l + i];         → Save the top-left element in a temp variable.
 *
 * matrix[top][l + i] = matrix[bottom - i][l];
 *                                             → Move bottom-left into top-left.
 *
 * matrix[bottom - i][l] = matrix[bottom][r - i];
 *                                             → Move bottom-right into bottom-left.
 *
 * matrix[bottom][r - i] = matrix[top + i][r];
 *                                             → Move top-right into bottom-right.
 *
 * matrix[top + i][r] = topLeft;             → Place saved top-left into top-right.
 *
 * ++l; --r;                                 → Move to next inner layer.
 *
 * }
 *
 */


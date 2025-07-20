#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Function to compute the minimum number of jumps to reach the last index.
     *
     * Approach:
     * - Use a greedy sliding window approach.
     * - At each "jump", explore all positions in the current window [l, r].
     * - Find the farthest position reachable from any point in this window.
     * - Move to the next window [r+1, farthest] and increment jump count.
     * - Repeat until `r` >= last index.
     *
     * Time Complexity: O(N) — we iterate over the array at most once.
     * Space Complexity: O(1) — constant extra space.
     */
    int jump(vector<int>& nums) {
        int res = 0;               // Number of jumps
        int l = 0, r = 0;         // Current window [l, r]

        while (r < nums.size() - 1) {
            int farthest = 0;     // Farthest position reachable in current jump

            // Explore all positions in the current window
            for (int i = l; i <= r; ++i) {
                farthest = max(farthest, i + nums[i]);
            }

            l = r + 1;            // Move left boundary to next position after r
            r = farthest;        // Move right boundary to the farthest reachable
            ++res;               // Increment jump count
        }

        return res;
    }
};

/*
====================================================
Line-by-line C++ syntax explanation:
====================================================

#include <bits/stdc++.h>
    -> Includes all standard C++ libraries (like <vector>, <string>, <iostream>, etc.)

using namespace std;
    -> Allows using standard library names (like vector, string) without std:: prefix.

class Solution {
public:
    -> Defines a class named Solution with public member functions.

int jump(vector<int>& nums) {
    -> Defines a method `jump` that takes a reference to a vector of integers and returns an int.

int res = 0;
    -> Initialize `res` to 0. This will store the number of jumps.

int l = 0, r = 0;
    -> `l` and `r` define the current window [l, r] we are exploring.

while (r < nums.size() - 1) {
    -> Loop until the right boundary `r` reaches or passes the last index.

int farthest = 0;
    -> Variable to track the farthest position we can reach in the current jump.

for (int i = l; i <= r; ++i) {
    -> Iterate over all indices in the current window [l, r].

farthest = max(farthest, i + nums[i]);
    -> Update `farthest` if `i + nums[i]` is farther.

l = r + 1;
    -> Move the left boundary to just after the current right boundary.

r = farthest;
    -> Move the right boundary to the farthest reachable index.

++res;
    -> Increment the number of jumps.

return res;
    -> Return the minimum number of jumps to reach the end.

====================================================
Time Complexity:
    - O(N): Each element is visited at most once.

Space Complexity:
    - O(1): Uses only a few integer variables regardless of input size.
====================================================
*/


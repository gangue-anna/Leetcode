#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Function to determine if you can reach the last index starting from index 0.
     *
     * Approach:
     * - Start from the end of the array.
     * - At each index, check if you can reach the current `goal` from there.
     * - If yes, update `goal` to current index.
     * - If at the end `goal == 0`, then you can reach the last index.
     *
     * Time Complexity: O(N) — traverse the array once.
     * Space Complexity: O(1) — uses only constant extra space.
     */
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;  // Initialize goal as the last index

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (i + nums[i] >= goal) {
                // If you can reach `goal` from index `i`, update goal
                goal = i;
            }
        }

        // If goal has been moved to index 0, return true
        return goal == 0;
    }
};

/*
====================================================
Line-by-line C++ syntax explanation:
====================================================

#include <bits/stdc++.h>
    -> Includes all standard C++ libraries (like <vector>, <string>, <iostream>, etc.)

using namespace std;
    -> Allows using standard library names (like vector, string) without prefixing them with std::

class Solution {
public:
    -> Defines a class named Solution with public member functions.

bool canJump(vector<int>& nums) {
    -> Defines a method `canJump` that takes a reference to a vector of integers and returns a bool.

int goal = nums.size() - 1;
    -> Initializes `goal` to the last index of the array.

for (int i = nums.size() - 1; i >= 0; --i) {
    -> Loop from the last index down to index 0.

if (i + nums[i] >= goal) {
    -> If you can reach `goal` from index `i`, update `goal` to `i`.

goal = i;
    -> Updates `goal` to the current index.

return goal == 0;
    -> If `goal` reaches 0, it means you can reach the end starting from 0.

====================================================
Time Complexity:
    - O(N): Iterates over the array exactly once.

Space Complexity:
    - O(1): Only uses a single integer variable `goal`.

====================================================
*/


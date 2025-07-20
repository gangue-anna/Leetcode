#include <bits/stdc++.h>
using namespace std;

/**
 * Approach:
 * - Use DFS (backtracking) to explore all possible combinations.
 * - At each step, decide:
 *      - include `nums[i]` and stay at `i` (since we can reuse the number),
 *      - or skip `nums[i]` and move to `i+1`.
 * - If the running sum equals the target → save this combination.
 * - If the running sum > target or index is out of bounds → backtrack.
 *
 * Time Complexity:
 *   - O(2^(t/m)), where t = target, m = smallest number in nums.
 *   - Because at each step we can either include or skip a number, and can reuse it.
 * Space Complexity:
 *   - O(target / min(nums)) → recursion depth.
 *   - Plus storage for the result.
 */

class Solution {
public:
    vector<vector<int>> res;         // Stores all valid combinations

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;           // Current combination being built
        dfs(0, nums, target, curr, 0);
        return res;
    }

    void dfs(int i, vector<int>& nums, int target, vector<int>& curr, int total) {
        if (total == target) {
            res.push_back(curr);   // Found a valid combination
            return;
        }
        if (i >= nums.size() || total > target) {
            return;                // Out of bounds or exceeded target → backtrack
        }

        // Include nums[i] and stay at `i` (since we can reuse it)
        curr.push_back(nums[i]);
        dfs(i, nums, target, curr, total + nums[i]);
        curr.pop_back();           // Backtrack

        // Exclude nums[i] and move to next
        dfs(i + 1, nums, target, curr, total);
    }
};

/*
-----------------------------------------------
📄 Line-by-Line C++ Syntax Explanation:
-----------------------------------------------

#include <bits/stdc++.h>
    → Includes all standard C++ headers in one line.

using namespace std;
    → Avoids writing std:: before vector, cout, etc.

class Solution { ... };
    → Defines a class named Solution.

vector<vector<int>> res;
    → A 2D vector to store all valid combinations.

vector<vector<int>> combinationSum(vector<int>& nums, int target)
    → Public method that starts the DFS and returns the result.

vector<int> curr;
    → Temporary vector to build the current combination.

dfs(0, nums, target, curr, 0);
    → Call the helper dfs starting at index 0, total = 0.

void dfs(int i, vector<int>& nums, int target, vector<int>& curr, int total)
    → Helper recursive function: explores combinations starting at index `i`.

if (total == target) { ... }
    → If we reach the target sum → save this combination.

res.push_back(curr);
    → Add current combination to result.

if (i >= nums.size() || total > target) { return; }
    → If we go past the last index or the sum exceeds target → backtrack.

curr.push_back(nums[i]);
    → Include nums[i] into current combination.

dfs(i, nums, target, curr, total + nums[i]);
    → Continue DFS keeping the same index (since reuse allowed).

curr.pop_back();
    → Backtrack by removing the last added number.

dfs(i + 1, nums, target, curr, total);
    → Explore path where we skip the current number.

-----------------------------------------------
⏱ Complexity:
- Time: O(2^(t/m)) → exponential.
- Space: O(depth of recursion + result size).

-----------------------------------------------
*/


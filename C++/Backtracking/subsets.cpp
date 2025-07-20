#include <bits/stdc++.h>
using namespace std;

/**
 * Approach:
 * - Use DFS (backtracking) to explore all subsets.
 * - At each index, decide whether to include nums[i] or not.
 * - When we reach the end of nums, we save the current subset.
 *
 * Time Complexity: O(2^n) → There are 2^n subsets.
 * Space Complexity: O(2^n * n) → Total size of result + recursion stack.
 */

class Solution {
public:
    vector<vector<int>> res;      // Stores all subsets
    vector<int> subset;           // Current subset being built

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }

    void dfs(int i, vector<int>& nums) {
        // If we've considered all elements, save the current subset
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }

        // Include nums[i] in the current subset
        subset.push_back(nums[i]);
        dfs(i + 1, nums);

        // Backtrack: remove nums[i] and explore the path without it
        subset.pop_back();
        dfs(i + 1, nums);
    }
};

/*
-----------------------------------------------
📄 Line-by-Line C++ Syntax Explanation:
-----------------------------------------------

#include <bits/stdc++.h>
    → Includes all standard C++ libraries (like vector, iostream, etc).

using namespace std;
    → Avoids writing std:: everywhere (so we can just write vector instead of std::vector).

class Solution { ... };
    → Defines a class named Solution.

vector<vector<int>> res;
    → A 2D vector to store all subsets.

vector<int> subset;
    → A vector to build the current subset during recursion.

vector<vector<int>> subsets(vector<int>& nums) { ... }
    → Public method to start the DFS and return all subsets.

dfs(0, nums);
    → Start DFS from index 0.

void dfs(int i, vector<int>& nums) { ... }
    → Private helper method that performs the DFS from index i.

if (i >= nums.size()) { ... }
    → If index is beyond the last element, we've formed a subset.

res.push_back(subset);
    → Add the current subset to the result.

subset.push_back(nums[i]);
    → Include nums[i] in the current subset.

dfs(i + 1, nums);
    → Recursively move to the next index.

subset.pop_back();
    → Backtrack by removing nums[i] from the current subset.

-----------------------------------------------
⏱ Time & Space:
- Time: O(2^n) → because each element has two choices: include or exclude.
- Space: O(2^n * n) → result + recursion stack.

-----------------------------------------------
*/


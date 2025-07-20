#include <bits/stdc++.h>
using namespace std;

/**
 * Approach:
 * - Sort the input array so duplicates are adjacent.
 * - Use backtracking to explore all subsets.
 * - At each step, decide to include the current number or not.
 * - If we choose to skip a number, skip all its duplicates to avoid duplicate subsets.
 *
 * Time Complexity: O(2^n), because each element can be included or not.
 * Space Complexity: O(2^n * n), for storing all subsets and recursion stack.
 */

class Solution {
public:
    vector<vector<int>> res; // To store all unique subsets

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to group duplicates together
        vector<int> subset;             // Current subset being built
        backtrack(0, nums, subset);
        return res;
    }

    void backtrack(int i, vector<int>& nums, vector<int>& subset) {
        if (i == nums.size()) {
            res.push_back(subset); // Base case: reached the end, add subset
            return;
        }

        // Include nums[i]
        subset.push_back(nums[i]);
        backtrack(i + 1, nums, subset);
        subset.pop_back(); // Backtrack

        // Skip duplicates
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        // Exclude nums[i] and move to next distinct number
        backtrack(i + 1, nums, subset);
    }
};

/*
------------------------------------------------------
📄 Line-by-Line C++ Syntax Explanation:
------------------------------------------------------

#include <bits/stdc++.h>
    → Includes all standard C++ libraries (vector, algorithm, etc.) in one line.

using namespace std;
    → So we don’t need to prefix std:: before every type.

class Solution { ... };
    → Defines a class named Solution.

vector<vector<int>> res;
    → 2D vector to store the resulting subsets.

vector<vector<int>> subsetsWithDup(vector<int>& nums)
    → Public function that takes a reference to a vector and returns all unique subsets.

sort(nums.begin(), nums.end());
    → Sort the input array so duplicates are next to each other.

vector<int> subset;
    → Temporary vector to hold the current subset being constructed.

backtrack(0, nums, subset);
    → Start recursive backtracking at index 0.

void backtrack(int i, vector<int>& nums, vector<int>& subset)
    → Recursive function to generate subsets.

if (i == nums.size()) { ... }
    → Base case: if we've processed all elements.

res.push_back(subset);
    → Add the current subset to the result.

subset.push_back(nums[i]);
    → Include nums[i] in the current subset.

backtrack(i + 1, nums, subset);
    → Recur with the next index.

subset.pop_back();
    → Backtrack: remove last element to try other combinations.

while (i + 1 < nums.size() && nums[i] == nums[i + 1]) { i++; }
    → Skip over consecutive duplicates.

backtrack(i + 1, nums, subset);
    → Recur by skipping the current number.

return res;
    → Return all unique subsets after exploration.

------------------------------------------------------
⏱ Complexity:
- Time: O(2^n), where n is the number of elements.
- Space: O(2^n * n), for storing all subsets and recursion stack.
------------------------------------------------------
*/


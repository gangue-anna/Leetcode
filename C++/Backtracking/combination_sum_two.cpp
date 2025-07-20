#include <bits/stdc++.h>
using namespace std;

/**
 * Approach:
 * - Sort the candidates array to easily handle duplicates.
 * - Use backtracking (DFS) to explore all unique combinations.
 * - At each position, skip duplicates by checking if the current number equals the previous one.
 * - Move to the next index in recursion (i+1) because each number can only be used once.
 * - If the sum equals the target, save the current combination.
 * - If the sum exceeds the target, backtrack immediately.
 *
 * Time Complexity:
 * - Worst case: O(2^n) (exploring all subsets of candidates).
 * - Due to pruning (because of the sorted array & skipping duplicates), it's better than O(2^n) in practice.
 *
 * Space Complexity:
 * - O(n) for recursion stack & current combination vector.
 */

class Solution {
public:
    vector<vector<int>> res; // Stores all valid combinations

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        vector<int> curr; // Current combination
        backtrack(candidates, target, 0, curr);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, int pos, vector<int>& curr) {
        if (target == 0) {
            res.push_back(curr); // Found valid combination
            return;
        }
        if (target < 0) return; // Exceeded target → backtrack

        int prev = -1; // To track duplicates
        for (int i = pos; i < candidates.size(); i++) {
            if (candidates[i] == prev) continue; // Skip duplicates
            curr.push_back(candidates[i]);       // Include current number
            backtrack(candidates, target - candidates[i], i + 1, curr); // Recurse
            curr.pop_back();                     // Backtrack
            prev = candidates[i];               // Set prev to current for next loop
        }
    }
};

/*
-----------------------------------------------
📄 Line-by-Line C++ Syntax Explanation:
-----------------------------------------------

#include <bits/stdc++.h>
    → Includes all standard C++ headers.

using namespace std;
    → Allows using standard library names (like vector) without `std::`.

class Solution { ... };
    → Defines a class named Solution.

vector<vector<int>> res;
    → 2D vector to store all valid combinations.

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    → Public method that starts backtracking and returns the result.

sort(candidates.begin(), candidates.end());
    → Sort the input array to easily handle duplicates.

vector<int> curr;
    → Temporary vector to build the current combination.

backtrack(candidates, target, 0, curr);
    → Call the helper backtracking function starting at index 0.

void backtrack(vector<int>& candidates, int target, int pos, vector<int>& curr)
    → Recursive function to explore all combinations.

if (target == 0) { res.push_back(curr); return; }
    → If target is achieved, save the combination & return.

if (target < 0) return;
    → If target is exceeded, backtrack.

int prev = -1;
    → Initialize prev to track and skip duplicates.

for (int i = pos; i < candidates.size(); i++) { ... }
    → Iterate over candidates starting from current position.

if (candidates[i] == prev) continue;
    → Skip if this number is same as previous one at this level.

curr.push_back(candidates[i]);
    → Include current number in combination.

backtrack(candidates, target - candidates[i], i + 1, curr);
    → Recurse with reduced target & next index.

curr.pop_back();
    → Remove last number to backtrack.

prev = candidates[i];
    → Update prev to current number.

-----------------------------------------------
⏱ Complexity:
- Time: O(2^n) in worst case.
- Space: O(n) for recursion & current path.

-----------------------------------------------
*/


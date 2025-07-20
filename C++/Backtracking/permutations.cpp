#include <bits/stdc++.h>
using namespace std;

/**
 * Approach:
 * - Use recursion to generate all permutations of the input list.
 * - For each element:
 *   - Remove it from the current list.
 *   - Generate all permutations of the remaining list.
 *   - Append the removed element to each permutation.
 *   - Restore the list by putting the element back at its original position.
 *
 * Time Complexity: O(n!), since there are n! permutations.
 * Space Complexity: O(n!) to store all permutations + recursion stack.
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res; // To store all permutations

        // Base case: if only one element left
        if (nums.size() == 1) {
            res.push_back(nums);
            return res;
        }

        // For each element in the input
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[0];          // take the first element
            nums.erase(nums.begin()); // remove it from the list

            // Generate all permutations of the remaining list
            vector<vector<int>> perms = permute(nums);

            // Append the removed element to each permutation
            for (auto& perm : perms) {
                perm.push_back(n);
            }

            // Add these permutations to the result
            res.insert(res.end(), perms.begin(), perms.end());

            nums.push_back(n);       // restore the removed element at the end
        }

        return res;
    }
};

/*
------------------------------------------------------
📄 Line-by-Line C++ Syntax Explanation:
------------------------------------------------------

#include <bits/stdc++.h>
    → Includes all standard C++ libraries in one line.

using namespace std;
    → Allows us to use standard library types without `std::` prefix.

class Solution { ... };
    → Defines a class named Solution.

vector<vector<int>> permute(vector<int>& nums)
    → Public method which takes a reference to a vector of integers and returns a 2D vector of integers.

vector<vector<int>> res;
    → Declares a 2D vector to hold all the permutations.

if (nums.size() == 1) { ... }
    → Base case: if only one element remains, return it as the only permutation.

res.push_back(nums);
    → Add the single-element vector to the result.

for (int i = 0; i < nums.size(); i++) { ... }
    → Loop through each element of the vector.

int n = nums[0];
    → Store the first element in variable n.

nums.erase(nums.begin());
    → Remove the first element from the vector.

vector<vector<int>> perms = permute(nums);
    → Recursively call permute on the remaining elements.

for (auto& perm : perms) { perm.push_back(n); }
    → Append the removed element `n` to each of the smaller permutations.

res.insert(res.end(), perms.begin(), perms.end());
    → Append all newly formed permutations to the result vector.

nums.push_back(n);
    → Restore the removed element back to the end of the vector for the next iteration.

return res;
    → Return all generated permutations.

------------------------------------------------------
⏱ Complexity:
- Time: O(n!) — number of permutations.
- Space: O(n!) — for storing all permutations and recursion stack.
------------------------------------------------------
*/


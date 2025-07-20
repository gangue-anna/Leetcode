#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
            Problem:
            - Determine if the array can be partitioned into two subsets with equal sum.

            Approach:
            - If the total sum is odd, it’s impossible to split into two equal parts.
            - Use a set `dp` to store all possible subset sums as we iterate.
            - At each step, consider including or excluding the current number.
            - If at any point we can form `target = totalSum/2`, return true.

            Time Complexity: O(n * target)
                - At each of n steps, we generate up to target sums.
            Space Complexity: O(target)
                - The dp set stores sums up to target.
        */

        int total = accumulate(nums.begin(), nums.end(), 0);

        // If total sum is odd, cannot partition into equal halves
        if (total % 2 != 0) return false;

        int target = total / 2;

        unordered_set<int> dp;
        dp.insert(0);

        for (int i = nums.size() - 1; i >= 0; i--) {
            unordered_set<int> nextDP;

            for (int t : dp) {
                if (t + nums[i] == target) {
                    return true;
                }
                nextDP.insert(t);
                nextDP.insert(t + nums[i]);
            }

            dp = nextDP;
        }

        return dp.find(target) != dp.end();
    }
};

/*
================ LINE-BY-LINE SYNTAX EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ libraries (vector, set, algorithm, etc.)

using namespace std;
    - Allows you to write vector, string, etc. without the std:: prefix.

class Solution {
    - Defines a class named Solution.

public:
    - Marks the following members as publicly accessible.

bool canPartition(vector<int>& nums)
    - Function returns a boolean and takes a reference to a vector of integers.

int total = accumulate(nums.begin(), nums.end(), 0);
    - Calculates the sum of all elements in nums using the standard library.

if (total % 2 != 0) return false;
    - If the sum is odd, return false because it cannot be split evenly.

int target = total / 2;
    - The desired sum for one subset.

unordered_set<int> dp;
    - A set to keep track of all possible sums we can form.

dp.insert(0);
    - Start with sum 0 (empty subset).

for (int i = nums.size() - 1; i >= 0; i--)
    - Iterate backwards over the array.

unordered_set<int> nextDP;
    - Temporary set to store the next state of possible sums.

for (int t : dp)
    - For each sum already possible in dp.

if (t + nums[i] == target)
    - If adding current number to t equals target, return true.

nextDP.insert(t);
nextDP.insert(t + nums[i]);
    - Add both options: without or with current number.

dp = nextDP;
    - Update dp with the next state.

return dp.find(target) != dp.end();
    - After processing all elements, check if target is achievable.

*/

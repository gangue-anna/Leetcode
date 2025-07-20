#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
            Problem: Count the number of ways to assign '+' and '-' to each element
            so that the sum equals target.

            Approach:
            - Reduce to a subset sum problem:
                Find number of subsets with sum = (totalSum + target) / 2.
            - Why? 
                Let sum(P) - sum(N) = target
                sum(P) + sum(N) = totalSum
                => 2 * sum(P) = target + totalSum
                => sum(P) = (target + totalSum) / 2
            - Use DP to count subsets with this sum.
            - Time: O(n * sum)
            - Space: O(sum)
        */

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If target is out of possible range or (S+target) is odd, no solution
        if (abs(target) > totalSum || (totalSum + target) % 2 != 0) {
            return 0;
        }

        int subsetSum = (totalSum + target) / 2;

        // dp[i]: number of ways to get sum i
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;  // base case: one way to make sum 0 (choose nothing)

        for (int num : nums) {
            // iterate backwards to avoid using the same number multiple times
            for (int i = subsetSum; i >= num; --i) {
                dp[i] += dp[i - num];
            }
        }

        return dp[subsetSum];
    }
};

/*
================ LINE-BY-LINE EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ libraries (like vector, iostream, etc.).

using namespace std;
    - Allows you to write vector, cout, etc. without the std:: prefix.

class Solution {
    - Defines a class called Solution.

public:
    - Marks the next members as public (accessible outside the class).

int findTargetSumWays(vector<int>& nums, int target)
    - Function to solve the problem.
    - Takes a reference to a vector of integers and an integer target.
    - Returns the number of ways as an integer.

int totalSum = accumulate(nums.begin(), nums.end(), 0);
    - Computes the sum of all elements in nums.

if (abs(target) > totalSum || (totalSum + target) % 2 != 0)
    - Checks if the target is out of range or (S+target) is not even.
    - If yes, return 0 because no solution exists.

int subsetSum = (totalSum + target) / 2;
    - Computes the subset sum we need to find.

vector<int> dp(subsetSum + 1, 0);
    - Creates a vector 'dp' of size subsetSum+1 initialized to 0.
    - dp[i] represents the number of ways to make sum 'i'.

dp[0] = 1;
    - Base case: 1 way to make sum 0 (by choosing nothing).

for (int num : nums) {
    - Loops over each number in nums.

for (int i = subsetSum; i >= num; --i) {
    - Loops from subsetSum down to num.
    - Ensures we don't count the same number more than once in one iteration.

dp[i] += dp[i - num];
    - Adds the number of ways to make (i-num) to dp[i].
    - This represents choosing 'num' as part of the subset.

return dp[subsetSum];
    - Returns the number of ways to achieve the target sum.
}
*/


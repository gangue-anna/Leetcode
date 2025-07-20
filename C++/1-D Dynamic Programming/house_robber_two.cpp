#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            Problem: House Robber II
            - Houses are arranged in a circle (1st and last are adjacent).
            - Cannot rob both 1st and last house.
            - Find the maximum money you can rob.

            Approach:
            - If there is only 1 house, rob it.
            - Otherwise:
              - Scenario 1: Rob houses from index 0 to n-2 (exclude last house)
              - Scenario 2: Rob houses from index 1 to n-1 (exclude first house)
            - Take the maximum of these two scenarios.

            Time Complexity: O(n)
                - We run a DP helper twice, each O(n).
            Space Complexity: O(1)
                - Only constant space used.
        */

        int n = nums.size();
        if (n == 1) return nums[0];  // Edge case: only one house

        // Run the helper on two scenarios
        return max(helper(vector<int>(nums.begin() + 1, nums.end())),
                   helper(vector<int>(nums.begin(), nums.end() - 1)));
    }

private:
    int helper(vector<int> nums) {
        /*
            Standard House Robber I (linear street).
            At each house:
              - rob1: max money if we rob up to i-2
              - rob2: max money if we rob up to i-1
            At current house, take max(rob1 + current, rob2)
        */

        int rob1 = 0, rob2 = 0;

        for (int n : nums) {
            int newRob = max(rob1 + n, rob2);  // Decide whether to rob or skip
            rob1 = rob2;                       // Move rob2 to rob1
            rob2 = newRob;                     // Update rob2 to new max
        }

        return rob2;  // rob2 holds the max money
    }
};

/*
================ LINE-BY-LINE SYNTAX EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ libraries like vector, string, iostream, etc.

using namespace std;
    - Allows us to use standard library names directly without the `std::` prefix.

class Solution {
    - Defines a class named Solution.

public:
    - Access specifier: functions and members under public can be accessed outside the class.

int rob(vector<int>& nums)
    - Function `rob` that takes a reference to a vector of integers `nums` and returns an integer.

int n = nums.size();
    - Get the number of houses.

if (n == 1) return nums[0];
    - If there’s only one house, rob it and return.

return max(helper(...), helper(...));
    - Return the maximum of the two scenarios by calling the helper function twice.

helper(vector<int> nums)
    - Private helper function that implements the standard House Robber I DP logic.

int rob1 = 0, rob2 = 0;
    - Initialize DP variables:
      rob1: max money if we rob up to i-2
      rob2: max money if we rob up to i-1

for (int n : nums)
    - Range-based for loop iterating through `nums`.

int newRob = max(rob1 + n, rob2);
    - Either rob this house (rob1 + n) or skip it (rob2).

rob1 = rob2;
    - Move rob2 to rob1 for next iteration.

rob2 = newRob;
    - Update rob2 to the new maximum.

return rob2;
    - Return the maximum money we can rob.

*/

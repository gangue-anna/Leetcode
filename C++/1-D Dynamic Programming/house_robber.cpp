#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            Problem: House Robber
            - Given an array `nums` where each element represents the amount of money at each house.
            - You cannot rob two adjacent houses.
            - Find the maximum amount of money you can rob.

            Approach:
            - Dynamic Programming (space-optimized).
            - Use two variables:
              - rob1: max money if we rob up to house i-2
              - rob2: max money if we rob up to house i-1
            - At each house, decide:
              - Rob this house → add current house's money to rob1
              - Or skip this house → keep rob2
            - The maximum of these two becomes the new `rob2`.

            Time Complexity: O(n)
                - We iterate through the array once.
            Space Complexity: O(1)
                - We only use two variables to keep track of the state.
        */

        int rob1 = 0, rob2 = 0;

        for (int n : nums) {
            // temp stores the maximum money after deciding whether to rob this house or not
            int temp = max(n + rob1, rob2);
            rob1 = rob2;  // Move rob2 to rob1 for the next iteration
            rob2 = temp;  // Update rob2 to the new maximum
        }

        return rob2; // rob2 holds the maximum money that can be robbed
    }
};

/*
================ LINE-BY-LINE SYNTAX EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ libraries like vector, iostream, etc.

using namespace std;
    - Allows using standard library names directly without the `std::` prefix.

class Solution {
public:
    - Defines a class named Solution with public member functions.

int rob(vector<int>& nums)
    - Function named `rob` that takes a reference to a vector of integers `nums` and returns an integer.

int rob1 = 0, rob2 = 0;
    - Initialize two variables to track maximum money if you rob up to house i-2 and i-1.

for (int n : nums)
    - Range-based for loop to iterate through each element of `nums`. Here `n` is each house's money.

int temp = max(n + rob1, rob2);
    - Decide to rob the current house (n + rob1) or skip it (rob2), and take the maximum.

rob1 = rob2;
    - Update rob1 for the next iteration to be rob2.

rob2 = temp;
    - Update rob2 to the new maximum after this house.

return rob2;
    - Return the maximum money that can be robbed.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
            Problem:
            - Given an array of integers `nums`, find the length of the longest strictly increasing subsequence.

            Approach:
            - Dynamic Programming (Bottom-Up)
            - LIS[i] stores the length of the longest increasing subsequence starting at index i.
            - For each element, look ahead and try to extend the subsequence if possible.

            Time Complexity: O(n^2)
                - Two nested loops each going up to n.
            Space Complexity: O(n)
                - One DP array of size n.
        */

        int n = nums.size();
        vector<int> LIS(n, 1); 
        // Initialize all LIS values to 1 because each element alone is a subsequence

        // Iterate backwards through the array
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] < nums[j]) {
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
        }

        // The answer is the maximum value in LIS
        return *max_element(LIS.begin(), LIS.end());
    }
};

/*
================ LINE-BY-LINE SYNTAX EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ libraries (like vector, algorithm, etc.)

using namespace std;
    - Allows us to use standard names (like vector, string) without the std:: prefix.

class Solution {
    - Defines a class named Solution.

public:
    - The following functions/data are public (can be accessed outside the class).

int lengthOfLIS(vector<int>& nums)
    - Function that returns an integer and takes a reference to a vector of integers.

int n = nums.size();
    - Gets the size of the input array `nums` and stores it in `n`.

vector<int> LIS(n, 1);
    - Initializes a vector of size `n` filled with 1. 
      Each LIS[i] starts at 1 because a single element is itself a subsequence.

for (int i = n - 1; i >= 0; i--)
    - Loop backwards from the end of the array towards the start.

for (int j = i + 1; j < n; j++)
    - For each i, look at all elements after it to see if they can extend the subsequence.

if (nums[i] < nums[j])
    - Check if the number at j is greater than at i (so we can extend the subsequence).

LIS[i] = max(LIS[i], 1 + LIS[j]);
    - Update LIS[i] to the maximum of its current value and (1 + LIS[j]).

return *max_element(LIS.begin(), LIS.end());
    - Return the maximum value in the LIS array.
      `*max_element` finds the largest value in the vector.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
            Problem:
            - Given an array of integers, find the contiguous subarray with the largest product.

            Approach:
            - Track both current maximum and current minimum products at each position because:
                - A negative number can flip min ↔ max.
            - Reset current products when encountering zero because multiplying further will always give zero.
            - Keep updating the result with the largest product seen so far.

            Time Complexity: O(n)
                - Single pass through the array.
            Space Complexity: O(1)
                - Uses only a few variables.
        */

        int res = *max_element(nums.begin(), nums.end()); 
        // `res` stores the maximum product found so far (handles case where all numbers are ≤ 0)

        int curMin = 1, curMax = 1; 
        // Track min and max products ending at the current index

        for (int n : nums) {
            if (n == 0) {
                // If current element is zero, reset curMin & curMax to 1
                curMin = 1;
                curMax = 1;
                continue;
            }

            int temp = curMax * n;
            // Save curMax * n before updating curMax

            curMax = max({n * curMax, n * curMin, n});
            // Maximum product ending here can be: n, n * curMax (prev), or n * curMin (prev)

            curMin = min({temp, n * curMin, n});
            // Minimum product ending here can also help if multiplied with another negative later

            res = max({res, curMax, curMin});
            // Update the result with the largest seen so far
        }

        return res;
    }
};

/*
================ LINE-BY-LINE SYNTAX EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ headers (like vector, iostream, etc).

using namespace std;
    - Allows us to use standard names (like vector, string) without prefixing them with std::.

class Solution {
    - Defines a class named Solution.

public:
    - The methods below are publicly accessible.

int maxProduct(vector<int>& nums)
    - Defines a function `maxProduct` that takes a vector of integers `nums` and returns an int.

int res = *max_element(nums.begin(), nums.end());
    - Initializes `res` with the largest number in `nums` to handle arrays where all numbers are ≤ 0.

int curMin = 1, curMax = 1;
    - Variables to keep track of the current minimum and maximum product ending at this index.

for (int n : nums)
    - Loop over each integer `n` in the vector `nums`.

if (n == 0)
    - If `n` is zero, reset `curMin` and `curMax` because zero resets the product.

int temp = curMax * n;
    - Temporarily store `curMax * n` before it gets updated (used later for curMin).

curMax = max({n * curMax, n * curMin, n});
    - Update `curMax` with the maximum of the three options.

curMin = min({temp, n * curMin, n});
    - Update `curMin` with the minimum of the three options.

res = max({res, curMax, curMin});
    - Update the result `res` if we find a bigger product.

return res;
    - Return the largest product found.

*/

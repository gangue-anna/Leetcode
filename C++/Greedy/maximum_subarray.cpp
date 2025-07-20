#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Function to find the contiguous subarray with the largest sum.
     *
     * Approach: Kadane's Algorithm
     * - Initialize maxSub to the first element (handles arrays with all negative numbers)
     * - Use curSum to keep track of the current subarray sum.
     * - If curSum becomes negative, reset it to 0 (start a new subarray)
     * - Iterate through the array, updating maxSub whenever curSum is larger.
     *
     * Time Complexity: O(N) — iterate through the array once
     * Space Complexity: O(1) — constant extra space
     */
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0];  // Stores maximum subarray sum found so far
        int curSum = 0;        // Current subarray sum

        for (int n : nums) {
            if (curSum < 0)
                curSum = 0;   // Start a new subarray if current sum < 0
            curSum += n;      // Add current number to the running sum
            maxSub = max(maxSub, curSum);  // Update maxSub if needed
        }

        return maxSub;
    }
};

/*
====================================================
Line-by-line C++ syntax explanation:
====================================================

#include <bits/stdc++.h>
    -> Includes all standard C++ libraries (like <vector>, <iostream>, etc.)

using namespace std;
    -> Allows using standard library names (like vector, string) without prefixing them with std::

class Solution {
public:
    -> Defines a class named Solution with public member functions.

int maxSubArray(vector<int>& nums) {
    -> Defines a member function `maxSubArray` that takes a reference to a vector of integers and returns an int.

int maxSub = nums[0];
    -> Initialize `maxSub` to the first element of the array. This is the best sum found so far.

int curSum = 0;
    -> Initialize `curSum` to 0. This will store the sum of the current subarray.

for (int n : nums) {
    -> Loop over each element `n` in the vector `nums`.

if (curSum < 0)
    curSum = 0;
    -> If the current subarray sum becomes negative, reset it to 0 to start a new subarray.

curSum += n;
    -> Add the current number to the current subarray sum.

maxSub = max(maxSub, curSum);
    -> Update the maximum sum found so far if the current sum is higher.

return maxSub;
    -> Return the maximum subarray sum found.

====================================================
Time Complexity:
    - O(N): We iterate over the array exactly once.

Space Complexity:
    - O(1): We only use two integer variables regardless of input size.
====================================================
*/


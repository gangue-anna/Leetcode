#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Approach:
     * - Use the sum formula for the first n natural numbers: sum = n*(n+1)/2.
     * - Subtract the sum of the input array from the expected sum to find the missing number.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected_sum = n * (n + 1) / 2;
        int actual_sum = 0;

        for (int num : nums) {
            actual_sum += num;
        }

        return expected_sum - actual_sum;
    }
};

class Solution2 {
public:
    /*
     * Approach:
     * - Use a single variable `res` to accumulate the difference between indices and values, starting from n.
     * - Iterate over the array and adjust `res`.
     * - At the end, `res` will hold the missing number.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;

        for (int i = 0; i < n; ++i) {
            res += i - nums[i];
        }

        return res;
    }
};

/*
📖 Line-by-line explanation:
----------------------------
#include <bits/stdc++.h>
    → Includes all standard C++ libraries.

using namespace std;
    → Avoids writing `std::` before common names like `vector` or `cout`.

class Solution { … };
    → Defines a class named `Solution` (LeetCode convention).

public:
    → Declares that the following methods are publicly accessible.

int missingNumber(vector<int>& nums) { … }
    → Function that takes a reference to a vector of integers and returns the missing number.

int n = nums.size();
    → Get the size of the input vector `nums`.

int expected_sum = n * (n+1) / 2;
    → Calculate the expected sum of numbers from 0 to n using the arithmetic progression formula.

int actual_sum = 0;
    → Initialize a variable to store the actual sum of the given numbers.

for (int num : nums) { actual_sum += num; }
    → Loop through each number in `nums` and add it to `actual_sum`.

return expected_sum - actual_sum;
    → The difference between expected and actual sum gives the missing number.

---
In `Solution2`:
int res = n;
    → Start with `n` because indices go from 0..n-1 but the numbers are from 0..n.

for (int i = 0; i < n; ++i) { res += i - nums[i]; }
    → For each index `i`, add `i` and subtract `nums[i]` from `res`.

return res;
    → Final result after the loop is the missing number.

-----------------------------------------
⏱ Time Complexity: O(n) → Linear, as it iterates through the array once.
🗃 Space Complexity: O(1) → Constant extra space is used.
*/


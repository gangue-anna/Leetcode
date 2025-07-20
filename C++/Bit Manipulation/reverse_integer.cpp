#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Approach:
     * - Extract the last digit of x using modulo (`x % 10`) and remove it from x by division (`x / 10`).
     * - Build the reversed number digit by digit.
     * - Before adding a digit, check if the result would overflow/underflow a 32-bit signed integer.
     *
     * Time Complexity: O(log |x|) → since we process each digit of x.
     * Space Complexity: O(1) → constant space.
     */
    int reverse(int x) {
        int MIN = INT_MIN; // -2^31
        int MAX = INT_MAX; //  2^31 - 1
        int res = 0;

        while (x != 0) {
            int digit = x % 10;   // Get the last digit
            x /= 10;             // Remove the last digit

            // Check for overflow/underflow before multiplying/res
            if (res > MAX / 10 || (res == MAX / 10 && digit > MAX % 10)) {
                return 0;
            }
            if (res < MIN / 10 || (res == MIN / 10 && digit < MIN % 10)) {
                return 0;
            }

            res = res * 10 + digit;
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
    → Allows use of standard names without `std::` prefix.

class Solution { … };
    → Defines a class named `Solution` (LeetCode style).

public:
    → Public access modifier so that `reverse` can be called from outside.

int reverse(int x) { … }
    → Function that takes an integer `x` and returns its reverse, or 0 if it overflows.

int MIN = INT_MIN;
int MAX = INT_MAX;
    → Constants representing the smallest and largest 32-bit signed integers.

int res = 0;
    → Initialize result variable to build the reversed number.

while (x != 0) {
    → Loop as long as `x` is not zero.

int digit = x % 10;
    → Get the last digit of `x` (handles negatives properly).

x /= 10;
    → Remove the last digit from `x`.

if (res > MAX / 10 || (res == MAX / 10 && digit > MAX % 10))
    → Check if adding `digit` would cause `res` to overflow positively.

if (res < MIN / 10 || (res == MIN / 10 && digit < MIN % 10))
    → Check if adding `digit` would cause `res` to overflow negatively.

res = res * 10 + digit;
    → Add the digit to `res`.

return res;
    → When finished, return the reversed integer.

-----------------------------------------
⏱ Time Complexity: O(log |x|) → proportional to number of digits.
🗃 Space Complexity: O(1) → constant space.
*/


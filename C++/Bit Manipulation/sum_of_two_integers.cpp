#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Approach:
     * - Use bitwise operations to compute sum without using '+'.
     * - At each step:
     *     sum without carry = a ^ b
     *     carry = (a & b) << 1
     * - Repeat until carry becomes 0.
     * - In C++, integers are already 32-bit and handle negative numbers with 2's complement,
     *   so no explicit mask is needed unlike Python.
     *
     * Time Complexity: O(1) → at most 32 iterations for a 32-bit integer.
     * Space Complexity: O(1)
     */
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned carry = (unsigned)(a & b) << 1; // Calculate carry and shift left
            a = a ^ b;  // Sum without carry
            b = carry;  // New carry
        }
        return a;
    }
};

/*
📖 Line-by-line explanation:
----------------------------
#include <bits/stdc++.h>
    → Includes all standard C++ libraries.

using namespace std;
    → Avoids writing `std::` before every standard function/type.

class Solution { … };
    → Defines a class named `Solution` (LeetCode convention).

public:
    → Marks the following methods as accessible from outside the class.

int getSum(int a, int b) { … }
    → Function that takes two integers `a` and `b` and returns their sum without using `+`.

while (b != 0) {
    → Continue the loop until there is no carry left.

unsigned carry = (unsigned)(a & b) << 1;
    → Calculate the carry by ANDing a and b, then left-shifting it by 1.

a = a ^ b;
    → Compute the sum without carry using XOR.

b = carry;
    → Assign carry to b to handle it in the next iteration.

return a;
    → When carry becomes 0, `a` holds the final sum.

-----------------------------------------
⏱ Time Complexity: O(1) → Constant, at most 32 steps.
🗃 Space Complexity: O(1) → Constant space usage.
*/


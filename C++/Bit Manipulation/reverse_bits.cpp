#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Approach:
     * - Iterate over all 32 bits of the input integer `n`.
     * - For each bit at position `i`, extract it and set it in position `31-i` in the result.
     * - Use bitwise shift and OR to construct the result.
     *
     * Time Complexity: O(1)
     *   - Exactly 32 iterations regardless of input.
     *
     * Space Complexity: O(1)
     *   - We use only two integers (`res` and `bit`).
     */
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;  // Variable to store the reversed bits

        for (int i = 0; i < 32; ++i) {
            uint32_t bit = (n >> i) & 1;         // Extract the i-th bit of n
            res |= (bit << (31 - i));           // Set it at position (31 - i) in res
        }

        return res;
    }
};

/*
📖 Line-by-line explanation for beginners:
------------------------------------------
#include <bits/stdc++.h>
    → Includes all standard C++ libraries.

using namespace std;
    → Avoids writing std:: before common objects like vector, cout, etc.

class Solution { … };
    → Defines a class named Solution (as per LeetCode style).

public:
    → Marks the following methods as accessible from outside the class.

uint32_t reverseBits(uint32_t n) { … }
    → Function that takes a 32-bit unsigned integer `n` and returns its bit-reversed value.

uint32_t res = 0;
    → Initialize the result variable `res` to 0.

for (int i = 0; i < 32; ++i) { … }
    → Loop through all 32 bits of the integer.

uint32_t bit = (n >> i) & 1;
    → Shift `n` right by `i` to bring the i-th bit to the least significant position,
      then use `& 1` to extract just that bit.

res |= (bit << (31 - i));
    → Shift `bit` to position `(31 - i)` (the mirror position) and OR it into `res`.

return res;
    → Return the final reversed bits as an unsigned integer.

------------------------------------------
Time Complexity: O(1) → 32 iterations.
Space Complexity: O(1) → Only uses a few integer variables.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Approach:
     * - Use Brian Kernighan's Algorithm to count the number of 1 bits.
     * - At each step: n = n & (n - 1) removes the least significant 1 bit.
     * - Increment a counter for each such step.
     *
     * Time Complexity: O(k), where k is the number of set bits in n.
     * - Each iteration removes one set bit.
     *
     * Space Complexity: O(1)
     * - Only one integer counter is used.
     */
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n = n & (n - 1);  // Remove the least significant 1 bit
            res++;            // Increment the count of 1 bits
        }
        return res;
    }
};

/*
📖 Line-by-line explanation for beginners:
-------------------------------------------
#include <bits/stdc++.h>          
    → Includes all standard C++ libraries at once.

using namespace std;             
    → Avoids having to prefix standard library names with `std::`.

class Solution { … };           
    → Defines a class named Solution.

public:                         
    → Everything below is publicly accessible outside the class.

int hammingWeight(uint32_t n) { … }
    → Function that takes a 32-bit unsigned integer `n` and returns the number of 1 bits.

int res = 0;                    
    → Initialize result counter to 0.

while (n) { … }                 
    → Loop runs while `n` is not zero.

n = n & (n - 1);                
    → Removes the least significant set bit in `n`.
      → Example: 12 (1100) → 8 (1000) after one operation.

res++;                          
    → Increment the counter for each removed bit.

return res;                     
    → Return the total count of 1 bits.

-------------------------------------------
Why use n & (n-1)?
- It efficiently removes one set bit in each iteration.
- Runs in O(k) time, where k = number of 1 bits.

Example:
n = 13 (1101)
1st: n = 1101 → 1100
2nd: n = 1100 → 1000
3rd: n = 1000 → 0000
Result: 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        /*
            Approach:
            - This is a dynamic programming problem, essentially the Fibonacci sequence.
            - At each step, you can come from the step before (1) or two steps before (2).
            - So, ways(i) = ways(i-1) + ways(i-2).
            - We optimize space by keeping only the last two computed values.
            
            Time Complexity: O(n)
                - Single loop from 0 to n-1.
            
            Space Complexity: O(1)
                - Only two variables (`one` and `two`) are maintained.
        */

        int one = 1, two = 1; // one: ways to reach i-1, two: ways to reach i-2

        for (int i = 0; i < n - 1; ++i) {
            int temp = one;    // Save current `one` temporarily
            one = one + two;   // Current ways = previous + one before previous
            two = temp;        // Update `two` to previous `one`
        }

        return one; // Final result: ways to reach step n
    }
};

/*
================ LINE-BY-LINE SYNTAX EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ libraries (iostream, vector, algorithm, etc.) in one line.

using namespace std;
    - Avoids prefixing standard library names with `std::`.

class Solution {
public:
    - Defines the Solution class with public methods.

int climbStairs(int n)
    - Function signature: takes an integer `n` (number of stairs) and returns an int (number of ways).

int one = 1, two = 1;
    - Initialize the two most recent results.
    - At the start, there's only 1 way to reach step 1 and step 0.

for (int i = 0; i < n - 1; ++i)
    - Loop through steps from 0 to n-2.
    - We iterate n-1 times since the first step is already covered by initialization.

int temp = one;
    - Save the current value of `one` so it can be assigned to `two` later.

one = one + two;
    - The number of ways to reach the current step is the sum of the ways to reach the previous step (`one`) and the step before that (`two`).

two = temp;
    - Update `two` to the previous `one` for the next iteration.

return one;
    - After the loop ends, `one` contains the number of ways to reach the nth step.

*/

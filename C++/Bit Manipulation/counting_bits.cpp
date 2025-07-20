#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Approach:
     * - Use DP to count the number of 1's in the binary representation for each number from 0 to n.
     * - For each i, find the largest power of two ≤ i (called offset).
     * - The number of 1's in i = 1 + number of 1's in (i - offset),
     *   because subtracting offset removes the most significant 1-bit from i.
     *
     * Time Complexity: O(n)
     *   - We process each number from 1 to n once.
     *
     * Space Complexity: O(n)
     *   - We store the count of 1's for each number in a vector of size n+1.
     */
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);  // DP array to store count of 1's
        int offset = 1;           // The current largest power of two ≤ i

        for (int i = 1; i <= n; ++i) {
            // When we reach the next power of two, update the offset
            if (offset * 2 == i) {
                offset = i;
            }
            dp[i] = 1 + dp[i - offset];
        }

        return dp;
    }
};

/*
📖 Line-by-line explanation for beginners:
-------------------------------------------
#include <bits/stdc++.h>
    → Includes all standard C++ libraries.

using namespace std;
    → So we don’t have to prefix things like vector, cout with `std::`.

class Solution { … };
    → Defines a class named Solution.

public:
    → Marks the following members as publicly accessible.

vector<int> countBits(int n) { … }
    → Function that takes an integer `n` and returns a vector<int> with the counts.

vector<int> dp(n + 1, 0);
    → Create a vector of size (n+1) initialized to 0, to store DP results.

int offset = 1;
    → Initialize offset to 1, which is the smallest power of two.

for (int i = 1; i <= n; ++i) { … }
    → Loop through numbers from 1 to n.

if (offset * 2 == i) offset = i;
    → If we reach the next power of two (like 2, 4, 8…), update offset.

dp[i] = 1 + dp[i - offset];
    → DP relation: 
      number of 1’s in i = 1 + number of 1’s in (i - offset),
      because (i - offset) removes the highest set bit from i.

return dp;
    → Return the DP array.

-------------------------------------------
🔷 Why does it work?
- At each number i, we find the largest power of two ≤ i.
- Remove this highest bit and count the remaining bits (already computed in DP).
- Add 1 for the removed bit.

Example:
i = 5 (binary: 101), offset = 4
i - offset = 1 (binary: 001), DP[1] = 1
So DP[5] = 1 + DP[1] = 2

-------------------------------------------
Time Complexity: O(n) → Loop runs n times.
Space Complexity: O(n) → We store n+1 integers.
*/

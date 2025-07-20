#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /*
            Problem:
            - Given a list of coin denominations and an amount, return the minimum number of coins needed to make that amount.
            - If it is not possible, return -1.

            Approach:
            - Dynamic Programming (Bottom-up):
                - dp[a] = minimum number of coins needed to make amount `a`.
                - Initialize dp with amount+1 (an impossible high value).
                - Base case: dp[0] = 0.
                - For each amount from 1 to `amount`, check all coins:
                    - If `a - c >= 0`, then we can use coin `c` and update dp[a].
                - After filling dp, if dp[amount] > amount, return -1 (not possible).

            Time Complexity: O(amount * n)
                - amount: target amount
                - n: number of coins
            Space Complexity: O(amount)
                - For the dp array.
        */

        vector<int> dp(amount + 1, amount + 1); // Initialize dp with impossible high value
        dp[0] = 0; // Base case: 0 coins to make amount 0

        // Build the dp array
        for (int a = 1; a <= amount; a++) {
            for (int c : coins) {
                if (a - c >= 0) {
                    dp[a] = min(dp[a], 1 + dp[a - c]); 
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

/*
================ LINE-BY-LINE SYNTAX EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ libraries.

using namespace std;
    - Allows us to use standard library names without prefixing them with std::.

class Solution {
    - Defines a class named Solution.

public:
    - Makes the following method publicly accessible.

int coinChange(vector<int>& coins, int amount)
    - Function `coinChange` takes a vector of integers `coins` and an integer `amount`, and returns an int.

vector<int> dp(amount + 1, amount + 1);
    - Create a vector `dp` of size amount+1 initialized to amount+1 (impossible high value).

dp[0] = 0;
    - Base case: to make amount 0, we need 0 coins.

for (int a = 1; a <= amount; a++)
    - Iterate through all amounts from 1 to `amount`.

for (int c : coins)
    - For each coin denomination `c`.

if (a - c >= 0)
    - If coin `c` can be used (i.e., `a >= c`).

dp[a] = min(dp[a], 1 + dp[a - c]);
    - Update `dp[a]` to the minimum between current value and `1 + dp[a-c]`.

return dp[amount] > amount ? -1 : dp[amount];
    - If `dp[amount]` is still greater than `amount`, no solution exists, return -1.
    - Otherwise, return `dp[amount]`.

*/

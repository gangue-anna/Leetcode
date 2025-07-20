#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*
            Problem: Find the number of ways to make up the given amount using coins.
            - Each coin can be used unlimited times.
            - We use a 1D DP array for space efficiency.
            
            Approach:
            - dp[a]: number of ways to make amount 'a'
            - Base case: dp[0] = 1 (one way to make amount 0 — use no coins)
            - For each coin:
                - For each amount from 1 to amount:
                    - dp[a] += dp[a - coin] if a >= coin
            - Time Complexity: O(amount * number of coins)
            - Space Complexity: O(amount)
        */

        vector<int> dp(amount + 1, 0); // DP array: ways to make each amount
        dp[0] = 1;                     // Base case: 1 way to make amount 0

        for (int coin : coins) {      // Loop through each coin
            for (int a = coin; a <= amount; ++a) {
                dp[a] += dp[a - coin]; // If we include this coin, add ways
            }
        }

        return dp[amount];           // Result: ways to make amount
    }
};

/*
================ LINE-BY-LINE EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ libraries: vector, iostream, etc.

using namespace std;
    - Allows us to write vector, cout, etc. without the std:: prefix.

class Solution {
    - Defines a class named Solution.

public:
    - Marks the following member functions as public.

int change(int amount, vector<int>& coins)
    - Function to compute number of ways to make 'amount' with given 'coins'.
    - Takes an integer (amount) and a reference to a vector of integers (coins).
    - Returns an integer (number of ways).

vector<int> dp(amount + 1, 0);
    - Creates a vector 'dp' of size (amount+1) initialized to 0.
    - dp[a] will hold the number of ways to make amount 'a'.

dp[0] = 1;
    - Base case: there is exactly one way to make amount 0 (use no coins).

for (int coin : coins) {
    - Range-based for loop: iterate over each coin in the vector 'coins'.

for (int a = coin; a <= amount; ++a) {
    - Loop over amounts from 'coin' to 'amount'.

dp[a] += dp[a - coin];
    - Add to dp[a] the number of ways to make amount (a - coin).
    - This represents including the current coin.

return dp[amount];
    - Return the number of ways to make 'amount' from dp.

}
*/


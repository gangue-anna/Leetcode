#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Function to compute the maximum coins obtainable by bursting balloons optimally.
     *
     * Approach: Interval DP + Memoization
     * - Pad the input array with 1 at both ends to handle boundaries easily.
     * - Use DFS + memoization to compute max coins in interval [l, r].
     * - For each interval, try bursting every balloon last and recursively solve subintervals.
     *
     * Time Complexity: O(n^3) where n = nums.size()
     * Space Complexity: O(n^2) for the DP cache
     */
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // Pad nums with 1 at both ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // Memoization cache: map of pair<int,int> -> int
        unordered_map<long long, int> dp;

        /**
         * Helper function to compute max coins in interval [l, r]
         * @param l - left index (inclusive)
         * @param r - right index (inclusive)
         * @param nums - padded vector of balloons
         * @param dp - memoization cache
         * @return maximum coins obtainable in [l, r]
         */
        function<int(int, int)> dfs = [&](int l, int r) -> int {
            if (l > r) return 0;

            // Encode (l,r) as a single key (since unordered_map doesn't support pair keys directly)
            long long key = ((long long)l << 32) | r;

            if (dp.find(key) != dp.end()) return dp[key];

            int max_coins = 0;

            // Try each balloon in [l,r] as the last balloon to burst
            for (int i = l; i <= r; ++i) {
                int coins = nums[l-1] * nums[i] * nums[r+1];
                coins += dfs(l, i-1) + dfs(i+1, r);
                max_coins = max(max_coins, coins);
            }

            dp[key] = max_coins;
            return max_coins;
        };

        return dfs(1, n);
    }
};

/*
===================================================
Line-by-line C++ syntax explanation:
===================================================

#include <bits/stdc++.h>
    -> Includes all standard C++ libraries (like <vector>, <unordered_map>, <string>, etc.)

using namespace std;
    -> Allows using standard library names (like vector, unordered_map) without prefixing them with std::

class Solution {
public:
    -> Defines a class named Solution with public member functions.

int maxCoins(vector<int>& nums) {
    -> Defines a member function `maxCoins` that takes a vector of ints (passed by reference) and returns an int.

int n = nums.size();
    -> Stores the size of the input vector in `n`.

nums.insert(nums.begin(), 1);
    -> Inserts 1 at the beginning of the vector `nums`.

nums.push_back(1);
    -> Appends 1 to the end of the vector `nums`.

unordered_map<long long, int> dp;
    -> Declares a hash map to store computed results for intervals.
       Uses `long long` as key (to encode pair<int,int>) and `int` as value.

function<int(int, int)> dfs = [&](int l, int r) -> int { ... };
    -> Defines a lambda function named `dfs` with capture [&], which takes (l, r) and returns an int.

if (l > r) return 0;
    -> Base case: if the interval is invalid, no balloons left to burst.

long long key = ((long long)l << 32) | r;
    -> Encodes the pair (l, r) into a single `long long` key.

if (dp.find(key) != dp.end()) return dp[key];
    -> If result for interval [l,r] is already computed, return cached result.

int max_coins = 0;
    -> Initialize variable to track maximum coins in current interval.

for (int i = l; i <= r; ++i) { ... }
    -> Try bursting each balloon `i` last in the interval [l,r].

int coins = nums[l-1] * nums[i] * nums[r+1];
    -> Coins gained by bursting balloon `i` last in this interval.

coins += dfs(l, i-1) + dfs(i+1, r);
    -> Add the coins from left and right subintervals.

max_coins = max(max_coins, coins);
    -> Keep track of maximum coins obtained among all choices.

dp[key] = max_coins;
    -> Memoize the computed result for interval [l,r].

return dp[key];
    -> Return the result.

return dfs(1, n);
    -> Start the recursion for interval [1, n] (excluding the added boundaries).

===================================================
Time Complexity:
    - There are O(n^2) possible intervals [l,r], and each requires O(n) work → O(n^3).

Space Complexity:
    - The DP cache stores O(n^2) entries → O(n^2) space.

===================================================
*/


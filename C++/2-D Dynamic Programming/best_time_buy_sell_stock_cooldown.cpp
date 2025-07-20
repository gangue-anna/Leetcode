#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            Problem:
            - Find the maximum profit with as many transactions as you want.
            - After selling a stock, you cannot buy on the next day (cooldown of 1 day).

            Approach:
            - Dynamic Programming with memoization (Top-down).
            - State: (i, buying)
                - i = current day
                - buying = true if allowed to buy, false if holding stock and allowed to sell.
            - At each step:
                - If buying:
                    - Buy at prices[i] → go to (i+1, false) → profit = -prices[i] + dfs(i+1, false)
                    - Cooldown → go to (i+1, true)
                - If selling:
                    - Sell at prices[i] → go to (i+2, true) because of cooldown → profit = +prices[i] + dfs(i+2, true)
                    - Cooldown → go to (i+1, false)
            - Use unordered_map to memoize the (i, buying) state.
            
            Time Complexity: O(n)
                - Each state is computed once (at most 2n states: n days × 2 states).
            Space Complexity: O(n)
                - Due to the recursion stack and memoization.
        */

        int n = prices.size();
        map<pair<int, bool>, int> dp; // memoization table: key = (day, buying), value = max profit

        function<int(int, bool)> dfs = [&](int i, bool buying) -> int {
            if (i >= n) return 0; // Base case: no more days

            if (dp.find({i, buying}) != dp.end())
                return dp[{i, buying}]; // return cached value

            int cooldown = dfs(i + 1, buying); // Option 1: cooldown (do nothing)

            if (buying) {
                // Option 2: buy at prices[i]
                int buy = dfs(i + 1, false) - prices[i];
                dp[{i, buying}] = max(buy, cooldown);
            } else {
                // Option 2: sell at prices[i] → note cooldown of 1 day after selling
                int sell = dfs(i + 2, true) + prices[i];
                dp[{i, buying}] = max(sell, cooldown);
            }

            return dp[{i, buying}];
        };

        return dfs(0, true); // start on day 0 with buying state
    }
};

/*
================ LINE-BY-LINE EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard libraries (vector, map, etc.)

using namespace std;
    - Allows usage of names like vector, map directly without std:: prefix.

class Solution {
    - Defines a class named Solution.

public:
    - The following members are accessible publicly.

int maxProfit(vector<int>& prices)
    - Function that takes a vector of integers (prices) and returns an int (max profit).

int n = prices.size();
    - Store the number of days.

map<pair<int, bool>, int> dp;
    - Create a map to memoize states.
    - Key: pair of (day, buying) → Value: max profit at that state.

function<int(int, bool)> dfs = [&](int i, bool buying) -> int { ... }
    - Define a lambda function with recursion for DFS.
    - i: current day, buying: true if we can buy now, false if holding stock.

if (i >= n) return 0;
    - Base case: if beyond the last day, profit is 0.

if (dp.find({i, buying}) != dp.end())
    - If this state has already been computed, return cached result.

int cooldown = dfs(i + 1, buying);
    - Option to do nothing and move to the next day.

if (buying) { ... }
    - If we can buy now:
        - Option to buy at prices[i] → go to (i+1, false)
        - Option to cooldown.

else { ... }
    - If we’re holding stock:
        - Option to sell at prices[i] → go to (i+2, true) because of cooldown.
        - Option to cooldown.

dp[{i, buying}] = max(...);
    - Store the maximum of the options in the DP map.

return dp[{i, buying}];
    - Return the computed result for this state.

return dfs(0, true);
    - Start from day 0 with buying = true.

*/

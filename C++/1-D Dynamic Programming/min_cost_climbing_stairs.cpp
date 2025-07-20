#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        /*
            Approach:
            - Dynamic Programming (bottom-up)
            - Append a 0 at the end of the cost vector to represent the "top" of the stairs (no cost to step off).
            - Traverse the array from the second-last real step backwards.
            - At each step, set cost[i] = cost of this step + min(cost of next one or two steps).
            - At the end, choose min(cost[0], cost[1]) since you can start from either step 0 or 1.

            Time Complexity: O(n)
                - We loop through the cost array once.

            Space Complexity: O(1)
                - We modify the `cost` array in-place, no extra space required.
        */

        cost.push_back(0); // Add a step at the end with 0 cost (the top of the stairs)

        // Start from the 3rd-to-last element and move backwards
        for (int i = cost.size() - 3; i >= 0; --i) {
            // Update cost[i] as cost[i] + min(cost[i+1], cost[i+2])
            cost[i] += min(cost[i + 1], cost[i + 2]);
        }

        // Return the minimum of starting from step 0 or step 1
        return min(cost[0], cost[1]);
    }
};

/*
================ LINE-BY-LINE SYNTAX EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ libraries like vector, iostream, etc.

using namespace std;
    - Avoids having to prefix `std::` for standard library functions or classes.

class Solution {
public:
    - Defines a class `Solution` with public member functions.

int minCostClimbingStairs(vector<int>& cost)
    - Function that takes a reference to a vector of integers `cost` and returns an integer.

cost.push_back(0);
    - Appends a 0 to the end of the `cost` vector to represent the top of the stairs.

for (int i = cost.size() - 3; i >= 0; --i)
    - Loop from the third-to-last element (`size()-3`) down to 0 (inclusive).

cost[i] += min(cost[i + 1], cost[i + 2]);
    - Updates `cost[i]` to include its cost plus the minimum of the next one or two steps.

return min(cost[0], cost[1]);
    - After filling the `cost` vector, returns the minimum cost of starting from step 0 or step 1.

*/

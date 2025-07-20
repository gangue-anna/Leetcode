#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Function to find the starting gas station index from which
     * you can travel around the circuit once.
     *
     * Approach:
     * - If total gas < total cost, it's impossible to complete the circuit → return -1.
     * - Otherwise, use a greedy strategy:
     *   - Track remaining gas (`total`) while iterating over stations.
     *   - If `total` becomes negative, it means you cannot reach the next station.
     *   - Reset `total` to 0 and set start index to the next station.
     * - At the end, `res` will hold the correct starting index.
     *
     * Time Complexity: O(N) — single pass through the stations.
     * Space Complexity: O(1) — constant extra space.
     */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        // If total gas < total cost, not possible to complete circuit
        if (totalGas < totalCost) 
            return -1;

        int total = 0;    // Tracks remaining gas during the iteration
        int res = 0;      // Stores the starting index

        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];

            if (total < 0) {
                // Cannot reach next station; reset start position
                total = 0;
                res = i + 1;
            }
        }

        return res;
    }
};

/*
====================================================
Line-by-line C++ syntax explanation:
====================================================

#include <bits/stdc++.h>
    -> Includes all standard C++ libraries (like <vector>, <string>, <numeric>, etc.)

using namespace std;
    -> Allows using standard library names (like vector, accumulate) without std:: prefix.

class Solution {
public:
    -> Defines a class named Solution with public member functions.

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    -> Defines a method `canCompleteCircuit` that takes two vectors of integers (gas and cost) and returns an int.

int totalGas = accumulate(gas.begin(), gas.end(), 0);
int totalCost = accumulate(cost.begin(), cost.end(), 0);
    -> Compute the sum of `gas` and `cost` using the `accumulate` function from <numeric>.

if (totalGas < totalCost)
    return -1;
    -> If total available gas is less than total cost, it’s impossible to complete the circuit.

int total = 0;
    -> Tracks remaining gas as we iterate.

int res = 0;
    -> Stores the potential starting station index.

for (int i = 0; i < gas.size(); ++i) {
    -> Loop over each station.

total += gas[i] - cost[i];
    -> Update remaining gas after visiting this station.

if (total < 0) {
    -> If remaining gas becomes negative, reset.

total = 0;
    -> Reset total gas to 0.

res = i + 1;
    -> Set the next station as the new potential starting point.

return res;
    -> Return the found starting index.

====================================================
Time Complexity:
    - O(N): Each station is visited exactly once.

Space Complexity:
    - O(1): Uses a few integer variables regardless of input size.
====================================================
*/


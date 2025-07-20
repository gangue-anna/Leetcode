#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        /*
            Approach:
            - Use a variation of Bellman-Ford algorithm to find the cheapest price with at most k stops.
            - Relax all edges up to (k+1) times (because k stops mean k+1 edges).
            - In each iteration, keep a temporary prices array to avoid using updated values in the same round.
            - After k+1 iterations, if dst is still infinite, return -1 (unreachable).
            
            Time Complexity: O(k * E), where E = number of flights
            - Each round processes all E flights.
            - Total rounds = k+1.
            
            Space Complexity: O(n)
            - We use two arrays of size n to track current and next prices.
        */

        vector<int> prices(n, INT_MAX); // Current minimum prices from src to each city
        prices[src] = 0;                // Starting city cost is 0

        for (int i = 0; i <= k; ++i) {
            vector<int> tmpPrices = prices; // Copy current prices to avoid in-round updates

            for (auto& flight : flights) {
                int s = flight[0], d = flight[1], p = flight[2];
                if (prices[s] == INT_MAX) continue; // If source city is not reachable yet, skip
                if (prices[s] + p < tmpPrices[d]) {
                    tmpPrices[d] = prices[s] + p;  // Relax edge if cheaper path found
                }
            }

            prices = tmpPrices; // Update prices for next round
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};

/*
================ LINE-BY-LINE SYNTAX EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ libraries (vectors, iostream, algorithm, etc.).

using namespace std;
    - So we don’t have to write std:: before every standard library function.

class Solution {
public:
    - Defines the Solution class with public methods.

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    - Function signature: returns int.
    - Inputs:
        n      - number of cities.
        flights - list of flights, each as [source, dest, price].
        src     - starting city.
        dst     - destination city.
        k       - maximum number of stops allowed.

vector<int> prices(n, INT_MAX);
    - Initialize a vector of size n with all values as INT_MAX (infinity), representing min prices.
    - INT_MAX is the maximum integer value in C++.

prices[src] = 0;
    - Set the price of the starting city to 0 (since we are already there).

for (int i = 0; i <= k; ++i)
    - Iterate up to (k+1) rounds (since k stops == k+1 edges).

vector<int> tmpPrices = prices;
    - Copy current prices to a temporary vector to avoid using updated values in the same round.

for (auto& flight : flights)
    - Iterate through each flight.
    - flight[0] = source city, flight[1] = dest city, flight[2] = price.

if (prices[s] == INT_MAX) continue;
    - If source city hasn’t been reached yet, skip.

if (prices[s] + p < tmpPrices[d])
    - If we find a cheaper path to city d through city s, update tmpPrices[d].

prices = tmpPrices;
    - After processing all flights for this round, update prices.

return prices[dst] == INT_MAX ? -1 : prices[dst];
    - If destination city is still unreachable, return -1.
    - Otherwise, return the cheapest price found.

*/


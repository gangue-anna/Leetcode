#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Function to count the number of distinct subsequences of `s` that equals `t`.
     *
     * Approach: Bottom-up Dynamic Programming
     * dp[i][j] = number of ways to form t[0..j-1] from s[0..i-1]
     *
     * Time Complexity: O(m * n) where m = s.size(), n = t.size()
     * Space Complexity: O(m * n) for the DP table
     */
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        // Create DP table of size (m+1) x (n+1), initialized with 0
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        // Base case: empty t can always be formed from any prefix of s in 1 way
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // Start by taking the number of ways without current s[i-1]
                dp[i][j] = dp[i-1][j];

                // If s[i-1] == t[j-1], we can also include this character
                if (s[i-1] == t[j-1]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }

        // The answer is dp[m][n]: ways to form all of t from all of s
        return dp[m][n];
    }
};

/*
=============================================
Line-by-line C++ syntax explanation:
=============================================

#include <bits/stdc++.h>
    -> Includes all standard C++ libraries at once (like <vector>, <iostream>, <string>, etc.)

using namespace std;
    -> Allows using standard library names (like vector, string) without prefixing them with std::

class Solution {
public:
    -> Defines a class called Solution, with public member functions.

int numDistinct(string s, string t) {
    -> Defines a member function `numDistinct` that takes two strings and returns an int.

int m = s.size();
int n = t.size();
    -> Store the lengths of strings s and t in variables m and n.

vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
    -> Creates a 2D vector (matrix) of size (m+1) x (n+1), initialized to 0. We use long long to prevent overflow.

for (int i = 0; i <= m; ++i) {
    dp[i][0] = 1;
}
    -> Initialize the base case: an empty t can be formed from any prefix of s in 1 way.

for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
        dp[i][j] = dp[i-1][j];
        if (s[i-1] == t[j-1]) {
            dp[i][j] += dp[i-1][j-1];
        }
    }
}
    -> Fill the DP table bottom-up.
    -> At each position (i,j), we consider two cases:
       - not using s[i-1]: take dp[i-1][j]
       - using s[i-1] if it matches t[j-1]: add dp[i-1][j-1]

return dp[m][n];
    -> Return the total number of ways to form t from s.

=============================================
Time Complexity:
    - Two nested loops: O(m * n)

Space Complexity:
    - DP table of size (m+1) x (n+1): O(m * n)
=============================================
*/


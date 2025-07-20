#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        /*
            Problem: Check if s3 is an interleaving of s1 and s2.

            Approach:
            - Use a DP table where dp[i][j] = true if s3[i+j:] can be formed
              by interleaving s1[i:] and s2[j:].
            - Fill the table in reverse order (from the end towards the start).
            - Time: O(len(s1) * len(s2))
            - Space: O(len(s1) * len(s2))
        */

        int m = s1.size(), n = s2.size(), l = s3.size();

        // Early check: sum of lengths must match
        if (m + n != l) return false;

        // Initialize DP table with all false
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base case: all strings exhausted
        dp[m][n] = true;

        // Fill the DP table bottom-up
        for (int i = m; i >= 0; --i) {
            for (int j = n; j >= 0; --j) {
                if (i < m && s1[i] == s3[i + j] && dp[i + 1][j]) {
                    dp[i][j] = true;
                }
                if (j < n && s2[j] == s3[i + j] && dp[i][j + 1]) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[0][0];
    }
};

/*
=================== LINE-BY-LINE EXPLANATION ===================

#include <bits/stdc++.h>
    - Includes all standard C++ libraries (like vector, string, etc.).

using namespace std;
    - Lets us use names like vector, cout, etc. without prefixing them with std::.

class Solution {
    - Defines a class named Solution.

public:
    - Public section of the class; the method is accessible from outside.

bool isInterleave(string s1, string s2, string s3)
    - Function that checks if s3 is formed by interleaving s1 and s2.
    - Takes three strings as input and returns true or false.

int m = s1.size(), n = s2.size(), l = s3.size();
    - m = length of s1, n = length of s2, l = length of s3.

if (m + n != l) return false;
    - If the combined length of s1 and s2 does not equal length of s3, return false.

vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    - Creates a 2D vector (m+1 by n+1) initialized to false.
    - dp[i][j] = true if s3[i+j:] can be formed by s1[i:] and s2[j:].

dp[m][n] = true;
    - Base case: if both s1 and s2 are exhausted, then s3 is also exhausted → true.

for (int i = m; i >= 0; --i) {
    - Loop backwards over s1.

for (int j = n; j >= 0; --j) {
    - Loop backwards over s2.

if (i < m && s1[i] == s3[i + j] && dp[i + 1][j])
    - If current char of s1 matches current char of s3 and dp[i+1][j] is true,
      then set dp[i][j] to true.

if (j < n && s2[j] == s3[i + j] && dp[i][j + 1])
    - If current char of s2 matches current char of s3 and dp[i][j+1] is true,
      then set dp[i][j] to true.

return dp[0][0];
    - Return true if starting from (0,0) we can form s3 by interleaving.
}
*/


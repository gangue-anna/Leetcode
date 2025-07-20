#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        /*
            Problem:
            - Find the length of the longest common subsequence (LCS) of two strings.
            - A subsequence does not require contiguous characters, but order must be maintained.

            Approach:
            - Dynamic Programming with a 2D DP table.
            - dp[i][j] represents the LCS length of text1[i:] and text2[j:].
            - Build the table bottom-up: from bottom-right to top-left.

            Time Complexity: O(m * n)
                - Fill each cell of the DP table once.
            Space Complexity: O(m * n)
                - DP table of size (m+1) x (n+1).
        */

        int m = text1.size();
        int n = text2.size();

        // Initialize a (m+1) x (n+1) DP table with all zeros
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Iterate through text1 and text2 from end to start
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    // If characters match, add 1 to the diagonal value
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    // If not, take the maximum of right and down
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];  // Final answer is at dp[0][0]
    }
};

/*
================ LINE-BY-LINE EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ libraries in one line (e.g., vector, string, etc.).

using namespace std;
    - Allows us to write vector, string, etc., without the std:: prefix.

class Solution {
    - Defines a class named Solution.

public:
    - Declares that the following method is public (accessible from outside the class).

int longestCommonSubsequence(string text1, string text2)
    - Function that returns an int and takes two strings as input.

int m = text1.size();
int n = text2.size();
    - Get the lengths of text1 and text2.

vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    - Create a 2D vector of size (m+1) x (n+1), initialized to 0.

for (int i = m - 1; i >= 0; i--)
    - Loop over text1 from the last character to the first.

for (int j = n - 1; j >= 0; j--)
    - Loop over text2 from the last character to the first.

if (text1[i] == text2[j])
    - If the characters at position i and j match…

dp[i][j] = 1 + dp[i + 1][j + 1];
    - …then the LCS includes this character + result of the remaining substring.

else
    - If they don’t match…

dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
    - …then take the longer LCS from skipping one character from either string.

return dp[0][0];
    - The answer (length of LCS) is stored at dp[0][0] after filling the table.

*/

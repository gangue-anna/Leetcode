#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Function to compute the minimum edit distance between word1 and word2
     * 
     * Approach: Bottom-up Dynamic Programming
     * dp[i][j] = minimum operations to convert word1[i:] to word2[j:]
     * 
     * Time Complexity: O(m * n) where m = word1.size(), n = word2.size()
     * Space Complexity: O(m * n) for DP table
     */
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // Create DP table of size (m+1) x (n+1), initialized to 0
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base case: convert suffix of word1[i:] to empty string
        for (int i = 0; i <= m; ++i) {
            dp[i][n] = m - i;  // delete all remaining characters of word1
        }

        // Base case: convert empty string to suffix of word2[j:]
        for (int j = 0; j <= n; ++j) {
            dp[m][j] = n - j;  // insert all remaining characters of word2
        }

        // Fill the DP table bottom-up
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    // Characters match → no operation needed
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    // Characters don't match → consider 3 options
                    int insertOp = dp[i][j + 1];      // insert word2[j] into word1
                    int deleteOp = dp[i + 1][j];      // delete word1[i]
                    int replaceOp = dp[i + 1][j + 1]; // replace word1[i] with word2[j]

                    // Take minimum of the 3 options + 1 operation
                    dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        return dp[0][0];  // answer is at dp[0][0]
    }
};

/*
=================================================
Line-by-line C++ syntax explanation:
=================================================

#include <bits/stdc++.h>
    -> Includes all standard C++ libraries (like <vector>, <string>, <iostream>, etc.)

using namespace std;
    -> Allows using standard library names (like vector, string) without prefixing them with std::

class Solution {
public:
    -> Defines a class named Solution with public member functions.

int minDistance(string word1, string word2) {
    -> Defines a member function `minDistance` that takes two strings and returns an int.

int m = word1.size();
int n = word2.size();
    -> Get the lengths of word1 and word2 and store in variables m and n.

vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    -> Create a 2D vector (matrix) of size (m+1) x (n+1), initialized to 0.

for (int i = 0; i <= m; ++i) {
    dp[i][n] = m - i;
}
    -> Base case: to convert word1[i:] to empty string, we need to delete remaining characters.

for (int j = 0; j <= n; ++j) {
    dp[m][j] = n - j;
}
    -> Base case: to convert empty string to word2[j:], we need to insert remaining characters.

for (int i = m - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
        if (word1[i] == word2[j]) {
            dp[i][j] = dp[i + 1][j + 1];
        } else {
            int insertOp = dp[i][j + 1];
            int deleteOp = dp[i + 1][j];
            int replaceOp = dp[i + 1][j + 1];
            dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
        }
    }
}
    -> Fill the DP table bottom-up.
    -> If characters match, carry forward the result from next indices.
    -> Otherwise, consider inserting, deleting, or replacing, and take minimum.

return dp[0][0];
    -> Return the minimum edit distance to convert word1 to word2.

=================================================
Time Complexity:
    - Two nested loops → O(m * n)

Space Complexity:
    - DP table of size (m+1) x (n+1) → O(m * n)
=================================================
*/


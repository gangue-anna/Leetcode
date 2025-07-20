#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Function to check if string `s` matches pattern `p`
     * where `p` can include '.' (matches any character) and '*' (matches 0 or more of previous char).
     *
     * Approach: DFS + Memoization
     * - Recursively try to match `s[i:]` and `p[j:]`
     * - Memoize intermediate results to avoid recomputation.
     *
     * Time Complexity: O(m * n) where m = s.size(), n = p.size()
     * Space Complexity: O(m * n) for the memoization table
     */
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();

        // Memoization table: map from pair<int,int> → bool
        unordered_map<long long, bool> memo;

        // Define the DFS helper function as a lambda
        function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            // Encode (i,j) as a single key
            long long key = ((long long)i << 32) | j;

            // Check if result is already computed
            if (memo.find(key) != memo.end())
                return memo[key];

            // Base case: both strings are exhausted
            if (i >= m && j >= n)
                return memo[key] = true;

            // Base case: pattern exhausted but string remains
            if (j >= n)
                return memo[key] = false;

            // Check if current characters match (or dot)
            bool match = (i < m) && (s[i] == p[j] || p[j] == '.');

            // If next pattern character is '*'
            if ((j + 1) < n && p[j + 1] == '*') {
                // Try zero occurrence of p[j] or one-or-more if match
                memo[key] = dfs(i, j + 2) || (match && dfs(i + 1, j));
                return memo[key];
            }

            // Regular match: advance both if match
            if (match) {
                memo[key] = dfs(i + 1, j + 1);
                return memo[key];
            }

            // No match
            return memo[key] = false;
        };

        return dfs(0, 0);
    }
};

/*
=================================================
Line-by-line C++ syntax explanation:
=================================================

#include <bits/stdc++.h>
    -> Includes all standard C++ libraries (like <vector>, <string>, <unordered_map>, etc.)

using namespace std;
    -> Allows using names from the standard library (like string, vector) without prefixing with std::

class Solution {
public:
    -> Defines a class named Solution with public methods.

bool isMatch(string s, string p) {
    -> Defines a method `isMatch` that takes two strings `s` and `p` and returns a bool.

int m = s.size(), n = p.size();
    -> Get the lengths of `s` and `p`.

unordered_map<long long, bool> memo;
    -> Hash table to store intermediate results.
       Uses `long long` as key (to encode (i,j)) and `bool` as value.

function<bool(int, int)> dfs = [&](int i, int j) -> bool {
    -> Defines a lambda function `dfs` that captures `memo` and `m`, `n` by reference.

long long key = ((long long)i << 32) | j;
    -> Encode the pair (i,j) into a single long long key.

if (memo.find(key) != memo.end())
    return memo[key];
    -> If result for (i,j) already computed, return cached result.

if (i >= m && j >= n)
    return memo[key] = true;
    -> Base case: both strings are fully matched.

if (j >= n)
    return memo[key] = false;
    -> Base case: pattern exhausted but string still has characters.

bool match = (i < m) && (s[i] == p[j] || p[j] == '.');
    -> Check if current characters match (including '.' wildcard).

if ((j + 1) < n && p[j + 1] == '*') {
    -> If next character in pattern is '*'.

memo[key] = dfs(i, j + 2) || (match && dfs(i + 1, j));
    -> Either skip the '*' (zero occurrence) or use it (one/more occurrences).

if (match) {
    memo[key] = dfs(i + 1, j + 1);
    return memo[key];
}
    -> If current characters match, move to next in both strings.

return memo[key] = false;
    -> Otherwise, no match.

return dfs(0, 0);
    -> Start recursion from indices (0,0)

=================================================
Time Complexity:
    - There are O(m * n) unique (i,j) states, each computed once → O(m * n)

Space Complexity:
    - Memoization table stores O(m * n) entries → O(m * n)
=================================================
*/


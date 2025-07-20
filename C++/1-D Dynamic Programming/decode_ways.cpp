#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        /*
            Problem:
            - Given a string of digits, count how many ways it can be decoded into letters
              (where '1' -> 'A', ..., '26' -> 'Z').

            Approach:
            - DFS + Memoization (Top-down DP):
                - For each index `i`, calculate the number of ways to decode `s[i:]`.
                - Base case: if `i == s.size()`, return 1 (empty string is a valid decode).
                - If `s[i] == '0'`, return 0 because '0' cannot map to a letter.
                - Try to decode:
                    - One digit (always possible if `s[i] != 0`).
                    - Two digits if valid (10 to 26).

            Time Complexity: O(n)
                - Each position `i` is visited at most once due to memoization.
            Space Complexity: O(n)
                - For the memoization map and recursion stack.
        */

        unordered_map<int, int> dp; // memoization: dp[i] = ways to decode s[i:]

        function<int(int)> dfs = [&](int i) {
            // If we've reached the end, one valid decode
            if (i == s.size()) return 1;

            // If this state already computed, return it
            if (dp.count(i)) return dp[i];

            // If current character is '0', no valid decode
            if (s[i] == '0') return 0;

            int res = dfs(i + 1); // decode single digit

            // decode two digits if within bounds and valid (10–26)
            if (i + 1 < s.size()) {
                int twoDigit = stoi(s.substr(i, 2));
                if (twoDigit >= 10 && twoDigit <= 26) {
                    res += dfs(i + 2);
                }
            }

            dp[i] = res; // memoize
            return res;
        };

        return dfs(0);
    }
};

/*
================ LINE-BY-LINE SYNTAX EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ libraries.

using namespace std;
    - Use the standard namespace to avoid writing std:: everywhere.

class Solution {
    - Defines a class named Solution.

public:
    - Makes the following method publicly accessible.

int numDecodings(string s)
    - Function `numDecodings` takes a string `s` and returns an int (number of ways to decode it).

unordered_map<int, int> dp;
    - A hash map for memoization where key = index `i`, value = ways to decode from `i`.

function<int(int)> dfs = [&](int i) {
    - Defines a recursive lambda function `dfs` that takes `i` and returns an int.

if (i == s.size()) return 1;
    - Base case: if we reach the end of the string, return 1 (valid decode).

if (dp.count(i)) return dp[i];
    - If result for `i` is already computed, return it.

if (s[i] == '0') return 0;
    - If current char is '0', no way to decode, return 0.

int res = dfs(i + 1);
    - Try decoding one character and add result.

if (i + 1 < s.size())
    - Check if two-character decode is possible.

int twoDigit = stoi(s.substr(i, 2));
    - Convert substring s[i:i+2] to integer.

if (twoDigit >= 10 && twoDigit <= 26)
    - If two-digit number is between 10 and 26, valid decode.

res += dfs(i + 2);
    - Add ways from decoding two characters.

dp[i] = res;
    - Memoize the result for index `i`.

return dfs(0);
    - Start recursion from index 0.

*/

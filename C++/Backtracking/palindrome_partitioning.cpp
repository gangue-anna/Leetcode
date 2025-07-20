#include <bits/stdc++.h>
using namespace std;

/**
 * Approach:
 * - Use backtracking (DFS) to explore all possible partitions of the string.
 * - At each step, iterate through all substrings starting from the current index.
 * - If the substring is a palindrome, include it in the current path and recurse.
 * - When we reach the end of the string, save the current path to the result.
 * - Use a helper function to check if a given substring is a palindrome.
 *
 * Time Complexity: O(2^n * n), where n = length of string
 *   → 2^n choices of partitions × O(n) to check palindrome
 * Space Complexity: O(n) (recursion stack) + O(2^n * n) (result)
 */

class Solution {
public:
    vector<vector<string>> res;      // To store all valid partitions
    vector<string> part;            // Current partition being built

    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return res;
    }

private:
    void dfs(int i, string& s) {
        if (i >= s.size()) {
            res.push_back(part);    // Reached end, save current partition
            return;
        }
        for (int j = i; j < s.size(); ++j) {
            if (isPalindrome(s, i, j)) {
                part.push_back(s.substr(i, j - i + 1));  // choose substring
                dfs(j + 1, s);                           // recurse
                part.pop_back();                         // backtrack
            }
        }
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
};

/*
------------------------------------------------------
📄 Line-by-Line C++ Syntax Explanation:
------------------------------------------------------

#include <bits/stdc++.h>
    → Includes all standard C++ headers (vector, string, etc.)

using namespace std;
    → Avoids having to prefix everything with std::

class Solution { ... };
    → Defines a class named Solution.

vector<vector<string>> res;
    → A 2D vector to store all the partitions.

vector<string> part;
    → Stores the current path (one possible partition).

vector<vector<string>> partition(string s)
    → Public function that starts the process, returns all partitions.

dfs(0, s);
    → Start DFS at index 0 with the string s.

void dfs(int i, string& s)
    → Recursive helper function to explore partitions starting at index i.

if (i >= s.size())
    → Base case: reached end of string.

res.push_back(part);
    → Save a copy of current partition.

for (int j = i; j < s.size(); ++j)
    → Try all substrings starting at i and ending at j.

if (isPalindrome(s, i, j))
    → If current substring is a palindrome, proceed.

part.push_back(s.substr(i, j - i + 1));
    → Add substring [i..j] to the current partition.

dfs(j + 1, s);
    → Recurse from the next index after j.

part.pop_back();
    → Backtrack: remove last added substring.

bool isPalindrome(string& s, int l, int r)
    → Checks if substring s[l..r] is a palindrome.

while (l < r) { ... }
    → Compare characters from both ends toward the center.

return true;
    → If all characters match, it is a palindrome.

------------------------------------------------------

⏱ Complexity:
- Time: O(2^n × n), exponential because of all possible partitions.
- Space: O(n) for recursion stack + result storage.
------------------------------------------------------
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        /*
            Problem:
            - Find the longest palindromic substring in a given string.

            Approach:
            - For each index `i` in the string, treat it as the center of a potential palindrome.
            - Expand outward in both directions for:
                - Odd-length palindromes (centered at i)
                - Even-length palindromes (centered between i and i+1)
            - Keep track of the longest palindrome seen so far.

            Time Complexity: O(n^2)
                - For each character, we may expand up to n times.
            Space Complexity: O(1)
                - Only variables to track indices and result.
        */

        string res = "";     // Stores the longest palindrome found
        int resLen = 0;      // Length of longest palindrome

        for (int i = 0; i < s.size(); ++i) {
            // Odd-length palindrome centered at i
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if ((r - l + 1) > resLen) {
                    res = s.substr(l, r - l + 1);
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }

            // Even-length palindrome centered between i and i+1
            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if ((r - l + 1) > resLen) {
                    res = s.substr(l, r - l + 1);
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return res;
    }
};

/*
================ LINE-BY-LINE SYNTAX EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ libraries (like string, vector, iostream, etc.).

using namespace std;
    - Allows us to use standard library classes/functions without writing `std::` prefix.

class Solution {
    - Defines a class named Solution.

public:
    - Makes the members below accessible outside the class.

string longestPalindrome(string s)
    - Function `longestPalindrome` takes a string `s` as input and returns a string.

string res = "";
    - Initialize an empty string to store the result.

int resLen = 0;
    - Variable to keep track of the length of the longest palindrome.

for (int i = 0; i < s.size(); ++i)
    - Loop through each character of the string.

int l = i, r = i;
    - Set `l` and `r` both to `i` to check for odd-length palindromes.

while (l >= 0 && r < s.size() && s[l] == s[r])
    - Expand outward as long as characters at `l` and `r` are equal and indices are valid.

if ((r - l + 1) > resLen)
    - If the current palindrome is longer than the longest seen so far.

res = s.substr(l, r - l + 1);
    - Update `res` with the new longest palindrome substring.

resLen = r - l + 1;
    - Update the length of the longest palindrome.

l--, r++;
    - Move left pointer one step left and right pointer one step right.

l = i, r = i + 1;
    - Set `l` to `i` and `r` to `i+1` to check for even-length palindromes.

return res;
    - Return the longest palindromic substring found.

*/

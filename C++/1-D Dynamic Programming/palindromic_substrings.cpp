#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        /*
            Problem:
            - Count all palindromic substrings in a given string.

            Approach:
            - Expand Around Center:
                - For each character `i` in the string:
                    - Treat it as the center of an odd-length palindrome and expand.
                    - Treat it as the left of center of an even-length palindrome and expand.
                - Increment the count for every valid palindrome found.

            Time Complexity: O(n^2)
                - For each character, expand up to n times.
            Space Complexity: O(1)
                - Only variables for indices and count.
        */

        int res = 0; // Total number of palindromic substrings

        for (int i = 0; i < s.size(); ++i) {
            // Odd-length palindromes centered at i
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }

            // Even-length palindromes centered between i and i+1
            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res++;
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
    - Includes all standard C++ libraries.

using namespace std;
    - Allows usage of standard library classes and functions without `std::` prefix.

class Solution {
    - Defines a class named Solution.

public:
    - Makes the methods below publicly accessible.

int countSubstrings(string s)
    - Function `countSubstrings` takes a string `s` and returns an int.

int res = 0;
    - Initialize a counter to store the number of palindromic substrings.

for (int i = 0; i < s.size(); ++i)
    - Loop over each character in the string.

int l = i, r = i;
    - Initialize two pointers at the same index to check odd-length palindromes.

while (l >= 0 && r < s.size() && s[l] == s[r])
    - Expand outward while the characters at `l` and `r` are equal.

res++;
    - Increment count for the found palindrome.

l--, r++;
    - Move pointers outward to check for longer palindromes.

l = i, r = i + 1;
    - Initialize pointers for even-length palindrome check.

while (l >= 0 && r < s.size() && s[l] == s[r])
    - Same as above but for even-length palindromes.

return res;
    - Return the total number of palindromic substrings found.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*
            Problem:
            - Given a string `s` and a dictionary of words `wordDict`,
              determine if `s` can be segmented into a space-separated sequence of one or more dictionary words.

            Approach:
            - Use dynamic programming.
            - dp[i] = true if s[i:] can be segmented into words from wordDict.
            - Iterate from the end of the string backwards to build the dp table.

            Time Complexity: O(n * m * k)
                - n = length of string s
                - m = number of words in wordDict
                - k = average length of words in wordDict
            Space Complexity: O(n)
                - dp array of size n+1
        */

        int n = s.size();
        vector<bool> dp(n + 1, false); 
        dp[n] = true; 
        // Base case: empty string can always be segmented

        for (int i = n - 1; i >= 0; i--) {
            for (string& w : wordDict) {
                if (i + w.size() <= n && s.substr(i, w.size()) == w) {
                    if (dp[i + w.size()]) {
                        dp[i] = true;
                        break; // Early exit if segmentation is found
                    }
                }
            }
        }

        return dp[0];
    }
};

/*
================ LINE-BY-LINE SYNTAX EXPLANATION =================

#include <bits/stdc++.h>
    - Includes all standard C++ headers (like vector, string, etc.)

using namespace std;
    - Allows usage of standard C++ classes without std:: prefix.

class Solution {
    - Defines a class named Solution.

public:
    - The following members are public (can be accessed outside the class).

bool wordBreak(string s, vector<string>& wordDict)
    - Function that returns a boolean and takes:
        - string s: the input string
        - vector<string>& wordDict: reference to a vector of strings (dictionary)

int n = s.size();
    - Stores the length of string s in variable n.

vector<bool> dp(n + 1, false);
    - Creates a boolean vector dp of size n+1 and initializes all values to false.

dp[n] = true;
    - Base case: an empty string (after last index) is always segmentable.

for (int i = n - 1; i >= 0; i--)
    - Iterate backwards through the string s.

for (string& w : wordDict)
    - Loop through each word w in the dictionary.

if (i + w.size() <= n && s.substr(i, w.size()) == w)
    - Check if word w fits starting at position i and matches the substring.

if (dp[i + w.size()])
    - Check if the remaining substring after w can also be segmented.

dp[i] = true;
    - If current prefix can lead to segmentation, mark dp[i] as true.

break;
    - Early exit from the inner loop as we already found a valid segmentation at i.

return dp[0];
    - Return true if the entire string can be segmented, false otherwise.

*/

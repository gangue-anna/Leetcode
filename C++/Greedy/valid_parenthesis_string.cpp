#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Function to check if a string with parentheses and '*' can be valid.
     *
     * Approach:
     * - Use two integers, leftMin and leftMax, to keep track of the minimum and maximum number of unmatched '('.
     * - Iterate through each character:
     *     - '(' increases both leftMin and leftMax.
     *     - ')' decreases both leftMin and leftMax.
     *     - '*' can act as '(', ')' or empty:
     *         -> decrease leftMin and increase leftMax.
     * - If at any point leftMax < 0 → too many ')', return false.
     * - If leftMin < 0 → reset to 0, because you can't have negative unmatched '('.
     * - At the end if leftMin == 0 → the string can be balanced, return true.
     *
     * Time Complexity: O(N) — Single pass over the string.
     * Space Complexity: O(1) — Constant extra space.
     */
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;

        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } else if (c == ')') {
                leftMin--;
                leftMax--;
            } else { // c == '*'
                leftMin--;
                leftMax++;
            }

            if (leftMax < 0) {
                // too many ')' encountered
                return false;
            }

            if (leftMin < 0) {
                // we can't have negative unmatched '('
                leftMin = 0;
            }
        }

        return leftMin == 0;
    }
};

/*
====================================================
Line-by-line C++ syntax explanation:
====================================================

#include <bits/stdc++.h>
    -> Includes all standard C++ headers (like <vector>, <string>, <map>, etc.) for convenience.

using namespace std;
    -> Allows you to use standard library names without `std::` prefix.

class Solution {
public:
    -> Defines a class named `Solution` with public methods.

bool checkValidString(string s) {
    -> Defines a method `checkValidString` which takes a string and returns a boolean.

int leftMin = 0, leftMax = 0;
    -> Initializes two integers to track min and max unmatched '('.

for (char c : s) {
    -> Range-based for loop over characters in string `s`.

if (c == '(') {
    -> If current character is '(':
leftMin++, leftMax++;
    -> Increment both counters because we have an unmatched '('.

else if (c == ')') {
    -> If current character is ')':
leftMin--, leftMax--;
    -> Decrement both counters because ')' matches a '('.

else {
    -> If current character is '*':
leftMin--, leftMax++;
    -> Treat '*' as either '(' or ')' or empty.

if (leftMax < 0) {
    -> If max unmatched '(' goes below 0 → invalid → too many ')'.
return false;

if (leftMin < 0) {
    -> If min unmatched '(' < 0 → set it to 0 because it can't be negative.
leftMin = 0;

return leftMin == 0;
    -> At the end, if min unmatched '(' is 0 → balanced → return true.

====================================================
Time Complexity:
    - O(N), where N is the length of the string.

Space Complexity:
    - O(1), only two counters are used.
====================================================
*/


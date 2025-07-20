#include <bits/stdc++.h>
using namespace std;

/**
 * Approach:
 * - Use backtracking to generate all possible letter combinations.
 * - For each digit in the input string, try every possible letter it maps to.
 * - When the current string length equals the digits length, add it to the result.
 * - Handles empty input by returning an empty list.
 *
 * Time Complexity: O(4^n), where n is the length of digits (each digit can map to up to 4 letters).
 * Space Complexity: O(4^n), for result + recursion stack.
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;  // stores all combinations

        if (digits.empty()) 
            return res; // if input is empty, return empty result

        unordered_map<char, string> digitToChar = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        string current = ""; // to build current string during backtracking
        backtrack(0, digits, current, res, digitToChar);
        return res;
    }

private:
    void backtrack(int i, string& digits, string& current, vector<string>& res,
                   unordered_map<char, string>& digitToChar) {
        if (current.size() == digits.size()) {
            res.push_back(current); // found a valid combination
            return;
        }

        for (char c : digitToChar[digits[i]]) {
            current.push_back(c);                  // choose a letter
            backtrack(i + 1, digits, current, res, digitToChar); // recurse
            current.pop_back();                   // backtrack
        }
    }
};

/*
------------------------------------------------------
📄 Line-by-Line C++ Syntax Explanation:
------------------------------------------------------

#include <bits/stdc++.h>
    → Includes all standard headers (vector, string, unordered_map, etc.)

using namespace std;
    → Avoids writing std:: before standard types and functions.

class Solution { ... };
    → Defines a class named Solution.

vector<string> letterCombinations(string digits)
    → Public method that starts the process; returns all combinations.

vector<string> res;
    → Stores the result combinations.

if (digits.empty()) return res;
    → If input is empty, return empty result immediately.

unordered_map<char, string> digitToChar = {...};
    → Maps each digit character to its corresponding string of letters.

string current = "";
    → Tracks the current string being built.

backtrack(0, digits, current, res, digitToChar);
    → Start backtracking from index 0.

void backtrack(...)
    → Private recursive helper function.

if (current.size() == digits.size())
    → Base case: if current string matches length of input, save it.

res.push_back(current);
    → Add current string to result list.

for (char c : digitToChar[digits[i]])
    → Loop through all letters corresponding to current digit.

current.push_back(c);
    → Add current letter to the path.

backtrack(i + 1, digits, current, res, digitToChar);
    → Recurse to next digit.

current.pop_back();
    → Remove last letter to explore other possibilities.

return res;
    → Final result is returned from the public method.

------------------------------------------------------

⏱ Complexity:
- Time: O(4^n), since each digit can have up to 4 choices and there are n digits.
- Space: O(4^n) for result + recursion stack.
------------------------------------------------------
*/


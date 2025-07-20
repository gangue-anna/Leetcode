#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        /*
         * Approach:
         * ✅ Reverse both strings to simplify handling of least significant digits first.
         * ✅ Use a vector<int> to hold intermediate results of multiplication.
         * ✅ Multiply each digit of num1 by each digit of num2 and accumulate into correct position.
         * ✅ Handle carry for each position.
         * ✅ Remove leading zeros and convert vector to string.
         *
         * Time Complexity: O(n * m), where n = len(num1), m = len(num2)
         * Space Complexity: O(n + m) for result vector.
         */
        
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size(), m = num2.size();
        vector<int> res(n + m, 0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int digit = (num1[i] - '0') * (num2[j] - '0');
                res[i + j] += digit;

                res[i + j + 1] += res[i + j] / 10;  // carry to next
                res[i + j] %= 10;                  // current digit
            }
        }

        // Remove leading zeros from the end of result
        while (res.size() > 1 && res.back() == 0) {
            res.pop_back();
        }

        // Convert vector<int> to string
        string result;
        for (int i = res.size() - 1; i >= 0; --i) {
            result.push_back(res[i] + '0');
        }

        return result;
    }
};

/*
 * 📖 Line-by-line explanation:
 *
 * #include <bits/stdc++.h>               → Includes all standard C++ libraries.
 * using namespace std;                  → Allows direct use of standard library names without std::.
 *
 * class Solution { … };                 → Defines a class named Solution.
 *
 * string multiply(string num1, string num2) → Method that multiplies two numbers represented as strings.
 *
 * if (num1 == "0" || num2 == "0") …     → If any number is 0, return "0".
 *
 * int n = num1.size(), m = num2.size(); → Get lengths of the two numbers.
 *
 * vector<int> res(n + m, 0);            → Initialize result vector with size n + m filled with 0.
 *
 * reverse(num1.begin(), num1.end());    → Reverse num1 to process least significant digit first.
 * reverse(num2.begin(), num2.end());    → Reverse num2 similarly.
 *
 * Nested loops (i, j):                 → Multiply each digit of num1 and num2.
 *
 * int digit = (num1[i] - '0') * (num2[j] - '0'); → Convert char to int and multiply.
 *
 * res[i + j] += digit;                 → Add product to the appropriate position.
 *
 * res[i + j + 1] += res[i + j] / 10;   → Carry over any excess (>9) to next position.
 *
 * res[i + j] %= 10;                    → Keep only single digit at position.
 *
 * while (…) res.pop_back();            → Remove any leading zeros from the result vector.
 *
 * string result;                       → To store the final result as string.
 *
 * for (…) result.push_back(res[i] + '0'); → Convert each int digit back to char and build result string.
 *
 * return result;                       → Return the result string.
 *
 */

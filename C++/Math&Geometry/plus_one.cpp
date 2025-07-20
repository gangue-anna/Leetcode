#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /*
         * Approach:
         * ✅ Start from the least significant digit and add 1.
         * ✅ If the digit becomes 10, set it to 0 and carry over 1.
         * ✅ Continue until no carry is left.
         * ✅ If after processing all digits carry is still 1 → insert 1 at the front.
         *
         * Time Complexity: O(n) — we process each digit once.
         * Space Complexity: O(n) — the result vector may grow by 1 element (in case of overflow).
         */
        
        int n = digits.size();
        int carry = 1; // we need to add 1 initially

        for (int i = n - 1; i >= 0; --i) {
            int sum = digits[i] + carry;

            if (sum >= 10) {
                digits[i] = 0;  // set current digit to 0
                carry = 1;      // carry 1 to the next digit
            } else {
                digits[i] = sum; // update digit
                carry = 0;       // no more carry
                break;           // we can stop early
            }
        }

        if (carry) {
            // if carry remains after processing all digits, insert 1 at the front
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

/*
 * 📖 Line-by-line explanation:
 *
 * #include <bits/stdc++.h>                → Includes all standard C++ libraries.
 * using namespace std;                   → Allows direct use of STL containers & functions.
 *
 * class Solution { … };                  → Defines the Solution class.
 *
 * vector<int> plusOne(vector<int>& digits) { … }  → Method to add 1 to the digits vector.
 *
 * int n = digits.size();                → Get number of digits.
 * int carry = 1;                        → Start with carry = 1 because we need to add 1.
 *
 * for (int i = n - 1; i >= 0; --i) {    → Iterate from least significant digit to most.
 *
 * int sum = digits[i] + carry;         → Add current digit + carry.
 *
 * if (sum >= 10) {                     → If the sum overflows (>=10):
 *     digits[i] = 0;                  → Set current digit to 0.
 *     carry = 1;                      → Carry over remains 1.
 * } else {                             → If no overflow:
 *     digits[i] = sum;               → Update digit.
 *     carry = 0;                     → No carry left.
 *     break;                         → Stop processing since no more carry.
 * }
 *
 * if (carry) {                         → After processing all digits, if carry remains:
 *     digits.insert(digits.begin(), 1); → Insert 1 at the beginning of the vector.
 * }
 *
 * return digits;                       → Return the updated digits vector.
 *
 */

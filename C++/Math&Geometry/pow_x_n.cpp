#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        /*
         * Approach:
         * ✅ Use fast exponentiation (iterative).
         * ✅ If n < 0 → invert x and use abs(n) because x^(-n) = 1/(x^n).
         * ✅ Loop while n > 0:
         *      - If n is odd → multiply result by current x.
         *      - Square x and halve n at each step.
         *
         * Time Complexity: O(log n) — because n is halved each time.
         * Space Complexity: O(1) — only a few variables.
         */
        
        if (n == 0) return 1.0;  // Base case: x^0 = 1

        long long N = n;  // use long long to avoid overflow when n = INT_MIN
        bool negative = false;

        if (N < 0) {
            negative = true;
            N = -N;         // take absolute value of n
        }

        double result = 1.0;

        while (N > 0) {
            if (N % 2 == 1) {
                result *= x;    // if N is odd, multiply result by x
            }
            x *= x;            // square x
            N /= 2;            // halve N
        }

        return negative ? (1.0 / result) : result;
    }
};

/*
 * 📖 Line-by-line explanation:
 *
 * #include <bits/stdc++.h>            → Includes all standard C++ headers (like iostream, cmath, etc.).
 * using namespace std;               → Allows direct use of standard library names without std:: prefix.
 *
 * class Solution { … };              → Defines a class named Solution.
 *
 * double myPow(double x, int n) { … } → Method that calculates x raised to the power n.
 *
 * if (n == 0) return 1.0;            → Any number raised to 0 is 1.
 *
 * long long N = n;                  → Copy n into a long long to avoid overflow (especially when n == INT_MIN).
 *
 * bool negative = false;           → Flag to remember if the original n was negative.
 *
 * if (N < 0) { negative = true; N = -N; } → If n < 0, invert and take abs(n).
 *
 * double result = 1.0;              → Initialize result to 1.
 *
 * while (N > 0) { … }               → Loop until N becomes 0.
 *
 * if (N % 2 == 1) { result *= x; } → If N is odd, multiply result by x.
 *
 * x *= x;                          → Square x for the next iteration.
 *
 * N /= 2;                          → Halve N.
 *
 * return negative ? (1.0 / result) : result; → If n was negative, return reciprocal of result.
 *
 */

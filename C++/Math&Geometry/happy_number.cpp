#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        /*
         * Approach:
         * 1️⃣ Use a set to record all numbers we've seen to detect cycles.
         * 2️⃣ Repeatedly replace `n` with the sum of squares of its digits.
         * 3️⃣ If we reach 1 → happy number → return true.
         * 4️⃣ If we encounter a number already in the set → cycle → return false.
         *
         * Time Complexity: O(log n) — because the number of digits and the sum of squares decrease fast.
         * Space Complexity: O(log n) — the set of seen numbers is small (bounded for base 10).
         */
        unordered_set<int> visit;

        while (visit.find(n) == visit.end()) {
            visit.insert(n);
            n = sumOfSquares(n);

            if (n == 1) return true;
        }

        return false;
    }

private:
    int sumOfSquares(int n) {
        /*
         * Helper function to compute sum of squares of digits of `n`.
         */
        int output = 0;

        while (n > 0) {
            int digit = n % 10;
            output += digit * digit;
            n /= 10;
        }

        return output;
    }
};

/*
 * 📖 Line-by-line explanation:
 *
 * #include <bits/stdc++.h>                  → Includes all standard C++ headers.
 * using namespace std;                     → Allows using STL classes & functions directly.
 *
 * class Solution { … };                    → Defines a Solution class.
 *
 * bool isHappy(int n) { … }                → Main function to check if `n` is happy.
 *
 * unordered_set<int> visit;               → A set to track numbers we've seen.
 *
 * while (visit.find(n) == visit.end())    → While `n` is NOT in the set (no cycle detected):
 *     visit.insert(n);                   → Add `n` to the set.
 *     n = sumOfSquares(n);              → Replace `n` with the sum of squares of its digits.
 *     if (n == 1) return true;          → If we reach 1 → happy number.
 *
 * return false;                          → If we exit the loop, a cycle was detected → not happy.
 *
 * int sumOfSquares(int n) { … }           → Helper function.
 *
 * int output = 0;                         → Initialize sum.
 *
 * while (n > 0) {                         → While there are digits left in `n`:
 *     int digit = n % 10;               → Get the last digit.
 *     output += digit * digit;         → Add its square to output.
 *     n /= 10;                         → Remove last digit from `n`.
 * }
 *
 * return output;                         → Return the computed sum of squares.
 */

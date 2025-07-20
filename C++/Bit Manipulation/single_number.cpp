#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Approach:
     * - Use XOR (^) to find the single number.
     * - Every number that appears twice cancels out (since n ^ n = 0).
     * - The number that appears only once remains at the end.
     *
     * Time Complexity: O(n)
     * - We iterate through the array once.
     *
     * Space Complexity: O(1)
     * - We only use a single integer variable for the result.
     */
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int n : nums) {
            res ^= n;  // XOR current number with result
        }
        return res;
    }
};

/*
 * 📖 Line-by-line explanation:
 *
 * #include <bits/stdc++.h>        → Includes all standard C++ libraries.
 * using namespace std;            → Allows usage of standard library names without `std::` prefix.
 *
 * class Solution { … };           → Defines a class named Solution.
 *
 * public:                         → All members below are accessible outside the class.
 *
 * int singleNumber(vector<int>& nums) { … } → Function that finds the single number.
 *
 * int res = 0;                    → Initialize result variable to 0.
 *
 * for (int n : nums) { … }       → Range-based for loop to iterate over all elements in nums.
 *
 * res ^= n;                       → XOR current number with res. (res = res ^ n)
 *                                  → Numbers appearing twice cancel out, leaving the unique number.
 *
 * return res;                      → Return the single number.
 *
 */

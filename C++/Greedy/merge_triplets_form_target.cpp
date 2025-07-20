#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Function to check if target triplet can be formed by merging some of the given triplets.
     *
     * Approach:
     * - Iterate over each triplet.
     * - Skip any triplet where a value exceeds the corresponding target value.
     * - For valid triplets, if a value equals the corresponding target value, mark it as achieved.
     * - If we can achieve all three positions (0,1,2), return true.
     *
     * Time Complexity: O(N) — one pass over all triplets.
     * Space Complexity: O(1) — only a few bool flags are used.
     */
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // Flags to check if each of the 3 positions has been matched to the target
        bool found0 = false, found1 = false, found2 = false;

        for (const auto& t : triplets) {
            // Skip triplets with any value greater than the corresponding target
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2])
                continue;

            // Check which positions of target are achieved by this triplet
            if (t[0] == target[0]) found0 = true;
            if (t[1] == target[1]) found1 = true;
            if (t[2] == target[2]) found2 = true;
        }

        // Return true if all three positions have been achieved
        return found0 && found1 && found2;
    }
};

/*
====================================================
Line-by-line C++ syntax explanation:
====================================================

#include <bits/stdc++.h>
    -> Includes all standard C++ libraries (like <vector>, <iostream>, <string>, etc.)

using namespace std;
    -> Allows using standard library names without writing std:: before them.

class Solution {
public:
    -> Defines a class named Solution with public member functions.

bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    -> Defines a method `mergeTriplets` that takes a 2D vector of integers and a vector of integers as input and returns a bool.

bool found0 = false, found1 = false, found2 = false;
    -> Three boolean flags to track if target[0], target[1], and target[2] have been achieved.

for (const auto& t : triplets) {
    -> Range-based for loop. `t` is a reference to each triplet (vector<int>) in `triplets`.

if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2])
    continue;
    -> Skip the current triplet if it has any value greater than the corresponding value in target.

if (t[0] == target[0]) found0 = true;
if (t[1] == target[1]) found1 = true;
if (t[2] == target[2]) found2 = true;
    -> Update flags if this triplet contributes to achieving the target values.

return found0 && found1 && found2;
    -> Return true only if all three flags are true (target can be formed).

====================================================
Time Complexity:
    - O(N), where N is the number of triplets.

Space Complexity:
    - O(1), constant space for the flags.
====================================================
*/


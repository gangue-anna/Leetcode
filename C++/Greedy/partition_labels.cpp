#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Function to partition the string so that each character appears in at most one part.
     *
     * Approach:
     * - First pass: Record the last occurrence index of each character.
     * - Second pass: Iterate and keep extending the current partition to the farthest
     *   last occurrence of characters seen so far.
     * - When current index equals the end of the partition, record the size.
     *
     * Time Complexity: O(N), where N is the length of the string.
     * Space Complexity: O(1), because we store last indices for at most 26 lowercase letters.
     */
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;  // map each character to its last occurrence

        // First pass: record last occurrence of each character
        for (int i = 0; i < s.size(); ++i) {
            lastIndex[s[i]] = i;
        }

        vector<int> res;     // stores partition sizes
        int size = 0, end = 0;

        // Second pass: build partitions
        for (int i = 0; i < s.size(); ++i) {
            ++size;  // increase current partition size
            end = max(end, lastIndex[s[i]]);  // update the farthest end of current partition

            if (i == end) {
                // current partition ends here
                res.push_back(size);
                size = 0;  // reset size for next partition
            }
        }

        return res;
    }
};

/*
====================================================
Line-by-line C++ syntax explanation:
====================================================

#include <bits/stdc++.h>
    -> Includes most of the standard C++ libraries (like <vector>, <unordered_map>, <iostream>, etc.).

using namespace std;
    -> Avoids writing std:: prefix everywhere for standard library names.

class Solution {
public:
    -> Defines a class named Solution with public member functions.

vector<int> partitionLabels(string s) {
    -> Defines a method `partitionLabels` that takes a string and returns a vector of integers.

unordered_map<char, int> lastIndex;
    -> A hash map to store the last occurrence of each character in the string.

for (int i = 0; i < s.size(); ++i) {
    -> Loop through each character of the string.
lastIndex[s[i]] = i;
    -> Store/update the last index of character s[i].

vector<int> res;
    -> Declare a vector to store the result (partition sizes).

int size = 0, end = 0;
    -> Initialize the current partition size and the end of the current partition.

for (int i = 0; i < s.size(); ++i) {
    -> Loop through each character of the string again.

++size;
    -> Increment the size of the current partition.

end = max(end, lastIndex[s[i]]);
    -> Update the end of the current partition if this character's last index is farther.

if (i == end) {
    -> If the current index equals the end of the partition:
res.push_back(size);
    -> Store the size of the current partition in the result vector.
size = 0;
    -> Reset size for the next partition.

return res;
    -> Return the result vector.

====================================================
Time Complexity:
    - O(N), two passes over the string.

Space Complexity:
    - O(1), because unordered_map has at most 26 keys.

====================================================
*/

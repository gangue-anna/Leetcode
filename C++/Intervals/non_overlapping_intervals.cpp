#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Find the minimum number of intervals to remove to make the rest non-overlapping.
     *
     * Time Complexity: O(N log N), where N is the number of intervals
     *   - Sorting takes O(N log N)
     *   - Iteration is O(N)
     *
     * Space Complexity: O(1)
     *   - Only a constant number of variables are used
     */
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals by their start time
        sort(intervals.begin(), intervals.end());

        int res = 0;  // Counter for removals
        int prevEnd = intervals[0][1];  // End of the previous interval

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start >= prevEnd) {
                // No overlap: move prevEnd forward
                prevEnd = end;
            } else {
                // Overlap: increment removal count and keep interval with smallest end
                res++;
                prevEnd = min(prevEnd, end);
            }
        }

        return res;
    }
};

/*
===========================================================
Line-by-line C++ syntax explanation:
===========================================================

#include <bits/stdc++.h>
    → Includes all standard C++ libraries (like vector, algorithm, iostream, etc.).

using namespace std;
    → Allows you to use standard library names without prefixing them with std::.

class Solution {
public:
    → Defines a class named Solution with public methods.

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    → Defines a method that:
       - Takes a reference to a vector of vectors of integers (`intervals`)
       - Returns an integer

sort(intervals.begin(), intervals.end());
    → Sorts the intervals in increasing order of their start time.

int res = 0;
    → Initialize a counter for the number of intervals to remove.

int prevEnd = intervals[0][1];
    → Initialize `prevEnd` as the end of the first interval.

for (int i = 1; i < intervals.size(); i++) {
    → Loop through the intervals starting from the second one.

int start = intervals[i][0];
int end = intervals[i][1];
    → Get the start and end of the current interval.

if (start >= prevEnd) {
    → If there is no overlap:
prevEnd = end;
    → Update `prevEnd` to the end of the current interval.

else {
    → Overlap detected:
res++;
    → Increment the count of removals.

prevEnd = min(prevEnd, end);
    → Keep the interval with the smaller end time (greedy choice).

return res;
    → Return the minimum number of intervals to remove.

===========================================================
Time Complexity: O(N log N) because of sorting.
Space Complexity: O(1) since no extra space proportional to N is used.
===========================================================
*/


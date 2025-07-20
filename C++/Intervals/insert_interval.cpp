#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Insert a new interval into the list of non-overlapping intervals and merge if needed.
     *
     * Time Complexity: O(N), where N = number of intervals.
     *   - Each interval is processed at most once.
     * Space Complexity: O(N), as we build a result vector.
     */
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); i++) {
            // Case 1: newInterval is before the current interval and does not overlap
            if (newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                // Append the rest of the intervals as they are
                res.insert(res.end(), intervals.begin() + i, intervals.end());
                return res;
            }
            // Case 2: newInterval is after the current interval and does not overlap
            else if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            }
            // Case 3: overlapping intervals — merge
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        // Add the (possibly merged) newInterval if it wasn’t already added
        res.push_back(newInterval);
        return res;
    }
};

/*
===========================================================
Line-by-line C++ syntax explanation:
===========================================================

#include <bits/stdc++.h>
    → Includes all standard C++ headers (like vector, string, iostream, etc.).

using namespace std;
    → Allows you to use standard library names without writing std:: every time.

class Solution {
public:
    → Defines a class `Solution` with public methods.

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    → Defines the method `insert` that takes:
       - intervals: a reference to a vector of vectors of integers.
       - newInterval: a reference to a vector of integers.
       Returns a vector of vectors of integers.

vector<vector<int>> res;
    → Initializes an empty result vector to store merged intervals.

for (int i = 0; i < intervals.size(); i++) {
    → Loop over each interval.

if (newInterval[1] < intervals[i][0]) {
    → If newInterval ends before the current interval starts:
res.push_back(newInterval);
    → Add newInterval to result.
res.insert(res.end(), intervals.begin() + i, intervals.end());
    → Append the rest of intervals from current index onwards.
return res;
    → Return result.

else if (newInterval[0] > intervals[i][1]) {
    → If newInterval starts after the current interval ends:
res.push_back(intervals[i]);
    → Add the current interval to result.

else {
    → Overlapping intervals:
newInterval[0] = min(newInterval[0], intervals[i][0]);
    → Update newInterval’s start to smallest.
newInterval[1] = max(newInterval[1], intervals[i][1]);
    → Update newInterval’s end to largest.

res.push_back(newInterval);
    → After the loop, add the last (possibly merged) newInterval.

return res;
    → Return the merged intervals.

===========================================================
Time Complexity: O(N), single pass through intervals.
Space Complexity: O(N), to store result.
===========================================================
*/


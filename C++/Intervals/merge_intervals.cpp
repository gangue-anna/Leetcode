#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Merge overlapping intervals in a list.
     *
     * Time Complexity: O(N log N), where N is the number of intervals
     *   - Sorting takes O(N log N)
     *   - The merge pass is O(N)
     *
     * Space Complexity: O(N)
     *   - To store the output list
     */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> output;
        output.push_back(intervals[0]); // Initialize output with the first interval

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int& lastEnd = output.back()[1];  // Reference to the end of the last interval in output

            if (start <= lastEnd) {
                // Overlapping intervals, merge by updating the end
                lastEnd = max(lastEnd, end);
            } else {
                // No overlap, add the current interval
                output.push_back({start, end});
            }
        }

        return output;
    }
};

/*
===========================================================
Line-by-line C++ syntax explanation:
===========================================================

#include <bits/stdc++.h>
    → Includes all standard C++ libraries (like vector, algorithm, iostream, etc.).

using namespace std;
    → Allows us to use standard library names without writing std:: explicitly.

class Solution {
public:
    → Defines a class named Solution with public methods.

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    → Defines the method `merge` that:
       - Takes a reference to a vector of vector of integers (`intervals`).
       - Returns a vector of vector of integers.

sort(intervals.begin(), intervals.end());
    → Sort the intervals by their starting time.
    → Uses the default comparator (which compares first elements of each vector).

vector<vector<int>> output;
    → Declare a 2D vector to store the result.

output.push_back(intervals[0]);
    → Add the first interval to the output.

for (int i = 1; i < intervals.size(); i++) {
    → Loop through intervals starting from the second one.

int start = intervals[i][0];
int end = intervals[i][1];
    → Get the start and end of the current interval.

int& lastEnd = output.back()[1];
    → Get a reference to the end of the last interval in output.

if (start <= lastEnd) {
    → If current interval overlaps with the last one in output:
lastEnd = max(lastEnd, end);
    → Merge by updating the end to the maximum of both.

else {
    → No overlap:
output.push_back({start, end});
    → Add the current interval to output.

return output;
    → Return the merged intervals.

===========================================================
Time Complexity: O(N log N) because of sorting.
Space Complexity: O(N) for output.
===========================================================
*/


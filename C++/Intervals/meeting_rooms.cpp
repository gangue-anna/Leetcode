#include <bits/stdc++.h>
using namespace std;

/**
 * Definition of Interval
 */
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    /**
     * Determine if a person can attend all meetings (i.e., no overlaps between intervals).
     *
     * Time Complexity: O(N log N), where N is the number of intervals
     *   - Sorting takes O(N log N)
     *   - Checking overlaps takes O(N)
     *
     * Space Complexity: O(1) (ignoring input)
     *   - Sorting is in-place and only constant extra space is used
     *
     * @param intervals: vector of Interval objects
     * @return bool: True if all meetings can be attended without conflict, else False
     */
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return true;  // No meetings, so no conflict
        }

        // Sort intervals based on their start time
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        // Check for overlap between consecutive intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i-1].end > intervals[i].start) {
                // If the previous meeting ends after the current one starts, conflict
                return false;
            }
        }

        return true;  // No overlap found
    }
};

/*
===========================================================
Line-by-line C++ syntax explanation:
===========================================================

#include <bits/stdc++.h>
    → Includes all standard C++ headers (vector, iostream, algorithm, etc.)

using namespace std;
    → Allows you to use standard library names without prefixing them with std::.

class Interval {
public:
    int start, end;
    → Declare two public integers, start and end, to represent an interval.

Interval(int start, int end) {
    this->start = start;
    this->end = end;
}
    → Constructor that initializes start and end with the given values.
      `this->start` refers to the class member variable.

class Solution {
public:
    → Defines a class Solution with public methods.

bool canAttendMeetings(vector<Interval>& intervals) {
    → Method that takes a reference to a vector of Interval objects and returns a bool.

if (intervals.empty()) {
    return true;
}
    → If the input vector is empty, return true (no conflict possible).

sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
    return a.start < b.start;
});
    → Sort the intervals in ascending order of their start time using a lambda function.

for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i-1].end > intervals[i].start) {
        return false;
    }
}
    → Loop through intervals starting from index 1.
      Check if current meeting starts before previous meeting ends.
      If yes, return false because there is overlap.

return true;
    → If no overlaps are found, return true.

===========================================================
Time Complexity: O(N log N) because of sorting.
Space Complexity: O(1) (ignoring the input data).
===========================================================
*/


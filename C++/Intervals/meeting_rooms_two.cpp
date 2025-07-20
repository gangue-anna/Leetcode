#include <bits/stdc++.h>
using namespace std;

/**
 * Definition of Interval:
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
     * Find the minimum number of meeting rooms required to accommodate all meetings.
     *
     * Time Complexity: O(N log N), where N is the number of intervals
     *   - Sorting the start and end times takes O(N log N)
     *   - Traversing the arrays takes O(N)
     *
     * Space Complexity: O(N)
     *   - Storing the start and end times arrays
     *
     * @param intervals: vector of Interval objects
     * @return int: minimum number of rooms required
     */
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        vector<int> start, end;

        // Extract start and end times
        for (const auto& i : intervals) {
            start.push_back(i.start);
            end.push_back(i.end);
        }

        // Sort start and end times
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int res = 0, count = 0;  // res = max rooms needed, count = current rooms in use
        int s = 0, e = 0;

        while (s < intervals.size()) {
            if (start[s] < end[e]) {
                // New meeting starts before the earliest ending one finishes -> need another room
                count++;
                s++;
            } else {
                // Meeting ended before the next starts -> free up a room
                count--;
                e++;
            }
            res = max(res, count);
        }

        return res;
    }
};

/*
===========================================================
Line-by-line C++ syntax explanation:
===========================================================

#include <bits/stdc++.h>
    → Includes all standard C++ libraries (vector, iostream, algorithm, etc.)

using namespace std;
    → Allows writing names like vector and cout without prefixing with std::

class Interval {
public:
    int start, end;
    → Two public integer variables start and end.

Interval(int start, int end) {
    this->start = start;
    this->end = end;
}
    → Constructor initializes the start and end values.

class Solution {
public:
    → Defines the Solution class and its public methods.

int minMeetingRooms(vector<Interval>& intervals) {
    → Method takes a reference to a vector of Interval objects and returns an int.

if (intervals.empty()) return 0;
    → If there are no meetings, no rooms are needed.

vector<int> start, end;
    → Two vectors to hold the start and end times of all meetings.

for (const auto& i : intervals) {
    start.push_back(i.start);
    end.push_back(i.end);
}
    → Loop through intervals and populate start and end vectors.

sort(start.begin(), start.end());
sort(end.begin(), end.end());
    → Sort start and end times in ascending order.

int res = 0, count = 0;
int s = 0, e = 0;
    → res = max rooms at any point, count = current number of rooms.
      s = index for start times, e = index for end times.

while (s < intervals.size()) {
    if (start[s] < end[e]) {
        count++;
        s++;
    } else {
        count--;
        e++;
    }
    res = max(res, count);
}
    → Traverse the start and end arrays:
      - If a meeting starts before any end -> need a new room.
      - Else -> a meeting ended -> free up a room.
      - Update maximum rooms needed (res).

return res;
    → Return the maximum number of rooms required.

===========================================================
Time Complexity: O(N log N) (because of sorting)
Space Complexity: O(N) (because of start and end vectors)
===========================================================
*/


#include <bits/stdc++.h>
using namespace std;

class CountSquares {
private:
    unordered_map<string, int> ptsCount; // maps "x,y" -> count
    vector<pair<int, int>> pts;          // stores all points

    // Helper to generate a string key from x and y
    string key(int x, int y) {
        return to_string(x) + "," + to_string(y);
    }

public:
    /*
     * Constructor: Initializes the data structure.
     */
    CountSquares() {
        // No additional initialization required
    }

    /*
     * Add a point to the data structure.
     * Time Complexity: O(1)
     */
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        ptsCount[key(x, y)]++;       // increment count of (x, y)
        pts.emplace_back(x, y);     // store point
    }

    /*
     * Count the number of axis-aligned squares with given point as one corner.
     * Time Complexity: O(N), where N = number of points added.
     */
    int count(vector<int> point) {
        int res = 0;
        int px = point[0], py = point[1];

        for (auto& p : pts) {
            int x = p.first, y = p.second;

            // Skip if not forming a square diagonal:
            if (abs(py - y) != abs(px - x) || x == px || y == py) continue;

            // Other two corners: (x, py) and (px, y)
            res += ptsCount[key(x, py)] * ptsCount[key(px, y)];
        }
        return res;
    }
};

/*
 * 📖 Line-by-line explanation:
 *
 * #include <bits/stdc++.h>           → Includes all standard C++ libraries.
 * using namespace std;              → Allows standard names without std:: prefix.
 *
 * class CountSquares { … };        → Defines a class named CountSquares.
 *
 * private:                          → Members declared private to hide implementation.
 *
 * unordered_map<string, int> ptsCount; → Stores counts of each point, key as "x,y".
 * vector<pair<int, int>> pts;           → Stores list of all points added so far.
 *
 * string key(int x, int y) { … }   → Helper to create a unique string for a point.
 *
 * public:                          → Public interface of the class.
 *
 * CountSquares() { … }            → Constructor — initializes an empty object.
 *
 * void add(vector<int> point) { … } → Adds a point to the data structure.
 * int x = point[0], y = point[1];  → Extract x and y from the vector.
 * ptsCount[key(x,y)]++;           → Increment count of that point.
 * pts.emplace_back(x,y);          → Add to the list of points.
 *
 * int count(vector<int> point) { … } → Counts the number of squares.
 * int res = 0;                      → Initialize result counter.
 * for (auto& p : pts)              → Iterate over all previously added points.
 * int x = p.first, y = p.second;  → Get x and y from pair.
 *
 * if (abs(py-y) != abs(px-x) || x==px || y==py) continue; → Skip invalid diagonals.
 *
 * res += ptsCount[key(x,py)] * ptsCount[key(px,y)]; → Multiply counts of other corners.
 *
 * return res;                       → Return total number of squares.
 *
 */


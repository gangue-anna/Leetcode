#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        /*
         * Approach:
         * - Sort the intervals by their start point.
         * - Create a vector of (query, original index) pairs and sort by query value.
         * - Use a min-heap (priority_queue) to keep track of intervals that can cover the current query.
         *   The heap stores (interval length, interval end).
         * - For each query:
         *      - Add all intervals that start <= query to the heap.
         *      - Remove from the heap all intervals that end < query.
         *      - If the heap is not empty, the smallest interval covering the query is at the top.
         *      - If no interval covers the query, answer is -1.
         * - Return answers in the original query order.
         *
         * Time Complexity: O((N+Q) log N), where N = number of intervals, Q = number of queries.
         * Space Complexity: O(N+Q), for heap and result storage.
         */

        // Sort intervals by their start point
        sort(intervals.begin(), intervals.end());

        // Pair each query with its index to restore original order later
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); ++i) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        // Result vector initialized with -1
        vector<int> result(queries.size(), -1);

        // Min-heap: (interval length, interval end)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        int i = 0; // pointer for intervals

        // Loop over queries in sorted order
        for (auto& p : sortedQueries) {
            int q = p.first;   // query value
            int idx = p.second; // original index of the query

            // Add all intervals starting before or at q
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                minHeap.push({r - l + 1, r});
                ++i;
            }

            // Remove intervals that end before q
            while (!minHeap.empty() && minHeap.top().second < q) {
                minHeap.pop();
            }

            // The smallest interval covering q is at the top of the heap
            if (!minHeap.empty()) {
                result[idx] = minHeap.top().first;
            }
        }

        return result;
    }
};

/*
 * Line-by-line syntax explanation:
 *
 * #include <bits/stdc++.h>               → Includes all standard C++ libraries.
 * using namespace std;                  → So we don’t need to write std:: before everything.
 *
 * class Solution { … };                 → Defines the Solution class with public methods.
 *
 * vector<int> minInterval( … )         → Function that takes intervals & queries and returns answers.
 *
 * sort(intervals.begin(), intervals.end());
 *                                        → Sorts intervals by start time.
 *
 * vector<pair<int,int>> sortedQueries; → Vector of pairs to store queries with their original indices.
 *
 * for (…) sortedQueries.push_back(…); → Build the query-index pairs.
 *
 * sort(sortedQueries.begin(), sortedQueries.end());
 *                                        → Sort queries by query value.
 *
 * priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
 *                                        → Min-heap of (interval length, interval end).
 *
 * int i = 0;                            → Pointer to iterate over intervals.
 *
 * for (auto& p : sortedQueries) {      → Loop through each query.
 *
 * int q = p.first, idx = p.second;    → Extract query value and its original index.
 *
 * while (i < intervals.size() && intervals[i][0] <= q) …
 *                                        → Add intervals starting before or at q into the heap.
 *
 * while (!minHeap.empty() && minHeap.top().second < q) …
 *                                        → Remove intervals that end before q.
 *
 * if (!minHeap.empty()) result[idx] = minHeap.top().first;
 *                                        → If the heap has valid intervals, pick the smallest length.
 *
 * return result;                        → Return the final answers.
 *
 */


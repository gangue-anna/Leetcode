#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Finds the k closest points to the origin (0,0) using a max-heap of size k.
     *
     * Approach:
     * - Iterate through each point and compute its squared distance from origin.
     * - Use a max-heap (priority_queue) to maintain k smallest distances seen so far.
     * - For each point:
     *     - Push {distance, point} into the heap.
     *     - If the heap size > k, remove the farthest point.
     * - At the end, extract the points from the heap.
     *
     * Time Complexity: O(n log k), where n = number of points.
     * Space Complexity: O(k) for heap + O(k) for result => O(k)
     */
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap to store {distance, point}
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (auto& point : points) {
            int x = point[0];
            int y = point[1];
            int dist = x*x + y*y; // squared distance

            maxHeap.push({dist, point});

            // If heap size > k, remove the farthest point
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Extract points from the heap
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers (vector, queue, etc.) in one line.

using namespace std;
    ✅ Allows us to write vector instead of std::vector, etc.

class Solution { ... }
    ✅ Defines a class named Solution.

public:
    ✅ Public section: methods accessible outside the class.

vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    ✅ Method returning a 2D vector, takes a reference to 2D vector `points` and integer `k`.

priority_queue<pair<int, vector<int>>> maxHeap;
    ✅ Declares a max-heap of pairs: (distance, point).

for (auto& point : points)
    ✅ For each point in the points vector, iterate by reference.

int x = point[0]; int y = point[1];
    ✅ Extract x and y coordinates of the current point.

int dist = x*x + y*y;
    ✅ Compute squared distance from origin.

maxHeap.push({dist, point});
    ✅ Push pair (distance, point) into the heap.

if (maxHeap.size() > k) maxHeap.pop();
    ✅ If heap size > k, remove the farthest point.

vector<vector<int>> result;
    ✅ Initialize result vector.

while (!maxHeap.empty())
    ✅ While heap is not empty.

result.push_back(maxHeap.top().second);
    ✅ Add the point of the top element (closest so far) to result.

maxHeap.pop();
    ✅ Remove the top element of the heap.

return result;
    ✅ Return the result vector.

*/

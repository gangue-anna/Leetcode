#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        /*
        Approach:
        - Treat each point as a node in a complete graph.
        - Edges are the Manhattan distances between points.
        - Use Prim’s Algorithm to find the Minimum Spanning Tree (MST) of this graph.

        Time Complexity: O(n² log n)
            - Building adjacency list: O(n²)
            - Each heap operation: O(log n), up to O(n²) operations.

        Space Complexity: O(n²)
            - Adjacency list: O(n²)
            - Priority queue: O(n²)
            - Visited set: O(n)
        */

        int N = points.size();

        // Build adjacency list: for each point, store all edges (cost, neighbor)
        unordered_map<int, vector<pair<int, int>>> adj;

        for (int i = 0; i < N; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < N; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);  // Manhattan distance
                adj[i].push_back(make_pair(dist, j));
                adj[j].push_back(make_pair(dist, i));
            }
        }

        int res = 0;                   // Total minimum cost
        unordered_set<int> visited;   // Visited points
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;

        // Start from point 0
        minH.push(make_pair(0, 0));  // (cost, point)

        while (visited.size() < N) {
            pair<int, int> top = minH.top();
            minH.pop();

            int cost = top.first;
            int i = top.second;

            if (visited.count(i)) continue;

            res += cost;
            visited.insert(i);

            for (size_t k = 0; k < adj[i].size(); ++k) {
                int neiCost = adj[i][k].first;
                int nei = adj[i][k].second;
                if (!visited.count(nei)) {
                    minH.push(make_pair(neiCost, nei));
                }
            }
        }

        return res;
    }
};


/*
================ LINE BY LINE SYNTAX EXPLANATION =====================

#include <bits/stdc++.h>
- Includes all standard C++ headers (vector, set, map, queue, etc.)

using namespace std;
- Avoids writing std:: before STL names.

class Solution
- Defines the Solution class, as required by LeetCode.

int minCostConnectPoints(vector<vector<int>>& points)
- Function that takes a vector of points and returns the minimum cost.

int N = points.size();
- Number of points.

unordered_map<int, vector<pair<int, int>>> adj;
- Adjacency list to store all edges from each point: point → [(cost, neighbor), …].

for (int i = 0; i < N; ++i)
- Outer loop to process each point.

int x1 = points[i][0], y1 = points[i][1];
- Get the x and y coordinates of point i.

for (int j = i + 1; j < N; ++j)
- Inner loop to process every other point after i.

int x2 = points[j][0], y2 = points[j][1];
- Get x and y of point j.

int dist = abs(x1 - x2) + abs(y1 - y2);
- Compute Manhattan distance.

adj[i].push_back(make_pair(dist, j));
adj[j].push_back(make_pair(dist, i));
- Add both edges (since the graph is undirected).

int res = 0;
- Variable to store the final minimum cost.

unordered_set<int> visited;
- Set of visited points to avoid cycles.

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
- Min-heap (priority queue) of (cost, point) pairs.

minH.push(make_pair(0, 0));
- Start from point 0 with cost 0.

while (visited.size() < N)
- Keep running until all points are visited.

pair<int, int> top = minH.top();
minH.pop();
- Extract the minimum cost edge.

int cost = top.first;
int i = top.second;
- Extract cost and point from the pair.

if (visited.count(i)) continue;
- Skip if already visited.

res += cost;
visited.insert(i);
- Add point to MST and update total cost.

for (size_t k = 0; k < adj[i].size(); ++k)
- Iterate over all neighbors of point i.

int neiCost = adj[i][k].first;
int nei = adj[i][k].second;
- Extract neighbor cost and index.

if (!visited.count(nei))
- If neighbor is not yet visited.

minH.push(make_pair(neiCost, nei));
- Push neighbor edge into heap.

return res;
- Return the minimum cost to connect all points.

=======================================================================
*/

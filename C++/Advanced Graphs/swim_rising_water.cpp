#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        /*
        Approach:
        - Dijkstra-like BFS on a grid using a min-heap (priority queue).
        - Always move to the reachable cell with the smallest elevation.
        - The result is the max elevation along the path when reaching (N-1, N-1).

        Time Complexity: O(N^2 * log N)
            - N^2 cells in the grid.
            - Each heap operation is O(log N^2) ~ O(log N)

        Space Complexity: O(N^2)
            - Visited grid and the min-heap.
        */

        int N = grid.size();

        vector<vector<bool>> visited(N, vector<bool>(N, false));

        // Min-heap of (time, row, col), where time is the max elevation so far.
        typedef tuple<int, int, int> T;
        priority_queue<T, vector<T>, greater<T>> minH;

        minH.push(make_tuple(grid[0][0], 0, 0));
        visited[0][0] = true;

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!minH.empty()) {
            T top = minH.top();
            minH.pop();

            int time = get<0>(top);
            int r = get<1>(top);
            int c = get<2>(top);

            // If bottom-right is reached, return the time
            if (r == N - 1 && c == N - 1)
                return time;

            for (auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    minH.push(make_tuple(max(time, grid[nr][nc]), nr, nc));
                }
            }
        }

        return -1; // Should not reach here if input is valid
    }
};

/*
================ LINE BY LINE EXPLANATION =====================

#include <bits/stdc++.h>
- Includes all standard C++ libraries.

using namespace std;
- So you don't need to prefix with std::

class Solution
- Defines a class Solution.

int swimInWater(vector<vector<int>>& grid)
- Function that finds the minimum time to swim across the grid.

int N = grid.size();
- Stores grid size.

vector<vector<bool>> visited(N, vector<bool>(N, false));
- Keeps track of which cells are visited.

typedef tuple<int, int, int> T;
- Defines a type alias for a tuple of (time, row, col).

priority_queue<T, vector<T>, greater<T>> minH;
- Min-heap where smallest time is at top.

minH.push(make_tuple(grid[0][0], 0, 0));
- Start with the top-left cell.

visited[0][0] = true;
- Mark start cell as visited.

vector<pair<int, int>> directions
- Defines the 4 movement directions.

while (!minH.empty())
- While there are cells to explore.

T top = minH.top();
- Get cell with smallest elevation seen so far.

minH.pop();
- Remove it from the heap.

int time = get<0>(top), r = get<1>(top), c = get<2>(top);
- Extract time, row, and col from tuple.

if (r == N-1 && c == N-1)
- If we reached bottom-right, return time.

for (auto& dir : directions)
- Check all 4 adjacent cells.

int nr = r + dir.first, nc = c + dir.second;
- Compute neighbor coordinates.

if (...) // check bounds and visited
- Skip invalid or already visited cells.

visited[nr][nc] = true;
- Mark as visited.

minH.push(make_tuple(max(time, grid[nr][nc]), nr, nc));
- Push neighbor with updated max elevation on path.

return -1;
- Fallback if no path found (should not occur).

===============================================================
*/

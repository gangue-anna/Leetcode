#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        /*
        Approach:
        - Use Multi-Source BFS (Breadth-First Search) to find shortest distance from any gate
        - Start BFS simultaneously from all gates (cells with value 0)
        - BFS guarantees shortest path, so first time we reach a room gives minimum distance
        - Use level-order traversal where each level represents distance from nearest gate
        - Mark visited cells to avoid reprocessing
        
        Key Insight: Instead of running BFS from each empty room to find nearest gate,
        we run BFS from all gates simultaneously, which is much more efficient.
        
        Time Complexity: O(m * n), where m and n are grid dimensions
        - Each cell is visited at most once during BFS
        - We process each cell exactly once when it's first reached
        
        Space Complexity: O(m * n) in worst case
        - visited set can store up to m*n coordinates
        - BFS queue can contain up to m*n elements (when all cells are empty rooms)
        */
        
        // Handle edge case: empty grid
        if (grid.empty() || grid[0].empty()) {
            return;
        }
        
        // Get grid dimensions
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Set to track visited cells
        set<pair<int, int>> visited;
        
        // Queue for BFS - stores coordinates as pairs
        queue<pair<int, int>> q;
        
        // Helper function to add valid rooms to queue
        auto addRoom = [&](int r, int c) {
            // Check boundary conditions and validity
            if (r < 0 ||                                    // out of bounds (top)
                r >= rows ||                                // out of bounds (bottom)  
                c < 0 ||                                    // out of bounds (left)
                c >= cols ||                                // out of bounds (right)
                visited.find({r, c}) != visited.end() ||   // already visited
                grid[r][c] == -1) {                         // wall cell
                return;
            }
            
            // Mark as visited and add to queue
            visited.insert({r, c});
            q.push({r, c});
        };
        
        // Phase 1: Find all gates and add them to queue
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {  // Gate found
                    q.push({r, c});
                    visited.insert({r, c});
                }
            }
        }
        
        // Phase 2: Multi-source BFS from all gates
        int distance = 0;
        
        while (!q.empty()) {
            // Process all cells at current distance level
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                // Get current cell coordinates
                pair<int, int> current = q.front();
                q.pop();
                int r = current.first;
                int c = current.second;
                
                // Fill the current cell with distance from nearest gate
                grid[r][c] = distance;
                
                // Add all 4 adjacent rooms to queue for next level
                addRoom(r + 1, c);  // down
                addRoom(r - 1, c);  // up
                addRoom(r, c + 1);  // right
                addRoom(r, c - 1);  // left
            }
            
            // Increment distance for next level
            distance++;
        }
    }
};

/*
=== C++ SYNTAX EXPLANATION FOR BEGINNERS ===

Line-by-line breakdown of key C++ concepts used:

1. #include <bits/stdc++.h>
   - Includes all standard C++ libraries
   - Contains vector, set, queue, pair, etc.

2. using namespace std;
   - Allows using standard library without "std::" prefix
   - Example: "vector" instead of "std::vector"

3. class Solution {
   - Defines a class named "Solution"
   - Groups related data and functions together

4. public:
   - Access specifier: functions can be called from outside the class

5. void islandsAndTreasure(vector<vector<int>>& grid)
   - void: function returns nothing (no return value)
   - vector<vector<int>>: 2D dynamic array of integers
   - &: reference parameter (passes actual grid, not a copy)

6. if (grid.empty() || grid[0].empty())
   - .empty(): checks if vector has no elements
   - ||: logical OR operator
   - grid[0]: accesses first row of 2D vector
   - Returns true if grid has no rows OR first row has no columns

7. return;
   - Exits function early (since return type is void)
   - No value returned

8. int rows = grid.size();
   - .size(): returns number of elements in vector
   - For 2D vector, gives number of rows

9. int cols = grid[0].size();
   - Gets number of columns from first row

10. set<pair<int, int>> visited;
    - set: container for unique elements in sorted order
    - pair<int, int>: holds two integers (row, column coordinates)
    - Used to track which cells have been visited

11. queue<pair<int, int>> q;
    - queue: FIFO (First In, First Out) container
    - Stores pairs of coordinates for BFS traversal

12. auto addRoom = [&](int r, int c) {
    - auto: compiler automatically deduces type
    - Lambda function (anonymous function) definition
    - [&]: captures all variables from surrounding scope by reference
    - Parameters: r (row), c (column)

13. if (r < 0 || r >= rows || c < 0 || c >= cols || visited.find({r, c}) != visited.end() || grid[r][c] == -1)
    - Multiple conditions with || (logical OR)
    - visited.find({r, c}): searches for coordinate pair in set
    - != visited.end(): checks if element was not found
    - grid[r][c] == -1: checks if cell is a wall

14. visited.insert({r, c});
    - .insert(): adds element to set
    - {r, c}: creates pair using brace initialization

15. q.push({r, c});
    - .push(): adds element to back of queue
    - {r, c}: creates pair for coordinates

16. for (int r = 0; r < rows; r++)
    - Traditional for loop
    - Initializes r to 0, continues while r < rows, increments r

17. if (grid[r][c] == 0)
    - Checks if current cell is a gate (value 0)

18. while (!q.empty())
    - Loop continues while queue is not empty
    - !: logical NOT operator
    - .empty(): returns true if queue has no elements

19. int levelSize = q.size();
    - Stores current queue size to process one level at a time
    - This is key for level-by-level BFS

20. for (int i = 0; i < levelSize; i++)
    - Processes exactly levelSize elements (one BFS level)
    - Ensures we process all nodes at current distance before moving to next

21. pair<int, int> current = q.front();
    - .front(): gets first element from queue without removing it
    - Stores the coordinate pair in 'current' variable

22. q.pop();
    - .pop(): removes first element from queue
    - Note: pop() doesn't return the element, just removes it

23. int r = current.first;
    int c = current.second;
    - .first: accesses first element of pair
    - .second: accesses second element of pair
    - Extracts row and column from coordinate pair

24. grid[r][c] = distance;
    - Assigns distance value to current grid cell
    - This fills the treasure map with distances

25. distance++;
    - Increment operator: increases distance by 1
    - Equivalent to distance = distance + 1

Key C++ Concepts Used:
- STL containers: vector, set, queue, pair
- References (&) for efficient parameter passing
- Lambda functions with capture by reference
- Auto keyword for type deduction
- Member functions (.size(), .empty(), .push(), .pop(), .front())
- Pair access using .first and .second
- Traditional and range-based for loops
- Logical operators (||, !, ==, !=)
- FIFO queue operations for BFS
- Level-order traversal technique

Algorithm Notes:
- Multi-source BFS: starts from multiple points simultaneously
- Level-by-level processing ensures shortest distance calculation
- visited set prevents infinite loops and duplicate processing
- The key insight is processing all nodes at distance d before any at distance d+1
*/
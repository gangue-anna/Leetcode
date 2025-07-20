#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*
        Approach:
        - Use Multi-Source BFS to simulate the rotting process minute by minute
        - Start BFS simultaneously from all initially rotten oranges (value 2)
        - Each BFS level represents one minute of time passing
        - Fresh oranges adjacent to rotten ones become rotten in the next minute
        - Count total time needed until no more fresh oranges can be reached
        
        Key Insight: All rotten oranges spread rot simultaneously each minute,
        so we need level-by-level BFS starting from all rotten oranges.
        
        Time Complexity: O(m * n), where m and n are grid dimensions
        - Each cell is processed at most once during the BFS
        - Initial grid scan takes O(m * n) to count fresh oranges and find rotten ones
        
        Space Complexity: O(m * n) in worst case  
        - BFS queue can contain up to m*n coordinates (when most cells are rotten)
        - No additional space for visited tracking (we modify grid in-place)
        */
        
        // Handle edge case: empty grid
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        // Get grid dimensions
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Queue for BFS - stores coordinates of rotten oranges
        queue<pair<int, int>> q;
        
        // Counters
        int time = 0;        // Minutes elapsed
        int fresh = 0;       // Count of fresh oranges
        
        // Phase 1: Count fresh oranges and enqueue all initially rotten oranges
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {      // Fresh orange
                    fresh++;
                } else if (grid[r][c] == 2) {  // Rotten orange
                    q.push({r, c});
                }
            }
        }
        
        // If no fresh oranges initially, no time needed
        if (fresh == 0) {
            return 0;
        }
        
        // Direction vectors for 4-directional movement: right, left, down, up  
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Phase 2: Multi-source BFS to spread rot minute by minute
        while (!q.empty() && fresh > 0) {
            // Process all rotten oranges at current time level
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                // Get current rotten orange coordinates
                pair<int, int> current = q.front();
                q.pop();
                int r = current.first;
                int c = current.second;
                
                // Check all 4 adjacent cells
                for (const auto& direction : directions) {
                    int newRow = r + direction[0];
                    int newCol = c + direction[1];
                    
                    // Check bounds and if cell contains fresh orange
                    if (newRow < 0 ||                    // out of bounds (top)
                        newRow >= rows ||                // out of bounds (bottom)
                        newCol < 0 ||                    // out of bounds (left)  
                        newCol >= cols ||                // out of bounds (right)
                        grid[newRow][newCol] != 1) {     // not a fresh orange
                        continue; // Skip this cell
                    }
                    
                    // Make the fresh orange rotten
                    grid[newRow][newCol] = 2;
                    
                    // Add newly rotten orange to queue for next minute
                    q.push({newRow, newCol});
                    
                    // Decrease fresh orange count
                    fresh--;
                }
            }
            
            // Increment time after processing all oranges at current level
            time++;
        }
        
        // Return result: time if all oranges are rotten, -1 if some remain fresh
        return fresh == 0 ? time : -1;
    }
};

/*
=== C++ SYNTAX EXPLANATION FOR BEGINNERS ===

Line-by-line breakdown of key C++ concepts used:

1. #include <bits/stdc++.h>
   - Includes all standard C++ libraries
   - Contains vector, queue, pair, etc.

2. using namespace std;
   - Allows using standard library without "std::" prefix

3. class Solution {
   - Defines a class named "Solution"

4. public:
   - Access specifier: functions can be called from outside the class

5. int orangesRotting(vector<vector<int>>& grid)
   - Function returns int (number of minutes or -1)
   - vector<vector<int>>: 2D dynamic array of integers
   - &: reference parameter (passes actual grid, not a copy)

6. if (grid.empty() || grid[0].empty())
   - .empty(): checks if vector has no elements
   - ||: logical OR operator
   - Checks if grid has no rows OR first row has no columns

7. return 0;
   - Returns integer value 0 to caller

8. int rows = grid.size();
   - .size(): returns number of elements in vector
   - Gets number of rows in 2D grid

9. int cols = grid[0].size();
   - grid[0]: accesses first row
   - Gets number of columns

10. queue<pair<int, int>> q;
    - queue: FIFO (First In, First Out) container
    - pair<int, int>: holds two integers (coordinates)
    - Used for BFS traversal

11. int time = 0;
    int fresh = 0;
    - Variable declarations with initialization
    - int: integer data type

12. for (int r = 0; r < rows; r++)
    - Traditional for loop
    - Initializes r to 0, continues while r < rows, increments r

13. if (grid[r][c] == 1)
    - Accesses 2D array element at position [r][c]
    - == : equality comparison operator
    - Checks if cell contains fresh orange (value 1)

14. fresh++;
    - Increment operator: increases fresh by 1
    - Equivalent to fresh = fresh + 1

15. else if (grid[r][c] == 2)
    - else if: alternative condition check
    - Checks if cell contains rotten orange (value 2)

16. q.push({r, c});
    - .push(): adds element to back of queue
    - {r, c}: creates pair using brace initialization

17. if (fresh == 0) return 0;
    - Single-line if statement
    - Returns early if no fresh oranges exist

18. vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    - 2D vector initialization with direction vectors
    - Each inner vector represents movement: {row_offset, col_offset}
    - Right, Left, Down, Up respectively

19. while (!q.empty() && fresh > 0)
    - while: loop that continues while condition is true
    - !: logical NOT operator
    - &&: logical AND operator
    - Continues while queue is not empty AND fresh oranges remain

20. int levelSize = q.size();
    - Gets current queue size for level-by-level processing
    - Essential for BFS time simulation

21. pair<int, int> current = q.front();
    - .front(): gets first element from queue without removing
    - Stores coordinate pair in variable

22. q.pop();
    - .pop(): removes first element from queue
    - Note: doesn't return the element, just removes it

23. int r = current.first;
    int c = current.second;
    - .first: accesses first element of pair
    - .second: accesses second element of pair

24. for (const auto& direction : directions)
    - Range-based for loop (C++11 feature)
    - const: indicates we won't modify direction
    - auto: compiler deduces type automatically
    - &: reference to avoid copying

25. int newRow = r + direction[0];
    int newCol = c + direction[1];
    - direction[0]: accesses first element of direction vector
    - direction[1]: accesses second element
    - Calculates new coordinates after applying direction

26. if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || grid[newRow][newCol] != 1)
    - Multiple conditions with || (logical OR)
    - Bounds checking and fresh orange validation
    - >=: greater than or equal operator
    - !=: not equal operator

27. continue;
    - Skips rest of current loop iteration
    - Jumps to next iteration of the for loop

28. grid[newRow][newCol] = 2;
    - Assignment operator =
    - Changes fresh orange (1) to rotten (2)

29. time++;
    - Increments time after processing one minute level

30. return fresh == 0 ? time : -1;
    - Ternary conditional operator: condition ? value_if_true : value_if_false
    - Returns time if no fresh oranges remain, otherwise returns -1

Key C++ Concepts Used:
- STL containers: vector, queue, pair
- References (&) for efficient parameter passing
- Traditional and range-based for loops
- Logical operators (||, &&, !, ==, !=, >=)
- Ternary conditional operator (? :)
- Queue operations (.push(), .pop(), .front(), .size(), .empty())
- Pair operations (.first, .second)
- Multi-dimensional vector access
- const and auto keywords
- continue statement for loop control
- Level-by-level BFS technique

Algorithm Notes:
- Multi-source BFS: starts from all rotten oranges simultaneously
- Level-by-level processing ensures accurate time simulation
- In-place grid modification eliminates need for visited array
- The algorithm simulates exactly how rot spreads in real time
- Time complexity is optimal since each cell is processed at most once
*/
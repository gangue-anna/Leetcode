#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        /*
        Approach:
        - Use BFS (Breadth-First Search) to traverse each island in the grid
        - For each unvisited '1' (land), start a BFS to explore all connected land cells
        - Mark all visited cells to avoid counting them again
        - Count the number of BFS runs, which equals the number of islands
        
        Time Complexity: O(m * n), where m and n are the grid dimensions
        - Each cell is visited at most once during the entire algorithm
        
        Space Complexity: O(m * n) in the worst case
        - visited set can store up to m*n coordinates
        - BFS queue can have up to m*n elements in worst case (all cells are land)
        */
        
        // Handle edge case: empty grid
        if (grid.empty()) {
            return 0;
        }
        
        // Get grid dimensions
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Set to keep track of visited cells
        set<pair<int, int>> visited;
        
        // Counter for number of islands
        int islands = 0;
        
        // BFS function to explore an island starting from (r, c)
        auto bfs = [&](int r, int c) {
            // Queue for BFS traversal
            queue<pair<int, int>> q;
            
            // Mark starting cell as visited and add to queue
            visited.insert({r, c});
            q.push({r, c});
            
            // Continue BFS until queue is empty
            while (!q.empty()) {
                // Get current cell coordinates
                pair<int, int> current = q.front();
                q.pop();
                int row = current.first;
                int col = current.second;
                
                // Define 4 directions: down, up, right, left
                vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                
                // Check all 4 adjacent cells
                for (auto& direction : directions) {
                    int nr = row + direction[0];  // new row
                    int nc = col + direction[1];  // new column
                    
                    // Check if the adjacent cell is valid and unvisited land
                    if (nr >= 0 && nr < rows &&           // within row bounds
                        nc >= 0 && nc < cols &&           // within column bounds
                        grid[nr][nc] == '1' &&            // is land
                        visited.find({nr, nc}) == visited.end()) {  // not visited
                        
                        // Add to queue and mark as visited
                        q.push({nr, nc});
                        visited.insert({nr, nc});
                    }
                }
            }
        };
        
        // Iterate through each cell in the grid
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // If current cell is land and not visited, start new island exploration
                if (grid[r][c] == '1' && visited.find({r, c}) == visited.end()) {
                    bfs(r, c);        // Explore the entire island
                    islands++;        // Increment island count
                }
            }
        }
        
        return islands;
    }
};

/*
=== C++ SYNTAX EXPLANATION FOR BEGINNERS ===

Line-by-line breakdown of key C++ concepts used:

1. #include <bits/stdc++.h>
   - Includes all standard C++ libraries (headers)
   - Common in competitive programming, not recommended for production code

2. using namespace std;
   - Allows us to use standard library functions without "std::" prefix
   - Example: we can write "vector" instead of "std::vector"

3. class Solution {
   - Defines a class named "Solution"
   - Classes group related data and functions together

4. public:
   - Access specifier: members after this can be accessed from outside the class
   - Other options: private (only class can access), protected (class + inheritance)

5. int numIslands(vector<vector<char>>& grid)
   - Function declaration: returns int, takes a 2D vector of chars
   - vector<vector<char>>: 2D dynamic array of characters
   - & (reference): passes the actual grid, not a copy (saves memory)

6. if (grid.empty())
   - .empty(): member function that returns true if vector has no elements
   - Returns boolean value

7. int rows = grid.size();
   - .size(): returns number of elements in vector
   - For 2D vector, this gives number of rows

8. set<pair<int, int>> visited;
   - set: container that stores unique elements in sorted order
   - pair<int, int>: holds two integers together (row, column coordinates)
   - Used to track which cells we've already visited

9. auto bfs = [&](int r, int c) {
   - Lambda function (anonymous function) definition
   - [&]: captures all variables from surrounding scope by reference
   - Takes two integers as parameters

10. queue<pair<int, int>> q;
    - queue: FIFO (First In, First Out) container
    - Used for BFS traversal

11. visited.insert({r, c});
    - .insert(): adds element to set
    - {r, c}: creates a pair using brace initialization

12. pair<int, int> current = q.front();
    - Creates a pair variable to store the front element of queue
    - q.front(): gets first element without removing it

13. int row = current.first;
    int col = current.second;
    - .first and .second: access first and second elements of pair
    - Extracts row and column coordinates from the pair

14. q.pop();
    - .pop(): removes first element from queue

15. vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    - 2D vector initialization with direction vectors
    - Each inner vector represents a direction (row_offset, col_offset)

16. for (auto& direction : directions)
    - Range-based for loop (C++11 feature)
    - auto: compiler deduces type automatically
    - &: reference to avoid copying

17. visited.find({nr, nc}) == visited.end()
    - .find(): searches for element in set
    - .end(): returns iterator to past-the-end element
    - If find() returns end(), element is not found

18. return islands;
    - Returns the final count to whoever called this function

Key C++ Concepts Used:
- STL containers: vector, set, queue, pair
- References (&) for efficient parameter passing
- Lambda functions with capture
- Auto keyword for type deduction
- Range-based for loops
- Member functions (.size(), .empty(), .insert(), etc.)
- Pair access using .first and .second
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        /*
        Approach:
        - Use DFS (Depth-First Search) to explore each island and calculate its area
        - For each unvisited land cell (1), start DFS to explore the entire connected island
        - DFS recursively visits all 4 directions and counts connected land cells
        - Track visited cells to avoid counting them multiple times
        - Keep track of maximum area found so far
        
        Time Complexity: O(m * n), where m and n are the grid dimensions
        - Each cell is visited at most once during the entire algorithm
        - DFS explores each cell exactly once
        
        Space Complexity: O(m * n) in the worst case
        - visited set can store up to m*n coordinates
        - DFS recursion stack can go up to m*n depth in worst case (all cells form one island)
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
        
        // Variable to track maximum area found
        int maxArea = 0;
        
        // DFS function to explore island and return its area
        function<int(int, int)> dfs = [&](int r, int c) -> int {
            // Base case: check if current position is invalid
            if (r < 0 ||                           // out of bounds (top)
                r >= rows ||                       // out of bounds (bottom)
                c < 0 ||                           // out of bounds (left)
                c >= cols ||                       // out of bounds (right)
                grid[r][c] == 0 ||                 // water cell
                visited.find({r, c}) != visited.end()) {  // already visited
                return 0;
            }
            
            // Mark current cell as visited
            visited.insert({r, c});
            
            // Count current cell (1) + recursively count all connected cells
            // Explore all 4 directions: down, up, right, left
            return (1 + dfs(r + 1, c) +    // explore down
                        dfs(r - 1, c) +    // explore up
                        dfs(r, c + 1) +    // explore right
                        dfs(r, c - 1));    // explore left
        };
        
        // Iterate through each cell in the grid
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // For each cell, find the area of island starting from this cell
                // DFS will return 0 if this cell is water or already visited
                int currentArea = dfs(r, c);
                
                // Update maximum area if current island is larger
                maxArea = max(maxArea, currentArea);
            }
        }
        
        return maxArea;
    }
};

/*
=== C++ SYNTAX EXPLANATION FOR BEGINNERS ===

Line-by-line breakdown of key C++ concepts used:

1. #include <bits/stdc++.h>
   - Includes all standard C++ libraries (headers)
   - Contains vector, set, algorithm, functional, etc.

2. using namespace std;
   - Allows us to use standard library functions without "std::" prefix
   - Example: "vector" instead of "std::vector", "max" instead of "std::max"

3. class Solution {
   - Defines a class named "Solution"
   - Classes encapsulate data and functions together

4. public:
   - Access specifier: members after this can be accessed from outside the class
   - Functions declared here can be called by external code

5. int maxAreaOfIsland(vector<vector<int>>& grid)
   - Function that returns an integer
   - vector<vector<int>>: 2D dynamic array of integers
   - & (reference): passes actual grid, not a copy (efficient memory usage)

6. if (grid.empty())
   - .empty(): member function that checks if vector has no elements
   - Returns true if vector is empty, false otherwise

7. int rows = grid.size();
   - .size(): returns number of elements in vector
   - For 2D vector, gives number of rows

8. int cols = grid[0].size();
   - grid[0]: accesses first row of the 2D vector
   - .size(): gets number of columns in first row

9. set<pair<int, int>> visited;
   - set: container that stores unique elements in sorted order
   - pair<int, int>: template that holds two integers (row, column)
   - Used to track coordinates of visited cells

10. int maxArea = 0;
    - Declares integer variable and initializes to 0
    - Will store the maximum island area found

11. function<int(int, int)> dfs = [&](int r, int c) -> int {
    - function<int(int, int)>: declares a function type that takes 2 ints, returns int
    - Lambda function definition with capture
    - [&]: captures all variables from surrounding scope by reference
    - -> int: explicitly specifies return type
    - Parameters: r (row), c (column)

12. if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0 || visited.find({r, c}) != visited.end())
    - Multiple conditions connected with || (logical OR)
    - r < 0: checks if row is negative (out of bounds)
    - r >= rows: checks if row exceeds grid height
    - c < 0 || c >= cols: similar checks for columns
    - grid[r][c] == 0: checks if current cell is water
    - visited.find({r, c}) != visited.end(): checks if cell was already visited
    - .find(): searches for element in set
    - .end(): returns iterator pointing past the last element
    - If find() returns end(), element is not found

13. visited.insert({r, c});
    - .insert(): adds element to set
    - {r, c}: creates pair using brace initialization

14. return (1 + dfs(r + 1, c) + dfs(r - 1, c) + dfs(r, c + 1) + dfs(r, c - 1));
    - Recursive calls to explore 4 directions
    - 1: counts current cell
    - dfs(r + 1, c): explores cell below
    - dfs(r - 1, c): explores cell above
    - dfs(r, c + 1): explores cell to the right
    - dfs(r, c - 1): explores cell to the left
    - Returns sum of all connected land cells

15. for (int r = 0; r < rows; r++)
    - Traditional for loop
    - Initializes r to 0, continues while r < rows, increments r after each iteration

16. int currentArea = dfs(r, c);
    - Calls dfs function and stores result in variable
    - dfs returns area of island starting from position (r, c)

17. maxArea = max(maxArea, currentArea);
    - max(): standard library function that returns larger of two values
    - Updates maxArea if currentArea is larger

18. return maxArea;
    - Returns the maximum area found to the caller

Key C++ Concepts Used:
- STL containers: vector, set, pair
- References (&) for efficient parameter passing
- Lambda functions with capture and explicit return type
- std::function for function objects
- Nested vectors for 2D arrays
- Member functions (.size(), .empty(), .insert(), .find())
- Logical operators (||, ==, !=)
- Recursive function calls
- Standard library algorithms (max)
*/
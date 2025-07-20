#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    /**
     * Pacific Atlantic Water Flow Problem
     * 
     * APPROACH:
     * Instead of checking if water can flow from each cell to both oceans (which would be inefficient),
     * we use reverse thinking: start from ocean borders and find all cells that water can reach.
     * 
     * 1. Use DFS from Pacific borders (top row, left column) to find all reachable cells
     * 2. Use DFS from Atlantic borders (bottom row, right column) to find all reachable cells
     * 3. Find intersection of both sets - cells reachable by both oceans
     * 
     * Water flows from higher or equal height to lower height, so in reverse DFS,
     * we can move to a cell only if its height >= previous cell's height
     * 
     * TIME COMPLEXITY: O(m * n) where m = rows, n = cols
     * - Each cell is visited at most twice (once for each ocean)
     * - DFS visits each cell exactly once for each ocean
     * 
     * SPACE COMPLEXITY: O(m * n)
     * - Two sets to store reachable cells: O(m * n) each
     * - Recursion stack depth in worst case: O(m * n)
     */
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();           // Get number of rows
        int cols = heights[0].size();        // Get number of columns
        
        // Sets to keep track of cells reachable from each ocean
        set<pair<int, int>> pac;             // Pacific reachable cells
        set<pair<int, int>> atl;             // Atlantic reachable cells
        
        // Start DFS from all Pacific border cells (top row and left column)
        for (int c = 0; c < cols; c++) {
            dfs(0, c, pac, heights[0][c], heights);           // Top row
            dfs(rows - 1, c, atl, heights[rows - 1][c], heights); // Bottom row
        }
        
        for (int r = 0; r < rows; r++) {
            dfs(r, 0, pac, heights[r][0], heights);           // Left column
            dfs(r, cols - 1, atl, heights[r][cols - 1], heights); // Right column
        }
        
        // Find cells that are reachable by both oceans
        vector<vector<int>> result;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // If current cell exists in both Pacific and Atlantic sets
                if (pac.count({r, c}) && atl.count({r, c})) {
                    result.push_back({r, c});
                }
            }
        }
        
        return result;
    }
    
private:
    /**
     * Depth-First Search helper function
     * @param r: current row
     * @param c: current column  
     * @param visit: set to track visited cells for current ocean
     * @param prevHeight: height of previous cell (for flow validation)
     * @param heights: the input height matrix
     */
    void dfs(int r, int c, set<pair<int, int>>& visit, int prevHeight, vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        // Base cases for terminating DFS:
        // 1. Out of bounds
        // 2. Already visited this cell
        // 3. Water cannot flow (current height < previous height)
        if (r < 0 || c < 0 || r >= rows || c >= cols || 
            visit.count({r, c}) || heights[r][c] < prevHeight) {
            return;
        }
        
        // Mark current cell as visited (reachable from this ocean)
        visit.insert({r, c});
        
        // Explore all 4 directions (up, down, left, right)
        // Pass current cell's height as prevHeight for next recursive calls
        dfs(r + 1, c, visit, heights[r][c], heights);  // Down
        dfs(r - 1, c, visit, heights[r][c], heights);  // Up  
        dfs(r, c + 1, visit, heights[r][c], heights);  // Right
        dfs(r, c - 1, visit, heights[r][c], heights);  // Left
    }
};

/*
DETAILED C++ SYNTAX EXPLANATION FOR BEGINNERS:

LINE-BY-LINE BREAKDOWN:

1. #include <vector> - Includes the vector library for dynamic arrays
2. #include <set> - Includes the set library for storing unique elements
3. using namespace std; - Allows us to use std library functions without std:: prefix

4. class Solution { - Defines a class named Solution
5. public: - Public access specifier, members can be accessed from outside class

6. vector<vector<int>> pacificAtlantic(...) - Function declaration
   - vector<vector<int>>: Return type is 2D vector of integers
   - pacificAtlantic: Function name  
   - vector<vector<int>>& heights: Parameter is reference to 2D vector
   - & means reference (no copying, direct access to original data)

7. int rows = heights.size(); - Get number of rows
   - .size() returns the number of elements in vector
   - int declares an integer variable

8. set<pair<int, int>> pac; - Declares a set of coordinate pairs
   - set: Container that stores unique elements in sorted order
   - pair<int, int>: Each element is a pair of two integers (row, col)
   - pac: Variable name for Pacific reachable cells

9. for (int c = 0; c < cols; c++) - For loop syntax
   - int c = 0: Initialize counter variable c to 0
   - c < cols: Continue while c is less than cols
   - c++: Increment c by 1 after each iteration

10. dfs(0, c, pac, heights[0][c], heights); - Function call
    - Calls dfs function with 5 parameters
    - heights[0][c]: Access element at row 0, column c

11. vector<vector<int>> result; - Declare empty 2D vector for results

12. if (pac.count({r, c}) && atl.count({r, c})) - Conditional check
    - pac.count({r, c}): Returns 1 if pair {r,c} exists in set, 0 otherwise
    - &&: Logical AND operator
    - {r, c}: Creates a pair object with values r and c

13. result.push_back({r, c}); - Add element to vector
    - push_back(): Adds element to end of vector
    - {r, c}: Creates vector with two elements r and c

14. return result; - Return the result vector from function

15. private: - Private access specifier, members only accessible within class

16. void dfs(...) - Private helper function declaration  
    - void: Returns nothing
    - Multiple parameters separated by commas

17. visit.insert({r, c}); - Add pair to set
    - insert(): Adds element to set
    - Sets automatically handle duplicates (won't add if already exists)

18. visit.count({r, c}): Check if pair exists in set (returns 1 if exists, 0 if not)

KEY C++ CONCEPTS USED:
- vector<T>: Dynamic array that can grow/shrink
- set<T>: Container for unique sorted elements  
- pair<T1, T2>: Container holding two values
- Reference (&): Avoids copying large objects
- Class/Public/Private: Object-oriented programming concepts
- Recursion: Function calling itself
- STL containers: Standard Template Library data structures
*/
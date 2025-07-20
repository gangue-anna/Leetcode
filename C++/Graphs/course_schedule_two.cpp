#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Course Schedule II Problem (LeetCode 210)
     * 
     * PROBLEM: Given numCourses and prerequisites, return the ordering of courses you should take
     * to finish all courses. If impossible, return empty array.
     * A prerequisite pair [a, b] means you must take course b before course a.
     * 
     * APPROACH - Topological Sort using DFS:
     * This problem requires finding a topological ordering of a directed graph.
     * Topological sort is only possible if the graph is a DAG (Directed Acyclic Graph).
     * 
     * Key Insight: Use DFS with 3-state tracking:
     * 1. UNVISITED (0): Course not processed yet
     * 2. VISITING (1): Course currently in DFS path (cycle detection)
     * 3. VISITED (2): Course completely processed and added to result
     * 
     * Algorithm:
     * 1. Build adjacency list: course -> list of prerequisites
     * 2. For each unvisited course, perform DFS
     * 3. During DFS:
     *    - Mark course as VISITING (cycle detection)
     *    - Recursively visit all prerequisites  
     *    - If cycle detected, return false
     *    - Mark course as VISITED and add to result
     * 4. Result is built in reverse topological order (post-order DFS)
     * 
     * WHY POST-ORDER WORKS:
     * - We add a course to result AFTER processing all its dependencies
     * - This ensures dependencies appear before the course in final order
     * 
     * TIME COMPLEXITY: O(V + E)
     * - V = numCourses (vertices), E = prerequisites (edges)
     * - Each course visited exactly once: O(V)
     * - Each prerequisite edge traversed exactly once: O(E)
     * - Total: O(V + E)
     * 
     * SPACE COMPLEXITY: O(V + E)
     * - Adjacency list: O(V + E)
     * - State tracking array: O(V)
     * - Result array: O(V)
     * - Recursion stack: O(V) in worst case (linear chain)
     * - Total: O(V + E)
     */
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build adjacency list (course -> list of prerequisites)
        vector<vector<int>> prereq(numCourses);
        
        for (const auto& edge : prerequisites) {
            int course = edge[0];        // Course that has prerequisite
            int prerequisite = edge[1];  // Required prerequisite course
            prereq[course].push_back(prerequisite);
        }
        
        // Step 2: Initialize state tracking
        // 0 = UNVISITED, 1 = VISITING (in current DFS path), 2 = VISITED (completed)
        vector<int> state(numCourses, 0);
        vector<int> result;
        
        // Step 3: Perform DFS on all unvisited courses
        for (int course = 0; course < numCourses; course++) {
            if (state[course] == 0) {  // If course is unvisited
                if (!dfs(course, prereq, state, result)) {
                    return {};  // Cycle detected, return empty vector
                }
            }
        }
        
        return result;
    }
    
private:
    /**
     * DFS helper function for topological sort with cycle detection
     * 
     * @param course: Current course to process
     * @param prereq: Adjacency list (course -> prerequisites)
     * @param state: State tracking array (0=unvisited, 1=visiting, 2=visited)
     * @param result: Result vector to store topological order
     * @return: true if no cycle detected, false if cycle found
     * 
     * Three-State DFS Logic:
     * 1. If VISITING (1): Cycle detected (back edge found)
     * 2. If VISITED (2): Already processed, return success
     * 3. If UNVISITED (0): Process this course
     */
    bool dfs(int course, vector<vector<int>>& prereq, vector<int>& state, vector<int>& result) {
        // Case 1: Cycle detection
        if (state[course] == 1) {  // VISITING state
            return false;  // Back edge found, cycle exists
        }
        
        // Case 2: Already processed
        if (state[course] == 2) {  // VISITED state
            return true;  // Already added to result, no need to reprocess
        }
        
        // Case 3: Process unvisited course
        state[course] = 1;  // Mark as VISITING (entering DFS path)
        
        // Recursively process all prerequisites
        for (int prerequisite : prereq[course]) {
            if (!dfs(prerequisite, prereq, state, result)) {
                return false;  // Cycle detected in prerequisite chain
            }
        }
        
        // All prerequisites processed successfully
        state[course] = 2;        // Mark as VISITED (leaving DFS path)
        result.push_back(course); // Add to result (post-order)
        
        return true;  // Success
    }
};

/*
DETAILED C++ SYNTAX EXPLANATION FOR BEGINNERS:

LINE-BY-LINE BREAKDOWN:

1. #include <bits/stdc++.h>
   - Non-standard header that includes most C++ standard library
   - Contains vector, iostream, algorithm, unordered_set, etc.
   - Commonly used in competitive programming for convenience

2. using namespace std;
   - Allows using standard library without "std::" prefix
   - Example: write "vector" instead of "std::vector"

3. class Solution {
   - Defines a class named "Solution"
   - Classes group related data and functions together
   - Follows LeetCode's standard class structure

4. public:
   - Access specifier: these members accessible from outside class
   - Functions here can be called by external code
   - Other specifiers: private (class only), protected (inheritance)

5. vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
   - Function declaration breakdown:
     * vector<int>: Return type - dynamic array of integers
     * findOrder: Function name
     * int numCourses: Parameter - total number of courses
     * vector<vector<int>>&: Reference to 2D vector (prerequisite pairs)
     * &: Reference operator - avoids copying, allows modification

6. vector<vector<int>> prereq(numCourses);
   - Declares 2D vector named "prereq"
   - vector<vector<int>>: Vector where each element is also a vector of ints
   - (numCourses): Constructor - creates vector with numCourses empty sub-vectors
   - This creates an adjacency list representation

7. for (const auto& edge : prerequisites) {
   - Range-based for loop (C++11 feature)
   - auto: Compiler automatically deduces type (vector<int>)
   - const: Cannot modify 'edge' within loop (read-only)
   - &: Reference to avoid copying each prerequisite pair
   - Iterates over each prerequisite pair

8. int course = edge[0];
   - Extract first element from current prerequisite pair
   - edge[0]: Zero-based array/vector indexing
   - int: Declare integer variable to store course number

9. prereq[course].push_back(prerequisite);
   - prereq[course]: Access sub-vector at index 'course'
   - .push_back(): Add element to end of vector
   - Builds adjacency list: course -> list of its prerequisites

10. vector<int> state(numCourses, 0);
    - Declare vector of integers named "state"
    - (numCourses, 0): Constructor - creates vector with numCourses elements, all initialized to 0
    - Used to track processing state of each course

11. vector<int> result;
    - Declare empty vector of integers
    - Will store the final course ordering
    - No constructor parameters = empty vector

12. for (int course = 0; course < numCourses; course++) {
    - Traditional for loop syntax
    - int course = 0: Initialize loop counter
    - course < numCourses: Continue condition
    - course++: Post-increment (add 1 after each iteration)

13. if (state[course] == 0) {
    - Conditional statement checking if course is unvisited
    - state[course]: Access element at index 'course'
    - ==: Equality comparison operator (different from assignment =)
    - 0 represents UNVISITED state

14. if (!dfs(course, prereq, state, result)) {
    - Function call with conditional check
    - dfs(...): Call DFS function with 4 parameters
    - !: Logical NOT operator (inverts boolean result)
    - If dfs returns false, condition becomes true

15. return {};
    - Return empty object of the function's return type
    - {}: Empty initializer list creates empty vector<int>
    - Alternative to: return vector<int>();

16. private:
    - Access specifier: members only accessible within this class
    - Helper functions typically placed in private section
    - Encapsulation: hides implementation details

17. bool dfs(int course, vector<vector<int>>& prereq, vector<int>& state, vector<int>& result) {
    - Private helper function declaration
    - bool: Returns true (success) or false (failure)
    - All vector parameters passed by reference (&) for efficiency
    - Avoids copying large data structures

18. if (state[course] == 1) {
    - Check if course is in VISITING state
    - 1 represents currently being processed in DFS path
    - This detects cycles (back edges in graph)

19. if (state[course] == 2) {
    - Check if course is in VISITED state  
    - 2 represents completely processed
    - Optimization: avoid reprocessing completed courses

20. state[course] = 1;
    - Assignment: set course state to VISITING
    - =: Assignment operator (modifies value)
    - Marks entry into DFS processing path

21. for (int prerequisite : prereq[course]) {
    - Range-based for loop over prerequisites
    - int prerequisite: Each element in prereq[course] vector
    - Cleaner syntax than traditional indexed loop
    - Iterates through all prerequisites of current course

22. state[course] = 2;
    - Mark course as VISITED after processing all prerequisites
    - Indicates course and all dependencies are resolved
    - Safe to add to final result

23. result.push_back(course);
    - Add course to end of result vector
    - Post-order addition: after processing all dependencies
    - This creates correct topological ordering

24. return true;
    - Return boolean success value
    - Indicates no cycle was detected in this DFS branch

KEY C++ CONCEPTS USED:
- vector<T>: Dynamic array that can grow/shrink at runtime
- 2D vectors: vector<vector<T>> for adjacency list representation
- References (&): Avoids copying, enables efficient parameter passing
- Range-based for loops: Modern C++ iteration over containers
- auto keyword: Automatic type deduction by compiler
- const correctness: Prevents unintended modifications
- Boolean logic: &&, ||, ! operators for conditions
- State machine: Using integers to represent different processing states
- Recursion: Function calling itself with modified parameters
- Post-order traversal: Processing node after visiting all children
- Empty initializer: {} creates empty objects of appropriate type
*/
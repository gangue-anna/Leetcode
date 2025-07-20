#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Course Schedule Problem (LeetCode 207)
     * 
     * PROBLEM: Given numCourses and prerequisites, determine if it's possible to finish all courses.
     * A prerequisite pair [a, b] means you must take course b before course a.
     * 
     * APPROACH:
     * This is essentially a cycle detection problem in a directed graph.
     * - Each course is a node in the graph
     * - Each prerequisite relationship is a directed edge
     * - If there's a cycle, it's impossible to complete all courses
     * - If no cycles exist, all courses can be completed
     * 
     * Algorithm:
     * 1. Build adjacency list: course -> list of prerequisites
     * 2. For each course, use DFS to check if it can be completed
     * 3. During DFS, track current path to detect cycles
     * 4. Mark completed courses by clearing their prerequisite list (optimization)
     * 5. If any course cannot be completed (cycle detected), return false
     * 
     * KEY INSIGHT: 
     * - visitSet tracks courses in CURRENT DFS path (for cycle detection)
     * - If we revisit a course in current path -> cycle exists
     * - Clear prerequisite list after successful completion (memoization)
     * 
     * TIME COMPLEXITY: O(V + E)
     * - V = numCourses (vertices/nodes)
     * - E = number of prerequisite relationships (edges)
     * - Each course and prerequisite relationship is visited at most once
     * - DFS traverses each edge once, visits each node once
     * 
     * SPACE COMPLEXITY: O(V + E)
     * - Adjacency list storage: O(V + E)
     * - Recursion stack depth: O(V) in worst case (linear chain of prerequisites)
     * - Visit set: O(V) in worst case
     */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build adjacency list (course -> list of its prerequisites)
        vector<vector<int>> preMap(numCourses);
        
        // Build the graph: for each prerequisite pair [course, prerequisite]
        for (const auto& prereq : prerequisites) {
            int course = prereq[0];        // Course that has prerequisite
            int prerequisite = prereq[1];  // Required prerequisite course
            preMap[course].push_back(prerequisite);
        }
        
        // Set to track courses in current DFS path (for cycle detection)
        unordered_set<int> visitSet;
        
        // Step 2: Check if each course can be completed
        for (int course = 0; course < numCourses; course++) {
            if (!dfs(course, preMap, visitSet)) {
                return false;  // Cycle detected, cannot finish all courses
            }
        }
        
        return true;  // All courses can be completed
    }
    
private:
    /**
     * DFS helper function to check if a course can be completed
     * 
     * @param course: Current course to check
     * @param preMap: Adjacency list (course -> prerequisites)
     * @param visitSet: Set of courses in current DFS path
     * @return: true if course can be completed, false if cycle detected
     * 
     * Logic:
     * 1. If course is in current path -> cycle detected
     * 2. If course has no prerequisites -> can be completed
     * 3. Add course to current path, check all prerequisites
     * 4. If all prerequisites can be completed, mark this course as completed
     * 5. Remove course from current path (backtrack)
     */
    bool dfs(int course, vector<vector<int>>& preMap, unordered_set<int>& visitSet) {
        // Cycle detection: if course is already in current DFS path
        if (visitSet.find(course) != visitSet.end()) {
            return false;  // Cycle detected
        }
        
        // Base case: if course has no prerequisites, it can be completed
        if (preMap[course].empty()) {
            return true;
        }
        
        // Add current course to visit set (mark as being processed)
        visitSet.insert(course);
        
        // Check all prerequisites of current course
        for (int prerequisite : preMap[course]) {
            // If any prerequisite cannot be completed, current course cannot be completed
            if (!dfs(prerequisite, preMap, visitSet)) {
                return false;
            }
        }
        
        // Backtrack: remove course from current path
        visitSet.erase(course);
        
        // Optimization: mark course as completed by clearing its prerequisites
        // This acts as memoization - we don't need to recheck this course again
        preMap[course].clear();
        
        return true;  // Course can be completed
    }
};

/*
DETAILED C++ SYNTAX EXPLANATION FOR BEGINNERS:

LINE-BY-LINE BREAKDOWN:

1. #include <bits/stdc++.h>
   - Non-standard header including most C++ standard library headers
   - Includes vector, unordered_set, iostream, algorithm, etc.
   - Used for competitive programming convenience

2. using namespace std;
   - Allows using standard library functions without "std::" prefix
   - Example: "vector" instead of "std::vector", "cout" instead of "std::cout"

3. class Solution {
   - Defines a class named "Solution"
   - Classes encapsulate data and functions together
   - This follows LeetCode's expected class structure

4. public:
   - Access specifier: members can be accessed from outside the class
   - Functions declared here can be called by external code

5. bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
   - Function declaration breakdown:
     * bool: Return type (true/false)
     * canFinish: Function name
     * int numCourses: Parameter - number of courses (integer)
     * vector<vector<int>>&: Reference to 2D vector of integers
     * &: Reference operator - avoids copying, works with original data

6. vector<vector<int>> preMap(numCourses);
   - Declares 2D vector named preMap
   - vector<vector<int>>: Each element is a vector of integers
   - (numCourses): Constructor parameter - creates vector with numCourses empty vectors
   - This creates adjacency list representation

7. for (const auto& prereq : prerequisites) {
   - Range-based for loop (C++11 feature)
   - auto: Compiler automatically deduces type (vector<int> in this case)
   - const: Cannot modify prereq within loop
   - &: Reference to avoid copying each prerequisite pair
   - prereq: Variable name for current prerequisite pair

8. int course = prereq[0];
   - Extract first element of prereq vector
   - prereq[0]: Array/vector indexing (0-based)
   - int: Declare integer variable

9. preMap[course].push_back(prerequisite);
   - preMap[course]: Access vector at index 'course'
   - push_back(): Add element to end of vector
   - This builds the adjacency list

10. unordered_set<int> visitSet;
    - Declares hash set of integers
    - unordered_set: Hash table implementation (fast lookup/insert/delete)
    - <int>: Template parameter specifying element type
    - Used for O(1) average-time cycle detection

11. for (int course = 0; course < numCourses; course++) {
    - Traditional for loop
    - int course = 0: Initialize counter
    - course < numCourses: Condition to continue
    - course++: Post-increment (add 1 after each iteration)

12. if (!dfs(course, preMap, visitSet)) {
    - !: Logical NOT operator
    - dfs(...): Function call with three parameters
    - If dfs returns false, the condition becomes true

13. return false;
    - Exit function and return boolean value false
    - Early termination when cycle is detected

14. private:
    - Access specifier: members only accessible within this class
    - Helper functions are typically private

15. bool dfs(int course, vector<vector<int>>& preMap, unordered_set<int>& visitSet) {
    - Private helper function declaration
    - All parameters passed by reference (&) for efficiency
    - Returns boolean indicating success/failure

16. if (visitSet.find(course) != visitSet.end()) {
    - visitSet.find(course): Search for 'course' in set
    - Returns iterator pointing to element if found
    - visitSet.end(): Iterator pointing to "past-the-end" position
    - !=: Not equal comparison
    - If found, element exists in set (cycle detected)

17. if (preMap[course].empty()) {
    - .empty(): Returns true if vector has zero elements
    - Base case: no prerequisites means course can be completed

18. visitSet.insert(course);
    - .insert(): Add element to set
    - Sets automatically handle duplicates (won't add if already exists)
    - Marks course as being processed in current path

19. for (int prerequisite : preMap[course]) {
    - Range-based for loop iterating over prerequisites
    - int prerequisite: Each element in preMap[course] vector
    - Simpler syntax than traditional for loop

20. visitSet.erase(course);
    - .erase(): Remove element from set
    - Backtracking: remove course from current DFS path
    - Essential for correct cycle detection

21. preMap[course].clear();
    - .clear(): Remove all elements from vector
    - Optimization: marks course as "completed"
    - Prevents redundant rechecking (memoization)

KEY C++ CONCEPTS USED:
- vector<T>: Dynamic array that can grow/shrink
- 2D vector: vector<vector<T>> for adjacency list representation
- unordered_set<T>: Hash table for O(1) average lookup time
- References (&): Avoids copying large objects, enables modification
- Range-based for loops: Modern C++ iteration syntax
- auto keyword: Automatic type deduction
- const: Prevents modification of variables
- Recursion: Function calling itself with modified parameters
- Iterator concepts: find() returns iterator, compared with end()
- Member functions: .empty(), .push_back(), .insert(), .erase(), .clear()
*/
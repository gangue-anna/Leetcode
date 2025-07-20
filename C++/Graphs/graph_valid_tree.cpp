#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Graph Valid Tree Problem (LeetCode 261)
     * 
     * PROBLEM: Given n nodes labeled from 0 to n-1 and a list of undirected edges,
     * determine if these edges make up a valid tree.
     * 
     * TREE PROPERTIES:
     * A valid tree must satisfy BOTH conditions:
     * 1. CONNECTED: All nodes must be reachable from any starting node
     * 2. ACYCLIC: No cycles should exist in the graph
     * 
     * Additional property: A tree with n nodes has exactly (n-1) edges
     * 
     * APPROACH - DFS with Cycle Detection:
     * 1. Build adjacency list for undirected graph
     * 2. Use DFS starting from node 0 to:
     *    - Detect cycles by tracking visited nodes and parent
     *    - Count reachable nodes
     * 3. Check if graph is connected (all nodes visited)
     * 
     * CYCLE DETECTION in UNDIRECTED GRAPH:
     * - In undirected graph, we can't just check if a node is visited
     * - We must exclude the parent node (where we came from)
     * - If we visit a node that's not our parent and already visited → cycle
     * 
     * WHY THIS WORKS:
     * - DFS explores all reachable nodes from starting point
     * - If cycle exists, we'll revisit a non-parent node
     * - If all nodes visited, graph is connected
     * - Both conditions satisfied → valid tree
     * 
     * TIME COMPLEXITY: O(V + E)
     * - V = number of nodes (n)
     * - E = number of edges
     * - Each node visited exactly once: O(V)
     * - Each edge traversed exactly twice (undirected): O(E)
     * - Building adjacency list: O(E)
     * - Total: O(V + E)
     * 
     * SPACE COMPLEXITY: O(V + E)
     * - Adjacency list storage: O(V + E)
     * - Visited set: O(V)
     * - Recursion stack depth: O(V) in worst case (linear tree)
     * - Total: O(V + E)
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Edge case: empty graph with 0 nodes is considered a valid tree
        if (n == 0) {
            return true;
        }
        
        // Step 1: Build adjacency list for undirected graph
        vector<vector<int>> adj(n);  // Each node maps to list of neighbors
        
        for (const auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            
            // Add edge in both directions (undirected graph)
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        
        // Step 2: Track visited nodes during DFS
        unordered_set<int> visited;
        
        // Step 3: Start DFS from node 0 with no parent (-1)
        // Check for cycles during traversal
        if (!dfs(0, -1, adj, visited)) {
            return false;  // Cycle detected
        }
        
        // Step 4: Check connectivity - all nodes should be visited
        return visited.size() == n;
    }
    
private:
    /**
     * DFS helper function with cycle detection for undirected graph
     * 
     * @param node: Current node being processed
     * @param parent: Parent node (where we came from, -1 if root)
     * @param adj: Adjacency list representation of graph
     * @param visited: Set to track visited nodes
     * @return: true if no cycle detected, false if cycle found
     * 
     * LOGIC:
     * 1. If current node already visited → cycle detected
     * 2. Mark current node as visited
     * 3. For each neighbor:
     *    - Skip if neighbor is parent (avoid false cycle detection)
     *    - Recursively check neighbor with current node as parent
     *    - If cycle found in any subtree, propagate failure
     * 4. Return true if no cycles in entire subtree
     */
    bool dfs(int node, int parent, vector<vector<int>>& adj, unordered_set<int>& visited) {
        // Cycle detection: if node already visited, cycle exists
        if (visited.find(node) != visited.end()) {
            return false;
        }
        
        // Mark current node as visited
        visited.insert(node);
        
        // Explore all neighbors
        for (int neighbor : adj[node]) {
            // Skip parent to avoid false cycle detection in undirected graph
            if (neighbor == parent) {
                continue;
            }
            
            // Recursively check neighbor with current node as parent
            if (!dfs(neighbor, node, adj, visited)) {
                return false;  // Cycle detected in subtree
            }
        }
        
        return true;  // No cycle detected in this subtree
    }
};

/*
DETAILED C++ SYNTAX EXPLANATION FOR BEGINNERS:

LINE-BY-LINE BREAKDOWN:

1. #include <bits/stdc++.h>
   - Non-standard header including most C++ standard libraries
   - Contains vector, unordered_set, iostream, algorithm, etc.
   - Commonly used in competitive programming for convenience

2. using namespace std;
   - Allows using standard library functions without "std::" prefix
   - Example: write "vector" instead of "std::vector"
   - Makes code cleaner but can cause naming conflicts in large projects

3. class Solution {
   - Defines a class named "Solution"
   - Classes encapsulate related data and functions
   - This follows LeetCode's standard problem structure

4. public:
   - Access specifier: members accessible from outside the class
   - Public functions can be called by external code
   - Other specifiers: private (class only), protected (inheritance)

5. bool validTree(int n, vector<vector<int>>& edges) {
   - Function declaration breakdown:
     * bool: Return type (true for valid tree, false otherwise)
     * validTree: Function name
     * int n: Parameter - number of nodes in graph
     * vector<vector<int>>&: Reference to 2D vector of edges
     * &: Reference operator - avoids copying, works with original data

6. if (n == 0) {
   - Conditional statement for edge case
   - ==: Equality comparison operator (different from assignment =)
   - Checks if graph has zero nodes

7. return true;
   - Exit function and return boolean value true
   - Early return for edge case handling

8. vector<vector<int>> adj(n);
   - Declare 2D vector named "adj" (adjacency list)
   - vector<vector<int>>: Each element is a vector of integers
   - (n): Constructor parameter - creates n empty sub-vectors
   - Represents graph where adj[i] contains neighbors of node i

9. for (const auto& edge : edges) {
   - Range-based for loop (C++11 feature)
   - auto: Compiler automatically deduces type (vector<int>)
   - const: Cannot modify 'edge' within loop (read-only)
   - &: Reference to avoid copying each edge pair
   - Iterates over each edge in the edges vector

10. int node1 = edge[0];
    - Extract first element from current edge
    - edge[0]: Zero-based indexing to access first node
    - int: Declare integer variable

11. adj[node1].push_back(node2);
    - adj[node1]: Access sub-vector for node1's neighbors
    - .push_back(): Add element to end of vector
    - Adds node2 as neighbor of node1

12. adj[node2].push_back(node1);
    - Add node1 as neighbor of node2
    - Creates bidirectional connection (undirected graph)
    - Each edge represented in both directions

13. unordered_set<int> visited;
    - Declare hash set of integers
    - unordered_set: Hash table for O(1) average lookup/insert
    - <int>: Template parameter specifying element type
    - Used to track which nodes have been visited during DFS

14. if (!dfs(0, -1, adj, visited)) {
    - Function call with conditional check
    - dfs(...): Call DFS function with 4 parameters
    - !: Logical NOT operator (inverts boolean result)
    - -1: Represents "no parent" for root node

15. return false;
    - Return failure value when cycle is detected
    - Early termination prevents unnecessary computation

16. return visited.size() == n;
    - visited.size(): Returns number of elements in set
    - ==: Equality comparison
    - Checks if all n nodes were visited (connectivity test)
    - Returns true if connected, false if disconnected

17. private:
    - Access specifier: members only accessible within this class
    - Helper functions typically placed in private section
    - Encapsulation principle: hide implementation details

18. bool dfs(int node, int parent, vector<vector<int>>& adj, unordered_set<int>& visited) {
    - Private helper function for DFS traversal
    - All parameters except 'node' and 'parent' passed by reference (&)
    - References avoid copying large data structures

19. if (visited.find(node) != visited.end()) {
    - visited.find(node): Search for 'node' in set
    - Returns iterator pointing to element if found
    - visited.end(): Iterator representing "past-the-end" position
    - !=: Not equal comparison
    - If element found, it exists in set (already visited)

20. visited.insert(node);
    - Add 'node' to the visited set
    - .insert(): Set method to add element
    - Sets automatically handle duplicates (won't add if exists)

21. for (int neighbor : adj[node]) {
    - Range-based for loop over neighbors
    - int neighbor: Each element in adj[node] vector
    - Cleaner syntax than traditional indexed loops
    - Iterates through all neighbors of current node

22. if (neighbor == parent) {
    - Check if current neighbor is the parent node
    - Essential for undirected graphs to avoid false cycle detection
    - We came from parent, so going back isn't a cycle

23. continue;
    - Skip current iteration and move to next neighbor
    - Control flow statement to avoid processing parent
    - Equivalent to Python's 'continue' statement

24. if (!dfs(neighbor, node, adj, visited)) {
    - Recursive call to check neighbor
    - neighbor: Next node to visit
    - node: Current node becomes parent for recursive call
    - !: Check if DFS returns false (cycle detected)

25. return false;
    - Propagate failure up the recursion chain
    - If any subtree has cycle, entire tree is invalid

26. return true;
    - Return success when no cycles found in current subtree
    - Base case for successful DFS completion

KEY C++ CONCEPTS USED:
- vector<T>: Dynamic array that can grow/shrink
- 2D vectors: vector<vector<T>> for adjacency list
- unordered_set<T>: Hash table for efficient lookups
- References (&): Avoids copying, enables modification
- Range-based for loops: Modern iteration syntax
- auto keyword: Automatic type deduction
- const correctness: Prevents accidental modifications
- Iterator concepts: find() returns iterator, compare with end()
- Boolean logic: !, ==, && operators
- Recursion: Function calling itself with different parameters
- Early returns: Efficient control flow
- Template syntax: <int> specifies container element type
*/
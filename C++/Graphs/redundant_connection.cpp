#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Approach:
     * - Use Union-Find (Disjoint Set Union) to detect cycles in the graph
     * - For each edge, try to union the two nodes. If they are already connected (same parent), 
     *   the edge creates a cycle and is redundant
     * - Return the first redundant edge found while processing edges in order
     * - Uses path compression and union by rank for efficiency
     * 
     * Time Complexity: O(E * α(N)), where E is number of edges and α is inverse Ackermann function
     * Space Complexity: O(N) for parent and rank arrays, where N is number of nodes
     */
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Initialize parent array - each node is its own parent initially
        // Size is edges.size() + 1 because nodes are 1-indexed in this problem
        vector<int> parent(edges.size() + 1);
        for (int i = 0; i <= edges.size(); i++) {
            parent[i] = i;
        }
        
        // Initialize rank array - all nodes start with rank 1
        vector<int> rank(edges.size() + 1, 1);
        
        // Helper function to find root parent with path compression
        auto find = [&](int n) -> int {
            int p = parent[n];
            // Traverse up to find root parent
            while (p != parent[p]) {
                // Path compression: make parent point to grandparent
                parent[p] = parent[parent[p]];
                p = parent[p];
            }
            return p;
        };
        
        // Helper function to union two nodes
        // Returns false if nodes are already connected (can't union)
        // Returns true if union is successful
        auto unionNodes = [&](int n1, int n2) -> bool {
            int p1 = find(n1);
            int p2 = find(n2);
            
            // If they have same root parent, they're already connected
            // Adding this edge would create a cycle
            if (p1 == p2) {
                return false; // Cannot union - redundant edge detected
            }
            
            // Union by rank: attach smaller tree under root of larger tree
            if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            } else {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
            
            return true; // Union performed successfully
        };
        
        // Process each edge in order
        for (const auto& edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];
            
            // If union returns false, this edge is redundant
            if (!unionNodes(n1, n2)) {
                return {n1, n2}; // Return the redundant edge
            }
        }
        
        // This should never be reached based on problem constraints
        return {};
    }
};

/*
LINE BY LINE SYNTAX EXPLANATION FOR C++ BEGINNERS:

1. #include <bits/stdc++.h>
   - This is a non-standard header that includes most of the C++ standard library
   - It's commonly used in competitive programming but not recommended for production code
   - Includes vector, iostream, algorithm, etc.

2. using namespace std;
   - Allows us to use standard library functions without "std::" prefix
   - So we can write "vector" instead of "std::vector"

3. class Solution {
   - Declares a class named "Solution"
   - Classes are blueprints for objects that group data and functions together

4. public:
   - Access specifier meaning the following members can be accessed from outside the class
   - Other access specifiers are "private" and "protected"

5. vector<int> findRedundantConnection(vector<vector<int>>& edges) {
   - Function declaration that returns a vector of integers
   - Takes a reference to a vector of vector of integers as parameter
   - The & means we pass by reference (no copying, can modify original)

6. vector<int> parent(edges.size() + 1);
   - Creates a vector of integers with size (edges.size() + 1)
   - edges.size() returns the number of elements in edges vector
   - +1 because nodes are numbered from 1 (not 0) in this problem

7. for (int i = 0; i <= edges.size(); i++) {
   - Standard for loop: initialize i=0, continue while i <= edges.size(), increment i
   - <= means "less than or equal to"

8. parent[i] = i;
   - Assigns value i to the element at index i in the parent array
   - [] is the subscript operator for accessing vector elements

9. vector<int> rank(edges.size() + 1, 1);
   - Creates vector "rank" with size (edges.size() + 1), all elements initialized to 1
   - Second parameter (1) is the default value for all elements

10. auto find = [&](int n) -> int {
    - "auto" lets compiler automatically determine the variable type
    - [&] creates a lambda function that captures all variables by reference
    - (int n) is the parameter list
    - -> int specifies the return type is integer

11. int p = parent[n];
    - Declares integer variable p and initializes it with parent[n]

12. while (p != parent[p]) {
    - Loop continues while p is not equal to parent[p]
    - != means "not equal to"

13. parent[p] = parent[parent[p]];
    - Path compression optimization
    - Sets parent[p] to its grandparent (parent[parent[p]])

14. auto unionNodes = [&](int n1, int n2) -> bool {
    - Another lambda function that takes two integers and returns a boolean
    - bool is a data type that can be true or false

15. if (p1 == p2) {
    - Conditional statement checking if p1 equals p2
    - == is the equality comparison operator

16. return false;
    - Returns the boolean value false to the caller
    - Indicates that union operation failed

17. if (rank[p1] > rank[p2]) {
    - Conditional checking if rank[p1] is greater than rank[p2]
    - > is the "greater than" operator

18. rank[p1] += rank[p2];
    - Shorthand for: rank[p1] = rank[p1] + rank[p2]
    - += is the compound assignment operator for addition

19. for (const auto& edge : edges) {
    - Range-based for loop (C++11 feature)
    - Iterates through each element in the edges container
    - "const auto&" means we get a constant reference to each edge (no copying)

20. int n1 = edge[0]; int n2 = edge[1];
    - Extracts first and second elements from the current edge
    - edge[0] gets element at index 0, edge[1] gets element at index 1

21. if (!unionNodes(n1, n2)) {
    - ! is the logical NOT operator
    - This checks if unionNodes returns false
    - Equivalent to: if (unionNodes(n1, n2) == false)

22. return {n1, n2};
    - Returns a vector initialized with values n1 and n2
    - {} is brace initialization (C++11 feature)

23. return {};
    - Returns an empty vector
    - {} creates an empty container of the return type

KEY C++ CONCEPTS USED:
- vector<type>: Dynamic arrays that can resize automatically
- Lambda functions: [capture](params) -> return_type { body }
- Range-based for loops: for (const auto& item : container)
- References (&): Direct access to variables without copying
- auto keyword: Automatic type deduction by compiler
- Brace initialization {}: Modern way to initialize objects
- Boolean type: true/false values
- Compound assignment operators: +=, -=, *=, /=
*/
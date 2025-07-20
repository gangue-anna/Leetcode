#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Approach:
     * - Use Union-Find (Disjoint Set Union) to count connected components in an undirected graph
     * - For each edge, union the two nodes. If they are already connected, do nothing
     * - Start with n components (each node is its own component)
     * - For each successful union operation, decrement the component count by 1
     * - Uses path compression and union by rank for efficiency
     * 
     * Time Complexity: O(E * α(N)), where E is number of edges and α is inverse Ackermann function
     * Space Complexity: O(N) for parent and rank arrays
     */
    int countComponents(int n, vector<vector<int>>& edges) {
        // Initialize parent array - each node is its own parent initially
        vector<int> par(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        
        // Initialize rank array - all nodes start with rank 1
        vector<int> rank(n, 1);
        
        // Helper function to find root parent with path compression
        auto findRootParent = [&](int n1) -> int {
            int res = n1;
            // Traverse up to find root parent
            while (res != par[res]) {
                // Path compression: make parent point to grandparent
                par[res] = par[par[res]];
                res = par[res];
            }
            return res;
        };
        
        // Helper function to union two nodes
        auto unionNodes = [&](int n1, int n2) -> int {
            int p1 = findRootParent(n1);
            int p2 = findRootParent(n2);
            
            // If they have same root parent, they're already connected
            if (p1 == p2) {
                return 0; // No union performed
            }
            
            // Union by rank: attach smaller tree under root of larger tree
            if (rank[p2] > rank[p1]) {
                par[p1] = p2;
                rank[p2] += rank[p1];
            } else {
                par[p2] = p1;
                rank[p1] += rank[p2];
            }
            
            return 1; // Union performed successfully
        };
        
        // Start with n components (each node is separate component)
        int res = n;
        
        // Process each edge
        for (const auto& edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];
            // Subtract 1 for each successful union (merges two components into one)
            res -= unionNodes(n1, n2);
        }
        
        return res;
    }
};

/*
LINE BY LINE SYNTAX EXPLANATION FOR C++ BEGINNERS:

1. #include <vector>
   - This includes the vector library which provides dynamic arrays

2. using namespace std;
   - This allows us to use standard library functions without the "std::" prefix

3. class Solution {
   - Declares a class named "Solution" (classes group related data and functions)

4. public:
   - Access specifier - means the following members can be accessed from outside the class

5. vector<int> par(n);
   - Declares a vector (dynamic array) of integers named "par" with size n
   - vector<type> creates a dynamic array that can resize

6. for (int i = 0; i < n; i++) { par[i] = i; }
   - Standard for loop: initialize i=0, continue while i<n, increment i after each iteration
   - par[i] = i assigns value i to the element at index i

7. vector<int> rank(n, 1);
   - Creates vector "rank" of size n, with all elements initialized to 1
   - The second parameter (1) is the default value for all elements

8. auto findRootParent = [&](int n1) -> int {
   - "auto" lets compiler deduce the type automatically
   - [&] creates a lambda (anonymous function) that captures all variables by reference
   - (int n1) is the parameter list
   - -> int specifies the return type is integer

9. int res = n1;
   - Declares integer variable "res" and initializes it with value n1

10. while (res != par[res]) {
    - Loop continues as long as res is not equal to par[res]
    - != means "not equal to"

11. par[res] = par[par[res]];
    - Path compression: sets parent of res to its grandparent
    - par[par[res]] gets the grandparent of res

12. auto unionNodes = [&](int n1, int n2) -> int {
    - Another lambda function that takes two integers and returns an integer

13. if (rank[p2] > rank[p1]) {
    - Conditional statement using ">" (greater than) operator

14. const auto& edge : edges
    - Range-based for loop iterating over each element in edges
    - "const auto&" means we get a constant reference to each edge (no copying)
    - This is equivalent to: for each edge in the edges collection

15. int n1 = edge[0]; int n2 = edge[1];
    - Extracts first and second elements from the edge vector
    - edge[0] gets first element, edge[1] gets second element

16. res -= unionNodes(n1, n2);
    - Shorthand for: res = res - unionNodes(n1, n2)
    - Calls unionNodes function and subtracts its return value from res

17. return res;
    - Returns the value of res to the caller

18. };
    - Closes the class definition (semicolon required after class definition)

KEY C++ CONCEPTS USED:
- vector<type>: Dynamic arrays that can resize
- Lambda functions [capture](params) -> return_type { body }
- Range-based for loops: for (const auto& item : container)
- References (&): Allow direct access to variables without copying
- auto keyword: Automatic type deduction by compiler
*/
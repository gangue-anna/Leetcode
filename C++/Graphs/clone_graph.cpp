#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        /*
        Approach:
        - Use DFS with memoization to clone the graph
        - Maintain a hash map (unordered_map) to track original -> cloned node mapping
        - For each node, create a clone and recursively clone all its neighbors
        - Use memoization to avoid infinite loops and duplicate cloning
        - If a node is already cloned, return the existing clone from the map
        
        Time Complexity: O(V + E), where V is number of vertices (nodes) and E is number of edges
        - Each node is visited exactly once during the cloning process
        - Each edge is traversed exactly once when cloning neighbors
        
        Space Complexity: O(V), where V is number of vertices
        - Hash map stores mapping for all V nodes
        - Recursion stack can go up to V levels deep in worst case (linear graph)
        - The cloned graph itself takes O(V + E) space but that's the required output
        */
        
        // Handle edge case: empty graph
        if (node == nullptr) {
            return nullptr;
        }
        
        // Hash map to store mapping from original nodes to their clones
        unordered_map<Node*, Node*> oldToNew;
        
        // DFS function to recursively clone nodes
        function<Node*(Node*)> cloneNode = [&](Node* originalNode) -> Node* {
            // If this node is already cloned, return the existing clone
            if (oldToNew.find(originalNode) != oldToNew.end()) {
                return oldToNew[originalNode];
            }
            
            // Create a new clone with the same value
            Node* clonedNode = new Node(originalNode->val);
            
            // Store the mapping immediately to prevent infinite loops
            oldToNew[originalNode] = clonedNode;
            
            // Recursively clone all neighbors and add them to the cloned node
            for (Node* neighbor : originalNode->neighbors) {
                clonedNode->neighbors.push_back(cloneNode(neighbor));
            }
            
            return clonedNode;
        };
        
        // Start the cloning process from the given node
        return cloneNode(node);
    }
};

/*
=== C++ SYNTAX EXPLANATION FOR BEGINNERS ===

Line-by-line breakdown of key C++ concepts used:

1. #include <bits/stdc++.h>
   - Includes all standard C++ libraries
   - Contains unordered_map, vector, functional, etc.

2. using namespace std;
   - Allows using standard library without "std::" prefix

3. class Node {
   - Node class definition (provided in the problem)
   - Represents a graph node with value and list of neighbors

4. public:
   - Access specifier: members can be accessed from outside the class

5. int val;
   - Member variable to store the node's value
   - int: integer data type

6. vector<Node*> neighbors;
   - Vector (dynamic array) of Node pointers
   - Node*: pointer to Node object
   - Stores addresses of neighboring nodes

7. Node() { val = 0; neighbors = vector<Node*>(); }
   - Default constructor: creates node with value 0 and empty neighbors
   - vector<Node*>(): creates empty vector of Node pointers

8. Node(int _val) { val = _val; neighbors = vector<Node*>(); }
   - Parameterized constructor: takes value as parameter
   - _val: parameter name (underscore to distinguish from member variable)

9. Node(int _val, vector<Node*> _neighbors) { val = _val; neighbors = _neighbors; }
   - Constructor that takes both value and neighbors vector
   - Initializes both member variables

10. Node* cloneGraph(Node* node)
    - Function returns pointer to Node
    - Parameter is pointer to Node (can be nullptr)
    - Node*: pointer type that stores memory address of Node object

11. if (node == nullptr)
    - nullptr: C++11 null pointer literal (safer than NULL)
    - Checks if the input pointer is null

12. return nullptr;
    - Returns null pointer to indicate no graph to clone

13. unordered_map<Node*, Node*> oldToNew;
    - Hash map (hash table) container
    - Key: Node* (original node pointer)
    - Value: Node* (cloned node pointer)
    - Provides O(1) average lookup time

14. function<Node*(Node*)> cloneNode = [&](Node* originalNode) -> Node* {
    - function<Node*(Node*)>: function type that takes Node* and returns Node*
    - Lambda function definition
    - [&]: captures all variables from surrounding scope by reference
    - -> Node*: explicitly specifies return type as Node pointer

15. if (oldToNew.find(originalNode) != oldToNew.end())
    - .find(): searches for key in unordered_map
    - Returns iterator to element if found, otherwise returns end()
    - != oldToNew.end(): checks if element was found

16. return oldToNew[originalNode];
    - []: subscript operator for map access
    - Returns the value (cloned node) associated with the key (original node)

17. Node* clonedNode = new Node(originalNode->val);
    - new: dynamic memory allocation operator
    - Creates new Node object on heap and returns pointer to it
    - originalNode->val: arrow operator to access member through pointer
    - Equivalent to (*originalNode).val

18. oldToNew[originalNode] = clonedNode;
    - Stores mapping in hash map
    - Key: original node pointer, Value: cloned node pointer

19. for (Node* neighbor : originalNode->neighbors)
    - Range-based for loop (C++11 feature)
    - Iterates through each Node* in the neighbors vector
    - neighbor: loop variable that holds current neighbor pointer

20. clonedNode->neighbors.push_back(cloneNode(neighbor));
    - ->: arrow operator to access member through pointer
    - .push_back(): adds element to end of vector
    - cloneNode(neighbor): recursive call to clone the neighbor
    - Builds the neighbor list for the cloned node

21. return cloneNode(node);
    - Calls the lambda function with the input node
    - Returns the cloned graph starting from the cloned version of input node

Key C++ Concepts Used:
- Pointers and dynamic memory allocation (new operator)
- Arrow operator (->) for pointer member access
- STL containers: unordered_map, vector
- Lambda functions with capture by reference
- std::function for function objects
- Range-based for loops
- nullptr for null pointer checking
- Recursive function calls
- Hash map operations (find, subscript operator)

Memory Management Notes:
- This solution uses 'new' to allocate Node objects on the heap
- In production code, consider using smart pointers (unique_ptr, shared_ptr)
- The caller is responsible for cleaning up the allocated memory
- Each cloned node is a separate object in memory
*/
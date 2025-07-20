#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Approach:
     * - Build a directed weighted graph using an adjacency list representation
     * - Use Dijkstra's algorithm with a min-heap (priority queue) to find shortest time to reach all nodes from source k
     * - Track visited nodes to avoid revisiting and ensure we process each node only once
     * - The answer is the maximum time among all reachable nodes (last node to receive signal)
     * - If not all nodes are reachable, return -1
     * 
     * Time Complexity: O(E log N), where E is number of edges and N is number of nodes
     *   - Each edge is processed once, and heap operations take O(log N) time
     * Space Complexity: O(N + E) for adjacency list, priority queue, and visited set
     *   - Adjacency list stores all E edges, other structures store up to N nodes
     */
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjacency list representation of the graph
        // Key: source node, Value: vector of (destination, weight) pairs
        unordered_map<int, vector<pair<int, int>>> edges;
        
        for (const auto& time : times) {
            int u = time[0];    // source node
            int v = time[1];    // destination node  
            int w = time[2];    // weight (time)
            edges[u].push_back({v, w});
        }
        
        // Min-heap (priority queue) for Dijkstra's algorithm
        // Stores (current_time, node) pairs, ordered by current_time (ascending)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        // Set to track visited nodes
        unordered_set<int> visited;
        
        // Start Dijkstra's from source node k with time 0
        minHeap.push({0, k});
        
        int maxTime = 0;  // Maximum time to reach any node (answer)
        
        // Dijkstra's algorithm
        while (!minHeap.empty()) {
            // Extract node with minimum time from heap
            auto current = minHeap.top();
            minHeap.pop();
            
            int currentTime = current.first;
            int currentNode = current.second;
            
            // Skip if already visited (handles duplicate entries in heap)
            if (visited.find(currentNode) != visited.end()) {
                continue;
            }
            
            // Mark current node as visited
            visited.insert(currentNode);
            
            // Update maximum time (time for signal to reach all nodes)
            maxTime = max(maxTime, currentTime);
            
            // Explore all neighbors of current node
            for (const auto& neighbor : edges[currentNode]) {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;
                
                // Add unvisited neighbors to heap with updated time
                if (visited.find(nextNode) == visited.end()) {
                    minHeap.push({currentTime + edgeWeight, nextNode});
                }
            }
        }
        
        // Check if all nodes are reachable
        // If visited set size equals n, all nodes received the signal
        return visited.size() == n ? maxTime : -1;
    }
};

/*
LINE BY LINE SYNTAX EXPLANATION FOR C++ BEGINNERS:

1. #include <bits/stdc++.h>
   - Non-standard header that includes most C++ standard library components
   - Includes vector, unordered_map, unordered_set, priority_queue, etc.

2. using namespace std;
   - Allows using standard library without "std::" prefix
   - We can write "vector" instead of "std::vector"

3. class Solution {
   - Declares a class named "Solution"
   - Classes encapsulate data and functions together

4. public:
   - Access specifier - following members can be accessed from outside the class

5. int networkDelayTime(vector<vector<int>>& times, int n, int k) {
   - Function returning integer, takes reference to 2D vector, and two integers
   - & means pass by reference (avoids copying, allows modification)

6. unordered_map<int, vector<pair<int, int>>> edges;
   - Hash map with integer keys and vector of integer pairs as values
   - unordered_map provides average O(1) lookup time
   - pair<int, int> stores two integers together

7. for (const auto& time : times) {
   - Range-based for loop iterating over each vector in times
   - const auto& means constant reference (no copying, can't modify)
   - auto lets compiler deduce the type automatically

8. int u = time[0];
   - Extracts first element from current time vector
   - time[0] accesses element at index 0

9. edges[u].push_back({v, w});
   - Access vector associated with key u in the map
   - push_back() adds element to end of vector
   - {v, w} creates a pair using brace initialization

10. priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    - Declares min-heap (priority queue) of integer pairs
    - First template parameter: element type (pair<int, int>)
    - Second template parameter: underlying container (vector)
    - Third template parameter: comparison function (greater makes it min-heap)

11. unordered_set<int> visited;
    - Hash set to store integers (visited nodes)
    - Provides average O(1) insertion and lookup

12. minHeap.push({0, k});
    - Adds pair (0, k) to the priority queue
    - {0, k} creates pair using brace initialization

13. int maxTime = 0;
    - Declares and initializes integer variable to 0

14. while (!minHeap.empty()) {
    - Loop continues while heap is not empty
    - ! is logical NOT operator
    - empty() returns true if container has no elements

15. auto current = minHeap.top();
    - Gets reference to top element (minimum) without removing it
    - auto lets compiler deduce the type (pair<int, int>)

16. minHeap.pop();
    - Removes the top element from heap
    - pop() doesn't return the element, just removes it

17. int currentTime = current.first;
    - Accesses first element of the pair
    - .first gets the first component of std::pair

18. int currentNode = current.second;
    - Accesses second element of the pair
    - .second gets the second component of std::pair

19. if (visited.find(currentNode) != visited.end()) {
    - find() searches for currentNode in visited set
    - Returns iterator to element if found, end() if not found
    - != means "not equal to"

20. continue;
    - Skips rest of current loop iteration and goes to next iteration

21. visited.insert(currentNode);
    - Adds currentNode to the visited set
    - insert() is method to add elements to sets

22. maxTime = max(maxTime, currentTime);
    - max() function returns larger of two values
    - Updates maxTime if currentTime is larger

23. for (const auto& neighbor : edges[currentNode]) {
    - Range-based for loop over neighbors of currentNode
    - edges[currentNode] returns vector of pairs

24. int nextNode = neighbor.first;
    - Extracts destination node from neighbor pair

25. int edgeWeight = neighbor.second;
    - Extracts edge weight from neighbor pair

26. minHeap.push({currentTime + edgeWeight, nextNode});
    - Adds new pair to heap with updated time
    - currentTime + edgeWeight calculates total time to reach nextNode

27. return visited.size() == n ? maxTime : -1;
    - Ternary operator: condition ? value_if_true : value_if_false
    - visited.size() returns number of elements in set
    - Returns maxTime if all nodes visited, -1 otherwise

KEY C++ CONCEPTS USED:
- unordered_map<key, value>: Hash table for key-value mappings
- unordered_set<type>: Hash table for unique elements  
- priority_queue<type>: Heap data structure for priority-based processing
- pair<type1, type2>: Container holding two values together
- Range-based for loops: for (const auto& item : container)
- auto keyword: Automatic type deduction
- References (&): Direct access without copying
- Ternary operator (?:): Compact conditional expression
- Template parameters: <> specify types for generic containers
- .first and .second: Access components of std::pair
- Brace initialization {}: Modern way to create objects
*/
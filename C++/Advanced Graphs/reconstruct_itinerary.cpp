#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Approach:
     * - Build an adjacency list (graph) where each airport points to a list of its destinations
     * - Sort each list of destinations in lexical order so we always choose the smallest lexical option first
     * - Use backtracking (DFS) to construct the itinerary, always choosing the next lexical destination
     * - Remove the destination from the adjacency list as we use it, and backtrack if needed
     * - The itinerary must use all tickets exactly once and start from 'JFK'
     * 
     * Time Complexity: O(E^2), where E is the number of tickets (edges)
     *   - Each edge is visited once, but insertion and removal in the list can take O(E) in worst case
     * Space Complexity: O(E) for the adjacency list and recursion stack
     */
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 1. Initialize adjacency list for all airports
        unordered_map<string, vector<string>> adj;
        
        // Build the graph from tickets
        for (const auto& ticket : tickets) {
            string src = ticket[0];
            string dst = ticket[1];
            
            // Initialize empty vectors for both source and destination if not present
            if (adj.find(src) == adj.end()) {
                adj[src] = vector<string>();
            }
            if (adj.find(dst) == adj.end()) {
                adj[dst] = vector<string>();
            }
            
            // Add destination to source's adjacency list
            adj[src].push_back(dst);
        }
        
        // 2. Sort destinations for lexical order
        for (auto& pair : adj) {
            sort(pair.second.begin(), pair.second.end());
        }
        
        // Initialize result with starting airport
        vector<string> result = {"JFK"};
        
        // Define DFS function using lambda
        function<bool(const string&)> dfs = [&](const string& src) -> bool {
            // Base case: if we've used all tickets, we found a valid itinerary
            if (result.size() == tickets.size() + 1) {
                return true;
            }
            
            // If source airport has no outgoing flights, return false
            if (adj.find(src) == adj.end()) {
                return false;
            }
            
            // 3. Create a copy of current destinations to iterate over
            vector<string> temp = adj[src];
            
            // Try each destination in lexical order
            for (int i = 0; i < temp.size(); i++) {
                string destination = temp[i];
                
                // 4. Check if the destination is still available in the original list
                auto it = find(adj[src].begin(), adj[src].end(), destination);
                if (it == adj[src].end()) {
                    continue; // This destination has been used
                }
                
                // 5. Remove the destination (use the ticket)
                adj[src].erase(it);
                result.push_back(destination);
                
                // Recursively try to complete the itinerary
                if (dfs(destination)) {
                    return true; // Found valid itinerary
                }
                
                // 6. Backtrack: restore the ticket and remove from result
                adj[src].insert(adj[src].begin() + i, destination);
                result.pop_back();
            }
            
            return false; // No valid itinerary found from this path
        };
        
        // Start DFS from JFK
        dfs("JFK");
        return result;
    }
};

/*
LINE BY LINE SYNTAX EXPLANATION FOR C++ BEGINNERS:

1. #include <bits/stdc++.h>
   - Non-standard header including most C++ standard library components
   - Includes vector, string, unordered_map, algorithm, functional, etc.

2. using namespace std;
   - Allows using standard library without "std::" prefix
   - Can write "vector" instead of "std::vector"

3. class Solution {
   - Declares a class named "Solution"
   - Classes group related data and functions together

4. public:
   - Access specifier - following members accessible from outside the class

5. vector<string> findItinerary(vector<vector<string>>& tickets) {
   - Function returning vector of strings
   - Parameter: reference to 2D vector of strings
   - & means pass by reference (avoids copying, allows modification)

6. unordered_map<string, vector<string>> adj;
   - Hash map with string keys and vector<string> values
   - Similar to Python dictionary with string keys and list values

7. for (const auto& ticket : tickets) {
   - Range-based for loop iterating over each ticket
   - const auto& means constant reference (no copying, can't modify)
   - auto lets compiler deduce type automatically

8. string src = ticket[0];
   - Extracts first element from ticket vector
   - ticket[0] accesses element at index 0

9. if (adj.find(src) == adj.end()) {
   - find() searches for key 'src' in the map
   - Returns iterator to element if found, end() if not found
   - == checks if key doesn't exist in map

10. adj[src] = vector<string>();
    - Creates empty vector and assigns it to key 'src'
    - vector<string>() creates empty vector of strings

11. adj[src].push_back(dst);
    - Adds 'dst' to the end of vector associated with key 'src'
    - push_back() appends elements to vectors

12. for (auto& pair : adj) {
    - Range-based for loop over key-value pairs in map
    - auto& means reference (can modify the pair)

13. sort(pair.second.begin(), pair.second.end());
    - Sorts the vector (pair.second) in lexicographical order
    - pair.second accesses the value part of key-value pair
    - begin() and end() return iterators to start and end of vector

14. vector<string> result = {"JFK"};
    - Creates vector initialized with one element "JFK"
    - {} is brace initialization

15. function<bool(const string&)> dfs = [&](const string& src) -> bool {
    - Declares lambda function stored in std::function wrapper
    - bool(const string&) is the function signature
    - [&] captures all variables by reference
    - -> bool specifies return type

16. if (result.size() == tickets.size() + 1) {
    - size() returns number of elements in container
    - == checks equality
    - +1 because result includes starting airport

17. auto it = find(adj[src].begin(), adj[src].end(), destination);
    - find() searches for 'destination' in the vector
    - Returns iterator pointing to found element or end() if not found
    - auto deduces iterator type

18. if (it == adj[src].end()) {
    - Checks if element was not found
    - end() represents past-the-end iterator

19. adj[src].erase(it);
    - Removes element pointed to by iterator 'it'
    - erase() removes elements from vector

20. result.push_back(destination);
    - Adds destination to end of result vector

21. if (dfs(destination)) {
    - Recursive call to dfs function
    - if checks if the recursive call returns true

22. adj[src].insert(adj[src].begin() + i, destination);
    - Inserts 'destination' at position i in the vector
    - begin() + i creates iterator pointing to position i
    - insert() adds element at specified position

23. result.pop_back();
    - Removes last element from result vector
    - pop_back() removes elements from end of vector

24. dfs("JFK");
    - Calls the lambda function with "JFK" as argument

KEY C++ CONCEPTS USED:
- unordered_map<key, value>: Hash table for key-value mappings
- vector<type>: Dynamic arrays that can resize
- Range-based for loops: for (const auto& item : container)
- Lambda functions: [capture](params) -> return_type { body }
- std::function: Wrapper for callable objects (needed for recursive lambdas)
- auto keyword: Automatic type deduction
- References (&): Direct access without copying
- Iterators: Objects pointing to elements in containers
- find(): STL algorithm to search in containers
- sort(): STL algorithm to sort containers
- insert() and erase(): Vector methods for adding/removing elements
- Brace initialization {}: Modern way to initialize containers
*/
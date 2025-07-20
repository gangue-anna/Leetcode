#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        /**
         * Deep copy a linked list where each node has both next and random pointers.
         * 
         * Algorithm:
         * 1. Create a hash map to store mapping from original nodes to their copies
         * 2. Initialize the map with nullptr -> nullptr mapping for convenience
         * 3. First pass: Create all new nodes and populate the hash map
         * 4. Second pass: Assign next and random pointers using the hash map
         * 5. Return the copy of the head node
         * 
         * Why this approach works:
         * - We need to maintain the same structure with both next and random pointers
         * - Random pointers can point to any node (including nullptr), so we need
         *   to create all nodes first before setting up the connections
         * - Hash map allows O(1) lookup to find the copy of any original node
         * 
         * Time Complexity: O(n) where n is the number of nodes
         * - We traverse the list twice: once to create nodes, once to set pointers
         * - Hash map operations (insert/lookup) are O(1) average case
         * 
         * Space Complexity: O(n)
         * - Hash map stores n key-value pairs (one for each original node)
         * - The new linked list itself takes O(n) space but that's required for the result
         */
        
        // Handle edge case: empty list
        if (head == nullptr) {
            return nullptr;
        }
        
        // Step 1: Create hash map to store original -> copy mapping
        // unordered_map provides O(1) average case lookup and insertion
        unordered_map<Node*, Node*> oldToCopy;
        
        // Step 2: Initialize map with nullptr -> nullptr for convenience
        // This handles cases where next or random pointers are nullptr
        oldToCopy[nullptr] = nullptr;
        
        // Step 3: First pass - create all nodes and populate hash map
        Node* cur = head;
        while (cur != nullptr) {
            // Create new node with same value
            Node* copy = new Node(cur->val);
            
            // Store mapping from original node to its copy
            oldToCopy[cur] = copy;
            
            // Move to next node
            cur = cur->next;
        }
        
        // Step 4: Second pass - assign next and random pointers
        cur = head;
        while (cur != nullptr) {
            // Get the copy of current node
            Node* copy = oldToCopy[cur];
            
            // Set next pointer using hash map lookup
            // oldToCopy[cur->next] will be nullptr if cur->next is nullptr
            copy->next = oldToCopy[cur->next];
            
            // Set random pointer using hash map lookup
            // oldToCopy[cur->random] will be nullptr if cur->random is nullptr
            copy->random = oldToCopy[cur->random];
            
            // Move to next node
            cur = cur->next;
        }
        
        // Step 5: Return the copy of the original head
        return oldToCopy[head];
    }
};

/*
=== C++ SYNTAX EXPLANATION FOR BEGINNERS ===

1. #include <bits/stdc++.h>
   - This is a non-standard header that includes most standard C++ libraries
   - It's commonly used in competitive programming for convenience
   - In production code, you should include specific headers like <unordered_map>

2. using namespace std;
   - Allows us to use standard library functions without std:: prefix
   - Example: we can write 'unordered_map' instead of 'std::unordered_map'

3. class Node {
   - Defines a class named Node
   - Classes are blueprints for creating objects

4. public:
   - Access specifier meaning the following members can be accessed from outside the class
   - Other access specifiers are 'private' (only within class) and 'protected'

5. int val;
   - Declares an integer member variable to store the node's value
   - Each Node object will have its own copy of this variable

6. Node* next;
   - Declares a pointer to another Node object
   - The asterisk (*) indicates this is a pointer type
   - This creates the "next" link in the linked list

7. Node* random;
   - Another pointer to a Node, representing the random connection
   - Can point to any node in the list or be nullptr

8. Node(int _val) {
   - Constructor function that runs when a new Node is created
   - Takes one parameter '_val' of type int
   - The underscore is just a naming convention (could be any name)

9. val = _val;
   - Assigns the parameter value to the member variable
   - 'val' refers to the member variable, '_val' is the parameter

10. next = NULL;
    - Sets the next pointer to NULL (older C++ style)
    - In modern C++, we prefer 'nullptr' over 'NULL'

11. unordered_map<Node*, Node*> oldToCopy;
    - Declares a hash map (hash table) variable
    - <Node*, Node*> specifies the key and value types (both are Node pointers)
    - unordered_map provides average O(1) lookup time

12. oldToCopy[nullptr] = nullptr;
    - Uses square bracket notation to insert/access map elements
    - This creates a mapping from nullptr key to nullptr value
    - Equivalent to oldToCopy.insert({nullptr, nullptr})

13. while (cur != nullptr) {
    - Loop that continues as long as cur is not nullptr
    - != means "not equal to"
    - nullptr is the modern C++ way to represent null pointers

14. Node* copy = new Node(cur->val);
    - Creates a new Node object on the heap using 'new' operator
    - new returns a pointer to the created object
    - cur->val accesses the val member through the pointer cur

15. oldToCopy[cur] = copy;
    - Inserts a new key-value pair into the hash map
    - Key is 'cur' (original node), value is 'copy' (new node)
    - If key already exists, this updates the value

16. cur = cur->next;
    - Updates cur to point to the next node in the list
    - -> operator is used to access members through a pointer
    - Equivalent to cur = (*cur).next

17. Node* copy = oldToCopy[cur];
    - Retrieves the value associated with key 'cur' from the hash map
    - Returns the copied node that corresponds to the original node 'cur'

18. copy->next = oldToCopy[cur->next];
    - Sets the next pointer of the copied node
    - oldToCopy[cur->next] looks up the copy of the original's next node
    - If cur->next is nullptr, this will assign nullptr (due to our initial mapping)

19. return oldToCopy[head];
    - Returns the copied version of the original head node
    - The hash map lookup finds the new head of our copied list

Key Concepts:
- Pointers: Variables that store memory addresses of other variables
- Hash Map: Data structure that maps keys to values with fast lookup
- Dynamic Memory: Using 'new' to create objects that persist until 'delete' is called
- Member Access: Using -> for pointers, . for direct objects
- Constructor: Special function that initializes objects when they're created

Note: In competitive programming, memory cleanup with 'delete' is often omitted
since the program terminates quickly, but in production code you should properly
manage memory to avoid leaks.
*/
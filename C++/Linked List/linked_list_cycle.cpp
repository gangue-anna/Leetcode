#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        /**
         * Detect if a linked list has a cycle using Floyd's Tortoise and Hare algorithm.
         * 
         * Approach:
         * - Use two pointers (slow and fast)
         * - Move slow pointer by 1 step and fast pointer by 2 steps
         * - If they meet at any point, there is a cycle
         * - If fast pointer reaches the end (nullptr), no cycle exists
         * 
         * Why this works:
         * - If there's a cycle, fast pointer will eventually "lap" the slow pointer
         * - The relative speed difference ensures they will meet inside the cycle
         * - If no cycle, fast pointer will reach the end first
         * 
         * Time Complexity: O(n) where n is the number of nodes
         *   - In worst case, we visit each node at most twice
         * Space Complexity: O(1) - only using two pointer variables
         */
        
        // Handle edge case: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        // Initialize both pointers to head
        ListNode* slow = head;  // Tortoise: moves 1 step at a time
        ListNode* fast = head;  // Hare: moves 2 steps at a time
        
        // Continue until fast pointer reaches the end
        while (fast != nullptr && fast->next != nullptr) {
            // Move slow pointer by 1 step
            slow = slow->next;
            
            // Move fast pointer by 2 steps
            fast = fast->next->next;
            
            // If pointers meet, we found a cycle
            if (slow == fast) {
                return true;
            }
        }
        
        // If we reach here, fast pointer hit the end, so no cycle
        return false;
    }
};

// -------------------
// Helper Functions for Testing
// -------------------

/**
 * Build a linked list with optional cycle
 * values: vector of node values
 * pos: index where the tail connects to (cycle), or -1 for no cycle
 * Returns the head of the linked list
 */
ListNode* buildLinkedListWithCycle(const vector<int>& values, int pos) {
    if (values.empty()) {
        return nullptr;
    }
    
    // Create all nodes first
    vector<ListNode*> nodes;
    for (int val : values) {
        nodes.push_back(new ListNode(val));
    }
    
    // Link nodes sequentially
    for (int i = 0; i < nodes.size() - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }
    
    // Create cycle if pos is valid
    if (pos >= 0 && pos < values.size()) {
        nodes[nodes.size() - 1]->next = nodes[pos];  // Last node points to pos
    }
    
    return nodes[0];  // Return head
}

/**
 * Clean up memory for linked list without cycle
 * WARNING: Only use this for lists without cycles!
 * For lists with cycles, we need special handling to avoid infinite loops
 */
void deleteLinkedListNoCycle(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 * Clean up memory for linked list that may have a cycle
 * Uses Floyd's algorithm to detect cycle, then breaks it before deletion
 */
void deleteLinkedListWithPossibleCycle(ListNode* head) {
    if (head == nullptr) return;
    
    // First, detect if there's a cycle and break it
    ListNode* slow = head;
    ListNode* fast = head;
    bool hasCycle = false;
    
    // Detect cycle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }
    
    // If cycle exists, break it
    if (hasCycle) {
        // Find the start of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Find the node just before the cycle start
        ListNode* prev = slow;
        while (prev->next != slow) {
            prev = prev->next;
        }
        
        // Break the cycle
        prev->next = nullptr;
    }
    
    // Now safely delete the list
    deleteLinkedListNoCycle(head);
}

/**
 * Print test case results
 */
void printTestResult(int testCase, const vector<int>& values, int pos, bool result) {
    cout << "Test Case " << testCase << ":" << endl;
    cout << "Values: [";
    for (int i = 0; i < values.size(); i++) {
        cout << values[i];
        if (i < values.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Cycle position: " << (pos == -1 ? "No cycle" : "Position " + to_string(pos)) << endl;
    cout << "Has cycle: " << (result ? "true" : "false") << endl;
    cout << endl;
}

// Test function to demonstrate the solution
int main() {
    Solution solution;
    
    // Test Case 1: [3,2,0,-4] with cycle at position 1
    cout << "=== Linked List Cycle Detection Tests ===" << endl << endl;
    
    vector<int> values1 = {3, 2, 0, -4};
    int pos1 = 1;  // Cycle: tail connects to node at index 1
    ListNode* head1 = buildLinkedListWithCycle(values1, pos1);
    bool result1 = solution.hasCycle(head1);
    printTestResult(1, values1, pos1, result1);
    
    // Test Case 2: [1,2] with cycle at position 0
    vector<int> values2 = {1, 2};
    int pos2 = 0;  // Cycle: tail connects to node at index 0
    ListNode* head2 = buildLinkedListWithCycle(values2, pos2);
    bool result2 = solution.hasCycle(head2);
    printTestResult(2, values2, pos2, result2);
    
    // Test Case 3: [1] with no cycle
    vector<int> values3 = {1};
    int pos3 = -1;  // No cycle
    ListNode* head3 = buildLinkedListWithCycle(values3, pos3);
    bool result3 = solution.hasCycle(head3);
    printTestResult(3, values3, pos3, result3);
    
    // Test Case 4: [1,2,3,4,5] with no cycle
    vector<int> values4 = {1, 2, 3, 4, 5};
    int pos4 = -1;  // No cycle
    ListNode* head4 = buildLinkedListWithCycle(values4, pos4);
    bool result4 = solution.hasCycle(head4);
    printTestResult(4, values4, pos4, result4);
    
    // Test Case 5: Empty list
    vector<int> values5 = {};
    int pos5 = -1;
    ListNode* head5 = buildLinkedListWithCycle(values5, pos5);
    bool result5 = solution.hasCycle(head5);
    printTestResult(5, values5, pos5, result5);
    
    // Clean up memory
    // Note: For lists with cycles, we need special cleanup
    deleteLinkedListWithPossibleCycle(head1);
    deleteLinkedListWithPossibleCycle(head2);
    deleteLinkedListWithPossibleCycle(head3);
    deleteLinkedListWithPossibleCycle(head4);
    deleteLinkedListWithPossibleCycle(head5);
    
    cout << "All tests completed successfully!" << endl;
    
    return 0;
}

/*
===============================================================================
C++ SYNTAX EXPLANATION FOR BEGINNERS
===============================================================================

1. #include <bits/stdc++.h>
   - Non-standard header that includes most C++ standard library components
   - Convenient for competitive programming but not recommended for production
   - In real projects, include specific headers like <iostream>, <vector>

2. using namespace std;
   - Allows using standard library names without std:: prefix
   - Example: cout instead of std::cout, vector instead of std::vector
   - Can cause name conflicts in large projects, so use carefully

3. struct ListNode { ... };
   - Defines a structure (similar to class but members are public by default)
   - Contains data members (val, next) and constructors
   - In C++, struct and class are nearly identical except default access

4. ListNode *next;
   - Declares a pointer to another ListNode
   - The asterisk (*) indicates this stores a memory address, not the actual object
   - Can point to another node or be nullptr (no connection)

5. ListNode() : val(0), next(nullptr) {}
   - Default constructor with member initializer list
   - : val(0), next(nullptr) initializes members before constructor body runs
   - {} is empty constructor body - all initialization done in initializer list
   - More efficient than assigning values inside constructor body

6. ListNode(int x) : val(x), next(nullptr) {}
   - Constructor taking one parameter
   - Initializes val with provided value, next with nullptr
   - Allows creating: ListNode node(42);

7. class Solution { public: ... };
   - Defines a class (members are private by default, unlike struct)
   - public: makes following members accessible from outside the class
   - Contains the main algorithm as a member function

8. bool hasCycle(ListNode* head)
   - Function returns boolean (true/false)
   - Takes a pointer to ListNode as parameter
   - Parameter name 'head' represents the first node of the list

9. head == nullptr
   - Compares pointer with nullptr (null pointer)
   - == is equality comparison operator
   - nullptr is modern C++ way to represent "points to nothing"

10. head->next == nullptr
    - Arrow operator (->) accesses members through a pointer
    - Equivalent to (*head).next but more readable
    - Checks if the next pointer of the node is null

11. ListNode* slow = head;
    - Declares a pointer variable 'slow' and initializes it with 'head'
    - Both pointers now point to the same memory location
    - Changes to *slow affect the same object as *head

12. while (fast != nullptr && fast->next != nullptr)
    - Loop continues while both conditions are true
    - && is logical AND operator - both sides must be true
    - != means "not equal to"
    - We check fast->next to ensure fast->next->next won't crash

13. slow = slow->next;
    - Updates slow pointer to point to the next node
    - This "moves" the pointer forward in the linked list
    - After this, slow points to a different node

14. fast = fast->next->next;
    - Moves fast pointer two steps forward
    - First ->next gets the next node, second ->next gets the one after that
    - This is why fast moves twice as fast as slow

15. if (slow == fast)
    - Compares if both pointers point to the same memory location
    - Not comparing values, but actual pointer addresses
    - If true, both pointers reference the same node object

16. return true; / return false;
    - Returns boolean values from the function
    - Immediately exits the function when reached
    - The calling code receives this boolean result

17. const vector<int>& values
    - const: parameter cannot be modified inside the function
    - vector<int>: dynamic array storing integers
    - &: pass by reference (no copy made, more efficient for large objects)
    - Without &, entire vector would be copied

18. vector<ListNode*> nodes;
    - Declares a vector that stores pointers to ListNode objects
    - Dynamic array that can grow/shrink during runtime
    - Each element is a pointer (memory address) to a ListNode

19. for (int val : values)
    - Range-based for loop (C++11 feature)
    - Iterates through each element in the 'values' container
    - 'val' takes the value of each element in turn
    - More readable than traditional index-based loops

20. nodes.push_back(new ListNode(val));
    - push_back(): adds element to the end of vector
    - new ListNode(val): allocates memory for new node with given value
    - Returns pointer to the newly created node
    - Vector stores this pointer, not the actual node

21. nodes[i]->next = nodes[i + 1];
    - Array subscript operator [] accesses vector element by index
    - nodes[i] gets the pointer at index i
    - ->next accesses the next member through that pointer
    - Links current node to the next node in sequence

22. nodes.size()
    - Member function returning number of elements in vector
    - Returns size_t type (unsigned integer)
    - Used for bounds checking and loop conditions

23. delete temp;
    - Frees memory allocated by 'new'
    - Every 'new' must have corresponding 'delete' to prevent memory leaks
    - After delete, the pointer becomes invalid (dangling pointer)

24. to_string(pos)
    - Converts integer 'pos' to string representation
    - Standard library function for type conversion
    - Useful for string concatenation and output

25. cout << "Text" << variable << endl;
    - cout: standard output stream (console)
    - <<: insertion operator, sends data to output stream
    - Can chain multiple << operations in one statement
    - endl: inserts newline and flushes output buffer

ALGORITHM EXPLANATION:
- Floyd's Cycle Detection (Tortoise and Hare):
  * Two pointers move at different speeds through the list
  * If there's a cycle, faster pointer will eventually meet slower one
  * If no cycle, faster pointer reaches end first
  * Mathematical proof: in a cycle, speed difference causes inevitable meeting

MEMORY MANAGEMENT NOTES:
- C++ requires manual memory management with new/delete
- Lists with cycles need special cleanup to avoid infinite loops
- Always pair 'new' with 'delete' to prevent memory leaks
- Modern C++ offers smart pointers (unique_ptr, shared_ptr) for automatic cleanup
*/
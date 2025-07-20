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
    void reorderList(ListNode* head) {
        /**
         * Reorder a linked list as L0→Ln→L1→Ln-1→L2→Ln-2→...
         * 
         * Approach:
         * 1. Find the middle of the list using slow/fast pointers (Floyd's algorithm)
         * 2. Split the list into two halves at the middle
         * 3. Reverse the second half of the list
         * 4. Merge the two halves alternately (first from first half, then from second half)
         * 
         * Example: [1,2,3,4,5] becomes [1,5,2,4,3]
         * Step 1: Split -> [1,2,3] and [4,5]
         * Step 2: Reverse second half -> [1,2,3] and [5,4]
         * Step 3: Merge -> [1,5,2,4,3]
         * 
         * Time Complexity: O(n) where n is the number of nodes
         *   - Finding middle: O(n)
         *   - Reversing second half: O(n/2) = O(n)
         *   - Merging: O(n/2) = O(n)
         *   - Total: O(n) + O(n) + O(n) = O(n)
         * 
         * Space Complexity: O(1) - only using a constant number of pointers
         * Modifies the list in-place, returns void (nothing)
         */
        
        // Handle edge cases: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        // Step 1: Find the middle of the list using slow/fast pointers
        // slow moves 1 step, fast moves 2 steps
        // When fast reaches the end, slow will be at the middle
        ListNode* slow = head;
        ListNode* fast = head->next;  // Start fast one step ahead
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // Move slow by 1 step
            fast = fast->next->next;  // Move fast by 2 steps
        }
        
        // At this point, slow is at the end of the first half
        // Split the list into two halves
        ListNode* second = slow->next;  // Start of second half
        slow->next = nullptr;           // End the first half
        
        // Step 2: Reverse the second half of the list
        // Use standard three-pointer reversal technique
        ListNode* prev = nullptr;
        
        while (second != nullptr) {
            ListNode* tmp = second->next;  // Store next node before changing links
            second->next = prev;           // Reverse the link
            prev = second;                 // Move prev forward
            second = tmp;                  // Move second forward
        }
        
        // Now prev points to the head of the reversed second half
        
        // Step 3: Merge the two halves alternately
        // first: head of first half
        // second: head of reversed second half (which is prev)
        ListNode* first = head;
        second = prev;
        
        while (second != nullptr) {  // Continue until second half is exhausted
            // Store next nodes before changing links
            ListNode* tmp1 = first->next;   // Next node in first half
            ListNode* tmp2 = second->next;  // Next node in second half
            
            // Connect current nodes alternately
            first->next = second;   // Connect first half node to second half node
            second->next = tmp1;    // Connect second half node to next first half node
            
            // Move to next pair of nodes
            first = tmp1;   // Move to next node in first half
            second = tmp2;  // Move to next node in second half
        }
        
        // The list is now reordered in-place
        // No return value needed since we modify the original list
    }
};

// -------------------
// Helper Functions for Testing
// -------------------

/**
 * Convert a vector to a linked list
 */
ListNode* vectorToLinkedList(const vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }
    
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    
    ListNode* head = dummy->next;
    delete dummy;  // Clean up dummy node
    return head;
}

/**
 * Convert a linked list to a vector
 */
vector<int> linkedListToVector(ListNode* head) {
    vector<int> result;
    ListNode* current = head;
    
    while (current != nullptr) {
        result.push_back(current->val);
        current = current->next;
    }
    
    return result;
}

/**
 * Print a vector in a readable format
 */
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

/**
 * Clean up memory by deleting all nodes
 */
void deleteLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 * Test function with detailed output
 */
void testReorderList(Solution& solution, const vector<int>& input, int testCase) {
    cout << "Test Case " << testCase << ":" << endl;
    cout << "Original:  ";
    printVector(input);
    cout << endl;
    
    // Create linked list and reorder it
    ListNode* head = vectorToLinkedList(input);
    solution.reorderList(head);
    
    // Convert back to vector and print
    vector<int> result = linkedListToVector(head);
    cout << "Reordered: ";
    printVector(result);
    cout << endl << endl;
    
    // Clean up memory
    deleteLinkedList(head);
}

// Test function to demonstrate the solution
int main() {
    Solution solution;
    
    cout << "=== Reorder Linked List Tests ===" << endl << endl;
    
    // Test Case 1: [1,2,3,4] -> [1,4,2,3]
    testReorderList(solution, {1, 2, 3, 4}, 1);
    
    // Test Case 2: [1,2,3,4,5] -> [1,5,2,4,3]
    testReorderList(solution, {1, 2, 3, 4, 5}, 2);
    
    // Test Case 3: [1,2] -> [1,2]
    testReorderList(solution, {1, 2}, 3);
    
    // Test Case 4: [1] -> [1]
    testReorderList(solution, {1}, 4);
    
    // Test Case 5: [1,2,3,4,5,6] -> [1,6,2,5,3,4]
    testReorderList(solution, {1, 2, 3, 4, 5, 6}, 5);
    
    // Test Case 6: Empty list
    cout << "Test Case 6:" << endl;
    cout << "Original:  []" << endl;
    ListNode* emptyHead = nullptr;
    solution.reorderList(emptyHead);
    cout << "Reordered: []" << endl << endl;
    
    cout << "All tests completed successfully!" << endl;
    
    return 0;
}

/*
===============================================================================
C++ SYNTAX EXPLANATION FOR BEGINNERS
===============================================================================

1. #include <bits/stdc++.h>
   - Non-standard header that includes most C++ standard library
   - Convenient for competitive programming, but not recommended for production
   - Better to include specific headers like <iostream>, <vector>

2. using namespace std;
   - Allows using standard library functions without std:: prefix
   - Example: cout instead of std::cout, vector instead of std::vector

3. struct ListNode { ... };
   - Defines a structure (like class but members are public by default)
   - Contains data (val, next) and constructors
   - Used to represent nodes in the linked list

4. ListNode *next;
   - Pointer to another ListNode (stores memory address)
   - The asterisk (*) indicates this is a pointer variable
   - Can point to another node or be nullptr (null pointer)

5. ListNode() : val(0), next(nullptr) {}
   - Default constructor with member initializer list
   - : val(0), next(nullptr) initializes members before constructor body
   - {} represents empty constructor body
   - More efficient than assignment inside constructor

6. void reorderList(ListNode* head)
   - Function returns void (nothing) - modifies list in-place
   - Takes pointer to ListNode as parameter
   - The function signature matches the problem requirements

7. if (head == nullptr || head->next == nullptr)
   - Logical OR operator (||) - true if either condition is true
   - == is equality comparison, != is inequality
   - Checks for edge cases: empty list or single node

8. head->next == nullptr
   - Arrow operator (->) accesses member through pointer
   - Equivalent to (*head).next but more readable
   - Used when you have a pointer to an object

9. ListNode* slow = head;
   - Declares pointer variable and initializes it
   - slow now points to the same location as head
   - Used for the "tortoise" in Floyd's algorithm

10. fast = fast->next->next;
    - Chain of arrow operators to move two steps
    - First ->next gets next node, second ->next gets the one after
    - This is how fast pointer moves twice as fast as slow

11. ListNode* second = slow->next;
    - Creates new pointer variable pointing to slow's next node
    - This becomes the start of the second half of the list
    - Used to split the list into two parts

12. slow->next = nullptr;
    - Sets the next pointer to nullptr, effectively cutting the link
    - This separates the first half from the second half
    - nullptr is modern C++ null pointer (safer than NULL)

13. while (second != nullptr)
    - Loop continues while second is not a null pointer
    - != means "not equal to"
    - Standard pattern for traversing linked lists

14. ListNode* tmp = second->next;
    - Store the next node before we change the link
    - Temporary variable to avoid losing reference
    - Essential for the reversal algorithm

15. second->next = prev;
    - Reverse the link: point current node to previous node
    - This is the key step in reversing a linked list
    - Changes the direction of the pointer

16. prev = second; second = tmp;
    - Move both pointers forward for next iteration
    - prev becomes the current node, second becomes the stored next
    - Standard technique for linked list traversal with modification

17. first->next = second;
    - Link current node from first half to current node from second half
    - This creates the alternating pattern
    - Modifies the original list structure

18. const vector<int>& values
    - const: parameter cannot be modified
    - vector<int>: dynamic array of integers
    - &: pass by reference (no copy made, more efficient)

19. values.empty()
    - Member function that returns true if vector has no elements
    - More readable than checking values.size() == 0
    - Standard way to check for empty containers

20. for (int val : values)
    - Range-based for loop (C++11 feature)
    - Iterates through each element in values
    - val takes the value of each element in turn

21. current->next = new ListNode(val);
    - Creates new node with given value using dynamic allocation
    - new returns pointer to newly allocated memory
    - Must be paired with delete to prevent memory leaks

22. delete dummy;
    - Frees memory allocated by new
    - Prevents memory leaks
    - Every new should have corresponding delete

23. result.push_back(current->val);
    - Adds element to end of vector
    - push_back() is vector member function
    - Vector automatically manages memory and resizes

24. vec.size()
    - Returns number of elements in vector
    - Return type is size_t (unsigned integer)
    - Used for loop bounds and conditions

25. cout << "[" << val << "]" << endl;
    - cout: standard output stream (console)
    - << : insertion operator for output
    - endl: newline + flush buffer (ensures immediate output)

ALGORITHM BREAKDOWN:
Step 1 - Find Middle:
- Use Floyd's algorithm (tortoise and hare)
- When fast reaches end, slow is at middle
- This splits list into two roughly equal halves

Step 2 - Reverse Second Half:
- Standard three-pointer reversal technique
- prev, current, next pointers manage the reversal
- Changes direction of all links in second half

Step 3 - Merge Alternately:
- Take one node from first half, then one from second half
- Continue until second half is exhausted
- Creates the required reordering pattern

MEMORY MANAGEMENT:
- Function modifies original list in-place
- No additional memory allocation for algorithm
- Test functions properly clean up with delete
- Always pair new with delete to prevent leaks

TIME COMPLEXITY ANALYSIS:
- Finding middle: O(n/2) = O(n)
- Reversing second half: O(n/2) = O(n) 
- Merging: O(n/2) = O(n)
- Overall: O(n) - linear time complexity

SPACE COMPLEXITY:
- Only uses constant extra space for pointers
- O(1) space complexity (not counting input/output)
- In-place algorithm - very memory efficient
*/
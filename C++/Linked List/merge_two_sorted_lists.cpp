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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /**
         * Merge two sorted linked lists into one sorted list.
         * 
         * Approach:
         * - Use a dummy node and a tail pointer to build the merged list
         * - Compare nodes from both lists and append the smaller one
         * - Attach the remaining nodes from either list at the end
         * 
         * Time Complexity: O(m + n), where m and n are the lengths of the lists
         * Space Complexity: O(1) (in-place, ignoring output space)
         */
        
        // Create a dummy node to simplify the merging process
        // This eliminates the need for special handling of the first node
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;  // tail pointer to build the merged list
        
        // Compare and merge nodes while both lists have nodes
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                // list1 node is smaller, attach it to the merged list
                tail->next = list1;
                list1 = list1->next;  // Move to the next node in list1
            } else {
                // list2 node is smaller or equal, attach it to the merged list
                tail->next = list2;
                list2 = list2->next;  // Move to the next node in list2
            }
            tail = tail->next;  // Move tail pointer to the newly added node
        }
        
        // Attach remaining nodes from either list
        // At most one of these conditions will be true
        if (list1 != nullptr) {
            tail->next = list1;  // Attach remaining nodes from list1
        } else if (list2 != nullptr) {
            tail->next = list2;  // Attach remaining nodes from list2
        }
        
        // Store the actual head before deleting dummy
        ListNode* mergedHead = dummy->next;
        delete dummy;  // Clean up the dummy node to prevent memory leak
        
        return mergedHead;  // Return the head of the merged list
    }
};

// -------------------
// Helper Functions for Testing
// -------------------

/**
 * Convert a vector to a linked list
 * Creates nodes dynamically and links them together
 */
ListNode* vectorToLinkedList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    
    for (int val : nums) {
        current->next = new ListNode(val);
        current = current->next;
    }
    
    ListNode* head = dummy->next;
    delete dummy;  // Clean up dummy node
    return head;
}

/**
 * Convert a linked list to a vector
 * Traverses the list and collects values
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
 * Helper function to print a vector in a readable format
 */
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

/**
 * Clean up memory by deleting all nodes in a linked list
 * Important to prevent memory leaks
 */
void deleteLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Test function to demonstrate the solution
int main() {
    Solution solution;
    
    // Test Case 1: list1 = [1,2,4], list2 = [1,3,4]
    cout << "Test Case 1:" << endl;
    vector<int> input1 = {1, 2, 4};
    vector<int> input2 = {1, 3, 4};
    
    ListNode* list1 = vectorToLinkedList(input1);
    ListNode* list2 = vectorToLinkedList(input2);
    
    cout << "List 1: ";
    printVector(input1);
    cout << "List 2: ";
    printVector(input2);
    
    ListNode* merged1 = solution.mergeTwoLists(list1, list2);
    vector<int> result1 = linkedListToVector(merged1);
    
    cout << "Merged: ";
    printVector(result1);
    cout << endl;
    
    // Test Case 2: list1 = [], list2 = [0]
    cout << "Test Case 2:" << endl;
    vector<int> input3 = {};
    vector<int> input4 = {0};
    
    ListNode* list3 = vectorToLinkedList(input3);
    ListNode* list4 = vectorToLinkedList(input4);
    
    cout << "List 1: ";
    printVector(input3);
    cout << "List 2: ";
    printVector(input4);
    
    ListNode* merged2 = solution.mergeTwoLists(list3, list4);
    vector<int> result2 = linkedListToVector(merged2);
    
    cout << "Merged: ";
    printVector(result2);
    cout << endl;
    
    // Test Case 3: list1 = [], list2 = []
    cout << "Test Case 3:" << endl;
    vector<int> input5 = {};
    vector<int> input6 = {};
    
    ListNode* list5 = vectorToLinkedList(input5);
    ListNode* list6 = vectorToLinkedList(input6);
    
    cout << "List 1: ";
    printVector(input5);
    cout << "List 2: ";
    printVector(input6);
    
    ListNode* merged3 = solution.mergeTwoLists(list5, list6);
    vector<int> result3 = linkedListToVector(merged3);
    
    cout << "Merged: ";
    printVector(result3);
    
    // Clean up memory
    deleteLinkedList(merged1);
    deleteLinkedList(merged2);
    deleteLinkedList(merged3);
    
    return 0;
}

/*
===============================================================================
C++ SYNTAX EXPLANATION FOR BEGINNERS
===============================================================================

1. #include <bits/stdc++.h>
   - This is a non-standard header that includes most of the C++ standard library
   - Commonly used in competitive programming for convenience
   - In production code, you should include specific headers like <iostream>, <vector>

2. using namespace std;
   - Allows us to use standard library functions without the std:: prefix
   - Example: cout instead of std::cout, vector instead of std::vector

3. struct ListNode { ... };
   - 'struct' defines a structure (like a class but members are public by default)
   - Contains data members and constructors
   - In C++, struct and class are almost identical except for default access level

4. ListNode *next;
   - Declares a pointer to a ListNode object
   - The asterisk (*) indicates this is a pointer (stores memory address)
   - Can point to another ListNode or be nullptr (null pointer)

5. ListNode() : val(0), next(nullptr) {}
   - This is a default constructor with member initializer list
   - : val(0), next(nullptr) initializes val to 0 and next to nullptr
   - {} represents an empty constructor body
   - Member initializer lists are more efficient than assignment in constructor body

6. ListNode(int x) : val(x), next(nullptr) {}
   - Constructor that takes an integer parameter 'x'
   - Initializes val with the provided value and next to nullptr

7. ListNode(int x, ListNode *next) : val(x), next(next) {}
   - Constructor that takes both value and next pointer
   - Allows creating a node with a specific value and linking it to another node

8. class Solution { public: ... };
   - 'class' defines a class (members are private by default)
   - 'public:' makes the following members accessible from outside the class
   - Functions defined in a class are called member functions or methods

9. ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
   - Function that returns a pointer to ListNode
   - Takes two parameters, both pointers to ListNode objects
   - The function signature matches the problem requirements

10. ListNode* dummy = new ListNode();
    - Creates a new ListNode object on the heap using 'new'
    - Returns a pointer to the newly created object
    - 'new' allocates memory dynamically - must be paired with 'delete'

11. list1->val
    - Arrow operator (->) accesses member 'val' through pointer 'list1'
    - Equivalent to (*list1).val but more readable
    - Used when you have a pointer to an object

12. list1 != nullptr
    - Compares pointer list1 with nullptr
    - != means "not equal to"
    - nullptr is the modern C++ way to represent null pointer (better than NULL)

13. while (list1 != nullptr && list2 != nullptr)
    - Loop continues while both conditions are true
    - && is the logical AND operator
    - Loop stops when either list becomes nullptr (reaches end)

14. tail->next = list1;
    - Sets the next pointer of the node pointed to by tail
    - Points it to the node currently pointed to by list1
    - This links the nodes together in the merged list

15. list1 = list1->next;
    - Moves the list1 pointer to the next node in the original list
    - This is how we "advance" through the linked list
    - After this, list1 points to the next node (or nullptr if at end)

16. delete dummy;
    - Frees the memory allocated by 'new'
    - Important to prevent memory leaks
    - Every 'new' should have a corresponding 'delete'

17. const vector<int>& nums
    - 'const' means the parameter cannot be modified inside the function
    - '&' means pass by reference (no copy is made, more efficient for large objects)
    - vector<int> is a dynamic array that stores integers

18. nums.empty()
    - Member function that returns true if the vector has no elements
    - More readable than checking if nums.size() == 0

19. for (int val : nums)
    - Range-based for loop (C++11 feature)
    - Iterates through each element in 'nums'
    - 'val' takes the value of each element in the container

20. result.push_back(current->val);
    - Adds an element to the end of the vector
    - push_back() is a member function of vector
    - The vector automatically manages memory and resizes as needed

21. vec.size()
    - Returns the number of elements in the vector
    - Returns type size_t (unsigned integer type)
    - Used in loops and conditions to check vector length

22. cout << "[";
    - cout is the standard output stream (console output)
    - << is the insertion operator, sends data to the output stream
    - Used for printing to console

23. endl
    - Inserts a newline character and flushes the output buffer
    - Ensures the output is immediately displayed
    - Alternative to "\n" but with guaranteed flush

24. return 0;
    - In main() function, returning 0 indicates successful program execution
    - Non-zero return values typically indicate errors
    - This is a convention in C/C++ programs

MEMORY MANAGEMENT NOTES:
- In C++, you're responsible for memory management
- Every 'new' should have a corresponding 'delete'
- Failing to delete allocated memory causes memory leaks
- The helper function deleteLinkedList() cleans up entire lists
- Modern C++ alternatives include smart pointers (unique_ptr, shared_ptr)
*/
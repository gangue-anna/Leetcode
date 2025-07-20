#include <iostream>
#include <vector>
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
    ListNode* reverseList(ListNode* head) {
        /**
         * Reverse a singly linked list using iterative approach
         * Time Complexity: O(n) where n is the number of nodes
         * Space Complexity: O(1) as we only use three pointers
         * 
         * Strategy:
         * 1. Use three pointers: prev, curr, and nextNode
         * 2. For each node:
         *    - Store next node before changing links
         *    - Reverse the link (point current to previous)
         *    - Move pointers forward
         * 3. Return prev as it will be the new head
         */
        
        // Initialize pointers
        ListNode* prev = nullptr;  // Previous node, initially nullptr
        ListNode* curr = head;     // Current node, start with head
        
        // Traverse the list
        while (curr != nullptr) {
            // Store next node before changing links
            ListNode* nextNode = curr->next;
            
            // Reverse the link
            // Point current node's next to previous node
            curr->next = prev;
            
            // Move pointers forward
            prev = curr;      // Previous becomes current
            curr = nextNode;  // Current becomes next
        }
        
        // Return prev as it will be the new head
        // When loop ends, curr is nullptr and prev is the last node
        return prev;
    }
};

// ------------------- 
// Helper Functions for Testing
// -------------------

/**
 * Convert a vector to a linked list
 */
ListNode* vectorToLinkedList(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    
    ListNode* dummy = new ListNode(0);  // Create dummy node
    ListNode* curr = dummy;
    
    for (int val : nums) {
        curr->next = new ListNode(val);
        curr = curr->next;
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
    ListNode* curr = head;
    
    while (curr != nullptr) {
        result.push_back(curr->val);
        curr = curr->next;
    }
    
    return result;
}

/**
 * Helper function to print a vector
 */
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

/**
 * Clean up memory by deleting all nodes in the linked list
 */
void deleteLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Test function
int main() {
    Solution solution;
    
    // Test case 1: [1, 2, 3, 4, 5]
    vector<int> input1 = {1, 2, 3, 4, 5};
    ListNode* head1 = vectorToLinkedList(input1);
    
    cout << "Original list: ";
    printVector(input1);
    
    ListNode* reversed1 = solution.reverseList(head1);
    vector<int> result1 = linkedListToVector(reversed1);
    
    cout << "Reversed list: ";
    printVector(result1);
    cout << endl;
    
    // Test case 2: [1, 2]
    vector<int> input2 = {1, 2};
    ListNode* head2 = vectorToLinkedList(input2);
    
    cout << "Original list: ";
    printVector(input2);
    
    ListNode* reversed2 = solution.reverseList(head2);
    vector<int> result2 = linkedListToVector(reversed2);
    
    cout << "Reversed list: ";
    printVector(result2);
    cout << endl;
    
    // Test case 3: Empty list
    ListNode* head3 = nullptr;
    cout << "Original list: []" << endl;
    
    ListNode* reversed3 = solution.reverseList(head3);
    vector<int> result3 = linkedListToVector(reversed3);
    
    cout << "Reversed list: ";
    printVector(result3);
    
    // Clean up memory
    deleteLinkedList(reversed1);
    deleteLinkedList(reversed2);
    deleteLinkedList(reversed3);
    
    return 0;
}

/*
===============================================================================
C++ SYNTAX EXPLANATION FOR BEGINNERS
===============================================================================

1. #include <iostream>
   - This includes the input/output stream library for cout, cin, etc.

2. #include <vector>
   - This includes the vector library for dynamic arrays

3. using namespace std;
   - This allows us to use cout, cin, vector etc. without writing std:: prefix
   - Without this, we'd need to write std::cout instead of just cout

4. struct ListNode { ... };
   - 'struct' defines a structure (similar to class but members are public by default)
   - Contains data members: int val, ListNode *next
   - Contains constructors (special functions that initialize the object)

5. ListNode *next;
   - The asterisk (*) means this is a pointer to a ListNode object
   - Pointers store memory addresses, not the actual values

6. ListNode() : val(0), next(nullptr) {}
   - This is a constructor using initialization list syntax
   - : val(0), next(nullptr) initializes val to 0 and next to nullptr
   - {} is an empty constructor body
   - nullptr is C++'s null pointer (safer than NULL)

7. class Solution { public: ... };
   - 'class' defines a class (members are private by default)
   - 'public:' makes the following members accessible from outside the class

8. ListNode* reverseList(ListNode* head)
   - This function returns a pointer to ListNode
   - Takes a parameter 'head' which is also a pointer to ListNode

9. ListNode* prev = nullptr;
   - Declares a pointer variable 'prev' and initializes it to nullptr
   - nullptr represents a null pointer (points to nothing)

10. curr->next
    - The arrow operator (->) is used to access members through a pointer
    - Equivalent to (*curr).next but more readable
    - Used when you have a pointer to an object

11. while (curr != nullptr)
    - Loop continues as long as curr is not a null pointer
    - != means "not equal to"

12. vector<int> nums
    - vector is a dynamic array that can grow/shrink during runtime
    - <int> specifies that this vector stores integers
    - Unlike regular arrays, vectors manage memory automatically

13. for (int val : nums)
    - This is a range-based for loop (C++11 feature)
    - Iterates through each element in 'nums'
    - 'val' takes the value of each element in turn

14. new ListNode(val)
    - 'new' allocates memory on the heap and returns a pointer
    - Creates a new ListNode object with value 'val'
    - Must be paired with 'delete' to free memory

15. delete dummy;
    - Frees the memory allocated by 'new'
    - Important to prevent memory leaks

16. const vector<int>& vec
    - 'const' means the parameter cannot be modified inside the function
    - '&' means pass by reference (no copy is made, more efficient)
    - Without &, a copy of the entire vector would be made

17. vec.size()
    - Member function that returns the number of elements in the vector
    - Returns type size_t (unsigned integer type)

18. cout << "[";
    - cout is the standard output stream (console output)
    - << is the insertion operator, sends data to the output stream

19. endl
    - Inserts a newline character and flushes the output buffer
    - Alternative to "\n" but ensures immediate output

20. return 0;
    - In main function, returning 0 indicates successful program execution
    - Non-zero values typically indicate errors
*/
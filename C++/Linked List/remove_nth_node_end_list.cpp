#include <iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /**
         * Remove the nth node from the end of a linked list using two pointers approach.
         * 
         * Algorithm:
         * 1. Create a dummy node pointing to head to handle edge cases (like removing first node)
         * 2. Initialize two pointers: left (starting at dummy) and right (starting at head)
         * 3. Move right pointer n steps ahead to create a gap of n nodes
         * 4. Move both pointers simultaneously until right reaches the end
         * 5. At this point, left will be just before the node to be removed
         * 6. Remove the target node by updating left->next
         * 7. Return dummy->next (which is the new head)
         * 
         * Time Complexity: O(L) where L is the length of the linked list
         * - We traverse the list at most twice: once to move right pointer n steps,
         *   and once to move both pointers to the end
         * 
         * Space Complexity: O(1) 
         * - We only use a constant amount of extra space for pointers and dummy node
         */
        
        // Step 1: Create dummy node to simplify edge case handling
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Step 2: Initialize two pointers
        ListNode* left = dummy;   // Left pointer starts at dummy
        ListNode* right = head;   // Right pointer starts at head
        
        // Step 3: Move right pointer n steps ahead
        while (n > 0 && right != nullptr) {
            right = right->next;
            n--;
        }
        
        // Step 4: Move both pointers until right reaches the end
        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }
        
        // Step 5: Remove the nth node from end
        // At this point, left->next is the node to be removed
        ListNode* nodeToDelete = left->next;
        left->next = left->next->next;
        
        // Step 6: Clean up memory and return result
        ListNode* result = dummy->next;
        delete dummy;        // Free the dummy node
        delete nodeToDelete; // Free the removed node
        
        return result;
    }
};

/*
=== C++ SYNTAX EXPLANATION FOR BEGINNERS ===

1. #include <iostream>
   - This is a preprocessor directive that includes the iostream library
   - iostream provides input/output functionality (like cout, cin)
   - The angle brackets < > indicate it's a system header file

2. using namespace std;
   - This tells the compiler to use the standard namespace
   - Without this, we'd need to write std::cout instead of just cout
   - std is the namespace where standard C++ library functions live

3. struct ListNode {
   - 'struct' defines a structure (similar to class, but members are public by default)
   - ListNode is the name of our structure
   - Curly braces { } contain the structure definition

4. int val;
   - Declares an integer variable named 'val' inside the structure
   - This will store the value of the node

5. ListNode *next;
   - Declares a pointer named 'next' that points to another ListNode
   - The asterisk (*) indicates this is a pointer
   - This creates the link to the next node in the list

6. ListNode() : val(0), next(nullptr) {}
   - This is a constructor (special function that runs when object is created)
   - The colon (:) starts the member initialization list
   - val(0) initializes val to 0
   - next(nullptr) initializes next pointer to nullptr (null pointer)
   - {} is an empty function body since initialization is done in the list

7. ListNode(int x) : val(x), next(nullptr) {}
   - Constructor that takes one parameter 'x'
   - Initializes val to the value of x
   - Still initializes next to nullptr

8. ListNode(int x, ListNode *next) : val(x), next(next) {}
   - Constructor that takes two parameters
   - Initializes both val and next with the provided values

9. class Solution {
   - 'class' defines a class named Solution
   - Classes are like structs but members are private by default

10. public:
    - Access specifier that makes following members accessible from outside the class
    - Without this, the function would be private and unusable

11. ListNode* removeNthFromEnd(ListNode* head, int n) {
    - Function declaration that returns a pointer to ListNode
    - Takes two parameters: head (pointer to ListNode) and n (integer)
    - The function name describes what it does

12. ListNode* dummy = new ListNode(0);
    - Creates a new ListNode object on the heap using 'new' operator
    - new returns a pointer to the created object
    - We store this pointer in 'dummy'

13. dummy->next = head;
    - The arrow operator (->) is used to access members through a pointer
    - This sets the next pointer of dummy to point to head
    - Equivalent to (*dummy).next = head

14. while (n > 0 && right != nullptr) {
    - while loop that continues as long as both conditions are true
    - && is the logical AND operator
    - != means "not equal to"
    - nullptr is C++'s null pointer literal

15. right = right->next;
    - Updates right pointer to point to the next node
    - Uses arrow operator to access next member through pointer

16. delete dummy;
    - Frees the memory allocated for dummy node
    - Important to prevent memory leaks when using 'new'
    - Every 'new' should have a corresponding 'delete'

17. return result;
    - Returns the pointer stored in result
    - This becomes the new head of the modified list

Note: In competitive programming, you often don't need to worry about 'delete'
statements as the program ends quickly, but it's good practice for real applications.
*/
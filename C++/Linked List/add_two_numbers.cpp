#include <bits/stdc++.h>  // includes all standard C++ libraries
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;             // value of this node
    ListNode *next;      // pointer to the next node

    // Default constructor: sets val=0 and next=nullptr
    ListNode() : val(0), next(nullptr) {}

    // Constructor with just a value
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor with a value and pointer to next node
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * Adds two numbers represented by two linked lists.
     * Digits are stored in reverse order.
     *
     * Time Complexity: O(max(m, n))
     * - because we traverse both lists once, where m and n are their lengths
     *
     * Space Complexity: O(max(m, n))
     * - because the result list can be as long as the longer input list (+1 if carry remains)
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to simplify result list construction
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;   // pointer to the current position in the result list
        int carry = 0;          // variable to hold carry from previous sum

        // Loop runs as long as either list has nodes left or there is a carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int v1 = (l1 != nullptr) ? l1->val : 0;  // get value of current l1 node or 0 if l1 is exhausted
            int v2 = (l2 != nullptr) ? l2->val : 0;  // get value of current l2 node or 0 if l2 is exhausted

            int val = v1 + v2 + carry;    // sum current digits and carry
            carry = val / 10;            // compute new carry
            val = val % 10;             // keep only the single digit

            // Create a new node with the computed digit and link it to the result
            cur->next = new ListNode(val);

            cur = cur->next;  // move to the newly added node

            // Move to next nodes in l1 and l2 if possible
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // Return the result list, skipping the dummy head
        return dummy->next;
    }
};

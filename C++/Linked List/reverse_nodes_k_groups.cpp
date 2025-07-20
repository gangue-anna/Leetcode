#include <bits/stdc++.h>  // includes all standard C++ headers
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * Reverse nodes in k-sized groups.
     *
     * Strategy:
     * 1. Use a dummy node to simplify operations at the head.
     * 2. For each group of k nodes:
     *      - Find the kth node
     *      - Reverse the group
     *      - Connect the reversed group back to the list
     *
     * Time Complexity: O(n) — each node is visited once
     * Space Complexity: O(1) — uses only pointers
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // dummy node to simplify edge cases
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (true) {
            // find kth node from current position
            ListNode* kth = getKth(groupPrev, k);
            if (!kth) break;  // not enough nodes to reverse
            ListNode* groupNext = kth->next;

            // reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // connect previous part to new head
            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp;
        }

        return dummy.next;
    }

private:
    /**
     * Helper function: get the kth node from current node
     *
     * Args:
     *   curr: starting node
     *   k: number of steps to move
     *
     * Returns:
     *   pointer to kth node if exists, else nullptr
     */
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};


/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers (like <vector>, <iostream>, etc.) at once.

using namespace std;
    ✅ Allows you to use names like vector, cout without writing std::vector.

struct ListNode {
    ✅ Defines a structure to represent a node of a singly-linked list.

int val;
    ✅ Stores the integer value of this node.

ListNode* next;
    ✅ Pointer to the next node in the list.

ListNode() : val(0), next(nullptr) {}
    ✅ Default constructor: sets val = 0 and next = nullptr.

ListNode(int x) : val(x), next(nullptr) {}
    ✅ Constructor that initializes val = x, next = nullptr.

ListNode(int x, ListNode* next) : val(x), next(next) {}
    ✅ Constructor with val and next pointer.

class Solution {
    ✅ Defines the class Solution.

public:
    ✅ Public methods accessible from outside the class.

ListNode* reverseKGroup(ListNode* head, int k)
    ✅ Function that reverses nodes in k-sized groups.

ListNode dummy(0, head);
    ✅ Dummy node with value 0, next pointing to head.

ListNode* groupPrev = &dummy;
    ✅ Pointer that tracks the node before the current group.

while (true)
    ✅ Infinite loop that breaks when fewer than k nodes remain.

ListNode* kth = getKth(groupPrev, k);
    ✅ Find the kth node from current position.

if (!kth) break;
    ✅ If kth is nullptr (not enough nodes), exit loop.

ListNode* groupNext = kth->next;
    ✅ Next node after the group.

ListNode* prev = groupNext;
ListNode* curr = groupPrev->next;
    ✅ Initialize pointers for reversal: prev is one step beyond group.

while (curr != groupNext)
    ✅ Reverse nodes in the current group.

ListNode* tmp = curr->next;
    ✅ Save next node.

curr->next = prev;
    ✅ Reverse the link of current node.

prev = curr; curr = tmp;
    ✅ Advance both pointers.

ListNode* tmp = groupPrev->next;
    ✅ Save old start of group (which becomes the end after reversal).

groupPrev->next = kth;
    ✅ Connect previous part to new head of group.

groupPrev = tmp;
    ✅ Move groupPrev forward for next group.

return dummy.next;
    ✅ Return new head of the reversed list.

private:
    ✅ Members below are accessible only within the class.

ListNode* getKth(ListNode* curr, int k)
    ✅ Finds the kth node from curr, or nullptr if not enough nodes.

while (curr && k > 0)
    ✅ Traverse k steps forward.

return curr;
    ✅ Return the kth node or nullptr.

*/

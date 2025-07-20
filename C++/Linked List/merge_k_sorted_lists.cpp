#include <bits/stdc++.h>  // includes all standard C++ libraries
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    // default constructor
    ListNode() : val(0), next(nullptr) {}

    // constructor with value
    ListNode(int x) : val(x), next(nullptr) {}

    // constructor with value and next node
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * Merge k sorted linked lists into one sorted linked list.
     *
     * Strategy:
     * - Use divide and conquer: merge pairs of lists repeatedly
     * - Each iteration reduces number of lists by half
     *
     * Time Complexity: O(n log k)
     *   - n = total number of nodes
     *   - k = number of lists
     *   - log k = number of merge iterations
     *
     * Space Complexity: O(1), since we reuse existing nodes
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;  // if list is empty, return null

        // Keep merging until only one list remains
        while (lists.size() > 1) {
            vector<ListNode*> mergedList;  // store merged pairs

            // merge lists in pairs
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                mergedList.push_back(mergeTwoLists(l1, l2));
            }
            lists = mergedList;  // replace lists with merged result
        }

        return lists[0];  // the final merged list
    }

private:
    /**
     * Helper function to merge two sorted lists.
     *
     * Args:
     *   l1: head of first sorted list
     *   l2: head of second sorted list
     *
     * Returns:
     *   head of merged sorted list
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;  // dummy head to simplify operations
        ListNode* tail = &dummy;  // pointer to build the result list

        // merge nodes from both lists in sorted order
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // attach any remaining nodes
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;

        return dummy.next;  // skip dummy head and return merged list
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ libraries in a single line.

using namespace std;
    ✅ Allows using names like vector, cout, etc., without writing std::vector.

struct ListNode {
    ✅ Defines a structure (like a class) to represent a node of a singly linked list.

int val;
    ✅ Stores the integer value of this node.

ListNode* next;
    ✅ Pointer to the next node in the list.

ListNode() : val(0), next(nullptr) {}
    ✅ Default constructor: sets val = 0 and next = nullptr.

ListNode(int x) : val(x), next(nullptr) {}
    ✅ Constructor with just value.

ListNode(int x, ListNode *next) : val(x), next(next) {}
    ✅ Constructor with value and pointer to next node.

class Solution {
    ✅ Defines a class named Solution.

public:
    ✅ All members declared here are publicly accessible.

ListNode* mergeKLists(vector<ListNode*>& lists)
    ✅ Function that takes a vector of ListNode pointers and returns a merged list head.

if (lists.empty()) return nullptr;
    ✅ If the input vector is empty, return null pointer.

while (lists.size() > 1)
    ✅ Loop until only one list remains.

vector<ListNode*> mergedList;
    ✅ Temporary vector to store merged lists.

for (int i = 0; i < lists.size(); i += 2)
    ✅ Iterate over the lists two at a time.

ListNode* l1 = lists[i];
    ✅ First list in the pair.

ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
    ✅ Second list if exists, otherwise nullptr.

mergedList.push_back(mergeTwoLists(l1, l2));
    ✅ Merge the pair and add to mergedList.

lists = mergedList;
    ✅ Replace lists with the newly merged lists.

return lists[0];
    ✅ Return the final merged list head.

private:
    ✅ Members below are only accessible within the class.

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    ✅ Helper function to merge two sorted linked lists.

ListNode dummy;
    ✅ Dummy node to simplify result list construction.

ListNode* tail = &dummy;
    ✅ Pointer to track the end of the result list.

if (l1->val < l2->val)
    ✅ Choose the smaller value node and advance that list.

tail = tail->next;
    ✅ Advance tail pointer.

if (l1) tail->next = l1;
if (l2) tail->next = l2;
    ✅ Attach remaining nodes if one list is longer.

return dummy.next;
    ✅ Return the merged list (skip dummy head).

*/

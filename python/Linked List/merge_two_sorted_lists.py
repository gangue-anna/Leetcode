from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        """
        Merge two sorted linked lists into one sorted list.
        Approach:
        - Use a dummy node and a tail pointer to build the merged list.
        - Compare nodes from both lists and append the smaller one.
        - Attach the remaining nodes from either list at the end.
        Time Complexity: O(m + n), where m and n are the lengths of the lists
        Space Complexity: O(1) (in-place, ignoring output)
        """
        dummy = ListNode()
        tail = dummy
        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next
        if list1:
            tail.next = list1
        elif list2:
            tail.next = list2
        return dummy.next

# -------------------
# Helper Functions for Testing
# -------------------
def list_to_linkedlist(lst):
    dummy = ListNode()
    cur = dummy
    for val in lst:
        cur.next = ListNode(val)
        cur = cur.next
    return dummy.next

def linkedlist_to_list(node):
    result = []
    while node:
        result.append(node.val)
        node = node.next
    return result

# -------------------
# Test Cases
# -------------------
def test_merge_two_sorted_lists():
    s = Solution()
    # Test case 1: Both lists non-empty
    l1 = list_to_linkedlist([1,2,4])
    l2 = list_to_linkedlist([1,3,4])
    result = s.mergeTwoLists(l1, l2)
    assert linkedlist_to_list(result) == [1,1,2,3,4,4]
    # Test case 2: One list empty
    l1 = list_to_linkedlist([])
    l2 = list_to_linkedlist([0])
    result = s.mergeTwoLists(l1, l2)
    assert linkedlist_to_list(result) == [0]
    # Test case 3: Both lists empty
    l1 = list_to_linkedlist([])
    l2 = list_to_linkedlist([])
    result = s.mergeTwoLists(l1, l2)
    assert linkedlist_to_list(result) == []
    # Test case 4: Lists with negative numbers
    l1 = list_to_linkedlist([-3,0,2])
    l2 = list_to_linkedlist([-2,1,3])
    result = s.mergeTwoLists(l1, l2)
    assert linkedlist_to_list(result) == [-3,-2,0,1,2,3]
    # Test case 5: One list much longer
    l1 = list_to_linkedlist([1])
    l2 = list_to_linkedlist([2,3,4,5,6])
    result = s.mergeTwoLists(l1, l2)
    assert linkedlist_to_list(result) == [1,2,3,4,5,6]
    print("All test cases passed!")

if __name__ == "__main__":
    test_merge_two_sorted_lists()
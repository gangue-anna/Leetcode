from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Reorder a linked list as L0→Ln→L1→Ln-1→L2→Ln-2→...
        Approach:
        1. Find the middle of the list (slow/fast pointers).
        2. Reverse the second half of the list.
        3. Merge the two halves alternately.
        Time Complexity: O(n)
        Space Complexity: O(1) (in-place)
        Modifies the list in-place, returns None.
        """
        if not head or not head.next:
            return
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next #type: ignore
            fast = fast.next.next
        second = slow.next #type: ignore
        prev = slow.next = None #type: ignore
        # Reverse second half
        while second:
            tmp = second.next  # type: ignore
            second.next = prev  # type: ignore
            prev = second
            second = tmp
        # Merge two halves
        first, second = head, prev
        while second:
            tmp1, tmp2 = first.next, second.next  # type: ignore
            first.next = second  # type: ignore
            second.next = tmp1  # type: ignore
            first, second = tmp1, tmp2

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
def test_reorder_list():
    s = Solution()
    # Test case 1: Even number of nodes
    l = [1,2,3,4]
    head = list_to_linkedlist(l)
    s.reorderList(head)
    assert linkedlist_to_list(head) == [1,4,2,3]
    # Test case 2: Odd number of nodes
    l = [1,2,3,4,5]
    head = list_to_linkedlist(l)
    s.reorderList(head)
    assert linkedlist_to_list(head) == [1,5,2,4,3]
    # Test case 3: Two nodes
    l = [1,2]
    head = list_to_linkedlist(l)
    s.reorderList(head)
    assert linkedlist_to_list(head) == [1,2]
    # Test case 4: Single node
    l = [1]
    head = list_to_linkedlist(l)
    s.reorderList(head)
    assert linkedlist_to_list(head) == [1]
    # Test case 5: Empty list
    l = []
    head = list_to_linkedlist(l)
    s.reorderList(head)
    assert linkedlist_to_list(head) == []
    print("All test cases passed!")

if __name__ == "__main__":
    test_reorder_list()

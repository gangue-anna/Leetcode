from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        """
        Remove the nth node from the end of a linked list.
        Approach:
        - Use two pointers (left and right).
        - Move right pointer n steps ahead.
        - Move both pointers until right reaches the end.
        - Remove the node after left.
        Time Complexity: O(L), where L is the length of the list
        Space Complexity: O(1)
        """
        dummy = ListNode(0, head)
        left = dummy
        right = head
        while n > 0 and right:
            right = right.next  # type: ignore
            n -= 1
        while right:
            left = left.next  # type: ignore
            right = right.next  # type: ignore
        # delete
        left.next = left.next.next  # type: ignore
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
def test_remove_nth_node_end_list():
    s = Solution()
    # Test case 1: Remove from middle
    l = [1,2,3,4,5]
    head = list_to_linkedlist(l)
    result = s.removeNthFromEnd(head, 2)
    assert linkedlist_to_list(result) == [1,2,3,5]
    # Test case 2: Remove head
    l = [1,2]
    head = list_to_linkedlist(l)
    result = s.removeNthFromEnd(head, 2)
    assert linkedlist_to_list(result) == [2]
    # Test case 3: Remove last node
    l = [1,2,3]
    head = list_to_linkedlist(l)
    result = s.removeNthFromEnd(head, 1)
    assert linkedlist_to_list(result) == [1,2]
    # Test case 4: Single node
    l = [1]
    head = list_to_linkedlist(l)
    result = s.removeNthFromEnd(head, 1)
    assert linkedlist_to_list(result) == []
    # Test case 5: n equals list length
    l = [1,2,3,4]
    head = list_to_linkedlist(l)
    result = s.removeNthFromEnd(head, 4)
    assert linkedlist_to_list(result) == [2,3,4]
    print("All test cases passed!")

if __name__ == "__main__":
    test_remove_nth_node_end_list()
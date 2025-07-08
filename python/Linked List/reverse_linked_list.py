from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Reverse a singly linked list using iterative approach
        Time Complexity: O(n) where n is the number of nodes
        Space Complexity: O(1) as we only use three pointers
        
        Strategy:
        1. Use three pointers: prev, curr, and next_node
        2. For each node:
           - Store next node before changing links
           - Reverse the link (point current to previous)
           - Move pointers forward
        3. Return prev as it will be the new head
        """
        # Initialize pointers
        prev = None  # Previous node, initially None
        curr = head  # Current node, start with head
        
        # Traverse the list
        while curr:
            # Store next node before changing links
            next_node = curr.next
            
            # Reverse the link
            # Point current node's next to previous node
            curr.next = prev
            
            # Move pointers forward
            prev = curr  # Previous becomes current
            curr = next_node  # Current becomes next
            
        # Return prev as it will be the new head
        # When loop ends, curr is None and prev is the last node
        return prev

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
def test_reverse_linked_list():
    s = Solution()
    # Test case 1: Multiple nodes
    l = [1,2,3,4,5]
    head = list_to_linkedlist(l)
    result = s.reverseList(head)
    assert linkedlist_to_list(result) == [5,4,3,2,1]
    # Test case 2: Two nodes
    l = [1,2]
    head = list_to_linkedlist(l)
    result = s.reverseList(head)
    assert linkedlist_to_list(result) == [2,1]
    # Test case 3: Single node
    l = [1]
    head = list_to_linkedlist(l)
    result = s.reverseList(head)
    assert linkedlist_to_list(result) == [1]
    # Test case 4: Empty list
    l = []
    head = list_to_linkedlist(l)
    result = s.reverseList(head)
    assert linkedlist_to_list(result) == []
    print("All test cases passed!")

if __name__ == "__main__":
    test_reverse_linked_list()
        
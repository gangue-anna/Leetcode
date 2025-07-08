from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        """
        Reverse nodes in a linked list k at a time.
        
        Strategy:
        1. Use a dummy node to handle the head of the list
        2. For each group of k nodes:
           - Find the kth node
           - Reverse the group
           - Connect the reversed group to the rest of the list
        
        Time Complexity: O(n) where n is the number of nodes
        Space Complexity: O(1) as we only use pointers
        
        Example:
        Input: 1->2->3->4->5, k=2
        Output: 2->1->4->3->5
        """
        # Create dummy node to handle the head of the list
        dummy = ListNode(0, head)
        groupPrev = dummy

        while True:
            # Get the kth node from the current position
            kth = self.getKth(groupPrev, k)  # type: ignore
            if not kth:
                break
            groupNext = kth.next  # type: ignore

            # Reverse the group
            prev, curr = kth.next, groupPrev.next  # type: ignore
            while curr != groupNext:
                tmp = curr.next  # type: ignore
                curr.next = prev  # type: ignore
                prev = curr
                curr = tmp

            # Connect the reversed group to the rest of the list
            tmp = groupPrev.next  # type: ignore
            groupPrev.next = kth  # type: ignore
            groupPrev = tmp
            
        return dummy.next

    def getKth(self, curr: ListNode, k: int) -> Optional[ListNode]:
        """
        Get the kth node from the current position.
        
        Args:
            curr: Current node
            k: Number of nodes to traverse
            
        Returns:
            The kth node or None if not enough nodes
        """
        while curr and k > 0:
            curr = curr.next  # type: ignore
            k -= 1
        return curr

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
def test_reverse_k_group():
    s = Solution()
    # Test case 1: k = 2
    l = [1,2,3,4,5]
    head = list_to_linkedlist(l)
    result = s.reverseKGroup(head, 2)
    assert linkedlist_to_list(result) == [2,1,4,3,5]
    # Test case 2: k = 3
    l = [1,2,3,4,5]
    head = list_to_linkedlist(l)
    result = s.reverseKGroup(head, 3)
    assert linkedlist_to_list(result) == [3,2,1,4,5]
    # Test case 3: k = 1 (no change)
    l = [1,2,3]
    head = list_to_linkedlist(l)
    result = s.reverseKGroup(head, 1)
    assert linkedlist_to_list(result) == [1,2,3]
    # Test case 4: k equals list length
    l = [1,2,3,4]
    head = list_to_linkedlist(l)
    result = s.reverseKGroup(head, 4)
    assert linkedlist_to_list(result) == [4,3,2,1]
    # Test case 5: List length not a multiple of k
    l = [1,2,3,4,5,6,7]
    head = list_to_linkedlist(l)
    result = s.reverseKGroup(head, 3)
    assert linkedlist_to_list(result) == [3,2,1,6,5,4,7]
    # Test case 6: Empty list
    l = []
    head = list_to_linkedlist(l)
    result = s.reverseKGroup(head, 2)
    assert linkedlist_to_list(result) == []
    print("All test cases passed!")

if __name__ == "__main__":
    test_reverse_k_group()
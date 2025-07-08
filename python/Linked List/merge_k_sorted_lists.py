from typing import Optional
from typing import List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        """
        Merge k sorted linked lists into one sorted linked list.
        
        Strategy:
        1. Use divide and conquer approach
        2. Repeatedly merge pairs of lists until only one list remains
        3. Each iteration reduces the number of lists by half
        
        Time Complexity: O(n log k) where:
        - n is the total number of nodes across all lists
        - k is the number of linked lists
        - log k is the number of merge operations needed
        
        Space Complexity: O(1) as we reuse existing nodes
        """
        if not lists or len(lists) == 0:
            return None
        
        # Continue until only one list remains
        while len(lists) > 1:
            mergedList = []

            # Merge pairs of lists
            for i in range(0, len(lists), 2):
                l1 = lists[i]
                l2 = lists[i + 1] if (i + 1) < len(lists) else None
                mergedList.append(self.mergeLists(l1, l2))
            lists = mergedList
            
        return lists[0]

    def mergeLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        """
        Merge two sorted linked lists into one sorted list.
        
        Args:
            l1: First sorted linked list
            l2: Second sorted linked list
            
        Returns:
            Merged sorted linked list
        """
        # Create dummy node to handle the result list
        dummy = ListNode()
        tail = dummy

        # Compare and merge nodes from both lists
        while l1 and l2:
            if l1.val < l2.val:
                tail.next = l1
                l1 = l1.next
            else:
                tail.next = l2
                l2 = l2.next
            tail = tail.next

        # Attach remaining nodes from either list
        if l1:
            tail.next = l1
        if l2:
            tail.next = l2
            
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
def test_merge_k_sorted_lists():
    s = Solution()
    # Test case 1: Three sorted lists
    lists = [[1,4,5],[1,3,4],[2,6]]
    llists = [list_to_linkedlist(l) for l in lists]
    result = s.mergeKLists(llists)
    assert linkedlist_to_list(result) == [1,1,2,3,4,4,5,6]
    # Test case 2: Empty list of lists
    lists = []
    llists = [list_to_linkedlist(l) for l in lists]
    result = s.mergeKLists(llists)
    assert linkedlist_to_list(result) == []
    # Test case 3: All lists empty
    lists = [[],[],[]]
    llists = [list_to_linkedlist(l) for l in lists]
    result = s.mergeKLists(llists)
    assert linkedlist_to_list(result) == []
    # Test case 4: Single list
    lists = [[1,2,3]]
    llists = [list_to_linkedlist(l) for l in lists]
    result = s.mergeKLists(llists)
    assert linkedlist_to_list(result) == [1,2,3]
    # Test case 5: Lists with negative numbers
    lists = [[-10,-5,0],[1,2,3],[-2,4]]
    llists = [list_to_linkedlist(l) for l in lists]
    result = s.mergeKLists(llists)
    assert linkedlist_to_list(result) == [-10,-5,-2,0,1,2,3,4]
    print("All test cases passed!")

if __name__ == "__main__":
    test_merge_k_sorted_lists()
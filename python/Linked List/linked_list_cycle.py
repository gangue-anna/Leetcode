from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        """
        Detect if a linked list has a cycle using Floyd's Tortoise and Hare algorithm.
        Approach:
        - Use two pointers (slow and fast).
        - Move slow by 1 and fast by 2 steps.
        - If they meet, there is a cycle. If fast reaches the end, no cycle.
        Time Complexity: O(n)
        Space Complexity: O(1)
        """
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next  # type: ignore
            fast = fast.next.next
            if slow == fast:
                return True
        return False

# -------------------
# Helper Functions for Testing
# -------------------
def build_linked_list_with_cycle(values, pos):
    """
    values: list of node values
    pos: index where the tail connects to (cycle), or -1 for no cycle
    Returns the head of the linked list
    """
    if not values:
        return None
    nodes = [ListNode(val) for val in values]
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i+1]  # type: ignore
    if pos != -1:
        nodes[-1].next = nodes[pos]  # type: ignore
    return nodes[0]

# -------------------
# Test Cases
# -------------------
def test_linked_list_cycle():
    s = Solution()
    # Test case 1: Cycle exists
    head = build_linked_list_with_cycle([3,2,0,-4], 1)
    assert s.hasCycle(head) == True
    # Test case 2: No cycle
    head = build_linked_list_with_cycle([1,2], -1)
    assert s.hasCycle(head) == False
    # Test case 3: Single node, no cycle
    head = build_linked_list_with_cycle([1], -1)
    assert s.hasCycle(head) == False
    # Test case 4: Single node, cycle to self
    head = build_linked_list_with_cycle([1], 0)
    assert s.hasCycle(head) == True
    # Test case 5: Empty list
    head = build_linked_list_with_cycle([], -1)
    assert s.hasCycle(head) == False
    print("All test cases passed!")

if __name__ == "__main__":
    test_linked_list_cycle()
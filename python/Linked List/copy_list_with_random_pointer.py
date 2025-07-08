from typing import Optional, Dict

# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Optional[Node]' = None, random: 'Optional[Node]' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: Optional[Node]) -> Optional[Node]:
        """
        Deep copy a linked list where each node has a random pointer.
        Approach:
        - Use a hash map to map original nodes to their copies.
        - First pass: create all nodes and store mapping.
        - Second pass: assign next and random pointers using the map.
        Time Complexity: O(n)
        Space Complexity: O(n)
        """
        oldToCopy: Dict[Optional[Node], Optional[Node]] = {None: None}
        cur = head
        while cur:
            copy = Node(cur.val)
            oldToCopy[cur] = copy
            cur = cur.next
        cur = head
        while cur:
            copy = oldToCopy[cur]
            copy.next = oldToCopy[cur.next]  # type: ignore
            copy.random = oldToCopy[cur.random]  # type: ignore
            cur = cur.next
        return oldToCopy[head]

# -------------------
# Helper Functions for Testing
# -------------------
def build_linked_list_with_random(arr):
    """
    arr: List of [val, random_index] where random_index is the index of the node the random pointer should point to, or None.
    Returns the head of the linked list.
    """
    if not arr:
        return None
    nodes = [Node(val) for val, _ in arr]
    for i, (val, rand_idx) in enumerate(arr):
        if i < len(nodes) - 1:
            nodes[i].next = nodes[i+1]
        nodes[i].random = nodes[rand_idx] if rand_idx is not None else None
    return nodes[0]

def linked_list_with_random_to_list(head: Optional[Node]):
    """
    Returns a list of [val, random_index] for the linked list.
    """
    nodes = []
    node_to_idx = dict()
    cur = head
    idx = 0
    while cur:
        nodes.append(cur)
        node_to_idx[cur] = idx
        cur = cur.next
        idx += 1
    result = []
    for i, node in enumerate(nodes):
        rand_idx = node_to_idx[node.random] if node.random in node_to_idx else None
        result.append([node.val, rand_idx])
    return result

# -------------------
# Test Cases
# -------------------
def test_copy_list_with_random_pointer():
    s = Solution()
    # Test case 1: Basic
    arr = [[7, None], [13, 0], [11, 4], [10, 2], [1, 0]]
    head = build_linked_list_with_random(arr)
    copied = s.copyRandomList(head)
    assert linked_list_with_random_to_list(copied) == arr
    # Test case 2: Single node, random to self
    arr = [[1, 0]]
    head = build_linked_list_with_random(arr)
    copied = s.copyRandomList(head)
    assert linked_list_with_random_to_list(copied) == arr
    # Test case 3: Empty list
    arr = []
    head = build_linked_list_with_random(arr)
    copied = s.copyRandomList(head)
    assert copied is None
    # Test case 4: All randoms are None
    arr = [[1, None], [2, None], [3, None]]
    head = build_linked_list_with_random(arr)
    copied = s.copyRandomList(head)
    assert linked_list_with_random_to_list(copied) == arr
    print("All test cases passed!")

if __name__ == "__main__":
    test_copy_list_with_random_pointer()
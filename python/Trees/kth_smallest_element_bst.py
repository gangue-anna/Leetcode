from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        """
        Finds the k-th smallest element in a Binary Search Tree (BST).
        Approach:
        - Uses iterative in-order traversal (left-root-right) with a stack.
        - In-order traversal of BST yields nodes in ascending order.
        - Increment a counter each time a node is visited; when counter == k, return node's value.

        Time Complexity: O(H + k), where H is the height of the tree. In the worst case (unbalanced tree), H = N, so O(N). For balanced BST, H = logN.
        Space Complexity: O(H), for the stack used in traversal (H = height of the tree).
        """
        n = 0
        stack = []
        curr = root

        # Iterative in-order traversal
        while curr or stack:
            # Go as left as possible
            while curr:
                stack.append(curr)
                curr = curr.left
            # Visit node
            curr = stack.pop()
            n += 1
            if n == k:
                return curr.val
            # Move to right subtree
            curr = curr.right
        raise ValueError("k is larger than the number of nodes in the tree")

# -------------------
# Helper Functions for Testing
# -------------------
def build_tree_from_list(lst):
    if not lst:
        return None
    nodes = [TreeNode(val) if val is not None else None for val in lst]
    kids = nodes[::-1]
    root = kids.pop()
    for node in nodes:
        if node:
            if kids: node.left = kids.pop()
            if kids: node.right = kids.pop()
    return root

# -------------------
# Test Cases
# -------------------
def test_kth_smallest():
    s = Solution()
    # Test case 1: Example
    root = build_tree_from_list([3,1,4,None,2])
    assert s.kthSmallest(root, 1) == 1
    assert s.kthSmallest(root, 2) == 2
    assert s.kthSmallest(root, 3) == 3
    assert s.kthSmallest(root, 4) == 4
    # Test case 2: Single node
    root = build_tree_from_list([1])
    assert s.kthSmallest(root, 1) == 1
    # Test case 3: Left-skewed BST
    root = build_tree_from_list([5,4,None,3,None,2,None,1])
    assert s.kthSmallest(root, 1) == 1
    assert s.kthSmallest(root, 5) == 5
    # Test case 4: Right-skewed BST
    root = build_tree_from_list([1,None,2,None,3,None,4])
    assert s.kthSmallest(root, 1) == 1
    assert s.kthSmallest(root, 4) == 4
    print("All test cases passed!")

if __name__ == "__main__":
    test_kth_smallest()

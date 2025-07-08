# type: ignore
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        """
        Finds the lowest common ancestor (LCA) of two nodes in a BST.
        Approach:
        - Traverse from root, using BST property:
          - If both p and q are greater than current, go right.
          - If both are less, go left.
          - Otherwise, current is the LCA.
        Time Complexity: O(h) (h = height of tree)
        Space Complexity: O(1)
        """
        curr = root
        while curr:
            if p.val > curr.val and q.val > curr.val:
                curr = curr.right
            elif p.val < curr.val and q.val < curr.val:
                curr = curr.left
            else:
                return curr
        return None  # type: ignore

# -------------------
# Helper Functions for Testing
# -------------------
def build_bst_from_list(lst):
    if not lst:
        return None
    nodes = [TreeNode(val) if val is not None else None for val in lst]
    kids = nodes[::-1]
    root = kids.pop()
    for node in nodes:
        if node:
            if kids: node.left = kids.pop()  # type: ignore
            if kids: node.right = kids.pop()  # type: ignore
    return root

def find_node(root, val):
    if not root:
        return None
    if root.val == val:
        return root
    left = find_node(root.left, val)
    if left:
        return left
    return find_node(root.right, val)

# -------------------
# Test Cases
# -------------------
def test_lowest_common_ancestor():
    s = Solution()
    # Test case 1: Example
    root = build_bst_from_list([6,2,8,1,4,7,9,None,None,3,5])
    p = find_node(root, 2)
    q = find_node(root, 8)
    assert s.lowestCommonAncestor(root, p, q).val == 6  # type: ignore
    p = find_node(root, 2)
    q = find_node(root, 4)
    assert s.lowestCommonAncestor(root, p, q).val == 2  # type: ignore
    # Test case 2: Single node
    root = build_bst_from_list([1])
    p = find_node(root, 1)
    q = find_node(root, 1)
    assert s.lowestCommonAncestor(root, p, q).val == 1  # type: ignore
    # Test case 3: LCA is root
    root = build_bst_from_list([5,3,6,2,4])
    p = find_node(root, 2)
    q = find_node(root, 6)
    assert s.lowestCommonAncestor(root, p, q).val == 5  # type: ignore
    print("All test cases passed!")

if __name__ == "__main__":
    test_lowest_common_ancestor()
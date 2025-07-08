from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        """
        Inverts a binary tree (mirror image).
        Approach:
        - Recursively swap left and right children for each node.
        Time Complexity: O(n)
        Space Complexity: O(h) (h = height of tree)
        """
        if not root:
            return None
        # Swap the children
        tmp = root.left
        root.left = root.right
        root.right = tmp
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root

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

def tree_to_list(root):
    if not root:
        return []
    result = []
    queue = [root]
    while any(queue):
        node = queue.pop(0)
        if node:
            result.append(node.val)
            queue.append(node.left)
            queue.append(node.right)
        else:
            result.append(None)
    while result and result[-1] is None:
        result.pop()
    return result

def is_same_tree(p, q):
    if not p and not q:
        return True
    if not p or not q or p.val != q.val:
        return False
    return is_same_tree(p.left, q.left) and is_same_tree(p.right, q.right)

# -------------------
# Test Cases
# -------------------
def test_invert_tree():
    s = Solution()
    # Test case 1: Example
    root = build_tree_from_list([4,2,7,1,3,6,9])
    expected = build_tree_from_list([4,7,2,9,6,3,1])
    assert is_same_tree(s.invertTree(root), expected)
    # Test case 2: Single node
    root = build_tree_from_list([1])
    expected = build_tree_from_list([1])
    assert is_same_tree(s.invertTree(root), expected)
    # Test case 3: Empty tree
    root = build_tree_from_list([])
    expected = build_tree_from_list([])
    assert is_same_tree(s.invertTree(root), expected)
    # Test case 4: Left-skewed tree
    root = build_tree_from_list([1,2,None,3])
    expected = build_tree_from_list([1,None,2,None,3])
    assert is_same_tree(s.invertTree(root), expected)
    print("All test cases passed!")

if __name__ == "__main__":
    test_invert_tree()
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        """
        Returns the diameter (longest path between any two nodes) of the binary tree.
        Approach:
        - Use DFS to compute the height of each subtree.
        - At each node, update the max diameter as left height + right height + 2 (number of edges).
        Time Complexity: O(n)
        Space Complexity: O(h) (h = height of tree)
        """
        res = [0]
        def dfs(root):
            if not root:
                return -1
            left = dfs(root.left)
            right = dfs(root.right)
            res[0] = max(2 + left + right, res[0])
            return 1 + max(left, right)
        dfs(root)
        return res[0]

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
def test_diameter_of_binary_tree():
    s = Solution()
    # Test case 1: Example
    root = build_tree_from_list([1,2,3,4,5])
    assert s.diameterOfBinaryTree(root) == 3
    # Test case 2: Single node
    root = build_tree_from_list([1])
    assert s.diameterOfBinaryTree(root) == 0
    # Test case 3: Empty tree
    root = build_tree_from_list([])
    assert s.diameterOfBinaryTree(root) == 0
    # Test case 4: Left-skewed tree
    root = build_tree_from_list([1,2,None,3,None,4,None])
    assert s.diameterOfBinaryTree(root) == 3
    # Test case 5: Right-skewed tree
    root = build_tree_from_list([1,None,2,None,3,None,4])
    assert s.diameterOfBinaryTree(root) == 3
    print("All test cases passed!")

if __name__ == "__main__":
    test_diameter_of_binary_tree()
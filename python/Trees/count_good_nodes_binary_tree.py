# type: ignore
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        """
        Counts the number of 'good' nodes in the binary tree.
        A node X is good if in the path from root to X there are no nodes with a value greater than X.
        Approach:
        - Use DFS, passing down the max value seen so far.
        - If current node >= max, it's a good node.
        Time Complexity: O(n)
        Space Complexity: O(h) (h = height of tree)
        """
        def dfs(node, maxVal):
            if not node:
                return 0
            res = 1 if node.val >= maxVal else 0
            maxVal = max(maxVal, node.val)
            res += dfs(node.left, maxVal)
            res += dfs(node.right, maxVal)
            return res
        return dfs(root, root.val)

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
def test_good_nodes():
    s = Solution()
    # Test case 1: Example
    root = build_tree_from_list([3,1,4,3,None,1,5])
    assert s.goodNodes(root) == 4  # type: ignore
    # Test case 2: All nodes same value
    root = build_tree_from_list([1,1,1,1,1,None,1])
    assert s.goodNodes(root) == 6  # type: ignore
    # Test case 3: Single node
    root = build_tree_from_list([0])
    assert s.goodNodes(root) == 1  # type: ignore
    # Test case 4: Increasing right-skewed
    root = build_tree_from_list([1,None,2,None,3,None,4])
    assert s.goodNodes(root) == 4  # type: ignore
    # Test case 5: Decreasing left-skewed
    root = build_tree_from_list([4,3,None,2,None,1])
    assert s.goodNodes(root) == 1  # type: ignore
    print("All test cases passed!")

if __name__ == "__main__":
    test_good_nodes()
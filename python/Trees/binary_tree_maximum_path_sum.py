from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        """
        Finds the maximum path sum in a binary tree. A path can start and end at any node,
        but must go downwards (traveling only from parent nodes to child nodes).
        Approach:
        - Use DFS to compute the maximum path sum for each node considering two cases:
          1. The path passes through the node and possibly both children (split path).
          2. The path continues from the node to one child (no split, for parent recursion).
        - At each node, update the global result with the maximum split path sum.
        - Return the maximum sum of a path starting from the current node and going down one side.

        Time Complexity: O(N), where N is the number of nodes (each node visited once).
        Space Complexity: O(H), where H is the height of the tree (recursion stack).
        """
        res = [root.val]  # type: ignore 

        # Return max path sum without split (for parent recursion)
        def dfs(root):
            if not root:
                return 0

            leftMax = dfs(root.left)
            rightMax = dfs(root.right)
            # Ignore negative paths (treat as 0)
            leftMax = max(leftMax, 0)
            rightMax = max(rightMax, 0)

            # Compute max path sum with split at current node
            res[0] = max(res[0], root.val + leftMax + rightMax)

            # Return max path sum without split (for parent recursion)
            return root.val + max(leftMax, rightMax)
        
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
def test_max_path_sum():
    s = Solution()
    # Test case 1: Example
    root = build_tree_from_list([1,2,3])
    assert s.maxPathSum(root) == 6
    # Test case 2: Negative values
    root = build_tree_from_list([-10,9,20,None,None,15,7])
    assert s.maxPathSum(root) == 42
    # Test case 3: Single node
    root = build_tree_from_list([2])
    assert s.maxPathSum(root) == 2
    # Test case 4: All negative
    root = build_tree_from_list([-3,-2,-1])
    assert s.maxPathSum(root) == -1
    # Test case 5: Mixed values
    root = build_tree_from_list([5,4,8,11,None,13,4,7,2,None,None,None,1])
    assert s.maxPathSum(root) == 48
    print("All test cases passed!")

if __name__ == "__main__":
    test_max_path_sum()
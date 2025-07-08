from typing import Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution2:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        """
        Find the maximum depth of a binary tree using BFS (level order traversal).
        Approach:
        - Use a queue to traverse the tree level by level.
        - Increment level counter for each level traversed.
        Time Complexity: O(n)
        Space Complexity: O(w) (w = max width of tree)
        """
        if not root:
            return 0
        level = 0
        q = deque([root])
        while q:
            for i in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            level += 1
        return level

class Solution3:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        """
        Find the maximum depth of a binary tree using iterative DFS approach.
        Strategy:
        1. Use a stack to simulate DFS traversal
        2. Keep track of current depth for each node
        3. Update maximum depth when reaching leaf nodes
        Time Complexity: O(n) where n is the number of nodes
        Space Complexity: O(h) where h is the height of the tree (O(n) in worst case for skewed tree)
        """
        if not root:
            return 0
        stack = [(root, 1)]
        res = 0
        while stack:
            node, depth = stack.pop()
            if node:
                res = max(res, depth)
                stack.append((node.right, depth + 1))  # type: ignore
                stack.append((node.left, depth + 1))   # type: ignore
        return res

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
def test_max_depth():
    s = Solution()
    # Test case 1: Example
    root = build_tree_from_list([3,9,20,None,None,15,7])
    assert s.maxDepth(root) == 3
    # Test case 2: Single node
    root = build_tree_from_list([1])
    assert s.maxDepth(root) == 1
    # Test case 3: Empty tree
    root = build_tree_from_list([])
    assert s.maxDepth(root) == 0
    # Test case 4: Left-skewed tree
    root = build_tree_from_list([1,2,None,3,None,4])
    assert s.maxDepth(root) == 4
    # Test case 5: Right-skewed tree
    root = build_tree_from_list([1,None,2,None,3,None,4])
    assert s.maxDepth(root) == 4
    print("All test cases passed!")

if __name__ == "__main__":
    test_max_depth()
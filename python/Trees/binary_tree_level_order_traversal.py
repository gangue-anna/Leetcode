from typing import Optional, List
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        """
        Return the level order traversal of a binary tree's nodes' values.
        Approach:
        - Use a queue to perform BFS, collecting values at each level.
        Time Complexity: O(n)
        Space Complexity: O(n)
        """
        res = []
        q = deque()
        q.append(root)
        while q:
            qLen = len(q)
            level = []
            for i in range(qLen):
                node = q.popleft()
                if node:
                    level.append(node.val)
                    q.append(node.left)
                    q.append(node.right)
            if level:
                res.append(level)
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
def test_level_order():
    s = Solution()
    # Test case 1: Example
    root = build_tree_from_list([3,9,20,None,None,15,7])
    assert s.levelOrder(root) == [[3],[9,20],[15,7]]
    # Test case 2: Single node
    root = build_tree_from_list([1])
    assert s.levelOrder(root) == [[1]]
    # Test case 3: Empty tree
    root = build_tree_from_list([])
    assert s.levelOrder(root) == []
    # Test case 4: Left-skewed tree
    root = build_tree_from_list([1,2,None,3,None,4,None])
    assert s.levelOrder(root) == [[1],[2],[3],[4]]
    # Test case 5: Right-skewed tree
    root = build_tree_from_list([1,None,2,None,3,None,4])
    assert s.levelOrder(root) == [[1],[2],[3],[4]]
    print("All test cases passed!")

if __name__ == "__main__":
    test_level_order()
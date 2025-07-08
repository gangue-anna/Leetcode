from typing import Optional, List
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        """
        Return the values of the nodes you can see from the right side (rightmost node at each level).
        Approach:
        - Use BFS (queue) to traverse the tree level by level.
        - At each level, record the last node seen (rightmost).
        Time Complexity: O(n)
        Space Complexity: O(n)
        """
        res = []
        q = deque([root])
        while q:
            rightSide = None
            qLen = len(q)
            for i in range(qLen):
                node = q.popleft()
                if node:
                    rightSide = node
                    q.append(node.left)
                    q.append(node.right)
            if rightSide:
                res.append(rightSide.val)
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
def test_right_side_view():
    s = Solution()
    # Test case 1: Example
    root = build_tree_from_list([1,2,3,None,5,None,4])
    assert s.rightSideView(root) == [1,3,4]
    # Test case 2: Single node
    root = build_tree_from_list([1])
    assert s.rightSideView(root) == [1]
    # Test case 3: Empty tree
    root = build_tree_from_list([])
    assert s.rightSideView(root) == []
    # Test case 4: Left-skewed tree
    root = build_tree_from_list([1,2,None,3,None,4,None])
    assert s.rightSideView(root) == [1,2,3,4]
    # Test case 5: Right-skewed tree
    root = build_tree_from_list([1,None,2,None,3,None,4])
    assert s.rightSideView(root) == [1,2,3,4]
    print("All test cases passed!")

if __name__ == "__main__":
    test_right_side_view()
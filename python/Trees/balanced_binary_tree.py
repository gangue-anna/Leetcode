from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        """
        Check if a binary tree is height-balanced.
        Approach:
        - Use DFS to check if left and right subtrees are balanced and their heights differ by at most 1.
        - Return [is_balanced, height] for each subtree.
        Time Complexity: O(n)
        Space Complexity: O(h) (h = height of tree, for recursion stack)
        """
        def dfs(root):
            if not root: return [True, 0]
            left, right = dfs(root.left), dfs(root.right)
            balanced  = (left[0] and right[0] and abs(left[1] - right[1]) <= 1)
            return [balanced, 1 + max(left[1], right[1])]
        return dfs(root)[0]

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
def test_is_balanced():
    s = Solution()
    # Test case 1: Balanced tree
    root = build_tree_from_list([3,9,20,None,None,15,7])
    assert s.isBalanced(root) == True
    # Test case 2: Unbalanced tree
    root = build_tree_from_list([1,2,2,3,3,None,None,4,4])
    assert s.isBalanced(root) == False
    # Test case 3: Empty tree
    root = build_tree_from_list([])
    assert s.isBalanced(root) == True
    # Test case 4: Single node
    root = build_tree_from_list([1])
    assert s.isBalanced(root) == True
    # Test case 5: Left-heavy tree
    root = build_tree_from_list([1,2,None,3,None,4,None])
    assert s.isBalanced(root) == False
    print("All test cases passed!")

if __name__ == "__main__":
    test_is_balanced()
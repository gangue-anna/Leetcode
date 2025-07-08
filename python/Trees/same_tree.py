from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        """
        Check if two binary trees are identical.
        Two binary trees are considered the same if they are structurally identical,
        and the nodes have the same value.
        
        Time Complexity: O(min(n,m)) where n and m are the number of nodes in trees p and q
        Space Complexity: O(min(h1,h2)) where h1 and h2 are the heights of trees p and q
        
        Args:
            p (Optional[TreeNode]): Root node of the first binary tree
            q (Optional[TreeNode]): Root node of the second binary tree
            
        Returns:
            bool: True if the trees are identical, False otherwise
        """
        # Base case: if both trees are empty, they are identical
        if not p and not q:
            return True
        # If one tree is empty and the other is not, they are not identical
        # Also check if current nodes have different values
        if not p or not q or p.val != q.val:
            return False
        # Recursively check if left and right subtrees are identical
        return (self.isSameTree(p.left, q.left) and 
                self.isSameTree(p.right, q.right))

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
def test_is_same_tree():
    s = Solution()
    # Test case 1: Identical trees
    p = build_tree_from_list([1,2,3])
    q = build_tree_from_list([1,2,3])
    assert s.isSameTree(p, q) == True
    # Test case 2: Different structure
    p = build_tree_from_list([1,2])
    q = build_tree_from_list([1,None,2])
    assert s.isSameTree(p, q) == False
    # Test case 3: Different values
    p = build_tree_from_list([1,2,1])
    q = build_tree_from_list([1,1,2])
    assert s.isSameTree(p, q) == False
    # Test case 4: Both empty
    p = build_tree_from_list([])
    q = build_tree_from_list([])
    assert s.isSameTree(p, q) == True
    # Test case 5: One empty, one not
    p = build_tree_from_list([1])
    q = build_tree_from_list([])
    assert s.isSameTree(p, q) == False
    print("All test cases passed!")

if __name__ == "__main__":
    test_is_same_tree()

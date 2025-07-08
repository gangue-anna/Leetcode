from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        """
        Check if subRoot is a subtree of root.
        A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants.
        The tree could also be considered as a subtree of itself.
        
        Time Complexity: O(m*n) where m and n are the number of nodes in root and subRoot
        Space Complexity: O(min(h1,h2)) where h1 and h2 are the heights of root and subRoot
        
        Args:
            root (Optional[TreeNode]): Root node of the main tree
            subRoot (Optional[TreeNode]): Root node of the potential subtree
            
        Returns:
            bool: True if subRoot is a subtree of root, False otherwise
        """
        # Base case: empty subtree is always a subtree of any tree
        if not subRoot:
            return True
        # Base case: if main tree is empty but subtree is not, return False
        if not root:
            return False
        # Check if current trees are identical
        if self.sameTree(root, subRoot):
            return True
        
        # Recursively check if subtree exists in left or right subtree of root
        return (self.isSubtree(root.left, subRoot) or
                self.isSubtree(root.right, subRoot))
        
    def sameTree(self, s: Optional[TreeNode], t: Optional[TreeNode]) -> bool:
        """
        Helper function to check if two trees are identical.
        
        Args:
            s (Optional[TreeNode]): Root node of first tree
            t (Optional[TreeNode]): Root node of second tree
            
        Returns:
            bool: True if trees are identical, False otherwise
        """
        # Base case: if both trees are empty, they are identical
        if not s and not t:
            return True
        
        # If both trees exist and have same value, check their subtrees
        if s and t and s.val == t.val:
            return (self.sameTree(s.left, t.left) and
                   self.sameTree(s.right, t.right))
        return False

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
def test_is_subtree():
    s = Solution()
    # Test case 1: Example
    root = build_tree_from_list([3,4,5,1,2])
    subRoot = build_tree_from_list([4,1,2])
    assert s.isSubtree(root, subRoot) == True
    # Test case 2: Not a subtree
    root = build_tree_from_list([1,2,3])
    subRoot = build_tree_from_list([2,3])
    assert s.isSubtree(root, subRoot) == False
    # Test case 3: Both empty
    root = build_tree_from_list([])
    subRoot = build_tree_from_list([])
    assert s.isSubtree(root, subRoot) == True
    # Test case 4: Subtree is empty
    root = build_tree_from_list([1,2,3])
    subRoot = build_tree_from_list([])
    assert s.isSubtree(root, subRoot) == True
    # Test case 5: Main tree is empty, subtree is not
    root = build_tree_from_list([])
    subRoot = build_tree_from_list([1])
    assert s.isSubtree(root, subRoot) == False
    print("All test cases passed!")

if __name__ == "__main__":
    test_is_subtree()
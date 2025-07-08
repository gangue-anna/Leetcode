from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        """
        Brute Force Approach:
        - For each node, check that all nodes in its left subtree are strictly less than the node's value,
          and all nodes in its right subtree are strictly greater than the node's value.
        - This is done by traversing the left and right subtrees for every node.
        - Time Complexity: O(N^2) in the worst case (for each node, traverse its subtrees).
        - Space Complexity: O(H) for recursion stack, where H is the height of the tree.
        """
        def check_left(node, val):
            if not node:
                return True
            if node.val >= val:
                return False
            return check_left(node.left, val) and check_left(node.right, val)

        def check_right(node, val):
            if not node:
                return True
            if node.val <= val:
                return False
            return check_right(node.left, val) and check_right(node.right, val)

        def is_bst(node):
            if not node:
                return True
            # Check all nodes in left subtree are < node.val
            if not check_left(node.left, node.val):
                return False
            # Check all nodes in right subtree are > node.val
            if not check_right(node.right, node.val):
                return False
            # Recursively check for left and right subtrees
            return is_bst(node.left) and is_bst(node.right)

        return is_bst(root)
        
class Solution2:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        """
        Efficient Approach (Bounds Checking):
        - For each node, ensure its value is strictly between the allowed lower (left) and upper (right) bounds.
        - Recursively check the left subtree with an updated upper bound (current node's value),
          and the right subtree with an updated lower bound (current node's value).
        - If any node violates the BST property, return False.
        - Time Complexity: O(N), where N is the number of nodes (each node is visited once).
        - Space Complexity: O(H), where H is the height of the tree (recursion stack).
        """
        def valid(node, left, right):
            if not node:
                return True
            # Node's value must be strictly between left and right bounds
            if not (left < node.val < right):
                return False
            # Recursively check left and right subtrees with updated bounds
            return (valid(node.left, left, node.val) and
                    valid(node.right, node.val, right))

        return valid(root, float('-inf'), float('inf'))

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
def test_is_valid_bst():
    s = Solution2()
    # Test case 1: Example
    root = build_tree_from_list([2,1,3])
    assert s.isValidBST(root) == True
    # Test case 2: Not a BST
    root = build_tree_from_list([5,1,4,None,None,3,6])
    assert s.isValidBST(root) == False
    # Test case 3: Single node
    root = build_tree_from_list([1])
    assert s.isValidBST(root) == True
    # Test case 4: Empty tree
    root = build_tree_from_list([])
    assert s.isValidBST(root) == True
    # Test case 5: Duplicates not allowed
    root = build_tree_from_list([2,2,2])
    assert s.isValidBST(root) == False
    # Test case 6: Valid BST with negative values
    root = build_tree_from_list([0,-1])
    assert s.isValidBST(root) == True
    print("All test cases passed!")

if __name__ == "__main__":
    test_is_valid_bst()
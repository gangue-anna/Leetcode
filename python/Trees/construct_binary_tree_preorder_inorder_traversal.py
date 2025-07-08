from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        """
        Reconstructs a binary tree from preorder and inorder traversal lists.
        Approach:
        - The first element of preorder is always the root.
        - Find the root in inorder to split left/right subtrees.
        - Recursively build left and right subtrees.
        Time Complexity: O(n^2) (due to list slicing and index search)
        Space Complexity: O(n) (call stack and tree nodes)
        """
        if not preorder or not inorder:
            return None
        root = TreeNode(preorder[0])
        mid = inorder.index(preorder[0])
        root.left = self.buildTree(preorder[1: mid + 1], inorder[:mid])
        root.right = self.buildTree(preorder[mid + 1:], inorder[mid + 1:])
        return root

# -------------------
# Helper Functions for Testing
# -------------------
def tree_to_list(root):
    # Level order traversal to list (None for missing nodes)
    if not root:
        return []
    result = []
    queue = [root]
    while any(queue):
        node = queue.pop(0)
        if node:
            result.append(node.val)
            queue.append(node.left)
            queue.append(node.right)
        else:
            result.append(None)
    # Remove trailing None values
    while result and result[-1] is None:
        result.pop()
    return result

def is_same_tree(p, q):
    if not p and not q:
        return True
    if not p or not q or p.val != q.val:
        return False
    return is_same_tree(p.left, q.left) and is_same_tree(p.right, q.right)

# -------------------
# Test Cases
# -------------------
def test_build_tree():
    s = Solution()
    # Test case 1: Example
    preorder = [3,9,20,15,7]
    inorder = [9,3,15,20,7]
    root = s.buildTree(preorder, inorder)
    assert tree_to_list(root) == [3,9,20,None,None,15,7]
    # Test case 2: Single node
    preorder = [1]
    inorder = [1]
    root = s.buildTree(preorder, inorder)
    assert tree_to_list(root) == [1]
    # Test case 3: Empty tree
    preorder = []
    inorder = []
    root = s.buildTree(preorder, inorder)
    assert tree_to_list(root) == []
    # Test case 4: Left-skewed tree
    preorder = [1,2,3]
    inorder = [3,2,1]
    root = s.buildTree(preorder, inorder)
    assert tree_to_list(root) == [1,2,None,3]
    # Test case 5: Right-skewed tree
    preorder = [1,2,3]
    inorder = [1,2,3]
    root = s.buildTree(preorder, inorder)
    assert tree_to_list(root) == [1,None,2,None,3]
    print("All test cases passed!")

if __name__ == "__main__":
    test_build_tree()
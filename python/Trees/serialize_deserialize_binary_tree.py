from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Codec:
    """
    Codec for serializing and deserializing a binary tree using preorder traversal.
    serialize: O(n) time, O(n) space
    deserialize: O(n) time, O(n) space
    """
    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:
        res = []
        def dfs(node):
            if not node:
                res.append("N")
                return
            res.append(str(node.val))
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        return ",".join(res)
    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        values = data.split(",")
        self.i = 0
        def dfs():
            if values[self.i] == "N":
                self.i += 1
                return None
            node = TreeNode(int(values[self.i]))
            self.i += 1
            node.left = dfs()
            node.right = dfs()
            return node
        return dfs()

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

def tree_to_list(root):
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
def test_serialize_deserialize():
    codec = Codec()
    # Test case 1: Example
    root = build_tree_from_list([1,2,3,None,None,4,5])
    data = codec.serialize(root)
    new_root = codec.deserialize(data)
    assert is_same_tree(root, new_root)
    # Test case 2: Single node
    root = build_tree_from_list([1])
    data = codec.serialize(root)
    new_root = codec.deserialize(data)
    assert is_same_tree(root, new_root)
    # Test case 3: Empty tree
    root = build_tree_from_list([])
    data = codec.serialize(root)
    new_root = codec.deserialize(data)
    assert is_same_tree(root, new_root)
    # Test case 4: Left-skewed tree
    root = build_tree_from_list([1,2,None,3])
    data = codec.serialize(root)
    new_root = codec.deserialize(data)
    assert is_same_tree(root, new_root)
    # Test case 5: Right-skewed tree
    root = build_tree_from_list([1,None,2,None,3])
    data = codec.serialize(root)
    new_root = codec.deserialize(data)
    assert is_same_tree(root, new_root)
    print("All test cases passed!")

if __name__ == "__main__":
    test_serialize_deserialize()
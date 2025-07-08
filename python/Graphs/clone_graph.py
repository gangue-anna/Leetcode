"""
Clone Graph (DFS)
Approach: Use DFS and a hashmap to clone each node and its neighbors recursively.
Time Complexity: O(N) where N is the number of nodes (each node and edge visited once).
Space Complexity: O(N) for the recursion stack and hashmap.
"""
from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        oldToNew = {}  # Maps original nodes to their clones
        
        def clone(node):
            if node in oldToNew:
                return oldToNew[node]  # Return already cloned node
            
            copy = Node(node.val)  # Clone the node
            oldToNew[node] = copy

            for nei in node.neighbors:
                copy.neighbors.append(clone(nei))  # Recursively clone neighbors
            return copy
        
        return clone(node) if node else None
    
# -------------------
# Test Cases
# -------------------
def test_clone_graph():
    # Helper to build a graph from adjacency list
    def build_graph(adj):
        if not adj:
            return None
        nodes = [Node(i+1) for i in range(len(adj))]
        for i, neighbors in enumerate(adj):
            nodes[i].neighbors = [nodes[j-1] for j in neighbors]
        return nodes[0]
    # Helper to serialize a graph to adjacency list
    def serialize(node):
        if not node:
            return []
        from collections import deque, defaultdict
        visited = set()
        adj = defaultdict(list)
        q = deque([node])
        while q:
            n = q.popleft()
            if n in visited:
                continue
            visited.add(n)
            for nei in n.neighbors:
                adj[n.val].append(nei.val)
                if nei not in visited:
                    q.append(nei)
        return [sorted(adj[i+1]) for i in range(len(adj))]
    sol = Solution()
    # Test case 1: Example graph
    adj1 = [[2,4],[1,3],[2,4],[1,3]]
    node1 = build_graph(adj1)
    clone1 = sol.cloneGraph(node1)
    assert serialize(clone1) == [sorted(x) for x in adj1]
    # Test case 2: Single node
    adj2 = [[]]
    node2 = build_graph(adj2)
    clone2 = sol.cloneGraph(node2)
    assert serialize(clone2) == [[]]
    # Test case 3: Empty graph
    node3 = build_graph([])
    clone3 = sol.cloneGraph(node3)
    assert clone3 is None
    print("All test cases passed!")

if __name__ == "__main__":
    test_clone_graph()
    
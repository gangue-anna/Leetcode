from typing import List

class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        """
        Approach:
        - Use DFS to check if the graph is a valid tree (connected and acyclic).
        - Build an adjacency list for the undirected graph.
        - Start DFS from node 0, marking nodes as visited.
        - If a node is revisited (other than its parent), a cycle exists.
        - After DFS, check if all nodes are visited (graph is connected).

        Time Complexity: O(V + E), where V is the number of nodes and E is the number of edges.
        Space Complexity: O(V + E), for the adjacency list and visited set.
        """
        if not n:
            return True
        adj = {i:[] for i in range (n)}
        for n1, n2 in edges:
            adj[n1].append(n2)
            adj[n2].append(n1)
        visit = set()
        def dfs(i, prev):
            if i in visit:
                return False
            visit.add(i)
            for j in adj[i]:
                if j == prev:
                    continue
                if not dfs(j, i): 
                    return False
            return True
        return dfs(0, -1) and n == len(visit)

# -------------------
# Test Cases
# -------------------
def test_valid_tree():
    sol = Solution()
    # Test case 1: Example from Leetcode
    n1 = 5
    edges1 = [[0,1],[0,2],[0,3],[1,4]]
    assert sol.validTree(n1, edges1) == True
    # Test case 2: Cycle exists
    n2 = 5
    edges2 = [[0,1],[1,2],[2,3],[1,3],[1,4]]
    assert sol.validTree(n2, edges2) == False
    # Test case 3: Disconnected graph
    n3 = 4
    edges3 = [[0,1],[2,3]]
    assert sol.validTree(n3, edges3) == False
    # Test case 4: Single node
    n4 = 1
    edges4 = []
    assert sol.validTree(n4, edges4) == True
    # Test case 5: No nodes
    n5 = 0
    edges5 = []
    assert sol.validTree(n5, edges5) == True
    print("All test cases passed!")

if __name__ == "__main__":
    test_valid_tree()
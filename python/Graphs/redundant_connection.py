from typing import List

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        """
        Approach:
        - Use Union-Find (Disjoint Set Union) to detect cycles in the graph.
        - For each edge, try to union the two nodes. If they are already connected, the edge is redundant.
        - Return the first redundant edge found.
        - Uses path compression and union by rank for efficiency.

        Time Complexity: O(E * α(N)), where E is the number of edges and α is the inverse Ackermann function (very slow-growing).
        Space Complexity: O(N), for the parent and rank arrays.
        """
        parent = [i for i in range(len(edges) + 1)]
        rank = [1] * (len(edges) + 1)

        def find(n):
            p = parent[n]

            while p != parent[p]:
                parent[p] = parent[parent[p]]
                p = parent[p]
            return p
        
        #return False if cant complete
        def union(n1, n2):
            p1, p2 = find(n1), find(n2)

            if p1 == p2:
                return False

            if rank[p1] > rank[p2]:
                parent[p2] = p1
                rank[p1] += rank[p2]
            else:
                parent[p1] = p2
                rank[p2] += rank[p1]
            return True

        for n1, n2 in edges:
            if not union(n1, n2):
                return [n1, n2]
        return []

# -------------------
# Test Cases
# -------------------
def test_find_redundant_connection():
    sol = Solution()
    # Test case 1: Example from Leetcode
    edges1 = [[1,2],[1,3],[2,3]]
    assert sol.findRedundantConnection(edges1) == [2,3]
    # Test case 2: Another cycle
    edges2 = [[1,2],[2,3],[3,4],[1,4],[1,5]]
    assert sol.findRedundantConnection(edges2) == [1,4]
    # Test case 3: No redundant edge (should not happen per constraints)
    edges3 = [[1,2],[2,3],[3,4]]
    assert sol.findRedundantConnection(edges3) == []
    # Test case 4: Single edge
    edges4 = [[1,2]]
    assert sol.findRedundantConnection(edges4) == []
    # Test case 5: Multiple cycles, return last one
    edges5 = [[1,2],[2,3],[3,1],[4,1],[4,5],[5,6],[6,4]]
    assert sol.findRedundantConnection(edges5) == [6,4]
    print("All test cases passed!")

if __name__ == "__main__":
    test_find_redundant_connection()
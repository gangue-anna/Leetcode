from typing import List

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        """
        Approach:
        - Use Union-Find (Disjoint Set Union) to count the number of connected components in an undirected graph.
        - For each edge, union the two nodes. If they are already connected, do nothing.
        - The result is decremented for each successful union (merging two components).
        - Uses path compression and union by rank for efficiency.

        Time Complexity: O(E * α(N)), where E is the number of edges and α is the inverse Ackermann function (very slow-growing).
        Space Complexity: O(N), for the parent and rank arrays.
        """
        par = [i for i in range(n)]
        rank = [1] * n

        def findRootParent(n1):
            res = n1

            while res != par[res]:
                par[res] = par[par[res]]
                res = par[res]
            return res

        def union(n1, n2):
            p1, p2 = findRootParent(n1), findRootParent(n2)

            if p1 == p2:
                return 0
            
            if rank[p2] > rank[p1]:
                par[p1] = p2
                rank[p2] += rank[p1]
            else:
                par[p2] = p1
                rank[p1] += rank[p2]
            return 1
        
        res = n
        for n1, n2 in edges:
            res -= union(n1, n2)
        return res

# -------------------
# Test Cases
# -------------------
def test_count_components():
    sol = Solution()
    # Test case 1: Example from Leetcode
    n1 = 5
    edges1 = [[0,1],[1,2],[3,4]]
    assert sol.countComponents(n1, edges1) == 2
    # Test case 2: All nodes connected
    n2 = 4
    edges2 = [[0,1],[1,2],[2,3]]
    assert sol.countComponents(n2, edges2) == 1
    # Test case 3: No edges
    n3 = 3
    edges3 = []
    assert sol.countComponents(n3, edges3) == 3
    # Test case 4: Disconnected pairs
    n4 = 6
    edges4 = [[0,1],[2,3],[4,5]]
    assert sol.countComponents(n4, edges4) == 3
    # Test case 5: Single node
    n5 = 1
    edges5 = []
    assert sol.countComponents(n5, edges5) == 1
    print("All test cases passed!")

if __name__ == "__main__":
    test_count_components()
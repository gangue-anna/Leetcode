from typing import List
from collections import defaultdict
import heapq

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        """
        Approach:
        - Build a directed weighted graph using an adjacency list.
        - Use Dijkstra's algorithm (min-heap/priority queue) to find the shortest time to reach all nodes from the source node k.
        - Track visited nodes to avoid revisiting.
        - The answer is the maximum time among all reachable nodes. If not all nodes are reachable, return -1.

        Time Complexity: O(E log N), where E is the number of edges and N is the number of nodes (due to heap operations).
        Space Complexity: O(N + E), for the adjacency list, heap, and visited set.
        """
        edges = defaultdict(list)
        for u, v, w in times:
            edges[u].append((v, w))
        minHeap = [(0, k)]  # (current_time, node)
        visit = set()
        t = 0
        while minHeap:
            w1, n1 = heapq.heappop(minHeap)
            if n1 in visit:
                continue
            visit.add(n1)
            t = max(t, w1)
            for n2, w2 in edges[n1]:
                if n2 not in visit:
                    heapq.heappush(minHeap, (w1 + w2, n2))
        return t if len(visit) == n else -1

# -------------------
# Test Cases
# -------------------
def test_networkDelayTime():
    s = Solution()
    # Test case 1: Example from Leetcode
    times1 = [[2,1,1],[2,3,1],[3,4,1]]
    assert s.networkDelayTime(times1, 4, 2) == 2

    # Test case 2: Not all nodes reachable
    times2 = [[1,2,1]]
    assert s.networkDelayTime(times2, 2, 1) == 1
    assert s.networkDelayTime(times2, 2, 2) == -1

    # Test case 3: Single node
    times3 = []
    assert s.networkDelayTime(times3, 1, 1) == 0

    # Test case 4: Cycle in the graph
    times4 = [[1,2,1],[2,3,2],[3,1,4]]
    assert s.networkDelayTime(times4, 3, 1) == 3

    print("All test cases passed!")

if __name__ == "__main__":
    test_networkDelayTime()

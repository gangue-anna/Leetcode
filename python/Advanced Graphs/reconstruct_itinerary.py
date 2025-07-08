from typing import List

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        """
        Approach:
        - Build an adjacency list (graph) where each airport points to a list of its destinations.
        - Sort each list of destinations in lexical order so we always choose the smallest lexical option first.
        - Use backtracking (DFS) to construct the itinerary, always choosing the next lexical destination.
        - Remove the destination from the adjacency list as we use it, and backtrack if needed.
        - The itinerary must use all tickets exactly once and start from 'JFK'.

        Time Complexity: O(E^2), where E is the number of tickets (edges). Each edge is visited once, but insertion and removal in the list can take O(E) in the worst case.
        Space Complexity: O(E), for the adjacency list and recursion stack.
        """
        # 1. Initialize adjacency list for all airports (including destinations)
        adj = {}
        for src, dst in tickets:
            if src not in adj:
                adj[src] = []
            if dst not in adj:  # Add this to handle destinations
                adj[dst] = []
            adj[src].append(dst)

        # 2. Sort destinations for lexical order
        for src in adj:
            adj[src].sort()

        res = ["JFK"]
        def dfs(src):
            if len(res) == len(tickets) + 1:
                return True
            if src not in adj:
                return False
            
            # 3. Create a copy of current destinations
            temp = adj[src][:]  # Make a copy instead of reference
            
            for i, v in enumerate(temp):
                # 4. Check if the destination is still available
                if v not in adj[src]: 
                    continue
                    
                # 5. Remove the destination correctly
                adj[src].remove(v)
                res.append(v)

                if dfs(v): 
                    return True

                # 6. Backtrack correctly
                adj[src].insert(i, v)
                res.pop()
                
            return False
        
        dfs("JFK")
        return res

# -------------------
# Test Cases
# -------------------
def test_findItinerary():
    s = Solution()
    # Test case 1: Example from Leetcode
    tickets1 = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
    assert s.findItinerary(tickets1) == ["JFK","MUC","LHR","SFO","SJC"]

    # Test case 2: Multiple valid itineraries, must pick lexical order
    tickets2 = [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
    assert s.findItinerary(tickets2) == ["JFK","NRT","JFK","KUL"]

    # Test case 3: Single ticket
    tickets3 = [["JFK","ATL"]]
    assert s.findItinerary(tickets3) == ["JFK","ATL"]

    # Test case 4: Disconnected graph (should not happen per problem constraints)
    tickets4 = [["JFK","ATL"],["SFO","LAX"]]
    # Should return a partial path starting from JFK
    result = s.findItinerary(tickets4)
    assert result[0] == "JFK" and "ATL" in result

    print("All test cases passed!")

if __name__ == "__main__":
    test_findItinerary()
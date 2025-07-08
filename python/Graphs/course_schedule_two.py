from typing import List

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        """
        Approach:
        - Build an adjacency list for prerequisites.
        - Use DFS to perform topological sort and detect cycles.
        - Each course can be in one of three states: unvisited, visiting (in current path), or visited (added to output).
        - If a cycle is detected, return an empty list.
        - Otherwise, return the order in which courses can be taken.

        Time Complexity: O(V + E), where V is the number of courses and E is the number of prerequisites.
        Space Complexity: O(V + E), for the graph and recursion stack.
        """
        #build adjacency list for prerequisites
        prereq = {c:[] for c in range(numCourses)}
        for crs, pre in prerequisites:
            prereq[crs].append(pre)

        # A course has 3 possible states

        # visited -> crs has been added to output
        # visiting -> crs not added to output, but added to cycle
        # unvisited -> crs not added to output or cycle

        output = []
        visit, cycle = set(), set()
        def dfs(crs):
            if crs in cycle:
                return False
            if crs in visit:
                return True
            
            cycle.add(crs)
            for pre in prereq[crs]:
                if dfs(pre) == False: 
                    return False
            cycle.remove(crs)
            visit.add(crs)
            output.append(crs)
            return True
        
        for c in range(numCourses):
            if dfs(c) == False:
                return []
        return output

# -------------------
# Test Cases
# -------------------
def test_find_order():
    sol = Solution()
    # Test case 1: Example from Leetcode
    numCourses1 = 2
    prerequisites1 = [[1,0]]
    result1 = sol.findOrder(numCourses1, prerequisites1)
    assert result1 == [0,1] or result1 == [1,0]  # Both are valid
    # Test case 2: Cycle exists
    numCourses2 = 2
    prerequisites2 = [[1,0],[0,1]]
    assert sol.findOrder(numCourses2, prerequisites2) == []
    # Test case 3: No prerequisites
    numCourses3 = 3
    prerequisites3 = []
    result3 = sol.findOrder(numCourses3, prerequisites3)
    assert sorted(result3) == [0,1,2]
    # Test case 4: Multiple courses, no cycle
    numCourses4 = 4
    prerequisites4 = [[1,0],[2,1],[3,2]]
    result4 = sol.findOrder(numCourses4, prerequisites4)
    assert result4 == [0,1,2,3]
    # Test case 5: Multiple valid orders
    numCourses5 = 4
    prerequisites5 = [[1,0],[2,0],[3,1],[3,2]]
    result5 = sol.findOrder(numCourses5, prerequisites5)
    assert result5[0] == 0 and set(result5) == {0,1,2,3}
    print("All test cases passed!")

if __name__ == "__main__":
    test_find_order()

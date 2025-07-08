from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        """
        Approach:
        - Build a graph (adjacency list) where each course points to its prerequisites.
        - Use DFS to detect cycles: if a course is revisited in the current path, a cycle exists.
        - Mark courses as completed by emptying their prereq list after visiting.
        - If all courses can be completed without cycles, return True.

        Time Complexity: O(V + E), where V is the number of courses and E is the number of prerequisites.
        Space Complexity: O(V + E), for the graph and recursion stack.
        """
        preMap = {i :[] for i in range(numCourses)}
        # map each course to prereq list
        for crs, pre in prerequisites:
            preMap[crs].append(pre)
        # visitSet = all courses along the current DFS path
        visitSet = set()
        def dfs(crs):
            if crs in visitSet:
                return False
            if preMap[crs] == []:
                return True
            visitSet.add(crs)
            for pre in preMap[crs]:
                if not dfs(pre): return False
            visitSet.remove(crs)
            preMap[crs] = []
            return True
        for crs in range(numCourses):
            if not dfs(crs): return False
        return True

# -------------------
# Test Cases
# -------------------
def test_can_finish():
    sol = Solution()
    # Test case 1: Example from Leetcode
    numCourses1 = 2
    prerequisites1 = [[1,0]]
    assert sol.canFinish(numCourses1, prerequisites1) == True
    # Test case 2: Cycle exists
    numCourses2 = 2
    prerequisites2 = [[1,0],[0,1]]
    assert sol.canFinish(numCourses2, prerequisites2) == False
    # Test case 3: No prerequisites
    numCourses3 = 3
    prerequisites3 = []
    assert sol.canFinish(numCourses3, prerequisites3) == True
    # Test case 4: Multiple courses, no cycle
    numCourses4 = 4
    prerequisites4 = [[1,0],[2,1],[3,2]]
    assert sol.canFinish(numCourses4, prerequisites4) == True
    # Test case 5: Multiple courses, with cycle
    numCourses5 = 3
    prerequisites5 = [[0,1],[1,2],[2,0]]
    assert sol.canFinish(numCourses5, prerequisites5) == False
    print("All test cases passed!")

if __name__ == "__main__":
    test_can_finish()


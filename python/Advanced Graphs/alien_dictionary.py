from typing import List

class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        """
        Given a list of words sorted lexicographically in an alien language, return a string of the unique characters in the correct order.
        If the order is invalid (cycle or prefix issue), return an empty string.

        Approach:
        1. Build a graph (adjacency list) where each node is a character, and edges represent precedence (w1[j] < w2[j]).
        2. For each adjacent pair of words, find the first differing character and add an edge.
        3. Detect invalid prefix case (e.g., ["abc", "ab"]).
        4. Perform DFS-based topological sort to determine character order.
        5. Detect cycles (invalid order) during DFS.

        Time Complexity: O(N + K)
            - N = total number of characters in all words
            - K = number of unique characters (nodes in graph)
            - Building the graph: O(N)
            - DFS/topological sort: O(K + E), E = number of edges (<= K^2)
        Space Complexity: O(K + E)
            - For adjacency list, visit dict, and recursion stack
        """
        # Special case: single word, return unique characters in order of appearance
        if len(words) == 1:
            return "".join(dict.fromkeys(words[0]))

        adj = {c : set() for w in words for c in w}  # Build graph nodes for all unique characters

        # Build edges based on the first differing character between adjacent words
        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i + 1]
            minLen = min(len(w1), len(w2))
            # Invalid case: prefix order (e.g., "abc" before "ab")
            if len(w1) > len(w2) and w1[: minLen] == w2[: minLen]:
                return ""
            for j in range(minLen):
                if w1[j] != w2[j]:
                    adj[w1[j]].add(w2[j])  # w1[j] comes before w2[j]
                    break

        visit = {} # False = visited, True = current path (for cycle detection)
        res = []   # Stores the topological order
        
        def dfs(c):
            if c in visit:
                return visit[c]  # True if cycle detected
            
            visit[c] = True  # Mark as visiting (current path)

            for nei in adj[c]:
                if dfs(nei):  # If cycle detected in neighbor
                    return True

            visit[c] = False  # Mark as visited (no cycle in this path)
            res.append(c)     # Add to result in postorder (topological sort)

        # Run DFS for all nodes
        for c in adj:
            if dfs(c):  # If cycle detected
                return ""
        res.reverse()  # Reverse to get correct order
        return "".join(res)


def test_foreign_dictionary():
    solution = Solution()
    # Test case 1: Simple order
    words1 = ["wrt", "wrf", "er", "ett", "rftt"]
    expected1 = "wertf"
    result1 = solution.foreignDictionary(words1)
    print(f"Test 1: {result1 == expected1}, Expected: {expected1}, Got: {result1}")

    # Test case 2: Cycle (invalid order)
    words2 = ["z", "x", "z"]
    expected2 = ""
    result2 = solution.foreignDictionary(words2)
    print(f"Test 2: {result2 == expected2}, Expected: {expected2}, Got: {result2}")

    # Test case 3: Prefix invalid
    words3 = ["abc", "ab"]
    expected3 = ""
    result3 = solution.foreignDictionary(words3)
    print(f"Test 3: {result3 == expected3}, Expected: {expected3}, Got: {result3}")

    # Test case 4: Single word
    words4 = ["abc"]
    expected4 = "abc"
    result4 = solution.foreignDictionary(words4)
    print(f"Test 4: {result4 == expected4}, Expected: {expected4}, Got: {result4}")

    # Test case 5: All characters same
    words5 = ["aaa", "aaa"]
    expected5 = "a"
    result5 = solution.foreignDictionary(words5)
    print(f"Test 5: {result5 == expected5}, Expected: {expected5}, Got: {result5}")

if __name__ == "__main__":
    test_foreign_dictionary()


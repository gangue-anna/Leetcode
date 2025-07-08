from typing import List
from collections import defaultdict
from collections import deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        """
        Approach:
        - Use BFS to find the shortest transformation sequence from beginWord to endWord.
        - Preprocess the word list to create a mapping from generic patterns (with one letter replaced by *) to words.
        - For each word, try all possible one-letter transformations and enqueue valid ones.
        - Return the length of the shortest path if found, otherwise 0.

        Time Complexity: O(N * M^2), where N is the number of words and M is the length of each word.
        Space Complexity: O(N * M), for the pattern mapping and visited set.
        """
        if endWord not in wordList:
            return 0
        nei = defaultdict(list)
        wordList.append(beginWord)
        for word in wordList:
            for j in range(len(word)):
                pattern = word[: j] + "*" + word[j + 1: ]
                nei[pattern].append(word)
        visit = set([beginWord])
        q = deque([beginWord])
        res = 1
        while q:
            for i in range(len(q)):
                word = q.popleft()
                if word == endWord:
                    return res
                for j in range(len(word)):
                    pattern = word[: j] + "*" + word[j + 1: ]
                    for neiWord in nei[pattern]:
                        if neiWord not in visit:
                            visit.add(neiWord)
                            q.append(neiWord)
            res += 1
        return 0

# -------------------
# Test Cases
# -------------------
def test_ladder_length():
    sol = Solution()
    # Test case 1: Example from Leetcode
    beginWord1 = "hit"
    endWord1 = "cog"
    wordList1 = ["hot","dot","dog","lot","log","cog"]
    assert sol.ladderLength(beginWord1, endWord1, wordList1) == 5
    # Test case 2: No possible transformation
    beginWord2 = "hit"
    endWord2 = "cog"
    wordList2 = ["hot","dot","dog","lot","log"]
    assert sol.ladderLength(beginWord2, endWord2, wordList2) == 0
    # Test case 3: Single letter transformation
    beginWord3 = "a"
    endWord3 = "c"
    wordList3 = ["a","b","c"]
    assert sol.ladderLength(beginWord3, endWord3, wordList3) == 2
    # Test case 4: beginWord == endWord
    beginWord4 = "same"
    endWord4 = "same"
    wordList4 = ["same"]
    assert sol.ladderLength(beginWord4, endWord4, wordList4) == 1
    # Test case 5: Empty word list
    beginWord5 = "a"
    endWord5 = "b"
    wordList5 = []
    assert sol.ladderLength(beginWord5, endWord5, wordList5) == 0
    print("All test cases passed!")

if __name__ == "__main__":
    test_ladder_length()
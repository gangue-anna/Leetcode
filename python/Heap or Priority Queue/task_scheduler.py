from typing import List
from collections import Counter, deque
import heapq

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        """
        Find the least number of units of times that the CPU will take to finish all the given tasks with cooldown n.
        Approach:
        - Use a max-heap to always schedule the most frequent task available.
        - Use a queue to keep track of tasks in cooldown (with their next available time).
        - At each time unit, either schedule a task or idle.
        - When a task's cooldown is over, push it back to the heap if it still has remaining count.
        Time Complexity: O(N), where N is the number of tasks
        Space Complexity: O(1) (since there are at most 26 tasks)
        """
        count = Counter(tasks)
        maxHeap = [-cnt for cnt in count.values()]
        heapq.heapify(maxHeap)

        time = 0
        q = deque() #pairs of [cnt, idleTime]
        
        while maxHeap or q:
            time += 1

            if maxHeap:
                cnt = 1 + heapq.heappop(maxHeap)
                if cnt:
                    q.append([cnt, time + n])

            if q and q[0][1] == time:
                heapq.heappush(maxHeap, q.popleft()[0])
        return time

# -------------------
# Test Cases
# -------------------
def test_task_scheduler():
    s = Solution()
    # Test case 1: Example
    tasks = ["A","A","A","B","B","B"]
    n = 2
    assert s.leastInterval(tasks, n) == 8  # A B idle A B idle A B
    # Test case 2: No cooldown
    tasks = ["A","A","A","B","B","B"]
    n = 0
    assert s.leastInterval(tasks, n) == 6
    # Test case 3: All unique tasks
    tasks = ["A","B","C","D"]
    n = 2
    assert s.leastInterval(tasks, n) == 4
    # Test case 4: Single task
    tasks = ["A","A","A","A"]
    n = 3
    assert s.leastInterval(tasks, n) == 13
    # Test case 5: Empty task list
    tasks = []
    n = 2
    assert s.leastInterval(tasks, n) == 0
    print("All test cases passed!")

if __name__ == "__main__":
    test_task_scheduler()
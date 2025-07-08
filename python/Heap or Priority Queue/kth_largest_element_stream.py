from typing import List
import heapq

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        """
        Initialize the KthLargest class with a stream of numbers.
        Approach:
        - Maintain a min-heap of size k containing the k largest elements seen so far.
        - Heapify the initial list and pop the smallest until only k elements remain.
        Time Complexity: O(n log k) for init, O(log k) per add
        Space Complexity: O(k)
        """
        #MinHeap with K largest integers
        self.minHeap, self.k = nums, k
        heapq.heapify(self.minHeap)

        while len(self.minHeap) > k:
            heapq.heappop(self.minHeap)

    def add(self, val: int) -> int:
        """
        Add a new value to the stream and return the kth largest element.
        Time Complexity: O(log k)
        Space Complexity: O(k)
        """
        heapq.heappush(self.minHeap, val)
        
        if len(self.minHeap) > self. k:
            heapq.heappop(self.minHeap)
        return self.minHeap[0]

# -------------------
# Test Cases
# -------------------
def test_kth_largest_stream():
    # Test case 1: Basic
    kth = KthLargest(3, [4,5,8,2])
    assert kth.add(3) == 4  # [4,5,8], 2,3 dropped
    assert kth.add(5) == 5  # [5,5,8]
    assert kth.add(10) == 5 # [5,8,10]
    assert kth.add(9) == 8  # [8,9,10]
    assert kth.add(4) == 8  # [8,9,10]
    # Test case 2: k = 1
    kth2 = KthLargest(1, [])
    assert kth2.add(-3) == -3
    assert kth2.add(-2) == -2
    assert kth2.add(-4) == -2
    assert kth2.add(0) == 0
    assert kth2.add(4) == 4
    # Test case 3: All elements same
    kth3 = KthLargest(2, [2,2,2])
    assert kth3.add(2) == 2
    assert kth3.add(2) == 2
    # Test case 4: Negative numbers
    kth4 = KthLargest(2, [-1,-2,-3])
    assert kth4.add(-4) == -2
    assert kth4.add(0) == -1
    print("All test cases passed!")

if __name__ == "__main__":
    test_kth_largest_stream()
import heapq

class MedianFinder:
    def __init__(self):
        # Max-heap for the smaller half (invert values for heapq)
        self.small = []
        # Min-heap for the larger half
        self.large = []

    def addNum(self, num: int) -> None:
        """
        Adds a number into the data structure.
        Approach:
        - Use two heaps:
          - self.small: Max-heap (as min-heap with negative values) for the smaller half
          - self.large: Min-heap for the larger half
        - Always push to self.small first, then balance heaps so:
          - All elements in self.small <= all elements in self.large
          - The size difference between heaps is at most 1
        Time Complexity: O(log n) per insertion (heap push/pop)
        Space Complexity: O(n) for storing all numbers
        """
        # Push to max-heap (invert value for heapq)
        heapq.heappush(self.small, -num)

        # Ensure every element in self.small <= every element in self.large
        if self.small and self.large and (-self.small[0] > self.large[0]):
            val = -heapq.heappop(self.small)
            heapq.heappush(self.large, val)
        
        # Balance the sizes (small can have at most 1 more than large)
        if len(self.small) > len(self.large) + 1:
            val = -heapq.heappop(self.small)
            heapq.heappush(self.large, val)
        if len(self.large) > len(self.small) + 1:
            val = heapq.heappop(self.large)
            heapq.heappush(self.small, -val)

    def findMedian(self) -> float:
        """
        Returns the median of all elements so far.
        Time Complexity: O(1)
        Space Complexity: O(1) (not counting the data stored)
        """
        if len(self.small) > len(self.large):
            return -self.small[0]
        if len(self.large) > len(self.small):
            return self.large[0]
        # If even number of elements, median is the average of the two middle values
        return ((-self.small[0]) + self.large[0]) / 2

# -------------------
# Test Cases
# -------------------
def test_median_finder():
    mf = MedianFinder()
    # Test case 1: Add numbers and check median
    mf.addNum(1)
    assert mf.findMedian() == 1
    mf.addNum(2)
    assert mf.findMedian() == 1.5
    mf.addNum(3)
    assert mf.findMedian() == 2
    # Test case 2: Add more numbers
    mf2 = MedianFinder()
    nums2 = [5, 15, 1, 3]
    expected2 = [5, 10.0, 5, 4.0]
    for i, num in enumerate(nums2):
        mf2.addNum(num)
        assert mf2.findMedian() == expected2[i]
    # Test case 3: All same number
    mf3 = MedianFinder()
    for _ in range(5):
        mf3.addNum(7)
    assert mf3.findMedian() == 7
    # Test case 4: Negative numbers
    mf4 = MedianFinder()
    mf4.addNum(-1)
    mf4.addNum(-2)
    mf4.addNum(-3)
    assert mf4.findMedian() == -2
    # Test case 5: Single element
    mf5 = MedianFinder()
    mf5.addNum(42)
    assert mf5.findMedian() == 42
    print("All test cases passed!")

if __name__ == "__main__":
    test_median_finder()
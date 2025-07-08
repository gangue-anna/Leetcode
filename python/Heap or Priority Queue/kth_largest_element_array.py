from typing import List
import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        """
        Finds the kth largest element in an array using a min-heap of size k.
        
        Approach:
        - Maintain a min-heap of size k.
        - Iterate through the array, pushing each element onto the heap.
        - If the heap exceeds size k, pop the smallest element.
        - The root of the heap is the kth largest element.

        Time Complexity: O(n log k)
        Space Complexity: O(k)
        """
        min_heap = []
        for num in nums:
            heapq.heappush(min_heap, num)
            if len(min_heap) > k:
                heapq.heappop(min_heap)
        return min_heap[0]
        
class Solution2:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        """
        Finds the kth largest element using the Quickselect algorithm (in-place).
        
        Approach:
        - Convert kth largest to (n-k)th smallest.
        - Use partitioning (like quicksort) to find the kth position.
        - Recursively partition until the pivot is at the kth position.

        Time Complexity: O(n) average, O(n^2) worst case
        Space Complexity: O(1) (in-place)
        """
        k = len(nums) - k

        def quickSelect(l, r):
            pivot, p = nums[r], l
            for i in range(l, r):
                if nums[i] <= pivot:
                    nums[p], nums[i] = nums[i], nums[p]
                    p += 1
            nums[p], nums[r] = pivot, nums[p]

            if p > k: return quickSelect(l, p - 1)
            elif p < k: return quickSelect(p + 1, r)
            else: return nums[p]

        return quickSelect(0, len(nums) - 1)

# -------------------
# Test Cases
# -------------------
def test_kth_largest():
    s1 = Solution()
    s2 = Solution2()
    # Test case 1: Basic
    nums = [3,2,1,5,6,4]
    k = 2
    expected = 5
    assert s1.findKthLargest(nums[:], k) == expected
    assert s2.findKthLargest(nums[:], k) == expected
    # Test case 2: k = 1 (largest)
    nums = [3,2,3,1,2,4,5,5,6]
    k = 1
    expected = 6
    assert s1.findKthLargest(nums[:], k) == expected
    assert s2.findKthLargest(nums[:], k) == expected
    # Test case 3: All elements same
    nums = [2,2,2,2]
    k = 3
    expected = 2
    assert s1.findKthLargest(nums[:], k) == expected
    assert s2.findKthLargest(nums[:], k) == expected
    # Test case 4: Negative numbers
    nums = [-1,-2,-3,-4,-5]
    k = 2
    expected = -2
    assert s1.findKthLargest(nums[:], k) == expected
    assert s2.findKthLargest(nums[:], k) == expected
    # Test case 5: Single element
    nums = [42]
    k = 1
    expected = 42
    assert s1.findKthLargest(nums[:], k) == expected
    assert s2.findKthLargest(nums[:], k) == expected
    print("All test cases passed!")

if __name__ == "__main__":
    test_kth_largest()
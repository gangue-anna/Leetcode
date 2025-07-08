from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k : int) -> List[int]:
        """
        Approach:
        - Count the frequency of each element using a dictionary.
        - Sort the items of the dictionary by frequency in descending order.
        - Return the first k elements from the sorted list.

        Time Complexity: O(n log n), where n is the number of elements in nums (due to sorting).
        Space Complexity: O(n), for the frequency dictionary and the output list.
        """
        freq = {}
        for i in nums:
            if i in freq:
                freq[i] += 1
            else:
                freq[i] = 1
        sorted_items = sorted(freq.items(), key=lambda x: x[1], reverse=True)
        return [item[0] for item in sorted_items[:k]]

# -------------------
# Test Cases
# -------------------
def test_top_k_frequent_elements():
    sol = Solution()
    # Test case 1: Example from Leetcode
    nums1 = [1,1,1,2,2,3]
    assert set(sol.topKFrequent(nums1, 2)) == {1,2}
    # Test case 2: All unique
    nums2 = [1,2,3,4]
    assert set(sol.topKFrequent(nums2, 2)) == {1,2,3,4} - set(sol.topKFrequent(nums2, 2)) == set()
    # Test case 3: k = 1
    nums3 = [4,4,4,6,6,7]
    assert sol.topKFrequent(nums3, 1) == [4]
    # Test case 4: k equals number of unique elements
    nums4 = [5,6,7,8]
    assert set(sol.topKFrequent(nums4, 4)) == {5,6,7,8}
    # Test case 5: Single element
    nums5 = [42]
    assert sol.topKFrequent(nums5, 1) == [42]
    print("All test cases passed!")

if __name__ == "__main__":
    test_top_k_frequent_elements()

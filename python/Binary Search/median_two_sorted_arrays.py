from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        """
        Approach:
        - Use binary search on the shorter array to find the correct partition between the two arrays.
        - The partition divides both arrays into left and right halves such that all elements on the left are less than or equal to all elements on the right.
        - The median is then determined by the max of the left elements and the min of the right elements, depending on the total length (odd/even).
        - Handles edge cases using infinity for out-of-bounds indices.

        Time Complexity: O(log(min(n, m))) where n, m are lengths of the arrays.
        Space Complexity: O(1).
        """
        # Make A the shorter array for efficiency
        A, B = nums1, nums2
        total = len(nums1) + len(nums2)
        half = total // 2
        if len(B) < len(A):
            A, B = B, A
        l, r = 0, len(A) - 1
        while True:
            # Calculate partition points
            i = (l + r) // 2  # Partition point in A
            j = half - i - 2  # Partition point in B
            # Get elements around partition points
            # Use infinity for out of bounds
            Aleft = A[i] if i >= 0 else float("-infinity")
            Aright = A[i + 1] if (i + 1) < len(A) else float("infinity")
            Bleft = B[j] if j >= 0 else float("-infinity")
            Bright = B[j + 1] if (j + 1) < len(B) else float("infinity")
            # Check if partition is correct
            if Aleft <= Bright and Bleft <= Aright:
                # For odd length, return min of right elements
                if total % 2:
                    return min(Aright, Bright)
                # For even length, return average of max of left and min of right
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2
            # If A's left is greater than B's right, move partition left in A
            elif Aleft > Bright:
                r = i - 1
            # If B's left is greater than A's right, move partition right in A
            else:
                l = i + 1

# -------------------
# Test Cases
# -------------------
def test_find_median_sorted_arrays():
    sol = Solution()
    # Test case 1: Example from Leetcode
    nums1 = [1,3]
    nums2 = [2]
    assert sol.findMedianSortedArrays(nums1, nums2) == 2.0
    # Test case 2: Even total length
    nums3 = [1,2]
    nums4 = [3,4]
    assert sol.findMedianSortedArrays(nums3, nums4) == 2.5
    # Test case 3: One array empty
    nums5 = []
    nums6 = [1]
    assert sol.findMedianSortedArrays(nums5, nums6) == 1.0
    # Test case 4: Both arrays single element
    nums7 = [2]
    nums8 = [1]
    assert sol.findMedianSortedArrays(nums7, nums8) == 1.5
    # Test case 5: Arrays with duplicates
    nums9 = [1,2,2]
    nums10 = [2,2,3]
    assert sol.findMedianSortedArrays(nums9, nums10) == 2.0
    print("All test cases passed!")

if __name__ == "__main__":
    test_find_median_sorted_arrays()
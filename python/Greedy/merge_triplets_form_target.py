from typing import List

class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        """
        Determine if we can form the target triplet by merging some of the given triplets.
        
        Approach:
        - For each triplet, check if any of its values exceed the target values.
        - If a triplet has any value greater than the target, skip it (it can't be used).
        - For valid triplets, check if any of their values match the target values exactly.
        - Keep track of which target positions (0, 1, 2) we can achieve.
        - If we can achieve all three target positions, return True.
        
        Time Complexity: O(N), where N is the number of triplets
        - We iterate through each triplet once
        
        Space Complexity: O(1)
        - The set 'good' stores at most 3 elements
        
        Args:
            triplets: List[List[int]] - List of triplets [a, b, c]
            target: List[int] - Target triplet [x, y, z]
        Returns:
            bool - True if target can be formed by merging triplets, False otherwise
        """
        good = set()

        for t in triplets:
            # Skip triplets that have any value greater than the target
            if t[0] > target[0] or t[1] > target[1] or t[2] > target[2]:
                continue

            # Check if any value in this triplet matches the target exactly
            for i, v in enumerate(t):
                if v == target[i]:
                    good.add(i)
        
        # Return True if we can achieve all three target positions
        return len(good) == 3

# -------------------
# Test Cases
# -------------------
def test_merge_triplets():
    s = Solution()
    # Test case 1: Can form target
    assert s.mergeTriplets([[2,5,3],[1,8,4],[1,7,5]], [2,7,5]) == True, "Failed on [[2,5,3],[1,8,4],[1,7,5]], [2,7,5]"
    # Test case 2: Cannot form target
    assert s.mergeTriplets([[3,4,5],[4,5,6]], [3,2,5]) == False, "Failed on [[3,4,5],[4,5,6]], [3,2,5]"
    # Test case 3: Single triplet matches target
    assert s.mergeTriplets([[1,2,3]], [1,2,3]) == True, "Failed on [[1,2,3]], [1,2,3]"
    # Test case 4: No valid triplets
    assert s.mergeTriplets([[2,2,2],[3,3,3]], [1,1,1]) == False, "Failed on [[2,2,2],[3,3,3]], [1,1,1]"
    # Test case 5: All triplets exceed target
    assert s.mergeTriplets([[4,5,6],[7,8,9]], [1,2,3]) == False, "Failed on [[4,5,6],[7,8,9]], [1,2,3]"
    # Test case 6: Multiple valid triplets
    assert s.mergeTriplets([[1,2,3],[4,2,6],[7,8,3]], [4,8,6]) == False, "Failed on [[1,2,3],[4,2,6],[7,8,3]], [4,8,6]"
    # Test case 7: Empty triplets
    assert s.mergeTriplets([], [1,2,3]) == False, "Failed on [], [1,2,3]"
    print("All test cases passed!")

if __name__ == "__main__":
    test_merge_triplets()
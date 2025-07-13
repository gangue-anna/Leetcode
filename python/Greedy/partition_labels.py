from typing import List

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        """
        Partition the string into as many parts as possible so that each letter appears in at most one part.
        
        Approach:
        - First pass: Find the last occurrence of each character in the string.
        - Second pass: Iterate through the string and keep track of the current partition size and the farthest end position.
        - For each character, update the end position to the maximum of its last occurrence and the current end.
        - When we reach the end position, we've found a complete partition.
        - Add the partition size to the result and reset for the next partition.
        
        Time Complexity: O(N), where N is the length of the string
        - We make two passes through the string
        
        Space Complexity: O(1)
        - The lastIndex dictionary stores at most 26 characters (for lowercase letters)
        
        Args:
            s: str - Input string
        Returns:
            List[int] - List of partition sizes
        """
        lastIndex = {} # char -> last index in s

        # First pass: Find the last occurrence of each character
        for i, c in enumerate(s):
            lastIndex[c] = i

        res = []
        size, end = 0, 0
        # Second pass: Build partitions
        for i, c in enumerate(s):
            size += 1
            end = max(lastIndex[c], end)

            # If we've reached the end of the current partition
            if i == end:
                res.append(size)
                size = 0

        return res

# -------------------
# Test Cases
# -------------------
def test_partition_labels():
    s = Solution()
    # Test case 1: Basic case
    assert s.partitionLabels("ababcbacadefegdehijhklij") == [9,7,8], "Failed on 'ababcbacadefegdehijhklij'"
    # Test case 2: Single character
    assert s.partitionLabels("a") == [1], "Failed on 'a'"
    # Test case 3: All same characters
    assert s.partitionLabels("aaa") == [3], "Failed on 'aaa'"
    # Test case 4: No repeated characters
    assert s.partitionLabels("abcdef") == [1,1,1,1,1,1], "Failed on 'abcdef'"
    # Test case 5: Empty string
    assert s.partitionLabels("") == [], "Failed on empty string"
    # Test case 6: Two partitions
    assert s.partitionLabels("abac") == [3,1], "Failed on 'abac'"
    # Test case 7: Complex case
    assert s.partitionLabels("caedbdedda") == [1, 9], "Failed on 'caedbdedda'"
    print("All test cases passed!")

if __name__ == "__main__":
    test_partition_labels()

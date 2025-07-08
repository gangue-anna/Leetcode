class Solution:
    def hammingWeight(self, n: int) -> int:
        """
        Approach:
        - Count the number of 1 bits by checking the least significant bit (n % 2) and right-shifting n.
        - Repeat until n becomes 0.

        Time Complexity: O(log n), where n is the input number (number of bits).
        Space Complexity: O(1).
        """
        res = 0
        while n:
            res += n % 2 
            n = n >> 1
        return res

class Solution2:
    def hammingWeight(self, n: int) -> int:
        """
        Approach:
        - Use Brian Kernighan's algorithm: repeatedly flip the least significant 1 bit to 0 and count the steps.
        - Each operation reduces the number of 1 bits by one.

        Time Complexity: O(k), where k is the number of 1 bits in n.
        Space Complexity: O(1).
        """
        res = 0
        while n:
            n = n & (n - 1)
            res += 1
        return res

# -------------------
# Test Cases
# -------------------
def test_hamming_weight():
    s1 = Solution()
    s2 = Solution2()
    # Test case 1: Example from Leetcode
    assert s1.hammingWeight(11) == 3
    assert s2.hammingWeight(11) == 3
    # Test case 2: All bits set
    assert s1.hammingWeight(0b1111) == 4
    assert s2.hammingWeight(0b1111) == 4
    # Test case 3: No bits set
    assert s1.hammingWeight(0) == 0
    assert s2.hammingWeight(0) == 0
    # Test case 4: Single bit set
    assert s1.hammingWeight(8) == 1
    assert s2.hammingWeight(8) == 1
    # Test case 5: Large number
    assert s1.hammingWeight(0xFFFFFFFF) == 32
    assert s2.hammingWeight(0xFFFFFFFF) == 32
    print("All test cases passed!")

if __name__ == "__main__":
    test_hamming_weight()
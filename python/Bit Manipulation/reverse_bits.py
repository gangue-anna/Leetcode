class Solution:
    def reverseBits(self, n: int) -> int:
        """
        Approach:
        - Iterate over all 32 bits of the input integer.
        - For each bit, extract it and set it in the reversed position in the result.
        - Use bitwise operations to shift and set bits.

        Time Complexity: O(1), always 32 iterations.
        Space Complexity: O(1).
        """
        res = 0
        for i in range(32):
            bit = (n >> i) & 1
            res = res | (bit << (31 - i))
        return res

# -------------------
# Test Cases
# -------------------
def test_reverse_bits():
    sol = Solution()
    # Test case 1: Example from Leetcode
    assert sol.reverseBits(0b00000010100101000001111010011100) == 964176192
    # Test case 2: All bits set
    assert sol.reverseBits(0xFFFFFFFF) == 0xFFFFFFFF
    # Test case 3: All bits zero
    assert sol.reverseBits(0) == 0
    # Test case 4: Single bit set at LSB
    assert sol.reverseBits(1) == 1 << 31
    # Test case 5: Single bit set at MSB
    assert sol.reverseBits(1 << 31) == 1
    print("All test cases passed!")

if __name__ == "__main__":
    test_reverse_bits()
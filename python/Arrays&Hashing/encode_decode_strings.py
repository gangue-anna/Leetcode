from typing import List

# This class provides a solution for encoding and decoding a list of strings 
# into a single string, a common problem in data serialization.
class Solution:
    def encode(self, strs: List[str]) -> str:
        """
        Encodes a list of strings into a single string using a length-prefix format.

        Approach:
        The core idea is to create a format that is reversible and can handle any
        character, including special delimiters. We achieve this by prepending each 
        string with its length, followed by a '#' separator.
        
        Example:
        ["hello", "world"] -> "5#hello5#world"
        ["a#b", "c"] -> "3#a#b1#c"

        Time Complexity: O(N), where N is the total number of characters across all strings in the list.
        Space Complexity: O(N), to store the resulting encoded string.
        """
        # Initialize an empty string to build the encoded result.
        # A list comprehension with "".join() would also be efficient here.
        res = ""
        # Iterate through each string in the input list.
        for s in strs:
            # For each string, create a chunk in the format "[length]#[string]".
            # This format ensures we know exactly how many characters to read for each string
            # during decoding, even if the string itself contains the '#' delimiter.
            res += str(len(s)) + '#' + s
        return res
    
    def decode(self, s: str) -> List[str]:
        """
        Decodes a single string (encoded with the length-prefix format) back into a list of strings.

        Approach:
        The method iterates through the encoded string, parsing it chunk by chunk.
        In each chunk, it first reads the number before the '#' to determine the
        length of the upcoming string, then extracts that many characters.

        Example:
        "5#hello5#world" -> ["hello", "world"]
        "3#a#b1#c" -> ["a#b", "c"]
        
        Time Complexity: O(N), where N is the length of the encoded string.
        Space Complexity: O(K), where K is the number of strings in the output list.
        """
        # `res` will store the decoded strings.
        # `i` is our main pointer, marking the beginning of the current chunk to process.
        res, i = [], 0
        
        # Loop until the pointer `i` has traversed the entire encoded string.
        while i < len(s):
            # Initialize a second pointer `j` at the same position as `i`.
            j = i 
            
            # Move pointer `j` forward to find the '#' delimiter.
            # The characters between `i` and `j` form the string's length.
            while s[j] != "#":
                j += 1
            
            # Extract the length by slicing the string from `i` to `j` and converting to an integer.
            length = int(s[i:j])
            
            # The actual string starts right after the '#' (at `j + 1`).
            # We slice from `j + 1` for `length` characters to get the original string.
            # The end of the slice is `j + 1 + length`.
            decoded_string = s[j + 1 : j + 1 + length]
            res.append(decoded_string)
            
            # Move the main pointer `i` to the beginning of the next chunk.
            i = j + 1 + length
            
        return res

# -------------------
# Test Cases
# -------------------
def test_encode_decode_strings():
    """
    A suite of test cases to verify the correctness of the encode and decode methods.
    """
    sol = Solution()
    print("Running test suite...")

    # Test case 1: Basic strings without any special characters.
    strs1 = ["hello", "world"]
    encoded1 = sol.encode(strs1)
    assert sol.decode(encoded1) == strs1, f"Test Case 1 Failed: {strs1}"
    print("Test Case 1 Passed!")

    # Test case 2: Strings containing the '#' delimiter to test robustness.
    strs2 = ["a#b#c", "##", "123"]
    encoded2 = sol.encode(strs2)
    assert sol.decode(encoded2) == strs2, f"Test Case 2 Failed: {strs2}"
    print("Test Case 2 Passed!")

    # Test case 3: An empty list, an important edge case.
    strs3 = []
    encoded3 = sol.encode(strs3)
    assert sol.decode(encoded3) == strs3, f"Test Case 3 Failed: {strs3}"
    print("Test Case 3 Passed!")

    # Test case 4: A list containing empty strings.
    strs4 = ["", "abc", ""]
    encoded4 = sol.encode(strs4)
    assert sol.decode(encoded4) == strs4, f"Test Case 4 Failed: {strs4}"
    print("Test Case 4 Passed!")

    # Test case 5: A single long string to check performance and correctness with larger inputs.
    strs5 = ["a" * 1000]
    encoded5 = sol.encode(strs5)
    assert sol.decode(encoded5) == strs5, "Test Case 5 Failed"
    print("Test Case 5 Passed!")

    print("\nAll test cases passed successfully! ✅")

if __name__ == "__main__":
    test_encode_decode_strings()

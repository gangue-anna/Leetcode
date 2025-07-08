class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        """
        Check if s2 contains a permutation of s1 (i.e., any substring of s2 is a permutation of s1).
        Approach:
        - Use sliding window and character frequency maps.
        - Compare window frequency with s1 frequency at each step.
        Time Complexity: O(n), where n is the length of s2
        Space Complexity: O(1) (since alphabet size is constant)
        """
        # If s1 is longer than s2, s1 cannot be a permutation of any substring in s2
        if len(s1) > len(s2):
            return False
            
        # Initialize character frequency maps
        s1_count = {}
        s2_count = {}
        
        # Count frequencies for s1
        for c in s1:
            s1_count[c] = s1_count.get(c, 0) + 1
            
        # Initialize window with first len(s1) characters of s2
        for i in range(len(s1)):
            s2_count[s2[i]] = s2_count.get(s2[i], 0) + 1
            
        # Check if first window matches
        if s1_count == s2_count:
            return True
            
        # Slide window and check each position
        for i in range(len(s1), len(s2)):
            # Add new character to window
            s2_count[s2[i]] = s2_count.get(s2[i], 0) + 1
            
            # Remove character that's no longer in window
            s2_count[s2[i - len(s1)]] -= 1
            if s2_count[s2[i - len(s1)]] == 0:
                del s2_count[s2[i - len(s1)]]
                
            # Check if current window matches s1
            if s1_count == s2_count:
                return True
                
        return False

# -------------------
# Test Cases
# -------------------
def test_permutation_string():
    s = Solution()
    # Test case 1: Basic
    assert s.checkInclusion("ab", "eidbaooo") == True
    # Test case 2: No permutation
    assert s.checkInclusion("ab", "eidboaoo") == False
    # Test case 3: s1 longer than s2
    assert s.checkInclusion("abc", "ab") == False
    # Test case 4: Exact match
    assert s.checkInclusion("a", "a") == True
    # Test case 5: Empty s1
    assert s.checkInclusion("", "abc") == True
    # Test case 6: Empty s2
    assert s.checkInclusion("a", "") == False
    # Test case 7: All characters same
    assert s.checkInclusion("aaa", "aaaaaa") == True
    print("All test cases passed!")

if __name__ == "__main__":
    test_permutation_string()
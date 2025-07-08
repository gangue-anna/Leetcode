from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        """
        Find the number of days until a warmer temperature for each day.
        
        Brute Force Approach:
        1. For each temperature, look at all temperatures after it
        2. Find the first temperature that is greater
        3. Store the difference in indices
        
        Time Complexity: O(n^2) - for each temperature, we look at all remaining temperatures
        Space Complexity: O(n) - to store the result array
        """
        n = len(temperatures)
        result = [0] * n  # Initialize result array with zeros
        
        # For each temperature
        for i in range(n):
            # Look at all temperatures after current temperature
            for j in range(i + 1, n):
                # If we find a warmer temperature
                if temperatures[j] > temperatures[i]:
                    result[i] = j - i  # Store the number of days
                    break  # Stop looking once we find the first warmer day
        
        return result

class Solution2:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        """
        Find the number of days until a warmer temperature for each day using a monotonic stack.
        
        Stack-based Approach:
        1. Use a stack to store [temperature, index] pairs
        2. For each temperature:
           - While current temperature is greater than stack top:
             * Pop the stack
             * Calculate days until warmer temperature
           - Push current temperature and index to stack
        
        Time Complexity: O(n) - each temperature is pushed and popped at most once
        Space Complexity: O(n) - stack and result array
        """
        res = [0] * len(temperatures)
        stack = []  # Stack stores [temperature, index] pairs
        
        for i, t in enumerate(temperatures):
            # While current temperature is greater than stack top
            while stack and t > stack[-1][0]:
                stackT, stackInd = stack.pop()
                res[stackInd] = (i - stackInd)  # Calculate days until warmer temperature
            stack.append([t, i])
        return res

# -------------------
# Test Cases
# -------------------
def test_daily_temperatures():
    s1 = Solution()
    s2 = Solution2()
    # Test case 1: Example
    temps = [73,74,75,71,69,72,76,73]
    expected = [1,1,4,2,1,1,0,0]
    assert s1.dailyTemperatures(temps) == expected
    assert s2.dailyTemperatures(temps) == expected
    # Test case 2: All increasing
    temps = [60,61,62,63]
    expected = [1,1,1,0]
    assert s1.dailyTemperatures(temps) == expected
    assert s2.dailyTemperatures(temps) == expected
    # Test case 3: All decreasing
    temps = [80,70,60,50]
    expected = [0,0,0,0]
    assert s1.dailyTemperatures(temps) == expected
    assert s2.dailyTemperatures(temps) == expected
    # Test case 4: All same
    temps = [50,50,50,50]
    expected = [0,0,0,0]
    assert s1.dailyTemperatures(temps) == expected
    assert s2.dailyTemperatures(temps) == expected
    # Test case 5: Single temperature
    temps = [100]
    expected = [0]
    assert s1.dailyTemperatures(temps) == expected
    assert s2.dailyTemperatures(temps) == expected
    # Test case 6: Empty list
    temps = []
    expected = []
    assert s1.dailyTemperatures(temps) == expected
    assert s2.dailyTemperatures(temps) == expected
    print("All test cases passed!")

if __name__ == "__main__":
    test_daily_temperatures()

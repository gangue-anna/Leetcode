from typing import List

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        """
        Calculate the number of car fleets that will arrive at the target.
        Approach:
        - Pair up positions and speeds, sort by position descending.
        - For each car, compute the time to reach the target.
        - Use a stack to count fleets: if a car catches up to the fleet ahead, it joins that fleet.
        Time Complexity: O(n log n) for sorting
        Space Complexity: O(n)
        """
        pair = [[p, s] for p, s in zip(position, speed)]
        stack = []

        for p, s in sorted(pair)[::-1]: #reverse sorted pair
            stack.append((target - p) / s)
            if len(stack) >= 2 and stack[-1] <= stack[-2]:
                stack.pop()
        return len(stack)
    


# -------------------
# Test Cases
# -------------------
def test_car_fleet():
    s = Solution()
    # Test case 1: Example
    assert s.carFleet(12, [10,8,0,5,3], [2,4,1,1,3]) == 3
    # Test case 2: All cars same speed
    assert s.carFleet(10, [0,2,4], [2,2,2]) == 1
    # Test case 3: No cars
    assert s.carFleet(10, [], []) == 0
    # Test case 4: One car
    assert s.carFleet(10, [5], [2]) == 1
    # Test case 5: Cars start at same position
    assert s.carFleet(10, [0,0,0], [1,2,3]) == 1
    # Test case 6: Cars never meet
    assert s.carFleet(10, [0,4,8], [1,1,1]) == 3
    print("All test cases passed!")

if __name__ == "__main__":
    test_car_fleet()
    
    


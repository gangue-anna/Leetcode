from typing import List

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        """
        Find the starting gas station index from which you can travel around the circuit once.
        If not possible, return -1.
        
        Approach:
        - If the total gas is less than the total cost, it's impossible to complete the circuit.
        - Use a greedy approach:
          - Track the total gas left as you iterate through the stations.
          - If at any point the total becomes negative, reset the starting index to the next station and reset total to 0.
          - The answer is the index after the last failure point.
        
        Time Complexity: O(N), where N is the number of stations
        - We iterate through the gas stations once
        
        Space Complexity: O(1)
        - Only a constant amount of extra space is used
        
        Args:
            gas: List[int] - Amount of gas at each station
            cost: List[int] - Cost to travel to the next station
        Returns:
            int - Starting station index, or -1 if not possible
        """
        if sum(gas) < sum(cost):
            return -1
        
        total = 0
        res = 0

        for i in range(len(gas)):
            total += (gas[i] - cost[i])

            if total < 0:
                # Can't reach the next station, reset start position
                total = 0
                res = i + 1
        
        return res

# -------------------
# Test Cases
# -------------------
def test_can_complete_circuit():
    s = Solution()
    # Test case 1: Can complete circuit
    assert s.canCompleteCircuit([1,2,3,4,5], [3,4,5,1,2]) == 3, "Failed on [1,2,3,4,5], [3,4,5,1,2]"
    # Test case 2: Cannot complete circuit
    assert s.canCompleteCircuit([2,3,4], [3,4,3]) == -1, "Failed on [2,3,4], [3,4,3]"
    # Test case 3: Single station, enough gas
    assert s.canCompleteCircuit([5], [4]) == 0, "Failed on [5], [4]"
    # Test case 4: Single station, not enough gas
    assert s.canCompleteCircuit([1], [2]) == -1, "Failed on [1], [2]"
    # Test case 5: All stations same gas and cost
    assert s.canCompleteCircuit([2,2,2], [2,2,2]) == 0, "Failed on [2,2,2], [2,2,2]"
    # Test case 6: Must start at last station
    assert s.canCompleteCircuit([2,3,4], [3,4,5]) == -1, "Failed on [2,3,4], [3,4,5]"
    # Test case 7: Multiple possible starts, return first valid
    assert s.canCompleteCircuit([4,5,2,6,5,3], [3,2,7,3,2,9]) == -1, "Failed on [4,5,2,6,5,3], [3,2,7,3,2,9]"
    print("All test cases passed!")

if __name__ == "__main__":
    test_can_complete_circuit()
from typing import List
import heapq

class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        """
        Determine if the hand can be rearranged into groups of consecutive cards of size groupSize.
        
        Approach:
        - If the total number of cards is not divisible by groupSize, return False.
        - Count the frequency of each card.
        - Use a min-heap to get the smallest card available.
        - For each group, try to form a consecutive sequence starting from the smallest available card.
        - If any card in the sequence is missing, return False.
        - Decrease the count of each card used in the group.
        - If a card's count becomes 0, remove it from the heap.
        - Continue until all cards are used or it's impossible to form groups.
        
        Time Complexity: O(N log N), where N is the number of cards
        - Building the heap takes O(N log N)
        - Each card is processed at most once
        
        Space Complexity: O(N)
        - Storing the count dictionary and heap
        
        Args:
            hand: List[int] - List of card values
            groupSize: int - Size of each group
        Returns:
            bool - True if hand can be arranged into groups, False otherwise
        """
        if len(hand) % groupSize:
            return False
        
        count = {}
        for n in hand:
            count[n] = 1 + count.get(n, 0)

        minH = list(count.keys())
        heapq.heapify(minH)

        while minH:
            first = minH[0]
            
            # Try to form a group starting from 'first'
            for i in range(first, first + groupSize):
                if i not in count:
                    return False
                count[i] -= 1
                if count[i] == 0:
                    if i != minH[0]:
                        return False
                    heapq.heappop(minH)
        return True

# -------------------
# Test Cases
# -------------------
def test_is_n_straight_hand():
    s = Solution()
    # Test case 1: Can form groups
    assert s.isNStraightHand([1,2,3,6,2,3,4,7,8], 3) == True, "Failed on [1,2,3,6,2,3,4,7,8], 3"
    # Test case 2: Cannot form groups
    assert s.isNStraightHand([1,2,3,4,5], 4) == False, "Failed on [1,2,3,4,5], 4"
    # Test case 3: Single group
    assert s.isNStraightHand([1,2,3], 3) == True, "Failed on [1,2,3], 3"
    # Test case 4: Empty hand
    assert s.isNStraightHand([], 2) == True, "Failed on [], 2"
    # Test case 5: Not enough cards
    assert s.isNStraightHand([1,2], 3) == False, "Failed on [1,2], 3"
    # Test case 6: Duplicate cards
    assert s.isNStraightHand([1,1,2,2,3,3], 2) == False, "Failed on [1,1,2,2,3,3], 2"
    # Test case 7: Large group size
    assert s.isNStraightHand([1,2,3,4,5,6], 6) == True, "Failed on [1,2,3,4,5,6], 6"
    print("All test cases passed!")

if __name__ == "__main__":
    test_is_n_straight_hand()
from typing import List
from collections import defaultdict

class CountSquares:
    """
    Data structure to add points on a 2D plane and count the number of axis-aligned squares
    that can be formed with a given query point as one of the corners.
    
    Approach:
    - Use a dictionary (ptsCount) to count occurrences of each point (for duplicate points)
    - Store all added points in a list (pts) for iteration
    - For a query point (px, py), iterate over all previously added points (x, y)
      and check if they can form a diagonal of a square with (px, py)
    - For each such diagonal, check if the other two corners exist using ptsCount
    - Multiply the counts of the other two corners to get the number of squares for this diagonal
    
    Time Complexity:
    - add: O(1) per operation
    - count: O(N), where N is the number of points added so far
      (since we iterate over all points for each count query)
    
    Space Complexity: O(N), where N is the number of points added (for pts and ptsCount)
    """
    def __init__(self):
        self.ptsCount = defaultdict(int)  # Maps (x, y) -> count
        self.pts = []  # List of all points added

    def add(self, point: List[int]) -> None:
        """
        Add a point to the data structure.
        Args:
            point: List[int] - The [x, y] coordinates of the point
        """
        self.ptsCount[tuple(point)] += 1
        self.pts.append(point)

    def count(self, point: List[int]) -> int:
        """
        Count the number of axis-aligned squares with the given point as one of the corners.
        Args:
            point: List[int] - The [x, y] coordinates of the query point
        Returns:
            int - The number of squares
        """
        res = 0
        px, py = point

        for x, y in self.pts:
            # Check if (x, y) can be a diagonal with (px, py) (must form a square)
            if (abs(py - y) != abs(px - x)) or x == px or y == py:
                continue
            # The other two corners are (x, py) and (px, y)
            res += self.ptsCount[(x, py)] * self.ptsCount[(px, y)]
        return res

# -------------------
# Test Cases
# -------------------
def test_detect_squares():
    cs = CountSquares()
    # Add points
    cs.add([3, 10])
    cs.add([11, 2])
    cs.add([3, 2])
    # Test case 1: No square yet
    assert cs.count([11, 10]) == 1, "Failed on count([11, 10])"
    # Add more points
    cs.add([11, 2])
    # Test case 2: Duplicate point increases square count
    assert cs.count([11, 10]) == 2, "Failed on count([11, 10]) after duplicate add"
    # Test case 3: No square possible
    assert cs.count([14, 8]) == 0, "Failed on count([14, 8])"
    # Add more points to form a square at a different location
    cs2 = CountSquares()
    cs2.add([1, 1])
    cs2.add([1, 2])
    cs2.add([2, 1])
    cs2.add([2, 2])
    assert cs2.count([1, 1]) == 1, "Failed on count([1, 1]) for perfect square"
    assert cs2.count([2, 2]) == 1, "Failed on count([2, 2]) for perfect square"
    # Test case 4: Multiple squares with shared points
    cs3 = CountSquares()
    cs3.add([0, 0])
    cs3.add([0, 1])
    cs3.add([1, 0])
    cs3.add([1, 1])
    cs3.add([2, 0])
    cs3.add([2, 1])
    assert cs3.count([1, 0]) == 2, "Failed on count([1, 0]) for two possible squares"
    print("All test cases passed!")

if __name__ == "__main__":
    test_detect_squares()

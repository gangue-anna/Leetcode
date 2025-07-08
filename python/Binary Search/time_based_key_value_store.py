class TimeMap:

    def __init__(self):
        """
        Initialize TimeMap with a dictionary
        key: string
        value: list of [value, timestamp] pairs, sorted by timestamp
        Time Complexity: O(1)
        Space Complexity: O(n), where n is the number of set operations
        """
        self.store = {} # key = string , value = [list of [value, timestamp]]

    def set(self, key: str, value: str, timestamp: int) -> None:
        """
        Set a key-value pair with timestamp
        Time Complexity: O(1)
        """
        if key not in self.store:
            self.store[key] = []
        self.store[key].append([value, timestamp])
        
    def get(self, key: str, timestamp: int) -> str:
        """
        Get the value for key at the given timestamp
        If no value exists at timestamp, return the value at the largest timestamp <= timestamp
        Time Complexity: O(log n) where n is number of values for the key
        """
        # If key doesn't exist or no values for key, return empty string
        if key not in self.store or not self.store[key]:
            return ""
        values = self.store[key]
        res = ""
        # Binary search to find the largest timestamp <= given timestamp
        l, r = 0, len(values) - 1
        while l <= r:
            m = (l + r) // 2
            # If current timestamp is <= target timestamp
            if values[m][1] <= timestamp:
                # Update result and search right for larger timestamp
                res = values[m][0]
                l = m + 1
            else:
                # Search left for smaller timestamp
                r = m - 1
        return res

# -------------------
# Test Cases
# -------------------
def test_time_map():
    tm = TimeMap()
    # Test case 1: Basic set and get
    tm.set("foo", "bar", 1)
    assert tm.get("foo", 1) == "bar"
    assert tm.get("foo", 3) == "bar"
    # Test case 2: Multiple sets, increasing timestamps
    tm.set("foo", "bar2", 4)
    assert tm.get("foo", 4) == "bar2"
    assert tm.get("foo", 5) == "bar2"
    # Test case 3: Key not found
    assert tm.get("baz", 1) == ""
    # Test case 4: Timestamp before any set
    assert tm.get("foo", 0) == ""
    # Test case 5: Multiple keys
    tm.set("baz", "qux", 2)
    assert tm.get("baz", 2) == "qux"
    assert tm.get("baz", 3) == "qux"
    print("All test cases passed!")

if __name__ == "__main__":
    test_time_map()
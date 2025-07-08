class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val
        self.prev = self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        """
        LRU Cache using a doubly linked list and hashmap.
        Approach:
        - Hashmap for O(1) access to nodes.
        - Doubly linked list to maintain LRU order (left: LRU, right: MRU).
        - On get/put, move node to MRU position.
        Time Complexity: O(1) for get and put
        Space Complexity: O(capacity)
        """
        self.cap = capacity
        self.cache = {} # map the key to node
        # left = least recently used, right = most recently used
        self.left, self.right = Node(0, 0), Node(0, 0)
        self.left.next, self.right.prev = self.right, self.left # type: ignore

    # remove node from list
    def remove(self, node):
        prev, nxt = node.prev, node.next
        prev.next, nxt.prev = nxt, prev  # type: ignore

    # insert node at right (MRU)
    def insert(self, node):
        prev, nxt = self.right.prev, self.right
        prev.next = nxt.prev = node  # type: ignore
        node.next, node.prev = nxt, prev

    def get(self, key: int) -> int:
        if key in self.cache:
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove(self.cache[key])
        self.cache[key] = Node(key, value)
        self.insert(self.cache[key])
        if len(self.cache) > self.cap:
            # remove from the list and delete the LRU from the hashmap
            lru = self.left.next
            self.remove(lru)
            del self.cache[lru.key]  # type: ignore

# -------------------
# Test Cases
# -------------------
def test_lru_cache():
    # Test case 1: Basic put/get
    lru = LRUCache(2)
    lru.put(1, 1)
    lru.put(2, 2)
    assert lru.get(1) == 1
    lru.put(3, 3)  # evicts key 2
    assert lru.get(2) == -1
    lru.put(4, 4)  # evicts key 1
    assert lru.get(1) == -1
    assert lru.get(3) == 3
    assert lru.get(4) == 4
    # Test case 2: Overwrite value
    lru = LRUCache(2)
    lru.put(1, 1)
    lru.put(1, 10)
    assert lru.get(1) == 10
    # Test case 3: Capacity 1
    lru = LRUCache(1)
    lru.put(1, 1)
    assert lru.get(1) == 1
    lru.put(2, 2)
    assert lru.get(1) == -1
    assert lru.get(2) == 2
    # Test case 4: Get non-existent key
    lru = LRUCache(2)
    assert lru.get(99) == -1
    # Test case 5: Edge case, no operations
    lru = LRUCache(2)
    print("All test cases passed!")

if __name__ == "__main__":
    test_lru_cache()
class MinStack:
    """
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    
    Approach:
    1. Use two stacks:
       - main stack for normal operations
       - minStack to track minimum values
    2. For each push:
       - Push to main stack
       - Push min(current value, current min) to minStack
    3. For each pop:
       - Pop from both stacks
    4. For getMin:
       - Return top of minStack
    
    Time Complexity:
    - All operations are O(1)
    
    Space Complexity: O(n)
    - We store each element in both stacks
    """
    def __init__(self):
        self.stack = []  # Main stack
        self.minStack = []  # Stack to track minimum values

    def push(self, val: int) -> None:
        self.stack.append(val)
        # If minStack is empty, val is the minimum
        # Otherwise, compare with current minimum
        if not self.minStack:
            self.minStack.append(val)
        else:
            self.minStack.append(min(val, self.minStack[-1]))

    def pop(self) -> None:
        # Pop from both stacks
        self.stack.pop()
        self.minStack.pop()

    def top(self) -> int:
        # Return top element of main stack
        return self.stack[-1]

    def getMin(self) -> int:
        # Return top element of minStack (current minimum)
        return self.minStack[-1]

# -------------------
# Test Cases
# -------------------
def test_min_stack():
    # Test case 1: Basic push/pop/min
    minStack = MinStack()
    minStack.push(-2)
    minStack.push(0)
    minStack.push(-3)
    assert minStack.getMin() == -3
    minStack.pop()
    assert minStack.top() == 0
    assert minStack.getMin() == -2
    # Test case 2: Increasing order
    minStack = MinStack()
    minStack.push(1)
    minStack.push(2)
    minStack.push(3)
    assert minStack.getMin() == 1
    minStack.pop()
    assert minStack.getMin() == 1
    # Test case 3: Decreasing order
    minStack = MinStack()
    minStack.push(3)
    minStack.push(2)
    minStack.push(1)
    assert minStack.getMin() == 1
    minStack.pop()
    assert minStack.getMin() == 2
    # Test case 4: All same
    minStack = MinStack()
    minStack.push(5)
    minStack.push(5)
    minStack.push(5)
    assert minStack.getMin() == 5
    minStack.pop()
    minStack.pop()
    assert minStack.getMin() == 5
    print("All test cases passed!")

if __name__ == "__main__":
    test_min_stack()
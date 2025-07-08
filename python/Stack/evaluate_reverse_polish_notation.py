from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        """
        Evaluate the value of an arithmetic expression in Reverse Polish Notation (RPN).
        Approach:
        - Use a stack to process tokens.
        - For each token:
          - If it's a number, push to stack.
          - If it's an operator, pop two numbers, apply the operator, and push the result.
        Time Complexity: O(n), where n is the number of tokens
        Space Complexity: O(n)
        """
        stack = []
        for c in tokens:
            if c == "+":
                stack.append(stack.pop() + stack.pop())
            elif c == "-":
                op2, op1 = stack.pop(), stack.pop()
                stack.append(op1 - op2)
            elif c == "*":
                stack.append(stack.pop() * stack.pop())
            elif c == "/":
                op2, op1 = stack.pop(), stack.pop()
                stack.append(int(op1 / op2))  # Truncate towards zero
            else:
                stack.append(int(c))
        return stack[0]

# -------------------
# Test Cases
# -------------------
def test_eval_rpn():
    s = Solution()
    # Test case 1: Basic
    assert s.evalRPN(["2","1","+","3","*"]) == 9
    # Test case 2: Division truncates towards zero
    assert s.evalRPN(["4","13","5","/","+"]) == 6
    # Test case 3: Negative numbers
    assert s.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]) == 22
    # Test case 4: Single number
    assert s.evalRPN(["42"]) == 42
    # Test case 5: Subtraction
    assert s.evalRPN(["5","3","-"]) == 2
    # Test case 6: Multiplication
    assert s.evalRPN(["3","-4","*"]) == -12
    # Test case 7: Division negative
    assert s.evalRPN(["7","-3","/"]) == -2
    print("All test cases passed!")

if __name__ == "__main__":
    test_eval_rpn()
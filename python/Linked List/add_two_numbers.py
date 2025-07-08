from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        """
        Add two numbers represented by linked lists (digits in reverse order).
        Approach:
        - Traverse both lists, summing corresponding digits and carry.
        - Create new nodes for each digit of the result.
        - Continue until both lists and carry are exhausted.
        Time Complexity: O(max(m, n)), where m and n are the lengths of the lists
        Space Complexity: O(max(m, n)) for the result list
        """
        dummy = ListNode()
        cur = dummy
        carry = 0

        while l1 or l2 or carry:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0

            #new digit
            val = v1 + v2 + carry
            
            carry = val // 10
            val = val % 10
            cur.next = ListNode(val)

            #update pointers
            cur = cur.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        return dummy.next

# -------------------
# Helper Functions for Testing
# -------------------
def list_to_linkedlist(lst):
    dummy = ListNode()
    cur = dummy
    for val in lst:
        cur.next = ListNode(val)
        cur = cur.next
    return dummy.next

def linkedlist_to_list(node):
    result = []
    while node:
        result.append(node.val)
        node = node.next
    return result

# -------------------
# Test Cases
# -------------------
def test_add_two_numbers():
    s = Solution()
    # Test case 1: Basic
    l1 = list_to_linkedlist([2,4,3])
    l2 = list_to_linkedlist([5,6,4])
    result = s.addTwoNumbers(l1, l2)
    assert linkedlist_to_list(result) == [7,0,8]
    # Test case 2: Different lengths
    l1 = list_to_linkedlist([9,9,9,9,9,9,9])
    l2 = list_to_linkedlist([9,9,9,9])
    result = s.addTwoNumbers(l1, l2)
    assert linkedlist_to_list(result) == [8,9,9,9,0,0,0,1]
    # Test case 3: One list is empty
    l1 = list_to_linkedlist([])
    l2 = list_to_linkedlist([1,2,3])
    result = s.addTwoNumbers(l1, l2)
    assert linkedlist_to_list(result) == [1,2,3]
    # Test case 4: Both lists empty
    l1 = list_to_linkedlist([])
    l2 = list_to_linkedlist([])
    result = s.addTwoNumbers(l1, l2)
    assert linkedlist_to_list(result) == []
    # Test case 5: Carry at the end
    l1 = list_to_linkedlist([5])
    l2 = list_to_linkedlist([5])
    result = s.addTwoNumbers(l1, l2)
    assert linkedlist_to_list(result) == [0,1]
    print("All test cases passed!")

if __name__ == "__main__":
    test_add_two_numbers()
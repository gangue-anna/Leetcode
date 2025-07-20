#include <bits/stdc++.h>  // includes all standard C++ libraries
using namespace std;

class Solution {
public:
    /**
     * Finds the duplicate number in an array using Floyd's Tortoise and Hare algorithm.
     *
     * Approach:
     * - Treat the array as a linked list where the value at each index is the next node.
     * - Use two pointers (slow and fast) to detect the cycle (intersection point).
     * - Then use another pointer starting from the beginning to find the entrance to the cycle.
     * - The entrance to the cycle is the duplicate number.
     *
     * Time Complexity: O(n)
     *   - Both pointers traverse the list at most twice.
     * Space Complexity: O(1)
     *   - No extra space is used, just pointers.
     */
    int findDuplicate(vector<int>& nums) {
        int slow = 0;  // slow pointer starts at index 0
        int fast = 0;  // fast pointer starts at index 0

        // First phase: find intersection point of the two runners
        while (true) {
            slow = nums[slow];           // move slow by 1 step
            fast = nums[nums[fast]];    // move fast by 2 steps
            if (slow == fast) {         // they meet inside the cycle
                break;
            }
        }

        // Second phase: find the entrance to the cycle
        int slow2 = 0;  // new pointer starts at index 0
        while (true) {
            slow = nums[slow];      // move slow by 1 step
            slow2 = nums[slow2];    // move slow2 by 1 step
            if (slow == slow2) {    // both meet at the duplicate number
                return slow;        // return the duplicate number
            }
        }
    }
};


/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ header files (like <vector>, <iostream>, etc.) in one line.

using namespace std;
    ✅ Lets you use names like vector, cout, etc., directly without writing std::vector.

class Solution {
    ✅ Defines a class called Solution.

public:
    ✅ Makes the following members of the class accessible from outside.

int findDuplicate(vector<int>& nums)
    ✅ Declares a function that takes a reference to a vector of integers and returns an int.

int slow = 0;
    ✅ Initializes a pointer/variable named slow to index 0.

int fast = 0;
    ✅ Initializes a pointer/variable named fast to index 0.

while (true)
    ✅ Starts an infinite loop that only stops when we explicitly break.

slow = nums[slow];
    ✅ Move slow pointer one step forward (to nums[slow]).

fast = nums[nums[fast]];
    ✅ Move fast pointer two steps forward (to nums[nums[fast]]).

if (slow == fast)
    ✅ If slow and fast meet, a cycle is detected — break out of the loop.

int slow2 = 0;
    ✅ Declare a second pointer starting at index 0.

slow = nums[slow];
slow2 = nums[slow2];
    ✅ Move both slow and slow2 forward one step each.

if (slow == slow2)
    ✅ When they meet, the duplicate number is found — return it.

return slow;
    ✅ Return the value of slow, which is the duplicate.

};
    ✅ End of the class definition.

*/

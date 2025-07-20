#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    /*
     * Use two stacks:
     * mainStack  - stores actual values
     * minStack   - tracks minimum at each level
     */
    stack<int> mainStack;  // Main stack
    stack<int> minStack;   // Minimum value stack

public:
    /*
     * Initialize empty MinStack
     * Time: O(1)
     */
    MinStack() {
        // Stacks are automatically initialized empty
    }
    
    /*
     * Push value onto stack and update minimum
     * Time: O(1)
     */
    void push(int val) {
        mainStack.push(val);
        
        // If minStack empty, val is minimum
        // Otherwise, push minimum of val and current minimum
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            minStack.push(min(val, minStack.top()));
        }
    }
    
    /*
     * Remove top element from both stacks
     * Time: O(1)
     */
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    /*
     * Return top element of main stack
     * Time: O(1)
     */
    int top() {
        return mainStack.top();
    }
    
    /*
     * Return current minimum (top of minStack)
     * Time: O(1)
     */
    int getMin() {
        return minStack.top();
    }
};

/*
 * Detailed C++ Syntax Explanation for Beginners:
 * 
 * 1. Class Structure:
 *    private:           // Members only accessible within class
 *    public:            // Members accessible from outside
 * 
 * 2. Stack Declaration:
 *    stack<int>         // STL stack container for integers
 *    stack.push(val)    // Add element to top
 *    stack.pop()        // Remove top element
 *    stack.top()        // Access top element
 *    stack.empty()      // Check if stack is empty
 * 
 * 3. Constructor:
 *    MinStack()         // Called when object is created
 *    - No explicit initialization needed
 * 
 * 4. Standard Library:
 *    min(a, b)         // Returns smaller of two values
 * 
 * Note: This implementation:
 * - Uses O(n) extra space for minStack
 * - Provides O(1) time for all operations
 * - Maintains minimum value without searching
 */

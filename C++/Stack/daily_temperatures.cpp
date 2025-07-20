#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /**
         * Find the number of days until a warmer temperature for each day using a monotonic stack.
         * 
         * Stack-based Approach:
         * 1. Use a stack to store pairs of [temperature, index]
         * 2. For each temperature:
         *    - While current temperature is greater than stack top temperature:
         *      * Pop the stack (this temperature now has found its warmer day)
         *      * Calculate days until warmer temperature (current index - popped index)
         *      * Store result for the popped index
         *    - Push current temperature and index to stack
         * 3. Remaining elements in stack don't have warmer days (result remains 0)
         * 
         * Time Complexity: O(n) - each temperature is pushed and popped at most once
         * Space Complexity: O(n) - stack can contain at most n elements + result vector
         */
        
        int n = temperatures.size();                    // Get size of input array
        vector<int> result(n, 0);                       // Initialize result vector with zeros
        stack<pair<int, int>> st;                       // Stack to store [temperature, index] pairs
        
        // Iterate through each temperature with its index
        for (int i = 0; i < n; i++) {
            int currentTemp = temperatures[i];
            
            // While stack is not empty AND current temperature is greater than stack top temperature
            while (!st.empty() && currentTemp > st.top().first) {
                pair<int, int> topPair = st.top();      // Get the top pair [temp, index]
                st.pop();                               // Remove the top element
                
                int stackTemp = topPair.first;          // Temperature at stack top
                int stackIndex = topPair.second;        // Index at stack top
                
                // Calculate days until warmer temperature and store in result
                result[stackIndex] = i - stackIndex;
            }
            
            // Push current temperature and index to stack
            st.push(make_pair(currentTemp, i));
        }
        
        // Elements remaining in stack don't have warmer days (result already initialized to 0)
        return result;
    }
};

/*
=== C++ SYNTAX EXPLANATION FOR BEGINNERS ===

1. #include <bits/stdc++.h>
   - This is a header file that includes most standard C++ libraries
   - It's commonly used in competitive programming but not recommended for production code
   - Alternative: include specific headers like #include <vector>, #include <stack>, etc.

2. using namespace std;
   - This allows us to use standard library functions without the std:: prefix
   - Without this, we'd need to write std::vector, std::stack, etc.

3. class Solution {
   - Defines a class named Solution
   - Classes group related data and functions together

4. public:
   - Access specifier that makes the following members accessible from outside the class
   - Other access specifiers: private (only accessible within class), protected (inheritance related)

5. vector<int> dailyTemperatures(vector<int>& temperatures)
   - Function declaration and definition
   - vector<int>: return type (dynamic array of integers)
   - dailyTemperatures: function name
   - vector<int>& temperatures: parameter (reference to vector of integers)
   - & means reference - we're working with the original vector, not a copy

6. int n = temperatures.size();
   - Declares integer variable n and initializes it with the size of temperatures vector
   - size() is a member function of vector that returns the number of elements

7. vector<int> result(n, 0);
   - Creates a vector named result with n elements, all initialized to 0
   - Constructor syntax: vector<type> name(size, initial_value)

8. stack<pair<int, int>> st;
   - Declares a stack that stores pairs of integers
   - pair<int, int> means each element is a pair containing two integers
   - Stack follows LIFO (Last In, First Out) principle

9. for (int i = 0; i < n; i++)
   - Standard for loop
   - Initializes i to 0, continues while i < n, increments i after each iteration

10. while (!st.empty() && currentTemp > st.top().first)
    - While loop with two conditions connected by AND (&&)
    - !st.empty(): checks if stack is NOT empty (! is the NOT operator)
    - st.top(): returns reference to the top element of stack
    - .first: accesses the first element of a pair

11. pair<int, int> topPair = st.top();
    - Creates a pair variable and copies the top element of stack into it
    - pair stores two related values together

12. st.pop();
    - Removes the top element from the stack
    - Note: pop() doesn't return the removed element in C++

13. st.push(make_pair(currentTemp, i));
    - Adds a new pair to the top of the stack
    - make_pair(): utility function to create a pair object

14. return result;
    - Returns the result vector from the function

=== KEY C++ CONCEPTS USED ===

- Vector: Dynamic array that can grow/shrink during runtime
- Stack: LIFO data structure with push(), pop(), top(), empty() operations  
- Pair: Container that holds two values together, accessed via .first and .second
- References (&): Allow functions to work with original data instead of copies
- Member functions: Functions that belong to objects (like .size(), .empty(), .top())
- Access specifiers: Control visibility of class members (public, private, protected)

*/
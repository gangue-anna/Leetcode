#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        /**
         * Calculate the number of car fleets that will arrive at the target.
         * 
         * Approach:
         * 1. Pair up positions and speeds, then sort by position in descending order
         * 2. For each car (starting from the car closest to target):
         *    - Calculate time to reach target: (target - position) / speed
         *    - Use a stack to track fleet formation:
         *      * If current car's time <= previous car's time, they form a fleet
         *      * Otherwise, current car forms a new fleet
         * 3. The number of elements in stack = number of fleets
         * 
         * Key Insight: A car can only catch up to slower cars ahead of it.
         * If a faster car is behind a slower car, it will be limited by the slower car's speed.
         * 
         * Time Complexity: O(n log n) - dominated by sorting the cars by position
         * Space Complexity: O(n) - for storing pairs and stack
         */
        
        int n = position.size();                        // Number of cars
        vector<pair<int, int>> cars;                    // Store [position, speed] pairs
        
        // Create pairs of [position, speed] for each car
        for (int i = 0; i < n; i++) {
            cars.push_back(make_pair(position[i], speed[i]));
        }
        
        // Sort cars by position in descending order (closest to target first)
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());
        
        vector<double> stack;                           // Stack to store arrival times
        
        // Process each car from closest to target to farthest
        for (int i = 0; i < n; i++) {
            int pos = cars[i].first;                    // Car's current position
            int spd = cars[i].second;                   // Car's speed
            
            // Calculate time for this car to reach target
            double timeToTarget = (double)(target - pos) / spd;
            
            // Add current car's time to stack
            stack.push_back(timeToTarget);
            
            // If current car catches up to the car ahead (forms a fleet)
            if (stack.size() >= 2 && stack[stack.size() - 1] <= stack[stack.size() - 2]) {
                // Current car joins the fleet ahead, so remove its separate time
                stack.pop_back();
            }
        }
        
        // Number of elements in stack = number of separate fleets
        return stack.size();
    }
};

/*
=== C++ SYNTAX EXPLANATION FOR BEGINNERS ===

1. int carFleet(int target, vector<int>& position, vector<int>& speed)
   - Function returns an integer (int)
   - Takes three parameters:
     * int target: target position (passed by value)
     * vector<int>& position: reference to vector of positions (no copy made)
     * vector<int>& speed: reference to vector of speeds (no copy made)

2. int n = position.size();
   - Declares integer variable n
   - Initializes it with the size of position vector
   - size() returns the number of elements in the vector

3. vector<pair<int, int>> cars;
   - Declares a vector that stores pairs of integers
   - Each pair will contain [position, speed] for a car
   - pair<int, int> means each element has two integer values

4. for (int i = 0; i < n; i++)
   - Standard for loop iterating from 0 to n-1
   - Declares int i, initializes to 0, continues while i < n, increments i each iteration

5. cars.push_back(make_pair(position[i], speed[i]));
   - push_back(): adds element to the end of vector
   - make_pair(): creates a pair object from two values
   - position[i]: accesses element at index i in position vector

6. sort(cars.begin(), cars.end(), greater<pair<int, int>>());
   - sort(): standard library function to sort elements
   - cars.begin(): iterator pointing to first element
   - cars.end(): iterator pointing to position after last element
   - greater<pair<int, int>>(): comparator for descending order
   - For pairs, comparison is done first by .first, then by .second

7. vector<double> stack;
   - Creates a vector of double (floating-point) values
   - Used as a stack to store arrival times
   - double is used for precise division results

8. int pos = cars[i].first;
   - Accesses the first element of the pair (position)
   - cars[i] gets the i-th pair in the vector
   - .first accesses the first element of the pair

9. int spd = cars[i].second;
   - Accesses the second element of the pair (speed)
   - .second accesses the second element of the pair

10. double timeToTarget = (double)(target - pos) / spd;
    - Calculates time as a double (floating-point number)
    - (double) is a cast that converts integer to double for precise division
    - Without casting, integer division would truncate decimal places

11. stack.push_back(timeToTarget);
    - Adds the calculated time to the end of stack vector
    - push_back() increases the vector size by 1

12. if (stack.size() >= 2 && stack[stack.size() - 1] <= stack[stack.size() - 2])
    - Checks two conditions with AND operator (&&)
    - stack.size() >= 2: ensures at least 2 elements exist
    - stack[stack.size() - 1]: accesses last element (most recent car)
    - stack[stack.size() - 2]: accesses second-to-last element (previous car)
    - Compares arrival times to see if current car catches up

13. stack.pop_back();
    - Removes the last element from the vector
    - Reduces vector size by 1
    - Used when cars form a fleet (merge times)

14. return stack.size();
    - Returns the number of elements in stack as an integer
    - This represents the number of separate car fleets

=== KEY C++ CONCEPTS USED ===

- Vector: Dynamic array with push_back(), pop_back(), size(), [] operations
- Pair: Container holding two values, accessed via .first and .second
- Sort: Algorithm to arrange elements, can use custom comparators
- Iterators: Objects that point to positions in containers (begin(), end())
- Type Casting: Converting between data types using (type) syntax
- References (&): Allow functions to work with original data without copying
- Comparators: Functions/objects that define custom sorting order
- greater<>: Built-in comparator for descending order (opposite of default ascending)

=== ALGORITHM EXPLANATION ===

Why sort by position descending?
- We process cars from closest to target to farthest
- This allows us to determine if a car behind can catch up to a car ahead

Why use arrival time comparison?
- If a car behind has arrival time <= car ahead, it will catch up and form a fleet
- The fleet moves at the speed of the slower (leading) car

Stack behavior:
- Each element represents a separate fleet
- When cars merge into a fleet, we remove the faster car's individual time
- Final stack size = number of distinct fleets reaching the target
*/
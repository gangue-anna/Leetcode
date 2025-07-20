#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Find longest consecutive sequence in array
     * 
     * Approach:
     * - Store numbers in hash set for O(1) lookup
     * - For each number, check if it's start of sequence
     * - If it is (num-1 not in set), count sequence length
     * - Track maximum sequence length found
     * 
     * Time Complexity: O(n) - each number visited at most twice
     * Space Complexity: O(n) - storing all numbers in set
     */
    int longestConsecutive(vector<int>& nums) {
        // Create hash set from input array
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxSize = 0;
        
        // Check each possible sequence
        for (int num : numSet) {
            // Only process numbers that could start a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currSize = 1;
                int currNum = num;
                
                // Count consecutive numbers
                while (numSet.find(currNum + 1) != numSet.end()) {
                    currSize++;
                    currNum++;
                }
                
                maxSize = max(maxSize, currSize);
            }
        }
        
        return maxSize;
    }
};

/*
 * Detailed C++ Syntax Explanation for Beginners:
 * 
 * 1. Header and Namespace:
 *    #include <bits/stdc++.h>    // Include all standard libraries
 *    using namespace std;        // Makes std:: prefix optional
 * 
 * 2. Function Declaration:
 *    int longestConsecutive(     // Return type is integer
 *        vector<int>& nums)      // Takes reference to vector of integers
 * 
 * 3. Set Creation:
 *    unordered_set<int> numSet(nums.begin(), nums.end())
 *    - unordered_set: hash set container
 *    - nums.begin(), nums.end(): iterator range for initialization
 *    - O(1) lookup time
 * 
 * 4. Range-based For Loop:
 *    for (int num : numSet)
 *    - Iterates through each number in set
 *    - int num: creates copy of current element
 * 
 * 5. Set Operations:
 *    numSet.find(num - 1)       // Search for element
 *    numSet.end()               // Iterator to end of set
 *    == comparison checks if element not found
 * 
 * 6. Variables and Scope:
 *    int currSize = 1           // Local variable initialization
 *    int currNum = num          // Copy value to new variable
 * 
 * 7. While Loop:
 *    while (condition)          // Repeat while condition is true
 *    currNum++                  // Increment operator
 * 
 * 8. Standard Library Function:
 *    max(maxSize, currSize)     // Returns larger of two values
 * 
 * Note: This implementation achieves:
 * - O(n) time complexity by visiting each number at most twice
 * - O(n) space complexity for storing the hash set
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Approach 1: HashSet Solution
     * - Use HashSet to track seen numbers
     * - For each number, check if already in set
     * - If found, return true (duplicate exists)
     * - If not found, add to set
     * 
     * Time Complexity: O(n)
     * - Single pass through array
     * - HashSet operations (insert/lookup) are O(1) average
     * 
     * Space Complexity: O(n)
     * - HashSet can store up to n elements
     */
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;
        for (int n : nums){
            if (hashSet.count(n) > 0){
                return true;
            }
            else{
                hashSet.insert(n);
            }
        }
        return false;
    }
};

class Solution2 {
public:
    /*
     * Approach 2: Sorting Solution
     * - Sort array first
     * - Check adjacent elements for duplicates
     * - If adjacent elements match, found duplicate
     * 
     * Time Complexity: O(n log n)
     * - Dominated by sorting operation
     * - Linear scan after sorting is O(n)
     * 
     * Space Complexity: O(1)
     * - Sort is in-place
     * - Only uses constant extra space
     */
    bool hasDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};

/*
 * Detailed Syntax Explanation:
 * 
 * 1. Function Parameters:
 *    bool hasDuplicate(vector<int>& nums)
 *    - Returns boolean (true/false)
 *    - Takes reference to vector of integers
 *    - & prevents copying of vector
 *
 * 2. HashSet Solution:
 *    unordered_set<int> hashSet;
 *    - Creates empty HashSet for integers
 *    - O(1) average time for operations
 *
 *    for (int n : nums)
 *    - Range-based for loop
 *    - Iterates through each element
 *
 *    hashSet.count(n)
 *    - Returns number of occurrences (0 or 1)
 *
 * 3. Sorting Solution:
 *    if (nums.empty())
 *    - Checks for empty vector
 *    - Early return optimization
 *
 *    sort(nums.begin(), nums.end())
 *    - STL sort function
 *    - Takes iterator range
 *    - Modifies vector in-place
 *
 *    nums.size() - 1
 *    - Prevents buffer overflow
 *    - Allows checking adjacent elements
 */
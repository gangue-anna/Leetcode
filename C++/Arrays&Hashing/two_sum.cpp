#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Find two numbers in array that sum to target
     * 
     * Approach:
     * 1. Use hash map to store numbers and their indices
     * 2. For each number x, check if (target - x) exists in map
     * 3. If found, return current index and stored index
     * 4. If not found, add current number and index to map
     * 
     * Time Complexity: O(n)
     * - Single pass through array
     * - Hash map operations (insert/lookup) are O(1) average
     * 
     * Space Complexity: O(n)
     * - Hash map stores at most n elements
     * - Each element stores number and its index
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (umap.find(diff) != umap.end()) {
                return {umap[diff], i};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};
/*
 * Detailed C++ Syntax Explanation for Beginners:
 * 
 * 1. Header and Namespace:
 *    #include <bits/stdc++.h>   // Includes all standard libraries
 *    using namespace std;       // Makes std:: prefix optional
 * 
 * 2. Class Declaration:
 *    class Solution {          // Defines a class named Solution
 *    public:                   // Makes members accessible from outside
 * 
 * 3. Function Declaration:
 *    vector<int>              // Return type: vector of integers
 *    twoSum(                  // Function name
 *        vector<int>& nums,   // Reference to input array
 *        int target)          // Target sum value
 * 
 * 4. Hash Map Usage:
 *    unordered_map<int, int>  // Key: number, Value: index
 *    umap                     // Variable name for hash map
 * 
 * 5. Loop Syntax:
 *    for (int i = 0; i < nums.size(); i++)
 *    - int i = 0;            // Initialize counter
 *    - i < nums.size();      // Continue while less than array size
 *    - i++                   // Increment counter
 * 
 * 6. Hash Map Operations:
 *    umap.find(diff)         // Searches for key 'diff'
 *    umap.end()             // Returns iterator to end of map
 *    umap[nums[i]] = i      // Assigns value i to key nums[i]
 * 
 * 7. Return Statements:
 *    return {umap[diff], i}  // Returns initializer list as vector
 *    return {};             // Returns empty vector
 */

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> valIndex;
        for (int i = 0; i < nums.size(); i++){
            valIndex.push_back({nums[i], i});
        }

        sort(valIndex.begin(), valIndex.end());

        int start = 0;
        int end = valIndex.size() - 1;
        while(start < end){
            int sum = valIndex[start].first + valIndex[end].first;
            if(sum == target){
                int i1 = min(valIndex[start].second, valIndex[end].second);
                int i2 = max(valIndex[start].second, valIndex[end].second);
                return {i1, i2};
            }
            else if(sum > target){
                end--;
            }
            else{
                start++;
            }
        }

    }
};

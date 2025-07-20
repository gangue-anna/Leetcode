#include <bits/stdc++.h>
using namespace std;   

class Solution {
public:
    /*
     * Problem: Find all unique triplets that sum to zero
     * 
     * Approach:
     * 1. Sort array to handle duplicates and use two pointers
     * 2. Fix first number, use two pointers for remaining two
     * 3. Skip duplicates to avoid duplicate triplets
     * 
     * Time: O(n^2) - n iterations with two pointers
     * Space: O(1) - not counting output array
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Sort array to handle duplicates and use two pointers
        sort(nums.begin(), nums.end());
        
        // Fix first element of triplet
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicates for first number
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            // Use two pointers for remaining elements
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum > 0) {
                    right--;  // Need smaller sum
                }
                else if (sum < 0) {
                    left++;   // Need larger sum
                }
                else {
                    // Found valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    
                    // Skip duplicates for second number
                    while (left < right && nums[left] == nums[left-1]) {
                        left++;
                    }
                }
            }
        }
        
        return result;
    }
};

/*
 * Detailed C++ Syntax Explanation:
 * 
 * 1. Vector Operations:
 *    vector<vector<int>>  // 2D vector for storing triplets
 *    nums.size()          // Get array length
 *    sort(nums.begin(), nums.end())  // Sort array
 * 
 * 2. Two Pointers:
 *    int left = i + 1    // Start after current number
 *    int right = nums.size() - 1  // End of array
 * 
 * 3. Vector Methods:
 *    result.push_back({a, b, c})  // Add triplet to result
 *    
 * 4. Duplicate Handling:
 *    nums[i] == nums[i-1]  // Check for duplicates
 *    while (left < right && nums[left] == nums[left-1])
 */

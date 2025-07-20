#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Problem: Find the k most frequent elements in array
     * 
     * Approach:
     * 1. Count frequencies using hash map
     * 2. Convert to vector of pairs (frequency, number)
     * 3. Sort pairs by frequency in descending order
     * 4. Return first k numbers
     * 
     * Time Complexity: O(n log n)
     * - n for counting frequencies O(n)
     * - Converting to vector O(n)
     * - Sorting vector O(n log n)
     * - Extracting k elements O(k)
     * Overall: O(n log n) dominated by sort
     * 
     * Space Complexity: O(n)
     * - Hash map stores at most n elements
     * - Vector of pairs stores at most n pairs
     * - Result vector stores k elements
     */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count frequencies using hash map
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Convert to vector of pairs for sorting
        vector<pair<int, int>> freqVec;
        for (const auto& entry : freq) {
            freqVec.push_back({entry.second, entry.first});
        }
        
        // Sort by frequency in descending order
        sort(freqVec.begin(), freqVec.end(), greater<pair<int, int>>());
        
        // Get top k elements
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqVec[i].second);
        }
        
        return result;
    }
};

/*
 * Detailed Syntax Explanation:
 * 
 * 1. Function Declaration:
 *    vector<int> topKFrequent(vector<int>& nums, int k)
 *    - Returns vector of k most frequent integers
 *    - Takes reference to input array and k value
 *    - & prevents copying of input vector
 * 
 * 2. Frequency Counting:
 *    unordered_map<int, int> freq;
 *    - Key: number from array
 *    - Value: its frequency count
 *    - O(1) average lookup/insert
 *    freq[num]++
 *    - Increment count for each number
 * 
 * 3. Pair Vector Creation:
 *    vector<pair<int, int>> freqVec;
 *    - Stores {frequency, number} pairs
 *    - First element is frequency for sorting
 *    freqVec.push_back({entry.second, entry.first})
 *    - Creates pair with frequency first
 * 
 * 4. Sorting:
 *    sort(freqVec.begin(), freqVec.end(), greater<pair<int,int>>())
 *    - STL sort with custom comparator
 *    - greater<> sorts in descending order
 *    - Compares first elements (frequencies)
 * 
 * 5. Result Collection:
 *    vector<int> result;
 *    - Stores k most frequent numbers
 *    result.push_back(freqVec[i].second)
 *    - second gives the number (not frequency)
 */
 

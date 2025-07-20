#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Simulate the process of smashing stones.
     * Approach:
     * - Use a max-heap (priority_queue) to always get the two largest stones.
     * - Pop the two heaviest stones, smash them:
     *      - If they are not equal, push the difference back into the heap.
     *      - If equal, both are destroyed.
     * - Repeat until at most one stone remains.
     * - Return the weight of the last stone or 0 if none remain.
     * 
     * Time Complexity: O(n log n) (heap operations per stone)
     * Space Complexity: O(n) (heap of stones)
     */
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        // Push all stones into the max-heap
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        // Smash stones until at most one remains
        while (maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();

            int second = maxHeap.top();
            maxHeap.pop();

            if (first != second) {
                maxHeap.push(first - second);
            }
            // If equal, both stones are destroyed (do nothing)
        }

        // If one stone remains, return its weight; otherwise return 0
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers (e.g., vector, queue, etc.).

using namespace std;
    ✅ Allows use of standard library names without the std:: prefix.

class Solution { ... }
    ✅ Defines the Solution class.

public:
    ✅ Section where public methods are declared/defined.

int lastStoneWeight(vector<int>& stones)
    ✅ Method that takes a reference to a vector of integers and returns an int.

priority_queue<int> maxHeap;
    ✅ Declares a max-heap (default in C++) to store the stones.

for (int stone : stones) maxHeap.push(stone);
    ✅ Push each stone into the max-heap.

while (maxHeap.size() > 1)
    ✅ Continue while more than one stone remains.

int first = maxHeap.top(); maxHeap.pop();
    ✅ Get the largest stone and remove it.

int second = maxHeap.top(); maxHeap.pop();
    ✅ Get the second largest stone and remove it.

if (first != second) maxHeap.push(first - second);
    ✅ If stones are unequal, push their difference back.

return maxHeap.empty() ? 0 : maxHeap.top();
    ✅ If heap is empty, return 0; otherwise, return last stone.

*/

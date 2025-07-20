#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Finds the kth largest element in an array using a min-heap of size k.
     *
     * Approach:
     * - Maintain a min-heap of size k.
     * - Iterate through the array, pushing each element into the heap.
     * - If the heap size exceeds k, remove the smallest element.
     * - At the end, the root of the min-heap is the kth largest element.
     *
     * Time Complexity: O(n log k), where n is the number of elements in nums.
     * Space Complexity: O(k), the size of the heap.
     */
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to store the k largest elements seen so far
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num); // push the current number into the heap

            // If heap size > k, remove the smallest element
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // The root of the min-heap is the kth largest element
        return minHeap.top();
    }
};

/*
---------------------- LINE-BY-LINE SYNTAX EXPLANATION ----------------------

#include <bits/stdc++.h>
    ✅ Includes all common C++ headers in one line (vector, queue, etc.)

using namespace std;
    ✅ Avoids writing std:: repeatedly before vector, cout, etc.

class Solution { ... }
    ✅ Defines a class named Solution.

public:
    ✅ Marks the section as public so that the method can be accessed externally.

int findKthLargest(vector<int>& nums, int k)
    ✅ Function returns an integer, takes reference to a vector of integers `nums` and an integer `k`.

priority_queue<int, vector<int>, greater<int>> minHeap;
    ✅ Declares a min-heap (priority_queue by default is max-heap).
    ✅ We specify `greater<int>` as the comparator to make it a min-heap.

for (int num : nums)
    ✅ Range-based for loop: iterates over each element of `nums`.

minHeap.push(num);
    ✅ Adds `num` to the heap.

if (minHeap.size() > k) minHeap.pop();
    ✅ If the heap has more than k elements, remove the smallest (root) element.

return minHeap.top();
    ✅ The smallest element in the heap (root) is the kth largest in the array.

*/

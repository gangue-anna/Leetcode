#include <bits/stdc++.h>
using namespace std;

/**
 * MedianFinder:
 * Supports adding numbers from a stream and finding the median efficiently.
 *
 * Approach:
 * - Use two heaps:
 *   - maxHeap (smaller half): a max-heap using priority_queue<int>
 *   - minHeap (larger half): a min-heap using priority_queue<int, vector<int>, greater<int>>
 * - Invariant:
 *   - All elements in maxHeap ≤ all elements in minHeap
 *   - The size difference of the heaps is at most 1
 * - Median:
 *   - If odd total elements: median = top of larger heap
 *   - If even: median = average of tops of both heaps
 *
 * Time Complexity:
 * - addNum: O(log n) (heap push/pop)
 * - findMedian: O(1)
 *
 * Space Complexity:
 * - O(n) to store all numbers
 */

class MedianFinder {
    priority_queue<int> maxHeap; // max-heap (stores smaller half)
    priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap (stores larger half)

public:
    MedianFinder() {
        // Constructor: nothing to initialize explicitly
    }

    void addNum(int num) {
        // Always push to maxHeap first
        maxHeap.push(num);

        // Ensure the maxHeap's largest ≤ minHeap's smallest
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int val = maxHeap.top(); maxHeap.pop();
            minHeap.push(val);
        }

        // Balance the sizes: maxHeap can have at most 1 more than minHeap
        if (maxHeap.size() > minHeap.size() + 1) {
            int val = maxHeap.top(); maxHeap.pop();
            minHeap.push(val);
        }

        if (minHeap.size() > maxHeap.size() + 1) {
            int val = minHeap.top(); minHeap.pop();
            maxHeap.push(val);
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        if (minHeap.size() > maxHeap.size()) {
            return minHeap.top();
        }

        // If equal, return average of two middle numbers
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/*
-----------------------------------------------
📄 Line-by-Line C++ Syntax Explanation:
-----------------------------------------------

#include <bits/stdc++.h>
    → Includes all standard C++ headers.

using namespace std;
    → Avoids writing std:: everywhere.

class MedianFinder { ... };
    → Defines the MedianFinder class.

priority_queue<int> maxHeap;
    → A max-heap storing the smaller half of numbers.

priority_queue<int, vector<int>, greater<int>> minHeap;
    → A min-heap storing the larger half of numbers.

MedianFinder() { ... }
    → Constructor of the class, runs when you create an object.

void addNum(int num) { ... }
    → Method to add a number into the data structure.

maxHeap.push(num);
    → Push `num` into the maxHeap.

if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) { ... }
    → Ensures the two halves are properly ordered.

int val = maxHeap.top(); maxHeap.pop();
    → Extract the largest element from maxHeap.

minHeap.push(val);
    → Push that element into minHeap.

if (maxHeap.size() > minHeap.size() + 1) { ... }
    → Balance the heaps if maxHeap has more than one extra element.

double findMedian() { ... }
    → Method to compute and return the median of all numbers added so far.

if (maxHeap.size() > minHeap.size())
    → If maxHeap has more elements, its top is the median.

if (minHeap.size() > maxHeap.size())
    → If minHeap has more elements, its top is the median.

return (maxHeap.top() + minHeap.top()) / 2.0;
    → If both have equal elements, average of tops of both is the median.

-----------------------------------------------
⏱ Time & Space:
- addNum: O(log n)
- findMedian: O(1)
- Space: O(n) (all numbers stored in heaps)
-----------------------------------------------
*/

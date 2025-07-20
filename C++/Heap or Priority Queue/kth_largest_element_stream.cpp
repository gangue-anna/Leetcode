#include <bits/stdc++.h>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap
    int k;

public:
    /**
     * Constructor
     * Initializes the KthLargest object with an integer k and a stream of integers nums.
     * Time: O(n log k) — inserting n elements into a heap of size at most k.
     * Space: O(k) — heap stores at most k elements.
     */
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            minHeap.push(num);               // push all elements
            if (minHeap.size() > k) {
                minHeap.pop();              // maintain only k largest
            }
        }
    }

    /**
     * Adds an integer val to the stream and returns the k-th largest element.
     * Time: O(log k) — one push + one optional pop.
     * Space: O(k) — heap size stays at most k.
     */
    int add(int val) {
        minHeap.push(val);

        if (minHeap.size() > k) {
            minHeap.pop();                 // remove smallest if heap size > k
        }

        return minHeap.top();             // the k-th largest element
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers (e.g., vector, queue, etc.).

using namespace std;
    ✅ Allows usage of standard library names without prefixing std::.

class KthLargest { ... }
    ✅ Defines the KthLargest class.

private:
    ✅ Section for private members (accessible only within the class).

priority_queue<int, vector<int>, greater<int>> minHeap;
    ✅ Declares a min-heap (priority queue with smallest at top) using greater<int>.

int k;
    ✅ Stores the k value.

public:
    ✅ Section for public methods (accessible outside the class).

KthLargest(int k, vector<int>& nums)
    ✅ Constructor with two parameters: an int k and reference to a vector of ints.

this->k = k;
    ✅ Sets the class member k to the given k.

for (int num : nums)
    ✅ Range-based for loop iterates through nums vector.

minHeap.push(num);
    ✅ Inserts num into the minHeap.

if (minHeap.size() > k) minHeap.pop();
    ✅ If heap size exceeds k, remove smallest element.

int add(int val)
    ✅ Method that adds val to the stream and returns the k-th largest.

minHeap.push(val);
    ✅ Insert val into the heap.

if (minHeap.size() > k) minHeap.pop();
    ✅ Maintain heap size at most k.

return minHeap.top();
    ✅ Return smallest in heap, which is k-th largest overall.

*/

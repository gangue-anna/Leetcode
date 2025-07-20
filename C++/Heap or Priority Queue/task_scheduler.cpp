#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Finds the least number of time units to finish all tasks with cooldown n.
     *
     * Approach:
     * - Use a max-heap to always select the task with the highest frequency.
     * - Use a queue to keep track of tasks in their cooldown period along with the time they become available again.
     * - At each time unit, either execute a task from the heap or stay idle.
     * - When a task's cooldown is over, push it back to the heap if it still has remaining count.
     *
     * Time Complexity: O(N), where N is the number of tasks.
     * Space Complexity: O(1), because there are at most 26 different tasks.
     */
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count; 
        for (char task : tasks) {
            count[task]++; // count frequency of each task
        }

        // Max-heap to store task frequencies (negated to simulate max-heap in C++)
        priority_queue<int> maxHeap;
        for (auto& it : count) {
            maxHeap.push(it.second);
        }

        queue<pair<int, int>> q; // queue of {remaining count, available_time}

        int time = 0;

        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int cnt = maxHeap.top() - 1; // execute the task, decrease its count
                maxHeap.pop();

                if (cnt > 0) {
                    q.push({cnt, time + n}); // put it in cooldown if it still needs to run
                }
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};

/*
---------------------- LINE-BY-LINE SYNTAX EXPLANATION ----------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ headers (vector, queue, unordered_map, etc.)

using namespace std;
    ✅ So we don’t have to write std:: repeatedly.

class Solution { ... }
    ✅ Defines a class named Solution.

public:
    ✅ Makes the following methods accessible from outside the class.

int leastInterval(vector<char>& tasks, int n)
    ✅ Function that takes a vector of characters (task names) and an integer n.

unordered_map<char, int> count;
    ✅ Hash map to store the count of each task.

for (char task : tasks) { count[task]++; }
    ✅ Count the frequency of each task.

priority_queue<int> maxHeap;
    ✅ Max-heap that stores task counts.

for (auto& [task, cnt] : count) { maxHeap.push(cnt); }
    ✅ Push each task count into the maxHeap.

queue<pair<int, int>> q;
    ✅ Queue to store tasks in cooldown along with the time they become available.

int time = 0;
    ✅ Time counter.

while (!maxHeap.empty() || !q.empty()) { ... }
    ✅ Loop until both the heap and queue are empty.

time++;
    ✅ Increment time unit.

if (!maxHeap.empty()) { ... }
    ✅ If there is a task available, run it.

int cnt = maxHeap.top() - 1; maxHeap.pop();
    ✅ Run task and decrement count.

if (cnt > 0) q.push({cnt, time + n});
    ✅ If the task still has remaining executions, push it into cooldown queue.

if (!q.empty() && q.front().second == time) { ... }
    ✅ If a task's cooldown has finished, re-add it to the heap.

return time;
    ✅ Return the total time taken.
*/

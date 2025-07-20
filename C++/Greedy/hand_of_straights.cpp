#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Function to determine if the hand can be rearranged into groups of consecutive cards of given size.
     *
     * Approach:
     * - If total cards % groupSize != 0 → not possible.
     * - Count frequencies of all cards using a map.
     * - Push all unique cards into a min-heap (priority_queue with greater<int>).
     * - While the heap is not empty:
     *   - Get the smallest card (top of heap).
     *   - Try to form a group of consecutive cards starting from smallest.
     *   - For each card in the group:
     *       - If card is missing → return false.
     *       - Decrease its count.
     *       - If its count becomes 0 and it is at the top of heap → pop it.
     *       - If its count becomes 0 but it's NOT at the top → invalid → return false.
     *
     * Time Complexity: O(N log N) — building and maintaining the heap.
     * Space Complexity: O(N) — map + heap.
     */
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> count; // stores frequency of each card
        for (int n : hand)
            count[n]++;

        priority_queue<int, vector<int>, greater<int>> minH;
        for (const auto& p : count) {
            minH.push(p.first);
        }

        while (!minH.empty()) {
            int first = minH.top(); // smallest available card

            for (int i = first; i < first + groupSize; ++i) {
                if (count.find(i) == count.end()) // card missing
                    return false;

                count[i]--;
                if (count[i] == 0) {
                    if (i != minH.top()) // if not at top, invalid
                        return false;
                    minH.pop(); // remove card from heap
                }
            }
        }

        return true;
    }
};

/*
====================================================
Line-by-line C++ syntax explanation:
====================================================

#include <bits/stdc++.h>
    -> Includes all standard C++ libraries (like <vector>, <map>, <queue>, <iostream>, etc.)

using namespace std;
    -> Allows using standard library names without std:: prefix.

class Solution {
public:
    -> Defines a class named Solution with public member functions.

bool isNStraightHand(vector<int>& hand, int groupSize) {
    -> Defines a method `isNStraightHand` that takes a vector of integers & an int, returns bool.

if (hand.size() % groupSize != 0)
    return false;
    -> If total cards is not divisible by groupSize, return false.

map<int, int> count;
    -> A map to store counts of each card.

for (int n : hand)
    count[n]++;
    -> Count frequency of each card in the hand.

priority_queue<int, vector<int>, greater<int>> minH;
    -> Min-heap (priority_queue with smallest element at top).

for (auto& [num, _] : count)
    minH.push(num);
    -> Push all unique cards into the min-heap.

while (!minH.empty()) {
    -> Loop until heap is empty.

int first = minH.top();
    -> Get smallest available card.

for (int i = first; i < first + groupSize; ++i) {
    -> Try to form a consecutive sequence starting from `first`.

if (count.find(i) == count.end())
    return false;
    -> If any card in the sequence is missing, return false.

count[i]--;
    -> Decrease count of current card.

if (count[i] == 0) {
    -> If count of card becomes zero

if (i != minH.top())
    return false;
    -> If zero count card is not at top of heap → invalid.

minH.pop();
    -> Remove the card from the heap.
}

return true;
    -> If all groups formed successfully, return true.

====================================================
Time Complexity:
    - O(N log N): Building the heap and processing cards.

Space Complexity:
    - O(N): To store the map and the heap.
====================================================
*/


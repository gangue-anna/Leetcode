#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        /*
        Approach:
        - Build a graph (adjacency list) where each character points to characters that must come after it.
        - Compare adjacent words: find the first differing character and add an edge.
        - Detect invalid case: when a longer word comes before its prefix.
        - Perform DFS-based topological sort to get character order.
        - Detect cycles (invalid ordering) during DFS.
        
        Time Complexity: O(N + K + E)
            - N = total number of characters in all words
            - K = number of unique characters
            - E = number of edges (<= K^2)
            - Build graph: O(N)
            - Topological sort: O(K + E)

        Space Complexity: O(K + E)
            - For graph, visited map, result, and recursion stack.
        */

        unordered_map<char, unordered_set<char>> adj;  // adjacency list
        unordered_map<char, int> visit;  // 0 = unvisited, 1 = visiting, 2 = visited
        string res;

        // Create nodes for all unique characters
        for (string& w : words) {
            for (char c : w) {
                adj[c]; // ensures node exists
            }
        }

        // Build edges from adjacent words
        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i], w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());
            if (w1.size() > w2.size() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return ""; // invalid prefix case
            }

            for (int j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]); // w1[j] < w2[j]
                    break;
                }
            }
        }

        // DFS function
        function<bool(char)> dfs = [&](char c) {
            if (visit[c] == 1) return true;  // cycle detected
            if (visit[c] == 2) return false; // already visited
            
            visit[c] = 1; // mark as visiting

            for (char nei : adj[c]) {
                if (dfs(nei)) return true;
            }

            visit[c] = 2; // mark as visited
            res.push_back(c);
            return false;
        };

        // Run DFS for all nodes
        for (auto& p : adj) {
            char c = p.first;
            if (!visit[c]) {
                if (dfs(c)) return ""; // cycle detected
            }
        }

        reverse(res.begin(), res.end()); // reverse to get correct order
        return res;
    }
};

/*
================== LINE BY LINE EXPLANATION ==================

#include <bits/stdc++.h>
- Includes all standard C++ libraries.

using namespace std;
- Avoids writing std:: repeatedly.

class Solution {
- Defines the Solution class.

string foreignDictionary(vector<string>& words) {
- Function to find the alien dictionary order.

unordered_map<char, unordered_set<char>> adj;
- Graph: maps each char to a set of chars that must come after it.

unordered_map<char, int> visit;
- Track state of each node: 0 = unvisited, 1 = visiting, 2 = visited.

string res;
- To store the final order of characters.

for (string& w : words) { for (char c : w) adj[c]; }
- Ensures all unique characters appear as nodes in graph.

for (int i = 0; i < words.size()-1; ++i) {
- Compare adjacent word pairs.

if (w1.size() > w2.size() && w1.substr(0, minLen) == w2.substr(0, minLen))
- If longer word comes before its prefix: invalid case.

if (w1[j] != w2[j]) { adj[w1[j]].insert(w2[j]); break; }
- Add edge w1[j] → w2[j] for first differing char.

function<bool(char)> dfs = [&](char c) {
- Lambda for DFS traversal to detect cycles and perform topo sort.

if (visit[c] == 1) return true;
- If currently visiting this node: cycle detected.

if (visit[c] == 2) return false;
- If already fully processed: skip.

visit[c] = 1;
- Mark as visiting.

for (char nei : adj[c]) { if (dfs(nei)) return true; }
- Visit all neighbors recursively.

visit[c] = 2;
- Mark as fully processed.

res.push_back(c);
- Add to result after processing all neighbors.

for (auto& [c, _] : adj) {
- Run DFS for all unvisited nodes.

if (dfs(c)) return "";
- If cycle detected, return empty string.

reverse(res.begin(), res.end());
- Reverse the result to get the correct order.

return res;
- Return final string.

================================================================
*/


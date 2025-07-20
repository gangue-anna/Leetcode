#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Approach:
     * - Use BFS to find the shortest transformation sequence from beginWord to endWord
     * - Preprocess the word list to create a mapping from generic patterns (with one letter replaced by '*') to words
     * - For each word, try all possible one-letter transformations and enqueue valid neighboring words
     * - Return the length of the shortest path if found, otherwise return 0
     * - BFS guarantees we find the shortest path since all edges have weight 1
     * 
     * Time Complexity: O(N * M^2), where N is number of words and M is length of each word
     *   - N words to process, for each word we create M patterns, each pattern creation takes O(M) time
     * Space Complexity: O(N * M) for the pattern mapping and visited set
     *   - Pattern mapping stores N*M entries, visited set stores up to N words
     */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Check if endWord exists in wordList - if not, transformation is impossible
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        
        // Create adjacency list using pattern mapping
        // Key: pattern with '*' (e.g., "h*t"), Value: list of words matching pattern
        unordered_map<string, vector<string>> neighbors;
        
        // Add beginWord to wordList for preprocessing
        wordList.push_back(beginWord);
        
        // Preprocess all words to create pattern mappings
        for (const string& word : wordList) {
            for (int j = 0; j < word.length(); j++) {
                // Create pattern by replacing character at position j with '*'
                string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                neighbors[pattern].push_back(word);
            }
        }
        
        // Initialize BFS components
        unordered_set<string> visited;    // Track visited words to avoid cycles
        queue<string> q;                  // BFS queue
        
        // Start BFS from beginWord
        visited.insert(beginWord);
        q.push(beginWord);
        int result = 1;  // Length starts at 1 (including beginWord)
        
        // BFS traversal
        while (!q.empty()) {
            int queueSize = q.size();
            
            // Process all words at current level
            for (int i = 0; i < queueSize; i++) {
                string currentWord = q.front();
                q.pop();
                
                // Check if we reached the target
                if (currentWord == endWord) {
                    return result;
                }
                
                // Try all possible one-letter transformations
                for (int j = 0; j < currentWord.length(); j++) {
                    // Create pattern for current position
                    string pattern = currentWord.substr(0, j) + "*" + currentWord.substr(j + 1);
                    
                    // Explore all words that match this pattern
                    for (const string& neighborWord : neighbors[pattern]) {
                        // If not visited, add to queue and mark as visited
                        if (visited.find(neighborWord) == visited.end()) {
                            visited.insert(neighborWord);
                            q.push(neighborWord);
                        }
                    }
                }
            }
            
            // Increment level/distance for next iteration
            result++;
        }
        
        // No path found to endWord
        return 0;
    }
};

/*
LINE BY LINE SYNTAX EXPLANATION FOR C++ BEGINNERS:

1. #include <bits/stdc++.h>
   - Non-standard header that includes most C++ standard library components
   - Includes vector, string, queue, unordered_map, unordered_set, algorithm, etc.

2. using namespace std;
   - Allows using standard library without "std::" prefix
   - So we can write "string" instead of "std::string"

3. class Solution {
   - Declares a class named "Solution"
   - Classes group related data and functions together

4. public:
   - Access specifier - members following this can be accessed from outside the class

5. int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
   - Function that returns an integer
   - Parameters: two strings by value, one vector of strings by reference
   - & means pass by reference (avoids copying, allows modification)

6. if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
   - find() searches for endWord in the range [wordList.begin(), wordList.end())
   - Returns iterator to element if found, or wordList.end() if not found
   - == checks if the returned iterator equals end() (meaning not found)

7. return 0;
   - Returns integer value 0 to the caller
   - Used when transformation is impossible

8. unordered_map<string, vector<string>> neighbors;
   - Declares hash map with string keys and vector<string> values
   - unordered_map provides average O(1) lookup time
   - Similar to Python's defaultdict(list)

9. wordList.push_back(beginWord);
   - Adds beginWord to the end of wordList vector
   - push_back() is the method to append elements to vectors

10. for (const string& word : wordList) {
    - Range-based for loop iterating over each string in wordList
    - const string& means we get a constant reference (can't modify, no copying)

11. for (int j = 0; j < word.length(); j++) {
    - Traditional for loop with integer counter j
    - word.length() returns the number of characters in the string
    - < means "less than"

12. string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
    - substr(start, length) extracts substring starting at position 'start'
    - word.substr(0, j) gets characters from position 0 to j-1
    - word.substr(j + 1) gets characters from position j+1 to end
    - + operator concatenates strings

13. neighbors[pattern].push_back(word);
    - Access vector associated with 'pattern' key in the map
    - If key doesn't exist, it's automatically created with empty vector
    - push_back() adds 'word' to that vector

14. unordered_set<string> visited;
    - Declares hash set to store strings
    - unordered_set provides average O(1) insertion and lookup
    - Similar to Python's set()

15. queue<string> q;
    - Declares a queue that holds strings
    - Queue is FIFO (First In, First Out) data structure
    - Used for BFS traversal

16. visited.insert(beginWord);
    - Adds beginWord to the visited set
    - insert() is the method to add elements to sets

17. q.push(beginWord);
    - Adds beginWord to the back of the queue
    - push() adds elements to queue

18. int result = 1;
    - Declares integer variable and initializes it to 1
    - Represents the current path length

19. while (!q.empty()) {
    - Loop continues while queue is not empty
    - ! is logical NOT operator
    - empty() returns true if queue has no elements

20. int queueSize = q.size();
    - Gets current number of elements in queue
    - size() returns the number of elements

21. string currentWord = q.front();
    - Gets reference to the first element in queue (without removing)
    - front() accesses the first element

22. q.pop();
    - Removes the first element from the queue
    - pop() removes elements from queue (doesn't return the element)

23. if (currentWord == endWord) {
    - Compares two strings for equality
    - == is the equality operator for strings

24. for (const string& neighborWord : neighbors[pattern]) {
    - Range-based for loop over vector of strings
    - neighbors[pattern] accesses the vector associated with 'pattern' key

25. if (visited.find(neighborWord) == visited.end()) {
    - find() searches for neighborWord in the visited set
    - Returns iterator to element if found, or end() if not found
    - Checks if the word hasn't been visited yet

26. visited.insert(neighborWord);
    - Adds neighborWord to the visited set

27. result++;
    - Increments result by 1
    - Equivalent to: result = result + 1

KEY C++ CONCEPTS USED:
- string: Sequence of characters with many built-in methods
- vector<type>: Dynamic arrays that can resize
- unordered_map<key, value>: Hash table for key-value pairs
- unordered_set<type>: Hash table for unique elements
- queue<type>: FIFO (First In, First Out) container
- Range-based for loops: for (const auto& item : container)
- References (&): Direct access without copying
- Iterators: Objects that point to elements in containers
- substr(): Method to extract substrings
- String concatenation with + operator
*/
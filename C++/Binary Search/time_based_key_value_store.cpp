#include <bits/stdc++.h>
using namespace std;

class TimeMap {
private:
    /*
     * Data Structure Design:
     * - Use unordered_map for O(1) average key lookup
     * - Key: string (the key for storage)
     * - Value: vector of pairs, where each pair contains [value, timestamp]
     * - The vector maintains chronological order (timestamps are always increasing)
     */
    unordered_map<string, vector<pair<string, int>>> store;
    
public:
    /*
     * Constructor: Initialize the TimeMap
     * Creates an empty hash map to store key-value-timestamp mappings
     * Time Complexity: O(1)
     * Space Complexity: O(1) initially, grows to O(n) where n is total number of set operations
     */
    TimeMap() {
        // Constructor body is empty as unordered_map initializes itself
        // store is automatically initialized as an empty hash map
    }
    
    /*
     * Set Operation: Store a key-value pair with a timestamp
     * 
     * Approach:
     * 1. Check if key exists in the map
     * 2. If not, create a new vector for this key
     * 3. Append [value, timestamp] pair to the vector
     * 
     * Important: Timestamps are guaranteed to be strictly increasing for each key,
     * so we can simply append without sorting
     * 
     * Time Complexity: O(1) average case for hash map operations
     * Space Complexity: O(1) per operation, O(n) total for n operations
     */
    void set(string key, string value, int timestamp) {
        // Access or create vector for this key and append the new pair
        // If key doesn't exist, unordered_map creates empty vector automatically
        store[key].push_back({value, timestamp});
        // Note: {value, timestamp} is C++11 brace initialization for pair
    }
    
    /*
     * Get Operation: Retrieve value for a key at a specific timestamp
     * 
     * Approach:
     * 1. Check if key exists and has values
     * 2. Use binary search to find the largest timestamp <= target timestamp
     * 3. Return corresponding value, or empty string if no valid timestamp found
     * 
     * Binary Search Logic:
     * - We want the rightmost position where timestamp <= target
     * - If current timestamp <= target: update result and search right for better match
     * - If current timestamp > target: search left for smaller timestamp
     * 
     * Time Complexity: O(log m) where m is number of values for the given key
     * Space Complexity: O(1) excluding input/output
     */
    string get(string key, int timestamp) {
        // Check if key exists in the map
        if (store.find(key) == store.end()) {
            return ""; // Key doesn't exist
        }
        
        // Get reference to the vector of [value, timestamp] pairs
        vector<pair<string, int>>& values = store[key];
        
        // Check if vector is empty (shouldn't happen in normal cases)
        if (values.empty()) {
            return "";
        }
        
        string res = ""; // Result to return
        int l = 0, r = values.size() - 1; // Binary search boundaries
        
        // Binary search for the largest timestamp <= target timestamp
        while (l <= r) {
            int m = l + (r - l) / 2; // Calculate middle index (overflow-safe)
            
            // Access the timestamp of middle element
            // values[m] is a pair<string, int>, values[m].second is the timestamp
            if (values[m].second <= timestamp) {
                // Current timestamp is valid (less than or equal to target)
                // Update result with current value and search for potentially better match on right
                res = values[m].first; // values[m].first is the value string
                l = m + 1; // Search right half for larger valid timestamp
            } else {
                // Current timestamp is too large, search left half
                r = m - 1;
            }
        }
        
        return res; // Return the best match found, or "" if no valid timestamp
    }
};

/*
 * DETAILED C++ SYNTAX EXPLANATION FOR BEGINNERS:
 * 
 * Line 1: #include <bits/stdc++.h>
 * - Includes all standard C++ libraries (non-standard header, convenient for competitive programming)
 * - Includes <unordered_map>, <vector>, <string>, <utility> (for pair), etc.
 * 
 * Line 2: using namespace std;
 * - Allows using standard library components without "std::" prefix
 * - Can write "string" instead of "std::string", "vector" instead of "std::vector"
 * 
 * Line 4: class TimeMap {
 * - Declares a class named TimeMap
 * - Classes encapsulate data (member variables) and functions (member methods)
 * 
 * Line 5: private:
 * - Access specifier: members declared after this are only accessible within the class
 * - Good practice to keep internal data private to maintain encapsulation
 * 
 * Line 12: unordered_map<string, vector<pair<string, int>>> store;
 * - "unordered_map" is a hash table (like Python's dict)
 * - Template syntax: <KeyType, ValueType>
 * - Key type: string
 * - Value type: vector<pair<string, int>>
 * - "pair<string, int>" represents a pair of (value_string, timestamp_int)
 * - "vector" is a dynamic array that can grow/shrink
 * 
 * Line 14: public:
 * - Access specifier: following members are accessible from outside the class
 * - Constructor and methods need to be public to be called by users
 * 
 * Line 21: TimeMap() {
 * - Constructor: special function called when TimeMap object is created
 * - Same name as class, no return type
 * - Empty body because member variables initialize themselves
 * 
 * Line 35: void set(string key, string value, int timestamp) {
 * - "void" return type means function doesn't return anything
 * - Parameters: key (string), value (string), timestamp (integer)
 * - Note: passing strings by value (copying), could be optimized with const string&
 * 
 * Line 39: store[key].push_back({value, timestamp});
 * - "store[key]" accesses the vector associated with key
 * - If key doesn't exist, unordered_map creates empty vector automatically
 * - "push_back()" adds element to end of vector
 * - "{value, timestamp}" is brace initialization creating a pair
 * - Equivalent to: pair<string, int>(value, timestamp)
 * 
 * Line 54: string get(string key, int timestamp) {
 * - Function returns a string
 * - "string" is C++ standard string class (like Python str)
 * 
 * Line 56: if (store.find(key) == store.end()) {
 * - "store.find(key)" searches for key in hash map
 * - Returns iterator pointing to element if found, or store.end() if not found
 * - "store.end()" represents "past-the-end" position (not a valid element)
 * - "==" compares iterators to check if key was found
 * 
 * Line 61: vector<pair<string, int>>& values = store[key];
 * - Declares reference to the vector stored at store[key]
 * - "&" makes it a reference (alias), not a copy
 * - Reference avoids copying the entire vector, making it efficient
 * - "pair<string, int>" is template specialization for string-int pairs
 * 
 * Line 64: if (values.empty()) {
 * - "empty()" is vector method that returns true if vector has no elements
 * - Returns boolean: true if size is 0, false otherwise
 * 
 * Line 68: string res = "";
 * - Declares string variable initialized with empty string
 * - Could also write: string res; (default initialization)
 * 
 * Line 69: int l = 0, r = values.size() - 1;
 * - Declares two integer variables in one statement
 * - "values.size()" returns number of elements (type size_t, converted to int)
 * - "size() - 1" gives last valid index (arrays are 0-indexed)
 * 
 * Line 73: int m = l + (r - l) / 2;
 * - Calculates middle index using overflow-safe formula
 * - Parentheses ensure correct order of operations
 * - Integer division truncates decimal part
 * 
 * Line 77: if (values[m].second <= timestamp) {
 * - "values[m]" accesses pair at index m
 * - ".second" accesses second element of pair (timestamp)
 * - ".first" would access first element of pair (value string)
 * - "<=" means "less than or equal to"
 * 
 * Line 80: res = values[m].first;
 * - Assigns the value string (first element of pair) to result
 * - "values[m].first" extracts the string value from the pair
 * 
 * Line 81: l = m + 1;
 * - Updates left boundary to search right half
 * - "+1" because we already checked middle element
 * 
 * Line 83: r = m - 1;
 * - Updates right boundary to search left half
 * - "-1" because we already checked middle element
 * 
 * Line 87: return res;
 * - Returns the string result to caller
 * - Function execution ends here
 * 
 * Line 88-89: }; (end of class)
 * - Closing brace ends class definition
 * - Semicolon is required after class definition in C++
 * 
 * KEY C++ CONCEPTS EXPLAINED:
 * 
 * 1. Templates:
 *    - unordered_map<KeyType, ValueType> allows specifying data types
 *    - pair<FirstType, SecondType> creates a two-element container
 *    - vector<ElementType> creates dynamic array of specific type
 * 
 * 2. Member Access:
 *    - obj.method() calls method on object
 *    - obj.member accesses data member
 *    - pair.first and pair.second access pair elements
 * 
 * 3. References (&):
 *    - Create alias to existing object without copying
 *    - More efficient than copying large objects like vectors
 *    - Changes through reference affect original object
 * 
 * 4. Auto-initialization:
 *    - unordered_map[key] creates empty vector if key doesn't exist
 *    - Convenient but can accidentally create unwanted entries
 * 
 * 5. Iterators:
 *    - find() returns iterator (pointer-like object)
 *    - end() represents position "after last element"
 *    - Used to check if element exists in container
 * 
 * 6. Method Chaining:
 *    - store[key].push_back() first accesses vector, then calls method on it
 *    - values[m].second first accesses pair, then accesses second element
 * 
 * MEMORY AND PERFORMANCE NOTES:
 * - unordered_map provides O(1) average lookup time
 * - vector provides O(1) append time and O(1) random access
 * - Binary search provides O(log n) search time
 * - Using references avoids unnecessary copying of large objects
 * - Space complexity grows linearly with number of set operations
 */
#include <bits/stdc++.h>  // includes all standard C++ libraries
using namespace std;

/**
 * LRUCache:
 * Implements a Least Recently Used (LRU) cache using a hash map and a doubly linked list.
 * - unordered_map provides O(1) access to nodes.
 * - doubly linked list maintains the LRU order: left = LRU, right = MRU.
 * - On get/put, move node to MRU position.
 * 
 * Time Complexity: O(1) for both get() and put().
 * Space Complexity: O(capacity)
 */

class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;  // maximum capacity of cache
    unordered_map<int, Node*> cache;  // maps keys to nodes
    Node* left;   // dummy head (LRU end)
    Node* right;  // dummy tail (MRU end)

    // Removes a node from the list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    // Inserts a node at the MRU position (just before right)
    void insert(Node* node) {
        Node* prev = right->prev;
        Node* nxt = right;
        prev->next = node;
        nxt->prev = node;
        node->prev = prev;
        node->next = nxt;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0, 0);   // dummy LRU node
        right = new Node(0, 0);  // dummy MRU node
        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            delete cache[key];
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);

        if (cache.size() > cap) {
            // remove LRU node
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/*
-------------------- LINE-BY-LINE SYNTAX EXPLANATION --------------------

#include <bits/stdc++.h>
    ✅ Includes all standard C++ header files (like <vector>, <unordered_map>, <iostream>, etc.) in one line.

using namespace std;
    ✅ Lets you use names like vector, unordered_map, cout, etc., directly without writing std::vector.

class Node {
    ✅ Defines a class called Node to represent each doubly linked list node.

int key, val;
    ✅ Stores the key and value for the cache entry.

Node* prev;
Node* next;
    ✅ Pointers to the previous and next nodes in the list.

Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    ✅ Constructor that initializes the node with key and value, and null pointers.

class LRUCache {
    ✅ Defines the LRUCache class.

private:
    ✅ Section for private data members & helper methods.

int cap;
    ✅ The maximum number of items the cache can hold.

unordered_map<int, Node*> cache;
    ✅ Maps keys to pointers to their corresponding nodes for O(1) lookup.

Node* left, *right;
    ✅ Dummy nodes for LRU and MRU ends of the list.

void remove(Node* node)
    ✅ Helper function to remove a node from its position in the list.

void insert(Node* node)
    ✅ Helper function to insert a node just before the MRU dummy node.

public:
    ✅ Section for public methods.

LRUCache(int capacity)
    ✅ Constructor that initializes the cache with given capacity and sets up dummy nodes.

int get(int key)
    ✅ Returns the value for key if found, otherwise -1. Also moves node to MRU position.

void put(int key, int value)
    ✅ Inserts or updates a key-value pair. If over capacity, removes the LRU item.

if (cache.find(key) != cache.end())
    ✅ Checks if key exists in the map.

remove(cache[key]);
    ✅ Removes the node from the list.

delete cache[key];
    ✅ Frees memory for the removed node.

Node* node = new Node(key, value);
    ✅ Creates a new node on the heap.

cache[key] = node;
    ✅ Adds the node to the hash map.

insert(node);
    ✅ Inserts the node at MRU position.

if (cache.size() > cap)
    ✅ If we exceed capacity, evict the least recently used (LRU) node.

cache.erase(lru->key);
    ✅ Remove the key from the hash map.

delete lru;
    ✅ Free memory of the removed LRU node.

*/

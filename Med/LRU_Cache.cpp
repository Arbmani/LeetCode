#include "list"
#include "unordered_map"
#include <functional>

using namespace std;

// The functions get and put must each run in O(1) average time complexity.
class LRUCache {
private:
    int capacity;
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> hashmap;

    void makeRecentlyUsed(list<pair<int, int>>::iterator it) {
        cache.splice(cache.begin(), cache, it);
    }

public:
    // LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    LRUCache(int capacity) : capacity(capacity) {}
    
    // int get(int key) Return the value of the key if the key exists, otherwise return -1.
    int get(int key) {
        auto it = hashmap.find(key);
        if(it == hashmap.end()) return -1;
        makeRecentlyUsed(it->second);
        return it->second->second;
        
    }
    
    // void put(int key, int value) Update the value of the key if the key exists. 
    // Otherwise, add the key-value pair to the cache. 
    // If the number of keys exceeds the capacity from this operation, evict the least recently used key.
    void put(int key, int value) {
        auto it = hashmap.find(key);

        if(it != hashmap.end()){
            it->second->second = value;
            makeRecentlyUsed(it->second);
            return;
        }
        cache.emplace_front(key, value);
        hashmap[key] = cache.begin();

        if(cache.size() > capacity) {
            int lruKey = cache.back().first;
            hashmap.erase(lruKey);
            cache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
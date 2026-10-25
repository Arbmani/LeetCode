#include <list>
#include <unordered_map>

using namespace std;

/*


Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

To determine the least frequently used key, a use counter is maintained for each key in the cache. 
The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). 
The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

*/


class LFUCache {
private:
    struct CacheEntry {
        int value;
        int frequency;
        list<int>::iterator positionInFrequencyList;
        CacheEntry(int entryValue) : value(entryValue), frequency(1) {}
    };
    int capacity;
    int minimumFrequency = 0;

    unordered_map<int, CacheEntry> cacheEntries;
    unordered_map<int, list<int>>  entriesByFrequency;

    void recordAccess(int key) {
        CacheEntry& entry = cacheEntries.at(key);
        int oldFrequency = entry.frequency;
        list<int>& oldList = entriesByFrequency[oldFrequency];
        oldList.erase(entry.positionInFrequencyList);
        if(oldList.empty() && minimumFrequency == oldFrequency){
            minimumFrequency++;
        }
        entry.frequency++; 
        list<int>& newList = entriesByFrequency[entry.frequency];
        newList.push_front(key);
        entry.positionInFrequencyList = newList.begin();
    }
public:
    // LFUCache(int capacity) Initializes the object with the capacity of the data structure.
    LFUCache(int capacity) : capacity(capacity) {}
    
    // int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
    int get(int key) {
        auto entryIterator = cacheEntries.find(key);
        if (entryIterator == cacheEntries.end()) return -1;
        recordAccess(key);
        return cacheEntries.at(key).value;
    }
    
    // void put(int key, int value) Update the value of the key if present, 
    // or inserts the key if not already present. When the cache reaches its capacity, 
    // it should invalidate and remove the least frequently used key before inserting a new item. 
    // For this problem, when there is a tie (i.e., two or more keys with the same frequency), 
    // the least recently used key would be invalidated.
    void put(int key, int value) {
        if (capacity == 0) return;
        auto entryIterator = cacheEntries.find(key);
        if (entryIterator != cacheEntries.end()){
            recordAccess(key);
            cacheEntries.at(key).value = value;
            return;
        }
        if (cacheEntries.size() == capacity) {
            list<int>& leastFrequentList = entriesByFrequency[minimumFrequency];
            int keyToEvict = leastFrequentList.back();
            leastFrequentList.pop_back();
            cacheEntries.erase(keyToEvict);
            if (leastFrequentList.empty()) entriesByFrequency.erase(minimumFrequency);
        }
        auto& frequencyOneList = entriesByFrequency[1];
        frequencyOneList.push_front(key);
        CacheEntry newEntry(value);
        newEntry.positionInFrequencyList = frequencyOneList.begin();
        cacheEntries.emplace(key, newEntry);
        minimumFrequency = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
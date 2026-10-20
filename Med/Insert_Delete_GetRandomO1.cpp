#include <unordered_map>
#include <vector>
#include <random>

using namespace std;

class RandomizedSet {
public:
    unordered_map<int, int> value_to_key;
    vector<int>             key_to_value;
    random_device rd;
    mt19937 gen{rd()};
    int size = 0;

    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (value_to_key.count(val)) return false;
        //size++;
        value_to_key[val] = size;
        key_to_value.push_back(val);
        size++;
        return true;
    }
    
    bool remove(int val) {
        if (!(value_to_key.count(val))) return false;
        //size--;
        int oldPos  = value_to_key[val];
        int lastVal = key_to_value[size - 1];
        key_to_value[oldPos] = lastVal;
        value_to_key[lastVal] = oldPos;

        value_to_key.erase(val);
        key_to_value.pop_back();

        size--; 

        return true;
    }
    
    int getRandom() {
        uniform_int_distribution<> dist(0, size - 1);
        return key_to_value[dist(gen)];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
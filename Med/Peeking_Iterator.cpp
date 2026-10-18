#include "vector"
#include "iostream"
#include <iterator>

using namespace std;

class Iterator {
    struct Data;
    Data* data;
public:
	Iterator(const vector<int>& nums);
 	Iterator(const Iterator& iter);

	int next();

	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    int cached;
    bool hasCached;

public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums), cached(0), hasCached(false) {
        if (Iterator::hasNext()){
            cached = Iterator::next();
            hasCached = true;
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return cached;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int result = cached;
        if(Iterator::hasNext()){
            cached = Iterator::next();
            hasCached = true;
        } else hasCached = false;
	    return result;
	}
	
	bool hasNext() const {
	    return hasCached;
	}
};
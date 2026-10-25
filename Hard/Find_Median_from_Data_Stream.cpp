#include "queue"
#include "vector"
#include <functional>
#include <queue>
#include <vector>
using namespace std;

/**

The median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.



*/

class MedianFinder{
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top())    maxHeap.push(num);
        else                                            minHeap.push(num);

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop(); 
        }
    }
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        if (minHeap.size() > maxHeap.size()) return minHeap.top();
        return (static_cast<double>(maxHeap.top()) + minHeap.top()) / 2.0;
    }

};

class MedianFinder_slow {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder_slow() {}
    
    void addNum(int num) {
        maxHeap.push(num);
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()){
            int largest_of_smallest = maxHeap.top();
            maxHeap.pop();
            minHeap.push(largest_of_smallest);
        }
        
        // Rebalance
        if (maxHeap.size() > minHeap.size() + 1) {
            int largest_of_smallest = maxHeap.top();
            maxHeap.pop();
            minHeap.push(largest_of_smallest);
        }
        else if (minHeap.size() > maxHeap.size() + 1) {
            int smallest_of_largest = minHeap.top();
            minHeap.pop();
            maxHeap.push(smallest_of_largest);
        }
    }
    
    // double findMedian() returns the median of all elements so far. Answers within 10^-5 of the actual answer will be accepted.
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        if (minHeap.size() > maxHeap.size()) return minHeap.top();
        return (static_cast<double>(minHeap.top()) + maxHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
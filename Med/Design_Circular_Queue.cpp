#include "vector"

using namespace std;

/**


Design your implementation of the circular queue. 
The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, 
and the last position is connected back to the first position to make a circle. 
It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. 
In a normal queue, once the queue becomes full, 
we cannot insert the next element even if there is a space in front of the queue. 
But using the circular queue, we can use the space to store new values.

*/

class MyCircularQueue {
private:
    vector<int> queue;
    int head;
    int count;
    int capacity;

public:
    // MyCircularQueue(k) Initializes the object with the size of the queue to be k.
    MyCircularQueue(int k) : queue(k), head(0), count(0), capacity(k) {}
    
    // boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
    bool enQueue(int value) {
        if (isFull()) return false;
        int tail = (head + count) % capacity;
        queue[tail] = value;
        count++;
        return true;
    }
    
    // Deletes an element from the circular queue. Return true if the operation is successful.
    bool deQueue() {
       if (isEmpty()) return false;
       head = (head + 1) % capacity;
       count--;
       return true; 
    }
    
    // int Front() Gets the front item from the queue. If the queue is empty, return -1.
    int Front() {
        if (isEmpty()) return -1;
        return queue[head];
    }
    
    // int Rear() Gets the last item from the queue. If the queue is empty, return -1.
    int Rear() {
        if (isEmpty()) return -1;
        int tail = (head + count - 1) % capacity;
        return queue[tail];
    }
    
    // Checks whether the circular queue is empty or not.
    bool isEmpty() {
        return  count == 0;
    }
    
    // Checks whether the circular queue is full or not.
    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
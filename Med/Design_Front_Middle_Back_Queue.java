import java.util.*;

/*

Design a queue that supports push and pop operations in the front, middle, and back.

Notice that when there are two middle position choices, the operation is 
performed on the frontmost middle position choice. For example:

-   Pushing 6 into the middle of [1, 2, 3, 4, 5] results in [1, 2, 6, 3, 4, 5].

-   Popping the middle from [1, 2, 3, 4, 5, 6] returns 3 and results in [1, 2, 4, 5, 6].

*/


//  Implement the FrontMiddleBackQueue class:
class FrontMiddleBackQueue {
    private Deque<Integer> left;
    private Deque<Integer> right;

    private void balance(){
        if (left.size() > right.size() + 1) right.addFirst(left.removeLast());
        else if (left.size() < right.size()) left.addLast(right.removeFirst());

    }

    //  FrontMiddleBackQueue() Initializes the queue.
    public FrontMiddleBackQueue() {
        left  = new ArrayDeque<>();
        right = new ArrayDeque<>();
    }
    
    //  void pushFront(int val) Adds val to the front of the queue.
    public void pushFront(int val) {
        left.addFirst(val);
        balance();
    }
    
    //  void pushMiddle(int val) Adds val to the middle of the queue.
    public void pushMiddle(int val) {
        if (left.size() > right.size()){
            right.addFirst(left.removeLast());
        }
        left.addLast(val);
        balance();
    }
    
    //  void pushBack(int val) Adds val to the back of the queue.
    public void pushBack(int val) {
        right.addLast(val);
        balance();
    }
    
    //  int popFront() Removes the front element of the queue and returns it. If the queue is empty, return -1.
    public int popFront() {
        if (left.isEmpty()) return -1;
        int val = left.removeFirst();
        balance();
        return val;
    }
    
    //  int popMiddle() Removes the middle element of the queue and returns it. If the queue is empty, return -1.
    public int popMiddle() {
        if (left.isEmpty()) return -1;
        int val = left.removeLast();
        balance();
        return val;
    }
    
    //  int popBack() Removes the back element of the queue and returns it. If the queue is empty, return -1.
    public int popBack() {
        if (left.isEmpty()) return -1;
        int val;
        if (!right.isEmpty()) val = right.removeLast();
        else                  val = left.removeLast();
        balance();
        return val;
    }
}

public class Design_Front_Middle_Back_Queue{
    public static void main(String[] args) {
        FrontMiddleBackQueue fmbq = new FrontMiddleBackQueue();

        fmbq.pushFront(1);
        fmbq.pushBack(2);
        fmbq.pushMiddle(3);
        fmbq.pushMiddle(4);
        System.out.println("\nWant : 1\nWas  : " + fmbq.popFront());
        System.out.println("\nWant : 3\nWas  : " + fmbq.popMiddle());
        System.out.println("\nWant : 4\nWas  : " + fmbq.popMiddle());
        System.out.println("\nWant : 2\nWas  : " + fmbq.popBack());
        System.out.println("\nWant : -1\nWas  : " + fmbq.popFront());

    }
}
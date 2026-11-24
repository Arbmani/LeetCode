import java.util.*;

/*

Design and implement a data structure for a Least Frequently Used (LFU) cache.

To determine the least frequently used key, a use counter is maintained for 
each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). 
The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

*/


//  Implement the LFUCache class:
class LFUCache {
    private final int capacity;
    private int minFrequency;
    private final Map<Integer, Node> cache;
    private final Map<Integer, DoubleLinkedList> frequencyMap;

    private class Node {
        int  key;
        int  value;
        int  frequency;
        Node prev;
        Node next;

        Node (int key, int value){
            this.key        = key;
            this.value      = value;
            this.frequency  = 1;
        }
    }

    private void increaseFrequency(Node node){
        int oldFrq = node.frequency;
        DoubleLinkedList oldList = frequencyMap.get(oldFrq);
        oldList.remove(node);
        if (oldFrq == minFrequency && oldList.isEmpty()) minFrequency++;
        node.frequency++;
        frequencyMap.computeIfAbsent(node.frequency, k -> new DoubleLinkedList()).addFirst(node);
    }

    private class DoubleLinkedList{
        Node head;
        Node tail;
        int  size;

        DoubleLinkedList(){
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head.next = tail;
            tail.prev = head;
        }

        void addFirst(Node node){
            node.next       = head.next;
            node.prev       = head;
            head.next.prev  = node;
            head.next       = node;
            size++;
        }
        void remove(Node node){
            node.prev.next = node.next;
            node.next.prev = node.prev;
            size--;
        }
        Node removeLast(){
            if (size == 0) return null;
            Node node = tail.prev;
            remove(node);
            return node;
        }
        boolean isEmpty(){
            return size == 0;
        }
    }

    //  LFUCache(int capacity) Initializes the object with the capacity of the data structure.
    public LFUCache(int capacity) {
        this.capacity       = capacity;
        this.minFrequency   = 0;
        cache               = new HashMap<>();
        frequencyMap        = new HashMap<>();
    }
    
    //  int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
    public int get(int key) {
        Node node = cache.get(key);
        if  (node == null) return -1;
        increaseFrequency(node);
        return node.value;
    }   
    
    //  void put(int key, int value) Update the value of the key if present, or inserts the key 
    //  if not already present. When the cache reaches its capacity, it should invalidate and 
    //  remove the least frequently used key before inserting a new item. For this problem, 
    //  when there is a tie (i.e., two or more keys with the same frequency), 
    //  the least recently used key would be invalidated.
    public void put(int key, int value) {
        if (capacity == 0) return;
        if (cache.containsKey(key)){
            Node node = cache.get(key);
            node.value = value;
            increaseFrequency(node);
            return;
        }
        if (cache.size() == capacity){
            DoubleLinkedList dll = frequencyMap.get(minFrequency);
            Node removed = dll.removeLast();
            cache.remove(removed.key);
            if (dll.isEmpty()) frequencyMap.remove(minFrequency);
        }
        Node newNode = new Node(key, value);
        cache.put(key, newNode);
        frequencyMap.computeIfAbsent(1, k -> new DoubleLinkedList()).addFirst(newNode);
        minFrequency = 1;
    }
}

public class LFU_Cache{
    public static void main(String[] args) {
        LFUCache lfuc = new LFUCache(2);
        lfuc.put(1, 1);
        lfuc.put(2, 2);
        System.out.println("\nWant : 1\nWas  : " + lfuc.get(1));
        lfuc.put(3, 3);
        System.out.println("\nWant : -1\nWas  : " + lfuc.get(2));
        System.out.println("\nWant : 3\nWas  : " + lfuc.get(3));
        lfuc.put(4, 4);
        System.out.println("\nWant : -1\nWas  : " + lfuc.get(1));
        System.out.println("\nWant : 3\nWas  : " + lfuc.get(3));
        System.out.println("\nWant : 4\nWas  : " + lfuc.get(4));
        
        
        
    }
}
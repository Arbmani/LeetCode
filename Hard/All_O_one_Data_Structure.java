import java.util.*;

/*

Design a data structure to store the strings' count with the 
ability to return the strings with minimum and maximum counts.

Note that each function must run in O(1) average time complexity.

*/

//  Implement the AllOne class:
class AllOne {
    private Map<String, Bucket> keyToBucket;
    private Bucket head;
    private Bucket tail;

    private static class Bucket {
        int count;
        Set<String> keys;
        Bucket prev;
        Bucket next;

        Bucket (int count){
            this.count = count;
            this.keys  = new HashSet<>();
        }
    }

    private void insertAfter(Bucket node, Bucket newBucket) {
        newBucket.prev  = node;
        newBucket.next  = node.next;
        node.next.prev  = newBucket;
        node.next       = newBucket;
    }
    private void insertBefore(Bucket node, Bucket newBucket){
        insertAfter(node.prev, newBucket);
    }
    private void removeBucket(Bucket bucket) {
        bucket.prev.next = bucket.next;
        bucket.next.prev = bucket.prev;
    }


    //  AllOne() Initializes the object of the data structure.
    public AllOne() {
        keyToBucket = new HashMap<>();
        head        = new Bucket(0); 
        tail        = new Bucket(0); 
        
        head.next = tail;
        tail.prev = head;
    }
    
    //  inc(String key) Increments the count of the string key by 1. 
    //  If key does not exist in the data structure, insert it with count 1.
    public void inc(String key) {
        if (!keyToBucket.containsKey(key)){
            Bucket first = head.next;
            if (first == tail || first.count != 1){
                Bucket newBucket = new Bucket(1);
                insertAfter(head, newBucket);
                first = newBucket;
            }
            first.keys.add(key);
            keyToBucket.put(key, first);
        } else {
            Bucket curr         = keyToBucket.get(key);
            Bucket nextBucket   = curr.next;
            if (nextBucket == tail || nextBucket.count != curr.count + 1){
                Bucket newBucket = new Bucket(curr.count + 1);
                insertAfter(curr, newBucket);
                nextBucket = newBucket;
            } 
            curr.keys.remove(key);
            nextBucket.keys.add(key);
            keyToBucket.put(key, nextBucket);
            if (curr.keys.isEmpty()) removeBucket(curr);
        }
    }
    
    //  dec(String key) Decrements the count of the string key by 1. 
    //  If the count of key is 0 after the decrement, remove it from the data structure. 
    //  It is guaranteed that key exists in the data structure before the decrement.
    public void dec(String key) {
        Bucket curr = keyToBucket.get(key);
        if (curr.count == 1){
            curr.keys.remove(key);
            keyToBucket.remove(key);
            if (curr.keys.isEmpty()) removeBucket(curr);
        } else {
            Bucket prevBucket = curr.prev;
            if (prevBucket == head || prevBucket.count != curr.count - 1){
                Bucket newBucket = new Bucket(curr.count - 1);
                insertBefore(curr, newBucket);
                prevBucket = newBucket;
            }
            curr.keys.remove(key);
            prevBucket.keys.add(key);
            keyToBucket.put(key, prevBucket);
            if (curr.keys.isEmpty()) removeBucket(curr);
        }
    }

    //  getMaxKey() Returns one of the keys with the maximal count. 
    //  If no element exists, return an empty string "".
    public String getMaxKey() {
        if (tail.prev == head) return "";
        return tail.prev.keys.iterator().next();
    }
    
    //  getMinKey() Returns one of the keys with the minimum count. 
    //  If no element exists, return an empty string "".
    public String getMinKey() {
        if (head.next == tail) return "";
        return head.next.keys.iterator().next();
    }
}

public class All_O_one_Data_Structure{
    public static void main(String[] args) {
        AllOne ao = new AllOne();
        ao.inc("hello");
        ao.inc("hello");
        System.out.println("\nWant : hello\nWas  : " + ao.getMaxKey());
        System.out.println("\nWant : hello\nWas  : " + ao.getMinKey());
        ao.inc("leet");
        System.out.println("\nWant : hello\nWas  : " + ao.getMaxKey());
        System.out.println("\nWant : leet\nWas  : " + ao.getMinKey());
    }
}
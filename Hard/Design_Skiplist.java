import java.util.Random;

/*

Design a Skiplist without using any built-in libraries.

A skiplist is a data structure that takes O(log(n)) time to add, erase and search. 
Comparing with treap and red-black tree which has the same function and performance, 
the code length of Skiplist can be comparatively short and the idea behind Skiplists is just simple linked lists.

For example, we have a Skiplist containing [30,40,50,60,70,90] and we want to add 80 and 45 into it. 
The Skiplist works this way:

You can see there are many layers in the Skiplist. Each layer is a sorted linked list. 
With the help of the top layers, add, erase and search can be faster than O(n). 
It can be proven that the average time complexity for each operation is O(log(n)) and space complexity is O(n).

See more about Skiplist: https://en.wikipedia.org/wiki/Skip_list

Note that duplicates may exist in the Skiplist, your code needs to handle this situation.

*/

//  Implement the Skiplist class:
class Skiplist {
    private static final int    MAX_LEVEL = 32;

    private final Node          head;
    private       int           level;
    private final Node[]        update;
    private final Random        random;

    private static class Node {
        int     val;
        Node[]  next;
        Node (int val, int level){
            this.val  = val;
            this.next = new Node[level];
        }
    }

    private int randomLevel(){
        int    level = 1;
        while (level < MAX_LEVEL && random.nextBoolean()) level++;
        return level;
    }

    private Node find(int target){
        Node curr = head;
        for (int i = level - 1; i >= 0; i--){
            while (curr.next[i] != null && curr.next[i].val < target) curr = curr.next[i];
            update[i] = curr;
        }
        return curr.next[0] != null && curr.next[0].val == target ? curr.next[0] : null;
    }


    //  Skiplist() Initializes the object of the skiplist.
    public Skiplist() {
        head        = new Node(0, MAX_LEVEL);
        level       = 1;
        update      = new Node[MAX_LEVEL];
        random      = new Random();
    }
    
    //  bool search(int target) Returns true if the integer target exists in the Skiplist or false otherwise.
    public boolean search(int target) {
        return find(target) != null;
    }
    
    //  void add(int num) Inserts the value num into the SkipList.
    public void add(int num) {
        find(num);
        int newlevel = randomLevel();
        if (newlevel > level){
            for (int i = level; i < newlevel; i++) update[i] = head;
            level = newlevel;
        }
        Node node = new Node(num, newlevel);
        for (int i = 0; i < newlevel; i++){
            node.next[i]        = update[i].next[i];
            update[i].next[i]   = node;
        }

    }
    
    //  bool erase(int num) Removes the value num from the Skiplist and returns true. 
    //  If num does not exist in the Skiplist, do nothing and return false. 
    //  If there exist multiple num values, removing any one of them is fine.
    public boolean erase(int num) {
        Node node = find(num);
        if  (node == null) return false;
        for (int i = 0; i < level && update[i].next[i] == node; i++) update[i].next[i] = node.next[i];
        while (level > 1 && head.next[level - 1] == null) level--;
        return true;
    }
}

public class Design_Skiplist{
    public static void main(String[] args) {
        Skiplist sl = new Skiplist();
        sl.add(1);
        sl.add(2);
        sl.add(3);
        System.out.println("\nWant : false\nWas  : " + sl.search(0));
        sl.add(4);
        System.out.println("\nWant : true\nWas  : " + sl.search(1));
        System.out.println("\nWant : false\nWas  : " + sl.erase(0));
        System.out.println("\nWant : true\nWas  : " + sl.erase(1));
        System.out.println("\nWant : false\nWas  : " + sl.search(1));
    }
}
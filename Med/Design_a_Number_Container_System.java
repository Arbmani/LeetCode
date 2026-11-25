import java.util.*;

/*

Design a number container system that can do the following:

-   Insert or Replace a number at the given index in the system.

-   Return the smallest index for the given number in the system.

*/

//  Implement the NumberContainers class:
class NumberContainers {
    private Map<Integer, Integer> indexToNumber;
    private Map<Integer, TreeSet<Integer>> numberToIndices;

    //  NumberContainers() Initializes the number container system.
    public NumberContainers() {
        indexToNumber   = new HashMap<>();
        numberToIndices = new HashMap<>();
    }
    
    //  void change(int index, int number) Fills the container at index with the number. 
    //  If there is already a number at that index, replace it.
    public void change(int index, int number) {
        if (indexToNumber.containsKey(index)){
            int oldNumber = indexToNumber.get(index);
            numberToIndices.get(oldNumber).remove(index);
            if (numberToIndices.get(oldNumber).isEmpty()) numberToIndices.remove(oldNumber);
        }
        indexToNumber.put(index, number);
        numberToIndices.putIfAbsent(number, new TreeSet<>());
        numberToIndices.get(number).add(index);
    }
    
    //  int find(int number) Returns the smallest index for the given number, 
    //  or -1 if there is no index that is filled by number in the system
    public int find(int number) {
        if(!numberToIndices.containsKey(number)) return -1;
        return numberToIndices.get(number).first();
    }
}

public class Design_a_Number_Container_System{
    public static void main(String[] args) {
        NumberContainers nc = new NumberContainers();
        System.out.println("\nWant : -1\nWas  : " + nc.find(10));
        nc.change(2, 10);
        nc.change(1, 10);
        nc.change(3, 10);
        nc.change(5, 10);
        System.out.println("\nWant : 1\nWas  : " + nc.find(10));
        nc.change(1, 20);
        System.out.println("\nWant : 2\nWas  : " + nc.find(10));
    }
}
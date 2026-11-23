import java.util.*;

/*

Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

The test cases are generated so that, at any time, 
the product of any contiguous sequence of numbers will 
fit into a single 32-bit integer without overflowing.

*/

//  Implement the ProductOfNumbers class:
class ProductOfNumbers {
    private ArrayList<Integer> vec;


    //  ProductOfNumbers() Initializes the object with an empty stream.
    public ProductOfNumbers() {
        vec = new ArrayList<>();
        vec.add(1);
    }
    
    //  void add(int num) Appends the integer num to the stream.
    public void add(int num) {
        if (num == 0){
            vec.clear();
            vec.add(1);
        } else {
            vec.add(num * vec.get(vec.size() - 1));
        }
    }
    
    //  int getProduct(int k) Returns the product of the last k numbers in the current list. 
    //  You can assume that always the current list has at least k numbers.
    public int getProduct(int k) {
        if (k >= vec.size()) return 0;
        return vec.get(vec.size() -1) / vec.get(vec.size() - (1 + k));
    }
}


public class Product_of_the_Last_K_Numbers{
    public static void main(String[] args) {
        ProductOfNumbers PON = new ProductOfNumbers();
        PON.add(3);
        PON.add(0);
        PON.add(2);
        PON.add(5);
        PON.add(4);
        System.out.println("\nWant : 20\nWas  : " + PON.getProduct(2));
        System.out.println("\nWant : 40\nWas  : " + PON.getProduct(3));
        System.out.println("\nWant : 0\nWas  : " + PON.getProduct(4));
        PON.add(8);
        System.out.println("\nWant : 32\nWas  : " + PON.getProduct(2));
    }
}
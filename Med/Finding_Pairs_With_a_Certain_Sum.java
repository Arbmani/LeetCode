import java.util.*;

/*

You are given two integer arrays nums1 and nums2. 
You are tasked to implement a data structure that supports queries of two types:

1.  Add a positive integer to an element of a given index in the array nums2.

2.  Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a 
    given value (0 <= i < nums1.length and 0 <= j < nums2.length).

*/

//  Implement the FindSumPairs class:
class FindSumPairs {
    private int[] nums2;

    private HashMap<Integer, Integer> freq1;
    private HashMap<Integer, Integer> freq2;


    //  FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object 
    //  with two integer arrays nums1 and nums2.
    public FindSumPairs(int[] nums1, int[] nums2) {
        this.nums2 = nums2;

        freq1 = new HashMap<>();
        freq2 = new HashMap<>();

        for (int num : nums1) freq1.put(num, freq1.getOrDefault(num, 0) + 1);
        for (int num : nums2) freq2.put(num, freq2.getOrDefault(num, 0) + 1);
    }
    
    //  void add(int index, int val) Adds val to 
    //  nums2[index], i.e., apply nums2[index] += val.
    public void add(int index, int val) {
        int oldVal = nums2[index];
        freq2.put(oldVal, freq2.get(oldVal) - 1);
        nums2[index] += val;
        int newVal = nums2[index];
        freq2.put(newVal, freq2.getOrDefault(newVal, 0) + 1);
    }

    //  int count(int tot) Returns the number of pairs (i, j) 
    //  such that nums1[i] + nums2[j] == tot.
    public int count(int tot) {
        int count = 0;
        for (int num : freq1.keySet()) count += freq1.get(num) * freq2.getOrDefault(tot - num, 0);
        return count;
    }
}



public class Finding_Pairs_With_a_Certain_Sum {
    public static void main(String[] args) {
        int [] nums1 = {1, 1, 2, 2, 2, 3};
        int [] nums2 = {1, 4, 5, 2, 5, 4};

        FindSumPairs FSP = new FindSumPairs(nums1, nums2);
        System.out.println("\nWant : 8\nWas  : " + FSP.count(7));
        FSP.add(3, 2);
        System.out.println("\nWant : 2\nWas  : " + FSP.count(8));
        System.out.println("\nWant : 1\nWas  : " + FSP.count(4));
        FSP.add(0, 1);
        FSP.add(1, 1);
        System.out.println("\nWant : 11\nWas  : " + FSP.count(7));

    }
}

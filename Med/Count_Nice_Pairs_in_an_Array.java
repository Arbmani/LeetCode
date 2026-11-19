import java.util.*;

/*

You are given an array nums that consists of non-negative integers. 
Let us define rev(x) as the reverse of the non-negative integer x. 
For example, rev(123) = 321, and rev(120) = 21. 

A pair of indices (i, j) is nice if it satisfies all of the following conditions:

-   0 <= i < j < nums.length

-   nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])

Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

*/

class SolutionCount_Nice_Pairs_in_an_Array {
    private final int mod = 1_000_000_007;

    private int reverse(int num) {
        int reversed = 0;
        while (num > 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return reversed;
    }

    public int countNicePairs(int[] nums) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        int count = 0;

        for (int num : nums){
            int diff = num - reverse(num);
            count    = (count + freq.getOrDefault(diff, 0)) % mod;
            freq.put(diff, freq.getOrDefault(diff, 0) + 1);
        }
        return count;        
    }
}


public class Count_Nice_Pairs_in_an_Array {
    public static void main(String[] args) {
        SolutionCount_Nice_Pairs_in_an_Array s = new SolutionCount_Nice_Pairs_in_an_Array();
        int [] nums1 = {42, 11, 1, 97};
        int [] nums2 = {13,10,35,24,76};

        System.out.println("\nWant : 2\nWas  : " + s.countNicePairs(nums1));
        System.out.println("\nWant : 4\nWas  : " + s.countNicePairs(nums2));

    }    
}

import java.util.*;
/*

Given an array nums of distinct positive integers, 
return the number of tuples (a, b, c, d) such 
that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

*/

class Solution {
    public int tupleSameProduct(int[] nums) {
        Map<Integer, Integer> productCount = new HashMap<>();
        int count = 0;
        for (int i = 0; i < nums.length; i++){
            for (int j = i + 1; j < nums.length; j++){
                int product = nums[i] * nums[j];
                count += productCount.getOrDefault(product, 0) * 8;
                productCount.put(product, productCount.getOrDefault(product, 0) + 1);
            }
        }
        return count;
    }
}

public class Tuple_with_Same_Product {
    public static void main(String[] args) {
        Solution s = new Solution();
        int []nums1 = {2,3,4,6};
        int []nums2 = {1,2,4,5,10};

        System.out.println("\nWant : 8\nWas  : " + s.tupleSameProduct(nums1));
        System.out.println("\nWant : 16\nWas  : " + s.tupleSameProduct(nums2));



    }
}
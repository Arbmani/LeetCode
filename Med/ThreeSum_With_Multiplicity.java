import java.util.*;

/*

Given an integer array arr, and an integer target, 
return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

As the answer can be very large, return it modulo 109 + 7.


*/

class Solution {
    public int threeSumMulti(int[] arr, int target) {
        final int mod = 1_000_000_007;
        Map<Integer, Long> pairs = new HashMap<>();
        long ans = 0;

        for (int k = 0; k < arr.length; k++){
            ans = (ans + pairs.getOrDefault(target - arr[k], 0L)) % mod;
            for (int j = 0; j < k; j++) pairs.put(arr[j] + arr[k], pairs.getOrDefault(arr[j] + arr[k], 0L) + 1);
        }   


        return (int) ans;
    }
}

public class ThreeSum_With_Multiplicity {
    public static void main(String[] args){
        Solution s = new Solution();
        int []arr1 = {1,1,2,2,3,3,4,4,5,5};
        int []arr2 = {1,1,2,2,2,2};
        int []arr3 = {2,1,3};


        System.out.println("\nWant : 20\nWas  : " + s.threeSumMulti(arr1, 8));
        System.out.println("\nWant : 12\nWas  : " + s.threeSumMulti(arr2, 5));
        System.out.println("\nWant : 1\nWas  : " + s.threeSumMulti(arr3, 6));

    }
}
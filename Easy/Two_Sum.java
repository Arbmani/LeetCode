import java.util.*;

/*

You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.


*/


class SolutiontwoSum {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++){
            if (map.containsKey(target - nums[i])) return new int[] {map.get(target - nums[i]), i};
            map.put(nums[i], i);
        }

        return new int[] {};
    }
}


public class Two_Sum {
    public static void main(String[] args) {
        SolutiontwoSum s = new SolutiontwoSum();
        int []nums1 = {2, 7, 11, 15};
        int []nums2 = {3, 2, 4};
        int []nums3 = {3, 3};

        System.out.println("\nWant : [0, 1]\nWas  : " + Arrays.toString(s.twoSum(nums1, 9)));
        System.out.println("\nWant : [1, 2]\nWas  : " + Arrays.toString(s.twoSum(nums2, 6)));
        System.out.println("\nWant : [0, 1]\nWas  : " + Arrays.toString(s.twoSum(nums3, 6)));

    }
    

}

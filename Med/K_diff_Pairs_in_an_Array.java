import java.util.*;
/*

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

-   0 <= i, j < nums.length

-   i != j

-   |nums[i] - nums[j]| == k

Notice that |val| denotes the absolute value of val.


// case 1: nums[i] >= nums[j] -> 

    nums[i] - k == nums[j] 

// case 2: nums[j] >= nums[i] -> 

    nums[i] + k == nums[j]


*/

class SolutionK_diff_Pairs_in_an_Array {
    public int findPairs(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int count = 0;
        
        for (int num : nums) map.put(num, map.getOrDefault(num, 0) + 1);
        for (int num : map.keySet()){
            if (k == 0){
                if (map.get(num) > 1) count++;
            }
            else if (map.containsKey(num + k)) count++;
        }
        return count;
    }   
}


public class K_diff_Pairs_in_an_Array {
    public static void main(String[] args) {
        SolutionK_diff_Pairs_in_an_Array s = new SolutionK_diff_Pairs_in_an_Array();
        int [] nums1  = {3,1,4,1,5}; 
        int [] nums2  = {1,2,3,4,5}; 
        int [] nums3  = {1,3,1,5,4}; 

        System.out.println("\nWant : 2\nWas  : " + s.findPairs(nums1, 2));
        System.out.println("\nWant : 4\nWas  : " + s.findPairs(nums2, 1));
        System.out.println("\nWant : 1\nWas  : " + s.findPairs(nums3, 0));

    }
}
import java.util.*;
/*

Given a 0-indexed integer array nums of size n and 
two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

-   0 <= i < j < n, and

-   lower <= nums[i] + nums[j] <= upper

*/

class SolutionCount_the_Number_of_Fair_Pairs {
    private long countPairsLessThan(int [] nums, int target){
        int left  = 0, right = nums.length - 1;
        long count = 0;
        while (left < right){
            if (nums[left] + nums[right] < target){
                count += (long) right - left;
                left++;
            } else right--;
        }
        return count;
    }


    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        return (countPairsLessThan(nums, upper + 1) - countPairsLessThan(nums, lower));
    }
}


public class Count_the_Number_of_Fair_Pairs{
    public static void main(String[] args) {
        SolutionCount_the_Number_of_Fair_Pairs s = new SolutionCount_the_Number_of_Fair_Pairs();
        int[] nums1 = {0,1,7,4,4,5};
        int[] nums2 = {1,7,9,2,5};

        System.out.println("\nWant : 6\nWas  : " + s.countFairPairs(nums1, 3,6));
        System.out.println("\nWant : 1\nWas  : " + s.countFairPairs(nums2, 11,11));

    }
}
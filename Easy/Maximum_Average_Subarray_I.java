/*

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average 
value and return this value. Any answer with a calculation error less than 10^-5 will be accepted.


*/


class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int sum     = 0;
        int maxSum  = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++){
            sum += nums[i];
            if (i >= k)     sum -= nums[i - k];
            if (i >= k - 1) maxSum = Math.max(maxSum, sum);

        }
        return (double) maxSum / k;
    }
}


public class Maximum_Average_Subarray_I{
    public static void main(String[] args){
        Solution s = new Solution();

        int [] nums1 = {1,12,-5,-6,50,3};
        int [] nums2 = {5};

        System.out.println("\nWant : 12.75000\nWas  : " + s.findMaxAverage(nums1, 4));
        System.out.println("\nWant : 5.00000\nWas  : " + s.findMaxAverage(nums2, 1));

    }
}
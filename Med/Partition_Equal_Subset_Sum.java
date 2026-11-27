/*

Given an integer array nums, return true if you can partition the array into 
two subsets such that the sum of the elements in both subsets is equal or false otherwise

*/

class SolutionPartition_Equal_Subset_Sum {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        int target      = sum / 2;
        boolean[] dp    = new boolean[target + 1];
        dp[0] = true;

        for (int i = 0; i < nums.length; i++){
            int num = nums[i];
            for (sum = target; sum >= num; sum--){
                dp[sum] = dp[sum] || dp[sum - num]; 
            }
        }

        return dp[target];       
    }
}


public class Partition_Equal_Subset_Sum{
    public static void main(String[] args) {
        int [] nums1 = {1,5,11,5};
        int [] nums2 = {1,2,3,5};
        SolutionPartition_Equal_Subset_Sum s = new SolutionPartition_Equal_Subset_Sum();
        System.out.println("\nWant : true\nWas  : " + s.canPartition(nums1));
        System.out.println("\nWant : false\nWas  : " + s.canPartition(nums2));

    }
}
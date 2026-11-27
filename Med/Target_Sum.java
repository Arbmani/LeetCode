
/*

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the 
symbols '+' and '-' before each integer in nums and then concatenate all the integers.

-   For example, if nums = [2, 1], you can add a '+' before 2 and a '-' 
    before 1 and concatenate them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.

*/

class SolutionTarget_Sum {
    public int findTargetSumWays(int[] nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;
        if ((sum + target) % 2 != 0 || Math.abs(target) > sum) return 0;
        int newTarget = (sum + target) / 2;
        int [] dp = new int[newTarget + 1];
        dp[0] = 1;

        for (int i = 0; i < nums.length; i++){
            int num = nums[i];
            for (target = newTarget; target >= num; target--){
                dp[target] += dp[target - num];
            }
        }
        return dp[newTarget];
    }
}


public class Target_Sum{
    public static void main(String[] args) {
        SolutionTarget_Sum s = new SolutionTarget_Sum();

        int[]nums1 = {1,1,1,1,1};
        int[]nums2 = {1};

        System.out.println("\nWant : 5\nWas  : " + s.findTargetSumWays(nums1, 3));
        System.out.println("\nWant : 1\nWas  : " + s.findTargetSumWays(nums2, 1));

    }
}
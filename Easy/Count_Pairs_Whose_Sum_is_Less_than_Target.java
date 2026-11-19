import java.util.*;


/*

Given a 0-indexed integer array nums of length n and an integer target, 
return the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.

*/

class SolutionCount_Pairs_Whose_Sum_is_Less_than_Target {
    public int countPairs(List<Integer> nums, int target) {
        Collections.sort(nums);
        int left = 0, right = nums.size() - 1, count = 0;
        while (left < right) {
            int sum = nums.get(left) + nums.get(right);
            if (sum < target){
                count += right - left;
                left++;
            } else right--;
        }
        return count;
    }
}

public class Count_Pairs_Whose_Sum_is_Less_than_Target {
    public static void main(String[] args) {
        List<Integer> nums1 = new ArrayList<>(Arrays.asList(-1,1,2,3,1));
        List<Integer> nums2 = new ArrayList<>(Arrays.asList(-6, 2, 5, -2, -7, -1, 3));
        SolutionCount_Pairs_Whose_Sum_is_Less_than_Target s = new SolutionCount_Pairs_Whose_Sum_is_Less_than_Target();
        System.out.println("\nWant : 3\nWas  : " + (s.countPairs(nums1, 2)));
        System.out.println("\nWant : 10\nWas  : " + (s.countPairs(nums2, -2)));

    }
}
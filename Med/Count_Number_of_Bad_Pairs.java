import java.util.*;

/*

You are given a 0-indexed integer array nums. 
A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.

*/

class SolutionCount_Number_of_Bad_Pairs {
    // j - nums[j] != i - nums[i]
    // therefore: 
    // -    "all pairs - (j - nums[j] == i - nums[i])" 
    // -    == 
    // -    "j - nums[j] != i - nums[i]"

    public long countBadPairs(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        long goodPairs = 0;
        long allPairs  = 0;
        for (int i = 0; i < nums.length; i++){
            allPairs  += i;
            int diff   = i - nums[i];
            goodPairs += map.getOrDefault(diff, 0);
            map.put(diff, map.getOrDefault(diff, 0) + 1);
        }

        return (allPairs - goodPairs);
    }
}

public class Count_Number_of_Bad_Pairs {
    public static void main(String[] args) {
        
        int[] nums1 = {4,1,3,3};
        int[] nums2 = {1,2,3,4,5};
        SolutionCount_Number_of_Bad_Pairs s = new SolutionCount_Number_of_Bad_Pairs();
        System.out.println("\nWant : 5\nWas  : " + s.countBadPairs(nums1));
        System.out.println("\nWant : 0\nWas  : " + s.countBadPairs(nums2));



    }
}
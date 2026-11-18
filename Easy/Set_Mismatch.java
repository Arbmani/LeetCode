
/**
You have a set of integers s, which originally contains all the numbers from 1 to n. 
Unfortunately, due to some error, one of the numbers in s got duplicated to 
another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.
 */

class Solution {
    public int[] findErrorNums(int [] nums) {
        int xor = 0;
        int n   = nums.length;
        for (int i = 0; i < n; i++){
            xor ^= nums[i];
            xor ^= (i + 1);
        }
        int bit = xor & -xor;
        int a   = 0;
        int b   = 0;

        for (int i = 0; i < n; i++){
            if ((nums[i] & bit) != 0) a ^= nums[i];
            else                      b ^= nums[i];

            if (((i + 1) & bit) != 0) a ^= (i + 1);
            else                      b ^= (i + 1);
        }
        for (int num : nums) if (num == a) return new int[]{a, b};
        return new int[]{b, a};
    }
}

class Solution_bad {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int [] count = new int[n + 1];
        for (int num : nums) count[num]++;
        int dups = 0;
        int miss = 0;
        for (int i = 1; i <= n; i++){
            if (count[i] == 2) dups = i;
            if (count[i] == 0) miss = i;
        }
        return new int[]{dups, miss};
    }
}






public class Set_Mismatch {
    public static void main(String[] args){
        Solution s = new Solution();

        System.out.println("\nWant : [2, 3]\nWas  : " + java.util.Arrays.toString(s.findErrorNums(new int[]{1,2,2,4})));
        System.out.println("\nWant : [1, 2]\nWas  : " + java.util.Arrays.toString(s.findErrorNums(new int[]{1, 1})));
    }
}
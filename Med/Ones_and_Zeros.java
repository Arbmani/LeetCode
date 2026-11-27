/*

You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

*/


class Solution {
    public int findMaxForm(String[] strs, int m, int n) {

        int[][] dp = new int[m + 1][n + 1];

        for (String str : strs){
            int zeros = 0;
            int ones  = 0;

            for (char c : str.toCharArray()){
                if (c == '0') zeros++;
                else          ones++;
            }

            for (int zero = m; zero >= zeros; zero--){
                for (int one = n; one >= ones; one--){
                    dp[zero][one] = Math.max(dp[zero][one], dp[zero - zeros][one - ones] + 1);
                }
            }
        }

        return dp[m][n];
    }
}

public class Ones_and_Zeros{
    public static void main(String[] args) {
        Solution s = new Solution();
        String [] strs1 = {"10","0001","111001","1","0"};
        String [] strs2 = {"10","0","1"};

        System.out.println("\nWant : 4\nWas  : " + s.findMaxForm(strs1, 5, 3));
        System.out.println("\nWant : 2\nWas  : " + s.findMaxForm(strs2, 1, 1));

    }   
}
import java.util.*;
/*

You are given an integer array coins representing coins of different 
denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.


*/

class Solution {
    public int coinChange(int[] coins, int amount) {
        int [] dp = new int[amount + 1];
        Arrays.fill(dp, Integer.MAX_VALUE / 2);
        dp[0] = 0;
        for (int i = 0; i < coins.length; i++){
            int coin = coins[i];
            for (int sum = coin; sum <= amount; sum++){
                dp[sum] = Math.min(dp[sum], dp[sum - coin] + 1);
            }
        }


        return dp[amount] == Integer.MAX_VALUE / 2 ? -1 : dp[amount];
    }
}


public class Coin_Change{
    public static void main(String[] args) {
        Solution s = new Solution();

        int[] coins1 = {1, 2, 5};
        int[] coins2 = {2};
        int[] coins3 = {1};

        System.out.println("\nWant : 3\nWas  : " + s.coinChange(coins1, 11));
        System.out.println("\nWant : -1\nWas  : " + s.coinChange(coins2, 3));
        System.out.println("\nWant : 0\nWas  : " + s.coinChange(coins3, 0));


    }
}
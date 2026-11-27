/*

You are given an integer array coins representing coins of different 
denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The final answer is guaranteed to fit into a signed 32-bit integer.


*/


class SolutionCoin_Change_II {
    public int change(int amount, int[] coins) {
        
        int[] dp = new int[amount + 1];
        dp[0]    = 1;
        
        for (int i = 0; i < coins.length; i++){
            int coin = coins[i];
            for (int sum = coin; sum <= amount; sum++){
                dp[sum] += dp[sum - coin];
            }
        }
        return dp[amount];
    }
}

public class Coin_Change_II{
    public static void main(String[] args) {
        SolutionCoin_Change_II s = new SolutionCoin_Change_II();

        int [] coins1 = {1, 2, 5};
        int [] coins2 = {2};
        int [] coins3 = {10};

        System.out.println("\nWant : 4\nWas  : " + s.change(5, coins1));
        System.out.println("\nWant : 0\nWas  : " + s.change(3, coins2));
        System.out.println("\nWant : 1\nWas  : " + s.change(10, coins3));


    }
}
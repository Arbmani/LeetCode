class Solution:
    '''
    You are given an integer array coins representing coins of different 
    denominations and an integer amount representing a total amount of money.

    Return the fewest number of coins that you need to make up that amount. 
    If that amount of money cannot be made up by any combination of the coins, return -1.

    You may assume that you have an infinite number of each kind of coin.
    
    '''

    def coinChange(self, coins: list[int], amount: int) -> int:
        dp      = [float("inf")] * (amount + 1)
        dp[0]   = 0

        for i in range(1, amount + 1):
            for coin in coins:
                if coin <= i and dp[i - coin] != float("inf"):
                    dp[i] = min(dp[i], 1 + dp[i - coin])
        return -1 if dp[amount] == float("inf") else dp[amount]


if __name__ == "__main__":
    print(f"Want :  {3}, Was :  {Solution().coinChange(coins = [1,2,5], amount = 11)}")
    print(f"Want : {-1}, Was : {Solution().coinChange(coins = [2], amount = 3)}")
    print(f"Want :  {0}, Was :  {Solution().coinChange(coins = [1], amount = 0)}")



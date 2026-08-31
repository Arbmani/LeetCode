from typing import List

class Solution:
    '''
        You are given an array prices where prices[i] is the price of a 
        given stock on the "i"th day.

        Find the maximum profit you can achieve. You may complete at most two transaction.

        Note:
            You may not engage in multiple transactions simultaneously
            (i.e., you must sell the stock before you buy again).
    '''


    def maxProfit(self, prices: List[int]) -> int:
        first_Buy,  first_Sell  = float("-inf"), 0
        second_Buy, second_Sell = float("-inf"), 0

        for price in prices:
            first_Buy   = max(first_Buy, - price)
            first_Sell  = max(first_Sell, first_Buy + price)

            second_Buy  = max(second_Buy, first_Sell - price)
            second_Sell = max(second_Sell, second_Buy + price)
        return second_Sell

if __name__ == "__main__":
    print(Solution().maxProfit([3,3,5,0,0,3,1,4]))
    print(Solution().maxProfit([1,2,3,4,5]))
    print(Solution().maxProfit([7,6,4,3,1]))

from typing import List 

class Solution:
    '''
        You are given an integer array "prices" where "prices[i]" is the price
        of a given stock on the "i"th day.

        On each day, you may decide to buy and/or sell the stock. You can only hold at most one
        share of the stock at any given time. However, you can sell and buy the stock
        multiple times on the same day, ensuring you never hold more than one share of the stock. 

        Find and return the maximum profit you can achieve.
    '''


    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        index, profit, yesterdays_price = 1, 0, prices[0]
        while(index < len(prices)):
            todays_price = prices[index]
            if todays_price > yesterdays_price:
                profit += (todays_price - yesterdays_price)
            yesterdays_price = todays_price
            index += 1

        return profit

if __name__ == "__main__":
    print(Solution().maxProfit([7,6,4,3,1]))
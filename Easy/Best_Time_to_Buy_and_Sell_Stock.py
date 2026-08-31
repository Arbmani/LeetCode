from typing import List

class Solution:
    '''
        You are given an array prices where prices[i] is the price of a given
        stock on the "i"th day.

        You want to maximize your profit by choosing a single day to buy one stock
        and choosing a different day in the future to sell that stock.

        Return the maximum profit you can achieve from this transaction.
        If you cannot achieve any profit, return 0.
    '''

    def maxProfit(self, prices: List[int]) -> int:
        largest_gap = 0
        best_buy  = float("inf")

        for price in prices:
            if price < best_buy:
                best_buy = price
            else:
                largest_gap = max(largest_gap, price - best_buy)

        return largest_gap
if __name__ == "__main__":
    print(Solution().maxProfit(prices = [7,1,5,3,6,4]))
    print(Solution().maxProfit(prices = [7,6,4,3,1]))
class Solution:
    '''
    You are given an integer array coins representing coins of
    different denominations (ascending order).

    Each coin can be used at most once.

    Return the smallest positive integer that cannot be formed
    as the sum of any subset of coins.
    '''

    def nonConstructibleChange(self, coins: list[int]) -> int:
        cur_sum = 0
        for coin in coins:
            if coin > cur_sum + 1: return cur_sum + 1
            cur_sum += coin
        return cur_sum + 1


if __name__ == "__main__":
    print(f"Want: {4}, Was: {Solution().nonConstructibleChange([1, 2, 5])}")
    print(f"Want: {1}, Was: {Solution().nonConstructibleChange([2, 3, 4])}")
    print(f"Want: {11}, Was: {Solution().nonConstructibleChange([1, 2, 3, 4])}")
    print(f"Want: {1}, Was: {Solution().nonConstructibleChange([])}")

from collections import defaultdict
class Solution:
    '''
    [Hard Problem]

        There is a group of "n" members, and a list of various crimes they could commit. The "i"th crime
        generates a profit[i] and requires group[i] members to participate in it. If a memeber participates
        in one crime, that member cant participate in another crime. 

        Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit,
        and the total number of members participating in that subset of crimes is at most "n".

        Return the number of schemes that can be choosen. Since the answer may be very large, 
        return it modulo 10**9 + 7.
    
    
    
    '''
    def profitableSchemes(self, n: int, minProfit: int, group: list[int], profit: list[int]) -> int:
        dp          = [[0] * (minProfit + 1) for _ in range(n + 1)]
        dp[0][0]    = 1
        mod         = 1_000_000_007
        for g, p in zip(group, profit):
            for members in range(n - g, -1, -1):
                src = dp[members]
                dst = dp[members + g]

                for current_profit in range(minProfit + 1):
                    count = src[current_profit]
                    if count: 
                        new_profit = min(minProfit, current_profit + p)
                        dst[new_profit] = (dst[new_profit] + count) % mod
        return sum(row[minProfit] for row in dp) % mod


    def profitableSchemes_best(self, n: int, minProfit: int, group: list[int], profit: list[int]) -> int:
        dp          = [[0] * (minProfit + 1) for _ in range(n + 1)]
        dp[0][0]    = 1
        mod         = 10**9 + 7
        for g, p in zip(group, profit):
            for members in range(n - g, -1, -1):
                src = dp[members]
                dst = dp[members + g]

                for current_profit in range(minProfit + 1):
                    if src[current_profit]: 
                        new_profit = min(minProfit, current_profit + p)
                        dst[new_profit] = dst[new_profit] + src[current_profit] % mod



        return sum(dp[m][minProfit] for m in range(n + 1)) % mod


    def profitableSchemes_slow(self, n: int, minProfit: int, group: list[int], profit: list[int]) -> int:
        len_group, mod = len(group), 10**9 + 7
        dp = defaultdict(int)
        for member in range(n + 1): dp[(len_group, member, minProfit)] = 1
        for index in range(len_group -1, -1, -1):
            for member in range(n + 1):
                for pfit in range(minProfit + 1):
                    dp[(index, member, pfit)] = dp[(index + 1, member, pfit)]
                    if member + group[index] <= n:
                        dp[(index, member, pfit)] += dp[(index + 1, member + group[index], min(minProfit, pfit + profit[index]))] % mod
        return dp[(0, 0, 0)] % mod       


    def profitableSchemes_To_Slow(self, n: int, minProfit: int, group: list[int], profit: list[int]) -> int:
        len_group, mod = len(group), 10**9 + 7
        dp  = {}

        def dfs(i, n, p):
            if i == len_group   : return 1 if p >= minProfit else 0 
            if (i, n, p) in dp  : return dp[(i, n, p)]
            dp[(i, n, p)] = dfs(i + 1, n, p)
            if n - group[i] >= 0: dp[(i, n, p)] += dfs(i + 1, n - group[i], p + profit[i]) % mod 
            return dp[(i, n, p)]

        return dfs(0, n, 0)


if __name__ == "__main__":

    print(f"Want : {2}, Was : {Solution().profitableSchemes(n = 5, minProfit = 3, group = [2,2], profit = [2,3])}")

    print(f"Want : {7}, Was : {Solution().profitableSchemes(n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8])}")


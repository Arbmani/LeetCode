class Solution:
    '''
    [Medium Problem]

        You are given an integer "n" representing a target score.

        You score starts at 0, and each day you either earn points or skip

        Points are earned during streak. On the first day of a streak you earn 1 point, on
        the second day 2 points, on the third day 3 points, and so on. Skipping a day
        earns nothing and resets the streak, so the next time you earn points, you start from 1 again.

        Return the minimum number of days, including any skipped days, needed to reach a score of exactly n.
    
    '''
    # 1     = 1 + 0
    # 3     = 2 + 1
    # 6     = 3 + 3
    # 10    = 4 + 6
    # 15    = 5 + 10
    # 21    = 6 + 15


    def minDays(self, n: int) -> int:
        dp      = [float("inf")] * (n + 1)
        dp[0]   = 0

        streak_values = []
        streak       = 1

        while streak * (streak + 1) // 2 <= n:
            streak_values.append((streak * (streak + 1) // 2, streak + 1))
            streak += 1

        for target in range(1, n + 1):
            for streak_value, streak_days, in streak_values:
                if streak_value > target:
                    break 
                dp[target] = min(dp[target], dp[target - streak_value] + streak_days)
        return dp[n] - 1



if __name__ == "__main__":
    print(f"Want : {3}, Was : {Solution().minDays(2)}")
    print(f"Want : {6}, Was : {Solution().minDays(9)}")
    print(f"Want : {7}, Was : {Solution().minDays(12)}")
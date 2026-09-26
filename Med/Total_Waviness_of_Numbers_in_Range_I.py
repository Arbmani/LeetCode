from functools import lru_cache
class Solution:
    '''
    [Medium Problem]

        You are given two integers num1 and num2 representing an inclusive range [num1, num2].

        The waviness of a number if defined as the total count of its peaks and valleys:

        -   A digit is a peak if it is strictly greater than both of its immediate  neighbors

        -   A digit is a valley if it is strictly less than both of its immediate neighbors

        -   The first and last digits of a number cannot be peaks or valleys.

        -   Any number with fewer than 3 digits has a waviness of 0.

        Return the total sum of waviness for all numbers in the range [num1, num2].
    
    '''
    #def totalWaviness(self, num1: int, num2: int) -> int:
    #    def solve(n: int) -> int:
    #        if n <= 0: return 0
    #        digits = list(map(int, str(n)))
#
    #        @lru_cache(None)
    #        def dp(pos, prev2, prev1, tight, started):
    #            if pos == len(digits): return 1, 0
#
    #            limit = digits[pos] if tight else 9
    #            ans   = 0
#
    #            for d in range(limit + 1):
    #                next_tight = tight and (d == digits[pos])
    #                if not started:
    #                    if d == 0: ans += dp(pos + 1, -1, -1, next_tight, False)
    #                    else: ans += dp(pos + 1, -1, d, next_tight, True)
    #                    continue
    #                wave = 0
    #                if prev2 != -1 and ((prev1 > prev2 and prev1 > d) or (prev1 < prev2 and prev1 < d)): wave = 1
#
    #                ans += wave 
    #                ans += dp(pos + 1, prev1, d, next_tight, True)
    #            return ans
    #        return dp(0, -1, -1, True, False)
    #    return solve(num2) - solve(num1 - 1)





    MIN, MAX = 0,100001
    dp      = [0] * MAX
    pref    = [0] * MAX 
    for i in range(100, MAX):
        r = i % 10
        m = (i // 10) % 10
        l = (i // 100) % 10

        isWave = m > max(l, r) or m < min(l, r)
        dp[i] = dp[i // 10] + int(isWave)
        pref[i] = pref[i - 1] + dp[i]


    def totalWaviness(self, num1: int, num2: int) -> int:
        return self.pref[num2] - self.pref[num1 - 1]



if __name__ == "__main__":
    print(f"Want : {3}, Was : {Solution().totalWaviness(num1 = 120, num2 = 130)}")
    print(f"Want : {3}, Was : {Solution().totalWaviness(num1 = 198, num2 = 202)}")
    print(f"Want : {2}, Was : {Solution().totalWaviness(num1 = 4848, num2 = 4848)}")
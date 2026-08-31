from typing import List
class Solution:
    '''
        Given a string "s", partition "s" such that every substring of the partition is a palindrome.

        Return the minimum cuts needed for a palindrome partitioning of "s".
    '''
    def minCut(self, s: str) -> int:
        cache_boolean = [[False] * len(s) for _ in range(len(s))]

        for substring_len in range(1, len(s) + 1):
            for substring_start in range(len(s) - substring_len + 1):
                substring_end = substring_start + substring_len - 1
                if s[substring_start] == s[substring_end] and (
                    substring_len <= 2 or 
                    cache_boolean[substring_start + 1][substring_end - 1]):
                    cache_boolean[substring_start][substring_end] = True 
        cache_cuts = [float("inf")] * len(s)
        for substring_end in range(len(s)):
            if cache_boolean[0][substring_end]:
                cache_cuts[substring_end] = 0
                continue
            for substring_start in range(1, substring_end + 1):
                if cache_boolean[substring_start][substring_end]:
                    cache_cuts[substring_end] = min(cache_cuts[substring_end], cache_cuts[substring_start - 1] + 1)
        return cache_cuts[-1]

if __name__ == "__main__":
    print(Solution().minCut("aab"))
    print(Solution().minCut("a"))
    print(Solution().minCut("ab"))
    print(Solution().minCut("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp"))
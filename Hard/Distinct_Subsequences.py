#class Solution:
#    def numDistinct(self, s: str, t: str) -> int:
#        cache = {}
#
#        def Depth_First_Search(index_s: int, index_t: int) -> int:
#            if index_t == len(t):
#                return 1
#            if index_s == len(s):
#                return 0
#            if (index_s, index_t) in cache:
#                return cache[(index_s, index_t)]
#
#            if s[index_s] == t[index_t]:
#                cache[(index_s, index_t)] = (Depth_First_Search(index_s = index_s + 1, index_t = index_t + 1) + Depth_First_Search(index_s = index_s + 1, index_t = index_t))
#            else:
#                cache[(index_s, index_t)] = Depth_First_Search(index_s = index_s + 1, index_t = index_t)
#            return cache[(index_s, index_t)]
#        return Depth_First_Search(index_s= 0,index_t=0)
#

# Idea gör en substring där vi räcknar alla 
#if __name__ == "__main__":
#    sol = Solution()
#    print(sol.numDistinct(s = "rabbbit", t = "rabbit"))
#

class Solution:
    '''
    [Hard Problem]

        Given two strings s and t, return the number of distinct subsequences of s, which equals t.

        The test cases are generated so that the answer fits on a 32-bit signed integer. 
    
    '''
    def numDistinct(self, s: str, t: str) -> int:
        t_len    = len(t)
        if len(s) < t_len:
            return 0
        cache    = [0] * (t_len + 1)
        cache[0] = 1
        for char in s:
            for t_index in range(t_len - 1, -1, -1):
                if char == t[t_index]:
                    cache[t_index + 1] += cache[t_index]
        return cache[-1]



    #def numDistinct(self, s: str, t: str) -> int:
    #    cache = {}
    #    t_len = len(t)
    #    s_len = len(s)
#
    #    def dfs(s_index: int, t_index: int) -> int:
    #        if t_index == t_len:
    #            return 1
    #        if s_index == s_len:
    #            return 0
    #        if (s_index, t_index) in cache:
    #            return cache[(s_index, t_index)]
    #        if s[s_index] == t[t_index]:
    #            cache[(s_index, t_index)] = (dfs(s_index+1, t_index+1) + dfs(s_index+1, t_index))
    #        else:
    #            cache[(s_index, t_index)] = dfs(s_index+1, t_index)
    #        return cache[(s_index, t_index)]
    #    return dfs(0, 0)

if __name__ == "__main__":
    print(Solution().numDistinct(s = "rabbbit", t = "rabbit"))
    print(Solution().numDistinct(s = "babbab", t = "bb"))